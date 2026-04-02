#include "scene_registry.h"
#include "string.h"
#include "common/vge_types.h"



uint8_t InitArena(Arena* arena, size_t initLength){
    if(!arena || !initLength){
        return 0;
    }

    arena->remaining = initLength;
    arena->length = initLength;
    arena->stringPool = malloc(initLength);
    if(!arena->stringPool){
        return 0;
    }

    return 1;
}


uint8_t CloseArena(Arena* arena){
    if(!arena){
        return 0;
    }

    free(arena->stringPool);

    return 1;
}

uint8_t Arena_SetSceneName(Arena* arena, const char* name, ATag* dest){
    if(!arena || !name || !dest){
        return 0;
    }

    size_t nameLen = strlen(name) + 1;

    if(nameLen >= arena->remaining){
        return 0;
    }

    char* arenaPtr = arena->stringPool + (arena->length - arena->remaining);    
    memcpy(arenaPtr, name, nameLen);
    arena->remaining -= nameLen;

    dest->length = nameLen;
    dest->ptr = arenaPtr;

    return 1;
}

uint8_t SRegistry_Init(SceneRegistry* sRegistry){
    if(!sRegistry){
        return 0;
    }
    sRegistry->count = 0;

    for(int i = 0; i < MAX_REGISTERED_SCENE_COUNT; i++){
        sRegistry->list[i].id = 0;
    }
    
    return 1;
}

uint8_t SRegistry_NewScene(SceneRegistry* sRegistry, SceneId sId, const char* name){
    if(!sRegistry || sRegistry->count >= MAX_REGISTERED_SCENE_COUNT){
        return 0;
    }

    uint32_t sceneIndex = sRegistry->count;
    sRegistry->count++;
    SceneDefinition* sDef = &sRegistry->list[sceneIndex];
    sDef->id = sId;
    if(!Arena_SetSceneName(&sRegistry->nameArena, name, &sDef->name)){
        return 0;
    }
    return 1;
}

const SceneDefinition* SRegistry_GetScene(const SceneRegistry* reg, SceneId id){

}