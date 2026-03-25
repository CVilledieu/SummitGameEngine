#include "render.h"

#include <stdint.h>
#include <GLFW/glfw3.h>
#include "glad/glad.h"

uint8_t InitRenderer(Renderer_t* renderer){
    InitShaderEffect(&renderer->shader);

    size_t sliceSize = 1024;
    CreateRSBuffer(&renderer->rsBuffer, sliceSize);

    
}


void Render(Renderer_t* renderer){
    glClear(GL_COLOR_BUFFER_BIT);
}