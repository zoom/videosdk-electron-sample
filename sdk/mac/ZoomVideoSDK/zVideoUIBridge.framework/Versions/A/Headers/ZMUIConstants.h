//
//  ZMUIConstants.h
//  SaasBeeConfUIModule
//
//  Created by francis zhuo on 2019/7/22.
//  Copyright © 2019 zoom.us. All rights reserved.
//

#ifndef ZMUIConstants_h
#define ZMUIConstants_h

#define ZMUserID UInt32
#define ZMUUID uint64_t
#define ZMUJID UInt32
#define ZMShareSourceID UInt32

#define kBitRoomID 48
typedef NS_ENUM(NSUInteger, ZMConfInstType) {
    ZMConfInstType_Default      = 1,
    ZMConfInstType_BOMaster     = 2,
    ZMConfInstType_Backstage    = 3,
    ZMConfInstType_Silent       = 4,
    
    ZMConfInstType_Common       = 100,
    ZMConfInstType_Transition   = 101,
    ZMConfInstType_Null         = 102,
    
    ZMConfInstType_SpotsBO      = 1ll<<(kBitRoomID-3),//roomID = ConfInstType>>(kBitRoomID)
    ZMConfInstType_PBO          = 1ll<<(kBitRoomID-2),//roomID = ConfInstType>>(kBitRoomID)
    ZMConfInstType_NewBO        = 1ll<<(kBitRoomID-1),//roomID = ConfInstType>>(kBitRoomID)
};

#define kZMConfInstType_Default @"kZMConfInstType_Default"
#define kZMConfInstType_BOMaster @"kZMConfInstType_BOMaster"
#define kZMConfInstType_Backstage @"kZMConfInstType_Backstage"
#define kZMConfInstType_Common @"kZMConfInstType_Common"
#define kZMConfInstType_NewBO_Prefix "kZMConfInstType_NewBO:"
#define ZMBOIdentifer(roomID) [NSString stringWithFormat:@"%s%@", kZMConfInstType_NewBO_Prefix, @(roomID)]
#define ZMBOInstType(roomID) (ZMConfInstType)(((1ll*roomID)<<(kBitRoomID))|ZMConfInstType_NewBO)
#define ZMBORoomID(InstType) (InstType>>(kBitRoomID))

#define kZMConfInstType_PBO_Prefix "kZMConfInstType_PBO:"
#define ZMPBOIdentifer(roomID) [NSString stringWithFormat:@"%s%@", kZMConfInstType_PBO_Prefix, @(roomID)]
#define ZMPBOInstType(roomID) (ZMConfInstType)(((1ll*roomID)<<(kBitRoomID))|ZMConfInstType_PBO)

#define kZMConfInstType_Transition @"kZMConfInstType_Transition"
#define kZMConfInstType_Null @"kZMConfInstType_Null"
#define kZMConfInstType_Silent @"kZMConfInstType_Silent"

#ifdef ENABLE_ZAPP
#define kZMConfInstType_SpotsBO_Prefix "kZMConfInstType_SpotsBO:"
#define ZMSpotsBOIdentifer(roomID) [NSString stringWithFormat:@"%s%@", kZMConfInstType_SpotsBO_Prefix, @(roomID)]
#define ZMSpotsBOInstType(roomID) (ZMConfInstType)(((1ll*roomID)<<(kBitRoomID))|ZMConfInstType_SpotsBO)
#endif

#pragma mark - Video Log Module Name
#define ZMLoggingModule_VideoUI_CC  "VideoUI_CC"
#define ZMLoggingModule_VideoUI_SDKMeeting  "VideoUI_SDKMeeting"
#define ZMLoggingModule_VideoUI_Interpretation  "VideoUI_Interpretation"
#define ZMLoggingModule_VideoUI_WBO "VideoUI_WBO"
#define ZMLoggingModule_VideoUI_CameraControl "VideoUI_CameraControl"
#define ZMLoggingModule_VideoUI_AIC  "VideoUI_AIC"
#define ZMLoggingModule_VideoUI_Tab  "VideoUI_Tab"
#define ZMLoggingModule_VideoUI_Topbar  "VideoUI_Topbar"
#define ZMLoggingModule_VideoUI_Chat "VideoUI_Chat"
#define ZMLoggingModule_VideoUI_WB   "VideoUI_WB"
#define ZMLoggingModule_VideoUI_Immersive "VideoUI_Immersive"
#define ZMLoggingModule_VideoUI_JoinFlow "VideoUI_JoinFlow"
#define ZMLoggingModule_VideoUI_Record "VideoUI_Record"

