//
//  ZPConfHelper.h
//  VideoUIBridge
//
//  Created by geno.chen on 2022/7/8.
//

#import <zVideoUIBridge/ZMConfAPI.h>
#import <zVideoUIBridge/ZMUIConstants.h>
#import <ZoomUnit/ZMGalleryPlusConstants.h>
#import <ZoomUnit/ZMPersonalWallpaperConfigModel.h>
#import <ZoomUnit/ZMGalleryPlusWallpaperModel.h>
#ifdef __cplusplus
#import <zm_conf_universal_ui/zm_conf_universal_ui_api.h>
#import <zm_conf_universal_ui/zm_conf_universal_ui_online_business_interface.h>
#import <zm_conf_universal_ui/zm_conf_uui_watermark_interface.h>
#endif

NS_ASSUME_NONNULL_BEGIN

#define ZMMonitor(confSession,eventType,format,...) ([confSession.zpConfHelper writeMonitorLog:(eventType) content:[NSString stringWithFormat:(format),##__VA_ARGS__]])

//ZOOM Client Version define
typedef NSString* ZCV NS_EXTENSIBLE_STRING_ENUM;
extern ZCV const ZCV6_3_0;
extern ZCV const ZCV6_4_0;
extern ZCV const ZCV6_4_10;
extern ZCV const ZCV6_5_10;
extern ZCV const ZCV6_6_0;
extern ZCV const ZCV6_6_10;

@class ZMUser;

@interface ZPConfHelper : ZMConfAPI

+ (ZPConfHelper*)sharedConfHelper;

- (int)getUserCount;
- (int)getPanelistUserCount;
- (int)getUserCountWithoutOnHold;

- (BOOL)isSameUser:(ZMUserID)user1 compareTo:(ZMUserID)user2;
- (BOOL)isMyUserID:(ZMUserID)userID;
- (ZMUserID)getMyUserID;
- (long long)getMyAttendeeID;
- (nullable NSString*)getMyDisplayName;
- (nullable NSString*)getZoomIdByUserId:(ZMUserID)inUserId;
- (nullable NSString*)getMeetingNumber;
- (nullable NSString*)getMeetingToken;
- (NSString*)getFormattedMeetingNumber;
- (nullable NSString *)getLocalMeetingNumber;
- (nullable NSString *)getHostJoinZak;
- (nullable NSString *)getZoomSessionId;
- (nullable NSString*)getUserNameByID:(int)userID;

- (BOOL)isWebinar;
- (BOOL)isSimuliveWebinar;
- (BOOL)isInSimuliveMode;
- (BOOL)isSimuliveEnablePracticeSession;
- (BOOL)isAllowSimuliveGoLive;
- (BOOL)startLiveSession;
- (BOOL)isNewSimuliveEnabled;
- (NSUInteger)getSimuliveRemainingTime;
- (BOOL)isViewOnly;

- (BOOL)isShowNoVideoUser;
- (BOOL)isMandatoryShowNoVideoUser;
- (BOOL)isShowMySelfVideo;
- (BOOL)isMandatoryShowMySelfVideo;
- (BOOL)isNoVideoMeeting;
- (BOOL)isStopIncomingVideo;

- (BOOL)isMeetingKeepOnTopEnabled; //ZOOM-893925
- (BOOL)isMeetingKeepOnTopMandatory;

- (BOOL)isFilterTWEmojiEnabled;
- (BOOL)isUserPicDownloaded:(int)inUserID;

- (BOOL)isLeadMode;



- (BOOL)isShareOnlyMeeting;
- (BOOL)isNoOneSendingVideo;
- (BOOL)isNoOneSendingDeviceVideo;
- (BOOL)isDirectShareClient;
- (BOOL)isDirectShareClientPresentRoom;

- (BOOL)isUserSupportRemoteControlWithUserId:(int)inUserId;
- (void)sendRemoteSupportResponse:(ZMUserID)inUserId type:(int)type bApproved:(BOOL)bApproved;
- (BOOL)sendRemoteSupportRequest:(ZMUserID)inUserId type:(int)type;
- (BOOL)isRemoteController;

- (BOOL)canUserRecordById:(int)inUserId;
- (BOOL)isUserRaiseHandById:(int)inUserId;

