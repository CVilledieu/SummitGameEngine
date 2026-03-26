#pragma once

#include "glad/glad.h"

#define N_BUFFERED_FRAMES 3

typedef struct Frame_t{
    size_t offset;
    GLsync fence;
}Frame_t;


typedef struct FameBuffer_t{
    uint8_t currentFrame;
    uint16_t bufferID;
    size_t maxFrameSize;
    Frame_t frameList[N_BUFFERED_FRAMES];
    uint8_t* buffer;
}FameBuffer_t;

uint8_t CreateSBuffer(FameBuffer_t* sBuffer, size_t sliceSize);