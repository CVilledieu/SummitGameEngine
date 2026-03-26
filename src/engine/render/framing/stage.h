#pragma once

#include "internal_config.h"



typedef struct MeshBlock_t{
    uint8_t meshId;
    uint8_t nInstances;
    uint8_t firstIndex;
}MeshBlock_t;



typedef struct ModelWriter_t{
    uint8_t nMeshes;
    uint8_t nModels;
    MeshBlock_t meshBlocks[MAX_MESH_TYPES];
    ModelInstance_t instanceList[INSTANCE_LIMIT];
} ModelWriter_t;


