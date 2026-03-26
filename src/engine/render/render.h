#pragma once


typedef struct Renderer_t{
    ShaderContext_t shader;
    FameBuffer_t rsBuffer;
    

}Renderer_t;

uint8_t InitRenderer(Renderer_t* renderer);