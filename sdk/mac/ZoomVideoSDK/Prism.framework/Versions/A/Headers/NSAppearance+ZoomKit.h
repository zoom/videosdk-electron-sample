//
//  NSAppearance+ZoomKit.h
//  ZCommonUI
//
//  Created by javenlee on 2019/4/22.
//  Copyright © 2019 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <AppKit/AppKit.h>
#import <Foundation/Foundation.h>

@interface NSAppearance (ZoomKit)
+ (NSAppearance*)zm_darkAppearance;
+ (NSAppearance*)zm_lightAppearance;
@property (readonly) BOOL isDarkMode;

+ (NSAppearance*)zmDrawingAppearance;

- (void)zm_performAsCurrentDrawingAppearance:(void (NS_NOESCAPE ^)(void))block;
@end

@interface NSView (ZoomAppearance)
@property (assign, readonly) BOOL isDarkMode;
@end
