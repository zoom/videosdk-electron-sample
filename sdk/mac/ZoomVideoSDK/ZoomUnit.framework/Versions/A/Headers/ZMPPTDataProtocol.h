//
//  ZMPPTDataProtocol.h
//  ZCommonUI
//
//  Created by FangJin on 8/7/15.
//  Copyright (c) 2015 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "ZMRoomConstants.h"
#import <Zoomkit/zoom_client_conf.h>
@class ZRScreenRenderAllOptions;


@protocol ZMPPTDataProtocol <NSObject>

#ifdef BUILD_FOR_MIMO

typedef enum{
    Prompt_Waiting_Host_Start,
    Prompt_Waiting_Host_Admit,
} PROMPT_WAITING_TYPE;

//ZoomRooms interfaces:
- (BOOL)isMetalRenderEnabled;
- (int)getMetalDeviceCount;
- (BOOL)isMicMutedByExtendedDevice;
- (BOOL)isOptimized4VideoSharing;
- (void)enableOptimizeVideoSharing:(BOOL)enabled;
- (int)getLegalScreenCount;
- (NSArray*)getLegalScreens;
- (NSArray*)getSortedScreens;
- (int)getNSScreenIndexByGeographicalScreenPos:(int)position;
- (NSScreen*)getVideoScreenForGeographicalPostion:(int)position;
- (NSScreen*)getMainVideoScreen;
- (int)getMainVideoScreenPosition;
- (NSString*)abbreviatedRoomName;
- (NSString*)fullRoomName;
- (ZRScreenRenderAllOptions*)getWebScreenRenderOptions;
- (NSString*)getExclusiveCameraName4Video;
- (NSString*)getZoomShareURL;
- (void)onAirHostConnected;
- (void)onAirHostDisconnected;
- (void)onLocalShareStart;
- (void)onLocalShareStop;
- (void)notifyLocalShareStatus:(BOOL)bShare;
- (void)onBlackMagicDataReady:(BOOL)flag;
- (void)startLocalPresentation4AutoHdmi;
- (BOOL)needsStartLocalPresentation4AutoHdmi:(BOOL)newStatus;
- (void)onDirectPresentationDataReady:(NSInteger)type;
- (BOOL)isDirectPresentationCodeAllowedToShow;
- (void)onDirectPresentationPasscodeUpdated;
- (void)dismissScreenSaver;
- (void)disableScreenSaver;
- (void)enableScreenSaver;
- (BOOL)hasPendingPSTNCall;
- (BOOL)isEnteringMeeting;
- (BOOL)doesZRCSupportClosedCaption;
- (BOOL)isInSIPCall;
- (void)onConfObjectsWillDestroy;
- (BOOL)isRoomLoggedOn;
- (BOOL)isJoinOnlyMode;
- (void)onRoomUIAvailabilityUpdated;
- (void)setIsAutoHdmiLocalSharingMeeting:(BOOL)flag;
- (BOOL)isAutoHdmiLocalSharingMeeting;
- (BOOL)doesZRCSupportMuteVideoByOther;
- (BOOL)shouldHideShareInstructionFromTV;
- (void)onSharingStart:(int)sharingType;
- (void)onSharingEnd:(int)sharingType;
- (void)wantsToShowPTInfo:(BOOL)flag;
- (BOOL)isSelfVideoMirrored:(NSString*)deviceId;
- (void)onWallViewStyleUpdate:(int)style;
- (BOOL)doesZRCSupportInitiativeMeetingParticipantList;
- (BOOL)isZRIdleOutOfOperationTime;
- (BOOL)doesZRCSupportMultiShare;
- (BOOL)shouldMeetingStartWithMultiShareSwitchedOn;
- (NSString *)getAirhostShareToken;
- (BOOL)doesZRCSupportSilentMode;
- (void)showWaitingPrompt:(PROMPT_WAITING_TYPE)type isDisplay:(BOOL)bDisplay;
- (BOOL)shouldShowAudioParticipants;
- (BOOL)shouldShowMoreParticipantsInGallery;
- (BOOL)isNDIEnabled;
- (BOOL)isNDISeparateAudio;
- (void)notifyPT2UpdateIndicatorWithType:(ZR_INDICATOR_TYPE)type;
- (CGFloat)getOffsetXOfIndicator:(ZR_INDICATOR_TYPE)type;
- (NSString*)getCustomHDMIText;
- (void)showUserMutedAlert:(BOOL)isShow isVoip:(BOOL)isVoip;
- (void)relayoutMutedAlertOnAllScreens;
- (BOOL)isShowingUserMutedAlert;
- (BOOL)doesZRCSupportRecordingConsent;
- (BOOL)isDirectShareEncryptOptionEnabled;
- (NSData*)getWBCameraImage;
- (BOOL)doesZRCSupportMeetingViewChat;
- (BOOL)doesZRCSupportMeetingAudioTroubleshooting;
- (float)getOffsetBlowTopBannerLeft;
- (float)getOffsetBlowTopBannerRight;
- (BOOL)shouldStopMonitoringCaptureCard;
- (void)checkAndShowWarningForAllDefaultDevices;
- (int)getZRWUserID;
- (void)onZRWLeaveMeeting;
- (BOOL)isDisableMeetingChatNotification;
- (void)notifyInSilentMode:(BOOL)isInSilentMode;
- (BOOL)doesZRCSupportLocalView;
- (BOOL)isInLocalViewPolicy:(int)localScreenType meetingScreenCount:(int)meetingScreenCount;
- (void)stopWBCameraShare;
- (BOOL)isWBCameraSharing;
- (BOOL)doesZRCSupportAdjustShareAudio;
- (BOOL)hasControllerConnected;
- (BOOL)hasWebZRCConnected;
- (BOOL)hasPhoneZRCConnected;
- (BOOL)hasZRAOnlineConnection;
- (BOOL)isMultiZRCConnected;
- (BOOL)doesZRCSupportShowEncryptedMeetingIcon;
- (BOOL)doesZRCSupportsLanguageInterpretationParticipant;
- (BOOL)doesZRCSupportChinaMeetingPrivacy;
- (BOOL)doesZRCSupportMeetingDisclaimer;
- (BOOL)doesZRCSupportsLiveTranscription;
- (BOOL)isDisabledScreenShare;
- (void)usageTrackingScreenSharingSetting:(int)sharingSetting;
- (BOOL)doesZRCSupportWaitingRoomInLocalPresent;
- (void)notifyEnableAdmitGuest:(BOOL)isEnable;
- (BOOL)isTeamsMeetingInProgress;
- (BOOL)doesZRCSupportMultiScreenFloating;
- (BOOL)doesZRCSupportViewOnlyTalk;
- (BOOL)doesZRCSupportBreakoutSession;
- (BOOL)kickOutZRCNotSupportsDeleteMeetingChatMessageFeatrue;
- (BOOL)doesZRCSupportUSBWhiteboardCamera;
- (BOOL)getUsedLengthInTopBannerByPhoneController;
- (BOOL)doesZRCSupportsPrivacyAlert_LiveTranscription;
- (BOOL)doesZRCSupportViewWebinarAttendee;
- (BOOL)doesZRCSupportsPrivacyAlert_LiveStream;
- (BOOL)doesZRCSupportsPrivacyAlert_AllowTalk;
- (BOOL)doesZRCSupportsPrivacyAlert_PromotedToPanelist;
- (BOOL)doesZRCSupportsPrivacyAlert_Archive;
- (BOOL)doesZRCSupportsDisclaimer_JoinAsPanelist;
- (BOOL)doesZRCSupportsNDIUsage;
- (BOOL)getCurrentFixedNotificationType:(int*)type subType:(int*)subType;
- (BOOL)doesZRCSupportAppSignaling;
- (BOOL)doesZRCSupportsConfirmJoinMeetingVideoPreview;
- (BOOL)isScreenLocked;
- (void)updateIncomingShare:(BOOL)hasIncomingShare;
#else

