//
//  ZMCallbackImpl.h
//  zChatUI
//
//  Created by groot.ding on 2019/1/30.
//  Copyright © 2019 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ZMReminderMessageInfo;

//callback types

typedef void(^ZMCallbackBlock)(NSString *key,id param,NSError *error);

typedef void(^ZMReminderCallbackBlock)(ZMReminderMessageInfo *info, NSError *error);

@interface ZMCallbackImpl : NSObject

//callback key listeners

- (void)addCallBackKey:(NSString *)callbackKey key:(NSString *)key
                 block:(ZMCallbackBlock)completion;

- (void)addCallBackKey:(NSString *)callbackKey key:(NSString *)key
            identifier:(NSUInteger)identifier block:(ZMCallbackBlock)completion;

- (void)addCallBackKey:(NSString *)callbackKey key:(NSString *)key
               timeout:(float)timeout timeoutError:(NSError *)timeoutError
                 block:(ZMCallbackBlock)completion;

- (void)addCallBackKey:(NSString *)callbackKey key:(NSString *)key
               timeout:(float)timeout timeoutError:(NSError *)timeoutError timeoutParam:(id)timeoutParam
                 block:(ZMCallbackBlock)completion;

- (void)addCallBackKey:(NSString *)callbackKey key:(NSString *)key
               timeout:(float)timeout timeoutError:(NSError *)timeoutError timeoutParam:(id)timeoutParam
            identifier:(NSUInteger)identifier block:(ZMCallbackBlock)completion;

- (void)callBackByKey:(NSString *)callbackKey key:(NSString *)key
                param:(id)param error:(NSError *)error;

- (void)removeCallbakByKey:(NSString *)callbackKey;

- (void)removeCallbakByKey:(NSString *)callbackKey identifier:(NSUInteger)identifier;

- (BOOL)hasCallbackByKey:(NSString *)callbackKey;

//target listeners

- (void)addListenCallbakByTarget:(id)target typeKey:(NSString *)typeKey block:(ZMCallbackBlock)completion;

- (void)callbackListenByTypekey:(NSString *)typeKey key:(NSString *)key
                          param:(id)param error:(NSError *)error;

- (void)removeListenCallbakByTarget:(id)target;


@end
