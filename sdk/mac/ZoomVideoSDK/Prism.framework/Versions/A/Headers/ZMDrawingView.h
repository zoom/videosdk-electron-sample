//
//  ZMDrawingView.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/12.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^ZMDrawingViewDrawingHandler)(NSRect bounds, NSRect dirtyRect);
typedef NS_OPTIONS(NSUInteger, ZMDrawingViewSuperDrawRectType) {
    ZMDrawingViewSuperDrawRectNone,//default
    ZMDrawingViewSuperDrawRectBegin,
    ZMDrawingViewSuperDrawRectEnd
};

@interface ZMDrawingView : NSView
{
    ZMDrawingViewDrawingHandler _drawingHandler;
    ZMDrawingViewSuperDrawRectType  _superDrawRectType;
}

+ (instancetype)drawingViewWithFrame:(NSRect)frameRect drawingHandler:(ZMDrawingViewDrawingHandler)handler;
- (void)cleanUp;

@property (nullable, copy) ZMDrawingViewDrawingHandler drawingHandler;
@property ZMDrawingViewSuperDrawRectType  superDrawRectType;

@end

NS_ASSUME_NONNULL_END
