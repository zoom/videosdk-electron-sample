//
//  ZMConfBaseSinkAdapter.h
//  VideoUI
//
//  Created by Francis Zhuo on 2/22/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMUser.h>
#import <zVideoUIBridge/ZMMTRosterList.h>
NS_ASSUME_NONNULL_BEGIN

@class ZMConfSession;
@interface ZMConfBaseSinkAdapter : NSObject
@property (nonatomic, weak) ZMConfSession* confSession;
@property (assign) BOOL isLeavingMeeting;

+ (instancetype)adapterWithSession:(ZMConfSession*)confSession;

- (void)registerPolicyObserver;
- (void)registerJSEventObserver;

- (ZMUser*)userWithID:(ZMUserID)userID;

/// Other
- (void)onAvatarDataUpdate:(NSString *)jid;
- (void)notifyToGetMeetingInviteesInfoBeforeLeaving;
@end

@interface ZMConfBaseSinkAdapter (User)
- (void)onUserStatusChanged:(USER_CMD)cmd userID:(CMM_USERID)userID;
- (void)onBatchUserStatusChanged:(USER_CMD)cmd list:(CmmUserChangeStatus*_Nullable*_Nullable)list number:(CmmUInt32)num;
- (void)onMyRosterCompleted;

//for overwriting
- (void)onUserStatusChanged:(USER_CMD)cmd user:(ZMUser*)zmUser userID:(CMM_USERID)userID;

- (BOOL)onAudioStatusChanged:(CmmUserChangeStatus*_Nullable*_Nullable)list number:(CmmUInt32)num;
- (BOOL)onRosterChanged:(CmmUserChangeStatus*_Nullable*_Nullable)list number:(CmmUInt32)num;
- (BOOL)onKBRosterChanged:(CmmUserChangeStatus*_Nullable*_Nullable)list number:(CmmUInt32)num;
@end

@interface ZMConfBaseSinkAdapter (ConfStatus)
- (void)onConfReady:(CmmUInt32)ret;

- (void)onConfStatusChanged:(const CONF_STATUS)eStatus;
- (void)onConfStatusChanged:(CONF_CMD)cmd params:(CmmUInt32)ret;

#pragma mark -
- (void)notifyGetSpotAppid:(NSString*)appid;

#pragma mark -
- (void)onAudioObjCreated;
- (void)onVideoObjCreated;
- (void)onShareObjCreated;
- (void)onRecordObjCreated;
- (void)onLTTObjCreated;
@end

@interface ZMConfBaseSinkAdapter (Device)

- (void)onDeviceStatusChanged:(DEVICE_CMD)cmd ret:(CmmUInt32)ret handle:(CmmUInt32)handle;
- (void)showMyAudioLevel:(CmmUInt32)level handle:(CmmUInt32)handle isMic:(CmmBool)isMic;
- (void)onVolumeChange:(CmmUInt32)vol isMic:(CmmBool)isMic;
- (void)onAudioDeviceSpecialInfoChange:(SSB_MC_DEVICE_SPECIAL_INFO)special_info deviceInfo:(CmmAudioDeviceBriefInfo)adbi;
- (void)onUltraSoundDetect_PairCode:(CmmBool)is_timeout code:(const CAString&)pair_code;
- (void)onDeviceStatelessButtonDown:(const CString&)device_id;
- (void)onDocumentCameraShareButtonPressed:(const CString&)device_id;

- (BOOL)canUseVirtualBackgroundNow;
- (BOOL)canUseErasedBackgroundNow;
- (BOOL)canUseEnhancedBackgroundNow;
- (BOOL)canUseVideo3DAvatarNow;
- (BOOL)canUseAudio3DAvatarNow;
- (BOOL)canUseVideoFilterNow;
- (BOOL)canUseStudioEffectNow;
- (void)onNeedPromptBiometricDisclaimer;
- (void)onNeedUpdateEnhancedPortraitPosition;

#pragma mark - ICmmConfUIAPI
- (void)onMyVideoDeviceRunStarted:(void*)hWnd type:(CMM_MY_VIDEO_RUN_TYPE)eRunType device:(PMediaDevice)pDeviceInfo;
- (void)onMyCameraCaptureSizeRatioChanged:(const CString&)cameraID fWidth2Height:(float)fWidth2Height;
- (void)onHandGestureDetected:(const SSB_MC_DATA_BLOCK_HAND_POSE_INFO&)info;
@end

@interface ZMConfBaseSinkAdapter (Share)

- (void)onShareAnnotationStatusChanged:(SSB_MC_ANNOTATION_NOTIFICATION)msg
                                  data:(DWORD)data;
- (void)onShareAnnotationStatusChanged:(SSB_MC_ANNOTATION_NOTIFICATION)msg
                            renderView:(void *)renderView
                                  data:(DWORD)data;
