#include "root.h"
#include "director.h"
#include "renderer.h"

#include <glfw/glfw3.h>
#include "glad/glad.h"


RoadEngine_t* mainEngine = NULL;


uint8_t InitEngine(RoadEngine_t* enginePtr, const char* windowTitle){
    mainEngine = &enginePtr;
    CreateWindow(&mainEngine->window, windowTitle);
    InitDirector(&mainEngine->director);

    return 0;
}    



void RunMainLoop(void){
    while(!glfwWindowShouldClose(mainEngine->window)){
        DrawScene();
    }    
}    
