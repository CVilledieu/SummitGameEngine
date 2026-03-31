#include "director.h"
#include "scene_registry.h"
#include "active_stack.h"


#include "village/village.h"




uint8_t InitDirector(Director* director){
    InitSceneStack(&director->stack);
    InitSceneRegister(&director->registry);

    return 1;
}