#pragma mark - video render
typedef NS_OPTIONS(NSUInteger, ZMVideoUpdateStrategy) {
    ZMVideoUpdateStrategyAvatar     = 1,
    ZMVideoUpdateStrategyUserInfo   = 1<<1,
    ZMVideoUpdateStrategyRender     = 1<<2,
    ZMVideoUpdateStrategyWaterMark  = 1<<3, // ZOOM-277664 personal water mark
    ZMVideoUpdateStrategyNameTag    = 1<<4, // ZOOM-314071 webinar username tag
    ZMVideoUpdateStrategyMuteButton = 1<<5,
    ZMVideoUpdateStrategyKubiButton = 1<<6,
    ZMVideoUpdateStrategyOtherButton= 1<<7,
    ZMVideoUpdateStrategyButton     = ZMVideoUpdateStrategyMuteButton|ZMVideoUpdateStrategyKubiButton|ZMVideoUpdateStrategyOtherButton,
    
    ZMVideoUpdateStrategyResubscribe= 1<<10,
    
    ZMVideoUpdateStrategySkintone   = 1<<13,
    ZMVideoUpdateStrategyReactions  = 1<<14,
    ZMVideoUpdateStrategyHandView   = 1<<15,
    
    ZMVideoUpdateStrategySmartTagInfo       = 1<<16,
    ZMVideoUpdateStrategySmartTagPosition   = 1<<17,
    
    ZMVideoUpdateStrategyAllInfo    = ZMVideoUpdateStrategyAvatar|ZMVideoUpdateStrategyButton|ZMVideoUpdateStrategyUserInfo|ZMVideoUpdateStrategySkintone|ZMVideoUpdateStrategySmartTagPosition,
    ZMVideoUpdateStrategyAll        = ZMVideoUpdateStrategyRender|ZMVideoUpdateStrategyAllInfo,
    
//    ZMVideoUpdateStrategyActiveVideo= 1<<18,
    ZMVideoUpdateStrategyCleanRender= 1<<19,
    ZMVideoUpdateStrategyDockbar    = 1<<20,
    ZMVideoUpdateStrategyRenderRect = 1<<21,
    ZMVideoUpdateStrategyScreenResolution = 1<<22,
};

