//
//  ZPZAppAdapter.h
//  zVideoUI
//
//  Created by TOTTI on 9/8/20.
//  Copyright © 2020 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#define ZoomAppsWindowNamePrefix @"Zoom Apps - "
#define ZoomAppsCollaborateWindowNameSuffix @" - Collaboration"
#define kZoomAppShareIdentity @"Zoom App Share Identity"
#define kZoomAppCollaborateMainWindowName @"Zoom Apps Collaboration Main Window"
#define MAX_AUTO_OPEN_COUNT 5
#define kZMZAppChildWebViewCtrlHeaderHeight 48
#define BundleArray @[@"/zApp.bundle", @"/ZoomMeetingBridge.framework", @"/ZoomAppUISDK.framework", @"/zAppUI.bundle"]

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ZMFilePickerScene) {
    ZMFilePickerScene_Default = 0,
    ZMFilePickerScene_ScreenShare,
    ZMFilePickerScene_IMChat,
    ZMFilePickerScene_ConfChat,
    ZMFilePickerScene_Fax,
};

@class ZMCaptureModel;
@protocol ZMFilePickerChatAppActionProtocol <NSObject>

@optional
- (void)filePickerChatAppClose:(NSString *)appID webviewID:(NSString *)webviewID;
- (void)filePickerChatAppBackLegacy:(NSString *)appID webviewID:(NSString *)webviewID;
- (void)filePickerChatAppCloseOnPTLogout;
- (void)filePickerChatAppCloseAtScene:(ZMFilePickerScene)scene;

@end

typedef NS_ENUM(NSInteger, ZMFilePickerItemType) {
    ZMFilePickerItemType_Default = 0,
    ZMFilePickerItemType_OneDriver,
    ZMFilePickerItemType_GoogleDriver,
    ZMFilePickerItemType_SharePoint,
    ZMFilePickerItemType_Box,
};

typedef NS_ENUM(NSInteger, ZAppSpotsSidebarSize) {
    Sidebar_Small = 0,
    Sidebar_Medium,
    Sidebar_XL,
    Sidebar_Hidden,
    Sidebar_COUNT,
};

typedef NS_ENUM(NSInteger, ZAppCollaborateLayoutStyle) {
    ZAppCollaborateLayoutStyle_None = 0,
    ZAppCollaborateLayoutStyle_Center,
    ZAppCollaborateLayoutStyle_SidePanel,
    ZAppCollaborateLayoutStyle_SidePanelWaitting, 
};

typedef NS_ENUM(NSInteger, ZMAppType) {
    ZMAppType_Default = -1,
    ZMAppType_Apps_PT = 0,
    ZMAppType_Apps_MT,
    ZMAppType_Phone,
    ZMAppType_OnZoom,
    ZMAppType_CCI,
    ZMAppType_SideCar,
    ZMAppType_Chat_DM,
    ZMAppType_Chat_Channel,
    ZMAppType_Mail,
    ZMAppType_Labs,
    ZMAppType_SpotMain,
    ZMAppType_SpotSidebar,
    ZMAppType_VCard,
    ZMAppType_ActivityCenter,
    ZMAppType_SearchApp,
    ZMAppType_Discover_Channels,
    ZMAppType_Chat_InMeeting,
    ZMAppType_SMS_DM,
    ZMAppType_SMS_Channel,
    ZMAppType_Calendar,
    ZMAppType_ZCC,
    ZMAppType_RTMP,
    ZMAppType_Surveys,
    ZMAppType_AIC_PLUS,
    ZMAppType_AIC_PLUS_IN_MEETING,
    ZMAppType_Events,
    ZMAppType_Clinical_Note,
    ZMAppType_Fax,
};

typedef NS_ENUM(NSInteger, ZMZAppViewCtrlActionType) {
    ACTION_DEFAULT = -1,
    ACTION_MORE = 0,
    ACTION_BACK, // Back Action
    ACTION_DROPDOWN, // Click DropDown
    ACTION_POP_OUT, // Click Pop Out
    ACTION_MERGE_BACK, // Click Merge back
    ACTION_REFRESH, // Refresh App
    ACTION_CLOSE, // Close App
    ACTION_CLOSE_ATTENDEE_PUSHED, // Close ATTENDEE Push
    ACTION_CLOSE_ALL_PUSHED, // Close All Pushed App
    ACTION_CLOSE_ALL_EXCEPT_ME_PUSHED, // Close all except me Pushed App
    ACTION_SEND, // Click Send
    ACTION_SEND_IN_CONTROLLERMODE, // Click Send In Layer Controller Mode
    ACTION_SHARE_WITH_AUDIO, // Click Share With Audio
    ACTION_SHARE_NO_AUDIO, // Click Share Whth No Audio
    ACTION_EXPAND, // Click Expand
    ACTION_COLLABORATE, // Click Collaborate
    ACTION_START_MEETTING, // Click Start Meeting
    ACTION_INVITE, // Click invite
    ACTION_OPEN_IN_MEETTING, // Click Open in Meeting
    ACTION_OPEN_NEW_WINDOW, // Click Open in New Window
    ACTION_SELECT_APP,
    ACTION_SHARE,
    ACTION_SELECT_WINDOW_APP_TAB,
    ACTION_ADD_APP,
    ACTION_SignIn,
    ACTION_OPEN_IN_ZR,
    ACTION_Copy_Share_Link,
    ACTION_Hide_Panel,
    ACTION_Close_All_Apps,
    ACTION_Guest_Mode,
};

typedef NS_ENUM(NSUInteger, ZAppRenderType) {
    ZAppRenderType_None,
    ZAppRenderType_Immersive,
    ZAppRenderType_CameraMode,
    ZAppRenderType_AppShare,
};

typedef NS_ENUM(NSInteger, ZMMTZappPluginModelType) {
    ZMMTZappPluginModelTypeVideo = 0,
    ZMMTZappPluginModelTypeImage,
};

typedef NS_ENUM(NSInteger, ZMZappLayersCutoutType) {
    ZMZappLayersCutoutType_Default = 0,
    ZMZappLayersCutoutType_Person, // remove the background
    ZMZappLayersCutoutType_Rectangle, // rounded corners
    ZMZappLayersCutoutType_Circle,
    ZMZappLayersCutoutType_Square, // rounded corners
    ZMZappLayersCutoutType_VerticalRectangle, // rounded corners
    ZMZappLayersCutoutType_Standard, // sharp corners (full video)
};

typedef NS_ENUM(NSUInteger, ZAppContentType) {
    ZAppContent_None,
    ZAppContent_List,
    ZAppContent_Detail,
    ZAppContent_App,
    ZAppContent_Error,
    ZAppContent_Authentication,
    ZAppContent_ControllerMode,
};

typedef NS_ENUM(NSUInteger, ZAppWebViewStatus) {
    ZAppWebView_Support = 0,
    ZAppWebView_Uninstall,
    ZAppWebView_Unsupport,
    ZAppWebView_Disable,
};

typedef NS_ENUM(NSUInteger, ZMZAppSetVBStatus) { // ZOOM-249560
    ZMZAppSetVB_Failed = 0,
    ZMZAppSetVB_Success,
    ZMZAppSetVB_Ignored,
};

typedef NS_ENUM(NSInteger, ZMAomhostDownloadErrorCode) {
    ZMAomhostDownloadSuccess,
    ZMAomhostDownloadFailed,
    ZMAomhostDownloadIgnored,
};

typedef NS_ENUM(NSUInteger, zappEnableState) {
    zappEnableState_Enable = 0,
    zappEnableState_Disable_By_Unknow_Error,
    zappEnableState_Disable_By_GPO,
    zappEnableState_Disable_By_Setting,
    zappEnableState_Disable_By_UserId_Mismatch,
    zappEnableState_Disable_By_Client_Not_Login,
    zappEnableState_Disable_By_Anonymous,
    zappEnableState_Disable_By_E2EE_ShowZapp,
    zappEnableState_Disable_By_Unknown_ShowZapp,
    zappEnableState_Disable_By_Different_Meeting,
    zappEnableState_Enable_Guest_Mode_For_Apps_Disabled_User,
    zappEnableState_Enable_Guest_Mode_For_Mismatched_User,
    zappEnableState_Disable_By_GPO_GuestMode,
    zappEnableState_Disable_By_Test_GuestMode,
    zappEnableState_Disable_By_Unsupport = 9999, // start for UI add state
    zappEnableState_Disable_By_macOSVersion = 10000,
};

