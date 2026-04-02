#pragma once

typedef struct Manager Manager;
typedef struct SceneDefinition SceneDefinition;



typedef struct VCtx{
    void* engine;
    void* game;
}VCtx;

typedef struct VeCtx{
    Manager* unwrapped;
} VeCtx;
