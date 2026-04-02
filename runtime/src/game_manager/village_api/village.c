#include "wrappers.h"
#include "village/village.h"
#include "game_manager/manager.h"
#include "common/vge_types.h"





uint8_t VGESetEngineCallback_StartUp(void (*startCB)(void)){
    if(!startCB){
        return 0;
    }
    

    return 1;
}

uint8_t VGESetEngineCallback_Update(void (*updateCB)(void)){
    if(!updateCB){
        return 0;
    }
    SetVGECallback_Update(&vgeHandler->unwrapped, updateCB);
    return 1;
}

uint8_t VGESetEngineCallback_Shutdown(void (*shutdownCB)(void)){
    if(!shutdownCB){
        return 0;
    }
    SetVGECallback_Shutdown(&vgeHandler->unwrapped, shutdownCB);
    return 1;
}

VGE_Scene* VGECreateNewScene(const char* sceneName){
    if(!sceneName){
        return 0;
    }
}

void VGESwitchScene(VGE_SceneId sId){
    
}