typedef NS_ENUM(NSUInteger, ZAppMarketPlaceErrorCode) {
    ZAppMarketPlaceErrorCode_None = 0,
    ZAppMarketPlaceErrorCode_DISABLE_UNINSTALL = 4034,
    ZAppMarketPlaceErrorCode_DISABLE_BY_ACCOUNT_ADMIN = 4037,
    ZAppMarketPlaceErrorCode_DISABLE_BY_MARKETPLACE_OP = 4038,
    ZAppMarketPlaceErrorCode_DISABLE_SUBSCRIPTION_BY_ACCOUNT_ADMIN = 4039,
    ZAppMarketPlaceErrorCode_DISABLE_APP_DELETED = 4041,
    ZAppMarketPlaceErrorCode_ENABLE_APP_INSTALL = 4042,
    ZAppMarketPlaceErrorCode_ENABLE_APP = 4043,
    ZAppMarketPlaceErrorCode_DISABLE_PREAPPROVAL_SETTING = 4044,
    ZAppMarketPlaceErrorCode_PREAPPROVAL = 4045,
    ZAppMarketPlaceErrorCode_CANCEL_PREAPPROVAL = 4046,
    ZAPPMarketPlaceErrorCode_INVALID_FOR_ANONYMOUS = 40325,
    ZAPPMarketPlaceErrorCode_INVALID_APP_OFF_GUEST_MODE = 40332,
    ZAPPMarketPlaceErrorCode_COLLABORATE_END_FAIL_OF_AUTH = 40340,
    ZAPPMarketPlaceErrorCode_COLLABORATE_START_FAIL_OF_RATE_LIMIT = 40341,
};

typedef NS_ENUM(NSUInteger, ZAppOpenAppPurpose) {
    ZAppOpenAppBy_NativeUI = 0,
    ZAppOpenAppBy_WebLaucher,
    ZAppOpenAppBy_DeepLink,
    ZAppOpenAppBy_Lobby,
    ZAppOpenAppBy_Connect,
    ZAppOpenAppBy_OpenZappInvitation,
    ZAppOpenAppBy_OtherModule,
    ZAppOpenAppBy_RefreshAppToken,
    ZAppOpenAppBy_CollaborateMode,
    ZAppOpenApp_By_AuthorizeDone,
    ZAppOpenApp_By_PushApp,
    ZAppOpenApp_By_Faxsipit,
    ZAppOpenApp_By_ReLaunch,
    ZAppOpenApp_By_Web,
    ZAppOpenApp_By_RefreshAppForUI,
    ZAppOpenApp_By_Sidecar,
    ZAppOpenApp_By_Guest,
    ZAppOpenApp_By_Workspace,
    ZAppOpenApp_By_DigitalSignage,
    ZAppOpenApp_By_AutoOpen,
    ZAppOpenApp_By_ApiAuto,
    ZAppOpenApp_By_CollaborateSidecarMode,
};

typedef NS_ENUM(NSInteger, ZAppCloudRecordCmd) {
    ZAppCloudRecordCmd_None = -1,
    ZAppCloudRecordCmd_START = 0,
    ZAppCloudRecordCmd_STOP,
    ZAppCloudRecordCmd_PAUSE,
    ZAppCloudRecordCmd_RESUME
};

typedef NS_ENUM(NSInteger, ZAppRefreshSettingType) {
    ZAppRefreshSetting_None = -1,
    ZAppRefreshSetting_RemoveVB,
    ZAppRefreshSetting_SetBlur,
    ZAppRefreshSetting_SetMirror,
    ZAppRefreshSetting_SelectCamera,
    ZAppRefreshSetting_SetHDVideo,
    ZAppRefreshSetting_SetDisplayUsernames,
    ZAppRefreshSetting_SetAudioSettings,
    ZAppRefreshSetting_DeleteVideoFilter,
    ZAppRefreshSetting_SetOriginalRatio,
    ZAppRefreshSetting_SetEmojiReaction,
    ZAppRefreshSetting_AddVB,
    ZAppRefreshSetting_DeleteVB,
    ZAppRefreshSetting_DeleteCurrentVB,
    ZAppRefreshSetting_RefreshMirrorSetting,
    ZAppRefreshSetting_HideNonVideoParams,
};

typedef NS_ENUM(NSInteger, ZAppShareCmd) {
    ZAppShareCmd_None = -1,
    ZAppShareCmd_START = 0,
    ZAppShareCmd_STOP,
};

typedef NS_ENUM(NSInteger, ZAppShareSourceType) {
    ZAppShareSource_None = -1,
    ZAppShareSource_App = 0,
    ZAppShareSource_Pure_Audio,
};

typedef NS_ENUM(NSInteger, ZMZAppSendMenuType) {
    SendMenu_None = 0,
    SendMenu_All = 1 << 0,
    SendMenu_Participants = 1 << 1,
    SendMenu_Host = 1 << 2,
    SendMenu_Panelist = 1 << 3,
    SendMenu_Select_Panelist = 1 << 4,
    SendMenu_Select_Attendee = 1 << 5
};

typedef NS_ENUM(NSInteger, ZAppOpenAppAction) {
    ZAppOpenAppAction_NONE = 0,
    ZAppOpenAppAction_OPEN_APP,
    ZAppOpenAppAction_CLOSE_APP,
    ZAppOpenAppAction_CLOSE_ALL_APP,
    ZAppOpenAppAction_ADD_APP,
    ZAppOpenAppAction_OPEN_APP_DETAIL,
    ZAppOpenAppAction_OPEN_LABAPP,
    ZAppOpenAppAction_CLOSE_LABAPP,
    ZAppOpenAppAction_CLOSE_SIDECAR_APP,
};

typedef NS_ENUM(NSInteger, ZAppShareWindowLocation) {
    ZAppShareWindowLocation_Window = 0,
    ZAppShareWindowLocation_Window_Basic,
    ZAppShareWindowLocation_Window_Apps,
};

