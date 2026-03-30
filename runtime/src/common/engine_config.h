#pragma once

//Add a second file specifically for what should be adjusted?
#include "common/VGE_types.h"



#ifndef MAX_SCENE_REGISTER_COUNT
#define MAX_SCENE_REGISTER_COUNT 64
#endif






#ifndef MAX_REGISTERED_MESHES
#define MAX_REGISTERED_MESHES 256
#endif





//Renderer config
#ifndef BUFFER_SLICE_COUNT
#define BUFFER_SLICE_COUNT 3
#endif


// Should this be a single macro? 
#ifndef MAX_MESHES_PER_FRAME
#define MAX_MESHES_PER_FRAME 256
#define MAX_MODELS_COUNT_PER_FRAME MAX_MESHES_PER_FRAME
#endif


#define PEAK_OBJECT_BYTES ((size_t)MAX_MODELS_COUNT_PER_FRAME * sizeof(ModelData_t))
#define PEAK_LIGHTING_BYTES (size_t)0 //Place holder, because I dont have lighting added

#define PEAK_BYTES_PER_FRAME (PEAK_OBJECT_BYTES + PEAK_LIGHTING_BYTES)

//Recommend headroom was 1.25 or 1.5 achieving 1.25 by multiplying by 5/4
#define HEADROOM_FACTOR_TOP (size_t)5
#define HEADROOM_FACTOR_BOTTOM (size_t)4

#define BYTES_PER_SLICE ((PEAK_BYTES_PER_FRAME * HEADROOM_FACTOR_TOP) / HEADROOM_FACTOR_BOTTOM )
#define TOTAL_BUFFER_BYTES (BUFFER_SLICE_COUNT * (size_t)BYTES_PER_SLICE)


#define BUFFER_STORAGE_GL_FLAGS (GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT) 
#define BUFFER_MAP_GL_FLAGS (GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT)

#define FENCE_SYNC_TIMEOUT 1000000ULL
#define MODEL_BINDING_INDEX 0
#define LIGHT_BINDING_INDEX 1
//end Renderer config


