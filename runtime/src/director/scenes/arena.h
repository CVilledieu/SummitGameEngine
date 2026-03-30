#pragma once

#include <stdint.h>


typedef struct ATag{
    const char* ptr;
    size_t length;
}ATag;

typedef struct Arena{
    size_t length;
    size_t remaining;
    char* stringPool;
}Arena; 




uint8_t InitArena(Arena* arena, size_t initLength);
uint8_t CloseArena(Arena* arena);
uint8_t Arena_SetSceneName(Arena* arena, const char* string, ATag* dest);