#include "sbuffer.h"
#include <stdlib.h>

#define BUFFER_GL_MAP_OPTIONS (GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT) 
#define FENCE_DELAY_VALUE 1000000ULL


static inline void SyncFence(SliceCtx_t* sCtx){
    while(sCtx->fence){
        GLenum res = glClientWaitSync(sCtx->fence, GL_SYNC_FLUSH_COMMANDS_BIT, FENCE_DELAY_VALUE);
        if(res == GL_ALREADY_SIGNALED || res == GL_CONDITION_SATISFIED){
            sCtx->fence = 0;
        }
    }
    glDeleteSync(sCtx->fence);
}


static inline void SetSliceOffsets(SliceCtx_t** sliceCtxList, uint32_t nSlices, size_t sliceSize){
    if(sliceCtxList == NULL || nSlices == 0 || sliceSize == 0){
        return;
    }
    
    for(uint32_t i = 0; i < nSlices; i++){
        sliceCtxList[i]->offset = (size_t)i * sliceSize;
    }
}


uint8_t InitStreamBuffer(StreamBuffer_t* sBuffer){
    if(sBuffer == NULL){
        return 0;
    }
    
    uint32_t nSlices = 3;
    size_t sliceSize = 1024;


    sBuffer->sliceCtxList = malloc(sizeof(SliceCtx_t) * nSlices);
    SetSliceOffsets(&sBuffer->sliceCtxList, nSlices, sliceSize);
    

    glGenBuffers(1, &sBuffer->bindId);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, sBuffer->bindId);

    GLsizeiptr bufferSize = sliceSize * nSlices;
    glBufferStorage(GL_SHADER_STORAGE_BUFFER, bufferSize, NULL, BUFFER_GL_MAP_OPTIONS);
	sBuffer->buffer = (uint8_t*)glMapBufferRange(GL_SHADER_STORAGE_BUFFER, 0, bufferSize, BUFFER_GL_MAP_OPTIONS);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);

    if(!sBuffer->buffer){
        glDeleteBuffers(1, &sBuffer->bindId);
        return 0;
    }

    return 1;
}