#ifndef _zoom_video_sdk_events_wrap_class_h_
#define _zoom_video_sdk_events_wrap_class_h_

#include "zoom_video_sdk_native_sdk_wrap_core_def.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"
#include "export_h/zoom_video_sdk_chat_message_interface.h"
#include "export_h/zoom_video_sdk_password_handler_interface.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ZNZoomVideoSDKPasswordHandler
{
public:
	~ZNZoomVideoSDKPasswordHandler()
	{
		m_pHandler = NULL;
	}
	static ZNZoomVideoSDKPasswordHandler& GetInst()
	{
		static ZNZoomVideoSDKPasswordHandler inst;
		return inst;
	}
	void SetHandler(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKPasswordHandler* handler)
	{
		m_pHandler = handler;
	}
	ZNZoomVideoSDKErrors InputSessionPassword(ZoomSTRING password)
	{
		ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Wrong_Usage;
		if (m_pHandler)
		{
			err = (ZNZoomVideoSDKErrors)m_pHandler->inputSessionPassword(password.c_str());
		}
		m_pHandler = NULL;
		return err;
	}
	ZNZoomVideoSDKErrors LeaveSessionIgnorePassword()
	{
		ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Wrong_Usage;
		if (m_pHandler)
		{
			err = (ZNZoomVideoSDKErrors)m_pHandler->leaveSessionIgnorePassword();
		}
		m_pHandler = NULL;
		return err;
	}
private:
	ZNZoomVideoSDKPasswordHandler() :m_pHandler(NULL) {}
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKPasswordHandler* m_pHandler;
};

class ZNZoomVideoSDKCameraControlRequestHandler
{
public:
	~ZNZoomVideoSDKCameraControlRequestHandler()
	{
		m_pHandler = NULL;
	}
	static ZNZoomVideoSDKCameraControlRequestHandler& GetInst()
	{
		static ZNZoomVideoSDKCameraControlRequestHandler inst;
		return inst;
	}
	void SetHandler(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKCameraControlRequestHandler* handler)
	{
		m_pHandler = handler;
	}
	ZNZoomVideoSDKErrors Approve()
	{
		ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Wrong_Usage;
		if (m_pHandler)
		{
			err = (ZNZoomVideoSDKErrors)m_pHandler->approve();
		}
		m_pHandler = NULL;
		return err;
	}
	ZNZoomVideoSDKErrors Decline()
	{
		ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Wrong_Usage;
		if (m_pHandler)
		{
			err = (ZNZoomVideoSDKErrors)m_pHandler->decline();
		}
		m_pHandler = NULL;
		return err;
	}
private:
	ZNZoomVideoSDKCameraControlRequestHandler() :m_pHandler(NULL) {}
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKCameraControlRequestHandler* m_pHandler;
};

#if (!defined __linux)
class ZNZoomVideoSDKRemoteControlHelper
{
public:
	~ZNZoomVideoSDKRemoteControlHelper()
	{
		m_pHelper = NULL;
	}
	static ZNZoomVideoSDKRemoteControlHelper& GetInst()
	{
		static ZNZoomVideoSDKRemoteControlHelper inst;
		return inst;
	}
	void SetHelper(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRemoteControlHelper* pHelper)
	{
		m_pHelper = pHelper;
	}
	bool CanRequestControl()
	{
		bool bret = false;
		if (m_pHelper)
		{
			bret = m_pHelper->canRequestControl();
		}
		return bret;
	}
	ZNZoomVideoSDKErrors RequestRemoteControl()
	{
		ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Wrong_Usage;
		if (m_pHelper)
		{
			err = (ZNZoomVideoSDKErrors)m_pHelper->requestRemoteControl();
		}
		return err;
	}
	ZNZoomVideoSDKErrors EndRemoteControl()
	{
		ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Wrong_Usage;
		if (m_pHelper)
		{
			err = (ZNZoomVideoSDKErrors)m_pHelper->endRemoteControl();
		}
		return err;
	}
	bool CanRemoteControl()
	{
		bool bret = false;
		if (m_pHelper)
		{
			bret = m_pHelper->canRemoteControl();
		}
		return bret;
	}
	ZNZoomVideoSDKErrors EnterRemoteControl()
	{
		ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Wrong_Usage;
		if (m_pHelper)
		{
			err = (ZNZoomVideoSDKErrors)m_pHelper->enterRemoteControl();
		}
		return err;
	}
	bool IsRemoteControlling()
	{
		bool bret = false;
		if (m_pHelper)
		{
			bret = m_pHelper->isRemoteControlling();
		}
		return bret;
	}
	ZNZoomVideoSDKErrors LeaveRemoteControl()
	{
		ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Wrong_Usage;
		if (m_pHelper)
		{
			err = (ZNZoomVideoSDKErrors)m_pHelper->leaveRemoteControl();
		}
		return err;
	}
private:
	ZNZoomVideoSDKRemoteControlHelper() :m_pHelper(NULL) {}
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRemoteControlHelper* m_pHelper;
};

