#include "engine/root.h"


int main(void){
    REC_t* engine = InitEngine("My 2D Game!");


    StartEngine(&engine);
}