typedef NS_ENUM(NSInteger, ZAppJsCallErrorType) {
    ZAppJsCallError_Success = 0,
    ZAppJsCallError_General = 10001,
    ZAppJsCallError_Para_Format = 10002, //when parse paras from jscall
    ZAppJsCallError_Config_Denied = 10003, //when execute config
    ZAppJsCallError_Not_Authed = 10004, //when execute other jscall
    ZAppJsCallError_Auth_Info_Expired = 10005, //when execute other jscall
    ZAppJsCallError_Access_Server_Fail = 10006, //send req to web fail
    ZAppJsCallError_Not_In_A_Meeting = 10007,
    ZAppJsCallError_API_NOT_Exist = 10008,
    ZAppJsCallError_JSSDK_Verify_Fail = 10009,
    ZAppJsCallError_Get_Download_Path_Fail = 10010,
    ZAppJsCallError_DownLoad_File_Fail = 10011,
    ZAppJsCallError_Update_VirtualBackground_Fail = 10012,
    ZAppJsCallError_GetSupportedJsApis_Req_Fail = 10013,
    ZAppJsCallError_VB_DownLoad_Cancel_For_Timeout = 10014,
    ZAppJsCallError_OpenUrl_Req_Fail = 10015,
    ZAppJsCallError_Too_Many_Call_Pending = 10016,
    ZAppJsCallError_User_Not_Allow = 10017,
    ZAppJsCallError_Share_App_Fail = 10018,
    ZAppJsCallError_No_Such_Camera = 10019,
    ZAppJsCallError_Video_Status_Off = 10020,
    ZAppJsCallError_CloudRecording_Not_Allowed = 10021,
    ZAppJsCallError_Share_App_Disabled = 10022,
    ZAppJsCallError_Share_App_Started = 10023,
    ZAppJsCallError_Share_App_Not_Start = 10024,
    ZAppJsCallError_Invalid_CloudRecording_Action = 10025,
    ZAppJsCallError_Send_App_Invitation_Fail = 10026,
    ZAppJsCallError_Send_App_Invitation_NotAllowed = 10027,
    ZAppJsCallError_Send_App_Invitation_Over_Limit = 10028,
    ZAppJsCallError_Unsurppoted_VB_Format = 10029,
    ZAppJsCallError_Device_Not_Support_Set_VB = 10030,
    ZAppJsCallError_VB_Feature_Not_Enable = 10031,
    ZAppJsCallError_Cannot_Set_VB_In_Cur_Immersive_Scene = 10032,
    ZAppJsCallError_Client_Rate_Limit = 10033,
    ZAppJsCallError_Client_Api_Not_Config = 10034,
    ZAppJsCallError_Server_Rate_Limit = 10035,
    ZAppJsCallError_DownloadUrl_Not_In_WhiteDomainList = 10036,
    ZAppJsCallError_OpenCloseApp_Fail = 10037,
    ZAppJsCallError_PostMessageToConnectApp_Fail = 10038,
    ZAppJsCallError_ConnectApp_In_PT = 10039,
    ZAppJsCallError_LocalRecording_In_Progress = 10040,
    ZAppJsCallError_Not_ConnectedApp = 10041,
    ZAppJsCallError_Not_ShowNotification_For_DND = 10042,
    ZAppJsCallError_Current_Url_Not_Valid = 10043,
    ZAppJsCallError_VirtualBackground_Decode_Fail = 10044,
    ZAppJsCallError_Smart_VB_Package_NeedDownload = 10045,
    ZAppJsCallError_OnZoom_Screenshot_OverMaxSize = 10046,
    ZAppJsCallError_Client_Api_No_Permission = 10047,
    ZAppJsCallError_Allow_Participant_To_Record_Fail = 10048,
    ZAppJsCallError_Not_Get_Participant_Info = 10049,
    ZAppJsCallError_Has_Record_Permission_Already = 10050,
    ZAppJsCallError_Invalid_User = 10051,
    ZAppJsCallError_No_Need_Revoke_Permission = 10052,
    ZAppJsCallError_API_Only_Can_Use_After_Meeting_End = 10053,
    ZAppJsCallError_Client_Only_UseInPt = 10054,
    ZAppJsCallError_Local_Record_Feature_Disabled = 10055,
    ZAppJsCallError_Cannot_Set_VB_Video_Merged_On_Share = 10056,
    ZAppJsCallError_Can_Not_Remove_VB_In_ForceVB_mode = 10057,
    ZAppJsCallError_Client_StartOrJoinMeeting_Faild = 10058,
    ZAppJsCallError_HasOtherShareObj = 10059,
    ZAppJsCallError_Client_User_Confirmation_Dialog_Cancel = 10060,
    ZAppJsCallError_Need_Host_Permission = 10061,
    ZAppJsCallError_Action_Flushed_By_New_Action = 10064,
    ZAppJsCallError_Toggle_My_Audio_Fail = 10073,
    ZAppJsCallError_Toggle_My_Video_Fail = 10074,
    ZAppJsCallError_App_In_Collaborate = 10084,
    ZAppJsCallError_App_Not_In_Collaborate = 10085,
    ZAppJsCallError_User_Already_Join_Collaborate = 10086,
    ZAppJsCallError_User_Not_Join_In_Collaborate = 10087,
    ZAppJsCallError_User_Start_Collaborate_Can_Not_Leave = 10088,
    ZAppJsCallError_App_Cannot_Support_Collaborate = 10089,
    ZAppJsCallError_Current_View_Cannot_Switch = 10115,
    ZAppJsCallError_Share_Computer_Audio_Fail = 10131,
    ZAppJsCallError_Need_Stop_Other_Share_To_Start_Share = 10137,
    ZAppJsCallError_Meeting_Cannot_Invite = 10152,
    ZAppJsCallError_No_Ongoing_Share_By_This_User = 10189,
    ZAppJsCallError_Collaboration_In_Progress = 10190,
    ZAppJsCallError_Broadcast_Voice_To_BO = 10191,
    ZAppJsCallError_Stop_Broadcast_Voice_To_BO = 10192,
    ZAppJsCallError_Update_VideoFilter_Fail = 10196,
    ZAppJsCallError_Smart_VF_Package_NeedDownload = 10197,
    ZAppJsCallError_Video_Filter_Applied_Failed = 10199,
};

typedef NS_ENUM(NSInteger, ZAppVBAction) {
    ZAppVBAction_None = -1,
    ZAppVBAction_RemoveVB = 0,
    ZAppVBAction_SetBlur,
};

typedef NS_ENUM(NSInteger, ZAppUserActionType) {
    ZAppUserAction_Undefined = -1,
    ZAppUserAction_BackToMyApps = 0,
    ZAppUserAction_BackToDiscover,
    ZAppUserAction_GoToAppDetail
};

typedef NS_ENUM(NSInteger, ZAppVideoSettingsType) {
    ZAppVideoSettingsType_None = 0,
    ZAppVideoSettingsType_Turn_On_HD_Video,
    ZAppVideoSettingsType_Turn_Off_HD_Video,
    ZAppVideoSettingsType_Hide_Non_Video_Participants,
    ZAppVideoSettingsType_Show_Non_Video_Participants,
    ZAppVideoSettingsType_Hide_Participant_Names,
    ZAppVideoSettingsType_Show_Participant_Names,
    ZAppVideoSettingsType_Turn_On_MirrorMyVideo,
    ZAppVideoSettingsType_Turn_Off_MirrorMyVideo,
    ZAppVideoSettingsType_Save_Camera_DeviceId,
    ZAppVideoSettingsType_Turn_On_Original_Ratio,
    ZAppVideoSettingsType_Turn_Off_Original_Ratio,
};

typedef NS_ENUM(NSInteger, ZAppAudioSettingsType) {
    ZAppAudioSettingsType_None = 0,
    ZAppAudioSettingsType_Change_Speaker_Device,
    ZAppAudioSettingsType_Change_Output_Volume,
    ZAppAudioSettingsType_Change_Microphone_Device,
    ZAppAudioSettingsType_Zoom_Optimized_Audio,
    ZAppAudioSettingsType_Original_Sound,
    ZAppAudioSettingsType_Turn_On_Original_Sound,
    ZAppAudioSettingsType_Turn_Off_Original_Sound,
    ZAppAudioSettingsType_Background_Suppression_Auto,
    ZAppAudioSettingsType_Background_Suppression_Low,
    ZAppAudioSettingsType_Background_Suppression_Medium,
    ZAppAudioSettingsType_Background_Suppression_High,
    ZAppAudioSettingsType_LivePerformanceAudio,
    ZAppAudioSettingsType_AudioIsolation,
    ZAppAudioSettingsType_TurnOnHighFidelityMusic,
    ZAppAudioSettingsType_TurnOffHighFidelityMusic,
    ZAppAudioSettingsType_TurnOnEchoCancellation,
    ZAppAudioSettingsType_TurnOffEchoCancellation,
    ZAppAudioSettingsType_TurnOnStereo,
    ZAppAudioSettingsType_TurnOffStereo,
};

typedef NS_ENUM(NSInteger, ZAppClosePushAppType) {
    ZAppClosePushApp_All = 0,
    ZAppClosePushApp_All_ExceptMe,
    ZAppClosePushApp_Attendee,
};

typedef NS_ENUM(NSInteger, ZAppMeetingAttrType) {
    ZAppMeetingAttr_None = 0,
    ZAppMeetingAttr_Collaboration,
    ZAppMeetingAttr_Close_Collaboration,
    ZAppMeetingAttr_PushApp,
    ZAppMeetingAttr_Close_All_PushApp,
    ZAppMeetingAttr_Close_Attendee_PushApp,
    ZappMeetingAttr_Close_ExceptMe_PushApp,
};

typedef NS_ENUM(NSInteger, ZAppSetMeetingViewState) {
    ZAppSetMeetingViewState_None,
    ZAppSetMeetingViewState_True,
    ZAppSetMeetingViewState_False,
};

typedef NS_ENUM(NSInteger, ZAppMeetingViewType) {
    ZAppMeetingView_None = 0,
    ZAppMeetingView_Speaker,
    ZAppMeetingView_Gallery,
    ZAppMeetingView_Dynamic,
    ZAppMeetingView_ToggleFullScreen,
    ZAppMeetingView_EnterFullScreen,
    ZAppMeetingView_ExitFullScreen,
    ZAppMeetingView_FullScreen,
    ZAppMeetingView_NotFullScreen,
    ZAppMeetingView_Standard,
    ZAppMeetingView_SidebysideSpeaker,
    ZAppMeetingView_SidebysideGallery,
    ZAppMeetingView_SidebysideDynamic,
    ZAppMeetingView_SharingHighlight,
    ZAppMeetingView_VideoHighlight,
    ZAppMeetingView_Sharing_No_View,
    ZAppMeetingView_Immersive,
    ZAppMeetingView_Minimize,
    ZAppMeetingView_Webinar,
    ZAppMeetingView_DriveMode,
    ZAppMeetingView_ZappLayers,
    ZAppMeetingView_Presenting,
    ZAppMeetingView_FollowHostVideoOrder,
    ZAppMeetingView_UnFollowHostViewOrder,
};

