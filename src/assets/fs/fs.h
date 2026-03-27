#pragma once



/*FileSys pathing*/
#define MAX_PATH_LENGTH 260
#define ASSETS_DIR "assets\\"
#define SHADERS_PATH "assets\\shaders\\"

typedef struct FSPath_t{
    char* path;
    uint8_t length;
}FSPath_t;

typedef struct FSReader_t{
    char* relativePath;
    char* fileName;
    uint8_t dataLength;
    uint8_t* data;
}FSReader_t;


uint8_t ReadFile(FSReader_t* reader);
void InitFileSys(void);
void FreeReader(FSReader_t* reader);