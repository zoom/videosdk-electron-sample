//
//  ZMPureWindow.h
//  zChatUI
//
//  Created by Huxley Yang on 2018/1/24.
//  Copyright © 2018 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ZMPureWindow : NSWindow

+ (instancetype)borderlessWindowWithView:(NSView *)view;
+ (instancetype)borderedWindowWithView:(NSView *)view;

@property (nonatomic) BOOL canBecomeKeyWindow;

@end