typedef NS_ENUM(NSInteger, ZAppOpenAppMode) {
    ZAppOpen_Undefine = -1,
    ZAppOpen_Default = 0,
    ZAppOpen_Basic,
    ZAppOpen_Install,
    ZAppOpen_In_Client_Install,
    ZAppOpen_Auth_Code_Ready,
};

typedef NS_ENUM(NSInteger, ZAppOpenAppSource) {
    ZAppOpenAppSource_Launcher,
    ZAppOpenAppSource_Dock,
};

typedef NS_ENUM(NSInteger, ZAppZoomLevelTag) {
    kLevel_FitToWindow = 0,
    kLevel_50p,
    kLevel_100p,
    kLevel_150p,
    kLevel_200p,
    kLevel_300p,
};

typedef NS_ENUM(NSInteger, ZAppGetMeetingTokenPurpose) {
    ZAppMeetingToken_For_Undefine = 0,
    ZAppMeetingToken_For_OpenApp = 1,
    ZAppMeetingToken_For_LauncherToken = 2,
    ZAppMeetingToken_For_JoinPushApp = 3,
    ZAppMeetingToken_For_JoinCollaborate = 4,
    ZAppMeetingToken_For_RefreshAppToken = 5,
    ZAppMeetingToken_For_StartPushApp = 6,
    ZAppMeetingToken_For_EndPushApp = 7,
    ZAppMeetingToken_For_StartOrEndCollaborate = 8,
};

typedef NS_ENUM(NSInteger, ZAppCollaborateAction) {
    ZAppCollaborateAction_JsEvent_StartCollaborate,
    ZAppCollaborateAction_JsEvent_EndCollaborate,
    ZAppCollaborateAction_JsEvent_JoinCollaborate,
    ZAppCollaborateAction_JsEvent_LeaveCollaborate,
};

typedef NS_OPTIONS(NSUInteger, ZMZappExitCollaborateModeOptions) {
    ZMZappExitCollaborateModeOption_None = 0,
    ZMZappExitCollaborateModeOption_ExitCollaborateMode = 1 << 0,
    ZMZappExitCollaborateModeOption_SendEndRequest = 1 << 1,
    ZMZappExitCollaborateModeOption_StopCollaborateShare = 1 << 2,
    ZMZappExitCollaborateModeOption_RestoreZappView = 1 << 3,
    ZMZappExitCollaborateModeOption_ResetContentValue = 1 << 4,
    ZMZappExitCollaborateModeOption_All = ZMZappExitCollaborateModeOption_ExitCollaborateMode | ZMZappExitCollaborateModeOption_SendEndRequest
                                          | ZMZappExitCollaborateModeOption_StopCollaborateShare | ZMZappExitCollaborateModeOption_RestoreZappView
                                          | ZMZappExitCollaborateModeOption_ResetContentValue,
};

typedef NS_ENUM(NSUInteger, ZMZappCollaborateViewType) {
    ViewType_Button_Collaborate,
    ViewType_Popover_NewFeature,
    ViewType_Alert_Start_New_Collaboration,
    ViewType_Alert_Start_Collaboration_Failed_Of_Unknown_Reason,
    ViewType_Alert_Start_Collaboration_Failed_Of_Launch_Policy,
    ViewType_Alert_Start_Collaboration_Failed_Of_Change_Policy,
    ViewType_Tip_Conf_Join_Collaborate,
    ViewType_Toast_Join_Collaborate,
    ViewType_Tip_Conf_Join_Collaborate_BO_Master,
    ViewType_Toast_Join_Collaborate_BO_Master,
    ViewType_Alert_Collaborate_Ended,
    ViewType_Alert_Collaborate_Ended_BO_Master,
    ViewType_Button_End_Collaborate,
    ViewType_Button_Leave_Collaborate,
    ViewType_Label_Collaborating,
    ViewType_Alert_Ask_Host_Start_Collaborate,
    ViewType_Alert_End_Collaboration,
    ViewType_Alert_Change_2_Share_From_Collaborate,
    ViewType_Alert_End_Collaborate_2_Revoke_Cohost,
    ViewType_Alert_End_Collaborate_2_Make_Host,
    ViewType_Alert_End_Collaborate_For_Everyone,
    ViewType_Alert_End_Collaborate_For_Everyone_Close_All,
    ViewType_Toast_Or_Alert_Collaborate_App_Not_Found,
    ViewType_Toast_Or_Alert_Start_Collaboration_Failed_Of_Rate_Limit,
    ViewType_Toast_Or_Alert_End_Collaborate_Fail_Of_Auth,
    ViewType_Alert_Collaborate_Could_Not_Be_Started,
    ViewType_Alert_Collaborate_Could_Not_Be_Ended,
    ViewType_Cosent_Dialog_Start_Collaborate,
    ViewType_Cosent_Dialog_End_Collaborate,
    ViewType_Cosent_Dialog_Join_Collaborate,
    ViewType_Cosent_Dialog_Leave_Collaborate,
    ViewType_Toast_Get_Meeting_Token_Fail_Join_Collaborate,
    ViewType_Toast_Get_Meeting_Token_Fail_Start_Or_End_Collaborate,
    ViewType_Alert_Change_2_Share_PureAudio_From_Collaborate,
};

typedef NS_ENUM(NSInteger, ZMZappFeatureName) {
    ZMZappFeatureName_None = 0,
    ZMZappFeatureName_Apps,
    ZMZappFeatureName_Share_Screen_Apps,
};

typedef NS_OPTIONS(NSUInteger, ZMZAppCacheDataModule) {
    ZMZAppCacheDataModuleNone = 0,
    ZMZAppCacheDataModuleKeepApps = 1 << 0,
    ZMZAppCacheDataModuleTakeSnap = 1 << 1,
};

extern NSString *const kCollaborateViewTitle;
extern NSString *const kCollaborateViewInformation;
extern NSString *const kCollaborateViewInformation_optional;
extern NSString *const kCollaborateViewDefaultButtonTitle;
extern NSString *const kCollaborateViewDefaultButtonStyle;
extern NSString *const kCollaborateViewSecondaryButtonTitle;
extern NSString *const kCollaborateViewToolTip;
extern NSString *const kCollaborateViewToolTip_Disable;
extern NSString *const kMail_ZMDFScheme;
extern NSString *const kMail_ZMDFSchemeQueryMailID;
extern NSString *const kMail_ZMDFSchemeAttachID;
extern NSString *const kMailScriptHandlerName;

typedef NS_ENUM(NSInteger, ZAppToastLinkType) {
    ZappToastLink_Undefine = -1,
    ZappToastLink_Detail = 0,
    ZappToastLink_Permission,
    ZappToastLink_Terms,
    ZappToastLink_Privacy,
    ZappToastLink_GuestModeLimit,
    ZappToastLink_LearnMoreLimitedApp,
    ZappToastLink_HelpDisableApp,
};

typedef NS_ENUM(NSInteger, ZAppPreapprovalState) {
    ZappApprovalState_None,
    ZappApprovalState_Approval,
    ZappApprovalState_Not_Approval,
};

typedef NS_ENUM(NSInteger, ZAppErrorWebViewType) {
    ZappErrorWebViewType_None,
    ZappErrorWebViewType_App,
    ZappErrorWebViewType_Auth,
};

typedef NS_ENUM(NSUInteger, ZMZAppInstallState) {
    ZappInstallState_Unknown = 0,
    ZappInstallState_Installed,
    ZappInstallState_Not_Installed,
    ZappInstallState_Disable,
};

typedef NS_ENUM(NSUInteger, ZMZAppOpenedState) {
    ZappOpenedState_None = 0,
    ZappOpenedState_Opened = 1,
    ZappOpenedState_Used = 2,
};

typedef NS_ENUM(NSUInteger, ZMZappStartCollaborateErrorCodeType) {
    ZMZappStartCollaborateErrorCode_Unknown = 0,
    ZMZappStartCollaborateErrorCode_Block_By_Launch_Policy,
    ZMZappStartCollaborateErrorCode_Block_By_Change_Policy,
};

