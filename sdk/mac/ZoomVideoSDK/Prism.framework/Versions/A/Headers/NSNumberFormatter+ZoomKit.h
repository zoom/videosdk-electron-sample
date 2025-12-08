//
//  NSNumberFormatter+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/12.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@interface NSNumberFormatter (ZoomKit)

+ (NSString *)stringFromByteCount:(long long)byteCount;//NSByteCountFormatterCountStyleBinary
+ (NSString *)stringFromByteCount:(long long)byteCount countStyle:(NSByteCountFormatterCountStyle)countStyle;

@end
NS_ASSUME_NONNULL_END
