#include "root.h"
#include "director.h"


#include <glfw/glfw3.h>
#include "glad/glad.h"


uint8_t InitEngine(RoadEngine_t* enginePtr, const char* windowTitle){
    CreateWindow(&mainEngine->window, windowTitle);
    InitDirector(&mainEngine->director);

    return 0;
}    


int main(void){
    RoadEngine_t engine = {0};

    InitEngine(&engine,"My 2D Game!");


    while(!glfwWindowShouldClose(engine.window)){
        
    }

    return 0;
}