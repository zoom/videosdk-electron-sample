//
//  NSArray+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/11.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSArray <__covariant ObjectType> (ZoomKit)

@property (readonly) ObjectType map;

- (BOOL)differentWithArray:(NSArray *)array selfDiff:(NSArray *_Nonnull * _Nullable)selfDiffObjects dstDiff:(NSArray *_Nonnull * _Nullable)dstDiffObjects;

- (nullable ObjectType)safeGetObjectAtIndex:(NSUInteger)index;

- (nullable NSArray *)minusWithArray:(nullable NSArray *)array;

- (void)makeObjectsPerformSelectorIfAvailable:(SEL)aSelector;
- (void)makeObjectsPerformSelectorIfAvailable:(SEL)aSelector withObject:(nullable id)argument;

- (BOOL)isRangeValid:(NSRange)range;

- (NSString *)toJsonString;

@end

@interface NSMutableArray <ObjectType> (ZoomKit)

- (BOOL)addObjectIfNonull:(nullable ObjectType)object;
- (BOOL)addObjectsFromArrayIfNonull:(nullable NSArray *)array;
- (void)moveObjectFromIndex:(NSUInteger)fromIndex toIndex:(NSUInteger)toIndex;//! Use -moveObjectAtIndex:toIndex: instead

- (BOOL)moveObjectAtIndex:(NSUInteger)fromIndex toIndex:(NSUInteger)toIndex;
@end

NS_ASSUME_NONNULL_END
