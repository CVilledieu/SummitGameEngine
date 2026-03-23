#pragma once

typedef uint32_t ShaderProgramID_t;
typedef uint32_t BufferBinding_t;

typedef struct ShaderEffect_t{
    ShaderProgramID_t program;
    BufferBinding_t bindIndex;
} ShaderEffect_t;

void InitShaderEffect(ShaderEffect_t* sEffect);