- (void)onRemoteSupportRequestReceived:(CMM_USERID)nUserFrom
                               cmdType:(SUPPORT_CMD_TYPE)cmdType;
- (void)onRemoteSupportResponseReceived:(CMM_USERID)nUserFrom
                                cmdType:(SUPPORT_CMD_TYPE)cmdType
                              bApproved:(CmmBool)bApproved;
- (void)onOnRemoteSupportNotificationReceived:(CMM_USERID)nUserFrom
                                      cmdType:(SUPPORT_NOTIFICATION_TYPE)cmdType;

- (void)onShareRenderEventWithType:(RENDER_EVENT_TYPE)type
                       shareRender:(ICmmASShareRender *)shareRender
                              data:(void *)data
                              size:(int32_t)size;
- (void)onProctoringModeContextChanged:(CmmProctoringModeContext)old_context new_context:(CmmProctoringModeContext)new_context;

- (void)onReceiveEnableMultiShareRequestMsg:(const CString&)reqID senderID:(CMM_USERID)senderID;
- (void)onReceiveEnableMultiShareResponseMsg:(CmmEnableMultiShareResponseStatus)status;
@end

@interface ZMConfBaseSinkAdapter (ClosedCaption)
- (void)onClosedCaptionMessageReceived:(const CString&)msgID
                               content:(const CString&)content
                                  time:(const Cmm::CTime&)timer;
- (void)onRealtimeClosedCaptionMessageReceived:(const CString&)content;
- (void)onLiveTranscriptionClosedCaptionMessageReceived:(const CString&)msgID
                                                   type:(CmmClosedCaption::CCOperationType)type;
- (void)onStartLiveTranscriptRequestReceived:(CMM_USERID)nUserFrom bAnonymous:(CmmBool)bAnonymous;

- (void)onAvailableFreeTrialInfoReceived:(BOOL)bSuccess;

- (void)onSpeakerDiarizationUpdated:(const audio_speaker_diarization_info_t*)info;
@end

@interface ZMConfBaseSinkAdapter (VideoOrder)
- (void)onGalleryVideoOrderSaved:(BOOL)ret;
- (void)onGalleryVideoOrderLoaded:(const CString&)data;
- (void)onDynamicLayoutChanged;
@end

@interface ZMConfBaseSinkAdapter (VideoRender)
- (void)onVideoRenderEventWithType:(RENDER_EVENT_TYPE)type
                       videoRender:(ICmmVideoRender *)videoRender
                              data:(void *)data
                              size:(int32_t)size;
@end

@interface ZMConfBaseSinkAdapter (Chat)
- (void)onChatMessageReceived:(const CString&)msgID;
- (void)onChatSendFile:(const CString&)msgID result:(CmmUInt32)result;
- (void)onChatFileProgress:(const CString&)msgID ratio:(CmmUInt32)ratio completeSize:(CmmUInt32)size speed:(CmmUInt32)bitPerSecond;
- (void)onChatFileStateChange:(const CString&)msgID;
- (void)OnChatShareFileInMeetingChat:(const ShareFileInMeetingChatParam_s&)shareFileInfo;
- (void)OnChatGetPublicDownloadLink:(const CString&)messageID result:(CmmUInt32)result;
- (void)OnChatMessageDeleted:(const CString&)msgId deleteBy:(CHAT_DELETE_BY)deleteBy;
@end

@interface ZMConfBaseSinkAdapter (Policy)
- (void)policyUpdated:(zpref::zPolicyId)policy;
@end

@interface ZMConfBaseSinkAdapter (Invite)
- (void)onMeetingCallReplyInfo:(const MeetingCallReplyInfo&)info;
@end

@interface ZMConfBaseSinkAdapter (Immersive)
- (void)onVideoLayoutDownload:(const CString&)layoutID xmlPath:(const CString&)xmlPath retCode:(CmmUInt32)retCode progress:(CmmUInt32)progress;
@end

@interface ZMConfBaseSinkAdapter (CameraControl)
- (void)onControllableCameraAdded:(CMM_USERID)userID;
- (void)onControllableCameraRemoved:(CMM_USERID)userID;
- (void)onCameraControlGroupAdded:(CMM_USERID)userID error:(FECCGroupAddmemberError)error;
- (void)onCameraControlGroupRemoved:(CMM_USERID)userID success:(CmmBool)success;
@end

@interface ZMConfBaseSinkAdapter (Simulive)
- (void)onSimuliveWebinarAutoReplyStatusChanged:(CmmBool)autoReply replyText:(const CString&)replyText;
- (void)onSimuliveMasterVideoPlayerChanged:(CmmUInt32)originalUJID nowUJID:(CmmUInt32)nowUJID;
- (void)onSimuliveStartFailed;
@end

