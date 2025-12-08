//
//  ZMALButton.h
//  ZCommonUI
//
//  Created by francis zhuo on 2019/8/8.
//  Copyright © 2019 zoom. All rights reserved.
//
//  ZMAotoLayoutButton, support autolayout, and support autoresize layout

#import <Prism/ZPTrackingButton.h>

extern const CGFloat kZMALBtnCellMargin;

NS_ASSUME_NONNULL_BEGIN
@interface ZMALButtonCell : NSButtonCell
@property(assign)IBInspectable NSSize checkImageSize;
@property(assign)IBInspectable CGFloat leftPadding;
@property(assign)IBInspectable CGFloat centerPadding;
@property(assign)IBInspectable CGFloat rightPadding;
@property(assign)IBInspectable CGFloat topPadding;
@property(assign)IBInspectable CGFloat bottomPadding;

@property(nullable,retain)IBInspectable NSColor* normalTitleColor;
@property(nullable,retain)IBInspectable NSColor* disableTitleColor;

- (NSSize)titleSizeWithWidth:(CGFloat)width;

@property IBInspectable BOOL legacyDrawing;

@end

@interface ZMALButton : ZPTrackingButton
/**
 *usesSingleLineMode default value is no.
 */
@property IBInspectable BOOL usesSingleLineMode NS_AVAILABLE_MAC(10_6);
- (__kindof ZMALButton* (^)(NSSize))checkImageSize;///< default value is {16,16}
- (__kindof ZMALButton* (^)(CGFloat))checkImageRadius;///< need overwrite
- (__kindof ZMALButton* (^)(CGFloat))leftPadding;///< default value is 0
- (__kindof ZMALButton* (^)(CGFloat))centerPadding;///< default value is 8.f
- (__kindof ZMALButton* (^)(CGFloat))rightPadding;///< default value is 0
- (__kindof ZMALButton* (^)(CGFloat))topPadding;///< default value is 2
- (__kindof ZMALButton* (^)(CGFloat))bottomPadding;///< default value is 2

- (__kindof ZMALButton* (^)(NSColor*))normalTitleColor;///< default value is 2
- (__kindof ZMALButton* (^)(NSColor*))disableTitleColor;///< default value is 2

- (void)heightToFit;
- (CGFloat)getHeightToFitByWidth:(CGFloat)width;

@property (nonatomic) IBInspectable BOOL legacyDrawing;

@end

NS_ASSUME_NONNULL_END
