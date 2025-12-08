//
//  NSView+Create.h
//  zChatUI
//
//  Created by groot.ding on 2018/6/14.
//  Copyright © 2018 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>

typedef NS_ENUM(NSUInteger, ZMButtonStyle) {
    ZMButtonStyleRoundFillBlue,
    ZMButtonStyleRoundFillRed,
    ZMButtonStyleRoundBorderHoverBlue,
    ZMButtonStyleRoundNoBorer,
};

@interface NSTextField (Create)


/**
 create TextField

 @return NSTextField instance and need release
 */
+ (instancetype)createTextField NS_RETURNS_RETAINED;

@end

@interface ZMTextField(Create)

+ (instancetype)createActiveBuleInputTextField NS_RETURNS_RETAINED;

@end

@interface ZMAutoShowToolTipTextField (Create)
+ (instancetype)createAutoShowToolTipTextField NS_RETURNS_RETAINED;
@end


@interface ZMButton (Create)


/**
 create button by ZMButtonStyle ,this style is from design : < https://www.figma.com/file/QuGWPtIB5YPfh4hzUHr8Occ4/🌎-All-Components?node-id=8%3A4831 >
 
 @param style buttonStyle
 @return ZMButton instance and need release
 */
+ (instancetype)createButtonByStyle:(ZMButtonStyle)style NS_RETURNS_RETAINED;


/**
 create button by ZMButtonStyleRoundBorderHoverBlue style and
 title is "cancle",
 keyEquivalent is esc,

 @return ZMButton instance
 */
+ (instancetype)createCancelButton NS_RETURNS_RETAINED;


/**
 create button by ZMButtonStyleRoundFillBlue style and
 keyEquivalent is enter,
 
 @return ZMButton instance
 */
+ (instancetype)createComfirmButton NS_RETURNS_RETAINED;


/**
 create button by ZMButtonStyleRoundFillBlue style 
 
 @return ZMButton instance
 */
+ (instancetype)createBorderFillBlueButton NS_RETURNS_RETAINED;

@end
