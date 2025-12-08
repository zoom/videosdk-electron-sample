//
//  ZMViewAttachmentCell.h
//  ParseHTML
//
//  Created by groot.ding on 22/6/21.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMViewAttachmentCell : NSTextAttachmentCell

@property (nonatomic,readonly) NSView *view;

@property (nonatomic,assign) NSPoint baselineOffset;

@property (nonatomic,copy) NSString *zmAccessibilityTitle;

+ (instancetype)attachmentCellWithView:(NSView *)view;

+ (NSAttributedString *)attributedStringWithView:(NSView *)view;

- (NSAttributedString *)attributedString;

- (void)sizeToFit;

@end

@interface ZMImageAttachmentCell : ZMViewAttachmentCell



+ (nullable instancetype)attachmentCellWithImageName:(NSString *)imgName;

+ (nullable instancetype)attachmentCellWithImage:(nullable NSImage *)image;

@end

NS_ASSUME_NONNULL_END
