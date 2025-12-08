//
//  ZMPopoverController.h
//  TestControl
//
//  Created by groot.ding on 2018/4/16.
//  Copyright © 2018 groot.ding. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN
typedef enum : NSUInteger {
    ZMPopoverAlignmentCenter,
    ZMPopoverAlignmentLeading,
    ZMPopoverAlignmentTrailing,
} ZMPopoverAlignment;


@class ZMPopoverController;
@protocol ZMPopoverControllerDelegate <NSObject>

@optional
- (void)popover:(ZMPopoverController *)popoverController mouseDownEvent:(NSEvent *)event;

- (void)popoverControllerDidClosed:(ZMPopoverController *)popoverController;

@end

@interface ZMPopoverController : NSObject

@property (weak) id <ZMPopoverControllerDelegate> delegate;

@property (nullable,retain) ZMBaseViewController *contentViewController;

@property (nullable,retain) IBOutlet NSView *contentView;

@property (nonatomic, assign) CGFloat cornerRadius;

@property (assign) BOOL needShowArrow;

@property (readonly) BOOL isVisible;

@property (readonly) NSWindow *window;

@property (assign, nonatomic) IBInspectable BOOL canBecomeKey;
/// If YES, the popover will become the key window when it pops up.
/// If NO, the popover won't change key status.
/// @discussion Defaults to YES
/// @note Has no effect if self.canBecomeKey is NO
@property (nonatomic, assign) BOOL becomeKeyOnAppearance;

@property (nullable,nonatomic,copy) NSString *theAccessibilityLabel;

@property (nonatomic,retain, nullable) NSColor *bgColor;
/// If YES, the popover will periodically check certain conditions (e.g. whether the mouse is outside the popover, whether the popover is visible)
/// and close itself once those conditions are false.
/// @note This can't be succinctly summarized, check the code to understand it.
@property (nonatomic,assign) BOOL autoClosePopover;

@property (nonatomic,assign) BOOL isAsChildWindow;

@property (nonatomic,assign) BOOL keepPopoverWhenPositionIsFirstResponder;
/// If YES, the popover will track certain events and use them for various behavior, such as closing the popover when clicking outside
/// or calling the popover delegate when clicking inside it.
/// @note This can't be summarized, check the code to understand it.
/// @note defaults to YES
@property (nonatomic,assign) BOOL needExclusiveEventClose;

@property (readonly) NSView *positioningView;
@property (nonatomic,assign) BOOL ignorePositioningView;

@property (readonly) NSRect positioningRect;

@property (nonatomic,assign) BOOL ignoreMouseDownEventMonitor;
@property (nonatomic,assign) BOOL ignoreResignKeyWindowMonitor;
@property (nonatomic,assign) BOOL temporarilyCancelAutoClosePopover;

- (void)showRelativeToRect:(NSRect)positioningRect ofView:(NSView *)positioningView preferredEdge:(NSRectEdge)preferredEdge alignment:(ZMPopoverAlignment)alignment;

- (void)updatePopoverToRect:(NSRect)positioningRect ofView:(NSView *)positioningView preferredEdge:(NSRectEdge)preferredEdge alignment:(ZMPopoverAlignment)alignment;

- (void)close;

- (void)schedule2ClosePopover;

- (void)relayout;
@end
NS_ASSUME_NONNULL_END
