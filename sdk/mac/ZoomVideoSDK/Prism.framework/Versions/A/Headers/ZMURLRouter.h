//
//  ZMURLRouter.h
//  ZCommonUI
//
//  Created by groot.ding on 23/09/2020.
//  Copyright © 2020 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMURLRouterProtocol <NSObject>

- (BOOL)openURL:(NSString *)url;

- (nullable NSArray <NSString *> *)urlFirstComponents;

@optional
- (BOOL)checkHandleURL:(NSString *)url;

@end

@interface ZMURLRouter : NSObject <ZMURLRouterProtocol>

+ (instancetype)sharedInstance;

+ (void)releaseInstance;

- (void)registerURLRouter:(id <ZMURLRouterProtocol>)router key:(NSString *)key;

- (void)unregisterURLRouterByKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