- (BOOL)isChatOff;
- (BOOL)isMeetingLocked;
- (BOOL)isInSilentMode;
- (BOOL)isMasterConfSupportSilentMode;
- (BOOL)isSupportWaitingOnEntry;
- (BOOL)isSupportEditAvatar;//ZOOM-167535
- (BOOL)isSupportUnmuteAudioPrivacy;//ZOOM-169862

#pragma mark - invitee list
- (BOOL)canShowInviteeListMenu;
- (void)setCurrentInviteeListCount:(NSInteger)count;
- (BOOL)canShowInviteeList;
/// Return true if allowed to show invitee never joined.
- (BOOL)shouldShowInviteeList;
- (BOOL)isProactiveActionRecapMeetingEnabled;
- (BOOL)isMeetingBillableHoursEnabled;
- (BOOL)isAutoTrackMeetingBillableHoursEnabled;
- (BOOL)isAudioSessionOff;
- (BOOL)isDisableAudioForInSipCall;//zoom-14478 sip
- (BOOL)isTurnoffComputerAudioInSipCall;//zoom-14478 ZOOM-20377 sip
- (BOOL)isFailoverJoin;
- (BOOL)isCurrentConferenceAudioOn;
- (BOOL)isUserAudioMuted:(int)userID;
- (int)getUserAudioType:(int)userID;

- (BOOL)amIHost;
- (BOOL)amICoHost;
- (BOOL)isMyRosterCompleted;

- (void)writeMonitorLog:(NSString*)inEventType content:(NSString*)inEventContent;

//ZOOM-309128 watermark
- (nullable NSString*)getConfidentialWaterMarker;
- (ZMConfWaterMarkCoverType)getWaterMarkCoverType;
- (ZMConfWaterMarkPosition)getWaterMarkPosition;
- (ZMConfWaterMarkVisibleOnType)getWaterMarkerVisibleOnType;
- (CGFloat)getWaterMarkerOpacityLevel;
- (BOOL)canSwitchWatermark;
- (BOOL)isConfidentialWatermarkOn;
- (void)setConfidentialWatermarkOn:(BOOL)turnOn;
- (BOOL)isVideoWatermarkEnabled;
- (void)setVideoWatermarkEnabled:(BOOL)enabled;
- (BOOL)isShareWatermarkEnabled;
- (void)setShareWatermarkEnabled:(BOOL)enabled;
#ifdef __cplusplus
- (std::map<NS_ZM_CONF_UNIVERSAL_UI::WatermarkMenuModelType, NS_ZM_CONF_UNIVERSAL_UI::WatermarkMenuModel>)getWatermarkMenuModels;
- (NS_ZM_CONF_UNIVERSAL_UI::WatermarkMenuModel)getWatermarkShareOptionModel;
#endif
- (BOOL)canEditWatermarkShareOption;
- (BOOL)isShareWatermarkEnabledWithSourceId:(ZMShareSourceID)sourceId;
- (BOOL)isConfidentialWaterMarkerLocked;
- (BOOL)isMMRSupportSplitWatermark;

- (BOOL)isTspEnabled;
- (nullable NSString*)getTspMergeCode;
- (BOOL)isNotSupportTelephony;
- (NSString*)getTelephoneBindingCode;//ZOOM-131003
- (NSString*)getTelephoneBindingParticipantCode;

- (nullable NSString*)getActiveSpeackName;
- (nullable ZMUser*)getActiveVideoUser;
- (nullable ZMUser*)getRealActiveVideoUser;
- (nullable ZMUser*)getActiveSpeakerUser;

- (BOOL)isAudioWatermarkEnabled;
- (BOOL)isE2EEncMeeting;
- (BOOL)isInstantMeeting;
- (BOOL)isFace2FaceMeeting;

- (BOOL)isAudioForceDisabled;//ZOOM-54743
- (BOOL)isAllowMessageAndFeedbackNotify;// ZOOM-82083
- (BOOL)isMessageAndFeedbackNotifyEnabled;// ZOOM-82083

- (BOOL)canSendMyVideo;//ZOOM-82229
- (BOOL)canReceiveVideo;//ZOOM-82229

- (int)getConfEncryptionType;//ZOOM-155247

- (BOOL)isAudioChannelForPrivateGroupShareEnabled;

