//
//  NSView+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/11.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Prism/ZMUIlocalizing.h>
#import <Prism/ZMNSRectCorner.h>
#import <Prism/ZMDistance.h>

@class ZMBaseMenuItem;

typedef NS_OPTIONS(NSUInteger, NSViewLayoutPolicy) {
    NSViewLayoutPolicyNone = 0,
    
    NSViewLayoutPolicyOriginPosition = 1 << 0,
    NSViewLayoutPolicyFullSize = 1 << 1,
    
    NSViewLayoutPolicyHorizontalCenter = 1 << 2,
    NSViewLayoutPolicyVerticalCenter = 1 << 3,
    
    NSViewLayoutPolicyLeading = 1 << 4,
    NSViewLayoutPolicyTrailing = 1 << 5,
    
    NSViewLayoutPolicyFloorFix = 1 << 6,
    NSViewLayoutPolicyCeilFix = 1 << 7
};


NS_ASSUME_NONNULL_BEGIN
@protocol ZMViewWidthAdjust <NSObject>

@required
@property (readonly) CGFloat perferredWidth;
- (void)widthToFit:(CGFloat)width;

@end

@protocol ZMkeyViewProtocal <NSObject>

@optional

- (BOOL)isKeyboardAccessGroup;

- (NSArray <NSView *> *)canBecomeKeySubViews;

- (void)willSelectNextBecomeFirstResponse;

- (void)willSelectPreviousBecomeFirstResponse;

- (void)didSelectNextBecomeFirstResponse;

- (void)didSelectPreviousBecomeFirstResponse;

- (nullable NSView *)fetchRealFirstResponder;

- (void)accessSubKeyViews;

@end

@interface ZMTagView : NSView
{
    NSInteger _tag;
}

@property IBInspectable NSInteger tag;

@end

@interface NSView (ZoomKit) <ZMUIlocalizing>

- (void)disableHierarchy;
- (void)enableHierarchy;

- (void)invalidateCursorRects;

@property (nonatomic) CGFloat x;
@property (nonatomic) CGFloat y;
@property (nonatomic) CGFloat maxX;
@property (nonatomic) CGFloat maxY;
@property (nonatomic) CGPoint origin;
//@property (nonatomic) CGSize  size NS_SWIFT_UNAVAILABLE("Use frame.size in Swift.");
@property (nonatomic) CGFloat tail;
@property (nonatomic) CGFloat bottom;
@property (nonatomic) NSPoint center;//by frame
//@property (nonatomic) CGFloat width;//by frame
//@property (nonatomic) CGFloat height;//by frame

/// When YES, this view (and all subviews) will ignore mouse/key events.
/// Used when presenting modal panels, see NSWindow+ZoomKit::setAlertWindow
@property (nonatomic,assign)   BOOL zmIgnoreEvent;
@property (nonatomic,assign)   BOOL zmCanBecomeKeyViewWhenHidden;
/// Sets zmIgnoreEvent = YES for self, but still allows events for the specified subviews.
/// @discussion The views in @c subviews do not need to be direct children of self. They can be any descendant.
- (void)setZmIgnoreEventButStillAllowingSubviews:(NSArray*)subviews;
@property (nonatomic,readonly) BOOL isAncestorIgnoreEvent;
@property (nonatomic,assign)   BOOL ignoreToolTipWhenHasShelter;
@property (nonatomic,readonly) BOOL isCanBeShelter;
@property (nonatomic,readonly) BOOL isAncestorIgnoreToolTipWhenHasShelter;
@property (nonatomic,readonly) BOOL isVisableInWindow;
@property (nonatomic,readonly) BOOL isMouseOnView;
@property (nonatomic, retain, nullable) NSView * preferPreviousKeyView;
@property (nonatomic, retain, nullable) NSView * preferNextKeyView;
- (void)removePreferKeyViews;

- (BOOL)zmSelectNextKeyView;//allowCycle = YES
- (BOOL)zmSelectPreviousKeyView;//allowCycle = YES

- (BOOL)zmSelectNextKeyView:(BOOL)allowCycle;
- (BOOL)zmSelectPreviousKeyView:(BOOL)allowCycle;

- (BOOL)zmSelectNextKeyView:(BOOL)allowCycle
               relativeView:(NSView* _Nullable)relativeView;
- (BOOL)zmSelectPreviousKeyView:(BOOL)allowCycle
                   relativeView:(NSView* _Nullable)relativeView;

- (void)moveByDistance:(ZMDistance)distance;

- (BOOL)convertPointToScreenIfAvailable:(NSPoint *)pPointInView;//return NO, if view is not install on a window
@property (nonatomic, readonly) NSPoint mouseLocationInView;//Mouse location in the coordinate system of the view

- (nullable __kindof NSView *)viewWithIdentifier:(NSString *)identifier;
@property (readonly) BOOL showing;

@property (assign, readonly) BOOL isFirstResponder;
@property (assign, readonly) BOOL isFirstResponderOrDescendant;//self or descendant is first responder
- (BOOL)makeFirstResponderIfPossible;
- (NSPoint)locationInView;//should named "currentMouseLocation"

- (NSPoint)boundsCorner:(NSRectCorner)corner;

+ (CGFloat)maxWidthOfViews:(NSArray<NSView *> *)views;
+ (CGFloat)maxHeightOfViews:(NSArray<NSView *> *)views;
+ (CGFloat)totalWidthOfViews:(NSArray<NSView *> *)views;
+ (CGFloat)totalHeightOfViews:(NSArray<NSView *> *)views;

