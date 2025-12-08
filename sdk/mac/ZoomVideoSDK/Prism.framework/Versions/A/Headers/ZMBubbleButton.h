//
//  ZMBubbleButton.h
//  ZCommonUI
//
//  Created by Francis Zhuo on 4/3/21.
//  Copyright © 2021 zoom. All rights reserved.
//

#import <Prism/ZMButton.h>
#import <Prism/ZMTextBubbleObject.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, ZMBubbleShowBehavior){
    ZMBubbleShowBy_Enter_Button   = 1,
    ZMBubbleShowBy_BecomeKey      = 1<<1,
    ZMBubbleShowBy_Click_Button   = 1<<2,
    ZMBubbleShowBy_Enter_Bubble   = 1<<3,
    ZMBubbleShowBy_EscAction      = 1<<4,
    
    ZMBubbleShowBy_Delay          = 1<<10,
    ZMBubbleShowBy_Customer       = 1<<20,
};
typedef NS_OPTIONS(NSUInteger, ZMBubbleHideBehavior){
    ZMBubbleHideBy_Exit_Button    = 1,
    ZMBubbleHideBy_ResignKey      = 1<<1,
    ZMBubbleHideBy_Click_Button   = 1<<2,
    ZMBubbleHideBy_Exit_Bubble    = 1<<3,
    ZMBubbleHideBy_Click_Other    = 1<<4,
    ZMBubbleHideBy_EscAction      = 1<<5,
    
    ZMBubbleHideBy_Delay          = 1<<10,
    ZMBubbleHideBy_Customer       = 1<<20,
};

//for quick to set show and hide behavior
typedef NS_OPTIONS(NSUInteger, ZMBubbleButtonBehavior){
    ZMBubbleButtonBehavior_Hover        = 1,
    
    ZMBubbleButtonBehavior_Hover_BAB    = 1<<1|ZMBubbleButtonBehavior_Hover,
    ZMBubbleButtonBehavior_BecomeKey    = 1<<5,
    ZMBubbleButtonBehavior_Click        = 1<<6,
    
    ZMBubbleButtonBehavior_Customer     = 1<<20,
};

//for customer behavior
typedef NS_OPTIONS(NSUInteger, ZMBubbleButtonEvent){
    ZMBubbleButtonEvent_Enter_Button      = 1,
    ZMBubbleButtonEvent_Exit_Button       = 1<<1,
    ZMBubbleButtonEvent_BecomeKey         = 1<<2,
    ZMBubbleButtonEvent_ResignKey         = 1<<3,
    ZMBubbleButtonEvent_Click_Button      = 1<<4,
    
    ZMBubbleButtonEvent_Time_Beat         = 1<<5,
    ZMBubbleButtonEvent_Enter_Bubble      = 1<<6,
    ZMBubbleButtonEvent_Exit_Bubble       = 1<<7,
    ZMBubbleButtonEvent_Click_Bubble      = 1<<8,
    ZMBubbleButtonEvent_Click_Other       = 1<<9,
    ZMBubbleButtonEvent_EscAction         = 1<<10,
};
typedef NS_OPTIONS(NSUInteger, ZMBubbleButtonEventMask){
    ZMBubbleButtonEventMask_Button_Hovered = 1,
    ZMBubbleButtonEventMask_Bubble_Hovered = 1<<1,
    ZMBubbleButtonEventMask_Button_Keyview = 1<<2,
};

@class ZMBubbleButton;
@protocol ZMBubbleButtonDelegate<NSObject>
@optional
- (void)willShowBubbleTipForButton:(ZMBubbleButton*)bubbleButton;
- (void)didShowBubbleTipForButton:(ZMBubbleButton*)bubbleButton;
- (void)willHideBubbleTipForButton:(ZMBubbleButton*)bubbleButton;
- (void)didHideBubbleTipForButton:(ZMBubbleButton*)bubbleButton;
@end

@interface ZMBubbleButton : ZMButton
@property(nonatomic, assign) ZMBubbleButtonBehavior behavior;//defualt is ZMBubbleButtonBehavior_Click
//for more refined Settings
@property(nonatomic, assign) ZMBubbleShowBehavior showBehavior;
@property(nonatomic, assign) ZMBubbleHideBehavior hideBehavior;

@property(nonatomic, weak) id<ZMBubbleButtonDelegate> delegate;

@property(nonatomic, retain,nullable) ZMBubbleObject* bubbleObject;

@property (nonatomic, assign) NSRectEdge preferredEdge;
@property (nonatomic, assign) NSInteger bubbleGap;//the bubble offset with button

- (void)setShowPopover:(BOOL)showPopover;
@property (readonly, assign) BOOL isBubbleShowing;

@property (assign) CGFloat timerInterval;//default 0.1s
@property (weak) NSEvent* mouseEvent;
@property (nonatomic, assign) ZMBubbleButtonEventMask eventMask;
@property (copy) BOOL (^shouldShowBubble)(ZMBubbleButton* button, ZMBubbleButtonEvent event);
@property (copy) BOOL (^shouldHideBubble)(ZMBubbleButton* button, ZMBubbleButtonEvent event);

- (void)willShowBubbleTip NS_REQUIRES_SUPER;
- (void)didShowBubbleTip NS_REQUIRES_SUPER;
- (void)willHideBubbleTip NS_REQUIRES_SUPER;
- (void)didHideBubbleTip NS_REQUIRES_SUPER;
@end

@interface ZMTextBubbleButton : ZMBubbleButton
@property(nonatomic, retain,nullable) ZMTextBubbleConfig* config;

@property (nonatomic, copy,nullable) NSString *textString;
@property (nonatomic, copy,nullable) NSAttributedString *textAttributedString;
@property (nonatomic, assign) BOOL supportHyperlinks;//default is NO;

@end

NS_ASSUME_NONNULL_END
