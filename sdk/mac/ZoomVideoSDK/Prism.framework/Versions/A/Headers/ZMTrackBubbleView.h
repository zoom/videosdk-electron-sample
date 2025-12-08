//
//  ZMMTTrackImageView.h
//  VideoUI
//
//  Created by davies zhao on 2022/5/23.
//  Copyright © 2022 zoom.us. All rights reserved.
//
#import <Prism/ZMTrackingView.h>
#import <Prism/ZMBubbleButton.h>

NS_ASSUME_NONNULL_BEGIN
@class ZMTrackBubbleView;
@protocol ZMTrackBubbleViewDelegate <NSObject>
@optional
- (void)willShowBubbleTip:(ZMTrackBubbleView* )view bubbleObject:(ZMBubbleObject *)bubbleObject;
- (void)didShowBubbleTip:(ZMTrackBubbleView* )view bubbleObject:(ZMBubbleObject *)bubbleObject;
- (void)willHideBubbleTip:(ZMTrackBubbleView* )view bubbleObject:(ZMBubbleObject *)bubbleObject;
- (void)didHideBubbleTip:(ZMTrackBubbleView* )view bubbleObject:(ZMBubbleObject *)bubbleObject;

@end

@interface ZMTrackBubbleView : ZMTrackingView

@property (nonatomic, weak) id<ZMTrackBubbleViewDelegate> bubbleViewdelegate;

@property(nonatomic, assign) ZMBubbleButtonBehavior behavior;//defualt is ZMBubbleButtonBehavior_Click
//for more refined Settings
@property(nonatomic, assign) ZMBubbleShowBehavior showBehavior;
@property(nonatomic, assign) ZMBubbleHideBehavior hideBehavior;

@property(nonatomic, retain, nullable) ZMBubbleObject* bubbleObject;

@property (nonatomic, assign) NSRectEdge preferredEdge;
@property (nonatomic, assign) NSInteger bubbleGap;//the bubble offset with image

- (void)setShowPopover:(BOOL)showPopover;
@property (readonly, assign) BOOL isBubbleShowing;

@property (assign) CGFloat timerInterval;//default 0.1s
@property (assign) CGFloat hiddenTimerInterval;//default 0.1s
@property (weak) NSEvent* mouseEvent;
@property (nonatomic, assign) ZMBubbleButtonEventMask eventMask;
@property (copy) BOOL (^shouldShowBubble)(ZMTrackBubbleView* image, ZMBubbleButtonEvent event);
@property (copy) BOOL (^shouldHideBubble)(ZMTrackBubbleView* image, ZMBubbleButtonEvent event);

- (void)willShowBubbleTip NS_REQUIRES_SUPER;
- (void)didShowBubbleTip NS_REQUIRES_SUPER;
- (void)willHideBubbleTip NS_REQUIRES_SUPER;
- (void)didHideBubbleTip NS_REQUIRES_SUPER;
@end

NS_ASSUME_NONNULL_END
