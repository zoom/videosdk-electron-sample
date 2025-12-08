//
//  NSButton+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/12.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Prism/NSControl+ZoomKit.h>

typedef void(^ZMButtonActionBlock)(void);

@interface NSButton (ZoomKit)

@property (retain) IBInspectable NSString* zmTitle;

@property (retain) id data;

- (void)targetActionToNil;

- (void)onClick:(ZMButtonActionBlock)block;

- (instancetype)bezelColor:(NSColor *)color;

- (void)makeTitleAttributed:(NSDictionary *)attribute;

- (void)setTextColor:(NSColor *)color font:(NSFont *)font;

+ (instancetype)buttonWithTitle:(NSString *)title target:(id)target action:(SEL)action frame:(NSRect)frame;//!<
+ (instancetype)radioButtonWithTitle:(NSString *)title target:(id)target action:(SEL)action frame:(NSRect)frame;//!<
+ (instancetype)checkboxWithTitle:(NSString *)title target:(id)target action:(SEL)action frame:(NSRect)frame;//!<
+ (instancetype)zm_buttonWithImage:(NSImage *)image target:(id)target action:(SEL)action;

@end

@interface NSPopUpButton (ZoomKit)

- (NSMenuItem *)addItemWithTitle:(NSString *)title tag:(NSInteger)tag;

@end

@interface NSButton (ZMHotkey)
@property(copy)IBInspectable NSString* hkIdentifier;
- (void)setValueIdentifier:(NSString*)valueIdentifier global:(BOOL)isGlobal;//for CheckBox Button
@end
