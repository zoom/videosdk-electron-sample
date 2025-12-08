//
//  ZMColor.h
//  ZCommonUI
//
//  Created by javenlee on 2019/4/22.
//  Copyright © 2019 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

/*
    ColorSpace must be equal
 */

NS_ASSUME_NONNULL_BEGIN

@interface ZMAppearanceColor : NSColor

+ (nullable NSColor *)colorWithLight:(NSUInteger)lightHex lightAlpha:(CGFloat)lightAlpha dark:(NSUInteger)darkHex darkAlpha:(CGFloat)darkAlpha;
@property (nonatomic, strong, readonly) NSColor *lightColor;
@property (nonatomic, strong, readonly) NSColor *darkColor;

@end

NS_ASSUME_NONNULL_END
