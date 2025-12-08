//
//  ZMHotkeyMgr.h
//  ZCommonUI
//
//  Created by francis on 2017/7/24.
//  Copyright © 2017 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN
@class ZMHotkeyCombo;
@class ZMHotkey;
@protocol ZMHotkeyCenterDelegate;
@interface ZMHotkeyCenter : NSObject
@property(nullable, weak) id<ZMHotkeyCenterDelegate> delegate;
@property(nonatomic, readonly, assign) BOOL isGlobalPaused;
@property(nonatomic, readonly, assign) BOOL isLocalPaused;
@property(nonatomic, assign) BOOL supportNoneModifiers;
@property(nonatomic, assign) UInt32 globalRequiredModifiers;
@property(nonatomic, assign) UInt32 localRequiredModifiers;
- (void)cleanUp;
- (BOOL)registerHotKey:(ZMHotkey*)hotKey global:(BOOL)isGlobal;
- (void)unregisterHotKey:(ZMHotkey*)hotKey global:(BOOL)isGlobal;
- (void)unregisterHotKeyByIdentifier:(NSString*)identifier global:(BOOL)isGlobal;

/**
 * assume the hotkey.identifier is not nil
 */
- (BOOL)bindHotKey:(ZMHotkey*)hotKey global:(BOOL)isGlobal;
- (BOOL)isBindByIdentifier:(NSString*)identifier global:(BOOL)isGlobal;
- (void)unbindHotkeyByIdentifier:(NSString*)identifier global:(BOOL)isGlobal;
- (void)unbindAll;

- (void)pause:(BOOL)isGlobal;
- (void)pauseAll;
- (void)resume:(BOOL)isGlobal;
- (void)resumeAll;

- (void)hotkey:(ZMHotkey*)hotkey longPressFail:(NSEvent*)downEvent upEvent:(NSEvent*)upEvent;
@end

@protocol ZMHotkeyCenterDelegate <NSObject>
@optional
- (BOOL)hotkeyCenter:(ZMHotkeyCenter*)center shouldSkipHotkey:(ZMHotkey*)hotkey event:(NSEvent*)event suggest:(BOOL)shouldSkip;
- (BOOL)hotkeyCenter:(ZMHotkeyCenter*)center longPressFail:(ZMHotkey*)hotkey shouldShortPress:(NSEvent*) downEvent upEvent:(NSEvent*)upEvent;
- (void)hotkeyCenter:(ZMHotkeyCenter*)center hotkeyWillUpdate:(ZMHotkey*)hotkey;
@end

NS_ASSUME_NONNULL_END