typedef NS_ENUM(NSUInteger, ZMZAppCollaborateLaunchPolicyType) {
    ZMZAppCollaborateLaunchPolicy_Anyone = 0, //the default policy
    ZMZAppCollaborateLaunchPolicy_Host_Only = 1,
};
typedef NS_ENUM(NSUInteger, ZMZAppCollaborateChangePolicyType) {
    ZMZAppCollaborateChangePolicy_Host_Only = 0, //the default policy
    ZMZAppCollaborateChangePolicy_Anyone = 1,
};
//how to clean the running collaboration when the owner leave meeting
typedef NS_ENUM(NSUInteger, ZMZAppCollaborateCleanPolicyType) {
    ZMZAppCollaborateCleanPolicy_Clean_Content_Only = 0, //the default policy
    ZMZAppCollaborateCleanPolicy_Clean_All = 1,
    ZMZAppCollaborateCleanPolicy_Not_Clean = 2,
};

typedef NS_ENUM(NSUInteger, ZMZappConfSessionType) {
    ZMZappConfSession_Default = 0,
    ZMZappConfSession_BoMaster,
};

typedef NS_ENUM(NSUInteger, ZMZappCollaborateInvitationStyle) {
    ZMZappCollaborateInvitation_Toast = 0,
    ZMZappCollaborateInvitation_Conf_Tip,
};

typedef NS_ENUM(NSUInteger, ZMZAppSupportBasicState) {
    ZappInvitationToast_Unknown = 0,
    ZappInvitationToast_Basic,
    ZappInvitationToast_Not_Support_Basic,
    ZappInvitationToast_Installed,
    ZappInvitationToast_Op_Disable,
};

typedef NS_ENUM(NSInteger, ZMZAppPromptShareStatusCode) {
    ZMZAppPromptShareSuccess = 0,
    ZMZAppPromptShare_Stop_Other_Share,
    ZMZAppPromptShare_Failed,
    ZMZAppPromptShare_BrowserNotSupport,
};

typedef NS_ENUM(NSUInteger, SpotsBubbleActionType)
{
    ZMSpot_Action_None = 0,
    ZMSpot_Joined,
    ZMSpot_Left,
    ZMSpotBubble_Created,
    ZMSpotBubble_Deleted,
    ZMSpotBubble_Renamed,
    ZMSpotBubble_Joined,
    ZMSpotBubble_Left,
};

typedef NS_ENUM(NSInteger, ZMZAppTimerCountOrder) {
    ZMZAppTimerCountOrder_None = 0,
    ZMZAppTimerCountOrder_Up,
    ZMZAppTimerCountOrder_Down,
};

typedef NS_ENUM(NSInteger, ZMZAppTimerOperation) {
    ZMZAppTimerOperation_Unknown = 0,
    ZMZAppTimerOperation_Start,
    ZMZAppTimerOperation_Pause,
    ZMZAppTimerOperation_Resume,
    ZMZAppTimerOperation_End,
    ZMZAppTimerOperation_Destroy,
};

typedef NS_ENUM(NSUInteger, ZMDynamicIndicatorTextStyle)
{
    ZMDynamicIndicatorTextStyle_default = 0,
    ZMDynamicIndicatorTextStyle_bold,
    ZMDynamicIndicatorTextStyle_italic,
};

typedef NS_ENUM(NSUInteger, ZMDynamicIndicatorIconType)
{
    ZMDynamicIndicatorIconType_default = 0,
    ZMDynamicIndicatorIconType_other,
};

typedef NS_ENUM(NSUInteger, ZMZAppOpenInZRErrorCode)
{
    ZMZAppOpenInZRErrorCode_Success = 0,
    ZMZAppOpenInZRErrorCode_ZRVersionNotSupport,
    ZMZAppOpenInZRErrorCode_NotInSameMeeting,
    ZMZAppOpenInZRErrorCode_DismissOpen,
};

typedef NS_ENUM(NSInteger, ZMSpotLightAlertAction) {
    ZMSpotLightAlertActionContinue = 0,
    ZMSpotLightAlertActionCancel,
    ZMSpotLightAlertActionDestroy,
};

typedef NS_ENUM(NSUInteger, ZMZAppMenuTag) {
    ZMZAppMenuTag_CopyLink = 1,
    ZMZAppMenuTag_AutoOpen = 2,
    ZMZAppMenuTag_AppDetail = 3,
    ZMZAppMenuTag_ManageApp = 4,
    ZMZAppMenuTag_CloseApp = 5,
    ZMZAppMenuTag_ShareApp = 6,
};

typedef NS_ENUM(NSUInteger, ZMZAppErrorViewType) {
    ZMZAppErrorViewTypeRestart,
    ZMZAppErrorViewTypeLoadingFailed,
    ZMZAppErrorViewTypeForceUpdate,
    ZMZAppErrorViewTypeE2E,
    ZMZAppErrorViewTypeNotSignIn,
    ZMZAppErrorViewTypeUnknown,
    ZMZAppErrorViewTypeUpgradeOS,
    ZMZAppErrorViewTypeDifferentMeeting,
    ZMZAppErrorViewTypeMismatch,
};

typedef NS_ENUM(NSUInteger, ZMZappUIAction) {
    ZMZappUIAction_None = 0,
    ZMZappUIAction_AppPopout = 1,
    ZMZappUIAction_AppMergeBackToMainWindow,
    ZMZappUIAction_BringAppToFront,
    ZMZappUIAction_SendAppToBackground,
    ZMZappUIAction_CloseApp,
};

typedef NS_ENUM(NSUInteger, ZMZappUIActionResult) {
    ZMZappUIActionResult_Success = 0,
    ZMZappUIActionResult_Fail,
    ZMZappUIActionResult_Cant_Execute,
    ZMZappUIActionResult_Already_Undocked,
    ZMZappUIActionResult_Already_Docked,
    ZMZappUIActionResult_Already_Front,
    ZMZappUIActionResult_Already_Background
};

typedef NS_ENUM(NSUInteger, ZMHuddlesMeetingWindowState) {
	ZMHuddlesMeetingWindowState_Active,
	ZMHuddlesMeetingWindowState_Deactive,
	ZMHuddlesMeetingWindowState_Close,
};

typedef NS_ENUM(NSUInteger, ZMZAppToastViewFrom) {
    ZMZAppToastViewFromNone,
    ZMZAppToastViewFromSendApp,
    ZMZAppToastViewFromMTChat,
    ZMZAppToastViewFromShareVB,
};

typedef NS_ENUM(NSUInteger, ZMZAppInvitationAlertType) {
    ZMZAppInvitationAlertType_SendApp,
    ZMZAppInvitationAlertType_ShareVB,
};

typedef NS_ENUM(NSInteger, ZMLocalShareDrawScreenScalingType) {
	ZMLocalShareDrawScreenScalingType_Fit,
	ZMLocalShareDrawScreenScalingType_Fill,
};

typedef NS_ENUM(NSInteger, ZMLocalShareChangeType) {
	ZMLocalShareChangeType_None = 0,
	ZMLocalShareChangeType_StartLocalShare = 11,
	ZMLocalShareChangeType_StopLocalShare,
};

typedef NS_ENUM(NSInteger, ZMAppLocation) {
    ZMAppLocation_None = 0,
    ZMAppLocation_Launcher,
    ZMAppLocation_SettingVB,
    ZMAppLocation_ScreenShare_GoogleDrive,
    ZMAppLocation_ScreenShare_MicrosoftOneDrive,
    ZMAppLocation_ScreenShare_MicrosoftSharePoint,
    ZMAppLocation_Mail_Message,
    ZMAppLocation_Mail_Thread,
    ZMAppLocation_TeamChat_GoogleDrive,
    ZMAppLocation_TeamChat_MicrosoftOneDrive,
    ZMAppLocation_TeamChat_MicrosoftSharePoint,
    ZMAppLocation_MeetingChat_GoogleDrive,
    ZMAppLocation_MeetingChat_MicrosoftOneDrive,
    ZMAppLocation_MeetingChat_MicrosoftSharePoint,
    ZMAppLocation_ScreenShare_Box,
    ZMAppLocation_TeamChat_TeamChat_Box,
    ZMAppLocation_MeetingChat_MeetingChat_Box,
    ZMAppLocation_TeamChat_ChannelTab,
    ZMAppLocation_TeamChat_NewTab,
    ZMAppLocation_Fax_GoogleDrive,
    ZMAppLocation_Fax_MicrosoftOneDrive,
    ZMAppLocation_Fax_MicrosoftSharePoint,
    ZMAppLocation_Fax_Box,
};

