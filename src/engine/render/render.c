#include "render.h"
#include "shaders/shaders.h"
#include "graphics/buffer.h"
#include "graphics/gb_modeling.h"


#include <stdint.h>
#include <GLFW/glfw3.h>
#include "glad/glad.h"



void Render(Renderer_t* renderer){
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    
}

static inline void DrawMeshBlocks(MeshRegistry_t* meshRegistry, ModelWriter_t* mWriter){
    for(uint32_t i = 0; mWriter->meshCount; i++){
        
    }
    glBindVertexArray()
}


uint8_t InitRenderer(Renderer_t* renderer){
    InitShaderEffect(&renderer->shaders);


    InitGraphicsBuffer(&renderer->gBuffer);
    InitModelWriter(&renderer->modelWriter);
    
}