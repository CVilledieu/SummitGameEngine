#include "shaders.h"


#include "shaders.h"


#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "glad/glad.h"

#define SHADER_DIR "assets\\shaders\\"



static inline void CompileShader(ShaderEffect_t* sEffect, const char* fName, GLenum sType){
    uint8_t* dataBuffer;
    uint32_t fSize = GetFileData(&dataBuffer, SHADER_DIR, fName);

    unsigned int shader = glCreateShader(sType);
    const char* constBufferPtr = (const char*)dataBuffer;
    glShaderSource(shader, 1, &constBufferPtr, NULL);

    glCompileShader(shader);
    
    int success = 0;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        return 0;
    }

    free(dataBuffer);


    glAttachShader(sEffect->program, shader);
    glDeleteShader(shader);
}





void InitShaderEffect(ShaderEffect_t* sEffect){
    sEffect->program = glCreateProgram();

    CompileShader(sEffect, "default.vert", GL_VERTEX_SHADER);
    CompileShader(sEffect, "default.frag", GL_FRAGMENT_SHADER);
    

    glLinkProgram(sEffect->program);
    

}



int DestroyShaderEffect(ShaderEffect_t* sEffect){
    glUseProgram(0);
    glDeleteProgram(sEffect->program);
}


