#include "director.h"
#include <stdlib.h>
#include <stdint.h>


uint8_t DeleteScene(Director_t* director){
    if(director == NULL && director->next < MAX_SCENES ){
        return 1;
    }

    director->next++;
    StackId_t stackId = director->next;


}


Scene_t* CreateNewScene(Director_t* director){
    if(director == NULL || director->next == EMPTY_STACK){
        return NULL;
    }

    SceneId_t sceneId = director->stack[director->next];
    director->next--;
    return &director->scenes[sceneId];

}





uint8_t InitDirector(Director_t* director){
    if(director == NULL){
        return 1;
    }

    director->next = MAX_SCENES;
    for (uint8_t index = 0; index < MAX_SCENES; index++){
        director->stack[index] = index;
        director->scenes[index].id = index;
    }

    return 0;
}
