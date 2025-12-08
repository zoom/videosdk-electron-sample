//
//  NSTouchBar+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/11.
//  Copyright © 2018 zoom. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN
/**
 Is Touch Bar related classes avaliable on current system
 
 @return YES if after 10.13
 */
APPKIT_EXTERN BOOL NSTouchBarAvailable(void);//10.13 above

#ifdef MAC_OS_X_VERSION_10_12_2

@interface NSTouchBarItem (PrivateAPI)

+ (void)addSystemTrayItem:(NSTouchBarItem *)item;//!<private API
+ (void)removeSystemTrayItem:(NSTouchBarItem *)item;//!<private API

@end

@interface NSTouchBar (PrivateAPI)

//! Do not call directry

//new version
+ (void)dismissSystemModalTouchBar:(NSTouchBar *)touchBar;
+ (void)minimizeSystemModalTouchBar:(NSTouchBar *)touchBar;
+ (void)presentSystemModalTouchBar:(NSTouchBar *)touchBar placement:(long long)arg2 systemTrayItemIdentifier:(id)arg3;
+ (void)presentSystemModalTouchBar:(NSTouchBar *)touchBar systemTrayItemIdentifier:(id)arg2;

//old version
+ (void)presentSystemModalFunctionBar:(NSTouchBar *)touchBar systemTrayItemIdentifier:(NSString *)identifier;//!<private API
+ (void)dismissSystemModalFunctionBar:(NSTouchBar *)touchBar;//!<private API

@end

@interface NSTouchBarItem (ZoomKit)

@property (readonly, nullable) NSButton * button;

@end

@interface NSTouchBar (ZoomKit)

+ (instancetype)touchaBar;

+ (void)zm_presentSystemModalTouchBar:(NSTouchBar *)touchBar systemTrayItemIdentifier:(NSString *)identifier;
+ (void)zm_dismissSystemModalTouchBar:(NSTouchBar *)touchBar;

@end

@interface NSCustomTouchBarItem (ZoomKit)

+ (instancetype)itemWithIdentifier:(NSString *)identifier;

//Button Item
+ (instancetype)buttonItemWithIdentifier:(NSString *)identifier title:(nullable NSString *)title image:(nullable NSImage *)image target:(nullable id)target action:(nullable SEL)action;
+ (nullable instancetype)buttonItemWithAssociatedButton:(NSButton *)button;//!<button must be identifier specifically
+ (nullable instancetype)buttonItemWithAssociatedButton:(NSButton *)button handler:(nullable NS_NOESCAPE void (^)(NSButton * button))handler;//!<button must be identifier specifically
@property (assign, nullable) NSButton * button;//!<no null for buttonBarItem

+ (nullable instancetype)buttonItemWithAssociatedNonTemplateButton:(NSButton *)button;

@end
#endif
NS_ASSUME_NONNULL_END
