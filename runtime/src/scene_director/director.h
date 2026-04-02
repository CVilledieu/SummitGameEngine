#pragma once

#include <stdint.h>
#include "active_stack.h"
#include "scene_registry.h"


#define MAX_ACTIVE_SCENE_COUNT 32
#define MAX_SCENE_DEF_COUNT 64

typedef struct Director{
    SceneStack stack;
    SceneRegistry registry;
}Director;

typedef struct NameArena{
    size_t length;
    size_t remaining;
    char* namePool;
}NameArena;

typedef struct SceneDirector{
    int32_t top;
    ActiveScene activeList[MAX_ACTIVE_SCENE_COUNT];
    uint32_t defCount;
    SceneDefinition defList[MAX_SCENE_DEF_COUNT];
    NameArena* nameArena;
}SceneDirector;



uint8_t Director_Init(Director* director);
uint8_t Director_RegisternewScene(Director* director, SceneId sId);
uint8_t Director_PushActiveScene(Director* director, SceneId sId);
uint8_t Director_PopActiveScene(Director* director, );
uint8_t Director_PeakActiveScene(Director* director);