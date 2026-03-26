#include "shaders.h"
#include "fs/fs.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "glad/glad.h"

#define SHADER_DIR "assets\\shaders\\"




static inline uint8_t BuildShaderElement(uint8_t* sProgram, const char* src, GLenum glType){
    uint8_t shaderElement = glCreateShader(glType);
    glShaderSource(shaderElement, 1, src, NULL);
    
    glCompileShader(shaderElement);
    
    int success = 0;
    char infoLog[512];
    glGetShaderiv(shaderElement, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(shaderElement, 512, NULL, infoLog);
        return 0;
    }

    glAttachShader(sProgram, shaderElement);
    glDeleteShader(shaderElement);
    return 1;
}


void CreateModelShader(ModelShader_t* mShader, uint8_t bindIndex){
    mShader->program = glCreateProgram();
    
    FSReader_t vertexReader = {
        .relativePath = SHADER_DIR,
        .fileName = "model.vert",
    };
    ReadFile(&vertexReader);    
    uint8_t ok = BuildShaderElement(mShader->program, vertexReader.data, GL_VERTEX_SHADER);
    if(!ok){
        return;
    }
    FreeReader(&vertexReader);
    
    FSReader_t fragReader = {
        .relativePath = SHADER_DIR,
        .fileName = "model.frag",
    };
    ReadFile(&fragReader);

    ok = BuildShaderElement(mShader->program, fragReader.data, GL_FRAGMENT_SHADER);
    if(!ok){
        return;
    }
    FreeReader(&fragReader);

    glLinkProgram(mShader->program);
}


uint8_t InitShaderContext(ShaderContext_t* sCtx){
    CreateModelShader(&sCtx->modelShader, 0);
}


int DestroyShaders(ShaderContext_t* sCtx){
    glUseProgram(0);
    glDeleteProgram(&sCtx->modelShader);
}



