#pragma once

/* Primary header for asset system
    handles "what exists on disk and how to load it"

*/
#include "engine_config.h"

typedef enum AssetType_e{
    
}AssetType_e;

typedef struct Asset_t{
    uint32_t id;
    char* fileName;

}Asset_t;

typedef struct InactiveAssets_t{

}InactiveAssets_t;

typedef struct ActiveAssets_t{

}ActiveAssets_t;

typedef struct AssMan_t{
    uint32_t assetCount;
    Asset_t* assetList;
}AssMan_t;