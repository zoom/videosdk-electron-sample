//
//  ZMFloatingThumbnailHelper.h
//  zVideoUI
//
//  Created by francis zhuo on 2019/9/11.
//  Copyright © 2019 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>


NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSUInteger,ZMFloatingDockType){
    ZMFloatingWndDockNone = 0,
    ZMFloatingWndDockLeft,
    ZMFloatingWndDockRight,
    ZMFloatingWndDockTop,
    ZMFloatingWndDockBottom,
};

@protocol ZMFloatThumbnailHelperDelegate <NSObject>

- (NSRect)getCurrentWindowFrame;
- (NSRect)getCurrentWindowScreenFrame;
- (NSSize)getWindowSizeWithLayout:(BOOL)isVerticalLayout;

- (void)dockWindowWithFrame:(NSRect)frameRect layout:(BOOL)isVerticalLayout;
@end

@interface ZMFloatThumbnailHelper : NSObject
@property (weak) id<ZMFloatThumbnailHelperDelegate> delegate;

- (void)setNeedsDock:(BOOL)needDock;
- (NSRect)constrainFrameRect:(NSRect)frameRect screenFrame:(NSRect)screenFrame;
- (BOOL)needDockWithWindowFrame:(NSRect)frameRect
                    screenFrame:(NSRect)screenFrame;
- (BOOL)needDockWithWindowFrame:(NSRect)frameRect
                    screenFrame:(NSRect)screenFrame
                       outFrame:(NSRect*)outFrame
                         layout:(BOOL*)isVerticalLayout;
@end

NS_ASSUME_NONNULL_END
