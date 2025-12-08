//
//  ZMPConfDataProtocol.h
//  ZCommonUI
//
//  Created by Justin Fang on 6/7/14.
//  Copyright (c) 2014 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "zoom_client_conf.h"
//#import "ZRBreakoutSessionInfo.h"


@protocol ZMPConfDataProtocol <NSObject>

#ifdef BUILD_FOR_MIMO

//ZoomRooms interfaces:
- (NSString*)getMeetingNumber;
- (NSString*)getMeetingID;
- (NSString*)getDialInNumber;
- (NSString*)getTollFreeNumber;
- (NSURL*)getInternationalNumberURL;
- (int)getParticipantID;
- (int)getMyUserID;
- (BOOL)isThisMyUserID:(int)userID;
- (BOOL)supportsSwitchWallViewMode;
- (BOOL)isAble2SwitchWallViewMode;
- (BOOL)isInWallViewMode;
- (BOOL)canSwitchToSpeakerView;
- (int)getSharingStatus;
- (BOOL)isSendingShare;
- (BOOL)isReceivingShare;
- (BOOL)isBothSendingAndReceivingShare;
- (BOOL)isSendingOrReceivingShare;
- (int)getUserCount;
- (NSArray*)getParticipantsArray;
- (BOOL)createCachedParticipantsArray;
- (NSArray*)getCachedParticipantsArray;
- (BOOL)deleteCachedParticipantsArray;
- (BOOL)isCachedParticipantsArrayAlreadyCreated;
- (NSArray*)getLeftArray;
- (BOOL)createCachedLeftArray;
- (NSArray*)getCachedLeftArray;
- (BOOL)deleteCachedLeftArray;
- (BOOL)isCachedLeftArrayAlreadyCreated;
- (BOOL)isMeetingLocked;
- (BOOL)isFirstPageOfGalleryView;
- (BOOL)isLastPageOfGalleryView;
- (BOOL)isFirstPageOfFloatingVideoStrip;
- (BOOL)isLastPageOfFloatingVideoStrip;
- (void)setMeetingPasswordRequired:(BOOL)required;
- (void)initMeetingData4NewConnection;
- (NSString*)getMeetingPassword;
- (NSString*)getRawMeetingPassword;
- (NSString*)getNumericPassword;
- (NSDictionary*)getRecordingReminderDic;
- (NSDictionary*)getStartRecordingDisclaimerDic;
- (BOOL)needPromptStartRecordingDisclaimer;
- (NSString*)getShareURL;
- (BOOL)isScheduleForLaptopShare;
- (void)removeScheduleForLaptopShare;
- (void)removeScheduleForAudioOnly;
- (BOOL)isBlackMagicDeviceReady;
- (BOOL)canControlMyCamera:(NSString*)deviceId;
- (BOOL)getRecordingInfo:(BOOL*)isMeetingRecording myStatus:(BOOL*)amIRecording CMRStatus:(BOOL*)cmrInProgress CMRConnecting:(BOOL*)isCMRConnecting privilege:(BOOL*)canIRecord;
- (BOOL)isPSTNCalloutMeeting;
- (void)removeScheduleForPSTNCalloutMeeting;
- (BOOL)isOriginalHost;
- (int)getCalloutType;
- (int)getHostUserType;
- (NSArray*)getCallOutCountryArray;
- (NSArray*)getTollFreeCallInNumberList;
- (NSArray*)getCallInCountryList;
- (NSString*)getDefaultCallInCountry;
- (long long)getScheduleOptions;
- (long long)getScheduleOptions2;
- (long long)getScheduleOptions3;
- (BOOL)isThirdPartyAudioOn;
- (NSString*)getThirdPartyAudioInfo;
- (BOOL)isViewOnlyMeeting;
- (BOOL)isWebinarMeeting;
- (BOOL)isLeadMode;
- (int)getSpotlightVideoUserID;
- (BOOL)isMultiShareMode;
//- (BOOL)hasContentToShowInScreenPosition:(int)screenPosition;
- (BOOL)hasContentToShowInMainVideo;
- (NSArray*)getMeetingScreenStatusForPin;
- (int)getWarningForSelfSharePinnedToViewerShare;
- (NSArray*)getAllShareSourceUserIDs;
- (NSArray*)getAllShareSourceItems;
- (BOOL)isFloatingVideoSupported;
- (BOOL)canAdjustSingleFloatingVideo;
- (int)getFloatingVideoPosition;
- (int)getFloatingVideoSize;
- (BOOL)isAdjustedToFloatingVideoStripType;
- (int)getVideoUserCountInCurrentPageOfFloatingStrip;
- (BOOL)canShowFloatingShareContent;
- (BOOL)isShowingFloatingShareContent;
- (BOOL)isVideoSharingOptimizationSupported;
- (BOOL)existsPureCallInUsers;
- (BOOL)getClosedCaptionInfo:(BOOL*)isCCAvailable isVisible:(BOOL*)isCCVisible fontStye:(int*)fontStyle;
- (BOOL)getLiveTranscriptionInfo:(BOOL*)isLiveTranscriptionEnabled isLiveTranscriptionVisible:(BOOL*)isLiveTranscriptionVisible isLiveTranscriptionFeatureOn:(BOOL*)isLiveTranscriptionFeatureOn
              privacyAlertAction:(int*)privacyAlertAction;
