//
//  NSScrollView+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/9/13.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface NSScrollView (ZoomKit)

@property (nonatomic,assign) BOOL stopForMenuPopup;

- (void)zm_pulseOverlayScrollers;

- (BOOL)shouldAutoScroll;

@end
