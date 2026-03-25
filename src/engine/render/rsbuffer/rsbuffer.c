#include "rsbuffer.h"
#include <stdlib.h>

#define BUFFER_GL_MAP_OPTIONS (GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT) 
#define FENCE_DELAY_VALUE 1000000ULL


static inline void SyncFence(Slice_t* sCtx){
    while(sCtx->fence){
        GLenum res = glClientWaitSync(sCtx->fence, GL_SYNC_FLUSH_COMMANDS_BIT, FENCE_DELAY_VALUE);
        if(res == GL_ALREADY_SIGNALED || res == GL_CONDITION_SATISFIED){
            sCtx->fence = 0;
        }
    }
    glDeleteSync(sCtx->fence);
}





uint8_t SetSlice(RSBuffer_t* sBuffer){
    if(sBuffer == NULL){
        return 0;
    }
    SyncFence(&sBuffer->sliceCtxList[sBuffer->currentSlice]);
    
}



uint8_t CreateRSBuffer(RSBuffer_t* sBuffer, size_t sliceSize){
    if(sBuffer == NULL || sliceSize == 0){
        return 0;
    }

    for(uint32_t i = 0; i < N_BUFFER_SLICES; i++){
        sBuffer->sliceCtxList[i].offset = (size_t)i * sliceSize;
    }
    sBuffer->sliceSize = sliceSize;

    glGenBuffers(1, &sBuffer->bindId);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, sBuffer->bindId);

    GLsizeiptr bufferSize = sliceSize * N_BUFFER_SLICES;

    glBufferStorage(GL_SHADER_STORAGE_BUFFER, bufferSize, NULL, BUFFER_GL_MAP_OPTIONS);
	sBuffer->buffer = (uint8_t*)glMapBufferRange(GL_SHADER_STORAGE_BUFFER, 0, bufferSize, BUFFER_GL_MAP_OPTIONS);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);

    if(!sBuffer->buffer){
        glDeleteBuffers(1, &sBuffer->bindId);
        return 0;
    }

    return 1;
}