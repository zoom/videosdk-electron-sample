//
//  ZMRichKeyButton.h
//  ZCommonUI
//
//  Created by Huxley on 2018/12/28.
//  Copyright © 2018 zoom. All rights reserved.
//
#import <Cocoa/Cocoa.h>

@interface ZMRichKeyButton : NSButton

- (void)commonInit NS_REQUIRES_SUPER; // to override
- (void)cleanUp NS_REQUIRES_SUPER;

- (void)setAction:(SEL)selector forKeyCode:(NSInteger)keyCode;//!< Custom an action for a specified keycode
- (void)removeActionForKeyCode:(NSInteger)keyCode;
- (void)addClickKey:(NSInteger)keyCode;
- (void)removeClickKey:(NSInteger)keyCode;

@property (assign, nonatomic) IBInspectable BOOL dropDown; //!< Make this property to YES, if button will trigger a Menu popup
@property (assign, nonatomic) IBInspectable BOOL popUp; //!< Make this property to YES, if button will trigger a Menu popup

@property (nonatomic , assign) BOOL zmEnable;

@end
