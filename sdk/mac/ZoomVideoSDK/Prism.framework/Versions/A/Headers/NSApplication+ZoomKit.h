//
//  NSApplication+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/12.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <AppKit/AppKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
APPKIT_EXTERN NSNotificationName const NSAccessibilityVoiceOverStatusChanged;//!< Notification
APPKIT_EXTERN NSString *const kZMUserAppearanceKey;
APPKIT_EXTERN NSString *const kZMFontSizeChangedKey;
APPKIT_EXTERN NSString *const KZMAccessibilityVoiceOverStatusObserverKey;

typedef NS_ENUM(NSInteger, ZMUserAppearance){
    ZMUserAppearanceSystem,
    ZMUserAppearanceLight,
    ZMUserAppearanceDark,
};

struct ZMVoiceOverInfo {
    BOOL isVoiceOverInitialized;
    BOOL isVoiceOverEnabledInCache;
};
APPKIT_EXTERN struct ZMVoiceOverInfo globalZMVoiceOverInfo;

@protocol ZMFontSizeDelegate <NSObject>
@optional
- (NSInteger)fontSizeDidFetch;
- (void)fontSizeDidChange:(NSInteger)newFontSize;
@end

@interface NSApplication (ZoomKit)
@property (nonatomic, readonly, assign) BOOL isDebuggerAttached;

@property (assign) BOOL canTerminateNow;
@property (assign, readonly) BOOL isSupportDarkMode;

@property (readonly, assign) BOOL isSupportUserAppearance;
@property (assign) ZMUserAppearance userAppearance;

@property (readonly, getter=isVoiceOverRunning) BOOL voiceOverRunning;//!< for tab control, use 'fullKeyboardAccessEnabled'

@property (nonatomic, assign) BOOL retinaBundleNotReady;
@property (readonly) BOOL isDarkMode;
@property (readonly) BOOL isLayoutRTL;
@property (assign) NSInteger fontSizeRate;
@property (assign) NSInteger lastFontSizeRate;
@property (nonatomic, weak) id<ZMFontSizeDelegate> fontSizeDelegate;

/**
 * check if screen recording in Security&Privacy is turn on
 **/
+ (BOOL)isScreenRecordingOn;

- (BOOL)inTyping;
/**
 mac os 13 & stage Manager mode
 */
+ (BOOL)isStageManagerMode;

- (BOOL)isRunAsHuddle;

//- (void)swizzledSendEvent:(NSEvent*)event;
@end
NS_ASSUME_NONNULL_END