- (BOOL)getInterpretLanguageInfo:(BOOL*)isInterpretationAvailable activeLanguage:(int*)activeLanguage interpretLanguages:(NSArray**)interpretLanguages isOriginalAudioMuted:(BOOL*)isOriginalAudioMuted;
- (NSDictionary*)getInterpretationLanguageDetail:(int)language;
- (NSRect)visibleFloatingVideoWindowRect;
//- (int)getFloatingVideoDisplayingUserID;
- (BOOL)canRequestRemoteCameraControl:(int)userID;
- (BOOL)isRemoteCameraControllingByMe:(int)userID;
- (BOOL)canMoveSelectedCamera:(int)userID;
- (BOOL)canZoomSelectedCamera:(int)userID;
- (BOOL)isCameraInControl:(int)userID;
- (BOOL)isMuteOnEntryOn;
- (BOOL)isSharingCamera;
- (NSString*)getSharingCameraID;
- (BOOL)canShowShareContentOnly;
- (BOOL)isShowingShareContentOnly;
- (BOOL)isCamraSupportSetMovingSpeed:(NSString*)deviceID;
- (int)getStoredCamMovingSpeedPercentage:(NSString*)deviceID;
- (BOOL)isAllowRaiseHandForAttendee;
- (BOOL)canSwitchToSideBySide;
- (BOOL)isAdjustedToFloatingSideBySideType;
- (BOOL)isSupportSilentMode;
- (BOOL)isSupportWaitingRoom;
- (BOOL)isEnableWaitingRoomOnEntry;
- (BOOL)isShowAudioParticipants;
- (BOOL)isShowMoreParticipantsInGallery;
- (BOOL)isIdentifyGuestParticipants;
- (BOOL)canAttendeesUnmuteThemSelves;
- (NSDictionary*)getCallInTspInfoDic;
- (BOOL)isNormalVideoMeeting;
- (int)getChatMessageCount;
- (BOOL)isShowChatListOnZR;
- (BOOL)isShowChatNotificationOnZR;
- (BOOL)isAudioTroubleshootingRunning;
- (int)getAudioTroubleshootingDuration;
- (int)getAudioTroubleshootingLeftTime;
- (BOOL)isAudioMuted;
- (BOOL)getSettingInAppContextString:(NSString*)key value:(BOOL*)value;
- (BOOL)setSettingInAppContextString:(NSString*)key value:(BOOL)value;
- (BOOL)hasOnly1HostAnd1H323;
- (BOOL)setSettingInAppContextStringForStringValue:(NSString*)key value:(NSString*)value;
- (BOOL)getSettingInAppContextStringForStringValue:(NSString*)key value:(NSString**)value;
- (BOOL)isSharingWBCamera;
- (void)setIsDeletingCachedParticipantsArrayFlag:(BOOL)isDeleting;
- (BOOL)getIsDeletingCachedParticipantsArrayFlag;
- (void)setIsDeletingCachedLeftArrayFlag:(BOOL)isDeleting;
- (BOOL)getIsDeletingCachedLeftArrayFlag;
- (BOOL)isEncryptedMeeting;
- (int)getEncryptionAlgorithm;
- (NSArray*)getAllDisplayingUserIDsListWithSharing;
- (BOOL)isShowingParticipantsCountInMeeting;
- (BOOL)isCanSendSharingContent;
- (int)getShareSettingType;
- (BOOL)isDisableScreenSharing;
- (BOOL)isShareSettingTypeLocked;
- (int)getMeetingSharePrivilege;
- (BOOL)isReportIssueEnabled;
- (NSString*)getBindKey;
- (BOOL)isSingleScreenShowingVideo;
- (BOOL)isInGalleryThumbnailMode;
- (int)getVideoUserCountInCurrentPageOfGalleryThumbnail;
- (BOOL)isViewOnlyCanTalk;
- (BOOL)isMultiShareDisabled;
- (long long)getScheduleOptions4;
- (BOOL)isE2EEncMeetingPreSession;
- (NSUInteger)getE2EEClientWithoutOnHoldUserCount;
- (BOOL)isZrwSharing;
- (BOOL)canShareSupportAnnotation;
- (BOOL)isMyShareAnnotationDisabled;
- (ZRBreakoutSessionInfo*)getBreakoutSessionInfo;
- (BOOL)isPromptUnencryptedData;
- (BOOL)isLiveStreamUnencrypted;
- (BOOL)hasRemoteControlAdmin;
- (BOOL)hasRemoteControlAssistant;
- (BOOL)IsShareDesktopDisabled;
- (BOOL)isSharingUSBWBCamera;
- (BOOL)isShowParticipantCount4Attendee;
- (NSArray*)getAttendeeList:(NSString*)filter;
- (NSArray*)getUnencryptedAttendeeList;
- (NSDictionary*)getArchiveCustomizeDic;
- (NSUInteger)getArchiveOption;
- (NSString*)getAccountPrivacyUrl;
- (NSString*)getOriginalHostName;
- (NSString*)getOriginalHostId;
- (NSArray*)getConfAppListWithAppId:(NSString*)appId;
- (BOOL)isConfAppListUpdated;
- (NSArray*)getReactionStatistics;
- (BOOL)needConfirmVideoPrivacyWhenJoinMeeting;
- (BOOL)isMeetingSupportInvite;
- (BOOL)isNeedHideMeetingNumber;
- (BOOL)isNeedHideMeetingPasscode;
- (NSString*)OnZoomEventDetailLink;
- (NSArray*)getNDISources;
- (BOOL)isNDIEnabled;
- (int)countOfNDISourceSupport;
- (NSString*)getMeetingPrivacyPolicyUrl;
- (BOOL)isCRCCalloutOnlyEnabled;

