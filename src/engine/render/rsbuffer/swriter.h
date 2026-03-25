#pragma once

#include <stdint.h>

#define MAX_DIRTY_CHUNKS 10 // After getting to max the full slice will be rewritten

typedef struct DirtyChunk_t{
    uint32_t offset;
    uint32_t length;
}DirtyChunk_t;

typedef struct MeshBlock_t{
    uint32_t meshId;
    uint32_t nInstances;
    uint32_t offset;
}MeshBlock_t;


typedef struct SliceWriter_t{
    uint8_t nDirtyChunks;
    uint8_t nMeshes;
    DirtyChunk_t dirtyChunks[MAX_DIRTY_CHUNKS];
    MeshBlock_t* meshBlocks;
    size_t length;
    void* data;
}SliceWriter_t;


void InitSliceWriter(SliceWriter_t* sWriter);