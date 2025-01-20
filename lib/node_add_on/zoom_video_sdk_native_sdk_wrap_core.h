#ifndef _zoom_video_sdk_native_sdk_wrap_core_h_
#define _zoom_video_sdk_native_sdk_wrap_core_h_
#include "zoom_video_sdk_native_sdk_wrap_core_def.h"
#include "zoom_video_sdk_sinks_wrap_class.h"
#include "zoom_video_sdk_native_session_info_wrap_core.h"
#include "zoom_video_sdk_native_audio_helper_wrap_core.h"
#include "zoom_video_sdk_native_video_helper_wrap_core.h"
#include "zoom_video_sdk_native_share_helper_wrap_core.h"
#include "zoom_video_sdk_native_user_helper_wrap_core.h"
#include "zoom_video_sdk_native_chat_helper_wrap_core.h"
#include "zoom_video_sdk_native_livestream_helper_wrap_core.h"
#include "zoom_video_sdk_native_shareinfo_helper_wrap_core.h"
#include "zoom_video_sdk_native_cmd_channel_helper_wrap_core.h"
#include "zoom_video_sdk_native_phone_helper_wrap_core.h"
#include "zoom_video_sdk_native_recording_helper_wrap_core.h"
#include "zoom_video_sdk_native_remote_camera_control_helper_wrap_core.h"
#include "zoom_video_sdk_native_audio_setting_wrap_core.h"
#include "zoom_video_sdk_native_live_transcription_helper_wrap_core.h"
#include "zoom_video_sdk_native_share_setting_wrap_core.h"


USING_ZOOM_VIDEO_SDK_NAMESPACE;

typedef ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK*(*fnCreateZoomVideoSDKObj)();
typedef void(*fnDestroyZoomVideoSDKObj)();

class ZOOM_HIDE_SYMBOL ZNativeVideoSDKWrap
{
public:
	ZNativeVideoSDKWrap();
	virtual ~ZNativeVideoSDKWrap();
	void SetSink(ZNativeZoomVideoSDKSinksWrap* pSink);
	ZNZoomVideoSDKErrors CreateZoomVideoSDKObj(ZoomSTRING path);
	ZNZoomVideoSDKErrors DestroyZoomVideoSDKObj();
	ZNZoomVideoSDKErrors Initialize(ZNZoomVideoSDKInitParams& initParam);
	ZNZoomVideoSDKErrors CleanUp();
	ZNZoomVideoSDKErrors JoinSession(ZNZoomVideoSDKSessionContext& joinParams);
	ZNZoomVideoSDKErrors LeaveSession(bool bEnd);
	ZNZoomVideoSDKErrors InputSessionPassword(ZoomSTRING passWord); //only valid when get the onSessionNeedPassword/onSessionPasswordWrong callback
	ZNZoomVideoSDKErrors LeaveSessionIgnorePassword(); //only valid when get the onSessionNeedPassword/onSessionPasswordWrong callback
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* GetVideoSDKObj();
	bool IsValidUser(IZoomVideoSDKUser* pUser);

	bool IsInSession();
	ZoomSTRING GetSDKVersion();
	ZCmdChannelHelperWrap& GetCmdChannelWrap();
	ZPhoneHelperWrap& GetPhoneHelperWrap();
	ZRecordingHelperWrap& GetRecordingHelperWrap();
	ZRemoteCameraControlHelperWrap& GetRemoteCameraCtrlHelperWrap();
	ZSessionInfoWrap& GetSessionInfoWrap();
	ZAudioHelperWrap& GetAudioHelperWrap();
	ZAudioSettingWrap& GetAudioSettingWrap();
	ZTestAudioDeviceWrap& GetTestAudioDeviceWrap();
	ZVideoHelperWrap& GetVideoHelperWrap();
	ZShareHelperWrap& GetShareHelperWrap();
	ZShareInfoHelperWrap& GetShareInfoHelperWrap();
	ZUserHelperWrap& GetUserHelperWrap();
	ZChatHelperWrap& GetChatHelperWrap();
	ZLiveStreamHelperWrap& GetLiveStreamHelperWrap();
	ZIncomingLiveStreamHelperWrap& GetIncomingLiveStreamHelperWrap();
	ZLiveTranscriptionHelperWrap& GetLiveTranscriptionHelperWrap();
	ZShareSettingWrap& GetShareSettingWrap();
	//ZNativeVideoSDKVideoSource& GetVideoSourceWrap();

