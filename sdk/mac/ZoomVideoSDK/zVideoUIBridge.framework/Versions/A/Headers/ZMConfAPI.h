//
//  ZMConfAPI.h
//  SaasBeeConfUIModule
//
//  Created by javenlee.li on 2021/7/23.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMBaseHelper.h>
#import <ZoomUnit/ZoomUnit.h>
#import <ZoomKit/ZoomKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMConfAPI : ZMBaseHelper

//ZOOM-13936
- (BOOL)isSelectAuduioDeviceDone;
- (void)setSelectAuduioDeviceDone;
//ZOOM-13934
- (BOOL)isConnectVOIPTIPDone;
- (void)setConnectVOIPTIPDone;
- (void)requestToRebootAndJoin;

- (int)getMaxMeetingParticipantCount;

- (BOOL)isSettingValueExistForKey:(NSString*)key;
- (BOOL)getBoolSettingValueForKey:(NSString*)key;
- (void)setSettingBoolValueForKey:(NSString*)key value:(BOOL)isYes;
- (BOOL)getIntSettingValueForKey:(NSString*)inKey value:(int*)outValue;
- (void)setSettingIntValueForKey:(NSString*)key value:(int)inValue;
- (BOOL)getStringSettingValueForKey:(NSString*)inKey value:(NSString *_Nonnull *_Nonnull)outValue;
- (void)setSettingStringValueForKey:(NSString*)inKey value:(NSString*)inValue;

- (void)logClientAction:(NSString*)uicontainer action:(NSString*)action param:(NSString*)param;

- (BOOL)isAccEventOptionOn:(NSInteger)eventId;//ZOOM-19946;

- (BOOL)needShowAttendeeNumber;

- (BOOL)isPTLogin;
- (BOOL)isPTLogined;//common api
- (BOOL)retrievePTLoginStatus;
- (nullable NSString *)getPTLoginJid;

- (BOOL)isFreewayUserIndex:(int)userID;
- (BOOL)isUserOriginalOrAltHostByJID:(NSString*)inJID;
- (BOOL)isUserOriginalHostByJID:(NSString*)inJID;
- (BOOL)isSelfOriginalHost;
- (BOOL)hasHostInMeeting;

- (BOOL)isSupportInvite;//ZOOM-167535
- (BOOL)isInDebriefSession;

- (nullable NSString*)getBackstageWebinarStartTime;
- (nullable NSString*)getSimuliveBackStageWebinarStartTime;

- (BOOL)isAllowParticipantRenameEnabled;//ZOOM-68095
- (BOOL)isAllowParticipantRenameLocked;
- (BOOL)isAllowParticipantRename;//ZOOM-68095
- (void)setAllowParticipantRename:(BOOL)allow;//ZOOM-68095
- (BOOL)isHostRenameWaitingRoomAttendeesEnabled;

- (BOOL)isAllowAttendeeRaiseHand;//ZOOM-15291
- (BOOL)isAttendeeVideoControlFollow;//ZOOM-15291
- (BOOL)isAttendeeVideoControlSideBySide;//ZOOM-248971
- (BOOL)isAttendeeVideoControlActive;//ZOOM-15291
- (BOOL)isAttendeeVideoControlWall;//ZOOM-15291
- (BOOL)isHostSupportSharedContentOnly;

@property(assign) BOOL isAvatarAllowed;

- (BOOL)isLegalConfNumber:(NSString*)confNumber;
- (nullable NSString*)getJoinMeetingURL;
- (nullable NSString*)getCopyJoinMeetingURLWithString:(NSString *)passwordString;
- (nullable NSString*)getPhoneCallInNumber;
- (nullable NSString*)getTollFreeNumber;
- (int)getMeetingDuration;
- (nullable NSString*)getFreeUserMeetingDurationLimit;
- (nullable NSString*)getZoomDomain;
- (nullable NSString*)getProductDomain;
- (nullable NSString*)getLoginHostName;
- (nullable NSString*)getMeetingPassword;
- (nullable NSString*)getRawMeetingPassword;
- (nullable NSString*)getH323Password;
- (nullable NSString*)getMeetingTopic;
- (void)setMeetingTopic:(NSString*)topic;
- (nullable NSString*)getMeetingHostName;
- (NSTimeInterval)getMeetingStartTime;
- (nullable NSURL*)getWebinarRegisterURL;
- (int)getFECCContinueIntervalInMS;
- (uint8_t)getAttendeeChatPriviledge;    //ZOOM-65890

- (BOOL)isSpotlightVideoByUserId:(int)inUserId;
- (void)spotlightUserById:(int)inUserId shouldSpotlight:(BOOL)inShouldSpotlight;

- (BOOL)hasEnoughPerformanceForWallView;
- (BOOL)hasEnoughPerformanceForDualMonitor;
- (BOOL)hasEnoughPerformanceForVirtualBackground;
- (BOOL)isEnabledDualMonitorMode;
- (BOOL)isAutoFullscreenWhenStartingConferenceVideo;

