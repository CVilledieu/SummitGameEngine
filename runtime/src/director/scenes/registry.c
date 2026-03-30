#include "registry.h"
#include "gamelayer/wrappers.h"
#include "string.h"

uint8_t InitSceneRegistry(SceneRegistry* sRegistry){
    if(!sRegistry){
        return 0;
    }
    sRegistry->count = 0;

    for(int i = 0; i < MAX_REGISTERED_SCENE_COUNT; i++){
        sRegistry->list[i].id = 0;
    }
    return 1;
}

uint8_t RegisterNewScene(SceneRegistry* sRegistry, SceneId sId, const char* name){
    if(!sRegistry || sRegistry->count >= MAX_REGISTERED_SCENE_COUNT){
        return 0;
    }

    uint32_t sceneIndex = sRegistry->count;
    sRegistry->count++;
    SceneDefinition* sDef = &sRegistry->list[sceneIndex];
    sDef->id = sId;
    size_t nameLen = strlen(name) + 1;
    sDef->name = malloc(nameLen);
    memcpy(sDef->name, name, nameLen);
    return 1;
}

const SceneDefinition* GetRegisteredScene(const SceneRegistry* reg, SceneId id){

}