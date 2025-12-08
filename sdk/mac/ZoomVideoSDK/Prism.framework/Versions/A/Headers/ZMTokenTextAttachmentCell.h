//
//  ZMTokenTextAttachmentCell.h
//  zChatUI
//
//  Created by groot.ding on 2018/5/22.
//  Copyright © 2018 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ZMTokenTextAttachmentCell : NSTextAttachmentCell

@property(nonatomic, copy) NSString *name;

@property(nonatomic, retain) NSDictionary *userInfo;

@property (nonatomic,copy) void (^remove)(ZMTokenTextAttachmentCell *cell);

@property (nonatomic,copy) void (^expand)(ZMTokenTextAttachmentCell *cell, NSUInteger atCharacterIndex);

@property (nonatomic, assign) BOOL isShowExternal;
@property (nonatomic, assign) BOOL isShowPending;
@property (nonatomic, assign) BOOL isShowAdded;

//default YES
@property (nonatomic, assign) BOOL isNeedShowCloseButton;

//default NO
@property (nonatomic, assign) BOOL isNeedShowExpandButton;

@property (readonly) NSRect closeIconRect;

@property (readonly) NSRect expandIconRect;

@property (nonatomic, assign) BOOL expandEnable;

@property (nonatomic, retain) NSColor *borderColor;

@property (nonatomic, retain) NSColor *backgroundColor;

@property (nonatomic, retain) NSColor *highlightBackgroundColor;

@property (nonatomic, retain) NSString *accessibilityDescription;

@property (nonatomic, retain) NSColor *textColor;

@property (nonatomic, copy) NSString *closeButtonLabel;


- (NSAttributedString *)attributedString;

@end
