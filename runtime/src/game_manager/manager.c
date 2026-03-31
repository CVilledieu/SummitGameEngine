#include "manager.h"
#include "village_api/wrappers.h"


uint8_t GameContextManager_Init(GCManager* gm){
    if(!gm){
        return 0;
    }
    gm->gHooks.On_Update = NULL;
    gm->gHooks.On_Shutdown = NULL;
    
    

    return 1;
}

// void SetVGECallback_StartUp(GCManager* gm, void (*funcPtr)(void)){
//     gm->gHooks.On_StartUp 
// }

uint8_t GCManager_StartUp(GCManager* gm){
    if(!gm || !gm->gHooks.On_StartUp){
        return 0;
    }

    gm->gHooks.On_StartUp();
    return 1;
}




uint8_t GCManager_Update(GCManager* gm){
    if(!gm || !gm->gHooks.On_Update){
        return 0;
    }
    gm->gHooks.On_Update();
    return 1;
}

uint8_t GCManager_Shutdown(GCManager* gm){
    if(!gm || !gm->gHooks.On_Shutdown){
        return 0;
    }
    gm->gHooks.On_Shutdown();
    return 1;
}

