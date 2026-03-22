#pragma once

#include <GLFW/glfw3.h>
#include "glad/glad.h"


typedef struct REC_t{
    GLFWwindow* mainWindow;
    SceneRegistry_t* 

}REC_t;

REC_t* InitEngine(const char* windowTitle);
void StartEngine(REC_t* engine);