#else

//Zoom client interfaces:
typedef enum
{
    Evt_Conf_SubType_None,
    Evt_Font_Size_Changed,
    Evt_Audio_Device_Changed,
    Evt_Audio_ManualSelectDevice_Error,
    Evt_Conf_SubType_Meeting_Controls,
    Evt_Conf_SubType_LeaveMeeting_By_Hardware,//ZOOM-10528
    Evt_Conf_SubType_LeaveMeeting_Without_Confirm,
    Evt_Conf_SubType_Feedback,
    Evt_Conf_SubType_Install_AudioDevice,
    Evt_Conf_SubType_DirectShare_Started,//[Zoom-13928]
    Evt_Conf_SubType_DirectShare_Stopped,//[Zoom-13928]
    Evt_Conf_SubType_SystemWillSleep,//[Zoom-13859]
    Evt_Conf_SubType_SystemDidWake,//[Zoom-75660]
    Evt_Conf_SubType_ShowMeetingTime,
    Evt_Conf_SubType_IsOrNotInSIPCall, //ZOOM-14478 sip call
    Evt_Conf_SubType_Fullscreen,//[Zoom-27177]
    Evt_Conf_SubType_MenuBar_Option_Change,//[Zoom-42226]
    Evt_Conf_SubType_Login_Finished,//[Zoom-42226]
    Evt_Conf_SubType_Logout_Finished,//[Zoom-42226]
    Evt_Conf_Audio_Setting_Show,//ZOOM-38961
    Evt_Conf_SubType_CoreAudio_JustKilled,//[Zoom-43850]
    Evt_conf_BandWidth_Limit_Info,//ZOOM-82229
    Evt_Conf_SubType_Font_Size_Changed,//ZOOM-20021
    Evt_Conf_SubType_Detect_Music,//ZOOM-213253
    Evt_Conf_SubType_Download_AOM_Share_Doc_Callback,//ZOOM-90578
    Evt_Conf_SubType_Download_AOM_Presenter_Layout_Callback,
    Evt_Conf_SubType_Download_AOM_Share_Video_Callback,//ZOOM-201098
    Evt_Conf_SubType_isConfirming_Leave_Meeting,
    Evt_Conf_SubType_Should_Disable_Mirror,
    Evt_Conf_SubType_Device_Authorization_Alert,
}EVENT_SUBTYPE_CONF;

typedef enum
{
    Evt_Conf_None,
    Evt_ClosedCaption,
    Evt_Audio,
    Evt_Meeting,
    Evt_DirectShare,
    Evt_Conf_Type_Accessibility,
    Evt_Conf_Type_MenuBar,//[Zoom-42226]
}EVENT_TYPE_CONF;

@optional
- (void)eventChangedWithType:(int)inType subType:(int)inSubType param:(id)inParam;
- (id)getEventValueForType:(int)inType subType:(int)inSubType;//[Zoom-27177]
#endif

@end
