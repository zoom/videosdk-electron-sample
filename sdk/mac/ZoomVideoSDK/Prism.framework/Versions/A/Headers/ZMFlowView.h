//
//  ZMFlowView.h
//  InterpretationDemo
//
//  Created by geno.chen on 2020/10/29.
//  Copyright © 2020 chenjiannan. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMFlowViewVerticalAlignment) {
    ZMFlowViewVerticalAlignmentTop,
    ZMFlowViewVerticalAlignmentCenter,
    ZMFlowViewVerticalAlignmentBottom,
};

typedef NS_ENUM(NSUInteger, ZMFlowViewHorizontalAlignment) {
    ZMFlowViewHorizontalAlignmentLeft,
    ZMFlowViewHorizontalAlignmentCenter,
    ZMFlowViewHorizontalAlignmentRight,
};

@interface ZMFlowView : NSView

@property IBInspectable NSEdgeInsets edgeInsets;
@property IBInspectable CGFloat marginX;
@property IBInspectable CGFloat marginY;

/** default is NO */
@property IBInspectable BOOL ignoreHiddenViews;

/** default is ZMFlowViewVerticalAlignmentTop */
@property IBInspectable ZMFlowViewHorizontalAlignment horizontalAlignment;
/** default is ZMFlowViewHorizontalAlignmentLeft */
@property IBInspectable ZMFlowViewVerticalAlignment verticalAlignment;


- (void)relayoutUsingFrameCalculation;
- (void)relayoutUsingConstrainst;
@end

NS_ASSUME_NONNULL_END
