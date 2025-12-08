//
//  ZMLable.h
//  ZCommonUI
//
//  Created by francis zhuo on 2019/6/4.
//  Copyright © 2019 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Prism/ZMBaseTextAttachmentCell.h>
#import <Prism/ZMTextView.h>

/**
 * support autolayout in 10.9 and 10.10
 */
NS_ASSUME_NONNULL_BEGIN
@interface ZMLabel : NSTextField

@property (nonatomic, assign) BOOL disableUserInteraction;
@property IBInspectable BOOL usesSingleLineMode NS_AVAILABLE_MAC(10_6);
- (CGFloat)getHeightToFitByWidth:(CGFloat)width;
- (NSSize)sizeToFitByWidth:(CGFloat)width;
+ (instancetype)labelWithString:(nullable NSString*)string;

@end

@interface ZMLabel(NSMenuItem)
+ (ZMLabel*)labelMenuItemWithString:(NSString*)string;
@end;


@interface ZMTextLabel : ZMTextView
+ (nonnull instancetype)labelWithString:(NSString *)string;

- (void)setString:(NSString *)string;
- (void)setAttributedString:(NSAttributedString*)attributedString;

- (CGFloat)getHeightToFitByWidth:(CGFloat)width;
@end

NS_ASSUME_NONNULL_END
