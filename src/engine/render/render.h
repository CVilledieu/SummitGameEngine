#pragma once
#include "engine_config.h"



typedef struct Renderer_t{
    ShaderContext_t shaders;
    GraphicsBuffer_t gBuffer;
    ModelWriter_t modelWriter;

}Renderer_t;

uint8_t InitRenderer(Renderer_t* renderer);