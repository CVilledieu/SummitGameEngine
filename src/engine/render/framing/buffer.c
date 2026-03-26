#include "buffer.h"

#include <stdlib.h>




static inline void SyncFence(FrameState_t* fs){
    while(fs->fence){
        GLenum res = glClientWaitSync(fs->fence, GL_SYNC_FLUSH_COMMANDS_BIT, FENCE_DELAY_VALUE);
        if(res == GL_ALREADY_SIGNALED || res == GL_CONDITION_SATISFIED){
            fs->fence = 0;
        }
    }
    glDeleteSync(fs->fence);
}





uint8_t SubmitFrame(FameBuffer_t* fBuffer){
    if(fBuffer == NULL){
        return 0;
    }
    SyncFence(&fBuffer->frameStates[fBuffer->currentFrame]);
    
}



uint8_t InitFBuffer(FameBuffer_t* fBuffer){
    if(fBuffer == NULL){
        return 0;
    }

    for(uint8_t i = 0; i < N_BUFFERED_FRAMES; i++){
        fBuffer->frameStates[i].index = (size_t)i * FRAME_SLICE_LENGTH;
    }


    glGenBuffers(1, &fBuffer->bufferID);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, fBuffer->bufferID);



    glBufferStorage(GL_SHADER_STORAGE_BUFFER, MAX_BUFFER_LENGTH, NULL, BUFFER_GL_MAP_OPTIONS);

	fBuffer->buffer = (uint8_t*)glMapBufferRange(GL_SHADER_STORAGE_BUFFER, 0, MAX_BUFFER_LENGTH, BUFFER_GL_MAP_OPTIONS);

	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);

    if(!fBuffer->buffer){
        glDeleteBuffers(1, &fBuffer->bufferID);
        return 0;
    }

    return 1;
}