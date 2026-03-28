#pragma once

#include <stdint.h>
#include "scene/table.h"
#include "scene/stack.h"


typedef struct Director {
    SceneTable table;
    SceneStack stack;

    uint8_t isTransitioning;
} Director;

uint8_t Director_Init(Director* d);

uint8_t Director_RegisterScene(Director* d, const SceneDefinition* def);

uint8_t Director_PushScene(Director* d, uint32_t id, SceneContext* ctx);
uint8_t Director_PopScene(Director* d, SceneContext* ctx);
uint8_t Director_SwitchScene(Director* d, uint32_t id, SceneContext* ctx);

void Director_Update(Director* d, SceneContext* ctx, float dt);
void Director_Render(Director* d, SceneContext* ctx);