- (BOOL)isReportIssueEnable;//ZOOM-150227
- (BOOL)isParticipantReportIssueEnable;//ZOOM-200525
- (BOOL)canIReportIssue;//ZOOM-200525
- (BOOL)isSuspendMeetingEnable;//ZOOM-200525

- (BOOL)isGovEnvironment;//ZOOM-151325
- (BOOL)isGovMilEnvironment; // ZOOM-715018

// top bar or share fit bar should show MIL/GOV icon or not
- (BOOL)shouldShowMilIcon;
- (BOOL)shouldShowGovIcon;

- (BOOL)hasLiveOnStream;

#pragma mark - meeting/webinar capacity
- (BOOL)isLiveStreamReminderOnWhenReachedCapacity;
- (void)setLiveStreamReminderWhenReachedCapacity:(BOOL)isOn;
- (BOOL)isLiveStreamReminderEnableWhenReachedCapacity;
- (BOOL)isLiveStreamReminderLockedWhenReachedCapacity;
- (int)getLiveStreamCapacityPromptThreshold;
- (int)getParticpantCountLimitation;
- (int)getViewOnlyCountLimitation;

- (BOOL)isNewLiveStreamIndicatorStringPrefixEnabled;

- (NSString*)getGiftUpgradeUrl;

- (BOOL)isNoOneInMeeting;
- (BOOL)isPracticeSessionFeatureOn;
- (BOOL)isPracticeSession;
- (BOOL)isDisplayPracticeSessionUserCountsEnabled;

- (BOOL)needPromptGreenRoomGuide;
- (void)increaseGreenRoomGuidePromptCount;

- (BOOL)isBrandingMeeting;
- (nullable NSString *)getBacksplashPath;
- (BOOL)canShowSessionBrandingBacksplash;

- (nullable ZMPersonalWallpaperConfigModel *)getPersonalWallpaperConfig;
- (BOOL)startDownloadPersonalWallpaper:(NSString *)wallpaperID;
- (nullable ZMGalleryPlusWallpaperModel *)getPersonalWallpaperById:(NSString *)wallpaperID;

- (BOOL)isShowUserAvatarDisable;
- (BOOL)isTWEmojiLibraryEnabled;
- (BOOL)isChangeMeetingTopicEnabled;
- (BOOL)canIChangeMeetingTopic;
- (BOOL)isHostChatToWaitingRoomDisabled;
- (BOOL)isChatDLPEnabled;
- (BOOL)isViewBOActivityEnabled;
- (BOOL)isSameAccountWithHost;

- (BOOL)doesCurrentMeetingSupportLivestreamToZoomEventLobby;
- (BOOL)isRecurringExceptNoFixTime;
- (BOOL)isRecurringNoFixTimeMeeting;
///return WAITINGROOM_USER_SORT_METHOD
- (NSInteger)waitingRoomUserSortMethod;//ZOOM-350340

- (BOOL)isMMRSupportSubscribeVirtualUser;

- (BOOL)isMeetingVCardEnabled;
- (BOOL)isMoreCustomInterpreteLanEnabled;//ZOOM-366210

- (BOOL)shouldToolbarAlwaysBeShowing; // Implemented by category

- (int)getLeaveReason;//return CmmLeaveReason

- (BOOL)isTeamChatEnabled;

- (BOOL)needPromptZoomPhoneACRDisclaimer;
- (BOOL)isZoomPhoneACRInProgress;

- (BOOL)isUnencryptedDataPromptEnabled;
- (BOOL)hasUnencryptedData;
- (NSInteger)getUnencryptedExceptionCount;
#ifdef __cplusplus
- (BOOL)isFirstTimeUseWithFlag:(FirstTimeFlag)flag;
- (void)setNotFirstTimeUseWithFlag:(FirstTimeFlag)flag;
+ (BOOL)isFirstTimeUse:(FirstTimeFlag)flag withMin:(ZCV)minVersion max:(ZCV)maxVersion;
#endif

- (BOOL)isRaiseHandImprovementsAvaiable;

- (BOOL)needPromptSmartSummaryDisclaimer;
- (BOOL)isDeleteAICompanionAssetsNeedHide;

