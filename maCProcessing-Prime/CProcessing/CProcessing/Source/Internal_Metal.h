//------------------------------------------------------------------------------
// file:    Internal_Graphics.h
// author:  Hazel Benting
// brief:   Set-Up for Metal API
//
// Copyright � 2026DigiPen, All rights reserved.
//------------------------------------------------------------------------------

@import AppKit;
@import MetalKit;
@import Metal;

//Set Up for Metal Shaders
/*#ifndef ShaderTypes_h
#define ShaderTypes_h

typedef enum InputBufferIndex {
    
    InputBufferIndexforVertexData = 0,
    
    InputBufferIndexForViewportSize = 1,
    
} InputBufferIndex;

typedef struct {
    
    simd_float2 position;
    
    simd_float4 color;
    
} VertexData;

#endif */

#define PlatformViewController NSViewController

@protocol Renderer<NSObject>

- (nonnull instancetype) initWithMetalKitView:(nonnull MTKView *) view;

- (void) updateViewPortSize:(CGSize) size;

- (void) renderFrametoView:(nonnull MTKView *) view;

@end

//Define interfaces for CP Metal
@interface MetalKitViewDelegate : NSObject<MTKViewDelegate>

- (nonnull instancetype) initWithMetalKitView:(nonnull MTKView *)view;
@end

@interface ViewController : PlatformViewController

@end

//Check if OS is equal to target to see if Metal4 Support is enabled
#if (!TARGET_OS_SIMULATOR)
@interface Metal4Renderer : NSObject<Renderer>
    
//Create device based on renderer for MTL4 specific commands if supported
@property (nonnull, readonly) id<MTLDevice> device;

@property (nonnull, readonly) id<MTLLibrary> defaultLibrary;

@end

@interface Metal4Renderer (Setup)

- (nonnull NSArray<id<MTLBuffer>> *) makeTriangleDataBuffers:(NSUInteger) count;

- (nonnull id<MTL4ArgumentTable>) makeArgumentTable;

- (nonnull id<MTLResidencySet>) makeResidenceSet;

- (nonnull NSArray<id<MTL4CommandAllocator>> *) makeCommandAllocators:(NSUInteger) count;

@end

@interface Metal4Renderer (Encoding)

- (void) waitOnSharedEvent:(nonnull id<MTLSharedEvent>) sharedEvent
           forEarlierFrame:(uint64_t) earlierFrameNumber;

- (void) setViewportSize:(simd_uint2) size
        forRenderEncoder:(nonnull id<MTL4RenderCommandEncoder>) renderPassEncoder;

- (void) setRenderPassArguments:(nonnull id<MTL4RenderCommandEncoder>) renderPassEncoder
                       forFrame:(NSUInteger) frameNumber
                           with:(nonnull id<MTL4ArgumentTable>) argumentTable
                   vertexBuffer:(nonnull id<MTLBuffer>) vertexBuffer
                   viewPortSize:(nonnull id<MTLBuffer>) viewportSizeBuffer;

- (void) submitCommandBuffer:(nonnull id<MTL4CommandBuffer>) commandBuffer
              toCommandQueue:(nonnull id<MTL4CommandQueue>) commandQueue
                     forView:(nonnull MTKView *) view;
@end

@interface Metal4Renderer (Compilation)

- (nonnull id<MTLRenderPipelineState>) compileRenderPipeline:(MTLPixelFormat) colorPixelFormat;

@end

#else

@interface MetalRenderer : NSObject<Renderer>

@property (nonnull, readonly) id<MTLDevice> device;

@end

@interface MetalRenderer (Setup)

- (nonnull NSArray<id<MTLBuffer>> *) makeTriangleDataBuffer:(NSUInteger *) count;

@end

@interface MetalRenderer (Complilation)

- (nonnull id<MTLRenderPipelineState>) compileRenderPipeline:(MTLPixelFormat) colorPixelFormat;

@end

#endif

