//
//  NSTextField+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/12.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Prism/NSControl+ZoomKit.h>

NS_ASSUME_NONNULL_BEGIN
@interface NSTextField (ZoomKit)

+ (instancetype)labelWithString:(NSString *)stringValue frame:(NSRect)frame;
+ (instancetype)centerLabelWithString:(NSString *)stringValue frame:(NSRect)frame;

- (instancetype)appendingAttributedString:(NSAttributedString *)attributedString;
- (void)ensureCursorBlink;

- (void)disableAutomaticTextCompletion;

- (void)sizeToFitWithLimitedWidth:(CGFloat)limitedWidth;

@property (nullable, copy) NSString *zm_placeholderString;

- (void)visibilitySetStringValue:(nullable NSString *)stringValue;

- (void)setPlaceholderStringColor:(NSColor *)color;

@property (assign) IBInspectable BOOL focusable;

@property (readonly, copy) NSString *trimmedPlainString;//strim space and newline and replaced all newline in content

@end
NS_ASSUME_NONNULL_END