#pragma mark - ZMMTConferenceStrategy
typedef NS_ENUM(NSInteger, ZMConfUpdateStrategy) {
    ZMConfUpdateStrategy_ConfReady,
    ZMConfUpdateStrategy_ConfLeave,
    
    ZMConfUpdateStrategy_BOConfReady,
    
    ZMConfUpdateStrategy_Preview_Changed,
    ZMConfUpdateStrategy_Companion_Changed,
    ZMConfUpdateStrategy_ZE_Companion_Image_Result,
    ZMConfUpdateStrategy_Silent_Changed,
    ZMConfUpdateStrategy_Backstage_Changed,
    ZMConfUpdateStrategy_Debrief_Changed,
    ZMConfUpdateStrategy_Practice_Changed,
    ZMConfUpdateStrategy_JoinFlow_Changed,
    ZMConfUpdateStrategy_Transition_Status_Changed,
    
    ZMConfUpdateStrategy_Zapp_Immersive_Changed,
    ZMConfUpdateStrategy_Zapp_Collaborate_Changed,
    
    ZMConfUpdateStrategy_Customer_Mode_Changed,
    ZMConfUpdateStrategy_Customer_Layout_Changed,
    ZMConfUpdateStrategy_Customer_Share_Source_Changed,
    ZMConfUpdateStrategy_Backstage_Leave_CountDown,
    ZMConfUpdateStrategy_Meeting_Topic_Changed,
    ZMConfUpdateStrategy_Avatar_Permission_Changed,
    
    ZMConfUpdateStrategy_Dual_Monitor_Changed,
    
    ZMConfUpdateStrategy_Audio_Status,
    ZMConfUpdateStrategy_Audio_Type,
    ZMConfUpdateStrategy_Active_Audio,
    
    ZMConfUpdateStrategy_Active_ZR_Speaker,
    ZMConfUpdateStrategy_Edit_ZR_Speaker_Info,
    ZMConfUpdateStrategy_Speaker_Tag_Enable_Changed,
    
    ZMConfUpdateStrategy_Video_Status,
    ZMConfUpdateStrategy_My_Video_Status,
    ZMConfUpdateStrategy_Talking_Video,
    ZMConfUpdateStrategy_Active_Video,
    ZMConfUpdateStrategy_Active_Video_Deck,
    ZMConfUpdateStrategy_Active_Video_2nd,
    
    ZMConfUpdateStrategy_User_Roster,//add/left/silent/BO/GR/Update
    ZMConfUpdateStrategy_User_Add,
    ZMConfUpdateStrategy_User_Left,
    ZMConfUpdateStrategy_User_Enter_Silent,
    ZMConfUpdateStrategy_User_Exit_Silent,
    ZMConfUpdateStrategy_User_Rename,
    
    ZMConfUpdateStrategy_Become_HostCohost,
    ZMConfUpdateStrategy_Lose_HostCohost,
    ZMConfUpdateStrategy_OtherUser_BecomeLoseHostCoHost,
    
    ZMConfUpdateStrategy_Show_My_Video,
    ZMConfUpdateStrategy_Show_No_Video,
    ZMConfUpdateStrategy_Show_Incoming_Video,
    ZMConfUpdateStrategy_Show_Meeting_Timers,
    ZMConfUpdateStrategy_Show_Billing_Timers,
    ZMConfUpdateStrategy_RTMS_Status_Changed,
    ZMConfUpdateStrategy_Spotlight_Self_Changed,
    
    ZMConfUpdateStrategy_Pin_Group_Changed,
    ZMConfUpdateStrategy_Spotlight_Changed,
    ZMConfUpdateStrategy_Drag_Layout_Changed,
    
    ZMConfUpdateStrategy_Attende_Layout_Changed,
    
    ZMConfUpdateStrategy_Meeting_Controls,
    ZMConfUpdateStrategy_Dockbar_Ready,
    ZMConfUpdateStrategy_Dockbar_Status_Changed,
    ZMConfUpdateStrategy_Dockbar_Did_Show,
    ZMConfUpdateStrategy_Dockbar_Did_Hide,
    
    ZMConfUpdateStrategy_Send_Share_Ready,
    ZMConfUpdateStrategy_Sending_Share_Status,
    ZMConfUpdateStrategy_Share_Source_Changed,
    ZMConfUpdateStrategy_Share_Session_Completed,
    ZMConfUpdateStrategy_Share_Toolbar_Did_Show,
    ZMConfUpdateStrategy_Share_Toolbar_Did_Hide,

    
    ZMConfUpdateStrategy_Closed_Caption,
    ZMConfUpdateStrategy_Captions_Status_Changed,
    ZMConfUpdateStrategy_Captions_User_Sub_Status_Changed,
    
    ZMConfUpdateStrategy_Backsatge_Transfer,
    
    ZMConfUpdateStrategy_Focus_Mode_Changed,
    
    ZMConfUpdateStrategy_BackSplash_Changed,
    
    ZMConfUpdateStrategy_E2E_Security_Code_Changed,
    ZMConfUpdateStrategy_E2EE_PQC_Security_Code_Changed,
    ZMConfUpdateStrategy_DC_Region_Ready,
    ZMConfUpdateStrategy_IDP_Status_Changed,
    ZMConfUpdateStrategy_Unencypted_Status_Changed,
    ZMConfUpdateStrategy_Livestream_Status_Changed,
    
    ZMConfUpdateStrategy_Share_Doc_Source_Changed,
    ZMConfUpdateStrategy_Share_Doc_Content_Received,
    ZMConfUpdateStrategy_Share_Doc_Load_State_Changed,
    
    // Clips
    ZMConfUpdateStrategy_Clips_Share_Started,
    ZMConfUpdateStrategy_Clips_Share_Stopped,
    
    ZMConfUpdateStrategy_Share_Audio_Sending_Status,//prue share audio
    ZMConfUpdateStrategy_Share_Audio_Source_Changed,//prue share audio
    
    ZMConfUpdateStrategy_Webinar_Reactions_Received,
    ZMConfUpdateStrategy_Webinar_Reactions_Type_Changed,
    ZMConfUpdateStrategy_Webinar_Reactions_Enabled_Changed,
    
    ZMConfUpdateStrategy_Mesh_Badge_Changed,
    
    ZMConfUpdateStrategy_Whiteboard_Source_Changed,
    ZMConfUpdateStrategy_Whiteboard_Presenter_Changed,
    ZMConfUpdateStrategy_Record_Status_Changed,
    ZMConfUpdateStrategy_Local_Record_Started,
    
    ZMConfUpdateStrategy_Gateway_Logo_Downloaded,
    ZMConfUpdateStrategy_Lipsync_State_Changed,
    
    ZMConfUpdateStrategy_Login_State_Changed,
    ZMConfUpdateStrategy_Archive_Status_Changed,
    
    ZMConfUpdateStrategy_Proctoring_Mode_Changed,
    ZMConfUpdateStrategy_Simulive_Live_Changed,
    ZMConfUpdateStrategy_NewSimulive_Status_Changed,
    
    ZMConfUpdateStrategy_User_Logged_In,
    ZMConfUpdateStrategy_User_Logged_Out,
    
    ZMConfUpdateStrategy_Query_Status_Changed,
    ZMConfUpdateStrategy_IQ_Status_Changed,
    ZMConfUpdateStrategy_Query_Setting_Changed,
    ZMConfUpdateStrategy_AI_Companion_Notice_Changed,
    ZMConfUpdateStrategy_Watch_Only_Status_Changed,
    ZMConfUpdateStrategy_CMR_Recording_Status_Changed,
    ZMConfUpdateStrategy_Resource_Visible_Status_Changed,
    
    ZMConfUpdateStrategy_Spatial_Audio_Effects_Changed,
    
    ZMConfUpdateStrategy_Doc_Source_Changed,
    ZMConfUpdateStrategy_Doc_WebView_Did_Show,
    ZMConfUpdateStrategy_User_Companion_Relation_Changed,
    ZMConfUpdateStrategy_User_Account_Option_Changed,
    
    ZMConfUpdateStrategy_BO_Share_Replaced_By_Host,
    ZMConfUpdateStrategy_Window_Level_Change,
    ZMConfUpdateStrategy_Animate_Emojis_Status_Changed,
};