- (BOOL)isAutoFullscreenWhenViewShare;
- (void)setAutoFullscreenWhenViewShare:(BOOL)on;
- (BOOL)isAutoMaxWindowWhenViewShare;
- (void)setAutoMaxWindowWhenViewShare:(BOOL)on;

- (BOOL)isAutoFit2Window4ViewingSharing;
- (BOOL)isConfirmWhenLeave;
- (BOOL)isAutoStartShare;
- (BOOL)shouldShowVideoUIDirectlyBeforeMeetingReady;
- (BOOL)isPrivateChatOff;
- (BOOL)isFeedbackOff;
- (BOOL)isMeetingSupportSilentMode;
- (BOOL)isAlwaysShowUserName;
- (BOOL)isAble2HideSystemCursor;
- (BOOL)amISpotlightSelf;
- (BOOL)isFileTransferEnabled;
- (BOOL)canSaveChat;
- (BOOL)isChatCopyEnabled;   //ZOOM-68845
- (BOOL)isPaidMeeting;//ZOOM-35970
- (BOOL)isEnablePushToTalk;//ZOOM-542
- (BOOL)isAllowUserRejoinAfterRemove;
- (BOOL)needPromptGuestParticipantLoginWhenJoin;
- (BOOL)isRemoteAdminExisting;//ZOOM-113382
- (BOOL)isAssistantAdminExisting;//ZOOM-255798
- (BOOL)isMMRSupportWaitingRoomMsg;//ZOOM-46301
- (BOOL)canMutedWhenScreenLocked;//ZOOM-136057
- (BOOL)isLeaveAssignNewHostEnabled;

//ZOOM-115938
- (BOOL)isBindTelephoneUserEnable;
- (BOOL)isUnbindTelephoneUserEnable;

- (BOOL)isSupportLivestreamToZoomEventLobby;
- (nonnull NSString *)getZoomEventsLivestreamLabel;

- (int)getViewOnlyUserCount;
- (int)getViewOnlyTelephoneUserCount;
- (int)getPracticeSessionUserCount;

// ZOOM-360254
- (BOOL)isMoreFeaturesAvailable;
- (void)setAgreeJoinSDKMeeting:(BOOL)agree;
- (BOOL)isJoinSDKMeeting;
- (BOOL)isSDKMeetingDisableMakeHostOrCohost;
- (BOOL)isSDKMeetingDisableHostLeave;
- (nullable NSString *)sdkMeetingFeatureUrl;
- (nullable NSString *)sdkMeetingLeaveUrl;
- (nullable NSString *)sdkMeetingLogoPathForDarkMode:(BOOL)darkMode;
- (nullable NSString *)gatewayName;
- (BOOL)isFirstTimeUseMoreFeatures;
- (void)setNotFirstTimeUseMoreFeatures;

- (float)getTitleBarHeightWithStyleMask:(int)inStyleMask;

//ZOOM-4026 Attention Track
- (BOOL)isEnableWebAttentionTrack;
- (BOOL)isEnableConfAttentionTrack;

- (BOOL)isWaitingOnEntryLocked;//ZOOM-147468
- (BOOL)isMasterConfSupportWaitingOnEntry;//ZOOM-224693
- (BOOL)isWaitingOnEntry;//ZOOM-147468

- (BOOL)isWallViewEnable180P;

- (NSInteger)freeGroupMeetingCount;//ZOOM-41323
- (BOOL)isMeetingUpgradedFromSip;
- (NSUInteger)getMeetingElapsedTime;

- (BOOL)isRequireEncryptionFor3rdEndpotins; // ZOOM-97072

- (BOOL)isAutoShowJoinAudioDialogEnabled;//ZOOM-76554
- (BOOL)isWebJoinFromTestMeeting;

- (BOOL)needShowBandWidthLimit; // this one is for disclaimer
- (BOOL)isEnableBandWidthLimit;//ZOOM-82229
- (BOOL)needShowBandwidthLimitIcon; // ZOOM-638677, for the topbar icon
- (BOOL)isBandWidthLimitSendVideo;//ZOOM-82229
- (BOOL)isBandWidthLimitReceiveVideo;//ZOOM-82229

- (NSString *)getMeetingID;
- (NSString *)getAccountID;
- (BOOL)isPrivateModeMeeting;
- (nullable NSString *)getConfDCRegionForMeeting:(BOOL)forMeeting;
- (nullable NSString *)getEventDetailLink;//ZOOM-167535
- (NSString *)getPTUserID;

- (BOOL)needPromotePotentialSecurityIssueDialog:(NSString *)messageId needShowCheck:(BOOL *)needShow;
- (void)setAlwaysTrustFileSender:(NSInteger)senderId alwaysTrust:(BOOL)alwaysTrust;

- (NSInteger)getConfStatus;//CONF_STATUS

- (BOOL)isE2EMeetingPQCProtected;
- (nullable NSString *)getE2EELearnMoreLink;
- (nullable NSString *)getMeetingArchiveLearnMoreLink;
- (BOOL)needPromptViewBOActDisclaimer;
- (void)agreeViewBOActDisclaimer;
- (void)disagreeViewBOActDisclaimer:(BOOL)bLeaveMeeting;
- (BOOL)canShowPollingDownloadLink;//ZOOM-199234

