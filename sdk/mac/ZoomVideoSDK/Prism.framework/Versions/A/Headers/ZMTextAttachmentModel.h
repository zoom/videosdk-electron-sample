//
//  ZMTextAttachmentModel.h
//  ZoomKit
//
//  Created by Mario Rao on 2023/8/17.
//

#import <Prism/ZMBaseTextAttachmentCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMTextAttachmentModel : NSObject

@property (nonatomic, strong) ZMBaseTextAttachmentCell *attachmentCell;
@property (nonatomic, strong) NSView<ZMTextAttachmentContentViewProtocol> *contentView;
@property (nonatomic, assign) BOOL isRefreshed;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithAttachmentCell:(ZMBaseTextAttachmentCell *)cell;

@end

NS_ASSUME_NONNULL_END
