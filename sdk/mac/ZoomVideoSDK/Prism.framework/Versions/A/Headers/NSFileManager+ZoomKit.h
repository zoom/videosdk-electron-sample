//
//  NSFileManager+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/7/30.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <AppKit/AppKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSFileManager (ZoomKit)

- (BOOL)copyItemAtPathReplaceIfNeeded:(NSString *)srcPath toPath:(NSString *)dstPath error:(NSError **)error;

- (BOOL)safeRemoveItemAtPath:(NSString *)path error:(NSError **)error;

- (BOOL)hasInvalidItemsAtPaths:(NSArray<NSString *> *)paths
                  invalidPaths:(NSArray<NSString *> * _Nonnull * _Nullable)outInvalidPaths;

@end

NS_ASSUME_NONNULL_END
