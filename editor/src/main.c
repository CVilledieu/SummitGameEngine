#include "village/village.h"
#include <stdlib.h>


void ShutdownGameLayer(void){

}

void UpdateGameLayer(void){

}

uint8_t InitVillageGameEngine(VeCtx* vgeHandler){
    if(!vgeHandler){
        return 0; 
    
    }
    VGESetCallback_Update(vgeHandler, UpdateGameLayer);
    VGESetCallback_Shutdown(vgeHandler, ShutdownGameLayer);
}


