#pragma once

#include "common/engine_config.h"


// Types

// Registry typing
typedef struct SceneContext {
    void* game;
    void* engine;
} SceneContext;

typedef struct SceneHooks {
    uint8_t (*on_enter)(SceneContext* ctx);
    void    (*on_exit)(SceneContext* ctx);
    void    (*on_pause)(SceneContext* ctx);
    void    (*on_resume)(SceneContext* ctx);
    void    (*on_update)(SceneContext* ctx, float dt);
    void    (*on_render)(SceneContext* ctx);
} SceneHooks;

typedef struct SceneDefinition {
    SceneId id;
    const char* name;
    SceneHooks hooks;
} SceneDefinition;

typedef struct SceneRegistry {
    SceneDefinition defs[DIRECTOR_MAX_SCENES_COUNT];
    uint16_t count;
} SceneRegistry;



// Stack typing
typedef enum ActiveSceneState{
    WAITING = 0,
    ACTIVE,
}ActiveSceneState;

typedef struct ActiveScene{
    SceneId id;
    ActiveSceneState* state;    
}ActiveScene;

typedef struct SceneStack {
    ActiveScene asList[DIRECTOR_MAX_SCENES_COUNT];
    SceneId list[DIRECTOR_MAX_SCENES_COUNT];
    int32_t top; 
} SceneStack;






// APIs

/* Table API*/
void SceneRegistry_Init(SceneRegistry* reg);
uint8_t SceneRegistry_NewScene(SceneRegistry* reg, const SceneDefinition* def);
const SceneDefinition* SceneRegistry_GetSceneDef(const SceneRegistry* reg, SceneId id);



/*Stack API*/
void SceneStack_Init(SceneStack* stack);
uint8_t SceneStack_Push(SceneStack* stack, SceneId id);
uint8_t SceneStack_Pop(SceneStack* stack, SceneId* outId);
uint8_t SceneStack_Peek(const SceneStack* stack, SceneId* outId);



/* Hook API*/

