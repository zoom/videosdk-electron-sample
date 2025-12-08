//
//  NSColor+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/11.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

APPKIT_EXTERN CGColorRef ZMCGColorCreateSRGB(CGFloat red, CGFloat green, CGFloat blue, CGFloat alpha);

// Optimized: Use macros instead of functions for simple color creation (package size optimization)
#define NSColorFRGB(r,g,b) [NSColor colorWithSRGBRed:(r) green:(g) blue:(b) alpha:1.0f]
#define NSColorFRGBA(r,g,b,a) [NSColor colorWithSRGBRed:(r) green:(g) blue:(b) alpha:(a)]
#define CGColorFRGB(r,g,b) CGColorFRGBA(r,g,b,1.0f)
#define CGColorFRGBA(r,g,b,a) ((CGColorRef)ZMAutorelease(ZMCGColorCreateSRGB((r),(g),(b),(a))))

/**
 Convenience Color method.
 @param r 0 ~ 255
 @param g 0 ~ 255
 @param b 0 ~ 255
 @return Calibrated RGB color, alpha is 1
 */
#define NSColorRGB(r,g,b) NSColorRGBA(r,g,b,1.0f)
#define CGColorRGB(r,g,b) CGColorRGBA(r,g,b,1.0f)

/**
 Convenience Color method.
 @param r 0 ~ 255
 @param g 0 ~ 255
 @param b 0 ~ 255
 @param a 0 ~ 1.0
 @return Calibrated RGB color
 */
APPKIT_EXTERN NSColor * NSColorRGBA(NSInteger r, NSInteger g, NSInteger b, CGFloat a);
APPKIT_EXTERN CGColorRef CGColorRGBA(NSInteger r, NSInteger g, NSInteger b, CGFloat a);


/**
  Convenience Color method.

 @param rgbValue hex value like 0xffffff
 @return Calibrated RGB color
 */
APPKIT_EXTERN NSColor * NSColorFromHex(NSInteger rgbValue);
APPKIT_EXTERN NSColor * NSColorFromRGBAHex(NSUInteger rgbaValue);
APPKIT_EXTERN CGColorRef CGColorFromHex(NSInteger rgbValue);

APPKIT_EXTERN NSColor * NSColorFromHexString(NSString *hexValue);

/**
 Convenience Color method.
 
 @param light and dark color hex value like 0xffffff
 @return Calibrated ZMAppearanceColor
 */
APPKIT_EXTERN NSColor * ZMHexColor(NSUInteger light, NSUInteger dark);

/**
 Convenience Color method.
 @param light hex value like 0xffffff
 @param lightAlpha 0 ~ 1
 @param dark hex value like 0xffffff
 @param darkAlpha 0 ~ 1
 @return Calibrated ZMAppearanceColor base on RGB color
 */
APPKIT_EXTERN NSColor * ZMHexColorWithAlpha(NSUInteger light, CGFloat lightAlpha,  NSUInteger dark, CGFloat darkAlpha);

/**
 Convenience Color method.
 
 @param rgbValue  hex value like 0xffffff
 @param alpha 0 ~ 1
 @return Calibrated RGB color
 */
APPKIT_EXTERN NSColor * NSColorFromHexWithAlpha(NSInteger rgbValue,float alpha);

@interface NSColor (ZoomKit)

@property (readonly) CGColorRef zm_CGColor NS_RETURNS_INNER_POINTER;
+ (nullable NSColor *)zm_colorWithCGColor:(nullable CGColorRef)cgColor;

/**
 * Pri == primary
 * Sec == Secondary
 * Tri == Tertiary
 * Des == Destructive
*/
#pragma mark - ZMButton Background Color
@property (class, readonly) NSColor *zmBtnPriNormalBgColor;
@property (class, readonly) NSColor *zmBtnSecNormalBgColor;
//@property (class, readonly) NSColor *zmBtnTriNormalBgColor;
//@property (class, readonly) NSColor *zmBtnDesNormalBgColor;
//@property (class, readonly) NSColor *zmBtnTxtNormalBgColor;

#pragma mark - ZMButton Title Color
@property (class, readonly) NSColor *zmBtnTxtNormalTitleColor;

#pragma mark - ZMButton Border Color
@property (class, readonly) NSColor *zmBtnNormalBorderColor;
//@property (class, readonly) NSColor *zmBtnSecNormalBorderColor;
//@property (class, readonly) NSColor *zmBtnSecHoverBorderColor;
//@property (class, readonly) NSColor *zmBtnSecPressBorderColor;

#pragma mark - Single color
@property (class, readonly) NSColor *zmBlue;
@property (class, readonly) NSColor *zmClearColor;
@property (class, readonly) NSColor *zmWhiteColor;

#pragma mark - Background Color

@property (class, readonly) NSColor *zmBackgroundColor;/* #FFFFFF, #0x1A1A1A */
@property (class, readonly) NSColor *zmSidebarBackgroundColor;

#pragma mark - Text color
@property (class, readonly) NSColor *zmPriTextColor;

//@property (class, readonly) NSColor *zmFocusBlueColor;

@property (class, readonly) NSColor *zmLineColor;

- (nullable NSString *)hexString;
//- (NSInteger)hexRGB;

@end

NS_ASSUME_NONNULL_END


