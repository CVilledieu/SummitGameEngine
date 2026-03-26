#include "modeling.h"


#include <stdlib.h>


static inline ClearMeshBlocks(ModelWriter_t* mWriter){
    mWriter->nMeshes = 0;

    for(int i = 0; i < FRAME_INSTANCES_LIMIT; i++){
        MeshBlock_t* block = &mWriter->meshBlocks[i];
        block->firstIndex = 0;
        block->meshId = 0;
        block->nInstances = 0;
    }
}

static inline void ClearModelInstance(ModelInstance_t* instance){
    for (int i = 0; i < FRAME_INSTANCES_LIMIT; i++){
        *instance[i] = 0;
    }
}


uint8_t CreateModelWriter(ModelWriter_t* mWriter, uint8_t){
    mWriter->nModels = 0;
    ClearMeshBlocks(mWriter);

}