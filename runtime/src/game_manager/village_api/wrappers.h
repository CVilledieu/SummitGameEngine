#pragma once

typedef struct Manager Manager;
typedef struct SceneDefinition SceneDefinition;


typedef struct VGE_Handler{
    Manager* unwrapped;
} VGE_Handler;

typedef struct VGE_Scene{
    SceneDefinition* unwrapped;
} VGE_Scene;
