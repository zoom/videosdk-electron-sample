//
//  ZMMTConfInstSink.h
//  VideoUI
//
//  Created by Francis Zhuo on 8/29/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMConfBaseSinkAdapter.h>
#import <zm_conf_universal_ui/zm_conf_universal_ui_api.h>
#import <zm_conf_callback_dispatcher/zm_conf_callback_dispatcher_api.h>

class ZMMTConfInstSink : public ICmmConfUIAPI,
public NS_ZM_CONF_CALLBACK_DISPATCHER::IConfApiSink,
public NS_ZM_UNIVERSAL_UI::IZmDllInfoApi
{
public:
    ZMMTConfInstSink(ZMConfBaseSinkAdapter *adapter);
    virtual ~ZMMTConfInstSink();
    
    virtual void InitModule();
    
    virtual void OnUserStatusChanged(USER_CMD cmd, CMM_USERID userID = 0); //userID = -1 means all ,=0 means himself
    virtual void OnBatchUserStatusChanged(USER_CMD cmd, CmmUserChangeStatus** list, CmmUInt32 num);
    virtual void OnMyRosterCompleted();
    virtual void OnConfStatusChanged(CONF_CMD cmd, CmmUInt32 ret); // Along with a status code for each status
    virtual void OnConfStatusChanged(const CONF_STATUS eStatus); // Along with a status code for each status

    virtual void OnVideoFECCCmd(SSB_MC_SESSION_COMMAND_TYPE command, void* p_data, int32_t size_of_data);
    virtual void OnPTEndSetting();
    virtual void OnPTLaunchSetting(const CmmShowSettingsDialogParams& params);
    virtual void OnActivateWindow(const CString& reason);
    virtual void OnPTInvitationSent(const Cmm::CAString& xmlInfo);
    virtual void OnPTAskToLeave(const CString& reason);
    virtual void OnPTInviteRoomSystemResult(CmmBool result, const InviteRoomDeviceInfo& room_dev);
    
    virtual void ShowWaitingUI(CmmBool bShow);
    virtual void OnVideoLayoutDownload(const CString& layoutID, const CString& xmlPath, CmmUInt32 retCode, CmmUInt32 progress);
    virtual void StartAppShare(const Cmm::CString& app, const Cmm::CString& previewUrl, CmmBool bFromDeepLink);

    virtual void OnEmojiDownloadStatus(const CString& strReqID, CmmUInt32 nProgress, CmmUInt32 nResult);

    //////////////////////////////////////////////////////////////////////////
    // APIs for Chat UI
    virtual void NotifyChatMessageReceived(
      const CString& msgID,
      CmmInt32 sender,
      const CString& senderDisplayName,
      CmmInt32 receiver,
      const CString& receiverDisplayName,
      const CString& content,
      const Cmm::CTime& time
    );


    //File transfer
    virtual void FT_OnSent(const CString& messageID, CmmUInt32 result);
    virtual void FT_OnProgress(const CString& messageID, CmmUInt32 ratio /*0-100*/, CmmUInt32 completeSize, CmmUInt32 bitPerSecond);
    virtual void FT_OnStatusChange(const CString& messageID);
    virtual void FT_OnGetPublicDownloadLink(const CString& messageID, CmmUInt32 result);
    
    virtual void OnMeetingCallReplyInfo(const MeetingCallReplyInfo& meeting_call_reply_info);

    virtual void NotifyClosedCaptionMessageReceived(const CString& msgID, const CString& content, const Cmm::CTime& time);
    virtual void NotifyRealtimeClosedCaptionMessageReceived(const CString& content);

    // "msgID" the message ID, UI use it to query and get an ICmmClosedCaptionMessageItem object (cc_item);
    // "type" is the operation type;
    // 1). if "type" is ADD, means a new live transcription closed caption item (cc_item) is arrive, and it must be
    // the latest one, UI should refresh BOTH the real-time dialog and history panel;
    // 2). if "type" is UPDATE, means an existed item (cc_item) has been updated. UI should call
    // "virtual CString ICmmClosedCaptionComponent::GetLatestClosedCaptionMessageItemMsgID() = 0;"
    // to get the latest item message ID to judge the object(cc_item) whether is the latest.
    // a). If the object is latest, UI should refresh BOTH the real-time dialog and history panel;
    // b). If the object is NOT latest, UI should only refresh history pannel;
    // 3). If "type" is DELETE, means an existed item (cc_item) has been deleted (at this time cc_item is NULL).
    // UI should refresh history pannel;
    virtual void NotifyLiveTranscriptionClosedCaptionMessageReceived(const CString& msgID, CmmClosedCaption::CCOperationType type);
    // ZOOM-254515
    virtual void OnStartLiveTranscriptRequestReceived(CMM_USERID nUserFrom, CmmBool bAnonymous) override;
    // ZOOM-630080
    virtual void OnTranslationFreeTrialRequestResponseReceived(CmmBool success, CmmBool timeout, const CString& err_msg) override;
    // ZOOM-659272
    virtual void OnAvailableFreeTrialInfoReceived(CmmBool success, CmmBool timeout) override;

    // kend. the following function will be removed after all platfroms implementing the virtual function. use the new version of function instead
    virtual void OnShareAnnotationStatusChanged(SSB_MC_ANNOTATION_NOTIFICATION msg, DWORD data);
    virtual void OnShareAnnotationStatusChanged(SSB_MC_ANNOTATION_NOTIFICATION msg, void* renderView, CmmDWORD data);
    //////////////////////////////////////////////////////////////////////////
    // new added for join scheduled meeting
    virtual CmmBool JoinConf_ConfirmMeetingInfo(CmmBool success, CmmBool hasPassword, CmmBool bHasScreenName);
    virtual CmmBool JoinConf_ConfirmPasswordValidateResult(CmmBool success, CmmBool needWait);
    virtual CmmBool JoinConf_ConfirmMeetingStatus(CmmBool canJoinNow, CmmBool bHasScreenName);
    virtual void JoinConf_ConfirmMultiVanityURLs();
    virtual void JoinConf_ConfirmUnreliableVanityURL();

    virtual void JoinConf_VerifyMeetingInfo(VerifyMeetingInfoType type);
    virtual void JoinConf_VerifyMeetingInfoResult(VerifyMeetingInfoType type, VerifyMeetingInfoResult result);

    virtual void PTNotify_LoginSuccess(UserAccountUpdateType type);

    //////////////////////////////////////////////////////////////////////////

    //the time start from "select", length is 60 seconds, only works for call (one-on-one instant meeting)
    virtual void NotifyCallTimeout();
    
    virtual void NotifyGetSpotAppid(const CString value);

    virtual void OnLaunchConfParamReady();

    //Q&A
    virtual void OnWebinarNeedRegister(CmmBool bNeedApproval = CmmFalse);

    virtual void ResponseToCheckUpdateForComponent(OndemandComponent component, const CString& latestVersion, const CString& downloadURL);
    virtual void OnConfBindKeyValue(const CString& requestID, CmmUInt32 result);

    virtual void OnCustomMessageFromPT(CmmUInt32 type, const CmmUInt8* pMsgData, CmmUInt32 size);

    virtual void OnLogitechDeviceCommand(LOGITECH_DEVICE_CMD cmd);

    //for support center
    virtual void OnRemoteSupportRequestReceived(CMM_USERID nUserFrom, SUPPORT_CMD_TYPE eCmdType);
    virtual void OnRemoteSupportResponseReceived(CMM_USERID nUserFrom, SUPPORT_CMD_TYPE eCmdType, CmmBool bApproved);
    virtual void OnOnRemoteSupportNotificationReceived(CMM_USERID nUserFrom, SUPPORT_NOTIFICATION_TYPE eCmdType);
    virtual void IsInitShareSessionAsService(CmmBool& ret); //only for windows

    virtual void OnMyVideoDeviceRunStarted(void* hWnd, CMM_MY_VIDEO_RUN_TYPE eRunType, PMediaDevice pDeviceInfo);
    virtual void OnMyVideoRotationStatusChanged(SSB_MC_VIDEO_ROTATION_ACTION action);
    virtual void OnMyCameraCaptureSizeRatioChanged(const CString& cameraID, float fWidth2Height);

    //notify UI layer new default image is downloaded, UI layer need call ICmmVideoBkgndImageMgr::RefeshData() to load the new image from DB
    virtual void OnVideoBkgndImageDownloaded(const CString& strImagePath);

    virtual void ZoomPresence_OnGetSecurityCode(CmmUInt32 result, const CString& securityCode, const CString& securityString, const CString& directShareAesKey, const CString& directShareAesIV, const CString& limitedToken, CmmUInt64 timestamp);
    virtual void ZoomPresence_OnGetRoomAddr(CmmUInt32 result, const CString& addr);
    virtual void DirectShare_OnDeleteParingCode(CmmUInt32 result);
    virtual void DirectShare_OnBindParingCodeWithMeeting(CmmUInt32 result);
    virtual void OnShowSpeakerVolumeReminder(CmmBool show, CmmBool& ret); //if return true, VideoApp layer won't auto adjust volume

    //
    // if (0 == result) means success; or else the result means error,
    // error numbers cames from SBWebServiceErrorCode.h (only 0, 300, 3001 return)
    // other kinds of errors will do retry in conf-agent module.
    //
    virtual void OnUpgradeThisFreeMeeting(CmmUInt32 result);
    virtual void OnGetUserCMRStorageInfo(CmmUInt32 result, const SB_webservice::CMRStorage& storage);
    virtual void OnCheckCMRPrivilege(CmmUInt32 result, CmmBool canStartNow);

    virtual void OnSettingStatusChanged(ConfSettingsOption setting_option, void* param);

    virtual void OnEmojiReactionReceived(CMM_USERID sender_id, const CString& emoji_content, CmmReactionCategory emoji_category) override;
    virtual void OnEmojiReactionReceived(CMM_USERID sender_id, CmmEmojiReactionType type, CmmEmojiReactionSkinTone skin);
    virtual void OnEmojiReactionReceivedInWebinar(const EmojiContentMap &emoji_contents);

    // features is the combination of SuspendFeature, 0 means all features
    virtual void OnSuspendMeetingReceived(CmmUInt64 sender_id, CmmUInt64 suspend_features);

    virtual void OnImmersiveCmdReceived(CMM_USERID sender_id, CMM_IMMERSIVE_CMD cmd);

    virtual void OnVerifyingMyGuestRole();
    virtual void OnVerifyMyGuestRoleResult(CmmBool verify_succ, CmmBool is_guest);

    virtual void OnLeavingSilentModeStatusChanged(CMM_USERID user_id, CmmBool is_leaving_silent_mode);

  #ifdef BUILD_FOR_VDI
    virtual void OnMediaChannelConnectStatusChange(CmmBool service_available);
    virtual void OnSetVideoSourceFailure();
  #endif

    virtual void NotifyMeetingEndAndTermAudioComplete();

    virtual void OnShareFileInMeetingChat(const ShareFileInMeetingChatParam_s& share_file_info);
    virtual void OnSaveFileInMeetingChat(CmmBool result);

    virtual void OnRequestRealNameAuthSMS(const CString& request_id, RequestRealNameAuthSMSResult result);

    virtual void OnHostBindTelNotification(CmmUInt32 operator_user_id, CmmUInt32 bound_user_id, CmmBool is_bind);

    virtual void OnVirtualBackgroundSettingChanged(const CmmVideoBKReplaceSettingData& old, const CmmVideoBKReplaceSettingData& new_data);

    virtual void OnFaceMakeupDataDownloaded(CmmBool result, CmmInt32 type, CmmInt32 index, NS_ZOOM_DATA::FaceMakeupCategory cate);
    virtual void OnFaceMakeupThumbDownloaded(CmmInt32 type, CmmInt32 index, NS_ZOOM_DATA::FaceMakeupCategory cate);

    virtual void OnWindowOutOfDevice(PSSB_MC_DATA_BLOCK_SHARE_WINDOW_OUT_OF_DEVICE info);

    virtual void OnJumpToExternalURL(const CString& external_url);
    virtual void OnChatMessageDeleted(const CString& msgId, CHAT_DELETE_BY deleteBy);

    virtual void IsZoomIMUser(CmmBool& ret);

    virtual void IsDataSessionDisableUDP(ComponentType type, CmmBool& ret);
    
    //MARK:ICmmDeviceUIAPI
    virtual void OnDeviceStatusChanged(DEVICE_CMD cmd, CmmUInt32 ret = 0, CmmUInt32 handle = 0); // Along with a status code for each status
    virtual void ShowMyAudioLevel(CmmUInt32 level, CmmUInt32 handle, CmmBool isMic = CmmTrue);
    virtual void OnVolumeChange(CmmUInt32 vol, CmmBool isMic);
    virtual void OnAudioDeviceSpecialInfoChange(SSB_MC_DEVICE_SPECIAL_INFO special_info, CmmAudioDeviceBriefInfo adbi);

    virtual void OnUltraSoundDetect_PairCode(CmmBool is_timeout, const CAString& pair_code);
    virtual void OnDeviceStatelessButtonDown(const CString& device_id);
    virtual void OnDocumentCameraShareButtonPressed(const CString& deviceId);
    
    //MARK:Backstage
    virtual void OnRecvMoveGRConfirm(CmmAssignGRUserAction action, CmmBool bOk);
    virtual void OnRecvMoveGRIndication(CMM_USERID sponsor, CmmAssignGRUserAction action);
    
    virtual void OnAudioObjCreated();
    virtual void OnVideoObjCreated();
    virtual void OnShareObjCreated();
    virtual void OnRecordObjCreated();
    virtual void OnLTTObjCreated();
    
    //ZOOM-298093
    void OnUploadGalleryVideoOrderResult(CmmBool succ) override;
    void OnDownloadGalleryVideoOrderResult(CmmBool succ, const CString &data) override;
    
    void OnSimuliveWebinarAutoReplyStatusChanged(CmmBool autoReply, const CString& replyText) override;
    void OnSimuliveMasterVideoPlayerChanged(CmmUInt32 original_unique_join_index, CmmUInt32 now_unique_join_index) override;
    void OnSimuliveStartFailed() override;
    
    //MARK:ICmmConfJoinerSink
    void OnRequestPassword() override;
    void OnVerifyPasswordResult(CmmBool success) override;
    void OnRequestUserConfirm() override;
    void OnRequestWaitingForHost() override;
    void OnConnectingMMR() override;
    void OnWaitingRoomPresetAudioStatusChanged() override;
    void OnWaitingRoomPresetVideoStatusChanged() override;
    
    // MARK: FECC
    // for controller
    void OnVideoFECCControllableCameraAdded(CMM_USERID userid) override;
    void OnVideoFECCControllableCameraRemoved(CMM_USERID userid) override;
    // for controlled
    void OnVideoFECCCameraControlGroupAdded(CMM_USERID userid, FECCGroupAddmemberError error) override;
    void OnVideoFECCCameraControlGroupRemoved(CMM_USERID userid, CmmBool success) override;
    
    virtual void OnVideoRenderEvent(RENDER_EVENT_TYPE type, ICmmVideoRender* video_render, void* p_data = 0, int32_t size_of_data = 0);
    virtual void OnShareRenderEvent(RENDER_EVENT_TYPE type, ICmmASShareRender* share_render, void* p_data = 0, int32_t size_of_data = 0);
    //MARK:ProctoringMode
    virtual void OnProctoringModeContextChanged(const CmmProctoringModeContext& old_context, const CmmProctoringModeContext& new_context) override;
    //AI Companion
    virtual void OnQueryRequestResponseReceived(CmmBool is_timeout, const CmmQueryRequestResponse& response) override;
    virtual void OnReceiveRequestToStartQueryMsg(const CString& req_id, CMM_USERID sender_id) override;
    virtual void OnReceiveRequestToEnableQueryMsg(CMM_USERID sender_id) override;
    virtual void OnReceiveRequestToEnableAICMsg(CMM_USERID sender_id, CmmInt64 aic_option) override;
    virtual void OnQuerySwitchStatusChanged(CmmBool enable) override;
    virtual void OnReceiveStartQueryResponseMsg(CmmBool timeout, CmmBool agree) override;
    virtual void OnReceiveChangeQueryPrivilegeSettingReqMsg(const CString& req_id, CMM_USERID sender_id, CmmUInt8 expect_setting) override;
    virtual void OnReceiveChangeQueryPrivilegeSettingRspMsg(CmmBool timeout, CmmBool decline) override;
    
    virtual void OnReceiveRequestToEnableSummaryMsg(CMM_USERID senderId) override;
    virtual void OnReceiveRequestToStartSummaryMsg(const CString& reqId, CMM_USERID senderId) override;
    virtual void OnReceiveStartSummaryRspMsg(CmmBool bTimeOut, CmmBool decline) override;
    virtual void OnSummaryFeatureOnStatusChanged(CmmBool summaryEnabled) override;
    virtual void OnReceiveSwitchAICResponseMsg(CmmBool timeout, CmmBool agree, SWITCH_AIC_ACTION switch_action) override;
    virtual void OnReceiveSwitchAICRequestMsg(const CString& req_id, CMM_USERID sender_id, CmmInt64 aic_opton, SWITCH_AIC_ACTION switch_action) override;
    virtual void OnAICompanionFeatureVisableChanged(CMM_AI_COMPANION feature, CmmBool visable) override;
    virtual void OnReportActivityForTranscriptResultReceived(const CString& reportId, CMM_ACTIVITY_TYPE_ABOUT_TRANSCRIPT type, CmmBool result) override;
    virtual void OnReqDeleteAICompanionAssetsResuleReceived(CmmInt64 aic_option, CmmBool success) override;
    virtual void OnSpeakerDiarizationUpdated(const audio_speaker_diarization_info_t* info) override;

    //MARK: ZE Companion Mode
    virtual void OnLeaveCompanionModeReqReceived(CMM_USERID senderId) override;
    virtual void OnLeaveCompanionModeRspReceived(CmmBool agreed, CMM_USERID senderId) override;
    //MultipleCMA
    virtual void OnCMARegionStatusChanged(const CString& region, archive_gw_status status) override;
    //CMR
    virtual void OnEnableSmartRecordingResult(CmmBool succ, CmmInt64 error_code) override;
    virtual void OnStartCMRRequestReceived(const CString& reqID, CMM_USERID senderId) override;
    virtual void OnStartCMRRequestResponseReceived(CmmBool bTimeOut, CmmBool bDecline) override;
    virtual void OnDynamicLayoutChanged() override;
    
    // for gallery plus wallpaer
    virtual void OnGalleryPlusWallpaperChanged(CMM_USERID sender_id, const CString& wallpaper_id) override;
    virtual void OnGalleryPlusTransparencyChanged(CMM_USERID sender_id, CmmInt32 transparency) override;
    virtual void OnGalleryPlusLayoutModeChanged(CMM_USERID sender_id, GALLEY_PLUS_LAYOUT_MODE layout_mode) override;

    // MARK: multi share alert
    virtual void OnReceiveEnableMultiShareRequestMsg(const CString& req_id, CMM_USERID sender_id) override;
    virtual void OnReceiveEnableMultiShareResponseMsg(CmmEnableMultiShareResponseStatus status) override;
    
#pragma mark - UniversalUI
    ZM_OVERRIDE_GET_INTERFACE(ICmmConfUIAPI) {return this;};
    ZM_OVERRIDE_GET_INTERFACE(NS_ZM_UNIVERSAL_UI::IZmDllInfoApi) {return this;};
    virtual NS_ZM_UNIVERSAL_UI::AtDll GetAtDll() override { return NS_ZM_UNIVERSAL_UI::AtDll::kAtDllZVideoUi;}

    void RegisterDispatcherSink(const CmmConfInstType& conf_inst_type, const CmmUInt16& room_id);
    void UnRegisterDispatcherSink();
    
    //MARK: media stream
    virtual void OnCommonDiclaimerReceived(const CString& notice_id, CmmInt32 notice_status, const CmmDisclaimerInfo& disclaimer) override;
    virtual void OnIndicatorAppStatusUpdated(const CString& notice_id, const CmmIndicatorAppItem& indicator_app) override;
    virtual void OnIndicatorTabReceived(const CString& tab_id, const CmmIndicatorTab& indicator_tab) override;
    virtual void OnToastStatusUpdated(const CString& notice_id, CmmInt32 notice_status, const CmmToast& toast) override;
    virtual void OnCommonNoticeDeleted(const CmmNoticeSet& cmm_notice) override;
    virtual void OnIndicatorTabDeleted(const CString& tab_id) override;
    virtual void OnZoomStreamingServiceSwitchChanged(CmmBool new_switch) override;
    virtual void OnZssStatusChanged(const CmmGwInstInfo& zss_info) override;
    virtual void OnPersonalWallpaperConfigChanged() override;
    virtual void OnPersonalWallpaperDownloadStatus(const CString& wallpaper_id, PersonalWallpaperDownloadStatus status) override;
    virtual void OnPersonalWallpaperThumbDownloadStatus(const CString& wallpaper_id, PersonalWallpaperDownloadStatus status) override;
    virtual void OnPSLMixShareInfoChanged(const SSB_MC_DATA_BLOCK_PS_MIX_SHARE_INFO& info) override;
    
    //MARK: clinical note
    virtual void OnReceiveSwitchClinicalNoteRequestMsg(const CString& req_id, CMM_USERID sender_id, SWITCH_CN_ACTION switch_action) override;
    virtual void OnReceiveSwitchClinicalNoteResponseMsg(CmmBool is_timeout, CmmBool is_decline, SWITCH_CN_ACTION switch_action) override;
    virtual void OnClinicalNoteStatusChanged(const CmmGwInstInfo& cn_info) override;
    virtual void OnCreateClinicalNoteSessionFailed(CMM_CN_ERROR_CODE err_code) override;
    virtual void OnAICompanionTokenReceived(CmmBool success, const CString& req_id, const CString& token) override;

    //MARK: RTMS
    virtual void OnRTMSGwStatusChanged(const CmmGwInstInfo& rtms_info) override;
    
    //MARK: live summary
    virtual void OnSmartAgendaDocIdReceived(const CString& doc_id) override;
    virtual void OnLiveSummaryDocUpdated(const CString& docId) override;
    virtual void OnSummaryShareLevelChanged(CmmInt32 new_level) override;
    virtual void OnLiveSummarySettingChanged(CmmBool is_live_summary_enabled) override;
    virtual void OnReceiveSwitchAICompanionWithLiveSummaryRequestMsg(const CString& req_id, CMM_USERID sender_id, CmmInt64 aic_option, SWITCH_AIC_ACTION switch_action) override;    
    virtual void OnReceiveSwitchAICompanionWithLiveSummaryResponseMsg(CmmInt64 aic_option, CmmBool timeout, CmmBool agree, SWITCH_AIC_ACTION switch_action) override;
    
    //MARK: billing meeting
    virtual void OnRcvContactStatusCheckRes(CmmBool is_my_contact, const CString& jid, const CString& contact_name) override;
    virtual void OnPSLInviteRequested(CmmBool status, CmmInt32 errorCode, const CAString& errorMessage, CmmBool result) override;
    virtual void OnPSLLiveLayoutChanged(CmmUInt32 sender, const CmmPSLLayout& layout) override;
    virtual void OnPSLControlCommandChanged(const CmmRSGWControlData& data) override;

    //MARK: vb
    virtual void CanUseVirtualBackgroundNow(CmmBool& ret) override;
    virtual void CanUseErasedBackgroundNow(CmmBool& ret) override;
    virtual void CanUseEnhancedBackgroundNow(CmmBool& ret) override;
    virtual void CanUseVideo3DAvatarNow(CmmBool& ret) override;
    virtual void CanUseAudio3DAvatarNow(CmmBool& ret) override;
    virtual void CanUseVideoFilterNow(CmmBool& ret) override;
    virtual void CanUseStudioEffectNow(CmmBool& ret) override;

    virtual void OnNeedPromptBiometricDisclaimer() override;
    virtual void OnNeedUpdateEnhancedPortraitPosition() override;
    
    //MARK: avatar
    virtual void OnAvatarDataUpdate(const CString& jid) override;
    //MARK: Recording
    virtual void NotifyGetUserRecordPic(SSB_MC_RECORDER_USER_VIDEO_GET_PIC_INFO type, uint32_t user_id) override;
    
    //MARK: far end audio control
    virtual void OnRemoteUserRequestedAudioControlByAutoFEAC(CMM_USERID controllerUserID) override;
    virtual void OnRemoteUserRequestedAudioControl(CMM_USERID userId) override;
    virtual void OnRemoteUserApprovedAudioControl(CMM_USERID userId) override;
    virtual void OnRemoteUserApprovedAudioControlByAutoFEAC(CMM_USERID controlledUserID) override;
    virtual void OnRemoteUserDeclinedAudioControl(CMM_USERID userId) override;
    virtual void OnRemoteUserStoppedAudioControl(CMM_USERID userId) override;
    virtual void OnRemoteUserGaveUpAudioControl(CMM_USERID userId) override;
    virtual void OnRemoteUserTookOverAudioControl(CMM_USERID userId,CMM_USERID remoteUserControllingUserId) override;
    virtual void OnRemoteAudioDeviceUpdate(const RemoteAudioDeviceInfo& deviceInfo, DeviceUpdateType updateType) override;
    virtual void OnFEACUnMuteDisabledByHost(CMM_USERID controlledUserID) override;
    virtual void OnAudioDeviceControlGroupOneRemoved(CMM_USERID sender_id, CmmBool ret) override;
    virtual void OnAudioDeviceControlGroupOneAdded(CMM_USERID sender_id, CmmBool ret) override;
    virtual void OnUserAudioDeviceControlAutoAcceptStatusChanged(CMM_USERID sender_id, CmmBool allow) override;
    
    virtual void OnHandGestureDetected(const SSB_MC_DATA_BLOCK_HAND_POSE_INFO& info) override;

    virtual void NotifyToGetMeetingInviteesInfoBeforeLeaving() override;
    
protected:
    ZMConfBaseSinkAdapter   *m_sinkAdapter;
    
    CmmConfInstType         m_confInstType;
    CmmUInt16                     m_roomID;
};