@interface ZMConfBaseSinkAdapter (BillingHours)
- (void)onRcvContactStatusCheckRes:(CmmBool)isMyContact jid:(const CString&)jid contactName:(const CString&)name;
@end

@interface ZMConfBaseSinkAdapter (ZoomIQ)
- (void)onQueryRequestResponseReceived:(CmmBool)is_timeout response:(const CmmQueryRequestResponse&)response;
- (void)onReceiveRequestToEnableSummaryMsg:(CMM_USERID)senderId;
- (void)onReceiveRequestToStartSummaryMsg:(const CString&)reqId senderId:(CMM_USERID)senderId;
- (void)onReceiveStartSummaryRspMsg:(CmmBool)bTimeOut decline:(CmmBool)decline;

- (void)onSummaryFeatureOnStatusChanged:(CmmBool)summaryEnabled;

- (void)onReceiveRequestToEnableQueriesMsg:(CMM_USERID)senderId;
- (void)onReceiveRequestToEnableAICMsg:(ZMUserID)senderId aicOption:(long long)aicOption;
- (void)onReceiveRequestToStartQueriesMsg:(const CString&)reqId senderId:(CMM_USERID)senderId;
- (void)onReceiveStartQueryResponseMsg:(CmmBool)agree timeout:(CmmBool)timeout;
- (void)onQuerySwitchStatusChanged:(CmmBool)enable;

- (void)onReceiveSwitchAICResponseMsg:(CmmBool)timeout agree:(CmmBool)agree switchAction:(NSInteger)switchAction;
- (void)onReceiveSwitchAICRequestMsg:(const CString&)reqId senderId:(CMM_USERID)senderId aicOption:(CmmInt64)aicOption switchAction:(NSInteger)switchAction;
- (void)onReceiveChangeQueryPrivilegeSettingReqMsg:(const CString&)reqId senderId:(CMM_USERID)senderId expectSetting:(NSInteger)expectSetting;
- (void)onReceiveChangeQueryPrivilegeSettingRspMsg:(CmmBool)timeout decline:(CmmBool)decline;
- (void)onAICompanionFeatureVisableChanged:(CMM_AI_COMPANION)feature visable:(CmmBool)visable;
- (void)onReportActivityForTranscriptResultReceived:(const CString&)reportId type:(CMM_ACTIVITY_TYPE_ABOUT_TRANSCRIPT)type result:(CmmBool) result;
- (void)onReqDeleteAICompanionAssetsResuleReceived:(CmmInt64)aic_option success:(CmmBool)success;
@end

@interface ZMConfBaseSinkAdapter (Companion)
- (void)onLeaveCompanionModeReqReceived:(CMM_USERID)senderId;
- (void)onLeaveCompanionModeRspReceived:(CMM_USERID)senderId agree:(CmmBool)agree;
@end

@interface ZMConfBaseSinkAdapter (Reaction)
- (void)onEmojiReactionReceived:(CMM_USERID)senderId emojiContent:(const CString&)emoji_content emojiCategory:(CmmReactionCategory)emojiCategory;
- (void)onEmojiReactionReceived:(CMM_USERID)senderId reactionType:(CmmEmojiReactionType)type reactionSkinTone:(CmmEmojiReactionSkinTone)skin;
- (void)onEmojiReactionReceivedInWebinar:(const EmojiContentMap &)emoji_contents;

@end

@interface ZMConfBaseSinkAdapter (MultipleCMA)
- (void)onCMARegionStatusChanged:(const CString&)region status:(archive_gw_status)status;
@end

@interface ZMConfBaseSinkAdapter (CMR)
- (void)onEnableSmartRecordingResult:(CmmBool)succ error:(CmmInt64)error_code;
- (void)onStartCMRRequestReceived:(const CString&)reqID sender:(CMM_USERID)senderId;
- (void)onStartCMRRequestResponseReceived:(CmmBool)bTimeOut decline:(CmmBool)bDecline;
@end

@interface ZMConfBaseSinkAdapter (GalleryPlus)
- (void)onGalleryPlusWallpaperChanged:(CMM_USERID)sender_id wallpaperID:(const CString&)wallpaper_id;
- (void)onGalleryPlusTransparencyChanged:(CMM_USERID)sender_id transparency:(NSInteger)transparency;
- (void)onGalleryPlusLayoutModeChanged:(CMM_USERID)sender_id layoutMode:(GALLEY_PLUS_LAYOUT_MODE)layoutMode;
- (void)onPersonalWallpaperConfigChanged;
- (void)onPersonalWallpaperDownloadStatus:(const CString&)wallpaper_id status:(PersonalWallpaperDownloadStatus)status;
- (void)onPersonalWallpaperThumbDownloadStatus:(const CString&)wallpaper_id status:(PersonalWallpaperDownloadStatus)status;

