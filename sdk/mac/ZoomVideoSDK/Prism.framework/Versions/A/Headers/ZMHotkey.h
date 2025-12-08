//
//  ZMHotkey.h
//  ZCommonUI
//
//  Created by francis on 2017/7/24.
//  Copyright © 2017 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

typedef BOOL(^keyDownAction)(id attachment,NSEvent* event);
typedef BOOL(^keyUpAction)(id attachment, NSEvent* event);

@class ZMHotkeyCombo;
@class ZMHotkeyCenter;
@interface ZMHotkey : NSObject<NSCopying>
{
@private
    NSString*       _identifier;
    ZMHotkeyCombo*  _hotkeyCombo;
    id              _attachment;
    
    SEL             _action;//keyDown Action
    SEL             _keyUpAction;
    
    keyDownAction   _keyDownActionBlock;
    keyUpAction     _keyUpActionBlock;
    
    CGFloat         _keyDownLongPressDelay;
    
    void*       	_eventHotKeyRef;
    
    NSEvent*        _downEvent;
    BOOL            _isKeyDown;
}
@property(nonatomic, copy) NSString* identifier;
@property(nonatomic, readwrite, copy) ZMHotkeyCombo*  hotkeyCombo;
@property(nonatomic, retain) id attachment;

@property(nonatomic, weak) id target;
@property(nonatomic, assign) SEL action;
@property(nonatomic, assign) SEL keyUpAction;
@property(nonatomic, copy) keyDownAction keyDownActionBlock;
@property(nonatomic, copy) keyUpAction keyUpActionBlock;

@property(nonatomic, assign) CGFloat keyDownLongPressDelay;
@property(nonatomic, assign) void* eventHotKeyRef;
@property(nonatomic, readonly, assign) BOOL isSingleKeyCombo;
@property(nonatomic, weak) ZMHotkeyCenter* hotkeyCenter;

@property(nonatomic, readonly, assign) BOOL isKeyDown;
@property(nonatomic, readonly, assign) BOOL isLongPressHotkey;
/**
 * if the hotcombo modifier is equal 0, the default value is YES
 * otherwise the default value is NO.
 */
@property(nonatomic, assign) BOOL skipWhenTyping;
+ (id)hotkeyWithIdentifier:(NSString*)identifier withObject:(id)attachment;
+ (id)hotkeyWithIdentifier:(NSString*)identifier keyCombo:(ZMHotkeyCombo*)combo withObject:(id)attachment;
- (id)init;
- (id)initWithIdentifier:(NSString*)identifier keyCombo:(ZMHotkeyCombo*)combo;
- (id)initWithIdentifier:(NSString*)identifier keyCombo:(ZMHotkeyCombo*)combo withObject:(id)attachment;
- (void)cleanUp;
- (BOOL)keyDown:(NSEvent*)event;
- (BOOL)keyUp:(NSEvent*)event;
@end
