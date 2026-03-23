#pragma once

#include "common/rt_types.h"

typedef enum FSTarget_t{
    FS_SHADER = 0,
}FSTarget_t;

typedef struct FSPath_t{
    char* path;
    uint32_t length;
}FSPath_t;

typedef struct FSReader_t{
    FSTarget_t targetType;
    char* fName;
    uint32_t dataLength;
    uint8_t* data;
}FSReader_t;

uint8_t ReadFile(FSReader_t* reader);
void InitFileSys(void);
