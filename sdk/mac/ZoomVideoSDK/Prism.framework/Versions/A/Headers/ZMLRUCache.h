//
//  ZMLRUCache.h
//  ZoomKit
//
//  Created by Zoro.Fu on 2022/6/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMLRUCache <KeyType, ObjectType> : NSObject

@property (assign, nonatomic, readonly) NSUInteger capacity;

@property (assign, nonatomic, readonly) NSUInteger count;
/// How long does cached data expire， default is 10 secs.
@property (assign, nonatomic) NSUInteger defaultExpiredTime;

- (instancetype)initWithCapacity:(NSUInteger)capacity defaultExpiredTime:(NSUInteger)defaultExpiredTime;

+ (instancetype)cacheWithCapacity:(NSUInteger)capacity;

- (void)setObject:(nullable ObjectType)value forKey:(KeyType)key;

- (nullable ObjectType)objectForKey:(KeyType)key;

- (nullable ObjectType)firstObject;

- (void)removeFirstObject;

- (void)cleanCache;

@end

NS_ASSUME_NONNULL_END
