//
//  ZMIMTrackingScrollView.h
//  zChatUI
//
//  Created by ryan on 30/05/2018.
//  Copyright © 2018 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#define ZMRefreshViewHeight 40.0f

typedef NS_ENUM(NSUInteger, ZMIMTrackingScrollViewType)
{
    ZMIMTrackingScrollViewType_none                 = 0,
    ZMIMTrackingScrollViewType_hoverToSelect        = 1 << 0,
    ZMIMTrackingScrollViewType_hoverButNotSelect    = 1 << 1,
    ZMIMTrackingScrollViewType_doMyself             = 1 << 2,
};


typedef NS_ENUM(NSUInteger, ZMScrollLoadingState) {
    ZMScrollLoadingStateNone = 0,
    ZMScrollLoadingStateUp = 1 << 1,
    ZMScrollLoadingStateDown = 1 << 2,
};

@interface ZMLoadingClipview : NSClipView

@property (nonatomic, assign) BOOL shouldKeepBottom;
@property (assign) BOOL shouldFixOriginPoint;
@property (assign) NSPoint fixedOriginPoint;

@property (nonatomic,assign) CGFloat fixBottomHeight;

@end

@interface ZMIMLoadingScrollView :NSScrollView


@property (weak) id delegate;


/**
 pull up no more
 */
@property (nonatomic,assign) BOOL upNoMore;


/**
 pull down no more
 */
@property (nonatomic,assign) BOOL downNoMore;


/**
 pull Down Trigger Title
 */
@property (nonatomic,copy) NSString * pullDownTriggerTitle;

/**
 pull Down Nomore Title
 */
@property (nonatomic,copy) NSString * pullDownNomoreTitle;

@property (nonatomic,copy) NSAttributedString * pullDownNomoreAttributedString;

/**
 pull Up Trigger Title
 */
@property (nonatomic,copy) NSString * pullUpTriggerTitle;

/**
 pull Up Nomore Title
 */
@property (nonatomic,copy) NSString * pullUpNomoreTitle;


@property (nonatomic,copy) NSAttributedString * pullUpNomoreAttributedString;

//pull down handler
- (void)setPullDownHandler:(void (^)(void))actionHandler;

//Pull Up Handler
- (void)setPullUpHandler:(void (^)(void))actionHandler;


/**
 refresh finish call this method 
 */
- (void)refreshFinished;

- (void)refreshUpFinish;
- (void)refreshDownFinish;

- (void)showUpLoading;

- (void)showDownLoading;

- (void)setPullUpNeedUI:(BOOL)needUI;
- (void)setPullDownNeedUI:(BOOL)needUI;

-(ZMScrollLoadingState)loadingState;

- (void)clearState;


@end


@interface ZMIMTrackingScrollView : ZMIMLoadingScrollView

@property (assign) NSInteger type;
@property (readonly, assign) NSInteger hoveredRow;

@property (nonatomic,copy) BOOL (^interceptKeyDownBlock)(NSEvent *);

//fullKeyboardAccessEnabled
@property (nonatomic,assign) BOOL focusRingExteriorKAS;

- (void)delayHoverRow:(NSInteger)row;
- (void)cleanUp;
- (void)updateHoverRow;
- (void)hoverRow:(NSInteger)row;
- (void)unhover;

@end

@interface ZMNestedScrollView : ZMIMTrackingScrollView

@end
