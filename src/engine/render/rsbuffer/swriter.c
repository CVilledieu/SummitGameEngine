#include "swriter.h"

static inline void ClearDirtyList(SliceWriter_t* sWriter){
    sWriter->nDirtyChunks = 0;
    for(int i = 0; i < MAX_DIRTY_CHUNKS; i++){
        DirtyChunk_t* chunk = &sWriter->dirtyChunks[i];
        chunk->length = 0;
        chunk->offset = 0;
    }
}

static inline uint8_t NewDirtyIndex(SliceWriter_t* sWriter, uint32_t dirtyIndex){
    if(!sWriter){
        return 0;
    }
    if(sWriter->nDirtyChunks == 0){
        DirtyChunk_t* chunk = &sWriter->dirtyChunks[0];
        chunk->length = 1;
        chunk->offset = dirtyIndex;
    }

    
}


uint8_t NewSliceWriter(SliceWriter_t* sWriter, size_t sliceLength){
    sWriter->length = sliceLength;
    ClearUpdatesList(sWriter);
}