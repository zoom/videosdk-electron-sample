//
//  ZPPTSinkEventHandler.h
//  SaasBeePTUIModule
//
//  Created by Justin Fang on 12/24/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//
#pragma once
#import <Foundation/Foundation.h>
#import <ZoomKit/zoom_client_conf.h>
extern NSString* kNoti_StartLogin;  //for show NotifyIcon animation
extern NSString* kNoti_Login_FBPage_Ready;
extern NSString* kNoti_Login_FB_AuthPage_Ready;
extern NSString* kNoti_Login_FB_Cancel;
extern NSString* kNoti_FB_RosterReady;
extern NSString* kNoti_FB_IM_LogOut;

extern NSString* kNoti_SB_Register;
extern NSString* kNoti_ListMeeting;

extern NSString* kNoti_IMCmd_Invitation;//Call invitation incoming. param1 InviteItem; param2
extern NSString* kNoti_IMCmd_Accept;//Call was accepted. param1 ; param2 
extern NSString* kNoti_IMCmd_Decline;//call was declined. param1 ; param2 
extern NSString* kNoti_IMCmd_Hangup;//caller hang up. param1 ; param2 

//Asyn Notify
extern NSString* kNoti_InviteBuddyFromConference; // param1 HWND; param2 MeetingItem
extern NSString* kNoti_IPC_InCall;//param1 pMeetingID
extern NSString* kNoti_IPC_CallEnded;//Param1 pMeetingID
extern NSString* kNoti_IPC_CallPListChange;
extern NSString* kNoti_IPC_Web_Start_LaunchCall;
extern NSString* kNoti_IPC_Event_WebstartNeedForceUpdate;

extern NSString* kNoti_PT_Set_SIP_Status; //zoom-14478
extern NSString* kNoti_PT_Dial_In_Meeting;//zoom-14478
extern NSString* kNoti_PT_Delete_Meeting;
extern NSString* kNoti_PT_List_Meeting;
extern NSString* kNoti_PT_List_History;
extern NSString* kNoti_PT_List_CalendarMeeting;   // ZOOM-28366
extern NSString* kNoti_Calendar_Account_Switch;   // ZOOM-28366
extern NSString* kNoti_RefreshCalendarConfig;    // ZOOM-40336
extern NSString* kNoti_CalendarConfigReady;      // ZOOM-40336
extern NSString* kNoti_PT_Get_Meeting_Invitation;//ZOOM-65612

extern NSString* kNoti_PT_Get_Calendar_Auth_Result;
extern NSString* kNoti_PT_Get_Calendar_BYOK_Result;
extern NSString* kNoti_PT_MeetingExtInfoChanged;//ZOOM-87204
extern NSString* kNoti_PT_OnZoom_Change;
extern NSString* kNoti_PT_OnZoomCanJoinChange;
extern NSString* kParam_PT_OnZoom_Title;
extern NSString* kParam_PT_OnZoom_Message;
extern NSString* kParam_PT_OnZoom_Result;
extern NSString* kParam_PT_OnZoom_Button_Text;
extern NSString* kParam_PT_OnZoom_Button_Url;
extern NSString* kNoti_PT_RequestLcp_Change;
extern NSString* kNoti_PT_OpenScheduleMeetingWindow;
extern NSString* kNoti_PT_ScheduleParam_MeetingNum;
extern NSString* kNoti_PT_ScheduleParam_OccurrenceTime;
extern NSString* kNoti_PT_ScheduleParam_WndMode;
extern NSString* kNoti_PT_ScheduleParam_PointerValue;
extern NSString* kNoti_PT_ScheduleParam_MeetingMasterEventId;
extern NSString* kNoti_PT_UpdateOutlookAttachments;
extern NSString* kNoti_PT_VBSettingChange;

extern NSString* kNoti_Setting_Changed;
extern NSString* kNoti_OnCmdReturn_MsgDlg;//MessageDialog Cmd Return param1 CmdCode, //Not used on Mac yet
extern NSString* kNoti_AutoLogin_WhenLaunch;
extern NSString* kNoti_PT_Minimized;
extern NSString* kNoti_PT_NewVersionReady;

extern NSString* kNoti_PT_AutoUpdate_CheckFailed;
extern NSString* kNoti_PT_Download_Progress_Updated;
extern NSString* kNoti_PT_No_NewVersion;
extern NSString* kNoti_PT_URLAction_PBXCall_NoCapabiltite;

extern NSString* kNoti_ProxyServerAuthenticationRequest;
extern NSString* kParam_ProxyServerAuthenticationHost;
extern NSString* kParam_ProxyServerAuthenticationPort;
extern NSString* kParam_ProxyServerAuthenticationDescription;

extern NSString* kNoti_ReleaseNoteForLatestVersion;
extern NSString* kParam_ReleaseNoteForLatestVersion;
extern NSString* kParam_ReleaseNoteForLatestNote;

extern NSString* kNoti_PT_OnSendFeedback;
extern NSString* kNoti_StartRecConverter;

//kNoti_InviteBuddyFromConference keys
extern NSString* kParam_InviteBuddyWindowID;
extern NSString* kParam_InviteBuddyMeetingID;
extern NSString* kParam_InviteBuddyMeetingNumber;

