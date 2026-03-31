#pragma once

#include <stdint.h>
#include "village_api/wrappers.h"



// typedef struct SceneHooks{
//     uint8_t (*On_Init)(VGE_Scene* vgeScene);
//     void (*On_Update)(VGE_Scene* vgeScene);
//     void (*On_Render)(VGE_Scene* vgeScene);
//     void (*On_Shutdown)(VGE_Scene* vgeScene);
// }SceneHooks;



typedef struct GameHooks{
    uint8_t (*On_StartUp)(void); //Before mainloop
    uint8_t (*On_Update)(void); //During mainloop
    uint8_t (*On_Shutdown)(void); //After mainloop
}GameHooks;

typedef struct GCManager{
    SceneHooks* hooks;
    GameHooks gHooks;
    VGE_Handler wrapper;
}GCManager;


// Manager Runtime functions
uint8_t GameContextManager_Init(GCManager* gcm);
uint8_t GCManager_StartUp(GCManager* gm);
uint8_t GCManager_Update(GCManager* gcm);
uint8_t GCManager_Shutdown(GCManager* gcm);



//