- (BOOL)isLiveUnencrypted;

- (NSInteger)getMeshUnSignedParticipantsCount;  // ZOOM-421787
- (BOOL)hasMeshUnSignedParticipants;                 // ZOOM-421787
- (BOOL)needHideMeetingNumber;//ZOOM-193452
- (BOOL)needHideMeetingPasscode;//ZOOM-193452
- (BOOL)isMyDlpEnabled;
- (NSInteger)checkDlpWithContent:(NSString *)content receiver:(NSString *)receiver policyName:(NSString *_Nullable *_Nullable)policyName;

//ZOOM-206956
- (BOOL)isImmersiveMode;
- (BOOL)isImmersiveModeEnabled;

//ZOOM-271443
- (BOOL)isFocusModeEnabled;
- (BOOL)isFocusModeEnding;
- (BOOL)isFocusModeOn;
- (BOOL)isVideoFocusModeOn;

- (BOOL)isShowClockEnabled;

//ZOOM-298093
- (BOOL)isGalleryVideoOrderEnabled;
- (BOOL)isGalleryVideoOrderSaved;

@property (nonatomic, assign, readonly) BOOL isCloudWhiteboardEnabled;
@property (nonatomic, assign, readonly) BOOL isCloudWhiteboardWebEnabled;
@property (nonatomic, assign, readonly) BOOL isWhiteboardOwnershipEnabled;
@property (nonatomic, assign, readonly) BOOL canNewWhiteboard;

- (void)enableWhiteboardStreamForRecording:(BOOL)bRecordWhiteboard;

//ZOOM-296843
- (BOOL)isWebinarContentOnlyEnabled;

// ZOOM-790004
- (BOOL)isSharedContentOnlyEnabled;

// ZOOM-796063
- (BOOL)isNewMeetingTabUIEnabled;

- (BOOL)isPollingLegalNoticeAvailable;
- (BOOL)isQALegalNoticeAvailable;
- (nullable NSString*)getRegisterAccountOwnerLink;
- (nullable NSString*)getRegisterTermsLink;
- (nullable NSString*)getRegisterPrivacyPolicyLink;
- (BOOL)isMeetingArchivingDisclaimerAvailable;
- (void)getMeetingArchivingDisclaimerWithTitle:(NSString *_Nonnull *_Nonnull)title
                                   description:(NSString *_Nonnull *_Nonnull)description
                                    linkString:(NSString *_Nonnull *_Nonnull)linkString
                                       linkUrl:(NSString *_Nonnull *_Nonnull)linkUrl;
- (nullable NSString *)getArchiveOwnerLink;
- (BOOL)isZappServiceEnabled;

- (BOOL)isAllowPanelistSendFileViaWebinarChatEnabled;
//ZOOM-273485
- (BOOL)isShareMyPronounEnabled;
- (BOOL)isEventDirectMeeting;

- (BOOL)isDisplayWebinarChatSettingEnabled;
- (void)changePanelistChatPriviledge:(NSInteger)priviledge;
- (NSInteger)getPanelistChatDefaultPrivilege;
- (NSInteger)getAttendeeDefaultChatTo;
- (NSInteger)getSaveChatPrivilege;
- (BOOL)isSupportAdvancedPollEnabled;
- (BOOL)supportWaitingRoomChat;
- (BOOL)shouldShowMeetingChatAvatar;

- (nullable NSString *)getUnlimitedMeetingNoticeTitleForThird30Min;
- (nullable NSString *)getUnlimitedMeetingNoticeDescriptionForThird30Min;
- (nullable NSString *)getUnlimitedMeetingNoticeButtonForThird30Min;
- (nullable NSString *)getUnlimitedMeetingNoticeUrlForThird30Min;
- (nullable NSString *)getUnlimitedMeetingNoticeIDForThird30Min;

- (nullable NSArray<NSString*>*)getExecuteFileBlacklist;

+ (BOOL)sendMessageToPT:(ZMIPCMessage*)message;

- (BOOL)IsMultiJoinSubProcess;

-(void)setClientLangId;
#ifdef __cplusplus
- (NS_ZOOM_DATA::UnLimitedMeetingNoticeInfo)getUnLimitedMeetingNoticeInfoWithIsPost:(BOOL)isPost;
#endif

//Psl coBrand featurtoggle
- (BOOL)isCoBrandEnable;
- (NSImage * _Nullable)getLightCobrandingDialogLogo;
- (NSImage * _Nullable)getDarkCobrandingDialogLogo;

// Deeplink
- (BOOL)chechIfZoomInternalNavigateURL:(NSURL *)url;
- (BOOL)handleZoomInternalNavigateURLAction:(NSString *)url;
- (BOOL)checkAndHandleZoomInternalNavigateURLAction:(NSURL *)url;
@end

NS_ASSUME_NONNULL_END
