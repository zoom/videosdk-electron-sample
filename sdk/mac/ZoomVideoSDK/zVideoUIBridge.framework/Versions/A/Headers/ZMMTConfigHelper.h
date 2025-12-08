//
//  ZMMTConfigHelper.h
//  VideoUIBridge
//
//  Created by Francis Zhuo on 2/16/23.
//

#import <zVideoUIBridge/ZMBaseHelper.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTConfigHelper : ZMBaseHelper

@property (nonatomic, assign) BOOL hideChatPreview;
@property (nonatomic, assign) ZMMTVideoSortType videoOrderSortType;

//ZOOM-878575
@property (nonatomic, assign) BOOL makeAttendeeStandard;
@property (nonatomic, assign) BOOL showMainWindowWhenSharing;

//ZOOM-893925
@property (nonatomic, assign) BOOL floatOnTop;

// ZOOM-748429
@property (nonatomic, assign) BOOL isPreferShareContentOnlyMode;

@property (nonatomic, assign) NSInteger numberOfSubscribeVideo;
- (void)increaseNumberOfSubscribeVideo;
@property (nonatomic, assign) NSInteger numberOfFailSubscribeVideo;
- (void)increaseNumberOfFailSubscribeVideo;
@property (nonatomic, assign) NSInteger numberOfUnsubscribeVideo;
- (void)increaseNumberOfUnsubscribeVideo;
@end

NS_ASSUME_NONNULL_END
