#pragma once

#include "common/engine_config.h"

#define SCENE_MAX_REGISTERED_COUNT 32
#define SCENE_MAX_ACTIVE_COUNT 16
#define SCENE_EMPTY_ACTIVE_STACK -1


typedef struct SceneDefinition {
    SceneId id;
    const char* name;
}SceneDefinition;

typedef struct SceneRegistry{
    SceneDefinition scenes[DIRECTOR_MAX_SCENES_COUNT];
    uint16_t registerCount;
}SceneRegistry;




typedef enum ActiveSceneState{
    WAITING = 0,
    ACTIVE,
}ActiveSceneState;

typedef struct ActiveScene{
    SceneId id;
    ActiveSceneState state;
}ActiveScene;

typedef struct ActiveSceneStack{
    int32_t current;
    ActiveScene scenes[DIRECTOR_MAX_SCENES_COUNT];
}ActiveSceneStack;


typedef struct SceneHandler{
    int32_t top;
    ActiveScene activeStack[SCENE_MAX_ACTIVE_COUNT];
    uint16_t registryCount;
    SceneDefinition registry[SCENE_MAX_REGISTERED_COUNT];
}SceneHandler;