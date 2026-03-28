#pragma once


#include "common/engine_config.h"

typedef struct SceneStack {
    uint32_t ids[DIRECTOR_MAX_SCENES_COUNT];
    int32_t top; /* -1 means empty */
} SceneStack;



void InitStack(SceneStack* stack);
uint8_t PushStack(SceneStack* stack, uint32_t id);
uint8_t PopStack(SceneStack* stack, uint32_t* outId);
uint8_t PeekStack(const SceneStack* stack, uint32_t* outId);