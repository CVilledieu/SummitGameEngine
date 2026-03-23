#include "root.h"




int main(void){
    RoadEngine_t mainEng = {0};

    InitEngine("My 2D Game!", &mainEng);


    RunMainLoop();

    return 0;
}