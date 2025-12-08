//
//  ZMBaseTextAttachmentCell.h
//  ZoomKit
//
//  Created by Mario Rao on 2023/8/17.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMBaseTextAttachmentCell;


@protocol ZMTextAttachmentContentViewProtocol <NSObject>

@optional
- (void)updateUIWithAttachmentCell:(ZMBaseTextAttachmentCell *)attchmentCell;

@end


@protocol ZMBaseTextProtocol <NSObject>

@required
- (void)addAttachmentCell:(ZMBaseTextAttachmentCell *)attachmentCell withFrame:(CGRect)frame;

- (nullable NSView <ZMTextAttachmentContentViewProtocol> *)findContentViewWithCell:(nonnull ZMBaseTextAttachmentCell *)cell;

@end


@interface ZMBaseTextAttachmentCell : NSTextAttachmentCell

@property (nonatomic, readonly, strong) NSUUID *uniqueID;

- (nullable NSView<ZMTextAttachmentContentViewProtocol> *)makeContentView;

@end

NS_ASSUME_NONNULL_END
