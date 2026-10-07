//------------------------------------------------------------------------------
// file:	Internal_Color.h
// author:	Daniel Hamilton
// brief:	Internal header for color related functions
//
// INTERNAL USE ONLY, DO NOT DISTRIBUTE
//
// Copyright � 2026 DigiPen, All rights reserved.
//------------------------------------------------------------------------------

#pragma once

#include "Internal_Graphics.h"
#ifndef TriangleData_h
#define TriangleData_h

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Defines:
//------------------------------------------------------------------------------

typedef struct TriangleData {
    VertexData vertex0;
    VertexData vertex1;
    VertexData vertex2;
}
TriangleData;

void configureVertexDataForBuffer(long rotationInDegrees, void *bufferContents);

#endif
