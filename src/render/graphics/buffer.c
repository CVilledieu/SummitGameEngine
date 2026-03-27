#include "buffer.h"

#include <stdlib.h>




static inline int SyncFence(SliceState_t* fs){
    GLenum res = glClientWaitSync(fs->fence, GL_SYNC_FLUSH_COMMANDS_BIT, FENCE_SYNC_TIMEOUT);
    while(res == GL_TIMEOUT_EXPIRED){
        GLenum res = glClientWaitSync(fs->fence, GL_SYNC_FLUSH_COMMANDS_BIT, FENCE_SYNC_TIMEOUT);
    }
    if (res == GL_WAIT_FAILED){
        return 1;
    }
    glDeleteSync(fs->fence);
}





int SubmitFrame(GraphicsBuffer_t* fBuffer){
    if(fBuffer == NULL){
        return 0;
    }
    SyncFence(&fBuffer->sliceStates[fBuffer->currentSlice]);
    
}





uint8_t InitGraphicsBuffer(GraphicsBuffer_t* gBuffer){
    if(gBuffer == NULL){
        return 0;
    }

    for(uint8_t i = 0; i < BUFFER_SLICE_COUNT; i++){
        gBuffer->sliceStates[i].offset = (size_t)i * BYTES_PER_SLICE;
    }


    glGenBuffers(1, &gBuffer->bufferID);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, gBuffer->bufferID);



    glBufferStorage(GL_SHADER_STORAGE_BUFFER, TOTAL_BUFFER_BYTES, NULL, BUFFER_STORAGE_GL_FLAGS);

    gBuffer->buffer = (uint8_t*)glMapBufferRange(GL_SHADER_STORAGE_BUFFER, 0, TOTAL_BUFFER_BYTES, BUFFER_MAP_GL_FLAGS);


    glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);

    if(!gBuffer->buffer){
        glDeleteBuffers(1, &gBuffer->bufferID);
        return 0;
    }

    return 1;
}