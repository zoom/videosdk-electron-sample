//
//  NSDictionary+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/12.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <AppKit/AppKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@interface NSDictionary (ZoomKit)

+ (instancetype)stringAttributesWithColor:(nullable NSColor *)color font:(nullable NSFont *)font alignment:(NSTextAlignment)alignment;

- (nullable NSString *)toJsonString;

- (nullable NSDictionary *)dictionaryForKey:(NSString *)key;

- (nullable NSArray *)arrayForKey:(NSString *)key;

- (nullable NSString *)stringForKey:(NSString *)key;

- (nullable NSNumber *)numberForKey:(NSString *)key;

- (NSInteger)integerForKey:(NSString *)key;

- (double)doubleForKey:(NSString *)key;

@end

@interface NSMutableDictionary (ZoomKit)

- (void)safelySetObject:(NSObject *)obj forKey:(NSString *)key;

@end
NS_ASSUME_NONNULL_END
