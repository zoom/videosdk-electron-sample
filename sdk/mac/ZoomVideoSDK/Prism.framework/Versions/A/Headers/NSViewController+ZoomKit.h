//
//  NSView+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/11.
//  Copyright © 2018 zoom. All rights reserved.
//
#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN
@class ZMNavigationController;
@interface NSViewController (ZoomKit)

@property (nonatomic, weak, nullable) ZMNavigationController *zmNavigationController;

@end
NS_ASSUME_NONNULL_END

