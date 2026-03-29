#include "director.h"
#include "scene.h"
#include "common/engine_config.h"



uint8_t Director_Init(Director* director){
    if(!director){
        return 0;
    }
    director->state = DS_STANDBY;
    InitRegistry(&director->registry);
    SceneStack_Init(&director->stack);

    return 1;
}


uint8_t Director_RegisterScene(Director* director, const SceneDefinition* def){
    if(!director || !def){
        return 0;
    }
    if(!SceneRegistry_NewScene(&director->registry, def)){
        return 0;
    }
    return 1;
}

uint8_t Director_PushScene(Director* director, SceneId id, SceneContext* ctx){
    if(!director || !ctx){
        return 0;
    }

    SceneStack_Push(&director->stack, id);
    return 1;
}

uint8_t Director_SwitchScene(Director* director, SceneId id, SceneContext* ctx){

}




void Director_Update(Director* director, SceneContext* ctx, float dt){

}

void Director_Render(Director* d, SceneContext* ctx){

}