#pragma once

#include <stdint.h>
#include "village_api/wrappers.h"



// typedef struct SceneHooks{
//     uint8_t (*On_Init)(VGE_Scene* vgeScene);
//     void (*On_Update)(VGE_Scene* vgeScene);
//     void (*On_Render)(VGE_Scene* vgeScene);
//     void (*On_Shutdown)(VGE_Scene* vgeScene);
// }SceneHooks;

typedef struct SceneHooks SceneHooks;

typedef struct GameHooks{
    uint8_t (*On_StartUp)(VeCtx* vCtx); //Before mainloop
    uint8_t (*On_Update)(VeCtx* vCtx); //During mainloop
    uint8_t (*On_Shutdown)(VeCtx* vCtx); //After mainloop
}GameHooks;

typedef struct GCManager{
    SceneHooks* hooks;
    GameHooks gHooks;
    VeCtx wrapper;
}GCManager;


// Manager Runtime functions
uint8_t GameContextManager_Init(GCManager* gcm);
uint8_t GCManager_StartUp(GCManager* gm);
uint8_t GCManager_Update(GCManager* gcm);
uint8_t GCManager_Shutdown(GCManager* gcm);



//


