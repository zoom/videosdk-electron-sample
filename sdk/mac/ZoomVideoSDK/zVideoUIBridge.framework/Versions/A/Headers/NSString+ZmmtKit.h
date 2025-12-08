//
//  NSString+ZmmtKit.h
//  zVideoUI
//
//  Created by Jeffery Lin on 2022/02/21.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (ZmmtKit)

- (NSString *)changeTWFlagEmojiIfNeed;
- (NSImage *)zmmt_avatarImageBySize:(NSSize)size;

@end

NS_ASSUME_NONNULL_END
