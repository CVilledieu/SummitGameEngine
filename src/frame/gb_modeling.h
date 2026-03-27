#pragma once


#include "engine_config.h"


typedef struct MeshBlock_t{
    uint16_t MeshHandle_t;
    uint16_t instanceCount;
    size_t offset;
}MeshBlock_t;



typedef struct ModelWriter_t{
    uint32_t meshCount;
    uint32_t modelCount;
    MeshBlock_t meshBlocks[MAX_MESHES_PER_FRAME];
    ModelData_t modelData[MAX_MODELS_COUNT_PER_FRAME];
} ModelWriter_t;

uint8_t InitModelWriter(ModelWriter_t* mWriter);