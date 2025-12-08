//
//  NSNotificationCenter+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/12.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@interface NSNotificationCenter (ZoomKit)

- (void)addUniqueObserver:(id)observer selector:(SEL)aSelector name:(NSNotificationName)aName object:(nullable id)anObject;

@end
NS_ASSUME_NONNULL_END