typedef NS_ENUM(NSInteger, HeaderLayoutMode) {
    HeaderLayoutMode_None = 0,
    HeaderLayoutMode_PT = 1<<0,
    HeaderLayoutMode_Meeting = 1<<1,
    HeaderLayoutMode_GuestMode = 1<<2,
    HeaderLayoutMode_Popout = 1<<3,
    HeaderLayoutMode_Phone = 1<<4,
    HeaderLayoutMode_Phone_launch = 1<<5,
    HeaderLayoutMode_SideCar = 1<<6,
    HeaderLayoutMode_Labs = 1<<7,
};

typedef NS_ENUM(NSUInteger, ZMAppGuestModeType) {
    ZMAppGuestMode_None = 100,
    ZMAppGuestMode_AddApp,
    ZMAppGuestMode_SignIn,
};

typedef NS_ENUM(NSUInteger, ZMMTAppTimerBtnType) {
    ZMMTAppTimerBtnType_TopBar = 0,
    ZMMTAppTimerBtnType_FitBar,
    ZMMTAppTimerBtnType_Menu,
};

typedef NS_ENUM(NSUInteger, ZMMTAppRTMSPermission) {
    ZMMTAppRTMSPermission_AllEnabled = 0,
    ZMMTAppRTMSPermission_ApprovalRequired,
    ZMMTAppRTMSPermission_AllDisabled,
};

typedef NS_OPTIONS(NSInteger, ZMZappRTMSPermissionTypeOptions) {
    ZMZappRTMSPermissionTypeOption_Audio = 1 << 0,
    ZMZappRTMSPermissionTypeOption_Video = 1 << 1,
    ZMZappRTMSPermissionTypeOption_Transcript = 1 << 2,
    ZMZappRTMSPermissionTypeOption_ScreenShare = 1 << 3,
    ZMZappRTMSPermissionTypeOption_Chat = 1 << 4,
};

typedef NS_ENUM(NSInteger, ZMZappRTMSStatus) {
    ZMZappRTMSStatus_None,
    ZMZappRTMSStatus_Requesting,
    ZMZappRTMSStatus_Connecting,
    ZMZappRTMSStatus_ConnectFail,
    ZMZappRTMSStatus_Active,
    ZMZappRTMSStatus_ActiveByAdmin,
    ZMZappRTMSStatus_ActiveRecording,
    ZMZappRTMSStatus_ActiveLiveStream,
    ZMZappRTMSStatus_LockedByAdmin,
    ZMZappRTMSStatus_Deny,
    ZMZappRTMSStatus_DisableByHost,
    ZMZappRTMSStatus_DisableByAdmin,
    ZMZappRTMSStatus_Enable,
    ZMZappRTMSStatus_Stop,
    ZMZappRTMSStatus_Paused,
    ZMZappRTMSStatus_RemoveByHost,
    ZMZappRTMSStatus_RemoveByUser,
    ZMZappRTMSStatus_SDKReady,
    ZMZappRTMSStatus_LiveStreamReady,
};

typedef NS_ENUM(NSInteger, ZMZappRTMSAppType) {
    ZMZappRTMSAppType_None,
    ZMZappRTMSAppType_Rtms,
    ZMZappRTMSAppType_LiveStream,
    ZMZappRTMSAppType_Sdk,
};

typedef NS_ENUM(NSInteger, ZMZappRTMSAction) {
    ZMZappRTMSAction_None,
    ZMZappRTMSAction_Disable,
    ZMZappRTMSAction_Enable,
    ZMZappRTMSAction_Stop,
    ZMZappRTMSAction_Pause,
    ZMZappRTMSAction_Resume,
    ZMZappRTMSAction_Start,
    ZMZappRTMSAction_ReStart,
    ZMZappRTMSAction_Remove,
};

typedef NS_ENUM(NSInteger, ZMZappRTMSErrorToastType) {
    ZMZappRTMSErrorToastType_None,
    ZMZappRTMSErrorToastType_HostNotInMeeting,
    ZMZappRTMSErrorToastType_HostNotSupportRtms,
    ZMZappRTMSErrorToastType_AllAppDisable,
    ZMZappRTMSErrorToastType_AllAppDisableAutoStart,
    ZMZappRTMSErrorToastType_NoAvaliableRtmsZone,
    ZMZappRTMSErrorToastType_RtmsAppSettingNotEnable,
    ZMZappRTMSErrorToastType_NormalRtmsConnectingFail,
};

typedef NS_ENUM(NSUInteger, ZMZappOpenSettingType) {
    ZMZappOpenSettingType_Default,
    ZMZappOpenSettingType_Audio,
};

@protocol ZMZappHelperProtocol <NSObject>
@property (nonatomic, assign) BOOL restoreAppStatus;

- (NSString *)getVBAppId;
- (void)restoreMirrorAppsIfNeeded;
- (void)cleanAllMirrorAppsInPT;
- (NSArray *)getAllConnectedZApp;
@end

@interface ZPZAppHeader : NSObject
@property (nonatomic, copy, nullable) NSString *appid;
@property (nonatomic, copy, nullable) NSString *iconPath;
@property (nonatomic, copy, nullable) NSString *name;
@property (nonatomic, assign) BOOL isBetaApp;
@property (nonatomic, copy, nullable) NSString *appCompanyName;
@property (nonatomic, assign) BOOL isInstall;
@end

@interface ZMZappContext : NSObject
@property (nonatomic, copy, nullable) NSString *installUrl;
@property (nonatomic, copy, nullable) NSString *appId;
@property (nonatomic, copy, nullable) NSString *homeUrl;
@property (nonatomic, copy, nullable) NSString *displayName;
@property (nonatomic, strong, nullable) NSDictionary *headerDict;
@property (nonatomic, assign) BOOL isDraftApp;
@property (nonatomic, assign) BOOL isAppDisabled;
@property (nonatomic, assign) ZAppOpenAppPurpose openAppPurpose;
@property (nonatomic, assign) BOOL showHomePage;
@property (nonatomic, assign) BOOL shareCookie;
@property (nonatomic, copy, nullable) NSString *launchTrackingId;
@property (nonatomic, copy, nullable) NSString *refreshUrl;
@property (nonatomic, assign) ZAppOpenAppMode openAppMode;
@property (nonatomic, assign) NSInteger errorCode;
@property (nonatomic, copy, nullable) NSString *invitationUUID;
@property (nonatomic, assign) BOOL isBetaApp;
@property (nonatomic, assign) ZAppPreapprovalState approvalState;
@property (nonatomic, copy, nullable) NSString *trackingId;

@property (nonatomic, copy, nullable) NSString *appResourcePath;
@property (nonatomic, copy, nullable) NSString *appResourceIndexFileName;
@property (nonatomic, copy, nullable) NSString *appResourceHashRoute;
@property (nonatomic, assign) BOOL needDecompress;

@property (nonatomic, assign) NSInteger httpRetCode;
@property (nonatomic, copy, nullable) NSString *cdnHtmlURL;
@property (nonatomic, copy) NSString *action;
@property (nonatomic, copy) NSString *marketplaceErrorMsg;

@end

@interface ZMZAppSetMeetingViewInfo: NSObject
@property (nonatomic, assign) ZAppSetMeetingViewState setFullScreen;
@property (nonatomic, assign) ZAppSetMeetingViewState setFollowHostOrder;
@property (nonatomic, assign) ZAppMeetingViewType meetingViewType;
@end

@interface ZMZAppAuthInfo : NSObject
@property (nonatomic, copy, nullable) NSString *appId;
@property (nonatomic, assign) ZAppOpenAppMode launchMode;
@property (nonatomic, copy, nullable) NSString *installUrl;
@end

@interface ZMZAppAuthorizeResult : NSObject
@property (nonatomic, copy, nullable) NSString *appId;
@property (nonatomic, copy, nullable) NSString *reason;
@property (nonatomic, copy, nullable) NSString *authCode;
@property (nonatomic, copy, nullable) NSString *state;
@property (nonatomic, assign) BOOL result;
@end

@interface ZMZAppParticipantInfo : NSObject
@property (nonatomic, assign) NSUInteger userId;
@property (nonatomic, copy, nullable) NSString *userName;
@property (nonatomic, strong, nullable) NSImage *avatarImage;
@end

