#pragma once

#include <stdint.h>
#include "rt_types.h"


#define EMPTY_STACK -1


typedef int32_t StackId_t;

typedef struct Director_t {
    StackId_t next;
    SceneId_t stack[MAX_SCENES];
    Scene_t scenes[MAX_SCENES];
} Director_t;


uint8_t InitDirector(Director_t* director);
Scene_t* CreateNewScene(Director_t* manager);