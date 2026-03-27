#version 460 core
layout (location = 0) in vec2 aPos;
layout (location = 1) in vec3 aColor;

layout(binding = 0, std430) buffer ssbo{
    vec2 model[];
}; 

uniform mat4 uView;

out vec3 vColor;

void main(){
    gl_Position = uView * vec4(aPos + model[gl_InstanceID], 0.0, 1.0);

    vColor = aColor;
}