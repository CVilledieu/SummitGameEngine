#pragma once

#include "engine_config.h"


typedef struct SliceState_t{
    size_t offset;
    GLsync fence;
}SliceState_t;


typedef struct GraphicsBuffer_t{
    uint8_t currentSlice;
    uint32_t bufferID;
    SliceState_t sliceStates[BUFFER_SLICE_COUNT];
    uint8_t* buffer;
}GraphicsBuffer_t;

uint8_t InitGraphicsBuffer(GraphicsBuffer_t* gBuffer);