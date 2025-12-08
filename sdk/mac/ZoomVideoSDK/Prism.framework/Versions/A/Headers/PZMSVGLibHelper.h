//
//  ZMSVGLibHelper.h
//  SVGTools
//
//  Created by Jed Zheng on 12/12/2019.
//  Copyright © 2019 jed. All rights reserved.
//

#import <AppKit/AppKit.h>
@class PZMSvgElement;

NS_ASSUME_NONNULL_BEGIN

@interface PZMSVGLibHelper : NSObject
+ (NSImage* _Nullable)exportImageWithPath:(NSString *)path;
+ (NSImage* _Nullable)exportImageWithElement:(PZMSvgElement *)element;
+ (NSImage* _Nullable)exportImageWithElement:(PZMSvgElement *)element scale:(CGFloat)scale;
+ (NSBezierPath * _Nullable)exportFirstPathWithElement:(PZMSvgElement *)element scale:(CGFloat)scale;
+ (NSImage *)exportImageWithSvgContent:(NSString *)svgStr;
@end
@compatibility_alias ZMSVGLibHelper PZMSVGLibHelper;

@interface NSColor (Utilities)

+ (NSColor *)hexColorWithString:(NSString *)hex;

@end

NS_ASSUME_NONNULL_END
