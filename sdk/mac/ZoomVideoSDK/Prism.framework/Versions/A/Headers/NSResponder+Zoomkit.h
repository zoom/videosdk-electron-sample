//
//  NSResponder+Zoomkit.h
//  ZoomKit
//
//  Created by Francis Zhuo on 2025/5/19.
//

#import <Cocoa/Cocoa.h>
#import <AppKit/AppKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSResponder (Zoomkit)
///if you did handle this event, please return responder, Otherwise return nil
///if you just handle event with keyUp, please also return responder when event with keyDown.
///
//- (NSResponder *)handleHotkeyWithEvent:(NSEvent *)event {
//if (event.keyCode == KEY_F && event.modifierFlags == NSEventModifierFlagCommand) {
//    if (event.type == NSEventTypeKeyDown) {
//        //open search window...
//    }
//    return self;
//}
//return [super handleHotkeyWithEvent:event];
//}

- (NSResponder*)handleHotkeyWithEvent:(NSEvent*)event;

@end
NS_ASSUME_NONNULL_END
