#include "fs.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


#ifdef _WIN32
    #include <windows.h>
#endif

FSPath_t rootPath = {0};

void FreeReader(FSReader_t* reader){
    if (reader == NULL){
        return;
    }
    free(reader->data);
}


// Caller is responsible for freeing memory
uint8_t ReadFile(FSReader_t* reader){
    if (reader == NULL) {
        return 0;
    }
    uint16_t bufferLength = rootPath.length + strlen(reader->relativePath) + strlen(reader->fileName) + 1;
    char buffer[bufferLength];


    snprintf(buffer, bufferLength, "%s%s%s", rootPath.path, reader->relativePath, reader->fileName);
    
    FILE* fp = fopen(buffer, "rb");
    if(fp == NULL){
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    uint8_t size = ftell(fp);
    rewind(fp);
    
    reader->data = malloc(size + 1);
    if (reader->data == NULL) {
        fclose(fp);
        return 0;
    }

    size_t bytesRead = fread(reader->data, 1, size, fp);
    reader->data[bytesRead] = '\0';
    fclose(fp);

    reader->dataLength = size;

    return 1;
}



void InitFileSys(void){
    char tempBuffer[MAX_PATH_LENGTH];
    uint8_t bufferLength = 0;
    // Load full app path into buffer. This includes .exe file
    #ifdef _WIN32
        GetModuleFileNameA(NULL, tempBuffer, MAX_PATH_LENGTH);
    #else
        // Do nothing for now? ill deal with this later
        // readlink("/proc/self/exe", tempBuffer, MAX_PATH_LENGTH);
    #endif


    for (uint8_t i = 0; tempBuffer[i] != '\0'; i++) {
        if (tempBuffer[i] == '\\')
            bufferLength = i + 1;
    }

    rootPath.length = bufferLength;
    rootPath.path = malloc(sizeof(char) * bufferLength + 1);
    memcpy(rootPath.path, tempBuffer, bufferLength);
    rootPath.path[bufferLength] = '\0';
}
