#pragma once

#include <GLFW/glfw3.h>
#include "glad/glad.h"


void WindowResized(GLFWwindow* window, int width, int height){
    (void)window;
    glViewport(0, 0, width, height);
}

int SetGLFWCtx(void){
    if(!glfwInit()){
        return 0;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    return 1;
}


GLFWwindow* OpenNewWindow( const char* title, int width, int height ){
    GLFWwindow* newWnd = glfwCreateWindow(width, height, title, NULL, NULL);

    glfwMakeContextCurrent(newWnd);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        return NULL;
    }

    glfwSetFramebufferSizeCallback(newWnd, WindowResized);


    return newWnd;
}
