#pragma once

#include <GLFW/glfw3.h>
#include "glad/glad.h"


void WindowResized(GLFWwindow* window, int width, int height){
    (void)window;
    glViewport(0, 0, width, height);
}


static inline void CreateWindow(GLFWwindow* mainWindow, const char* title){
    if(mainWindow == NULL || !glfwInit()){
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    mainWindow = glfwCreateWindow(800, 600, title, NULL, NULL);

    glfwMakeContextCurrent(mainWindow);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        return;
    }

    glfwSetFramebufferSizeCallback(mainWindow, WindowResized);


    return;
}