class ZNZoomVideoSDKRemoteControlRequestHandler
{
public:
	~ZNZoomVideoSDKRemoteControlRequestHandler()
	{
		m_pHandler = NULL;
	}
	static ZNZoomVideoSDKRemoteControlRequestHandler& GetInst()
	{
		static ZNZoomVideoSDKRemoteControlRequestHandler inst;
		return inst;
	}
	void SetHandler(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRemoteControlRequestHandler* handler)
	{
		m_pHandler = handler;
	}
	ZNZoomVideoSDKErrors Approve()
	{
		ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Wrong_Usage;
		if (m_pHandler)
		{
			err = (ZNZoomVideoSDKErrors)m_pHandler->approve();
		}
		m_pHandler = NULL;
		return err;
	}
	ZNZoomVideoSDKErrors Deny()
	{
		ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Wrong_Usage;
		if (m_pHandler)
		{
			err = (ZNZoomVideoSDKErrors)m_pHandler->deny();
		}
		m_pHandler = NULL;
		return err;
	}
private:
	ZNZoomVideoSDKRemoteControlRequestHandler() :m_pHandler(NULL) {}
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRemoteControlRequestHandler* m_pHandler;
};
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeZoomVideoSDKDelegate : public ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKDelegate
{
public:
	void SetOwner(ZNativeVideoSDKWrap* obj) { owner_ = obj; }
	virtual void onSessionJoin() 
	{
		if (owner_) 
		{
			owner_->onSessionJoin();
		}
	}
	virtual void onSessionLeave() 
	{
	
	}
	virtual void onSessionLeave(ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKSessionLeaveReason eReason)
	{
		if (owner_)
		{
			owner_->onSessionLeave((ZNZoomVideoSDKSessionLeaveReason)eReason);
		}
	}
	virtual void onError(ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors errorCode, int detailErrorCode)
	{
		if (owner_) 
		{
			owner_->onError((ZNZoomVideoSDKErrors)errorCode, detailErrorCode);
		}
	}
	virtual void onUserJoin(IZoomVideoSDKUserHelper* pUserHelper, ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<IZoomVideoSDKUser*>* userList)
	{
		if (owner_ && pUserHelper && userList)
		{
			owner_->onUserJoin(userList);
		}
	}
	virtual void onUserLeave(IZoomVideoSDKUserHelper* pUserHelper, ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<IZoomVideoSDKUser*>* userList)
	{
		if (owner_ && pUserHelper && userList)
		{
			owner_->onUserLeave(userList);
		}
	}
	virtual void onUserVideoStatusChanged(IZoomVideoSDKVideoHelper* pVideoHelper, ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<IZoomVideoSDKUser*>* userList)
	{
		if (owner_ && pVideoHelper && userList)
		{
			owner_->onUserVideoStatusChanged(userList);
		}
	}
	virtual void onUserAudioStatusChanged(IZoomVideoSDKAudioHelper* pAudioHelper, ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<IZoomVideoSDKUser*>* userList)
	{
		if (owner_ && pAudioHelper && userList)
		{
			owner_->onUserAudioStatusChanged(userList);
		}
	}
	virtual void onUserShareStatusChanged(IZoomVideoSDKShareHelper* pShareHelper, IZoomVideoSDKUser* pUser, IZoomVideoSDKShareAction* pShareAction)
	{
		if (owner_ && pShareHelper && pUser && pShareAction)
		{
			owner_->onUserShareStatusChanged(pUser, pShareAction);
		}
	}
	virtual void onFailedToStartShare(IZoomVideoSDKShareHelper* pShareHelper, IZoomVideoSDKUser* pUser)
	{
		if (owner_ && pShareHelper && pUser)
		{
			owner_->onFailedToStartShare(pUser);
		}
	}
	virtual void onLiveStreamStatusChanged(IZoomVideoSDKLiveStreamHelper* pLiveStreamHelper, ZoomVideoSDKLiveStreamStatus status)
	{
		if (owner_ && pLiveStreamHelper)
		{
			owner_->onLiveStreamStatusChanged((ZNZoomVideoSDKLiveStreamStatus)status);
		}
	}
	virtual void onChatNewMessageNotify(IZoomVideoSDKChatHelper* pChatHelper, IZoomVideoSDKChatMessage* messageItem)
	{
		if (owner_ && messageItem && pChatHelper)
		{
			ZNZoomVideoSDKChatMessageInfo sdk_chat_message;
			IZoomVideoSDKUser* pSendUser = messageItem->getSendUser();
            sdk_chat_message.pSender = (int64_t)pSendUser;
			if (pSendUser)
			{
				sdk_chat_message.senderName = pSendUser->getUserName();
			}
			IZoomVideoSDKUser* pReceiveUser = messageItem->getReceiveUser();
            sdk_chat_message.pReceiver = (int64_t)pReceiveUser;
			if (pReceiveUser)
			{
				sdk_chat_message.receiverName = pReceiveUser->getUserName();
			}
			sdk_chat_message.messageContent = messageItem->getContent();
			sdk_chat_message.timeStamp = messageItem->getTimeStamp();
			sdk_chat_message.isChatToAll = messageItem->isChatToAll();
			sdk_chat_message.isSelfSend = messageItem->isSelfSend();
			sdk_chat_message.messageID = messageItem->getMessageID();
			owner_->onChatNewMessageNotify(sdk_chat_message);
		}
	}
	virtual void onChatMsgDeleteNotification(IZoomVideoSDKChatHelper* pChatHelper, const zchar_t* msgID, ZoomVideoSDKChatMessageDeleteType deleteBy)
	{
		if (owner_ && msgID && pChatHelper)
		{
			ZoomSTRING zn_msgID = msgID;
			owner_->onChatMsgDeleteNotification(zn_msgID,(ZNZoomVideoSDKChatMessageDeleteType)deleteBy);
		}
	}
	virtual void onUserHostChanged(IZoomVideoSDKUserHelper* pUserHelper, IZoomVideoSDKUser* pUser)
	{
		if (owner_ && pUserHelper && pUser)
		{
			owner_->onUserHostChanged(pUser);
		}
	}
	virtual void onUserActiveAudioChanged(IZoomVideoSDKAudioHelper* pAudioHelper, ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<IZoomVideoSDKUser*>* list)
	{
		if (owner_ && pAudioHelper && list)
		{
			owner_->onUserActiveAudioChanged(list);
		}
	}
	virtual void onSessionNeedPassword(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKPasswordHandler* handler) 
	{
		if (owner_ && handler)
		{
			ZNZoomVideoSDKPasswordHandler::GetInst().SetHandler(handler);
			owner_->onSessionNeedPassword();
		}
	}
	virtual void onSessionPasswordWrong(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKPasswordHandler* handler) 
	{
		if (owner_ && handler)
		{
			ZNZoomVideoSDKPasswordHandler::GetInst().SetHandler(handler);
			owner_->onSessionPasswordWrong();
		}
	}
	virtual void onCommandReceived(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pSender, const zchar_t* strCmd)
	{
		if (owner_ && pSender)
		{
			owner_->onCommandReceived(pSender, strCmd);
		}
	}
	virtual void onCommandChannelConnectResult(bool isSuccess)
	{
		if (owner_)
		{
			owner_->onCommandChannelConnectResult(isSuccess);
		}
	}
	virtual void onHostAskUnmute()
	{
		if (owner_)
		{
			owner_->onHostAskUnmute();
		}
	}
	virtual void onInviteByPhoneStatus(ZOOM_VIDEO_SDK_NAMESPACE::PhoneStatus status, ZOOM_VIDEO_SDK_NAMESPACE::PhoneFailedReason reason)
	{
		if (owner_)
		{
			owner_->onInviteByPhoneStatus((ZNPhoneStatus)status, (ZNPhoneFailedReason)reason);
		}
	}
	virtual void onCloudRecordingStatus(ZOOM_VIDEO_SDK_NAMESPACE::RecordingStatus status, IZoomVideoSDKRecordingConsentHandler* pHandler)
	{
		if (owner_)
		{
			owner_->onCloudRecordingStatus((ZNRecordingStatus)status);
		}
	}
	virtual void onCameraControlRequestResult(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, bool isApproved)
	{
		if (owner_ && pUser)
		{
			owner_->onCameraControlRequestResult(pUser, isApproved);
		}
	}
	virtual void onCameraControlRequestReceived(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKCameraControlRequestType requestType, ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKCameraControlRequestHandler* pCameraControlRequestHandler)
	{
		if (owner_ && pUser)
		{
			if (pCameraControlRequestHandler)
			{
				ZNZoomVideoSDKCameraControlRequestHandler::GetInst().SetHandler(pCameraControlRequestHandler);
			}
			owner_->onCameraControlRequestReceived(pUser, (ZNZoomVideoSDKCameraControlRequestType)requestType);
		}
	}
	virtual void onMultiCameraStreamStatusChanged(ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKMultiCameraStreamStatus status, ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRawDataPipe* pVideoPipe)
	{
		if (owner_)
		{
			owner_->onMultiCameraStreamStatusChanged((ZNZoomVideoSDKMultiStreamStatus)status, pUser, pVideoPipe);
		}
	}
	virtual void onMicSpeakerVolumeChanged(unsigned int micVolume, unsigned int speakerVolume)
	{
		if (owner_)
		{
			owner_->onMicSpeakerVolumeChanged(micVolume, speakerVolume);
		}
	}
	virtual void onAudioDeviceStatusChanged(ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKAudioDeviceType type, ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKAudioDeviceStatus status)
	{
		if (owner_)
		{
			owner_->onAudioDeviceStatusChanged((ZNZoomVideoSDKAudioDeviceType)type, (ZNZoomVideoSDKAudioDeviceStatus)status);
		}
	}
	virtual void onTestMicStatusChanged(ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDK_TESTMIC_STATUS status)
	{
		if (owner_)
		{
			owner_->onTestMicStatusChanged((ZNZoomVideoSDK_TESTMIC_STATUS)status);
		}
	}
	virtual void onSelectedAudioDeviceChanged()
	{
		if (owner_)
		{
			owner_->onSelectedAudioDeviceChanged();
		}
	}
	virtual void onLiveTranscriptionStatus(ZoomVideoSDKLiveTranscriptionStatus status)
	{
		if (owner_)
		{
			owner_->onLiveTranscriptionStatus((ZNZoomVideoSDKLiveTranscriptionStatus)status);
		}
	}
	virtual void onLiveTranscriptionMsgError(ILiveTranscriptionLanguage* spokenLanguage, ILiveTranscriptionLanguage* transcriptLanguage)
	{
		if (owner_)
		{
			owner_->onLiveTranscriptionMsgError(spokenLanguage, transcriptLanguage);
		}
	}
	virtual void onMixedAudioRawDataReceived(AudioRawData* data_)
	{
		if (owner_ && data_)
		{
			owner_->onMixedAudioRawDataReceived(data_);
		}
	}
	virtual void onOneWayAudioRawDataReceived(AudioRawData* data_, IZoomVideoSDKUser* pUser)
	{
		if (owner_ && data_ && pUser)
		{
			owner_->onOneWayAudioRawDataReceived(data_, pUser);
		}
	}
	virtual void onUserManagerChanged(IZoomVideoSDKUser* pUser)
	{
		if (owner_ && pUser)
		{
			owner_->onUserManagerChanged(pUser);
		}
	}
	virtual void onUserNameChanged(IZoomVideoSDKUser* pUser)
	{
		if (owner_ && pUser)
		{
			owner_->onUserNameChanged(pUser);
		}
	}
	virtual void onSharedAudioRawDataReceived(AudioRawData* data_)
	{
		if (owner_ && data_)
		{
			owner_->onSharedAudioRawDataReceived(data_);
		}
	}
	virtual void onProxyDetectComplete()
	{

	}
	virtual void onProxySettingNotification(IZoomVideoSDKProxySettingHandler* handler)
	{

	}
	virtual void onSSLCertVerifiedFailNotification(IZoomVideoSDKSSLCertificateInfo* handler)
	{

	}
	virtual void onUserVideoNetworkStatusChanged(ZoomVideoSDKNetworkStatus status, IZoomVideoSDKUser* pUser)
	{
		
	}
	virtual void onUserRecordingConsent(IZoomVideoSDKUser* pUser)
	{

	}
	virtual void onLiveTranscriptionMsgInfoReceived(ILiveTranscriptionMessageInfo* messageInfo)
	{
		if (owner_ && messageInfo)
		{
			ZNLiveTranscriptionMessageInfo sdk_message_info;
			if (messageInfo->getMessageID())
			{
				sdk_message_info.messageID = messageInfo->getMessageID();
			}
			if (messageInfo->getMessageContent())
			{
				sdk_message_info.messageContent = messageInfo->getMessageContent();
			}
			if (messageInfo->getSpeakerID())
			{
				sdk_message_info.speakerID = messageInfo->getSpeakerID();
			}
			if (messageInfo->getSpeakerName())
			{
				sdk_message_info.speakerName = messageInfo->getSpeakerName();
			}
			sdk_message_info.timeStamp = messageInfo->getTimeStamp();
			sdk_message_info.messageType = (ZNZoomVideoSDKLiveTranscriptionOperationType)messageInfo->getMessageType();
			owner_->onLiveTranscriptionMsgInfoReceived(sdk_message_info);
		}
	}
	virtual void onOriginalLanguageMsgReceived(ILiveTranscriptionMessageInfo* messageInfo)
	{
		if (owner_ && messageInfo)
		{
			ZNLiveTranscriptionMessageInfo sdk_message_info;
			if (messageInfo->getMessageID())
			{
				sdk_message_info.messageID = messageInfo->getMessageID();
			}
			if (messageInfo->getMessageContent())
			{
				sdk_message_info.messageContent = messageInfo->getMessageContent();
			}
			if (messageInfo->getSpeakerID())
			{
				sdk_message_info.speakerID = messageInfo->getSpeakerID();
			}
			if (messageInfo->getSpeakerName())
			{
				sdk_message_info.speakerName = messageInfo->getSpeakerName();
			}
			sdk_message_info.timeStamp = messageInfo->getTimeStamp();
			sdk_message_info.messageType = (ZNZoomVideoSDKLiveTranscriptionOperationType)messageInfo->getMessageType();
			owner_->onOriginalLanguageMsgReceived(sdk_message_info);
		}
	}
	virtual void onCallCRCDeviceStatusChanged(ZoomVideoSDKCRCCallStatus status)
	{
		
	}
	virtual void onVideoCanvasSubscribeFail(ZoomVideoSDKSubscribeFailReason fail_reason, IZoomVideoSDKUser* pUser, void* handle)
	{

	}
	virtual void onShareCanvasSubscribeFail(IZoomVideoSDKUser* pUser, void* handle, IZoomVideoSDKShareAction* pShareAction)
	{

	}
	virtual void onChatPrivilegeChanged(IZoomVideoSDKChatHelper* pChatHelper, ZoomVideoSDKChatPrivilegeType privilege)
	{

	}
	virtual void onAnnotationHelperCleanUp(IZoomVideoSDKAnnotationHelper* helper)
	{

	}
	virtual void onAnnotationPrivilegeChange(IZoomVideoSDKUser* pUser, IZoomVideoSDKShareAction* pShareAction)
	{

	}
	virtual void onSendFileStatus(IZoomVideoSDKSendFile* file, const FileTransferStatus& status)
	{

	}
	virtual void onReceiveFileStatus(IZoomVideoSDKReceiveFile* file, const FileTransferStatus& status)
	{
		
	}
	virtual void onAnnotationHelperActived(void* handle)
	{

	}
	virtual void onCameraListChanged()
	{

	}
	virtual void onCalloutJoinSuccess(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, const zchar_t* phoneNumber)
	{
		if (owner_ && pUser)
		{
			ZoomSTRING zn_phoneNumber = phoneNumber;
			owner_->onCalloutJoinSuccess(pUser, zn_phoneNumber);
		}
	}
	virtual void onVideoAlphaChannelStatusChanged(bool isAlphaModeOn)
	{
	}
	virtual void onSpotlightVideoChanged(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper, ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<IZoomVideoSDKUser*>* userList)
	{
		if (owner_ && userList)
		{
			owner_->onSpotlightVideoChanged(userList);
		}
	}
	virtual void onBindIncomingLiveStreamResponse(bool bSuccess, const zchar_t* strStreamKeyID)
	{
		if (owner_ && strStreamKeyID)
		{
			ZoomSTRING zn_strStreamKeyID = strStreamKeyID;
			owner_->onBindIncomingLiveStreamResponse(bSuccess, zn_strStreamKeyID);
		}
	}
	virtual void onUnbindIncomingLiveStreamResponse(bool bSuccess, const zchar_t* strStreamKeyID)
	{
		if (owner_ && strStreamKeyID)
		{
			ZoomSTRING zn_strStreamKeyID = strStreamKeyID;
			owner_->onUnbindIncomingLiveStreamResponse(bSuccess, zn_strStreamKeyID);
		}
	}
	virtual void onIncomingLiveStreamStatusResponse(bool bSuccess, ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<IncomingLiveStreamStatus>* pStreamsStatusList)
	{
		if (owner_ && pStreamsStatusList)
		{
			owner_->onIncomingLiveStreamStatusResponse(bSuccess, pStreamsStatusList);
		}
	}
	virtual void onStartIncomingLiveStreamResponse(bool bSuccess, const zchar_t* strStreamKeyID)
	{
		if (owner_ && strStreamKeyID)
		{
			ZoomSTRING zn_strStreamKeyID = strStreamKeyID;
			owner_->onStartIncomingLiveStreamResponse(bSuccess, zn_strStreamKeyID);
		}
	}
	virtual void onStopIncomingLiveStreamResponse(bool bSuccess, const zchar_t* strStreamKeyID)
	{
		if (owner_ && strStreamKeyID)
		{
			ZoomSTRING zn_strStreamKeyID = strStreamKeyID;
			owner_->onStopIncomingLiveStreamResponse(bSuccess, zn_strStreamKeyID);
		}
	}
#if (!defined __linux)
	virtual void onRemoteControlStatus(IZoomVideoSDKUser* pUser, IZoomVideoSDKShareAction* pShareAction, ZoomVideoSDKRemoteControlStatus status)
	{
		if (owner_ && pUser && pShareAction)
		{
			if (pShareAction->getRemoteControlHelper()) {
				ZNZoomVideoSDKRemoteControlHelper::GetInst().SetHelper(pShareAction->getRemoteControlHelper());
			}
			owner_->onRemoteControlStatus(pUser, pShareAction, (ZNZoomVideoSDKRemoteControlStatus)status);
		}
	}
	virtual void onRemoteControlRequestReceived(IZoomVideoSDKUser* pUser, IZoomVideoSDKShareAction* pShareAction, IZoomVideoSDKRemoteControlRequestHandler* pRemoteControlRequestHandler)
	{
		if (owner_ && pUser && pShareAction)
		{
			if (pRemoteControlRequestHandler)
			{
				ZNZoomVideoSDKRemoteControlRequestHandler::GetInst().SetHandler(pRemoteControlRequestHandler);
			}
			owner_->onRemoteControlRequestReceived(pUser, pShareAction);
		}
	}
#endif
#if (defined _WIN32)
	virtual void onRemoteControlServiceInstallResult(bool bSuccess)
	{
		if (owner_)
		{
			owner_->onRemoteControlServiceInstallResult(bSuccess);
		}
	}
#endif
private:
	ZNativeVideoSDKWrap* owner_;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class VideoSDKEventWrapMgr
{
public:
	
	ZNativeZoomVideoSDKDelegate m_zoomVideoSDKDelegate;

	static VideoSDKEventWrapMgr& GetInst()
	{
		static VideoSDKEventWrapMgr inst;
		return inst;
	}
	~VideoSDKEventWrapMgr() {}
private:
	VideoSDKEventWrapMgr() {}
};
#endif // !_zoom_video_sdk_sinks_wrap_class_h_
