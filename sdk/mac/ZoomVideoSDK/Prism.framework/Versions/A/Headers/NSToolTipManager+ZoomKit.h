//
//  NSToolTipManager+ZoomKit.h
//  ZCommonUI
//
//  Created by groot.ding on 25/08/2020.
//  Copyright © 2020 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

//private class
@interface NSToolTip : NSObject

- (NSView *)view;

@end

//private class
@interface NSToolTipManager : NSObject

@end

@interface NSToolTipManager (ZoomKit)

@end

NS_ASSUME_NONNULL_END
