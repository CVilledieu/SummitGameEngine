#include "trailborn/trailborn.h"
#include "common/engine_config.h"


#include <glfw/glfw3.h>
#include "glad/glad.h"

typedef struct ECtx_t{
    GLFWwindow* mainWindow;
    AssMan_t* assetManager;
    SceneSystem_t* sceneSystem;
    Renderer_t* renderer;
    Framer_t* framer;
}ECtx_t;




int InitEngineComponents(ECtx_t* eCtx, const char* windowTitle){
    InitRenderer(&eCtx->renderer, &eCtx->mainWindow);
    CreateWindow(&eCtx->mainWindow, windowTitle);
    eCtx->assetManager = CreateAssetManager();
    
    return 0;
}    


int main(void){
    ECtx_t eCtx = {0};
    
    InitEngine(&eCtx,"My 2D Game!");


    while(!glfwWindowShouldClose(eCtx.mainWindow)){
        
    }

    return 0;
}