//kNoti_IM_InputStateChange parameters
extern NSString* kParam_IM_InputStateChange_Sender;
extern NSString* kParam_IM_InputStateChange_State;

// PTUI defined notification
extern NSString* ZPAuthSuccessfulNotification;
extern NSString* ZPSignOutNotification;
extern NSString* ZPIMReconnectingNotification;
extern NSString* kNoti_PT_SettingSpeakerTestingEnd;
extern NSString* kNoti_FavoriteSearchDomainUser;
extern NSString* kNoti_FavoriteAvatarReady;
extern NSString* kNoti_FavoriteRefreshDomain;
extern NSString* kNoti_FavoriteRefreshFavorite;
extern NSString* kParam_Favorite_Result;
extern NSString* kParam_SearchDomainUser_Array;
extern NSString* kNoti_PT_SSOLogin_Back;
//call out
extern NSString* kNoti_CalloutStatusChanged;
extern NSString* kNoti_PairCode_Status_Changed;
extern NSString* kNoti_H323CalloutStatusChanged;
extern NSString* kNoti_H323CalloutNodeIdChanged;    //ZOOM-57206
extern NSString* kParam_H323CaloutUserId;           //ZOOM-57206
extern NSString* kParam_H323CaloutUserName;         //ZOOM-57206
extern NSString* kNoti_OpenInviteSip;

//direct share
extern NSString* kNoti_DirectShareStatus_Update;

// IM
extern NSString* const kIM_ShareMessage_back;
extern NSString* const kIM_ShareMessage_In_Meeting_back;
extern NSString* kIM_E2EKeyBindingFailed;
extern NSString* kNoti_SDK_OnAuth;
extern NSString* kNoti_SDK_PairCode_Status_Changed;
extern NSString* kNoti_SDK_WaitRoom_Join;
extern NSString* kNoti_SDK_WaitRoom_Leave;
extern NSString* kIM_CrawlURLBack;
extern NSString* kIM_LinkPreviewDownloaded;
extern NSString* kIM_ChatBeginConnecting;
extern NSString* kIM_NotifySubscribedPresenceExpired;
extern NSString* kNoti_UpcomingMeetingReminder;
extern NSString* kIM_NotifyUnsupportMessageRefresh;
extern NSString* kIM_IndicationCallActionNotification;//ZOOM-50424
extern NSString* KIM_IntegrationFileInfoUpdate;
extern NSString* kIM_AssignChannelAdmin;
extern NSString* kIM_RemovedFromGroup;

extern NSString* kIM_NotifyInstantMeetingWebSettingUpdate;

extern NSString* kIM_ReceiveOfflineCallNotification; //ZOOM-156782
extern NSString* kIM_JoinChannelReject;

extern NSString* kNoti_IM_BotListReceived;
extern NSString* kNoti_IM_BotAdded;
extern NSString* kNoti_IM_BotRemoved;

extern NSString* kIM_ShareZAppMessage_back; // ZOOM-290161

// ZOOM-418931

extern NSString* kParam_Bot_ReqID;
extern NSString* kParam_Bot_Channel;
extern NSString* kParam_Bot_HasNext;
extern NSString* kParam_Bot_jids;
extern NSString* kParam_Bot_BotInfos;
extern NSString* kParam_Bot_Name;
extern NSString* kParam_Bot_IconPath;
extern NSString* kParam_Bot_Description;
extern NSString* kParam_Bot_BotJid;
extern NSString* kParam_Bot_Supported;
extern NSString* kParam_Bot_Error;
extern NSString* kParam_Bot_Error_Code;
extern NSString* kParam_Bot_Success;

#ifdef ENABLE_MAILCLIENT_SERVICE
extern NSString* kIM_NotifyMailDownloadCompletionResult;
extern NSString* kIM_NotifyRCFIDReceived;

extern NSString* kIM_NotifySearchLocalBuddyReceived;
extern NSString* kIM_NotifySearchRemoteBuddyReceived;
extern NSString* kIM_NotifySearchSuggestBuddyReceived;

extern NSString* kMail_NotifyRemoveAccount;
extern NSString* kMail_NotiJidUpdate;
extern NSString* kMail_NotifyWindowShouldChangeCompress;
extern NSString* kMail_NotifyDelete;
extern NSString* kIM_ShareMailToChat;
#endif

//extern NSString* kNoti_OutlookVcardCall; //ZOOM-140729


@interface ZPPTSinkEventHandler : NSObject
+ (void)notify:(NSString*)eventName object:(id)wparam lparam:(int)lparam;
+ (void)notify:(NSString*)eventName object:(id)wparam object:(id)lparam;
+ (void)notify:(NSString*)eventName wparam:(int)wparam lparam:(int)lparam;
+ (void)asynNotify:(NSString*)eventName wparam:(int)wparam lparam:(int)lparam;
+ (void)notify:(NSString*)eventName object:(id)param;
+ (void)notify:(NSString*)eventName info:(NSDictionary*)dict;
+ (void)asynNotify:(NSString*)eventName object:(id)param;
+ (void)asynNotify:(NSString*)eventName dict:(NSDictionary*)dict;
+ (id)parseNotify:(NSNotification*)aNotification;           //Only parse single id with key "param", multify objects in dictory need parse by yourself.
@end
