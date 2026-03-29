#include "scene.h"
#include "common/engine_config.h"
#include "string.h"

void SceneRegistry_Init(SceneRegistry* sr){
    sr->count = 0;
    for(uint32_t idx = 0; idx < DIRECTOR_MAX_SCENES_COUNT; idx++){
        SceneDefinition* sDef = &sr->defs[idx];
        sDef->id = 0;
    }

}


uint8_t SceneRegistry_NewScene(SceneRegistry* sr, const SceneDefinition* callerDef){
    if(!sr || !callerDef || sr->count >= DIRECTOR_MAX_SCENES_COUNT){
        return 0;
    }

    uint16_t tableIdx = sr->count;
    SceneDefinition* regDef = &sr->defs[tableIdx];
    memcpy(regDef, callerDef, sizeof(SceneDefinition));
    sr->count++;
    
    return 1;
}


const SceneDefinition* SceneRegistry_GetSceneDef(const SceneRegistry* sr, SceneId id){
    if(!sr){
        return NULL;
    }

    for(uint16_t i = 0; i < sr->count; i++){
        if (sr->defs[i].id == id){
            return &sr->defs[i];
        }
    }

    return NULL;
}

