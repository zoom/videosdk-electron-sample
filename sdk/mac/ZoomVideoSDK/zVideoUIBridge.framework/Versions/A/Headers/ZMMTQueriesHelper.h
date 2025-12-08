//
//  ZMMTQueriesHelper.h
//  VideoUIBridge
//
//  Created by Amanda Souriyamath on 6/29/23.
//

#import <zVideoUIBridge/ZMBaseHelper.h>
#import <zVideoUIBridge/ZMIQConstant.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMQuerySettingOptions;
@class ZMAIDynamicNotifier;
@class ZMIQMeetingPrompt;
@class ZMAICDialogInfo;
@interface ZMMTQueriesHelper : ZMBaseHelper

//ICmmConfContext:
-(BOOL)isAskAICompanionEnabled;
-(BOOL)isQueryEntranceEnabled;
-(BOOL)needShowQueriesEntrance;
- (BOOL)isQueryEnabledButNotOnForAttendee;
-(BOOL)isMeetingQueryFeatureOn;
-(BOOL)isStartAICWithCloudRecordingEnabled;
-(BOOL)isStartAICWithCloudRecordingLocked;
//-(BOOL)isZoomAIFeatureOn;
-(NSString*)getZoomAILearnMoreLink;
-(BOOL)needPromptQueryDisclaimer;

//ICmmConstaus:
-(BOOL)changeMeetingQueryStatus:(ZMQueriesStatus)newStatus;
-(ZMQueriesStatus)getMeetingQueryStatus;
-(BOOL)isMeetingQueriesStarted;

//ICmmWebAgentAPI:
-(BOOL)sendFeedbackOfQueryAnswer:(ZMQueriesFeedback)feedback withRequestId:(NSString*)requestId;

//ICmmConfInst(cmmconfmgr):
-(NSString*)sendQueryQuestionRequest:(NSString*)question;

//-(BOOL)needShowFirstTimeInDisclaimer;

-(BOOL)needShowTip;
-(void)setShownTip;

-(BOOL)isQueryFreeTrial;
-(BOOL)isQueryAutoStartEnabled;
-(void)agreeQueryDisclaimer:(BOOL)didAgree;

- (BOOL)requestToEnableQueries;
- (BOOL)requestToEnableAIC;
- (BOOL)requestToStartQueries;
- (BOOL)requestToChangeQueryPrivilegeSetting:(NSInteger)setting;
- (BOOL)canStartSummary;
- (BOOL)canStartQuery;
- (void)startAICFeature:(ZMMTAICFeatureType)featureType;
- (void)requestStartAicFeature:(ZMMTAICFeatureType)featureType;
- (void)requestStartAicFeatureWithLiveSummary:(ZMMTAICFeatureType)featureType;
-(BOOL)rspStartQueryReq:(NSString *)reqId senderId:(ZMUserID)senderId decline:(BOOL)decline;
- (BOOL)respondToChangeQueryPrivilegeSetting:(NSString *)reqId senderId:(ZMUserID)senderId decline:(BOOL)decline;
-(BOOL)recordReqChangeQuerySettingUser:(ZMUserID)reqUserId;
-(BOOL)trackReqEnableAICompanionUser:(ZMUserID)reqUserId aicOption:(long long)aicOption;
-(BOOL)turnMeetingQueriesFeatureOn;
-(BOOL)turnMeetingQueriesFeatureOff;
-(BOOL)disclaimerDoNotShow:(BOOL)notShow;
- (NSString *)getQuerySettingUrl;
- (NSString *)getEnableAICompanionSettingUrl;
- (BOOL)isQueryEnableStrategyInMeeting;
- (BOOL)isQueryEnableStrategyInWeb;


//2023.9.23 patch//
-(NSArray<ZMQuerySettingOptions*>*)getQuerySettingOptions;
-(ZMIQMeetingPrompt*)getAICompanionMultiLanguagesPrompt;
- (ZMAICDialogInfo *)getRequestAICompanionDialogInfo;
-(BOOL)canSendQuery;
-(BOOL)canSeeQuerySetting;
-(BOOL)canChangeQuerySetting;
-(BOOL)canShowCaretMenu;
-(BOOL)changeQuerySettingsTo:(NSUInteger)settingOptionId;
-(NSUInteger)getCurrentQuerySetting;
-(nullable ZMQuerySettingOptions*)getCurrentQuerySettingOption;
-(NSString*)getSettingChangedInfo;
-(ZMAIDynamicNotifier*)getAINotifier;
-(BOOL)isAICompanionNoticeActive;
-(BOOL)needShowAICPreviewTip;

- (BOOL)isAICFeaturesOn;
- (BOOL)isAICFeaturesOff;
- (BOOL)isAICFeaturesOffExceptSmartRecord;
- (BOOL)isAICFeaturesOnExceptSmartRecord;
- (BOOL)isSummaryOn;
- (BOOL)isQueryOn;
- (BOOL)isSmartRecordingOn;
- (BOOL)onlySmartRecordingOnAndForbidStop;
- (BOOL)turnOffAICompanionByHostCohost:(long long)aicOption deleteAssets:(BOOL)deleteAssets;
- (BOOL)turnOffAICompanionByAttendee:(long long)aicOption deleteAssets:(BOOL)deleteAssets;
- (BOOL)requestToSwitchAICompanion:(long long)aicOption switchAction:(NSInteger)switchAction;
- (BOOL)isAICompanionTurnOffFlowEnabled;
- (BOOL)isAICompanionTurnOnFlowEnabled;
- (void)agreeTurnOffAICompanionBeforeHostJoin:(long long)aicOption;
- (BOOL)isRequestAICompanionAllowed;
- (BOOL)setAllowAttendeeRequestAICompanion:(BOOL)allow;
- (BOOL)isAICompanionAssetsDeleted:(NSInteger)gatewayType;
- (BOOL)turnOnAllAICompanion;
- (BOOL)AICFeaturesCanTurnOff;
- (BOOL)reportMeetingActivityForTranscript:(NSString *)reqID activityType:(NSInteger)activityType;
- (void)sendReportMeetingActivityForTranscriptAway;
- (BOOL)sendReportMeetingActivityForTranscriptPollGen;

// ZOOM-935086
- (BOOL)isAICompanionActiveWarningNeedShow;
- (void)setAICompanionActiveWarningDontShow;
- (BOOL)hasStopAicPermission;
- (void)stopAllAicFeatures;

- (BOOL)respondToSwitchAICompanion:(NSString *)reqId senderId:(ZMUserID)senderId switchAction:(NSInteger)switchAction agree:(BOOL)agree;

#pragma mark - AIC Free Trial
- (BOOL)isAICFreeTrialAvaiable;
@end

NS_ASSUME_NONNULL_END
