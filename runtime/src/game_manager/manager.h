#pragma once

#include <stdint.h>


typedef struct SceneHooks{
    uint8_t (*On_Init)(VGE_Scene* vgeScene);
    void (*On_Update)(VGE_Scene* vgeScene);
    void (*On_Render)(VGE_Scene* vgeScene);
    void (*On_Shutdown)(VGE_Scene* vgeScene);
}SceneHooks;

typedef struct GameHooks{
    uint8_t (*On_Update)(void); //During mainloop
    uint8_t (*On_Shutdown)(void); //After mainloop
}GameHooks;

typedef struct GameManager{
    SceneHooks* hooks;
    GameHooks gHooks;
    VGE_Handler wrapper;
}GameManager;