#pragma mark - ZMMTContentType
/**
 content type will write in monitor log, so cannot change value anymore, 6.0.0 release
 */
typedef NS_OPTIONS(NSUInteger, ZMMTContentType){
    ZMMTContentType_None        = 0,
    ZMMTContentType_Previewing  = 1ll<<0,
    ZMMTContentType_Wallpaper   = 1ll<<2,//old ZMMTContentType_BrandView(less than 6.1.5)
    ZMMTContentType_Waiting_Host= 1ll<<3,
    
    ZMMTContentType_Transition  = 1ll<<4,
    ZMMTContentType_GRTransform = 1ll<<5,
    ZMMTContentType_BackStage   = 1ll<<6,
    ZMMTContentType_BRTransform = 1ll<<7,
    
    ZMMTContentType_Captions    = 1ll<<10,
    ZMMTContentType_Companion   = 1ll<<11,
    ZMMTContentType_Thumbnail   = 1ll<<12,
    ZMMTContentType_View_Share  = 1ll<<13,
    ZMMTContentType_Whiteboard  = 1ll<<14,
    ZMMTContentType_BarrageView = 1ll<<15,
    ZMMTContentType_Share_Only  = 1ll<<16,
    ZMMTContentType_CompanionZE = 1ll<<17,
    ZMMTContentType_Doc         = 1ll<<18,
    ZMMTContentType_Improved_Companion = 1ll<<19,
    ZMMTContentType_ProductionStudio = 1ll<<20,
    ZMMTContentType_Active      = 1ll<<21,
    ZMMTContentType_Gallery     = 1ll<<22,
    ZMMTContentType_Customer    = 1ll<<23,
    ZMMTContentType_Group_Pin   = 1ll<<24,
    ZMMTContentType_Zapp_Immersive = 1ll<<25,
    ZMMTContentType_Zapp_Collaborate = 1ll<<26,
    ZMMTContentType_Simulive    = 1ll<<27,
    ZMMTContentType_Dynamic     = 1ll<<28,
    ZMMTContentType_ComputerAudio = 1ll<<29,
    
    ZMMTContentType_Send_Slide_Share= 1ll<<30,
    ZMMTContentType_Send_Screen_Share= 1ll<<31,
    ZMMTContentType_Send_Camera_Share= 1ll<<32,
    ZMMTContentType_Send_Video_Share = 1ll<<33,

    ZMMTContentType_Practice_Session = 1ll<<34,
    ZMMTContentType_ProctoringMode  = 1ll<<35,
    
    ZMMTContentType_ExplosionView   = 1ll<<36,
    ZMMTContentType_FloatingReaction= 1ll<<37,
    
    ZMMTContentType_Side_By_Side    = 1ll<<48,
    ZMMTContentType_Swap_Share      = 1ll<<49,
    
    ZMMTContentType_FullScreen      = 1ll<<50,
    ZMMTContentType_KeepFullScreen  = 1ll<<51,
    ZMMTContentType_Toolbar         = 1ll<<52,
    ZMMTContentType_Toolbar_Lock    = 1ll<<53,
    ZMMTContentType_Wallpaper_Flag  = 1ll<<54,
};

