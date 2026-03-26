#include "gb_modeling.h"


static inline ClearMeshBlocks(ModelWriter_t* mWriter){
    mWriter->meshCount = 0;
    
    for(int i = 0; i < MAX_MESHES_PER_FRAME; i++){
        MeshBlock_t* block = &mWriter->meshBlocks[i];
        block->offset = 0;
        block->meshId = 0;
        block->instanceCount = 0;
    }
}

static inline void ClearObjectData(ModelData_t* instance){
    for (int i = 0; i < MAX_MODELS_COUNT_PER_FRAME; i++){
        *instance[i] = 0;
    }
}





uint8_t InitModelWriter(ModelWriter_t* mWriter){
    mWriter->modelCount = 0;
    ClearMeshBlocks(mWriter);
    
}