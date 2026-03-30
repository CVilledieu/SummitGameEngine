#include "active_stack.h"
#include "common/engine_config.h"



uint8_t InitActiveSceneStack(SceneStack* sStack){
    if(!sStack){
        return 0;
    }
    sStack->top = EMPTY_ACTIVE_SCENE_STACK;

    for(int i = 0; i < MAX_ACTIVE_SCENE_COUNT; i++){
        sStack->scenes[i].state = INACTIVE;
    }

    return 1;
}


uint8_t PushActiveScene(SceneStack* sStack, SceneId sId){
    if(!sStack || sStack->top >= (MAX_ACTIVE_SCENE_COUNT-1)){
        return 0;
    }
    sStack->top++;
    int32_t stackIndex = sStack->top;
    sStack->scenes[stackIndex].id = sId;

    return 1;
}


uint8_t PopActiveScene(SceneStack* sStack, SceneId* sId){
    if(!sStack || !sId || sStack->top == EMPTY_ACTIVE_SCENE_STACK){
        return 0;
    }
    *sId = sStack->scenes[sStack->top].id;
    sStack->top--;

    return 1;
}

uint8_t PeakActiveScene(SceneStack* sStack, SceneId* sId){
    if(!sStack || !sId || sStack->top == EMPTY_ACTIVE_SCENE_STACK){
        return 0;
    }
    *sId = sStack->scenes[sStack->top].id;

    return 1;
}