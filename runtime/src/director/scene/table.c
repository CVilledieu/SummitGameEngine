#include "scene.h"



void InitSceneTable(SceneTable* sTable){
    sTable->count = 0;
    for(uint32_t idx = 0; idx < DIRECTOR_MAX_SCENES_COUNT; idx++){
        SceneDefinition* sDef = &sTable->defs[idx];
        sDef->id = 0;
    }

}

uint8_t RegisterScene(SceneTable* sTable, const SceneDefinition* def){
    if(!sTable || !def || sTable->count >= DIRECTOR_MAX_SCENES_COUNT){
        return 1;
    }

    


    return 0;
}


const SceneDefinition* GetSceneDefById(const SceneTable* reg, uint32_t id){


}

