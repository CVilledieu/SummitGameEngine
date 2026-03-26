#include "sbuffer.h"
#include <stdlib.h>

#define BUFFER_GL_MAP_OPTIONS (GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT) 
#define FENCE_DELAY_VALUE 1000000ULL


static inline void SyncFence(Frame_t* sCtx){
    while(sCtx->fence){
        GLenum res = glClientWaitSync(sCtx->fence, GL_SYNC_FLUSH_COMMANDS_BIT, FENCE_DELAY_VALUE);
        if(res == GL_ALREADY_SIGNALED || res == GL_CONDITION_SATISFIED){
            sCtx->fence = 0;
        }
    }
    glDeleteSync(sCtx->fence);
}





uint8_t SendFrame(FameBuffer_t* fBuffer){
    if(fBuffer == NULL){
        return 0;
    }
    SyncFence(&fBuffer->frameList[fBuffer->currentFrame]);
    
}



uint8_t CreateFrameBuffer(FameBuffer_t* fBuffer, size_t maxFrameSize){
    if(fBuffer == NULL || maxFrameSize == 0){
        return 0;
    }

    for(uint8_t i = 0; i < N_BUFFERED_FRAMES; i++){
        fBuffer->frameList[i].offset = (size_t)i * maxFrameSize;
    }
    fBuffer->maxFrameSize = maxFrameSize;

    glGenBuffers(1, &fBuffer->bufferID);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, fBuffer->bufferID);

    GLsizeiptr bufferSize = maxFrameSize * N_BUFFERED_FRAMES;

    glBufferStorage(GL_SHADER_STORAGE_BUFFER, bufferSize, NULL, BUFFER_GL_MAP_OPTIONS);
	fBuffer->buffer = (uint8_t*)glMapBufferRange(GL_SHADER_STORAGE_BUFFER, 0, bufferSize, BUFFER_GL_MAP_OPTIONS);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);

    if(!fBuffer->buffer){
        glDeleteBuffers(1, &fBuffer->bufferID);
        return 0;
    }

    return 1;
}