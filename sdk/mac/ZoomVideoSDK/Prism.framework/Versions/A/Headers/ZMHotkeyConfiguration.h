//
//  ZMHotkeyConfiguration.h
//  ZCommonUI
//
//  Created by francis zhuo on 2019/2/21.
//  Copyright © 2019 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>


extern NSNotificationName const kZMHotkeyValueDidChanged;

typedef NSString* ZMHotkeyName NS_EXTENSIBLE_STRING_ENUM;

@interface ZMHotkeyConfiguration : NSObject
+ (NSDictionary<NSString*, NSNumber*>*)hotkeyMap;
+ (void)registerDefaultHotkey;

+ (BOOL)getHotkeyState:(ZMHotkeyName)hkIdentifier global:(BOOL)isGlobal;
+ (void)setHotkeyEnable:(BOOL)enable key:(ZMHotkeyName)hkIdentifier global:(BOOL)isGlobal;

+ (NSArray<NSDictionary*>*)defaultHotkeyArray;
+ (NSArray<NSDictionary*>*)customHotkeyArray:(BOOL)isGlobal;
+ (NSArray<ZMHotkeyName>*)supportGlobalHotkeyNameArray;
+ (void)restoreDefaults;
+ (NSDictionary*)hotkeyInfo:(ZMHotkeyName)hotkeyName global:(BOOL)isGlobal;
+ (void)saveHotkey:(ZMHotkeyName)hotkeyName global:(BOOL)isGlobal hotkey:(NSDictionary*)hotkey;
@end
