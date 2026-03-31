#pragma once

#include <stdint.h>
#include "active_stack.h"
#include "scene_registry.h"


typedef struct Director{
    SceneStack stack;
    SceneRegistry registry;
}Director;



uint8_t Director_Init(Director* director);
uint8_t Director_RegisternewScene()