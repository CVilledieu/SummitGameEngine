#include "wrappers.h"
#include "village/village.h"
#include "director.h"
#include "common/vge_types.h"

uint8_t VGESetCallback_Update(VGE_Handler* vgeHandler, void (*updateCB)(void)){
    if(!vgeHandler || !updateCB){
        return 0;
    }
    SetAPICallback_Update(&vgeHandler->unwrapped);
    return 1;
}

uint8_t VGESetCallback_Shutdown(VGE_Handler* vgeHandler, void (*shutdownCB)(void)){
    if(!vgeHandler || !shutdownCB){
        return 0;
    }
    SetAPICallback_Shutdown(&vgeHandler->unwrapped);
    return 1;
}

VGE_Scene* VGECreateNewScene(VGE_Handler* vgeHandler, const char* sceneName){
    if(!vgeHandler || !sceneName){
        return 0;
    }
}