typedef NS_OPTIONS(NSUInteger, ZMUserExcludeFilter){
    ZMUserExcludeFilter_None    = 0,
    ZMUserExcludeFilter_Silent  = 1<<1,
    ZMUserExcludeFilter_BO      = 1<<2,
    ZMUserExcludeFilter_ViewOnly= 1<<3,
    ZMUserExcludeFilter_GR      = 1<<4,
    ZMUserExcludeFilter_MultiStream = 1<<5,
    ZMUserExcludeFilter_VirtualAssistant = 1<<6,
    ZMUserExcludeFilter_Myself = 1<<7,
    ZMUserExcludeFilter_SignInterpreter = 1<<8,
    ZMUserExcludeFilter_CompanionModeWithParent = 1<<9,
    ZMUserExcludeFilter_PSLProducer = 1<<10,
    ZMUserExcludeFilter_PBO     = 1<<11,
    ZMUserExcludeFilter_VirtualUser = 1<<12,
};

#pragma mark - Water Mark
typedef NS_ENUM(NSInteger, ZMConfWaterMarkCoverType) {
    ZMConfWaterMarkCoverTypeNone,
    ZMConfWaterMarkCoverTypeInstance,
    ZMConfWaterMarkCoverTypeRepeated,
};
typedef NS_OPTIONS(NSUInteger, ZMConfWaterMarkVisibleOnType) {
    ZMConfWaterMarkVisibleOnTypeNone            = 0,
    ZMConfWaterMarkVisibleOnTypeShareContent    = 1 << 0,
    ZMConfWaterMarkVisibleOnTypeVideoFeeds      = 1 << 1,
};
typedef NS_ENUM(NSInteger, ZMConfWaterMarkPosition) {
    ZMConfWaterMarkPositionMiddle,
    ZMConfWaterMarkPositionTop,
    ZMConfWaterMarkPositionBottom,
    ZMConfWaterMarkPositionLeft,
    ZMConfWaterMarkPositionRight,
};

typedef NS_ENUM(NSInteger, ZMMTJoinUpdateStrategy)
{
    ZMMTJoinUpdateStrategy_None,
    ZMMTJoinUpdateStrategy_Login_Changed,
    ZMMTJoinUpdateStrategy_Content_Changed,
    ZMMTJoinUpdateStrategy_Silent_Changed,
    ZMMTJoinUpdateStrategy_ConnectedMMR,
    ZMMTJoinUpdateStrategy_Silent_Countdown,
    
    ZMMTJoinUpdateStrategy_Preview_Audio_Status,
    ZMMTJoinUpdateStrategy_Preview_Audio_Option_Status,
    ZMMTJoinUpdateStrategy_Preview_Video_Status,
    ZMMTJoinUpdateStrategy_Preview_Video_Option_Status,
    ZMMTJoinUpdateStrategy_Preview_Lipsync_State,
    ZMMTJoinUpdateStrategy_Preview_Avatar_Update,
    ZMMTJoinUpdateStrategy_Preview_Join_Audio,
    
    ZMMTJoinUpdateStrategy_Preview_Camera_Changed,
    ZMMTJoinUpdateStrategy_Status_NonHost_Changed,
    ZMMTJoinUpdateStrategy_Status_Preview_Changed,
    ZMMTJoinUpdateStrategy_Status_Topic_Changed,
    
    ZMMTJoinUpdateStrategy_Waiting_Image_Status, //defult Image
    ZMMTJoinUpdateStrategy_Waiting_Logo_Status,
    ZMMTJoinUpdateStrategy_Waiting_Video_Status,
    ZMMTJoinUpdateStrategy_Waiting_Video_Progress,
    ZMMTJoinUpdateStrategy_Waiting_Video_PausePlay,
    ZMMTJoinUpdateStrategy_Waiting_Title_Description,
    
    ZMMTJoinUpdateStrategy_Status_HostLeavedAndAutoAssignWR,
};

