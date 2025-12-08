//
//  NSObject+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/12.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Prism/ZMObjectDispose.h>
#import <Prism/ZMPlainBlock.h>

NS_ASSUME_NONNULL_BEGIN

#ifndef __ZM_FUNC__

#define __ZM_FUNC__ [NSString stringWithFormat:@"[%p]%s,%@",self,__FUNCTION__,self.zmLogIdentifier].UTF8String

#endif

@interface NSObject (ZoomKit) <ZMObjectDispose>
- (void)cleanUp;

@property (nonatomic,copy) NSString *zmLogIdentifier;

- (void)performSelector:(SEL)aSelector withArguments:(NSArray *)arguments afterDelay:(NSTimeInterval)delay;
- (void)modifyValueWithBlock:(/*NS_NOESCAPE*/ ZMPlainBlock)block forKey:(NSString *)key;
- (BOOL)conformsToProtocol:(Protocol *)aProtocol toPerformSelector:(SEL)aSelector withObject:(nullable id)object;

+ (BOOL)swizzleSEL:(SEL)originalSEL withSEL:(SEL)swizzledSEL;
+ (BOOL)swizzleClass:(id)originalClass andSEL:(SEL)originalSEL withTaget:(id)targetClass andSEL:(SEL)targetSEL;
@end
NS_ASSUME_NONNULL_END