//subviews
- (void)addSubviewSafely:(nullable NSView *)view;
- (void)addSubviews:(NSArray<NSView *> *)views;
- (void)removeSubviews:(NSArray<NSView *> *)views;
- (void)removeAllSubviews;

- (BOOL)containSubTreeView:(NSView *)view;
- (BOOL)checkPointHasShelter:(NSPoint)point;

@property(assign) NSInteger navagationPriority;
- (nullable NSArray <NSView *> *)getSubKeyViews;
- (nullable NSArray <NSView *> *)getSubTextView:(BOOL)selectable;

- (void)addFullSizeSubView:(NSView *)view animate:(BOOL)bAnimate;
- (void)addSubview:(NSView *)view layoutPolicies:(NSViewLayoutPolicy)policies;

+ (void)animateWithDuration:(NSTimeInterval)duration
                  animation:(nullable void (^)(void))animationBlock;
+ (void)animateWithDuration:(NSTimeInterval)duration
                  animation:(nullable void (^)(void))animationBlock
                 completion:(nullable void (^)(void))completionBlock;
+ (void)animateWithDuration:(NSTimeInterval)duration
         timingFunctionName:(NSString *)timingFunctionName
                  animation:(void (^)(void))animationBlock
                 completion:(void (^)(void))completionBlock;

- (void)removeAllConstraints;
- (void)removeAllConstraintsRelatedToSuperView;

- (nullable NSLayoutConstraint *)getConstraint:(NSView *)view1 attribute1:(NSLayoutAttribute)attribute1 view2:(nullable NSView *)view2 attribute2:(NSLayoutAttribute)attribute2 relation:(NSLayoutRelation)relation;
- (void)removeConstraint:(NSView *)view1 attribute1:(NSLayoutAttribute)attribute1 view2:(nullable NSView *)view2 attribute2:(NSLayoutAttribute)attribute2 relation:(NSLayoutRelation)relation;

- (NSLayoutConstraint *)addConstraint:(NSView *)view1 attribute1:(NSLayoutAttribute)attribute1 view2:(nullable NSView *)view2 attribute2:(NSLayoutAttribute)attribute2 relation:(NSLayoutRelation)relation constant:(CGFloat)constant;

- (NSLayoutConstraint *)addHeightConstraint:(CGFloat)height;
- (NSLayoutConstraint *)addWidthConstraint:(CGFloat)height;
- (void)addFixedConstraintWithSize:(NSSize)size;

- (BOOL)checkSubviewIsFirstResponseWithPoint:(NSPoint)point;

@property (readonly) BOOL firstResponderOnMeOrMyDescendant;

@property (nonatomic, assign, nullable) ZMBaseMenuItem *enclosingHMenuItem;

- (NSImage *)imageRepresentation;

- (NSRect)rectInWindow;
- (NSRect)rectInScreen;
- (CGRect)cgRectInScreen;
- (NSString *)getSubViewsInfo;
- (nullable NSView *)firstSuperViewWithClass:(Class)aClass;

- (void)scrollToVisableIfNeed;

/**
 A change in the frame of the superview may cause the rectInWindow of the current view to change, but not absolutely
 */
- (void)zm_rectInWindowDidChanged:(BOOL)changed NS_REQUIRES_SUPER;

@property (nonatomic, copy, nullable) void (^viewWillStartLiveResizeBlock)(NSView *view);
@property (nonatomic, copy, nullable) void (^viewDidEndLiveResizeBlock)(NSView *view);
@property (nonatomic, copy, nullable) void (^viewFrameSizeDidChanged)(void);
@property (nonatomic, copy, nullable) void (^viewHiddenDidChanged)(NSView *view);
@property (nonatomic, copy, nullable) void (^rectInWindowDidChanged)(NSView *view);
@property (nonatomic, copy, nullable) void (^viewDidMoveToWindowBlock)(NSWindow *_Nullable window);
#pragma mark - Appearance
@property (nonatomic, copy, nullable) void (^viewEffectiveAppearanceDidChanged)(NSView* view);

#pragma mark - resize
@property(assign) BOOL zm_inLiveResize;
- (void)zm_viewWillStartLiveResize;
- (void)zm_viewDidEndLiveResize;
@end

//ZOOM-71195
@interface NSView (ZoomKit_ForceUIUpdateImage)
- (void)forceUpdateUIImageRecursively;
@end

@interface NSView (ZMPrivate)

- (void)_windowWillOrderOffScreen;

#ifndef MAC_OS_VERSION_14_0
@property BOOL clipsToBounds API_AVAILABLE(macos(10.9));
#endif
@end

//auto means auto convert frame to RTL Layout
@interface NSView (ZoomKit_RTL)

@property (nonatomic, readonly) BOOL isLayoutRTL;
@property (nonatomic, readonly) NSPoint autoOriginInScreen;

@property (nonatomic, readonly) NSAutoresizingMaskOptions leadingMask;
@property (nonatomic, readonly) NSAutoresizingMaskOptions trailingMask;

@property (nonatomic, assign) NSRect autoFrame; //only valid when have superview with correct frame
@property (nonatomic, assign) NSPoint autoFrameOrigin;

- (NSRect)autoRect:(NSRect)rect;

@end

NS_ASSUME_NONNULL_END

