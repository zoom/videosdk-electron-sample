//
//  NSAttributedString+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/11.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString* const kPhoneNumber;
extern NSString* const kMeetingNumber;
extern NSString* const kHostJoinZak;
extern NSString* const ZMLinkAttributeName;
extern NSString* const ZMAXRoleAttributeName;
extern NSString* const ZMTargetAttributeName;
extern NSString* const ZMActionAttributeName;

@interface NSAttributedString (ZoomKit)

+ (instancetype)attributedStringWithString:(NSString *)str attributes:(nullable NSDictionary *)attrs;

+ (instancetype)hyperlinkWithString:(NSString *)string link:(id)link;

- (nullable NSArray *)getRectsByGlyphRange:(NSRange)glyphRange textContainer:(NSTextContainer *)textContainer;

- (NSRect)getRectByGlyphIndex:(NSInteger)index textContainer:(NSTextContainer *)textContainer;

- (NSRange)getSameAttributeRangeWithIndex:(NSUInteger)index attributeKey:(NSString *)attributeKey value:(id)value;

- (NSUInteger)charIndexWithPoint:(NSPoint)point textContainer:(NSTextContainer *)textContainer;

- (nullable NSImage *)asImage;

/// Returns new string where all new-line style characters (e.g., CRLF, paragraph separator, etc.) are replaced
/// with the given character replacement.
///
/// - Parameter replacement: The character to replace the newline-style characters with.
///
/// - Returns: A new attributed string with the newline characters replaced.
- (NSAttributedString *)stringByReplacingNewlinesWithCharacter:(unichar)replacement;
- (NSAttributedString *)stringByReplacingNewlinesWithString:(NSString *)replacement;

/**
 Returns a new string where all new-line style characters (e.g. CRLF, paragraph separator, etc.) are replaced with the new line character
 */
- (NSAttributedString*)stringBySimplifyingNewlines;

/**
 Writes this string to the given pasteboard item for all the specified types.
 @return True if writing succeeded for all types, false if writing for any type failed
 */
- (BOOL)writeToPasteboardItem:(NSPasteboardItem*)item forTypes:(NSArray<NSPasteboardType>*)types;

- (CGFloat)getParagraphTailIndentInLocatioin:(NSInteger)location;

/// Returns an attributed substring of the receiver that is truncated to contain
/// at most the specified lines.
///
/// - Parameters:
///   - lines: Number of maximum lines the substring can contain.
///   - maxWidth: The maximum width used to constrain the text layout.
///   - textContainer: A reference text container for layout.
- (NSAttributedString *)zm_attributedSubstringTruncatedToLines:(NSUInteger)lines
                                                maxLayoutWidth:(CGFloat)maxWidth
                                                 textContainer:(NSTextContainer *)textContainer API_AVAILABLE(macos(10.11));

- (NSRect)zm_boundingRectWithMaxLayoutWidth:(CGFloat)maxWidth
                      numberOfLineFragments:(NSUInteger * _Nullable)outNumberOfLineFragments
                              textContainer:(NSTextContainer *)textContainer API_AVAILABLE(macos(10.11));

- (NSAttributedString *)zm_attributedStringByAppendingString:(NSString *)string;

- (BOOL)isEmptyOrSpacesOnly;

//support link
@property(readonly, assign) BOOL containHyperlinks;
@end
NS_ASSUME_NONNULL_END
