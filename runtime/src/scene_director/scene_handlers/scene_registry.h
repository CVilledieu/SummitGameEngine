#pragma once

#include "common/engine_config.h"
#include "common/vge_types.h"

#define MAX_REGISTERED_SCENE_COUNT 32


typedef struct ATag{
    const char* ptr;
    size_t length;
}ATag;

typedef struct Arena{
    size_t length;
    size_t remaining;
    char* stringPool;
}Arena; 


typedef struct SceneDefinition{
    SceneId id;
    ATag name;
    // SceneHooks hooks;
}SceneDefinition;

typedef struct SceneRegistry{
    uint32_t count;
    SceneDefinition list[MAX_REGISTERED_SCENE_COUNT];
    Arena* nameArena;
}SceneRegistry;

//Arena
uint8_t InitArena(Arena* arena, size_t initLength);
uint8_t CloseArena(Arena* arena);
uint8_t Arena_SetSceneName(Arena* arena, const char* string, ATag* dest);


//Scene Registry
uint8_t SRegistry_Init(SceneRegistry* sRegistry);
uint8_t SRegistry_NewScene(SceneRegistry* sRegistry, SceneId sId, const char* name);
const SceneDefinition* SRegistry_GetScene(const SceneRegistry* reg, SceneId id);