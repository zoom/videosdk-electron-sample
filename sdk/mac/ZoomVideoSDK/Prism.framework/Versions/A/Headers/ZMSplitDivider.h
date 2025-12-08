//
//  ZMSplitDivider.h
//  SaasBeeConfUIModule
//
//  Created by Francis Zhuo on 8/15/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMSplitView;
@interface ZMSplitDivider : NSView
@property (readonly, assign) NSEdgeInsets dragPadding;
@property (weak) ZMSplitView* splitView;

@property (readonly) NSColor* normalBgColor;
@property (readonly) NSColor* hoverBgColor;
@property (readonly) NSColor* pressBgColor;
@property (readonly) NSColor* dividerPointColor;
@property (readonly, getter=isHover) BOOL hover;
@property (readonly) BOOL isHighlight;

@property (assign) BOOL isVertical;
@property (assign) BOOL useAutoLayout;
@property (assign) BOOL enableDrag;
+ (CGFloat)dividerWidth;

- (void)suspendDragIfNeed;
@end
@compatibility_alias ZMMTSplitDivider ZMSplitDivider;
NS_ASSUME_NONNULL_END
