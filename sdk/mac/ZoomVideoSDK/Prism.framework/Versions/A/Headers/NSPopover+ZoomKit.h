//
//  NSPopover+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/11.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#define kNSPopoverMaxTextWidthNotSpecified 1024.f

NS_ASSUME_NONNULL_BEGIN

@interface ZMWrapedIntrinsicContentSizeFixedTextField : NSTextField
{
    NSSize m_previousIntrinsicContentSize;
}

@end

@interface NSPopover (ZoomKit) //!< Use -> ZMPopoverManager

+ (instancetype)defaultContentPopover; //!< Use -> ZMPopoverManager
+ (instancetype)darkDefaultContentPopover; //!< Use -> ZMPopoverManager
+ (instancetype)lightDefaultContentPopover; //!< Use -> ZMPopoverManager

@property (copy, nonatomic) NSString *content; //!< Use -> ZMPopoverManager

- (instancetype)initWithContent:(NSString *)content; //!< Use -> ZMPopoverManager
- (instancetype)initWithContent:(NSString *)content alignment:(NSTextAlignment)alignment xMargin:(CGFloat)xMargin yMargin:(CGFloat)yMargin maxTextWidth:(CGFloat)maxTextWidth;//!< pass kNSPopoverMaxTextWidthNotSpecified to maxTextWidth if don't need to limit width.

@end

NS_ASSUME_NONNULL_END
