#pragma once

#include <stdint.h>
#include "scene_handlers/scene__handlers.h"

typedef struct SceneDirector{
    SceneHandler sHandler;

}SceneDirector;



uint8_t Director_Init(Director* director);
uint8_t Director_RegisternewScene(Director* director, SceneId sId);
uint8_t Director_PushActiveScene(Director* director, SceneId sId);
uint8_t Director_PopActiveScene(Director* director, );
uint8_t Director_PeakActiveScene(Director* director);