typedef NS_OPTIONS(NSUInteger, ZMMTVideoFilter) {
    ZMMTVideoFilter_None                    = 0,
    ZMMTVideoFilter_MySelf                  = 1 << 0,
    ZMMTVideoFilter_PureCallIn              = 1 << 1,
    
    ZMMTVideoFilter_NoVideo                 = 1 << 3,
    ZMMTVideoFilter_NoVideoAndNoRaiseHand   = 1 << 4 | ZMMTVideoFilter_NoVideo,
    ZMMTVideoFilter_SLInterpreter           = 1 << 5,
    ZMMTVideoFilter_Proctoring              = 1 << 6,
    ZMMTVideoFilter_Pinned                  = 1 << 7,
    ZMMTVideoFilter_Spotlight               = 1 << 8,
    
    ZMMTVideoFilter_VirtualUser             = 1 << 10,
    ZMMTVideoFilter_NotAssitantUser         = 1 << 11,
    ZMMTVideoFilter_NotRSGeteway            = 1 << 12,
    ZMMTVideoFilter_CompanionUser_NoVideo   = 1 << 13,
    ZMMTVideoFilter_ViewOnlyUser            = 1 << 14,
    ZMMTVideoFilter_RTMPUser                = 1 << 15,
    ZMMTVideoFilter_NotActiveRTMPUser       = 1 << 16|ZMMTVideoFilter_RTMPUser,
    ZMMTVideoFilter_SimuliveUser            = 1 << 17,
    ZMMTVideoFilter_NotActiveSimuliveUser   = 1 << 18|ZMMTVideoFilter_SimuliveUser,
    ZMMTVideoFilter_VideoSceneUser          = 1 << 19,
    ZMMTVideoFilter_NotActiveVideoSceneUser       = 1 << 20|ZMMTVideoFilter_VideoSceneUser,
};

typedef NS_OPTIONS(NSUInteger, ZMMTVideoSortType) {
    ZMMTVideoSortType_None                  = 0,
    ZMMTVideoSortType_FirstNameAsc          = 1,
    ZMMTVideoSortType_FirstNameDesc         = 2,
    ZMMTVideoSortType_LastNameAsc           = 3,
    ZMMTVideoSortType_LastNameDesc          = 4,
    ZMMTVideoSortType_EntryTimeAsc          = 5,
    ZMMTVideoSortType_EntryTimeDesc         = 6,
};

typedef NS_ENUM(NSInteger, ZMMTRelation){
    ZMMTRelationLessThan            = 0,
    ZMMTRelationLessThanOrEqual     = 1,
    ZMMTRelationEqual               = 2,
    ZMMTRelationGreaterThanOrEqual  = 3,
    ZMMTRelationGreaterThan         = 4,
};

typedef NS_ENUM(NSUInteger, ZMMTRenderBKType) {
    ZMMTRenderBKType_Normal,
    ZMMTRenderBKType_Transparent,
    ZMMTRenderBKType_NoColor,
};

typedef NS_ENUM(NSUInteger, ZMMTDisclaimerType){
    ZMMTDisclaimerType_None = 0,
    ZMMTDisclaimerType_Queries,
    ZMMTDisclaimerType_Summary,
    ZMMTDisclaimerType_Recording,
    ZMMTDisclaimerType_SmartRecording,
    ZMMTDisclaimerType_ZRARecording,
    ZMMTDisclaimerType_Livestream,
    ZMMTDisclaimerType_Archive,
    ZMMTDisclaimerType_ClosedCaption,
    ZMMTDisclaimerType_AI,
};

typedef NS_ENUM(NSInteger, ZMMTVideoLayoutMode) {
    ZMMTVideoLayoutModeNone,
    ZMMTVideoLayoutModeActive,
    ZMMTVideoLayoutModeDynamic,
    ZMMTVideoLayoutModeGallery,
};

typedef NS_ENUM(NSUInteger, ZMMTUpgradeEntrance) {
    ZMMTUpgradeEntrance_None,
    ZMMTUpgradeEntrance_TipWnd,
    ZMMTUpgradeEntrance_PlistBanner,
    ZMMTUpgradeEntrance_ChatBanner,
    ZMMTUpgradeEntrance_AiPanel,
};

typedef NS_ENUM(NSInteger, ZMMTCaptionDisplayMode) {
    ZMMTCaptionDisplayModePinToBottom,
    ZMMTCaptionDisplayModePopOutOverlay,
};

#endif /* ZMUIConstants_h */