	void onSessionJoin();
	void onSessionLeave();
	void onSessionLeave(ZNZoomVideoSDKSessionLeaveReason eReason);
	void onError(ZNZoomVideoSDKErrors errorCode, int detailErrorCode);
	void onUserJoin(ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<IZoomVideoSDKUser*>* userList);
	void onUserLeave(ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<IZoomVideoSDKUser*>* userList);
	void onUserVideoStatusChanged(ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<IZoomVideoSDKUser*>* userList);
	void onUserAudioStatusChanged(ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<IZoomVideoSDKUser*>* userList);
	void onUserShareStatusChanged(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKShareAction* pShareAction);
	void onLiveStreamStatusChanged(ZNZoomVideoSDKLiveStreamStatus status);
	void onChatNewMessageNotify( ZNZoomVideoSDKChatMessageInfo messageInfo);
	void onChatMsgDeleteNotification(ZoomSTRING msgID, ZNZoomVideoSDKChatMessageDeleteType deleteBy);
	void onUserHostChanged(IZoomVideoSDKUser* pUser);
	void onUserManagerChanged(IZoomVideoSDKUser* pUser);
	void onUserNameChanged(IZoomVideoSDKUser* pUser);
	void onUserActiveAudioChanged(ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<IZoomVideoSDKUser*>* list);
	void onSessionNeedPassword();
	void onSessionPasswordWrong();
	void onMixedAudioRawDataReceived(AudioRawData* data_);
	void onOneWayAudioRawDataReceived(AudioRawData* data_, IZoomVideoSDKUser* pUser);
	void onSharedAudioRawDataReceived(AudioRawData* data_);
	void onCommandReceived(IZoomVideoSDKUser* pSender, ZoomSTRING strCmd);
	void onCommandChannelConnectResult(bool isSuccess);
	void onCloudRecordingStatus(ZNRecordingStatus status);
	void onCameraControlRequestResult(IZoomVideoSDKUser* pUser, bool isApproved);
	void onCameraControlRequestReceived(IZoomVideoSDKUser* pUser, ZNZoomVideoSDKCameraControlRequestType requestType);
	void onHostAskUnmute();
	void onInviteByPhoneStatus(ZNPhoneStatus status, ZNPhoneFailedReason reason);
	void onMultiCameraStreamStatusChanged(ZNZoomVideoSDKMultiStreamStatus status, ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRawDataPipe* pVideoPipe);
	/// \brief Notify the current mic or speaker volume when testing.
	/// \param micVolume Specify the volume of the mic when testing or in session.
	/// \param speakerVolume Specify the volume of the speaker when testing.
	void onMicSpeakerVolumeChanged(unsigned int micVolume, unsigned int speakerVolume);
	void onAudioDeviceStatusChanged(ZNZoomVideoSDKAudioDeviceType type, ZNZoomVideoSDKAudioDeviceStatus status);
	void onTestMicStatusChanged(ZNZoomVideoSDK_TESTMIC_STATUS status);
	void onSelectedAudioDeviceChanged();
	void onLiveTranscriptionStatus(ZNZoomVideoSDKLiveTranscriptionStatus status);
	void onLiveTranscriptionMsgError(ILiveTranscriptionLanguage* spokenLanguage, ILiveTranscriptionLanguage* transcriptLanguage);
	void onLiveTranscriptionMsgInfoReceived(ZNLiveTranscriptionMessageInfo messageInfo);
	void onOriginalLanguageMsgReceived(ZNLiveTranscriptionMessageInfo messageInfo);
	void onCalloutJoinSuccess(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, ZoomSTRING phoneNumber);
	void onSpotlightVideoChanged(ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<IZoomVideoSDKUser*>* userList);
	void onBindIncomingLiveStreamResponse(bool bSuccess, ZoomSTRING strStreamKeyID);
	void onUnbindIncomingLiveStreamResponse(bool bSuccess, ZoomSTRING strStreamKeyID);
	void onIncomingLiveStreamStatusResponse(bool bSuccess, ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<IncomingLiveStreamStatus>* pStreamsStatusList);
	void onStartIncomingLiveStreamResponse(bool bSuccess, ZoomSTRING strStreamKeyID);
	void onStopIncomingLiveStreamResponse(bool bSuccess, ZoomSTRING strStreamKeyID);
	void onFailedToStartShare(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser);
#if (!defined __linux)
	void onRemoteControlStatus(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, IZoomVideoSDKShareAction* pShareAction, ZNZoomVideoSDKRemoteControlStatus status);
	void onRemoteControlRequestReceived(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, IZoomVideoSDKShareAction* pShareAction);
#endif
#if (defined _WIN32)
	void onRemoteControlServiceInstallResult(bool bSuccess);
#endif

private:
	bool ConfigSDKModule(ZoomSTRING& path);
	void Reset();
	bool m_bInit;
	fnCreateZoomVideoSDKObj m_fnCreateZoomVideoSDKObj;
	fnDestroyZoomVideoSDKObj m_fnDestroyZoomVideoSDKObj;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* m_pVideoSDK;
	ZSessionInfoWrap m_SessionInfoCtrl;
	ZAudioHelperWrap m_AudioHelper;
	ZVideoHelperWrap m_VideoHelper;
	ZShareHelperWrap m_ShareHelper;
	ZShareInfoHelperWrap m_ShareInfoHelper;
	ZUserHelperWrap m_UserHelper;
	ZChatHelperWrap m_ChatHelper;
	ZCmdChannelHelperWrap m_CmdChannelHelper;
	ZPhoneHelperWrap m_PhoneHelper;
	ZRecordingHelperWrap m_RecordingHelper;
	ZLiveStreamHelperWrap m_LiveStreamHelper;
	ZIncomingLiveStreamHelperWrap m_IncomingLiveStreamHelper;
	ZRemoteCameraControlHelperWrap m_RemoteCameraCtrlHelper;
	ZAudioSettingWrap m_AudioSetting;
	ZTestAudioDeviceWrap m_TestAudioDevice;
	ZLiveTranscriptionHelperWrap m_LTTHelper;
	ZShareSettingWrap m_ShareSetting;
	ZNativeZoomVideoSDKSinksWrap* m_pSink;

};
#endif