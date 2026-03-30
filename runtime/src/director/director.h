#pragma once

#include <stdint.h>




typedef struct GameHooks{
    uint8_t (*On_Update)(void); //During mainloop
    uint8_t (*On_Shutdown)(void); //After mainloop
}GameHooks;

typedef struct Director{
    GameHooks gHooks;
    SceneStack stack;
    SceneRegistry registry;
    VGE_Handler wrapper;
}Director;



uint8_t InitDirector(Director* director);
uint8_t RunUpdateGHook(Director* director);
uint8_t RunShutdownGHook(Director* director);
