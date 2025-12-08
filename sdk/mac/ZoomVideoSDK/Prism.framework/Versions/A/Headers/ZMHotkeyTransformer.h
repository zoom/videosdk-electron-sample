//
//  ZMSCModifyFlagsTransformer.h
//  ZMHotkeyTest
//
//  Created by francis zhuo on 2017/9/13.
//  Copyright © 2017 fenfei. All rights reserved.
//

#import <Cocoa/Cocoa.h>
typedef NS_ENUM(unichar, ZMKeyCodeGlyph)
{
    ZMKeyCodeGlyphTabRight = 0x21E5, // ⇥
    ZMKeyCodeGlyphTabLeft = 0x21E4, // ⇤
    ZMKeyCodeGlyphReturn = 0x2305, // ⌅
    ZMKeyCodeGlyphReturnR2L = 0x21A9, // ↩
    ZMKeyCodeGlyphDeleteLeft = 0x232B, // ⌫
    ZMKeyCodeGlyphDeleteRight = 0x2326, // ⌦
    ZMKeyCodeGlyphPadClear = 0x2327, // ⌧
    ZMKeyCodeGlyphClear = 0x2715, // x
    ZMKeyCodeGlyphLeftArrow = 0x2190, // ←
    ZMKeyCodeGlyphRightArrow = 0x2192, // →
    ZMKeyCodeGlyphUpArrow = 0x2191, // ↑
    ZMKeyCodeGlyphDownArrow = 0x2193, // ↓
    ZMKeyCodeGlyphPageDown = 0x21DF, // ⇟
    ZMKeyCodeGlyphPageUp = 0x21DE, // ⇞
    ZMKeyCodeGlyphNorthwestArrow = 0x2196, // ↖
    ZMKeyCodeGlyphSoutheastArrow = 0x2198, // ↘
    ZMKeyCodeGlyphEscape = 0x238B, // ⎋
    ZMKeyCodeGlyphSpace = 0x0020, // ' '
};

APPKIT_EXTERN NSString* ZMUnicharToString(unichar aChar);

@interface ZMBaseKeyCodeTransformer : NSValueTransformer
+ (NSString*)transformedValue:(NSNumber*)value;
@end

@interface ZMASCIIKeyCodeTransformer : ZMBaseKeyCodeTransformer
@end

@interface ZMUSKeyCodeTransformer : ZMBaseKeyCodeTransformer
@end

@interface ZMHotkeyModifyFlagsTransformer : NSValueTransformer
+ (NSString*)transformedValue:(NSNumber*)value;
+ (NSString*)characterSymbol:(NSNumber*)value;
+ (NSString*)emojiSymbol:(NSNumber*)value;
@end

@interface ZMKeyEquivalentTransformer : ZMUSKeyCodeTransformer
@end

@interface ZMKeyEquivalentModifierMaskTransformer : NSValueTransformer
+ (NSNumber*)transformedValue:(NSNumber*)value;
@end

