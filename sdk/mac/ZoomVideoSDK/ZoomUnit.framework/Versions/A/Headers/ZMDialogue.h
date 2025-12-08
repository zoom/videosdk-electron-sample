//
//  ZMDialogue.h
//  TestDownloader
//
//  Created by Yang on 05/01/2018.
//  Copyright © 2018 Yang. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <ZoomUnit/ZMProgressIndicator.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, ZMDialogueResponse)
{
    ZMDialogueResponseFirst = 1000,
    ZMDialogueResponseSecond = 1001,
    ZMDialogueResponseThird = 1002
};

typedef void (^ ZMDialogueHandler)(ZMDialogueResponse response);

@class ZMButton;
@interface ZMDialogue : NSWindowController
{
    ZMButton *_firstButton;
    ZMButton *_secondButton;
    ZMButton *_thirdButton;
    ZMDialogueHandler _handler;
    
    BOOL _keepAlive;
}

@property (weak, readonly) NSTextField *messageField;
@property (weak, readonly) ZMProgressIndicator *indicator;
@property (readonly) NSButton *firstButton;
@property (readonly) NSButton *secondButton;
@property (readonly) NSButton *thirdButton;
@property (assign) BOOL keepAlive;

- (void)beginSheet:(nullable NSWindow *)sheetWindow completionHandler:(nullable ZMDialogueHandler)handler;
- (void)endSheet;

@end
NS_ASSUME_NONNULL_END
