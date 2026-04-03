#include "scene__handlers.h"






//Init function and helpers

static inline uint8_t NameArena_Init(NameArena* nArena, size_t arenaSize){
    if(!nArena){
        return 0;
    }

    nArena->length = arenaSize;
    nArena->remaining = arenaSize;
    nArena->namePool = malloc(arenaSize);
    if(!nArena->namePool){
        return 0;
    }

    return 1;
}


static inline uint8_t SceneRegistry_Init(SceneRegistry* sRegistry){
    if(!sRegistry){
        return 0;
    }

    sRegistry->definitionCount = 0;

    return 1;
}

static inline uint8_t ActiveStack_Init(ActiveScenes* aScenes ){
    if(!aScenes){
        return 0;
    }

    aScenes->top = EMPTY_ACTIVE_SCENE_LIST;

    for(int index = 0; index < MAX_ACTIVE_SCENE_COUNT; index++){
        aScenes->stack[index].state = 0;
    }

    return 1;
}



uint8_t SceneHandler_Init(SceneHandler* sHandler){
    if(!sHandler){
        return 0;
    }

    
    ActiveStack_Init(&sHandler->activeList);
    SceneRegistry_Init(&sHandler->sceneList);
    NameArena_Init(&sHandler->nameArena);



    return 1;
}






// Shutdown function and helpers
static inline void NameArena_Shutdown(NameArena* nArena){
    if(!nArena){
        return 0;
    }

    free(nArena->namePool);

    return 1;
}

uint8_t SceneHandler_Shutdown(SceneHandler* sHandler){
    if(!sHandler){
        return 0;
    }

    NameArena_Shutdown(&sHandler->nameArena);
    return 1;
}




// Register new scene
static inline uint8_t Arena_RegisterName(NameArena* nArena, const char* sName, ArenaTag* aTag){
    if(!nArena || !sName || !aTag){
        return 0;
    }


    size_t nameLen = strlen(sName) + 1;

    if(nameLen >= nArena->remaining){
        return 0;
    }

    char* arenaPtr = nArena->namePool + (nArena->length - nArena->remaining);    
    memcpy(arenaPtr, sName, nameLen);
    nArena->remaining -= nameLen;

    aTag->length = nameLen;
    aTag->ptr = arenaPtr;

    return 1;
}


uint8_t SceneHandler_RegisterScene(SceneHandler* sHandler, const SceneId sId, const char* sceneName){
    if(!sHandler || !sceneName){
        return 0;
    }
    SceneRegistry* sRegistry = &sHandler->sceneList;
    if(sRegistry->definitionCount >= (MAX_SCENE_DEF_COUNT - 1)){
        return 0;
    }

    uint32_t definitionIndex = sRegistry->definitionCount;

    SceneDefinition* sDef = &sRegistry->definitionList[definitionIndex];
    sDef->id = sId;
    Arena_RegisterName(&sHandler->nameArena, sceneName, &sDef->name);

    return 1;
}




//Push scene onto active stack


uint8_t SceneHandler_PushActive(SceneHandler* sHandler, const SceneId sId){
    
}