@protocol ZMMTZappPluginModel <NSObject>
@property (nonatomic, assign) ZMMTZappPluginModelType type;
@property (nonatomic, copy, nullable) NSString *zAppID;
@property (nonatomic, assign) NSUInteger userID;
@property (nonatomic, assign) NSInteger zIndex;
@property (nonatomic, assign) BOOL animation;
@property (nonatomic, assign) CFTimeInterval duration;
@property (nonatomic, assign) NSRect designRect;
@property (nonatomic, assign) NSRect oldRect;
@property (nonatomic, assign) NSInteger radius;
@property (nonatomic, assign) BOOL showName;
@property (nonatomic, assign) BOOL showMuteIcon;
@property (nonatomic, assign) BOOL showNoAudioIcon;
@property (nonatomic, assign) BOOL showTalking;

- (NSString *)getIdentifier;
- (NSRect)getRealRect;
@end

@interface ZMZappLayersParticipant : NSObject <ZMMTZappPluginModel>
@property (nonatomic, assign) ZMZappLayersCutoutType cutoutType;

- (instancetype)initWithUserID:(UInt32)userID
                        zAppID:(NSString *)zAppID
                        zIndex:(NSInteger)zIndex
                          rect:(NSRect)rect
                    cutoutType:(ZMZappLayersCutoutType)cutoutType;

- (instancetype)initWithUserID:(UInt32)userID
                        zAppID:(NSString *)zAppID
                        zIndex:(NSInteger)zIndex
                          rect:(NSRect)rect
                    cutoutType:(ZMZappLayersCutoutType)cutoutType
                       oldRect:(NSRect)oldRect
                      duration:(CFTimeInterval)duration
                     animation:(BOOL)animation
                        radius:(NSInteger)radius;
@end

@interface ZMZappLayersImage : NSObject <ZMMTZappPluginModel>
@property (nonatomic, strong, nullable) NSImage *image;
@property (nonatomic, strong, nullable) NSString *imageID;

- (instancetype _Nonnull)initWithImageID:(NSString *_Nonnull)imageID
                                   image:(NSImage *_Nonnull)image
                                  zAppID:(NSString *_Nonnull)zAppID
                                  zIndex:(NSInteger)zIndex
                                    rect:(NSRect)rect;
@end

@interface ZMZappDownloadParam : NSObject

@property (nonatomic, assign) NSUInteger senderId;
@property (nonatomic, copy) NSString *downloadUrl;
@property (nonatomic, assign) NSUInteger alg;
@property (nonatomic, assign) NSUInteger generateKey;

@end

@interface ZMZappConfShareConfigure : NSObject

@property (nonatomic, copy, nullable) NSString *appId;
@property (nonatomic, copy, nullable) NSString *appName;
@property (nonatomic, copy, nullable) NSString *iconPath;
@property (nonatomic, copy, nullable) NSString *messageText;
@property (nonatomic, copy, nullable) NSString *primaryButtonText;
@property (nonatomic, copy, nullable) NSString *secondaryButtonText;
@property (nonatomic, copy, nullable) NSString *htmlPageTitle;
@property (nonatomic, copy, nullable) NSString *deeplinkURL;
@property (nonatomic, assign) BOOL isValid;
@property (nonatomic, copy, nullable) NSString *dialogHeading;
@property (nonatomic, copy, nullable) NSString *dialogButtonText;
@property (nonatomic, copy, nullable) NSString *imagePath; //The original image of the thumbnail
@property (nonatomic, copy, nullable) NSString *thumbnailPath;
@property (nonatomic, strong, nullable) ZMZappDownloadParam *downloadParam;
@property (nonatomic, copy, nullable) NSString *msgId;

@end

@interface ZMZAppConfShareInfo : NSObject

@property (nonatomic, copy, nullable) NSString *appID;
@property (nonatomic, copy, nullable) NSString *shareURL;
@property (nonatomic, copy, nullable) NSString *displayName;
@property (nonatomic, copy, nullable) NSString *invitationUUID;
@property (nonatomic, copy, nullable) NSString *maketplaceUrl;
@property (nonatomic, assign) BOOL isFromJs;
@property (nonatomic, assign) BOOL isInImmersiveMode;
@property (nonatomic, assign) ZMZappLayersCutoutType cutoutType;
@property (nonatomic, strong, nullable) ZMZappConfShareConfigure *configure;
@property (nonatomic, assign) ZMZAppToastViewFrom dataFrom;

- (BOOL)isVaild;

@end

@interface ZMZAppFilePickerInfo : NSObject

@property (nonatomic, copy, nullable) NSString *docTypeName;
@property (nonatomic, copy, nullable) NSString *docFileName;
@property (nonatomic, copy, nullable) NSString *detailDesc;

@end

typedef void (^ZMZAppToastConfirmBlock)(void);
@interface ZMZAppToastInfo : NSObject

@property (nonatomic, copy, nullable) NSString *appId;
@property (nonatomic, copy, nullable) NSString *appName;
@property (nonatomic, strong, nullable) NSImage *thumbnailImg;
@property (nonatomic, strong, nullable) NSImage *appIcon;
@property (nonatomic, copy, nullable) NSString *sentFrom;
@property (nonatomic, strong, nullable) ZMZAppConfShareInfo *shareInfo;
@property (nonatomic, strong, nullable) ZMZAppFilePickerInfo *filePickerInfo;

@property (nonatomic, copy, nullable) NSString *appCompanyName;
@property (nonatomic, copy, nullable) NSString *customPolicyText;
@property (nonatomic, strong, nullable) NSImage *betaIcon;
@property (nonatomic, assign) BOOL needUpdateIfNeed;
@property (nonatomic, assign) BOOL isSender;
@property (nonatomic, copy, nullable) ZMZAppToastConfirmBlock confirmBlock;
- (BOOL)isNeedCustomUI;

@end

@interface ZMZAppInstallInfo : NSObject

@property (nonatomic, assign) ZMZAppSupportBasicState supportBasicState;
@property (nonatomic, assign) ZMZAppInstallState installState;

@end

@interface ZMZAppCollaborateData : NSObject
@property (nonatomic, assign) ZMZAppCollaborateLaunchPolicyType launchPolicy;
@property (nonatomic, assign) ZMZAppCollaborateChangePolicyType changePolicy;
@property (nonatomic, assign) ZMZAppCollaborateCleanPolicyType cleanPolicy;
@property (nonatomic, copy, nullable) NSString *appId;
@property (nonatomic, assign) NSUInteger actorId; // who update the content or policy latest
@property (nonatomic, assign) NSUInteger contentActorId; // who update the content latest
@property (nonatomic, assign) NSUInteger appFeature;
@property (nonatomic, assign) ZMZappConfSessionType sessionType;
@end

@protocol ZMZappNotificationDelegate <NSObject>
@optional
- (void)onDefaultButtonClicked;
- (void)onSecondaryButtonClicked;
@end

@interface ZMZAppCollaborateInvitation : NSObject <ZMZappNotificationDelegate>

@property (nonatomic, assign) BOOL isInvitationClicked;
@property (nonatomic, assign) ZMZappCollaborateInvitationStyle style;
@property (nonatomic, copy, nullable) NSString *collaborateAppId;
@property (nonatomic, assign) NSUInteger contentActorId;
@property (nonatomic, assign) ZMZappConfSessionType sessionType;

- (void)resetInvitation;
- (BOOL)isSameCollaboration:(nullable ZMZAppCollaborateData *)collaborateData;

@end

@interface ZMZAppsInteractInfo : NSObject

@property (nonatomic, assign) NSUInteger eventSource;
@property (nonatomic, assign) NSUInteger eventLocation;
@property (nonatomic, assign) NSUInteger eventType;
@property (nonatomic, assign) NSUInteger eventName;
@property (nonatomic, assign) NSUInteger featureName;
@property (nonatomic, copy, nullable) NSString *eventContext;
@property (nonatomic, copy, nullable) NSString *appId;
@property (nonatomic, copy, nullable) NSString *launchTrackingId;
@property (nonatomic, copy, nullable) NSString *appCategory;

@end

@interface ZMZAppVideoSettingsTypes : NSObject

@property (nonatomic, assign) ZAppVideoSettingsType videoSettingsType;

@end

@interface ZMZAppAudioSettingsTypes : NSObject

@property (nonatomic, assign) ZAppAudioSettingsType audioSettingsType;

@end

@interface ZMZAppDrawParticipantInfo : NSObject

@property (nonatomic, assign) UInt32 participantId;
@property (nonatomic, assign) NSRect rect;
@property (nonatomic, assign) NSInteger zIndex;
@property (nonatomic, assign) BOOL mirrorVideo;
@property (nonatomic, assign) ZMZappLayersCutoutType cutoutType;