//[ZOOM-458717] Proctoring Mode
- (BOOL)isEnableProctoringMode;
- (BOOL)isInProctoringMode;
- (BOOL)stopProctoringMode;
- (BOOL)isSharingInProctroingMode:(ZMUser *)inUser;
#ifdef __cplusplus
- (BOOL)setProctoringModeContext:(CmmProctoringModeContext)modeContext;
- (CmmProctoringModeContext)getProctoringModeContext;
#endif

// ZOOM-618553
- (BOOL)isSimplifyConsentNoticeEnabled;
- (BOOL)isNewRecordDisclaimerEnabled;
- (BOOL)isCustomizedDisclaimerByType:(ZMMTDisclaimerType)type;
// ZOOM-722366
- (BOOL)allowUserHideFeatureDisclaimer;
- (BOOL)isDontAskAgainCheckedByDisclaimerType:(ZMMTDisclaimerType)type;
- (BOOL)setDontAskAgainCheckedByDisclaimerSet:(NSInteger)disclaimerSet value:(BOOL)value;

- (void)agreeLiveStreamDisclaimer:(BOOL)bAgree;
- (void)agreeSmartSummaryDisclaimer:(BOOL)bAgree;

- (void)logUIWindowSize:(NSSize)meetingWindowSize activeSize:(NSSize)activeSize;

// ZOOM-1001627
- (BOOL)removeMyWatchOnlyMode;
- (BOOL)hasAicRegulatedUserInMeeting;
- (BOOL)isAicOutOfComplianceNotifyOnlyEnabled;
- (BOOL)isAicOutOfComplianceNotifyAndDisableEnabled;

//[ZOOM-528112] BasicPlus
- (BOOL)isBasicPlusHostEnabled;
- (BOOL)isBasicPlusMeetingEnabled;
- (BOOL)isMeetingAlreadyExtend;
- (BOOL)requestExtendMeeting;
- (BOOL)cancelExtendMeeting;
- (NSInteger)getExtendMeetingRemainTimeInSecs;
- (NSInteger)getMeetingElapsedTimeInSecs:(BOOL)bLocal whole:(BOOL)whole;
- (NSInteger)getFreeMeetingElapsedTimeInSecs;
- (BOOL)isFirstTimeUseExtendMeeting;
- (void)setNotFirstTimeUseExtendMeeting;
- (NSInteger)getFreeMeetingLimitMeetingDurationMins;
- (NSInteger)getBasicPlusExtendedMeetingDurationMins;
- (BOOL)isInExtendMeeting;

// Companion Mode
- (BOOL)isInCompanionMode;
- (BOOL)isInAudioCompanionMode;
- (BOOL)isInVideoCompanionMode;//ZOOM-82110
- (BOOL)isSwitchCompanionModeEnabled;
- (BOOL)isJoinZEWithCompanionMode;
- (BOOL)isJoinZRWithCompanionMode;
- (BOOL)enterCompanionMode;
- (BOOL)leaveCompanionMode;
- (BOOL)leaveCompanionModeWithVideoOff;
- (BOOL)leaveImprovedCompanionMode;
- (BOOL)isInZECompanionMode;
- (BOOL)isJoinWithImprovedCompanionMode;
- (BOOL)isInImprovedCompanionMode;

// ZOOM-706990 ZE invite
- (BOOL)isOnZoomMeeting;
- (BOOL)isInviteInZoomEventAvailable;

//[ZOOM-565401] ppm
- (BOOL)isPPMeetingCreditEnabled;
- (NSInteger)getPPMFreeMeetingMins;
- (void)setNotFirstTimeUsePPM;
- (BOOL)isFirstTimeUsePPM;
- (BOOL)isInPPMeeting;

//[ZOOM-634357]
- (BOOL)isToolbarPinEnabled;
- (BOOL)isToolbarSimplificationEnabled;
- (BOOL)canPersonalizeToolbar;
- (BOOL)storeToolbarOrder:(NSArray<NSString *> *)orderArray;
- (NSArray<NSString *> *)getToobarOrderArray;
- (NSArray<NSString *> *)getDefaultToobarOrderArray;

#pragma mark - vcard
- (nullable NSString*)getMyProfileJID;
- (nullable NSString*)getProfileCardURL;
- (nullable NSString *)getMyXmppDomain;

