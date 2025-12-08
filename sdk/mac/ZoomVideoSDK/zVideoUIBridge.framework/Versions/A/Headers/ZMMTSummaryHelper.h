//
//  ZMMTSummaryHelper.h
//  VideoUIBridge
//
//  Created by Howie Xu on 3/7/23.
//

#import <zVideoUIBridge/ZMBaseHelper.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMIQMeetingPrompt;
@interface ZMMTSummaryHelper : ZMBaseHelper

- (BOOL)isSummaryEntranceEnabled;

- (BOOL)isSummryAutoStartEnabled;

- (BOOL)needShowSummaryEntrance;

- (BOOL)isSummaryEnabledButNotOnForAttendee;

- (BOOL)isAIEnableStrategyInMeeting;

- (BOOL)isAIEnableStrategyInWeb;

- (BOOL)isSmartSummaryFeatureOn;

- (BOOL)isSmartSummaryFreeTrial;

- (BOOL)isFreeAccountAvailable;

- (BOOL)showFreeTrialTip;

- (BOOL)showUpgradePlanTip;

- (void)startMeetingSummary:(BOOL)start;

- (BOOL)isMeetingSummaryStarted;

- (BOOL)requestToEnableSummary;

- (BOOL)requestToStartSummary;

- (BOOL)rspStartSummaryReq:(NSString *)reqId senderId:(ZMUserID)senderId decline:(BOOL)decline;

- (BOOL)enableSummary;

- (BOOL)disclaimerDoNotShow:(BOOL)notShow;

- (BOOL)recordReqChangeSummarySettingUser:(ZMUserID)reqUserId;

- (ZMIQMeetingPrompt *)getSummaryFirstIntroductionPrompt;

- (ZMIQMeetingPrompt *)getSummarySupportMultiLanguagePrompt;

- (ZMIQMeetingPrompt *)getAIEnablementStartPormpt;

- (NSString *)getSummarySettingUrl;

- (NSString *)getFreeTrialPolicyUrl;

@end

NS_ASSUME_NONNULL_END
