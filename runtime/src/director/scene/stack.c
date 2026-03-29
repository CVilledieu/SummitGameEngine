#include "scene.h"


void SceneStack_Init(SceneStack* stack){
    stack->top = DIRECTOR_EMPTY_STACK;
    for(int i = 0; i < DIRECTOR_MAX_SCENES_COUNT; i++){
        stack->list[i] = 0;
    }
}



uint8_t SceneStack_Push(SceneStack* stack, SceneId id){
    if(!stack || (stack->top + 1) >= DIRECTOR_MAX_SCENES_COUNT){
        return 0;
    }

    stack->top++;
    stack->list[stack->top] = id;
    return 1;
}

uint8_t SceneStack_Pop(SceneStack* stack, SceneId* outId){
    if(!stack || !outId || stack->top == DIRECTOR_EMPTY_STACK){
        return 0;
    }
    *outId = stack->list[stack->top];
    stack->top--;

    return 1;
}

uint8_t SceneStack_Peek(const SceneStack* stack, SceneId* outId){
    if(!stack || !outId || stack->top == DIRECTOR_EMPTY_STACK){
        return 0;
    }
    *outId = stack->list[stack->top];
    return 1;
}