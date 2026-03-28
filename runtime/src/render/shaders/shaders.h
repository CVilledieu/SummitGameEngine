#pragma once



typedef uint8_t ShaderProgramID_t;
typedef uint8_t BufferBinding_t;

typedef struct ShaderEffect_t{
    ShaderProgramID_t program;
    BufferBinding_t bindIndex;
} ShaderEffect_t;


typedef struct ModelShader_t{
    uint8_t program;
    uint8_t   index;
}ModelShader_t;

typedef struct ShaderContext_t{
    ModelShader_t modelShader;
}ShaderContext_t;

void InitShaderEffect(ShaderEffect_t* sEffect);
uint8_t InitShaderContext(ShaderContext_t* sCtx);