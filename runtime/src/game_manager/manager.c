#include "manager.h"
#include "village_api/wrappers.h"


uint8_t InitBridgeManager(GameManager* gm){
    if(!gm){
        return 0;
    }
    if(!InitVillageGameEngine(&gm->wrapper)){
        return 0;
    }

    return 1;
}


uint8_t RunUpdateGHook(GameManager* gm){
    if(!gm || !gm->gHooks.On_Update){
        return 0;
    }
    gm->gHooks.On_Update();
    return 1;
}

uint8_t RunShutdownGHook(GameManager* gm){
    if(!gm || !gm->gHooks.On_Shutdown){
        return 0;
    }
    gm->gHooks.On_Shutdown();
    return 1;
}

