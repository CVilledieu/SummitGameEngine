#pragma once

#include <stdint.h>
#include "common/engine_config.h"
#include "common/engine_types.h"



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
    uint32_t id;
    const char* name;
    SceneHooks hooks;
} SceneDefinition;

typedef struct SceneStack {
    uint32_t list[DIRECTOR_MAX_SCENES_COUNT];
    int32_t top; /* -1 means empty */
} SceneStack;


typedef struct SceneTable {
    SceneDefinition defs[DIRECTOR_MAX_SCENES_COUNT];
    uint16_t count;
} SceneTable;



/* Hook API*/


/*Stack API*/
void InitStack(SceneStack* stack);
uint8_t PushStack(SceneStack* stack, uint32_t id);
uint8_t PopStack(SceneStack* stack, uint32_t* outId);
uint8_t PeekStack(const SceneStack* stack, uint32_t* outId);

/* Table API*/
void InitSceneTable(SceneTable* reg);
uint8_t RegisterScene(SceneTable* reg, const SceneDefinition* def);
const SceneDefinition* GetSceneDefById(const SceneTable* reg, uint32_t id);


