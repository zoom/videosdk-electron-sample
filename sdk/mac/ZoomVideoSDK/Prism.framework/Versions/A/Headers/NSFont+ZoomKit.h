//
//  NSFont+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/11.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Prism/NSApplication+ZoomKit.h>
#import <AppKit/AppKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

static CGFloat const ZMBaseReferenceFontSize = 14.0;

static inline CGFloat ZMDisplayFontSize(void) {
    return floor(ZMBaseReferenceFontSize * NSApp.fontSizeRate / 100);
}

/**
 Build-in font "SF Pro" with macOS 15 has layout issues when typing with marked-text.
 make it easy to rollback if any risk happens.
 */
static inline NSFont *_Nonnull ZMMessageFontWithSize(CGFloat fontSize) {
//    if (@available(macOS 15.0, *)) { // Helvetica Neue
//        NSFont *expFont = [NSFont fontWithName:@"Helvetica" size:fontSize];
//        if (!expFont) {
//            expFont = [NSFont systemFontOfSize:fontSize];
//        }
//        return expFont;
//    }
//    else {
        return [NSFont systemFontOfSize:fontSize weight:NSFontWeightRegular];
//    }
}

static inline NSFont *ZMMessageFontWithCurrentAppSize(void) {
    return ZMMessageFontWithSize(ZMDisplayFontSize());
}

static inline NSFont *_Nonnull ZMMessageFontWithScaledSize(CGFloat scaledSize) {
    CGFloat fontSize = floor(scaledSize * NSApp.fontSizeRate / 100);
    return ZMMessageFontWithSize(fontSize);
}

@interface NSFont (ZoomKit)

/**
 If can't create font by particularly name, will return system font by given size
 @return no null font
 */
+ (NSFont *)nonullFontWithName:(nullable NSString *)fontName size:(CGFloat)fontSize;


/**
  If can't create font by particularly bold name, will return system bold font by given size

 @return no null font
 */
+ (NSFont *)nonullBoldFontWithName:(nullable NSString *)fontName size:(CGFloat)fontSize;

+ (NSFont *)zmSystemFontOfSize:(CGFloat)fontSize;
+ (NSFont *)zmBoldSystemFontOfSize:(CGFloat)fontSize;

+ (NSFont *)zmMonospacedDigitFontOfSize:(CGFloat)fontSize;
+ (NSFont *)zmMediumMonospacedDigitFontOfSize:(CGFloat)fontSize;
+ (NSFont *)zmBoldMonospacedDigitFontOfSize:(CGFloat)fontSize;

+ (NSFont *)mediumSystemFontOfSize:(CGFloat)fontSize;
+ (NSFont *)lightSystemFontOfSize:(CGFloat)fontSize;
+ (NSFont *)ultralightSystemFontOfSize:(CGFloat)fontSize;

@end
NS_ASSUME_NONNULL_END
