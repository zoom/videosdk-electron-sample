//
//  NSScreen+ZMConvenience.h
//  checkMainMenu
//
//  Created by francis zhuo on 24/11/2017.
//  Copyright © 2017 fenfei. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <AppKit/AppKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSScreen(ZoomKit)

@property (readonly) NSEdgeInsets safeAreaInsets API_AVAILABLE(macos(12.0));
- (NSPoint)frameCenter;
- (BOOL)hasCameraNotch;
@property (class, readonly, nullable, strong) NSScreen *mouseLocatedScreen;
+ (nullable NSScreen*)zmScreenAtPoint:(NSPoint)point;
@end

@interface NSScreen (MenuBar)
- (BOOL)isMenuBarVisible:(CGFloat *_Nullable)menuHeight;
@end

NS_ASSUME_NONNULL_END
