//
//  ZMTimer.h
//  SaasBeeConfUIModule
//
//  Created by francis on 2/13/17.
//  Copyright © 2017 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern ZMTimerName kZMTimerPlistVoipAudioFlash;
extern ZMTimerName kZMTimerPlistTeleAudioFlash;
extern ZMTimerName kZMTimerPlistRecordFlash;
extern ZMTimerName kZMTimerPlistMuteTipView;
extern ZMTimerName kZMTimerPlistSortPanelist;
extern ZMTimerName kZMTimerPlistSortPanelistAudioStatusChange;
extern ZMTimerName kZMTimerPlistUpdateAttendee;
extern ZMTimerName kZMTimerPlistSortActiveChanded;
extern ZMTimerName kZMTimerConfClockTime;
#ifdef ENABLE_ZAPP
extern ZMTimerName kZMTimerConfAppClockTime;
#endif
extern ZMTimerName kZMTimerToolbarHandTipView;
extern ZMTimerName kZMTimerMainUIAttedeeVideoLayout;
extern ZMTimerName kZMTimerMonitorMemoryDisk;
extern ZMTimerName kZMTimerWallViewTopCountChanged;
extern ZMTimerName kZMTimerDynamicViewTopCountChanged;
extern ZMTimerName kZMTimerPushToTalk;
extern ZMTimerName kZMTimerCheckCoreAudio;
extern ZMTimerName kZMTimerFitbarAudioFlash;
extern ZMTimerName kZMTimerChatRotate;
extern ZMTimerName kZMTimerNewSimulive;
extern ZMTimerName kZMTimerTrackBilling;

@interface ZMTimerMgr : ZMTimer
+ (nullable instancetype)shareTimer_0_01;
+ (nullable instancetype)shareTimer_0_1;
+ (nullable instancetype)shareTimer_1_0;
+ (void)removeTimerWithTarget:(id)target;
@end

NS_ASSUME_NONNULL_END
