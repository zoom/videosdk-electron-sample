//
//  NSMenuItem+ZoomKit.h
//  ZCommonUI
//
//  Created by francis zhuo on 2018/10/24.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#ifndef ZMCleanUpMenuItemToNil
#define ZMCleanUpMenuItemToNil(arg) if (arg) {arg.hkIdentifier = nil; arg = nil;}
#endif

#ifndef ZMCleanUpReleaseMenuItemToNil
#define ZMCleanUpReleaseMenuItemToNil(arg) if (arg) {arg.hkIdentifier = nil; [arg release]; arg = nil;}
#endif

@class ZMHMenuItem;
@interface NSMenuItem (ZMHotkey)
@property(copy)IBInspectable NSString* hkIdentifier;

@property (assign, readonly) ZMHMenuItem *equivalentZMHMenuItem;
@end
