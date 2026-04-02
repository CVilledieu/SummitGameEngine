#pragma once

#include <stdint.h>


//types
typedef uint32_t VGE_SceneId;
typedef struct VGE_Scene VGE_Scene;
typedef struct VEngHandler VEngHandler;

// Game Context defined
uint8_t GameLayer_Init(VEngHandler* vEngHandler);
uint8_t GameLayer_Update(VEngHandler* vEngHandler);
uint8_t GameLayer_Shutdown(void);


// Engine defined


