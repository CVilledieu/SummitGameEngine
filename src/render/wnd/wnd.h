#pragma once

#include <GLFW/glfw3.h>
#include "glad/glad.h"


void WindowResized(GLFWwindow* window, int width, int height){
    (void)window;
    glViewport(0, 0, width, height);
}

int InitGameWindow(GLFWwindow* window){
    if(window == NULL || !glfwInit()){
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

}


static inline void OpenWindow(GLFWwindow* mainWindow, const char* title, int width, int height ){
    mainWindow = glfwCreateWindow(width, height, title, NULL, NULL);

    glfwMakeContextCurrent(mainWindow);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        return;
    }

    glfwSetFramebufferSizeCallback(mainWindow, WindowResized);


    return;
}
