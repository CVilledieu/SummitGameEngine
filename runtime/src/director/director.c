#include "director.h"
#include "gamelayer/wrappers.h"
#include "scenes/registry.h"
#include "scenes/active_stack.h"

#include "village/village.h"



uint8_t RunUpdateGHook(Director* director){
    if(!director || !director->gHooks.On_Update){
        return 0;
    }
    director->gHooks.On_Update();
    return 1;
}

uint8_t RunShutdownGHook(Director* director){
    if(!director || !director->gHooks.On_Shutdown){
        return 0;
    }
    director->gHooks.On_Shutdown();
    return 1;
}


uint8_t InitDirector(Director* director){
    InitSceneStack(&director->stack);
    InitSceneRegister(&director->registry);
    if(InitVillageGameEngine(&director->wrapper)){
        return 0;
    }

    return 1;
}