@end

@interface ZMZAppOpenActionInfo : NSObject

@property (nonatomic, copy, nullable) NSString *appId;
@property (nonatomic, copy, nullable) NSString *appName;
@property (nonatomic, assign) BOOL supportTransferZR;

@property (nonatomic, assign) ZAppOpenAppPurpose openPurpose;
@property (nonatomic, assign) ZAppOpenAppAction openAction;
@property (nonatomic, assign) ZAppOpenAppSource openSource;

@end

@interface ZMZAppDockAppTooltipInfo : NSObject

@property (nonatomic, copy, nullable) NSString *appId;
@property (nonatomic, copy, nullable) NSString *appName;
@property (nonatomic, copy, nullable) NSString *appDescription;
@property (nonatomic, assign) BOOL isShowTip;
@property (nonatomic, assign) NSInteger posY;

@end

@interface ZMZAppShareScreenInfo : NSObject

@property (nonatomic, assign) BOOL zappEnableAudioShare;
@property (nonatomic, assign) BOOL zappEnableVideoShare;
@property (nonatomic, assign) BOOL zappEnableBoShare;
@property (nonatomic, assign) BOOL zappEnableLocalShare;
@end

@interface ZMZAppDynamicIndicatorInfo : NSObject

@property (nonatomic, copy, nullable) NSString *text;
@property (nonatomic, copy, nullable) NSString *textColor;
@property (nonatomic, copy, nullable) NSString *borderColor;
@property (nonatomic, copy, nullable) NSString *backgroundColor;
@property (nonatomic, copy, nullable) NSString *appName;
@property (nonatomic, copy, nullable) NSString *appIconPath;
@property (nonatomic, assign) NSUInteger timeSync;
@property (nonatomic, assign) NSUInteger senderTime;
@property (nonatomic, copy, nullable) NSString *appId;
@property (nonatomic, assign) NSUInteger senderNodeId;
@property (nonatomic, assign) NSUInteger pauseTime;
@property (nonatomic, assign) ZMZAppTimerCountOrder order;
@property (nonatomic, assign) BOOL playSound;
@property (nonatomic, assign) BOOL showNotification;
@property (nonatomic, assign) BOOL countNegativeAfterAlarm;
@property (nonatomic, assign) ZMZAppTimerOperation operation;
@property (nonatomic, assign) ZMDynamicIndicatorTextStyle textType;
@property (nonatomic, assign) NSUInteger songIndex;
@end

@interface ZMSpotsPopoutChatInfo : NSObject

@property (nonatomic, assign) NSUInteger width;
@property (nonatomic, assign) NSUInteger height;
@property (nonatomic, assign) NSInteger top;
@property (nonatomic, assign) NSInteger left;

@end

@interface ZMZJsMenuInfo : NSObject

@property (nonatomic, copy) NSArray<NSNumber *> *menuTags;
@property (nonatomic, copy) NSString *appId;
@property (nonatomic, copy) NSString *appName;
@property (nonatomic, assign) NSPoint position;
@property (nonatomic, assign) ZMAppType appType;
@property (nonatomic, copy) NSString *appShareLink;
@property (nonatomic, copy) NSString *webviewId;
@property (nonatomic, copy) NSString *appManageLink;

@end

@interface ZMLocalShareDrawScreenInfo : NSObject

@property (nonatomic, assign) NSRect rect;
@property (nonatomic, assign) NSInteger zIndex;
@property (nonatomic, assign) NSInteger radius;
@property (nonatomic, assign) ZMLocalShareDrawScreenScalingType scalingType;

@end

@interface ZMGetCurrentShareInfo : NSObject

@property (nonatomic, assign) NSInteger screenShareCount;
@property (nonatomic, assign) NSInteger whiteboardCount;
@property (nonatomic, assign) NSInteger audioShareCount;

@end

typedef NS_ENUM(NSInteger, ZMOpenChatAppSrc) {
    ZMOpenChatAppByDefault = 0,
    ZMOpenChatAppByShortcutInMessage,
    ZMOpenChatAppByShortcutInCompose,
    ZMOpenChatAppByActionInBotMessage,
    ZMOpenChatAppBySlashCommand,
    ZMOpenChatAppByDocumentPreview,
    ZMOpenChatAppByShortcutInThread,
    ZMOpenChatAppByHoverLinkInMessage,
    ZMOpenChatAppByHoverLinkInCompose,
    ZMOpenChatAppByChatTab,
    ZMOpenChatAppByChatTabPicker,
};

typedef NS_OPTIONS(NSInteger, ZMSupportedFileTypeOption) {
    ZMSupportedFileTypeOption_None,
    ZMSupportedFileTypeOption_PDF = (1 << 0),
};

@interface ZMAppContextParam : NSObject

@property (nonatomic, copy) NSString *targetURL;
@property (nonatomic, copy) NSString *meetingNumber;
@property (nonatomic, assign) ZAppOpenAppPurpose openPurpose;
@property (nonatomic, assign) ZMOpenChatAppSrc openSrc;
@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *sessionId;
@property (nonatomic, copy) NSString *messageId;
@property (nonatomic, copy) NSString *threadId;
@property (nonatomic, copy) NSString *actionId;
@property (nonatomic, copy) NSString *action;
@property (nonatomic, assign) BOOL isInternalApp;
@property (nonatomic, copy) NSString *allowedDomainListStr;
@property (nonatomic, assign) NSInteger featureOptions;
@property (nonatomic, copy) NSString *smsSessionInfo;
@property (nonatomic, copy) NSString *appResourceHashRoute;
@property (nonatomic, copy) NSString *ccQueueId;
@property (nonatomic, copy) NSString *hoverLink;
@property (nonatomic, copy) NSString *invitationUUID;
@property (nonatomic, copy) NSString *meetingUserNodeID;
@property (nonatomic, assign) BOOL isE2EChat;
@property (nonatomic, copy) NSString *unfurlingExt;
@property (nonatomic, assign) BOOL isCheckZakState;
@property (nonatomic, copy) NSString *routingUrl;
@property (nonatomic, copy) NSString *chatCustomPayload;
@property (nonatomic, copy) NSString *supportedFileTypes;

@end

@interface ZMAppSystemBrowserShareHelper : NSObject

+ (void)systemBrowserShareWithURL:(NSURL *)url completionHandler:(void (^)(BOOL isBrowserSupport, ZMCaptureModel *model))completionHandler;

@end

@interface ZMAppCustomToastInfo : NSObject

@property (nonatomic, copy) NSString *messageText;
@property (nonatomic, copy) NSString *appId;

@end

@interface ZMAppCodeSignHelper : NSObject
+ (BOOL)isZAppInstalledInMainBundle;
+ (void)hasValidZoomCodeSignFromOnDemand:(void (^)(BOOL result))completion;
+ (NSString *)getZAppBundlePath;
@end

@interface ZMZAppKeepModel : NSObject

@property (nonatomic, copy) NSString *appId;
@property (nonatomic, copy) NSString *appName;
@property (nonatomic, copy) NSString *iconPath;
@property (nonatomic, assign) BOOL isSelected;

- (instancetype)initWithAppId:(NSString *)appId appName:(NSString *)appName iconPath:(NSString *)iconPath isSelected:(BOOL)isSelected;

@end

typedef NS_ENUM(NSInteger, ZMZAppUpgradeRspActionType) {
    ZMZAppUpgradeRspActionType_None = 0,
    ZMZAppUpgradeRspActionType_Error,
    ZMZAppUpgradeRspActionType_Success,
    ZMZAppUpgradeRspActionType_Warning,
};

@interface ZMZAppUpgradeRspAction : NSObject

@property (nonatomic, assign) ZMZAppUpgradeRspActionType resultType;
@property (nonatomic, copy) NSString *content;
@property (nonatomic, copy) NSString *link;
@property (nonatomic, copy) NSString *linkText;

@end

@interface ZMZAppUpgradeRspInfo : NSObject

@property (nonatomic, copy) NSString *appId;
@property (nonatomic, copy) NSString *dialogContent;
@property (nonatomic, copy) NSString *confirmButtonText;
@property (nonatomic, copy) NSString *inputBoxPlaceholder;
@property (nonatomic, assign) NSInteger inputBoxLengthLimit;
@property (nonatomic, strong) ZMZAppUpgradeRspAction *successAction;

@end
NS_ASSUME_NONNULL_END
