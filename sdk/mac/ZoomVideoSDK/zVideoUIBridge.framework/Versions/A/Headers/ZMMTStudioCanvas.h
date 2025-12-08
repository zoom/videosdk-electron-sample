//
//  ZMMTStudioCanvas.h
//  zStudioUI
//
//  Created by geno.chen on 2021/6/2.
//

#import <Cocoa/Cocoa.h>
#import "ZMMTStudioConstants.h"

#ifdef __cplusplus
#include <zPSApp/media/IPSCanvas.h>
#endif

@class ZMMTStudioRender;
@class ZMMTStudioBizSession;

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTStudioCanvas : NSObject
#ifdef __cplusplus
@property (nonatomic, readonly, nullable)  ps::IPSCanvas *studioCanvas;
#endif
@property (nonatomic, strong, readonly) ZMMTStudioBizSession *bizSession;
@property (nonatomic, assign, readonly) void *canvasHandle;
@property (nonatomic, weak, readonly) ZMMTStudioCanvas *superCanvas;
@property (nonatomic, assign) BOOL transparent;
@property (nonatomic, assign) NSRect frame;
@property (nonatomic, weak) NSColor *backgroundColor;
@property (nonatomic, assign, readonly) CGFloat aspectRatio;
@property (nonatomic, assign) int aspectMode; //SSB_MC_VIDEO_ASPECT_MODE
@property (nonatomic, assign) BOOL canMove;
@property (nonatomic, strong) NSMutableArray * _Nullable subCanvases;
@property (nonatomic, assign) NSInteger tag;
@property (nonatomic, strong, nullable) id representedObject;
@property (nonatomic, assign) NSSize videoRatio;

- (instancetype)initWithCanvasHandle:(void *)canvasHandle superCanvas:(nullable ZMMTStudioCanvas *)superCanvas bizSession:(ZMMTStudioBizSession *)bizSession;

- (ZMMTStudioCanvas * _Nullable)createSubCanvasWithFrame:(NSRect)frame subCanvasClass:(Class)subCanvasClass;
- (ZMMTStudioCanvas * _Nullable)createShareSubCanvasWithFrame:(NSRect)frame subCanvasClass:(Class)subCanvasClass;

- (void)destorySubCanvas:(ZMMTStudioCanvas *)subCanvas;
- (void)removeSubCanvas:(ZMMTStudioCanvas *)subCanvas;
- (void)clearCanvas;
- (void)refreshCanvas;
- (void)updateWithCanvas:(ZMMTStudioCanvas *)canvas;

- (void)redraw;
- (void)moveUpper;
- (void)moveDown;
- (void)moveTop;
- (void)moveBottom;

- (ZMMTStudioCanvas * _Nullable)subCanvasWithTag:(NSInteger)tag;
- (NSUInteger)getBroadcastId;
- (void)addWallpaperWithPath:(NSString *)path;
- (CGRect)imageRectFromCanvasSize:(NSSize)canvasSize imageSize:(NSSize)imageSize;

- (void)bindVideoWithUserID:(ZMUserID)userId confInstId:(NSUInteger)confInstId videoSize:(NSUInteger)videoSize;
- (void)bindShareWithUserID:(ZMUserID)userId shareSourceID:(ZMShareSourceID)shareSourceID confInstId:(NSUInteger)confInstId videoSize:(NSUInteger)videoSize;
- (void)unbindStreamRes;
- (void)addPic:(NSBitmapImageRep *)bmpImageRep
          rect:(NSRect)rect
           tag:(ZMMTStudioResourceTag)tag
      position:(ZMMTStudioResourceRelativePosition)position;
- (void)removePicWithTag:(ZMMTStudioResourceTag)tag position:(ZMMTStudioResourceRelativePosition)position;

@end

@interface ZMMTStudioRootCanvas : ZMMTStudioCanvas

@property (nonatomic, weak) NSView *view;
@property (nonatomic, assign, readonly) BOOL isAttachedToRender;
@property (nonatomic, assign, readonly) BOOL isPublishing;
- (instancetype)initWithFrame:(NSRect)frame bizSession:(ZMMTStudioBizSession *)bizSession;
- (ZMMTStudioCanvas *)hitTest:(NSPoint)point;

- (void)publish;
- (void)stopPublish;
- (void)start;
- (void)stop;

@end


NS_ASSUME_NONNULL_END