- (BOOL)loginToJoinMeeting;
- (BOOL)isConfUserLogin;
- (void)agreeInternalMMRModeGuestJoinDisclaimer:(BOOL)agree;
- (void)agreeMeetingConnectorGuestJoinDisclaimer:(BOOL)agree;

- (BOOL)isPutAllIntoWaitingRoomWhenLeaveEnabled;
- (BOOL)isHostLeavedAndAutoAssignWR;

- (void)requestPoppingUpConfTipName:(nullable NSString*)name message:(NSString*)message type:(NSInteger)type FBID:(nullable NSString*)fbID;

#pragma mark - Gallery Plus
- (BOOL)isGalleryPlusWallpaperEnabled;
- (BOOL)isPersonalWallpaperEnabled;
- (BOOL)isHostSetGalleryPlusWallpaperEnabled;
- (BOOL)hasGalleryPlusWallpaperAttr;
- (nullable NSString *)getGalleryPlusWallpaper;
- (BOOL)setGalleryPlusWallpaper:(NSString *)wallpaperID;
- (NSInteger)getGalleryPlusTransparency;
- (BOOL)setGalleryPlusTransparency:(NSInteger)transparency;
- (ZMWallpaperContentMode)getGalleryPlusLayoutMode;
- (BOOL)setGalleryPlusLayoutMode:(ZMWallpaperContentMode)layoutMode;

#pragma mark - Dynamic Layout
- (BOOL)isDynamicLayoutEnabled;

//ZOOM-664241
- (NSInteger)getRSGWVolume;
#pragma mark Media Stream
- (BOOL)isZoomStreamingServiceEnabled;
- (BOOL)isZoomStreamingServiceActiveInMeeting;

#pragma mark - Clinical Note
- (BOOL)isClinicalNoteEnabled;

- (BOOL)isSurvivabilityModeEnabled;//ZOOM-753652
- (NSString*)getSurvivabilityModeLearnMoreLink;//ZOOM-753652

#ifdef __cplusplus
- (BOOL)getMeetingAssetsInfo:(MeetingAssetsInfo &)info;
- (BOOL)getMeetingInviteesInfoForPostMeeting:(MeetingInviteesInfo&)info;
#endif

#pragma mark - F2F Voice Recording
- (BOOL)enableDeleteF2FMeetingAsserts;
- (BOOL)deleteF2FMeetingAssets;
- (void)endAndDeleteF2FMeeting;
- (void)disassocateEventForF2F;

- (BOOL)isParticipantsScreenCaptureAllowed;
- (BOOL)isParticipantsScreenCaptureFeatureSupport;
- (BOOL)isParticipantsScreenCaptureLocked;
- (void)toggleParticipantsScreenCaptureEnabled;

// ZOOM-799004
- (BOOL)isAttendeeVideoControlShareContentOnly;
- (BOOL)isVideoLayoutEnhancementEnabled;
- (BOOL)isPSLOptimizationEnabled;
- (BOOL)isPslCloudMixEnabled;
- (BOOL)isMMRSupportCloudPsl;
- (BOOL)canStartDebrief;

#pragma mark -WebinarFreeTrial
- (void)onWebinarFreeTrialToastAutoHide:(BOOL)dontShowAgainChecked;
- (void)onWebinarFreeTrialToastCloseBtnClicked:(BOOL)dontShowAgainChecked;
- (void)onWebinarFreeTrialToastLinkUrlClicked;
- (void)onWebinarFreeTrialPanelCloseBtnClicked:(BOOL)dontShowAgainChecked;
- (void)onWebinarFreeTrialPanelLinkUrlClicked;
#ifdef __cplusplus
- (void)getWebinarFreetrialToolbarInfo:(NS_ZM_CONF_UNIVERSAL_UI::WebinarFreetrialReminderInfo &)info;
- (void)getWebinarFreetrialToastInfo:(NS_ZM_CONF_UNIVERSAL_UI::WebinarFreetrialReminderInfo &)info;
#endif

- (NSString *)getCurrentClientVersion;

- (NSString *)getE2EMeetingSecurityCode;
- (NSInteger)getE2EMeetingSecurityCodePassedSeconds;
- (BOOL)isNewEndLeavingUIEnabled;
@end

NS_ASSUME_NONNULL_END
