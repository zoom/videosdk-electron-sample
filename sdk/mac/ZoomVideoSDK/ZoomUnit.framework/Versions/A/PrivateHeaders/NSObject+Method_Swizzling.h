//
//  NSObject+Method_Swizzling.h
//  ChatUI
//
//  Created by Cooper.Chen on 2023/11/13.
//  Copyright © 2023 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (Method_Swizzling)

+ (void)zoomDefenderSwizzlingClassMethod:(SEL)originalSelector withMethod:(SEL)swizzledSelector withClass:(Class)targetClass;

+ (void)zoomDefenderSwizzlingInstanceMethod:(SEL)originalSelector withMethod:(SEL)swizzledSelector withClass:(Class)targetClass;

@end

#ifndef __ZOOM_NO_CLIENT_LOG

@interface ZMSafeCushionAlert : NSObject

+ (void)dumpSafeCushionLog;

@end

#endif

NS_ASSUME_NONNULL_END
