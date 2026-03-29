#pragma once

#include "common/engine_config.h"


typedef struct SceneNode{

}SceneNode;

typedef struct SceneHooks{

}SceneHooks;



typedef struct SceneGraph{
    SceneId id;
    const char* name;
    SceneNode* root;
    SceneHooks hooks;
}SceneGraph;




typedef enum GraphState{
    
}GraphState;

typedef struct GraphCtx{
    SceneId id;
    GraphState state;
}GraphCtx;

typedef struct GraphStack{
    int32_t top;
    
}GraphStack;