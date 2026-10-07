//---------------------------------------------------------
// file:    CP_Metal.m
// author:   Hazel Benting
// brief:    Creating and managing windows with Metal
//
// Copyright � 2026 DigiPen, All rights reserved.
//---------------------------------------------------------

#include "Internal_Metal.h"
#include "Internal_Color.h"

#define kMaxFramesInFlight 3

@implementation Metal4Renderer {
    
    uint64_t frameNumber;
    simd_uint2 viewPortSize;
    
    id<MTL4CommandQueue> commandQueue;
    id<MTL4CommandBuffer> commandBuffer;
    id<MTLResidencySet> residencySet;
    id<MTL4ArgumentTable> argumentTable;
    id<MTLSharedEvent> sharedEvent;
    id<MTLBuffer> viewportsizeBuffer;
    id<MTLRenderPipelineState> renderPipelineState;
    
    NSArray<id<MTL4CommandAllocator>> *commandAllocator;
    NSArray<id<MTLBuffer>> *vertexTriangleBuffers;
}

- (nonnull instancetype) initWithMetalKitView:(nonnull MTKView *)view {
    self = [super init];
    if (nil == self) { return nil;}
    
    _device = view.device;
    commandQueue = [self.device newMTL4CommandQueue];
    commandBuffer = [self.device newCommandBuffer];
    _defaultLibrary = [self.device newDefaultLibrary];
    
    vertexTriangleBuffers = [self makeTriangleDataBuffers:kMaxFramesInFlight];
    argumentTable = [self makeArgumentTable];
    residencySet = [self makeResidenceSet];
    commandAllocator = [self makeCommandAllocators:kMaxFramesInFlight];
    
    viewportsizeBuffer = [self.device newBufferWithLength:sizeof(viewPortSize) options:MTLResourceStorageModeShared];
    
    renderPipelineState = [self compileRenderPipeline:view.colorPixelFormat];
    
    frameNumber = 0;
    
    sharedEvent = [self.device newSharedEvent];
    sharedEvent.signaledValue = frameNumber;
    
    [residencySet commit];
    
    [commandQueue addResidencySet:residencySet];
    [commandQueue addResidencySet:((CAMetalLayer *)view.layer).residencySet];
    
    [self updateViewPortSize:view.drawableSize];
    
    return self;
}

- (void) updateViewPortSize:(CGSize) size {
    viewPortSize.x = size.width;
    viewPortSize.y = size.height;
    
    memcpy(viewportsizeBuffer.contents, &viewPortSize, sizeof(viewPortSize));
}

- (void) renderFrametoView:(nonnull MTKView *) view {
    if ([self isMissingRequirementsFromView:view]) { return ; }
    
    frameNumber += 1;
    
    const uint32_t frameIndex = frameNumber % kMaxFramesInFlight;
    NSString *label = [NSString stringWithFormat:@"Frame %llu", frameNumber];
    
    if (frameNumber < kMaxFramesInFlight) {
        [self waitOnSharedEvent:sharedEvent forEarlierFrame:frameNumber - kMaxFramesInFlight];
    }
    
    id<MTL4CommandAllocator> frameAllocator = commandAllocator[frameIndex];
    [frameAllocator reset];
    
    [commandBuffer beginCommandBufferWithAllocator:frameAllocator];
    commandBuffer.label = label;
    
    id<MTL4RenderCommandEncoder> renderPassEncoder;
    MTL4RenderPassDescriptor *configuration = view.currentMTL4RenderPassDescriptor;
    renderPassEncoder = [commandBuffer renderCommandEncoderWithDescriptor:configuration];
    renderPassEncoder.label = label;
    
    [renderPassEncoder setRenderPipelineState:renderPipelineState];
    
    [self setViewportSize:viewPortSize forRenderEncoder:renderPassEncoder];
    [self setRenderPassArguments:renderPassEncoder
                        forFrame:frameNumber
                            with:argumentTable
                    vertexBuffer:vertexTriangleBuffers[frameIndex]
                    viewPortSize:viewportsizeBuffer];
    
    [renderPassEncoder drawPrimitives:MTLPrimitiveTypeTriangle vertexStart:0 vertexCount:3];
    
    [renderPassEncoder endEncoding];
    
    [commandBuffer endCommandBuffer];
    
    [self submitCommandBuffer:commandBuffer toCommandQueue:commandQueue forView:view];
    
    [commandQueue signalEvent:sharedEvent value:frameNumber];
        
}

- (bool) isMissingRequirementsFromView:(nonnull MTKView *) view{
    bool drawableMissing = false;
    bool renderPassDescriptorMissing = false;
    
    if (nil == view.currentDrawable) {
        NSLog(@"The view doesn't have a drawable view");
        drawableMissing = true;
    }
    if (nil == view.currentMTL4RenderPassDescriptor) {
        NSLog(@"The doesn't have a render pass descriptor for metal");
        renderPassDescriptorMissing = true;
    }
    
    return drawableMissing || renderPassDescriptorMissing;
}

@end

@implementation Metal4Renderer (Setup)

- (nonnull NSArray<id<MTLBuffer>> *) makeTriangleDataBuffers:(NSUInteger)count {
    
    NSMutableArray<id<MTLBuffer>> *bufferArray;
    bufferArray = [[NSMutableArray alloc] initWithCapacity:count];
    for (uint bufferNumber = 0; bufferNumber < count; bufferNumber += 1) {
        id<MTLBuffer> buffer;
        buffer = [self.device newBufferWithLength:sizeof(TriangleData) options:MTLResourceStorageModeShared];
    }
    
    return bufferArray;

}

@end
