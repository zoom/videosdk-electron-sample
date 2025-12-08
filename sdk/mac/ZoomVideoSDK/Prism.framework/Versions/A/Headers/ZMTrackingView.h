//
//  ZMTrackingView.h
//  ZCommonUI
//
//  Created by John Zhang on 13-4-2.
//  Copyright (c) 2013 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Prism/NSView+ZoomKit.h>

@protocol ZMTrackingViewDelegate <NSObject>

@optional
- (void)mouseEnteredView:(nullable NSView *)view;
- (void)mouseExitedView:(nullable NSView *)view;

@end

@interface ZMTrackingView : ZMTagView
{
    BOOL    _hovered;
    NSTrackingArea* _trackingArea;
}

@property(nonatomic, assign) BOOL hovered;
@property(nullable, nonatomic, retain) NSTrackingArea* trackingArea;
@property(nullable, nonatomic, weak) id<ZMTrackingViewDelegate> delegate;

- (void)viewWillMoveToWindow:(nullable NSWindow *)newWindow NS_REQUIRES_SUPER;
- (void)viewDidMoveToWindow NS_REQUIRES_SUPER;

- (void)cleanUp;
@end

@interface ZMTrackingViewOutSide : NSView
{
    BOOL    _hovered;
    NSTrackingArea* _trackingArea;
}

@property(nonatomic, assign) BOOL hovered;
@property(nullable, nonatomic, retain) NSTrackingArea* trackingArea;

- (void)cleanUp;
@end
