//
//  ZMProgressView.h
//  zChatUI
//
//  Created by javenlee on 2018/11/7.
//  Copyright © 2018 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <QuartzCore/QuartzCore.h>

@interface ZMProgressView : NSView

@property (nonatomic, assign) float progress;
@property (nonatomic, assign) double doubleValue;

- (void)setProgressLayerClass:(Class)layerClass;
- (void)setProgress:(float)progress animated:(BOOL)animated;
- (void)setTintColor:(NSColor *)tintColor;
- (void)setBackColor:(NSColor *)backColor;// default "whiteColor"
- (void)setLineWidth:(CGFloat)lineWidth;// default 2

@end
