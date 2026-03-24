#pragma once

#include "glad/glad.h"

typedef struct SliceCtx_t{
    size_t offset;
    GLsync fence;
}SliceCtx_t;


typedef struct StreamBuffer_t{
    uint8_t* buffer;
    uint32_t bindId;
    uint32_t currentSlice;
    SliceCtx_t* sliceCtxList;
}StreamBuffer_t;