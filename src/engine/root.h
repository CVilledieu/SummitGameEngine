#pragma once

#include "director.h"
#include "wnd.h"

typedef struct RoadEngine_t{
    GLFWwindow* window;
    Director_t director;
    Renderer_t renderer;
} RoadEngine_t;



uint8_t InitEngine(RoadEngine_t* enginePtr, const char* windowTitle);
void RunMainLoop(void);