//Zoom client interfaces:

typedef enum
{
    Evt_PT_SubType_None,
    Evt_PT_SubType_ToggleMeetingControls,
    Evt_PT_SubType_Setting_Close_For_Video,
    Evt_PT_SubType_IsLogin,
    Evt_PT_SubType_Login,
    Evt_PT_SubType_Logout,
    Evt_PT_SubType_Switch_Account,
    Evt_PT_SubType_Start_Video_Meeting,
    Evt_PT_SubType_Start_NoVideo_Meeting,
    Evt_PT_SubType_Join_Meeting,
    Evt_PT_SubType_EnterFullscreen,
    Evt_PT_SubType_ExitFullscreen,
    Evt_PT_SubType_CMRStorageInfo,//ZOOM-5534
    Evt_PT_SubType_Status,
    Evt_PT_SubType_BOFollowFullscreen,//ZOOM-183814
    Evt_PT_SubType_Enable,
    Evt_PT_SubType_Side_By_Side_Mode,//ZOOM-26329 for split sharing&video
    Evt_PT_SubType_Device_Changed,
    Evt_PT_Audio_Wizard_Show,//ZOOM-38961
    Evt_PT_SubType_Event_Track,//[Zoom-46054]
    Evt_PT_SubType_updateOriginalSoundSetting,//ZOOM-50116
    Evt_PT_SubType_BandWidth_Limit_Info_Changed,//ZOOM-82229
    Evt_PT_SubType_Did_Leave_Meeting,
    Evt_PT_SubType_Report_Problem,//ZOOM-118634
    Evt_PT_SubType_Upload_Avatar,//ZOOM-123364
    Evt_PT_SubType_DownloadAOM_Share_Doc,//ZOOM-90578
    Evt_PT_SubType_DownloadAOM_Presenter_Layout,//ZOOM-90578
    Evt_PT_SubType_Allow_Unmute_Audio_List_Change,//ZOOM-169862
    Evt_PT_SubType_DownloadAOM_Share_Video,//ZOOM-201098
    Evt_PT_SubType_IsAomhostDownloaded,//ZOOM-257648
    Evt_PT_SubType_IsJoinOnlyUser,//ZOOM-315763
    Evt_PT_Zapp_Join_Meeting,
    Evt_PT_Zapp_IsLatest,
    Evt_PT_Zapp_Login,
    Evt_PT_Zapp_Loaded,
    Evt_PT_Zapp_SetMTTimer,
} EVENT_SUBTYPE_PT;

typedef enum
{
    Evt_PT_None,
//    Evt_PT_Accessibility,
    Evt_PT_Setting,
    Evt_PT_Account,
    Evt_PT_Quit,
    Evt_PT_Meeting,
    Evt_PT_Schedule,
    Evt_PT_Direct_Share,
    Evt_PT_Fullscreen_Changed,
    Evt_PT_CMR,//ZOOM-5534
    Evt_PT_MainWindowId,
    Evt_PT_Zapp
}EVENT_TYPE_PT;

typedef enum
{//[Zoom-20918]
    Event_Status_None = 0,
    Event_Status_Show = 1,//indicate control show or not
    Event_Status_Enable = 2,//indicate control enable or disable
    Event_Status_On = 4,//indicate control is on or off
    
}EVENT_PT_STATUS;

@optional
- (void)eventChangedWithType:(int)inType subType:(int)inSubType param:(id)inParam;
- (id)getEventValueForType:(int)inType subType:(int)inSubType;
- (id)getEventValueForType:(int)inType subType:(int)inSubType param:(id)inParam;
- (NSString *)getPolicyLink;
- (NSString *)getTermServiceLink;
#endif

@end
