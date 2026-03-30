#pragma once

typedef struct Director Director;
typedef struct SceneDefinition SceneDefinition;


typedef struct VGE_Handler{
    Director* unwrapped;
} VGE_Handler;

typedef struct VGE_Scene{
    SceneDefinition* unwrapped;
} VGE_Scene;
