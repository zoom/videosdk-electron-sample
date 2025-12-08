//
//  ZMAnimationAndErrorView.h
//  ZCommonUI
//
//  Created by groot.ding on 27/07/2020.
//  Copyright © 2020 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMAnimationAndErrorView : NSView

@property(nonatomic, strong, nullable) NSImage *errImage;

@property (nonatomic, assign, getter=isShowErrImage)  BOOL showErrImage;
@property (nonatomic, assign, getter=isShowAnimation) BOOL showAnimation;
@property (nonatomic, assign, getter=isShowCornerRadius) BOOL showCornerRadius;
@property (nonatomic, strong, nullable) NSColor *backgroundColor;

- (void)setContentWidth:(CGFloat)width;

@end

NS_ASSUME_NONNULL_END
