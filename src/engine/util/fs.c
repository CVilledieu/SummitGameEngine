#include "fs.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif

/*FileSys pathing*/
#define MAX_PATH_LENGTH 260
#define ASSETS_DIR "assets\\"
#define SHADER_DIR "shaders\\"

FSPath_t rootPath = {0};


static inline void BuildFullPath(FSReader_t* reader, FSPath_t* dest){ 
    switch(reader->targetType){
        case FS_SHADER:
            snprintf(dest->path, dest->length, "%s%s%s", rootPath.path, SHADER_DIR, reader->fName);
            break;
        default:
            break;
    }
}



// Caller is responsible for freeing memory
uint8_t ReadFile(FSReader_t* reader){
    if (reader == NULL) {
        return 0;
    }
    uint32_t pathLen = rootPath.length + strlen(SHADER_DIR) + strlen(reader->fName) + 1;
    FSPath_t filePath = {
        .length = pathLen,
        .path = malloc(pathLen),
    };

    BuildFullPath(reader, &filePath);
    
    FILE* fp = fopen(filePath.path, "rb");
    if(fp == NULL){
        free(filePath.path);
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    uint32_t size = ftell(fp);
    rewind(fp);
    
    reader->data = malloc(size + 1);
    if (reader->data == NULL) {
        fclose(fp);
        return 0;
    }

    size_t bytesRead = fread(reader->data, 1, size, fp);
    reader->data[bytesRead] = '\0';
    fclose(fp);
    free(filePath.path);

    reader->dataLength = size;

    return 1;
}



void InitFileSys(void){
    char tempBuffer[MAX_PATH_LENGTH];
    uint32_t bufferLength = 0;
    // Load full app path into buffer. This includes .exe file
    #ifdef _WIN32
        GetModuleFileNameA(NULL, tempBuffer, MAX_PATH_LENGTH);
    #else
        // Do nothing for now? ill deal with this later
        // readlink("/proc/self/exe", tempBuffer, MAX_PATH_LENGTH);
    #endif


    for (uint32_t i = 0; tempBuffer[i] != '\0'; i++) {
        if (tempBuffer[i] == '\\')
            bufferLength = i + 1;
    }

    rootPath.length = bufferLength;
    rootPath.path = malloc(sizeof(char) * bufferLength + 1);
    memcpy(rootPath.path, tempBuffer, bufferLength);
    rootPath.path[bufferLength] = '\0';
}
