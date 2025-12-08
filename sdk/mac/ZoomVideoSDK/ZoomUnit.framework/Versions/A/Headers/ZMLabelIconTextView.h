//
//  ZMLabelIconTextView.h
//  zChatUI
//
//  Created by Yong Zhou on 2021/7/16.
//  Copyright © 2020 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

typedef NS_ENUM(NSInteger, ZMLabelIconStateType)
{
    ZMLabelIconStateType_Normal,
    ZMLabelIconStateType_Hover,
    ZMLabelIconStateType_Selected,
    ZMLabelIconStateType_NoAlpha
};

NS_ASSUME_NONNULL_BEGIN

@interface ZMLabelIconTextView : NSTextField

@property (nonatomic, assign) ZMLabelIconStateType stateType;

@property(nonatomic, copy , nullable) NSString *labelTitle;
- (NSSize)stringSize;
@end

NS_ASSUME_NONNULL_END
