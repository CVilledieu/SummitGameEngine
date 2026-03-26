#pragma once

#include <stdint.h>
#include "glad/glad.h"


#define MODEL_

typedef float ModelInstance_t[2];


#ifndef ENGINE_SCENE_CONFIG
#define ENGINE_SCENE_CONFIG 1

#define MAX_SCENES 64
#endif //ENGINE_SCENE_CONFIG





#ifndef MY_RENDERER_CONFIG
#define MY_RENDERER_CONFIG 1


#define MAX_MESH_TYPES 128

#define MODEL_INDEX_LENGTH 2 // X,Y
#define MODEL_INDEX_TYPE float
#define MODEL_INDEX_BYTES sizeof(MODEL_INDEX_TYPE) 




#define MODEL_SIZE (MODEL_INDEX_LENGTH * MODEL_INDEX_SIZE)
#define INSTANCE_LIMIT 128

#define MODELING_SIZE (INSTANCE_LIMIT * MODEL_SIZE)
#define LIGHTING_SIZE 0 //Place holder, because I dont have lighting added
#define PEAK_FRAME_LENGTH (MODELING_SIZE + LIGHTING_SIZE)
#define SLICE_HEADROOM 1 //Recommend is 1.25 or 1.5 (125%/150% of Peak)
#define FRAME_SLICE_LENGTH (PEAK_FRAME_LENGTH * SLICE_HEADROOM)
#define N_BUFFERED_FRAMES 3
#define MAX_BUFFER_LENGTH (N_BUFFERED_FRAMES * FRAME_SLICE_LENGTH)


#define BUFFER_GL_MAP_OPTIONS (GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT) 
#define FENCE_DELAY_VALUE 1000000ULL


#define MODEL_BINDING_INDEX 0
#define LIGHT_BINDING_INDEX 1



#endif //MY_RENDERER_CONFIG

