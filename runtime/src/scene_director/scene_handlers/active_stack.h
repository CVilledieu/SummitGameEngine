#pragma once


#define MAX_ACTIVE_SCENE_COUNT 16
#define EMPTY_ACTIVE_SCENE_STACK -1

typedef enum ActiveSceneState{
    INACTIVE = 0,
    ACTIVE,
}ActiveSceneState;

typedef struct ActiveScene{
    SceneId id;
    ActiveSceneState state;    
}ActiveScene;


typedef struct SceneStack{
    int32_t top;
    ActiveScene scenes[MAX_ACTIVE_SCENE_COUNT];
}SceneStack;

uint8_t InitActiveSceneStack(SceneStack* sStack);
uint8_t PushActiveScene(SceneStack* sStack, SceneId sId);
uint8_t PopActiveScene(SceneStack* sStack,  SceneId* sId);
uint8_t PeakActiveScene(SceneStack* sStack, SceneId* sId);