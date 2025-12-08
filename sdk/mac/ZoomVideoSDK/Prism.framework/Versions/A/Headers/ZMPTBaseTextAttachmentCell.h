//
//  ZMPTBaseTextAttachmentCell.h
//  ZoomKit
//
//  Created by Francis Zhuo on 6/21/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMPTBaseTextAttachmentCell : NSTextAttachmentCell

@property (assign) BOOL shouldUpdateWhenExit;
@property (assign) BOOL isAnimating;
@property (assign) NSRect cellFrame;
@property (assign) BOOL isSelected;
@property (nonatomic,readonly) BOOL needFocusRing;

- (BOOL)shouldDoSomeAtPoint:(NSPoint)point hasUIChange:(BOOL*)hasChange;
- (void)mouseExisted;
- (void)onMouseClickOnPoint:(NSPoint)point andControlView:(NSTextView*)controlView;
@end


NS_ASSUME_NONNULL_END
