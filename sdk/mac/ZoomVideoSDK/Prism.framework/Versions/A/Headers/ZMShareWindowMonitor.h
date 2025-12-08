//
//  ZMInvisibleWindowMgr.h
//  ZCommonUI
//
//  Created by francis zhuo on 2018/11/23.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Prism/NSWindow+ZoomShare.h>
extern NSNotificationName const ZMUnshareableWindowsDidChanged;
extern NSNotificationName const ZMShareableWindowsDidChanged;

@interface ZMShareWindowMonitor : NSObject
+ (id)sharedMonitor;
/**
 * only main thread can call add/reomve method
 */
- (void)window:(NSInteger)windowID shareTypeChangeTo:(ZMWindowShareType)zmShareType;

/** return windows number array.
 *
 * It is safe to call this method from any thread in your app
 */
- (NSArray<NSNumber *> *)windowsForShareType:(ZMWindowShareType)shareType;
@end
