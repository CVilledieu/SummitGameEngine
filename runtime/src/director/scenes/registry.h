#pragma once

#include "common/engine_config.h"


#define MAX_REGISTERED_SCENE_COUNT 32

typedef struct SceneHooks{
    uint8_t (*On_Init)(VGE_Scene* vgeScene);
    void (*On_Update)(VGE_Scene* vgeScene);
    void (*On_Render)(VGE_Scene* vgeScene);
    void (*On_Shutdown)(VGE_Scene* vgeScene);
}SceneHooks;


typedef struct SceneDefinition{
    SceneId id;
    const char* name;
    SceneHooks hooks;
    VGE_Scene wrapper;
}SceneDefinition;

typedef struct SceneRegistry{
    uint32_t count;
    SceneDefinition list[MAX_REGISTERED_SCENE_COUNT];
}SceneRegistry;


uint8_t InitSceneRegistry(SceneRegistry* sRegistry);
uint8_t RegisterNewScene(SceneRegistry* sRegistry, const SceneDefinition* sDef);
const SceneDefinition* GetRegisteredScene(const SceneRegistry* reg, SceneId id);