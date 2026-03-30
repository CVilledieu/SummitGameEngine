#include "arena.h"
#include <stdlib.h>
#include <string.h>

uint8_t InitArena(Arena* arena, size_t initLength){
    if(!arena || !initLength){
        return 0;
    }

    arena->remaining = initLength;
    arena->length = initLength;
    arena->stringPool = malloc(initLength);
    if(!arena->stringPool){
        return 0;
    }

    return 1;
}


uint8_t CloseArena(Arena* arena){
    if(!arena){
        return 0;
    }

    free(arena->stringPool);

    return 1;
}

uint8_t Arena_SetSceneName(Arena* arena, const char* name, ATag* dest){
    if(!arena || !name || !dest){
        return 0;
    }

    size_t nameLen = strlen(name) + 1;

    if(nameLen >= arena->remaining){
        return 0;
    }

    char* arenaPtr = arena->stringPool + (arena->length - arena->remaining);
    memcpy(arenaPtr, name, nameLen);
    arena->remaining -= nameLen;

    dest->length = nameLen;
    dest->ptr = arenaPtr;

    return 1;
}


