#include "stack.h"


void InitStack(SceneStack* stack){
    stack->top = 0;
    for(int i = 0; i < DIRECTOR_MAX_SCENES_COUNT; i++){
        stack->ids[i] = 0;
    }
}



uint8_t PushStack(SceneStack* stack, uint32_t id){
    if(!stack || stack->top == -1){
        return 1;
    }
    stack->ids[stack->top] = id;
    stack->top++;
    if(stack->top >= DIRECTOR_MAX_SCENES_COUNT){
        stack->top = -1;
    }
    return 0;
}

uint8_t PopStack(SceneStack* stack, uint32_t* outId){
    
}

uint8_t PeekStack(const SceneStack* stack, uint32_t* outId){
    
}