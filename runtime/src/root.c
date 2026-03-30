#include "common/engine_config.h"
#include "director/director.h"
#include "wnd/wnd.h"
#include "render/render.h"

#include <glfw/glfw3.h>
#include "glad/glad.h"

typedef struct EngineCtx{
    Director director; // Game layer api handler
    AssManager assets;
    Renderer renderer;
}EngineCtx;




int InitEngineComponents(EngineCtx* eCtx){
    InitDirector(&eCtx->director);
    LoadAssets(&eCtx);
    InitRenderer(&eCtx->renderer);
    
    return 0;
}


int FrameLoop(EngineCtx* eCtx){

}



int main(void){
    EngineCtx eCtx = {0};
    
    InitEngineComponents(&eCtx);

    GLFWwindow* mainWindow = OpenNewWindow("My game engine", 800, 600);
    while(!glfwWindowShouldClose(mainWindow)){
        
    }

    return 0;
}