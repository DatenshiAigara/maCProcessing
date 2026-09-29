//------------------------------------------------------------------------------
// file:    Internal_Graphics.h
// author:  Hazel Benting
// brief:   Set-Up for Metal API
//
// Copyright � 2026DigiPen, All rights reserved.
//------------------------------------------------------------------------------
#pragma once

#include <simd/simd.h>

#ifdef __cplusplus
extern "C" {
#endif

//Set Up for Metal Shaders
#ifndef ShaderTypes_h
#define ShaderTypes_h

typedef enum InputBufferIndex {
    
    InputBufferIndexforVertexData = 0,
    
    InputBufferIndexForViewportSize = 1,
    
} InputBufferIndex;

typedef struct {
    
    simd_float2 position;
    
    simd_float4 color;
    
} VertexData;

#endif

#ifdef __cplusplus
extern "C" {
#endif