/*
#include<Foundation/Foundation.h>
#include<QuartzCore/CAMetalLayer.h>
#include<QuartzCore/CAMetalDisplayLink.h>
#include<QuartzCore/CARenderer.h>
#include<Metal/Metal.h>
#include<Metal/MTLHeap.h>
#include<Metal/MTLEvent.h>
#include<Metal/MTLFence.h>
#include<Metal/MTLTypes.h>
#include<Metal/MTLBuffer.h>
#include<Metal/MTLDevice.h>
#include<Metal/MTLTensor.h>
#include<Metal/MTLDefines.h>
#include<Metal/MTLLibrary.h>
#include<Metal/MTLSampler.h>
#include<Metal/MTLTexture.h>
#include<Metal/MTLArgument.h>
#include<Metal/MTLCounters.h>
#include<Metal/MTLDrawable.h>
#include<Metal/MTLPipeline.h>
#include<Metal/MTLResource.h>
#include<Metal/MTLAllocation.h>
#include<Metal/MTLGPUAddress.h>
#include<Metal/MTLIOCompressor.h>
#include<Metal/MTL4Archive.h>
#include<Metal/MTLBlitPass.h>
#include<Metal/MTLDataType.h>
#include<Metal/MTLLogState.h>
#include<Metal/MTL4Compiler.h>
#include<Metal/MTL4Counters.h>
#include<Metal/MTLRenderPass.h>
#include<Metal/MTLComputePass.h>
#include<Metal/MTLFunctionLog.h>
#include<Metal/MTLPixelFormat.h>
#include<Metal/MTLCaptureScope.h>
#include<Metal/MTLCommandQueue.h>
#include<Metal/MTLDepthStencil.h>
#include<Metal/MTLResidencySet.h>
#include<Metal/MTLBinaryArchive.h>
#include<Metal/MTLCommandBuffer.h>
#include<Metal/MTLCaptureManager.h>
#include<Metal/MTLCommandEncoder.h>
#include<Metal/MTLDynamicLibrary.h>
#include<Metal/MTLFunctionHandle.h>
#include<Metal/MTLIOCommandQueue.h>
#include<Metal/MTLRenderPipeline.h>
#include<Metal/MTLArgumentEncoder.h>
#include<Metal/MTLComputePipeline.h>
#include<Metal/MTLIOCommandBuffer.h>
#include<Metal/MTLLinkedFunctions.h>
#include<Metal/MTLVertexDescriptor.h>
#include<Metal/MTLFunctionStitching.h>
#include<Metal/MTLRasterizationRate.h>
#include<Metal/MTLFunctionDescriptor.h>
#include<Metal/MTLDeviceCertification.h>
#include<Metal/MTLAccelerationStructure.h>
#include<Metal/MTL4RenderPass.h>
#include<Metal/MTL4BufferRange.h>
#include<Metal/MTL4CommandQueue.h>
#include<Metal/MTL4CompilerTask.h>
#include<Metal/MTL4ArgumentTable.h>
#include<Metal/MTL4CommandBuffer.h>
#include<Metal/MTL4PipelineState.h>
#include<Metal/MTL4BinaryFunction.h>
#include<Metal/MTL4CommandEncoder.h>
#include<Metal/MTL4CommitFeedback.h>
#include<Metal/MTL4RenderPipeline.h>
#include<Metal/MTL4ComputePipeline.h>
#include<Metal/MTL4CommandAllocator.h>
#include<Metal/MTL4LibraryDescriptor.h>
#include<Metal/MTL4LinkingDescriptor.h>
#include<Metal/MTL4FunctionDescriptor.h>
#include<Metal/MTL4AccelerationStructure.h>
#include<Metal/MTL4MeshRenderPipeline.h>
#include<Metal/MTL4TileRenderPipeline.h>
#include<Metal/MTL4RenderCommandEncoder.h>
#include<Metal/MTL4ComputeCommandEncoder.h>
#include<Metal/MTL4MachineLearningPipeline.h>
#include<Metal/MTL4BinaryFunctionDescriptor.h>
#include<Metal/MTL4LibraryFunctionDescriptor.h>
#include<Metal/MTL4StitchedFunctionDescriptor.h>
#include<Metal/MTL4SpecializedFunctionDescriptor.h>
#include<Metal/MTL4PipelineDataSetSerializer.h>
#include<Metal/MTL4MachineLearningCommandEncoder.h>
#include<MetalKit/MetalKit.h>
#include<MetalKit/MTKView.h>
#include<MetalKit/MTKModel.h>
#include<MetalKit/MTKDefines.h>
#include<MetalKit/MTKTextureLoader.h> */
