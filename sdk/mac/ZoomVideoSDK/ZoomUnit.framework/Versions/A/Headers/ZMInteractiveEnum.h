//
//  ZMInteractiveEnum.h
//  SaasBeeMainboard
//
//  Created by Justin on 3/3/12.
//  Copyright (c) 2012 Zipow. All rights reserved.
//

#import <Foundation/Foundation.h>

#define _ZP_MODULE_EXPORT_SYMBOL_ __attribute__((visibility("default")))

extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_PTDockMenuItemJoinByID;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_PTDockClick2ReopenWindows;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_PTBringConfWindowFront;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_PTProcessShouldTerminate;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_ConfirmPTProcessShouldTerminate;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_ConfPoppingUpTipRequest;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_ConfPoppingUpTipName;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_ConfPoppingUpTipMessage;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_ConfAudioDeviceType;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_ConfPoppingUpTipType;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_ConfPoppingUpTipFBID;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_ConfPoppingUpTipSpeak;

extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_SettingsChangedForConference;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_SettingsChangedForConferenceType;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_SettingsChangedForConferenceValue;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_PTNotifyConferenceProcessID;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_PTNotifyConferenceProcessID;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_ConfNotifyPTOpenSetting;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_ConfNotifyPTOpenSetting;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_ConfNotifyPTCloseSetting;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_ConfRequestPTForceQuitting;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_ActiveConferenceDueToPTActivated;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_ZoomApplicationWillResignActive;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_ZoomApplicationDidResignActive;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_ZoomApplicationDidBecomeActive;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_ConferenceEndedEvent;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_ConferenceObjectDidCreate;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_ConferenceUIDidCreate;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_ConferenceObjectWillDestroy;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_ConferenceObjectDidDestroy;

extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_ConfNotifyPTSendFeedback;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_ConfNotifyPTSendFeedback;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_PTAskConfToLeaveBeforeTerm;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_PTAskConfForLeaveNeedConfirm;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_ConfLeavingReasonForPT;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_WillShowAttitudeFeedbackForPT;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_StopPreLoadingConference;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_PTForceToLeaveCurConf;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_ConfWindowHandleChanged;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_ConfWindowHandleChanged;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_BOInprogressing;//ZOOM-183814
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_BOJoinByClick;//ZOOM-183814
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_BOJoinSessionName;//ZOOM-183814
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_ConfNotifyUpdateWindow;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_MBRequestPTConfStatus;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_PTReplyMBConfStatus;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_PTReplyMBConfStatus;

extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_Device_cam;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_Device_Info_Ret;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_Device_CamErr;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_ConfStartLoginWindow;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_ActivateZoomApplicationExternally;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_ActivateZoomApplicationExternally;

extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kZoomEnterFullscreenWhenViewShare;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kZoomDualMonitor;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kZoomEnterFullscreenWhenDualMonitorSetted;

extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kZoomFitToWindowViewShare;

extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kZoomRemoteControlAlwaysShowToolbar;//ZOOM-17122

extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kZoomFITDocked;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kZoomFITXPOS;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kZoomFITYPOS;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kZoomClosedCaptionFontSize;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kZoomClosedCaptionCaptionColor;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kZoomClosedCaptionTranslationColor;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kZoomClosedCaptionAlwaysShowCaptions;

extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kZoomShowIconInMenuBar;//[Zoom-21620]
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kZoomWillReopenTheApplication;//ZOOM-24821
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kZoomParam_EventTrack_ClientType;//[Zoom-46054]
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kZoomParam_EventTrack_Location;//[Zoom-46054]
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kZoomParam_EventTrack_Event;//[Zoom-46054]
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kZoomParam_EventTrack_SubEvent;//[Zoom-46054]
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kZoomParam_EventTrack_ExtraData;//[Zoom-46054]
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_SilentActiveZoomApp;

//send message from PT to meeting
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_UnmuteAudio;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_Audio_Error_No_Callback;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_PTRequestConfExitFullScreen;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_PT_Checked_Fit2Window_Button;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_Always_Show_User_Name;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_Auto_Join_Audio;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_Host_Not_Join;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_Host_Join;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_Meeting_Request_Password;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_HideNoVideoUser;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_SpotlightSelf;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_DualMonitor;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_Open_Browser;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_Logitech_Audio_Status_Changed;//ZOOM-4319
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_Switch_Topbanner_in_meeting;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_SharingCode_Show_Update;


//send message from meeting to PT
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_VideoVirtualBkImageDidDownloaded;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_Conf_Close_Invite;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_Conf_Fail;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_Conf_Param;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_Conf_Param2;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_Conf_Param3;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_Conf_ErrorNumber;


extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_Selected_Camera_WillChange;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kNoti_Selected_Camera_Changed;

extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_MaxParticipantCount;

extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_CameraControl;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_Device_Id;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_Device_Name;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_MeetingURL;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_LiveSteamViewUrl;//ZOOM-158179
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_IsWebinar;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_MeetingWindowFrame;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_MeetingReportProblemType;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_MeetingReportProblemType_Audio;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_MeetingAudioLogDir;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_ErrorTitle;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_ErrorDesc;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kParam_ErrorDescLink;

extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kIMUserStatus;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kIMUserCustomMessage;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*    kIMUserStatusChanged;

static _ZP_MODULE_EXPORT_SYMBOL_ NSString* const kZoomAppearanceDidChange = @"ZoomAppearanceDidChange";
static _ZP_MODULE_EXPORT_SYMBOL_ NSString* const kZoomProcessAppearanceDidChange = @"ZoomProcessAppearanceDidChange";
static _ZP_MODULE_EXPORT_SYMBOL_ NSString* const kZoomProcessUserAppearance = @"ZoomProcessUserAppearance";

extern _ZP_MODULE_EXPORT_SYMBOL_ NSString* kNoti_Components_Download_Finished;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString* kNoti_Components_Download_Failed;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString* kNoti_Components_Download_Begin;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString* kNoti_Components_Installed;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString* kNoti_Components_Not_Need_Download;

// Zoom Apps
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString* kNoti_PTProcessWillTerminate; // ZOOM-241091
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString* kNoti_ShowZoomAppUnavailableAlert;

extern _ZP_MODULE_EXPORT_SYMBOL_ NSString *const kAppOnGetContextNotification;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString *const kAppOnTokenExpiredNotification;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString *const kChatAppStatusChangedNotification;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString *const kAppLoadCompletedNotification;

//Zoomphone
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString*  kNoti_ConfMcmWillTerm;

extern _ZP_MODULE_EXPORT_SYMBOL_ NSString *kIM_JSHuddleViewHandle;

//aomhost
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString *kNoti_Aomhost_Download_Success;

extern _ZP_MODULE_EXPORT_SYMBOL_ NSString* kIM_JSWebVcardFrameChanged;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString* kIM_JSCloseWebVcard;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString* kIM_JSWebResourceReady;

//Business UI
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString* kSetting_ClosedCaptionFontSizeChanged;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString* kSetting_ClosedCaptionColorChanged;
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString* kSetting_ClosedCaptionTranslationColorChanged;

//Spaces
extern _ZP_MODULE_EXPORT_SYMBOL_ NSString* kNoti_Spaces_Installed;

