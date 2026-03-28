#include "scene.h"


void InitStack(SceneStack* stack){
    stack->top = DIRECTOR_MAX_SCENES_COUNT;
    for(int i = 0; i < DIRECTOR_MAX_SCENES_COUNT; i++){
        stack->list[i] = 0;
    }
}



uint8_t PushStack(SceneStack* stack, uint32_t id){
    if(!stack || stack->top >= DIRECTOR_MAX_SCENES_COUNT){
        return 1;
    }

    stack->top--;
    stack->list[stack->top] = id;
    return 0;
}

uint8_t PopStack(SceneStack* stack, uint32_t* outId){
    if(!stack || stack->top == DIRECTOR_EMPTY_STACK){
        return 1;
    }
    *outId = stack->list[stack->top];
    stack->top++;

    return 0;
}

uint8_t PeekStack(const SceneStack* stack, uint32_t* outId){
    if(!stack || !outId){
        return 1;
    }
    *outId = stack->list[stack->top];
    return 0;
}