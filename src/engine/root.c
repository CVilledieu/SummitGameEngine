#include "root.h"
#include "wnd/wnd.h"

REC_t mainEngine = {0};

REC_t* InitEngine(const char* windowTitle){
    CreateWindow(&mainEngine.mainWindow, windowTitle);
    
    return &mainEngine;
}



void StartEngine(REC_t* engine){
    while(!glfwWindowShouldClose(mainEngine.mainWindow)){

    }
}