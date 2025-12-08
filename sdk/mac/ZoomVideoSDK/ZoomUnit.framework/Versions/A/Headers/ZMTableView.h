//
//  ZMTableView.h
//  zChatUI
//
//  Created by groot.ding on 2018/5/19.
//  Copyright © 2018 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ZMTableView : NSTableView

@property (nonatomic,copy) BOOL (^interceptKeyDownBlock)(NSEvent *);
@property (nonatomic,copy) void (^becomeFirstResponsederBlock)(BOOL);

@property (nonatomic,assign) BOOL keyDownFocusRingOnly; //no focus ring when mouse down

@property (assign) BOOL allowMutableSelected;

@property (assign) BOOL mutableSelectOnlyOne;

@end
