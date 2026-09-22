//---------------------------------------------------------
// file:    CP_Metal.m
// author:   Hazel Benting
// brief:    Creating and managing windows with Metal
//
// Copyright � 2026 DigiPen, All rights reserved.
//---------------------------------------------------------

#include <stdbool.h>
#include "Internal_System.h"

#define kMaxFramesInFlight 3

@implementation Metal4Renderer

    uint64_t frameNumber;
    simd_uint2 viewPortSize;

    id<MTLCommandQueue> commandQueue;
    id<MTLCommandBuffer> commandBuffer;
    id<MTLResidencySet> residencySet;
    id<MTL4ArgumentTable> argumentTable;
    id<MTLSharedEvent> shaderEvents;
    id<MTLBuffer> viewportsizeBuffer;
    id<MTLRenderPipelineState> renderPipelineState;

    NSArray<id<MTL4CommandAllocator>> *commandAllocator;
    NSArray<id<MTLBuffer>> *verticaleTriangleBuffer;
    
@end
