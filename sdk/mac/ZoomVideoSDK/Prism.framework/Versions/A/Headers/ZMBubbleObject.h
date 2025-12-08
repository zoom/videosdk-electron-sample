//
//  ZMBubbleObject.h
//  ZMTipWindowDemo
//
//  Created by Francis Zhuo on 2/9/21.
//  Copyright © 2021 Francis Zhuo. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Prism/ZMNSRectCorner.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, ZMArrowAlignment){
    ZMArrowAlignmentCenter,
    ZMArrowAlignmentLeft,
    ZMArrowAlignmentRight,
    
    ZMArrowAlignmentTop = ZMArrowAlignmentLeft,
    ZMArrowAlignmentBottom = ZMArrowAlignmentRight,
};

typedef NS_ENUM(NSInteger, ZMBubbleAppearance){
    ZMBubbleAppearanceSystem,
    ZMBubbleAppearanceLight,
    ZMBubbleAppearanceDark,
};

typedef NS_ENUM(NSInteger, ZMBubbleConstrainFrameMode){
    ZMBubbleConstrainFrameModeScreen,
    ZMBubbleConstrainFrameModeWindow,
    ZMBubbleConstrainFrameModeScreenAndWindow,
    ZMBubbleConstrainFrameModeBlock,
    ZMBubbleConstrainFrameModeCustom,//if ConstrainFrame equal to NSZeroRect will not constain
};

typedef NS_ENUM(NSUInteger, ZMBubbleArrowSizeMode) {
    ZMBubbleArrowSizeModeDefault,
    ZMBubbleArrowSizeModeRegular,
    ZMBubbleArrowSizeModeSmall,
    ZMBubbleArrowSizeModeNone,
    ZMBubbleArrowSizeModeCustom,
};

@interface ZMBubbleConfig : NSObject
@property(nonatomic, assign) ZMBubbleArrowSizeMode arrowSizeMode;
@property(assign) NSSize arrowSize;
@property(assign) CGFloat arrowRadius;//suggest arrowSize.height/2
@property(assign) ZMArrowAlignment alignment;//default ZMArrowAlignmentCenter

@property(assign) CGFloat minWidth;
@property(assign) CGFloat maxWidth;
@property(assign) CGFloat minHeight;
@property(assign) CGFloat maxHeight;

@property(assign) NSEdgeInsets margin;

@property(nonatomic, assign) ZMBubbleAppearance appearance;//default ZMBubbleAppearanceSystem
@property(nonatomic, strong) NSAppearance* windowAppearance;//default is nil option<nil, zm_dark, zm_light>
@property(nullable, copy) NSColor* backgroundColor;
@property(nullable, copy) NSColor* borderColor;
@property(assign) CGFloat borderWidth;
@property(assign) CGFloat cornerRadius;

@property(assign) BOOL canBecomeKey;
@property(assign) BOOL makeKeyWhenOrderFront;
@property(assign) BOOL makeKeyOnlyFromKeyWindow; //default YES

@property(assign) BOOL careMouseMoveEvent;
@property(assign) BOOL relayoutWhenPositionViewRectChanged;
@property(assign) BOOL preferUseCacheArrowEdge;//default YES

@property(assign) BOOL displayWhenActiveSpace;
@property(assign) NSRectCorner pinRectCorner;

/// Controls whether the bubble window adjusts its position to stay fully within the visible screen area.
/// When set to YES, the window will be repositioned if it would otherwise overflow the screen.
@property(assign) BOOL constrainToScreen;
@property(assign) ZMBubbleConstrainFrameMode constrainFrameMode;//default ZMBubbleConstrainFrameModeScreen
@property(assign) NSEdgeInsets constrainFrameMargin;//default NSEdgeInsetsZero
@property(copy) NSRect (^constrainFrameBlock)(NSView* positioningView);

@property (assign) BOOL disableAnimation;

/**
 return  rectangle in positioningView coordinates.
 */
@property(copy) NSRect (^positioningRectBlock)(NSView* positioningView);

@property(nullable, readonly, weak) NSView* positioningView;

@property(nullable, copy) BOOL (^forwardFirstResponder)(void);

@property(assign) NSInteger relativeWindowLevel;

// kept for backwards compatibility. NOT animated.
+ (instancetype)defautConfig API_DEPRECATED_WITH_REPLACEMENT("defaultConfig", macos(10.10, 13.0));
// new default config - animated, but otherwise the same as the legacy defaults.
+ (instancetype)defaultConfig;
+ (instancetype)smallConfig;
@end

@interface ZMBubbleObject : NSObject
@property(nullable, retain) NSViewController* contentViewController;
@property(nullable, nonatomic, retain) NSView* contentView;
@property(nullable, nonatomic, retain) ZMBubbleConfig* config;
@property(readonly) BOOL isShowing;
@property(readonly) NSWindow* bubbleWindow;
@property(nullable, nonatomic, retain) id representedValue;

@property(copy) void (^escAction)(ZMBubbleObject* bubbleObj);
@property(copy) void (^mouseEventAction)(ZMBubbleObject* bubbleObj,NSEvent* event);

@property(copy) NSString* (^accessibilityBlock)(void);

- (void)cleanUp;
- (void)showRelativeToRect:(NSRect)positioningRect ofView:(NSView *)positioningView preferredEdge:(NSRectEdge)preferredEdge;
- (void)showRelativeToRect:(NSRect)positioningRect ofView:(NSView *)positioningView preferredEdge:(NSRectEdge)preferredEdge constrainFrame:(NSRect)constrainFrame;
- (void)relayout;
- (void)close;
- (void)closeWithAnimation:(void (^ _Nullable)(void))completionHandler;

- (BOOL)isMouseActionOnContentView:(NSEvent*)event;
- (BOOL)isMouseActionOnPositionView:(NSEvent*)event;
@end

NS_ASSUME_NONNULL_END
