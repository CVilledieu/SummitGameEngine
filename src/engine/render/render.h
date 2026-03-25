#pragma once

#include "shaders/shaders.h"
#include "shaders/rsbuffer.h"
typedef struct Renderer_t{
    ShaderContext_t shader;
    RSBuffer_t rsBuffer;

}Renderer_t;

uint8_t InitRenderer(Renderer_t* renderer);