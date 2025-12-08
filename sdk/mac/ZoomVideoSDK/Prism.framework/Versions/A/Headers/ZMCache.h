//
//  ZMCache.h
//  MessageListDemo
//
//  Created by groot.ding on 05/11/2020.
//  Copyright © 2020 groot.ding. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMCache <KeyType, ObjectType> : NSObject

- (nullable ObjectType)objectForKey:(KeyType)key;

- (void)setObject:(ObjectType)obj forKey:(KeyType)key; // 0 cost
- (void)setObject:(ObjectType)obj forKey:(KeyType)key cost:(NSUInteger)g;
- (void)removeObjectForKey:(KeyType)key;

- (void)removeAllObjects;

@property (readonly) NSUInteger count;

@property NSUInteger totalCostLimit;    // limits are imprecise/not strict
@property NSUInteger countLimit;    // limits are imprecise/not strict

@property NSInteger unuseReleaseTime;   //default 0

@end

NS_ASSUME_NONNULL_END
