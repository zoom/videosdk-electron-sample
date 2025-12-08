//
//  ZMTextBubbleObject.h
//  ZCommonUI
//
//  Created by Francis Zhuo on 2/25/21.
//  Copyright © 2021 zoom. All rights reserved.
//

#import <Prism/ZMBubbleObject.h>

NS_ASSUME_NONNULL_BEGIN
@interface ZMTextBubbleConfig : ZMBubbleConfig
@property(strong, nullable) NSColor* textColor;
@property(strong, nullable) NSFont* textFont;//defalut systemFontOfSize:12
@property(assign) NSTextAlignment textAlignment;//default NSTextAlignmentCenter
@end

@interface ZMTextBubbleObject : ZMBubbleObject
@property(nonatomic, strong) ZMTextBubbleConfig *config;
@property(nullable, nonatomic, copy) NSString* bubbleText;
@property(nullable, nonatomic, strong) NSAttributedString* attributedBubbleText;
@property(nonatomic, assign) BOOL supportHyperlinks;
@end

NS_ASSUME_NONNULL_END
