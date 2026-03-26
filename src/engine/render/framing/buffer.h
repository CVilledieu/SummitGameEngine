#pragma once

#include "internal_config.h"


typedef struct FrameState_t{
    size_t index;
    GLsync fence;
}FrameState_t;


typedef struct FameBuffer_t{
    uint8_t currentFrame;
    uint16_t bufferID;
    FrameState_t frameStates[N_BUFFERED_FRAMES];
    uint8_t* buffer;
}FameBuffer_t;

uint8_t InitFBuffer(FameBuffer_t* sBuffer);