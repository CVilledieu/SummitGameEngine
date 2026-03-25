#pragma once

#include "glad/glad.h"

#define N_BUFFER_SLICES 3

typedef struct Slice_t{
    size_t offset;
    GLsync fence;
}Slice_t;


typedef struct RSBuffer_t{
    uint8_t* buffer;
    uint32_t bindId;
    uint32_t currentSlice;
    size_t maxSliceSize;
    Slice_t sliceCtxList[N_BUFFER_SLICES];
}RSBuffer_t;

uint8_t CreateRSBuffer(RSBuffer_t* sBuffer, size_t sliceSize);