@end

@interface ZMConfBaseSinkAdapter (MediaStream)
- (void)onCommonDiclaimerReceived:(const CString&)notice_id status:(CmmInt32)notice_status;
- (void)onIndicatorAppStatusUpdated:(const CString&)notice_id app:(const CmmIndicatorAppItem&)indicator_app;
- (void)onToastStatusUpdated:(const CString&)notice_id status:(CmmInt32)notice_status;
- (void)onIndicatorTabReceived:(const CString&)tab_id;
- (void)onCommonNoticeDeleted:(const CmmNoticeSet&)cmm_notice;
- (void)onIndicatorTabDeleted:(const CString&)tab_id;
- (void)onZoomStreamingServiceSwitchChanged:(CmmBool)new_switch;
- (void)onZssStatusChanged;
@end

@interface ZMConfBaseSinkAdapter (ProductionStudio)
- (void)onPSLMixShareInfoChangedWithSourceID:(ZMShareSourceID)shareSourceID rect:(NSRect)rect;
- (void)onPSLInviteRequested:(BOOL)isSuccess message:(nullable NSString *)errorMessage;
- (void)onPSLLiveLayoutChanged:(CMM_USERID)sender_id layout:(const CmmPSLLayout&)layout;
- (void)onPSLControlCommandChanged:(const CmmRSGWControlData&)data;

@end

@interface ZMConfBaseSinkAdapter (ClinicalNote)
- (void)onReceiveSwitchClinicalNoteRequestMsg:(const CString&)reqId senderId:(CMM_USERID)senderId switchAction:(NSInteger)switchAction;
- (void)onReceiveSwitchClinicalNoteResponseMsg:(CmmBool)timeout isDecline:(CmmBool)decline switchAction:(NSInteger)switchAction;
- (void)onClinicalNoteStatusChanged;
- (void)onCreateClinicalNoteSessionFailed:(CMM_CN_ERROR_CODE)errCode;
- (void)onAICompanionTokenReceived:(CmmBool)success reqId:(const CString&)reqId token:(const CString&)token;
@end

@interface ZMConfBaseSinkAdapter (LiveSummary)
- (void)onSmartAgendaDocIdReceived:(const CString&)docId;
- (void)onLiveSummaryDocUpdated:(const CString&)docId;
- (void)onSummaryShareLevelChanged:(CmmInt32)newLevel;
- (void)onLiveSummarySettingChanged:(CmmBool)isLiveSummaryEnabled;
- (void)onReceiveSwitchAICompanionWithLiveSummaryRequestMsg:(const CString&)reqId senderId:(CMM_USERID)senderId aicOption:(CmmInt64)aicOption switchAction:(NSInteger)switchAction;
- (void)onReceiveSwitchAICompanionWithLiveSummaryResponseMsg:(CmmInt64)aicOption timeout:(CmmBool)timeout agree:(CmmBool)agree switchAction:(NSInteger)switchAction;
@end

@interface ZMConfBaseSinkAdapter (Recording)
- (void)notifyGetUserRecordPic:(SSB_MC_RECORDER_USER_VIDEO_GET_PIC_INFO)type userId:(uint32_t)user_id;
@end

@interface ZMConfBaseSinkAdapter (FEAC)
- (void)onRemoteUserRequestedAudioControlByAutoFEAC:(CMM_USERID)userId;
- (void)onRemoteUserRequestedAudioControl:(CMM_USERID)userId;
- (void)onRemoteUserApprovedAudioControl:(CMM_USERID)userId;
- (void)onRemoteUserApprovedAudioControlByAutoFEAC:(CMM_USERID)userId;
- (void)onRemoteUserDeclinedAudioControl:(CMM_USERID)userId;
- (void)onRemoteUserStopAudioControl:(CMM_USERID)userId;
- (void)onRemoteUserGaveUpAudioControl:(CMM_USERID)userId;
- (void)onRemoteUserTookOverAudioControl:(CMM_USERID)userId controlUser:(CMM_USERID)remoteUserControllingUserId;
- (void)onRemoteAudioDeviceUpdate:(const RemoteAudioDeviceInfo&)deviceInfo type:(DeviceUpdateType)updateType;
- (void)onFEACUnMuteDisabledByHost;
- (void)onAudioDeviceControlGroupOneRemoved:(CMM_USERID)sender_id result:(CmmBool)ret;
- (void)onAudioDeviceControlGroupOneAdded:(CMM_USERID)sender_id result:(CmmBool)ret;
- (void)onUserAudioDeviceControlAutoAcceptStatusChanged:(CMM_USERID)sender_id result:(CmmBool)allow;
@end

@interface ZMConfBaseSinkAdapter (RTMS)
- (void)onRTMSGwStatusChanged;
@end

NS_ASSUME_NONNULL_END
