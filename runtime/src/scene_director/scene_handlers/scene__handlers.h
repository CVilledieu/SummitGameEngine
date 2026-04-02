#pragma once

#include <stdint.h>

#define MAX_ACTIVE_SCENE_COUNT 32
#define MAX_SCENE_DEF_COUNT 64
#define EMPTY_ACTIVE_SCENE_LIST (int32_t)-1




typedef uint32_t SceneId;
typedef uint16_t ActiveSceneState;



typedef struct SceneReference{
    SceneId id;
    ActiveSceneState state;    
}SceneReference;


typedef struct ActiveScenes{
    int32_t top;
    SceneReference stack[MAX_ACTIVE_SCENE_COUNT];
    
}ActiveScenes;




typedef struct ArenaTag{
    const char* ptr;
    size_t length;
}ArenaTag;

typedef struct NameArena{
    size_t length;
    size_t remaining;
    char* namePool;
}NameArena;





typedef struct SceneDefinition{
    SceneId id;
    ArenaTag name;
    // SceneHooks hooks;
}SceneDefinition;

typedef struct SceneRegistry{
    uint32_t definitionCount;
    SceneDefinition definitionList[MAX_SCENE_DEF_COUNT];
}SceneRegistry;




typedef struct SceneHandler{
    ActiveScenes activeList;
    SceneRegistry sceneList;
    NameArena* nameArena;
}SceneHandler;



uint8_t SceneHandler_Init(SceneHandler* sHandler);
uint8_t SceneHandler_Shutdown(SceneHandler* sHandler);