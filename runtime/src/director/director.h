#pragma once

typedef enum DirectorState{
    DS_STANDBY = 0, 
    DS_TRANSITIONING = 1,
}DirectorState;

typedef struct Director {
    SceneRegistry registry;
    SceneStack stack;
    
    // Replaced transitioning flag with director state
    // uint8_t isTransitioning;
    DirectorState state;
} Director;

uint8_t Director_Init(Director* director);

uint8_t Director_RegisterScene(Director* d, const SceneDefinition* def);

uint8_t Director_PushScene(Director* d, SceneId id, SceneContext* ctx);
uint8_t Director_PopScene(Director* d, SceneContext* ctx);
uint8_t Director_SwitchScene(Director* d, SceneId id, SceneContext* ctx);

void Director_Update(Director* d, SceneContext* ctx, float dt);
void Director_Render(Director* d, SceneContext* ctx);