#pragma once
#include "engine_config.h"


typedef struct SliceState_t{
    size_t offset;
    GLsync fence;
}SliceState_t;


typedef struct Renderer_t{
    ShaderContext_t shaders;

    uint8_t currentSlice;
    uint32_t bufferID;
    SliceState_t sliceStates[BUFFER_SLICE_COUNT];
    uint8_t buffer[TOTAL_BUFFER_BYTES];
}Renderer_t;


uint8_t InitGraphicsBuffer(GraphicsBuffer_t* gBuffer);
uint8_t InitRenderer(Renderer_t* renderer);