//
//  ZMMenuEventHelper.h
//  ZoomKit
//
//  Created by martin yu on 2024/3/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 This Class is designed to solve Menu related problems.
 
 For ZMMenu, ZMHMenu and NSMenu, the following steps will cause team chat session list become unresponsive:
 1.Make other app(such as TextEdit.app) active
 2.Open a ZMMenu, ZMHMenu or NSMenu in the nonactivating panel(such as in-meeting chat panel, plist panel or zoom setting panel)
 3.Click the team chat session list outline view.
 */
@interface ZMMenuEventHelper : NSObject
+ (instancetype)sharedInstance;
- (void)setup;

@property (nonatomic, assign, readonly) BOOL isAppActive;

- (nullable NSEvent *)generateFakeEventForEvent:(NSEvent *)event;
@end

@interface NSMenu (ZMMenuEventHelper)
@property (nonatomic, assign) BOOL zm_ignoreTrackingNSMenuEvent;
@end

NS_ASSUME_NONNULL_END
