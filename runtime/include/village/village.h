#pragma once

#include <stdint.h>


//types
typedef uint32_t VGE_SceneId;
typedef struct VGE_Scene VGE_Scene;
typedef struct VeCtx VeCtx;

// Game Context defined
uint8_t Game_Init(VeCtx* vCtx);



// Engine defined

// Manager Callbacks
uint8_t VGESetEngineCallback_StartUp(void (*startCB)(void));
uint8_t VGESetEngineCallback_Update(void (*updateCB)(void));
uint8_t VGESetEngineCallback_Shutdown(void (*shutdownCB)(void));



