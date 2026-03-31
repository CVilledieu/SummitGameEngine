#pragma once

#include <stdint.h>


//types
typedef uint32_t VGE_SceneId;
typedef struct VGE_Scene VGE_Scene;
typedef struct VGE_Handler VGE_Handler;

// Game Context defined
uint8_t InitVillageGameEngine(VGE_Handler* vgeHandler);



// Engine defined

// Director Callbacks
uint8_t VGESetEngineCallback_Update(void (*updateCB)(void));
uint8_t VGESetEngineCallback_Shutdown(void (*shutdownCB)(void));

// Scene Callbacks


//
VGE_Scene VGECreateNewScene(VGE_Handler* vgeHandler, const char* sceneName);
