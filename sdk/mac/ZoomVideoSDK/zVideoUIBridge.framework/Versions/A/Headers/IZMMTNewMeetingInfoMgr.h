//
//  IZMMTNewMeetingInfoMgr.h
//  VideoUI
//
//  Created by Carol.Li on 2024/4/22.
//  Copyright © 2024 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class ZMBuddyAdapter;
@protocol IZMMTNewMeetingInfoMgr <NSObject>

@property (nonatomic, assign) BOOL isFromViewBillingInfo;

- (void)openNewMeetingInfo;
- (void)closeNewMeetingInfo;
- (BOOL)isNewMeetingInfoShowing;
- (void)mergeToMeetingWindow;
- (BOOL)shouldShowMeetingDetailsOnToolbar;

- (void)onHandleJSBridgeGetMeetingInfo:(NSString *)jsCallId;
- (void)onHandleJSBridgeStartShareDoc:(NSString *)jsString jsCallId:(NSString *)jsCallId;
- (void)onHandleJSBridgeStartShareExistedWB:(NSString *)jsString jsCallId:(NSString *)jsCallId;
- (void)onHandleJSBridgeGetMeetingDetailShareAssetsStatus:(NSString *)jsCallId;
- (void)onHandleJSBridgeGetMeetingDetailUserSettings:(NSString *)jsCallId;
- (void)onHandleJSBridgeStartOrEndLiveNote:(NSString *)jsString jsCallId:(NSString *)jsCallId;
- (void)onHandleJSBridgeOpenLinkInDefaultBrowser:(NSString *)jsString jsCallId:(NSString *)jsCallId;
- (void)onHandleJSBridgeStartLiveSummary:(NSString *)jsString jsCallId:(NSString *)jsCallId;
- (void)onHandleJSBridgeJumpToAICSetting:(NSString *)jsString jsCallId:(NSString *)jsCallId;
- (void)onHandleJSBridgeRequestLiveSummary:(NSString *)jsString jsCallId:(NSString *)jsCallId;
- (void)onHandleJSBridgeCreateDocInMeeting:(NSString *)jsString;
- (void)onMeetingDetailGetMeetingDocsToken:(NSString *)jsCallId;
- (void)onGetMeetingDocsTokenBack:(NSString *)token;
- (void)onHandleJSBridgeCopyToClipboard:(NSString *)jsString jsCallId:(NSString *)jsCallId;
- (void)onHandleJSBridgGetMeetingDetailBillableHoursInfo:(NSString *)jsCallId;
- (void)onHandleJSBridgeGetMeetingDetailBillableHoursTime:(NSString *)jsCallId;
- (void)onBillableHoursTimeChanged;
- (void)onPatchBillableHoursInfo:(NSString *)jsString jsCallId:(NSString *)jsCallId;
- (void)onJudgeUserIsKnownContact:(NSString *)jsString jsCallId:(NSString *)jsCallId;
- (void)onHandleJSBridgeGetMeetingDetailParticipants:(NSString *)jsCallId;
- (void)onHandleJSBridgeGetMeetingSearchContact:(NSString *)jsString jsCallId:(NSString *)jsCallId;
- (void)onHandleJSBridgeOpenCreateContactPanel:(NSString *)jsString jsCallId:(NSString *)jsCallId;
- (void)onMeetingParticipantsChanged;
- (void)onMeetingDetailStartExistedWB:(NSDictionary *)dic;
- (void)onMeetingDetailStartShareDoc:(NSDictionary *)dic;
- (void)onMeetingDetailsSettingChanged;
- (void)onMeetingDetailsSettingChangedWithCancelLiveSummary:(BOOL)isCancelStartLiveSummary;

- (void)onMeetingDetailWBStatusStarted:(NSString *)docID;
- (void)onMeetingDetailWBStatusEnded:(NSString *)docID;
- (void)onMeetingDetailDocStatusStarted:(NSString *)docID;
- (void)onMeetingDetailDocStatusEnded:(NSString *)docID;


- (void)onSmartAgendaDocIdReceived:(NSString *)docId;
- (void)onLiveSummaryDocUpdated:(NSString *)docId;
- (void)onSummaryShareLevelChanged:(long long)newLevel;
- (void)onLiveSummarySettingChanged:(BOOL)isLiveSummaryEnabled;
- (void)onLiveSummaryStatusChanged;
- (void)onReceiveSwitchAICompanionWithLiveSummaryRequestMsg:(NSString *)reqId senderId:(ZMUserID)senderId aicOption:(long long)aicOption switchAction:(NSInteger)switchAction;
- (void)onReceiveSwitchAICompanionWithLiveSummaryResponseMsg:(long long)aicOption timeout:(BOOL)timeout agree:(BOOL)agree switchAction:(NSInteger)switchAction;

@end
NS_ASSUME_NONNULL_END
