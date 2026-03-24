#pragma once

typedef struct Shader_t Shader_t;

typedef struct Renderer_t{
    Shader_t* shader;
}Renderer_t;

uint8_t InitRenderer(Renderer_t* renderer);