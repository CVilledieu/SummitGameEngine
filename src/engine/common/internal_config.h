#pragma once

#include <stdint.h>




// 
// Scene system config

//
// Director
#ifndef MAX_MESH_PER_SCENE
#define SCENE_MESH_LIMIT 128
#endif    


#ifndef MAX_MODELS_PER_SCENE
#define MAX_MODELS_PER_SCENE 128
#endif

#ifndef MODEL_VEC
#define MODEL_VEC 2
#endif


#ifndef MAX_SCENES
#define MAX_SCENES 64
#endif


//
//
// Render system config


//
// Frame 
typedef uint8_t ModelInstance_t[MODEL_VEC];

#ifndef FRAME_INSTANCES_LIMIT
#define FRAME_INSTANCES_LIMIT 128
#endif


//
// Buffer
#ifndef SSBUFFER_CONFIG
#define SSBUFFER_CONFIG 1

#define N_BUFFERED_FRAMES 3
#endif //SSBUFFER_CONFIG




//
// Shaders
#ifndef SSBO_BINDINGS_CONFIG
#define SSBO_BINDINGS_CONFIG 1

#define MODEL_BINDING_INDEX 0
#define LIGHT_BINDING_INDEX 1
#endif //SSBO_BINDINGS_CONFIG

