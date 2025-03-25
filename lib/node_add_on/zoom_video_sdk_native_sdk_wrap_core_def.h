#ifndef _zoom_video_sdk_native_sdk_wrap_core_def_h_
#define _zoom_video_sdk_native_sdk_wrap_core_def_h_
#include <string>
#include <vector>
#include "export_h/zoom_video_sdk_api.h"
#include "export_h/zoom_video_sdk_interface.h"
#include "export_h/helpers/zoom_video_sdk_user_helper_interface.h"
#include "export_h/zoom_video_sdk_delegate_interface.h"
#include "export_h/zoom_video_sdk_session_info_interface.h"
#include "export_h/helpers/zoom_video_sdk_audio_helper_interface.h"
#include "export_h/helpers/zoom_video_sdk_video_helper_interface.h"
#include "export_h/helpers/zoom_video_sdk_share_helper_interface.h"

#include "export_h/helpers/zoom_video_sdk_chat_helper_interface.h"
#include "export_h/helpers/zoom_video_sdk_livestream_helper_interface.h"
#include "export_h/helpers/zoom_video_sdk_cmd_channel_interface.h"
#include "export_h/helpers/zoom_video_sdk_phone_helper_interface.h"
#include "export_h/helpers/zoom_video_sdk_recording_helper_interface.h"
#include "export_h/helpers/zoom_video_sdk_audio_setting_interface.h"
#include "export_h/helpers/zoom_video_sdk_livetranscription_helper_interface.h"
#include "export_h/helpers/zoom_video_sdk_share_setting_interface.h"

#if (defined BUILD_WIN)
#define ZoomSTRING std::wstring
#define NOMINMAX
#include <Windows.h>
#else
#define ZoomSTRING std::string
#endif
#ifdef BUILD_WIN
#define ZOOM_HIDE_SYMBOL
#else
#define ZOOM_HIDE_SYMBOL __attribute__((visibility("hidden")))
#endif

class IInternalMagicCallback
{
public:
	virtual ~IInternalMagicCallback() {}
	virtual void onGlobalRawDataFrameReceived(YUVRawDataI420* data_, ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<unsigned long long>* recv_handle, bool is_video) = 0;
};

class IZoomElectronHelper
{
public:
	virtual ~IZoomElectronHelper() {}
	virtual void RegisterGlobalRawDataCB(IInternalMagicCallback* cb) = 0;
};

class ZNativeVideoSDKInternalMagicCallback : public IInternalMagicCallback
{
public:
	virtual ~ZNativeVideoSDKInternalMagicCallback() {}
	virtual void onGlobalRawDataFrameReceived(YUVRawDataI420* data_, ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<unsigned long long>* recv_handle, bool is_video);
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef enum
{
	ZNZoomVideoSDKErrors_Success = 0,///<Success.
	ZNZoomVideoSDKErrors_Wrong_Usage,
	ZNZoomVideoSDKErrors_Internal_Error,
	ZNZoomVideoSDKErrors_Uninitialize,
	ZNZoomVideoSDKErrors_Memory_Error,
	ZNZoomVideoSDKErrors_Load_Module_Error,
	ZNZoomVideoSDKErrors_UnLoad_Module_Error,
	ZNZoomVideoSDKErrors_Invalid_Parameter,
	ZNZoomVideoSDKErrors_Call_Too_Frequently,
	ZNZoomVideoSDKErrors_No_Impl,
	ZNZoomVideoSDKErrors_Dont_Support_Feature,
	ZNZoomVideoSDKErrors_Unknown,
	ZNZoomVideoSDKErrors_Auth_Base = 1000,
	ZNZoomVideoSDKErrors_Auth_Error,
	ZNZoomVideoSDKErrors_Auth_Empty_Key_or_Secret,
	ZNZoomVideoSDKErrors_Auth_Wrong_Key_or_Secret,
	ZNZoomVideoSDKErrors_Auth_DoesNot_Support_SDK,
	ZNZoomVideoSDKErrors_Auth_Disable_SDK,
	ZNZoomVideoSDKErrors_JoinSession_NoSessionName = 1500,
	ZNZoomVideoSDKErrors_JoinSession_NoSessionToken,
	ZNZoomVideoSDKErrors_JoinSession_NoUserName,
	ZNZoomVideoSDKErrors_JoinSession_Invalid_SessionName,
	ZNZoomVideoSDKErrors_JoinSession_Invalid_Password,
	ZNZoomVideoSDKErrors_JoinSession_Invalid_SessionToken,
	ZNZoomVideoSDKErrors_JoinSession_SessionName_TooLong,
	ZNZoomVideoSDKErrors_JoinSession_Token_MismatchedSessionName,
	ZNZoomVideoSDKErrors_JoinSession_Token_NoSessionName,
	ZNZoomVideoSDKErrors_JoinSession_Token_RoleType_EmptyOrWrong,
	ZNZoomVideoSDKErrors_JoinSession_Token_UserIdentity_TooLong,
	ZNZoomVideoSDKErrors_Session_Base = 2000,
	ZNZoomVideoSDKErrors_SessionModule_Not_Found,
	ZNZoomVideoSDKErrors_SessionService_Invalid,
	ZNZoomVideoSDKErrors_Session_Join_Failed,
	ZNZoomVideoSDKErrors_Session_No_Rights,
	ZNZoomVideoSDKErrors_Session_Already_In_Progress,
	ZNZoomVideoSDKErrors_Session_Dont_Support_MeetingType,
	ZNZoomVideoSDKErrors_Session_Reconncting,
	ZNZoomVideoSDKErrors_Session_Disconncting,
	ZNZoomVideoSDKErrors_Session_Not_Started,
	ZNZoomVideoSDKErrors_Session_Need_Password,
	ZNZoomVideoSDKErrors_Session_Password_Wrong,
	ZNZoomVideoSDKErrors_Session_Remote_DB_Error,
	ZNZoomVideoSDKErrors_Session_Invalid_Param,
	ZNZoomVideoSDKErrors_Session_Client_Incompatible,
	ZNZoomVideoSDKErrors_Session_Audio_Error = 3000,
	ZNZoomVideoSDKErrors_Session_Audio_No_Microphone,
	ZNZoomVideoSDKErrors_Session_Audio_No_Speaker,
	ZNZoomVideoSDKErrors_Session_Video_Error = 4000,
	ZNZoomVideoSDKErrors_Session_Video_Device_Error,
	ZNZoomVideoSDKErrors_Session_Live_Stream_Error = 5000,
	ZNZoomVideoSDKErrors_Session_Phone_Error = 5500,

	ZNZoomVideoSDKErrors_RAWDATA_MALLOC_FAILED = 6001,
	ZNZoomVideoSDKErrors_RAWDATA_NOT_IN_Session,
	ZNZoomVideoSDKErrors_RAWDATA_NO_LICENSE,
	ZNZoomVideoSDKErrors_RAWDATA_VIDEO_MODULE_NOT_READY,
	ZNZoomVideoSDKErrors_RAWDATA_VIDEO_MODULE_ERROR,
	ZNZoomVideoSDKErrors_RAWDATA_VIDEO_DEVICE_ERROR,
	ZNZoomVideoSDKErrors_RAWDATA_NO_VIDEO_DATA,
	ZNZoomVideoSDKErrors_RAWDATA_SHARE_MODULE_NOT_READY,
	ZNZoomVideoSDKErrors_RAWDATA_SHARE_MODULE_ERROR,
	ZNZoomVideoSDKErrors_RAWDATA_NO_SHARE_DATA,
	ZNZoomVideoSDKErrors_RAWDATA_AUDIO_MODULE_NOT_READY,
	ZNZoomVideoSDKErrors_RAWDATA_AUDIO_MODULE_ERROR,
	ZNZoomVideoSDKErrors_RAWDATA_NO_AUDIO_DATA,
	ZNZoomVideoSDKErrors_RAWDATA_PREPROCESS_RAWDATA_ERROR,
	ZNZoomVideoSDKErrors_RAWDATA_NO_DEVICE_RUNNING,
	ZNZoomVideoSDKErrors_RAWDATA_INIT_DEVICE,
	ZNZoomVideoSDKErrors_RAWDATA_VIRTUAL_DEVICE,
	ZNZoomVideoSDKErrors_RAWDATA_CANNOT_CHANGE_VIRTUAL_DEVICE_IN_PREVIEW,
	ZNZoomVideoSDKErrors_RAWDATA_INTERNAL_ERROR,
	ZNZoomVideoSDKErrors_RAWDATA_SEND_TOO_MUCH_DATA_IN_SINGLE_TIME,
	ZNZoomVideoSDKErrors_RAWDATA_SEND_TOO_FREQUENTLY,
	ZNZoomVideoSDKErrors_RAWDATA_VIRTUAL_MIC_IS_TERMINATE,

	ZNZoomVideoSDKErrors_Meeting_Share_Error = 7001,
	ZNZoomVideoSDKErrors_Meeting_Share_Module_Not_Ready,
	ZNZoomVideoSDKErrors_Meeting_Share_You_Are_Not_Sharing,
	ZNZoomVideoSDKErrors_Meeting_Share_Type_Is_Not_Support,
	ZNZoomVideoSDKErrors_Meeting_Share_Internal_Error,
	ZNZoomVideoSDKErrors_Dont_Support_Multi_Stream_Video_User,
	ZNZoomVideoSDKErrors_Fail_Assign_User_Privilege,
	ZNZoomVideoSDKErrors_No_Recording_In_Process,
	ZNZoomVideoSDKErrors_Set_Virtual_Background_Fail,
	ZNZoomVideoSDKErrors_Session_Share_Camera_Video_Not_Start,
	ZNZoomVideoSDKErrors_Session_Share_Camera_Conflict_With_Video_Effects,
	ZNZoomVideoSDKErrors_Filetransfer_UnknowError = 7500,
	ZNZoomVideoSDKErrors_Filetransfer_FileTypeBlocked,
	ZNZoomVideoSDKErrors_Filetransfer_FileSizelimited,
	ZNZoomVideoSDKErrors_Spotlight_NotEnoughUsers = 7600,
	ZNZoomVideoSDKErrors_Spotlight_ToMuchSpotlightedUsers,
	ZNZoomVideoSDKErrors_Spotlight_UserCannotBeSpotlighted,
	ZNZoomVideoSDKErrors_Spotlight_UserWithoutVideo,
	ZNZoomVideoSDKErrors_Spotlight_UserNotSpotlighted
}ZNZoomVideoSDKErrors;

typedef enum
{
	ZNZoomVideoSDKSessionLeaveReason_Unknown = 0,
	ZNZoomVideoSDKSessionLeaveReason_BySelf,
	ZNZoomVideoSDKSessionLeaveReason_KickByHost,
	ZNZoomVideoSDKSessionLeaveReason_EndByHost,
	ZNZoomVideoSDKSessionLeaveReason_NetworkError,
}ZNZoomVideoSDKSessionLeaveReason;

typedef enum
{
	ZNZoomVideoSDKShareStatus_None,
	ZNZoomVideoSDKShareStatus_Start,
	ZNZoomVideoSDKShareStatus_Pause,
	ZNZoomVideoSDKShareStatus_Resume,
	ZNZoomVideoSDKShareStatus_Stop,
}ZNZoomVideoSDKShareStatus;

typedef enum
{
	ZNZoomVideoSDKSubscribeFailReason_None = 0,
	ZNZoomVideoSDKSubscribeFailReason_HasSubscribe1080POr720P,
	ZNZoomVideoSDKSubscribeFailReason_HasSubscribeTwo720P,
	ZNZoomVideoSDKSubscribeFailReason_HasSubscribeExceededLimit,
	ZNZoomVideoSDKSubscribeFailReason_HasSubscribeTwoShare,
	ZNZoomVideoSDKSubscribeFailReason_HasSubscribeVideo1080POr720PAndOneShare
}ZNZoomVideoSDKSubscribeFailReason;

typedef enum
{
	ZNZoomVideoSDKShareType_None,
	ZNZoomVideoSDKShareType_Normal, ///<application or desktop share
	ZNZoomVideoSDKShareType_PureAudio, ///<pure computer audio share
	ZNZoomVideoSDKShareType_Camera, ///<camera share
}ZNZoomVideoSDKShareType;

typedef enum
{
	ZNZoomVideoSDKLiveStreamStatus_None,
	ZNZoomVideoSDKLiveStreamStatus_InProgress,
	ZNZoomVideoSDKLiveStreamStatus_Connecting,
	ZNZoomVideoSDKLiveStreamStatus_FailedTimeout,
	ZNZoomVideoSDKLiveStreamStatus_StartFailed,
	ZNZoomVideoSDKLiveStreamStatus_Ended,
}ZNZoomVideoSDKLiveStreamStatus;

typedef enum
{
	ZNZoomVideoSDKRawDataMemoryModeStack = 0,
	ZNZoomVideoSDKRawDataMemoryModeHeap,
}ZNZoomVideoSDKRawDataMemoryMode;

typedef struct tagZNZoomVideoSDKExtendParams
{
	ZoomSTRING speakerTestFilePath;
	int wrapperType;

	tagZNZoomVideoSDKExtendParams()
	{
		wrapperType = 3;
	}
}ZNZoomVideoSDKExtendParams;

typedef struct tagZNZoomVideoSDKInitParams
{
	ZoomSTRING domain;
	ZoomSTRING logFilePrefix;
	bool  enableLog;
	ZNZoomVideoSDKRawDataMemoryMode audioRawDataMemoryMode;
	ZNZoomVideoSDKRawDataMemoryMode videoRawDataMemoryMode;
	ZNZoomVideoSDKRawDataMemoryMode shareRawDataMemoryMode;
	ZNZoomVideoSDKExtendParams extendParam;

	tagZNZoomVideoSDKInitParams()
	{
		enableLog = false;
		audioRawDataMemoryMode = ZNZoomVideoSDKRawDataMemoryModeStack;
		videoRawDataMemoryMode = ZNZoomVideoSDKRawDataMemoryModeStack;
		shareRawDataMemoryMode = ZNZoomVideoSDKRawDataMemoryModeStack;
	}
}ZNZoomVideoSDKInitParams;

typedef struct tagZNZoomVideoSDKShareOption
{
	bool isWithDeviceAudio;            ///<share option, true: share computer sound when share screen/window, otherwise not.
	bool isOptimizeForSharedVideo;     ///<share option, true: optimize the frame rate when share screen/window, otherwise not.
	tagZNZoomVideoSDKShareOption()
	{
		isWithDeviceAudio = false;
		isOptimizeForSharedVideo = false;
	}
}ZNZoomVideoSDKShareOption;

typedef struct tagZNZoomVideoSDKVideoOption
{
	bool localVideoOn; ///<video option to set local video open or close when join session.
	tagZNZoomVideoSDKVideoOption()
	{
		localVideoOn = true;
	}
}ZNZoomVideoSDKVideoOption;

typedef struct tagZNZoomVideoSDKAudioOption
{
	bool connect; ///<Audio option  is connect audio when enter session
	bool mute;    ///<Audio option  is mute audio when enter session

	tagZNZoomVideoSDKAudioOption()
	{
		connect = true;
		mute = false;
	}
}ZNZoomVideoSDKAudioOption;

typedef struct tagZNZoomVideoSDKSessionContext
{
	ZoomSTRING sessionName;
	ZoomSTRING sessionPassword; ///<Session password, optional
	ZoomSTRING userName;        ///<Display name in session, required
	ZoomSTRING token;
	ZNZoomVideoSDKVideoOption videoOption;
	ZNZoomVideoSDKAudioOption audioOption;
	bool preProcessor;
	bool externalVideoSource;
	unsigned int sessionIdleTimeoutMins; ///<Customize close time when session is idle, the unit is minutes. 0: never close.
	tagZNZoomVideoSDKSessionContext()
	{
		preProcessor = false;
		externalVideoSource = false;
		sessionIdleTimeoutMins = 40;
	}
}ZNZoomVideoSDKSessionContext;

typedef struct tagZNZoomVideoSDKCameraDevice
{
	ZoomSTRING deviceID;
	ZoomSTRING deviceName;
	bool isSelectedDevice;
}ZNZoomVideoSDKCameraDevice;

typedef struct tagZNZoomVideoSDKSpeakerDevice
{
	ZoomSTRING deviceID;
	ZoomSTRING deviceName;
	bool isSelectedDevice;

}ZNZoomVideoSDKSpeakerDevice;
typedef struct tagZNZoomVideoSDKMicDevice
{
	ZoomSTRING deviceID;
	ZoomSTRING deviceName;
	bool isSelectedDevice;

}ZNZoomVideoSDKMicDevice;

typedef enum
{
	ZNVideoRotation_0,
	ZNVideoRotation_90,
	ZNVideoRotation_180,
	ZNVideoRotation_270,
}ZNVideoRotation;

typedef enum
{
	ZNRAW_DATA_TYPE_VIDEO = 0,
	ZNRAW_DATA_TYPE_SHARE,
}ZNZoomVideoSDKRawDataType;

typedef enum 
{
	ZNZoomVideoSDKResolution_90P = 0,
	ZNZoomVideoSDKResolution_180P,
	ZNZoomVideoSDKResolution_360P,
	ZNZoomVideoSDKResolution_720P,
#if (defined _WIN32) || (defined TARGET_OS_MAC)
	ZNZoomVideoSDKResolution_1080P,
#endif
	ZNZoomVideoSDKResolution_NoUse = 100,
}ZNZoomVideoSDKResolution;

/*! \struct ZoomVideoSDKShareCursorData
	\brief Share cursor information.
*/
typedef struct
{
	unsigned int source_id;
	int x;
	int y;
}ZNZoomVideoSDKShareCursorData;

typedef struct tagZNZoomVideoSDKVideoStatus
{
	bool isHasVideoDevice;
	bool isOn;

	tagZNZoomVideoSDKVideoStatus()
	{
		isHasVideoDevice = false;
		isOn = false;
	}
}ZNZoomVideoSDKVideoStatus;

typedef enum {
	ZNZoomVideoSDKAudioType_VOIP,
	ZNZoomVideoSDKAudioType_TELEPHONY,
	ZNZoomVideoSDKAudioType_None,
}ZNZoomVideoSDKAudioType;

typedef struct tagZNZoomVideoSDKAudioStatus
{
	ZNZoomVideoSDKAudioType audioType;
	bool isMuted;
	bool isTalking;
	tagZNZoomVideoSDKAudioStatus()
	{
		audioType = ZNZoomVideoSDKAudioType_None;
		isMuted = false;
		isTalking = false;
	}
}ZNZoomVideoSDKAudioStatus;

typedef struct
{
	int width;
	int height;
	int fps;
	int bpf;
}ZNZoomVideoSDKVideoStatisticInfo;

typedef struct
{
	int width;
	int height;
	int fps;
	int bpf;
}ZNZoomVideoSDKShareStatisticInfo;

typedef enum {
	ZNUserInfoType_FAKE,
	ZNUserInfoType_REAL,
}ZNUserInfoType;

typedef struct _ZNShareAction
{
	unsigned int shareSourceId; // share source id.
	ZNZoomVideoSDKShareStatus shareStatus; // share status.
	ZNZoomVideoSDKSubscribeFailReason subscribeFailReason; // subscribe fail reason.
	bool isAnnotationPrivilegeEnabled; // whether annotation privilege is enabled.
	ZNZoomVideoSDKShareType shareType; // share type.
	_ZNShareAction()
	{
		shareStatus = ZNZoomVideoSDKShareStatus_None;
		isAnnotationPrivilegeEnabled = false;
	}
}ZNShareAction;

typedef struct tagZNZoomVideoSDKUserInfo
{
	unsigned int userID; // The user id of the user object.
	ZoomSTRING customIdentity; // The Custom id of the user object.
	ZoomSTRING userName; // The name of the user object.
	ZoomSTRING userReference; // user's reference info.
	//ZoomSTRING emailAddress;
	ZNZoomVideoSDKVideoStatus videoStatus;
	ZNZoomVideoSDKAudioStatus audioStatus; // Audio status of the user object.
	std::vector<ZNShareAction> shareActionList;// the user's share-action list.
	bool isHost; // True indicates that the user is the host, otherwise false.
	bool isManager; // True indicates that the user is the manager(coHost), otherwise false.
	bool isVideoSpotLighted; // True indicates that the user is spotLighted, otherwise false.
	bool isIncomingLiveStreamUser; // True indicates that the user is an incoming live stream user, otherwise false.
	ZNZoomVideoSDKVideoStatisticInfo videoStatisticInfo;
	ZNZoomVideoSDKShareStatisticInfo shareStatisticInfo;
	ZNUserInfoType userInfoType;
	unsigned int userPointer;
	tagZNZoomVideoSDKUserInfo()
	{
		isHost = false;
		isManager = false;
		isVideoSpotLighted = false;
		isIncomingLiveStreamUser = false;
		userInfoType = ZNUserInfoType_FAKE;
	}
}ZNZoomVideoSDKUserInfo;

typedef struct tagZNZoomVideoSDKChatMessageInfo
{
	int64_t pSender;
	ZoomSTRING senderName;
	int64_t pReceiver;
	ZoomSTRING receiverName;
	ZoomSTRING messageContent;
	time_t timeStamp;
	bool isChatToAll;
	bool isSelfSend;
	ZoomSTRING senderID;
	ZoomSTRING receiverID;
	ZoomSTRING messageID;

	tagZNZoomVideoSDKChatMessageInfo()
	{
		pSender = 0;
		pReceiver = 0;
		isChatToAll = false;
		isSelfSend = false;
	}
}ZNZoomVideoSDKChatMessageInfo;

#define USERINFO_USERID 1UL
#define USERINFO_USERNAME (1UL << 1)
#define USERINFO_CUSTOMIDENTITY (1UL << 2)
#define USERINFO_EMAILADDRESS (1UL << 3)
#define USERINFO_ISHASVIDEODEVICE (1UL << 4)
#define USERINFO_ISVIDEOON (1UL << 5)
#define USERINFO_AUDIOTYEP (1UL << 6)
#define USERINFO_ISMUTED (1UL << 7)
#define USERINFO_ISTALKING (1UL << 8)
#define USERINFO_SHARESTATUS (1UL << 9)
#define USERINFO_ISHOST (1UL << 10)
#define USERINFO_ISMANAGER (1UL << 11)
#define USERINFO_VSI_HIGHT (1UL << 12)
#define USERINFO_VSI_WIDTH (1UL << 13)
#define USERINFO_VSI_BPF (1UL << 14)
#define USERINFO_VSI_FPS (1UL << 15)
#define USERINFO_SSI_HIGHT (1UL << 16)
#define USERINFO_SSI_WIDTH (1UL << 17)
#define USERINFO_SSI_BPF (1UL << 18)
#define USERINFO_SSI_FPS (1UL << 19)
#define USERINFO_ISVIDEOSPOTLIGHTED (1UL << 20)

typedef struct tagZNZoomVideoSDKShareAppInfo
{
	ZoomSTRING appName;
	ZoomSTRING appHandle;
}ZNZoomVideoSDKShareAppInfo;



typedef enum {
	CallMessageType_onSessionJoin = 0,
	CallMessageType_onSessionLeave,
	CallMessageType_onError,
	CallMessageType_onUserJoin,
	CallMessageType_onUserLeave,
	CallMessageType_onUserVideoStatusChanged,
	CallMessageType_onUserAudioStatusChanged,
	CallMessageType_onUserShareStatusChanged,
	CallMessageType_onLiveStreamStatusChanged,
	CallMessageType_onChatNewMessageNotify,
	CallMessageType_onUserHostChanged,
	CallMessageType_onUserActiveAudioChanged,
	CallMessageType_onSessionNeedPassword,
	CallMessageType_onSessionPasswordWrong,

	CallMessageType_onVideoSourceInitialize,
	CallMessageType_onPropertyChange,
	CallMessageType_onStartSend,
	CallMessageType_onStopSend,
	CallMessageType_onUninitialized,
	CallMessageType_onRawDataStatusChanged,

	CallMessageType_onUserManagerChanged,
	CallMessageType_onUserNameChanged,
	CallMessageType_onCommandReceived,
	CallMessageType_onCloudRecordingStatus,
	CallMessageType_onCameraControlRequestResult,
	CallMessageType_onCameraControlRequestReceived,
	CallMessageType_onCommandChannelConnectResult,
	CallMessageType_onHostAskUnmute,
	CallMessageType_onInviteByPhoneStatus,
	CallMessageType_onMultiCameraStreamStatusChanged,
	CallMessageType_onMicSpeakerVolumeChanged,
	CallMessageType_onAudioDeviceStatusChanged,
	CallMessageType_onTestMicStatusChanged,
	CallMessageType_onSelectedAudioDeviceChanged,
	CallMessageType_onLiveTranscriptionStatus,
	CallMessageType_onLiveTranscriptionMsgError = 36,
	CallMessageType_onChatMsgDeleteNotification,
	CallMessageType_onLiveTranscriptionMsgInfoReceived,
	CallMessageType_onOriginalLanguageMsgReceived,
	CallMessageType_onCalloutJoinSuccess,
	CallMessageType_onShareCursorDataReceived,
	CallMessageType_onRemoteControlStatus,
	CallMessageType_onRemoteControlRequestReceived,
	CallMessageType_onRemoteControlServiceInstallResult,
	CallMessageType_onSpotlightVideoChanged,
	CallMessageType_onBindIncomingLiveStreamResponse, ///<Callback event that binds the incoming live stream.
	CallMessageType_onUnbindIncomingLiveStreamResponse, ///<Callback event that unbinds the incoming live stream.
	CallMessageType_onIncomingLiveStreamStatusResponse, ///<Callback event that gets the streams status.
	CallMessageType_onStartIncomingLiveStreamResponse, ///<Callback event that starts the binded stream.
	CallMessageType_onStopIncomingLiveStreamResponse, ///<Callback event that stops the binded stream.
	CallMessageType_onFailedToStartShare, ///<Invoked when a user failed to start sharing.
	CallMessageType_onCameraListChanged, ///<Notify that the camera list has changed.
	CallMessageType_onShareContentChanged, ///<Invoked when a user makes changes to their share content type, such as camera share switch to normal share. The share type can be found in \link ZNZoomVideoSDKShareType \endlink.
	CallMessageType_onShareContentSizeChange, ///<Invoked when the share content size changed.
}ZNCallMessageType;

/*! \enum PhoneStatus
	\brief Status of telephone.
	Here are more detailed structural descriptions.
*/
typedef enum {
	ZNPhoneStatus_None,///<No status.
	ZNPhoneStatus_Calling,///<In process of calling out.
	ZNPhoneStatus_Ringing,///<In process of ringing.
	ZNPhoneStatus_Accepted,///<Accept the call.
	ZNPhoneStatus_Success,///<Call successful.
	ZNPhoneStatus_Failed,///<Call failed.
	ZNPhoneStatus_Canceling,///<In process of canceling the response to the previous state.
	ZNPhoneStatus_Canceled, ///<Cancel successfully.
	ZNPhoneStatus_Cancel_Failed,///<Cancel fails.
	ZNPhoneStatus_Timeout,///<Timeout.
}ZNPhoneStatus;


/*! \enum PhoneFailedReason
	\brief The reason for the failure of the telephone call.
	Here are more detailed structural descriptions.
*/
typedef enum {
	ZNPhoneFailedReason_None,///<For initialization.
	ZNPhoneFailedReason_Busy,///<The telephone service is busy.
	ZNPhoneFailedReason_Not_Available,///<The telephone is out of the service.
	ZNPhoneFailedReason_User_Hangup,///<The user hangs up.
	ZNPhoneFailedReason_Other_Fail,///<Other reasons.
	ZNPhoneFailedReason_No_Answer,///<The telephone does not reply.
	ZNPhoneFailedReason_Block_No_Host,///<Disable the function of international call-out before the host joins the session.
	ZNPhoneFailedReason_Block_High_Rate,///<The call-out is blocked by the system due to the high cost.
	ZNPhoneFailedReason_Block_Too_Frequent,///<All the invitees invited by the call should press the button one(1) to join the session. In case that many invitees do not press the button that leads to time out, the call invitation for this meeting shall be banned.
}ZNPhoneFailedReason;

typedef enum{
	ZNRecording_Start,///<Start recording on local computer or on cloud.
	ZNRecording_Stop,///<Stop recording on local computer or on cloud.
	ZNRecording_DiskFull,///<There is no space to store for cloud recording.
	ZNRecording_Pause,///<Pause recording on local or on cloud.
}ZNRecordingStatus;

typedef enum
{
	ZNZoomVideoSDKCameraControlRequestType_RequestControl = 0,
	ZNZoomVideoSDKCameraControlRequestType_GiveUpControl

}ZNZoomVideoSDKCameraControlRequestType;

enum ZNZoomVideoSDKRemoteControlStatus
{
	ZNZoomVideoSDKRemoteControlStatus_None = 0,			///<For initialization.
	ZNZoomVideoSDKRemoteControlStatus_CanRequestControl,	///<Remote control information. I can enable the remote control.	
	ZNZoomVideoSDKRemoteControlStatus_RequestDenied,	///<Remote control information. I have received a refused information of remote control.
	ZNZoomVideoSDKRemoteControlStatus_GotControl,			///<The authority of remote control. I get control when remote control begins.
	ZNZoomVideoSDKRemoteControlStatus_LostControl,		///<The authority of remote control. I lose control when remote control ends. 
	ZNZoomVideoSDKRemoteControlStatus_ControlStart,	///<The status of remote control. I am remotely controlling another.
	ZNZoomVideoSDKRemoteControlStatus_ControlStop,	///<The status of remote control. I am not remotely controlling another.
	ZNZoomVideoSDKRemoteControlStatus_GiveControlTo,		///<The status of remote control. I can be controlled by the specified user.
	ZNZoomVideoSDKRemoteControlStatus_ControlRevoked,		///<The status of remote control. I have revoked remote control.
	ZNZoomVideoSDKRemoteControlStatus_ControlledBy,		///<The status of remote control. I am being controlled by the specified user.
	ZNZoomVideoSDKRemoteControlStatus_NotControlled,		///<The status of remote control. I am not being controlled.
};

/*  \enum ZNZoomVideoSDKVideoPreferenceMode
	\brief video preference mode types
	Here are more detailed structural descriptions.
*/
typedef enum
{
	ZNZoomVideoSDKVideoPreferenceMode_Balance, ///<Balance mode
	ZNZoomVideoSDKVideoPreferenceMode_Sharpness, ///<Sharpness mode
	ZNZoomVideoSDKVideoPreferenceMode_Smoothness, ///<Smoothness mode	
	ZNZoomVideoSDKVideoPreferenceMode_Custom	///<Custom mode.
}ZNZoomVideoSDKVideoPreferenceMode;

typedef struct tagZNVideoPreferenceSetting
{
	ZNZoomVideoSDKVideoPreferenceMode mode;  ///<0: Balance mode; 1: Smoothness mode; 2: Sharpness mode; 3: Custom mode
	uint32_t minimum_frame_rate; ///<0 for the default value,minimum_frame_rate should be less than maximum_frame_rate, range: from 0 to 30 .out of range for frame-rate will use default frame-rate of Zoom	
	uint32_t maximum_frame_rate; ///<0 for the default value,maximum_frame_rate should be less and equal than 30, range: from 0 to 30.out of range for frame-rate will use default frame-rate of Zoom
	tagZNVideoPreferenceSetting()
	{
		mode = ZNZoomVideoSDKVideoPreferenceMode_Balance;
		minimum_frame_rate = 0;
		maximum_frame_rate = 0;
	}
}ZNZoomVideoSDKVideoPreferenceSetting;

typedef enum
{
	ZNZoomVideoSDKSuppressBackgroundNoiseLevel_Auto = 0,
	ZNZoomVideoSDKSuppressBackgroundNoiseLevel_Low,
	ZNZoomVideoSDKSuppressBackgroundNoiseLevel_Medium,
	ZNZoomVideoSDKSuppressBackgroundNoiseLevel_High
}ZNZoomVideoSDKSuppressBackgroundNoiseLevel;

typedef enum {
	ZNZoomVideoSDKEchoCancellationLevel_Default = 0,
	ZNZoomVideoSDKEchoCancellationLevel_Aggressive
}ZNZoomVideoSDKEchoCancellationLevel;

typedef enum {
	ZNZoomVideoSDKMultiCameraStreamStatus_JoinStart, ///<For local, it means that who enable multi camera and who can receive the status.
	ZNZoomVideoSDKMultiCameraStreamStatus_JoinFail,  ///<For local, it means that who enable multi camera fail and who can receive the status.
	ZNZoomVideoSDKMultiCameraStreamStatus_Joined,    ///<For all participants, when someone enable multi camera success, all participant receive the status.
	ZNZoomVideoSDKMultiCameraStreamStatus_Left,      ///<For all participants, when someone disable multi camera success, all participant receive the status.
}ZNZoomVideoSDKMultiStreamStatus;

typedef	enum
{
	ZNZoomVideoSDKMic_CanTest = 0,///<Test the mic via TestMicStartRecording. It is useless to call TestMicStopTesting/TestMicPlayRecording in this status.
	ZNZoomVideoSDKMic_Recording,///<Test the mic via TestMicStopTesting/TestMicPlayRecording. It is useless to call TestMicStartRecording in this status.
	ZNZoomVideoSDKMic_CanPlay,///<Test the mic via TestMicStopTesting/TestMicPlayRecording. It is useless call TestMicStartRecording in this status.
}ZNZoomVideoSDK_TESTMIC_STATUS;

typedef enum
{
	ZNZoomVideoSDKDevice_Microphone = 0,
	ZNZoomVideoSDKDevice_Speaker
}ZNZoomVideoSDKAudioDeviceType;

typedef enum {
	ZNZoomVideoSDK_Device_Error_Unknow = 0,
	ZNZoomVideoSDK_No_Device,
	ZNZoomVideoSDK_Device_List_Update,
	ZNZoomVideoSDK_Audio_No_Input,
	ZNZoomVideoSDK_Audio_Disconnect_As_Detected_Echo
}ZNZoomVideoSDKAudioDeviceStatus;

enum ZNVideoSourceDataMode
{
	ZNVideoSourceDataMode_None = 0,    ///<For general usage scenarios.
	ZNVideoSourceDataMode_Horizontal,  ///<Special usage scenarios, each frame of video is organized around two images.
	ZNVideoSourceDataMode_Vertical     ///<Special usage scenarios, each frame of video is two images organized up and down together.
};

struct ZNVideoSourceCapability
{
	unsigned int width;
	unsigned int height;
	unsigned int frame;
	ZNVideoSourceDataMode data_mode;

	ZNVideoSourceCapability()
	{
		width = 0;
		height = 0;
		frame = 0;
		data_mode = ZNVideoSourceDataMode_None;
	}
};

/**
 * @brief Enumerations of the type for live transcription status.
 */
typedef enum
{
	ZNZoomVideoSDKLiveTranscription_Status_Stop = 0,//not start
	ZNZoomVideoSDKLiveTranscription_Status_Start = 1,  //start
}ZNZoomVideoSDKLiveTranscriptionStatus;

/**
 * @brief Enumerations of the type for live transcription operation type.
 */
typedef enum
{
	ZNZoomVideoSDKLiveTranscription_OperationType_None = 0,
	ZNZoomVideoSDKLiveTranscription_OperationType_Add,
	ZNZoomVideoSDKLiveTranscription_OperationType_Update,
	ZNZoomVideoSDKLiveTranscription_OperationType_Delete,
	ZNZoomVideoSDKLiveTranscription_OperationType_Complete,
	ZNZoomVideoSDKLiveTranscription_OperationType_NotSupported,
}ZNZoomVideoSDKLiveTranscriptionOperationType;

typedef struct tagZNLiveTranscriptionLanguage
{
	int lttLanguageID;
	ZoomSTRING lttLanguageName;

	tagZNLiveTranscriptionLanguage()
	{
		lttLanguageID = 0;
	}
}ZNLiveTranscriptionLanguage;

typedef enum {
	ZNZoomVideoSDKChatDelete_None = 0,  ///<none
	ZNZoomVideoSDKChatDelete_BySelf,      ///<delete by self
	ZNZoomVideoSDKChatDelete_ByHost,      ///<delete by host
	ZNZoomVideoSDKChatDelete_ByDlp,       ///<delete by dlp when the message goes against the host organization's compliance policies.
}ZNZoomVideoSDKChatMessageDeleteType;

typedef struct tagZNLiveTranscriptionMessageInfo
{
	time_t timeStamp;
	ZoomSTRING messageID;
	ZoomSTRING messageContent;
	ZoomSTRING speakerName;
	ZoomSTRING speakerID;
	ZNZoomVideoSDKLiveTranscriptionOperationType messageType;

	tagZNLiveTranscriptionMessageInfo()
	{
		messageType = ZNZoomVideoSDKLiveTranscription_OperationType_None;
	}
}ZNLiveTranscriptionMessageInfo;

typedef struct tagZNInvitePhoneUserInfo
{
	ZoomSTRING countryCode;///<InvitePhoneUserInfo, The country code of the specified user must be in the support list. 
	ZoomSTRING phoneNumber;///<InvitePhoneUserInfo, The phone number of specified user.
	ZoomSTRING name;///<InvitePhoneUserInfo, The screen name of the specified user in the session.
	bool bPressOne;///<InvitePhoneUserInfo , true: Need press number one to agree to join the session, otherwise not.
	bool bGreeting;///<InvitePhoneUserInfo, true: When joining the session, play a greeting prompt tone., otherwise not.

	tagZNInvitePhoneUserInfo()
	{
		bPressOne = true;
		bGreeting = true;
	}
}ZNInvitePhoneUserInfo;

typedef enum {
    ///<Screen capture mode is automatically.
    ZNZoomVideoSDKScreenCaptureMode_Auto = 0,
    ///<Screen capture mode is legacy operating systems.
    ZNZoomVideoSDKScreenCaptureMode_Legacy,
    ///<Screen capture mode is capture with window filtering.
    ZNZoomVideoSDKScreenCaptureMode_Filtering,
    ///<Screen capture mode is advanced share with window filtering.
    ZNZoomVideoSDKScreenCaptureMode_ADA_Filtering,
    ///<Screen capture mode is advanced share without window filtering.
    ZNZoomVideoSDKScreenCaptureMode_ADA_Without_Filtering,
    ///<Screen capture mode is secure share with window filtering.
    ZNZoomVideoSDKScreenCaptureMode_Secure_Filtering,
}ZNZoomVideoSDKScreenCaptureMode;


////////////////////////////////////////////////////////////////////////////////////////////////////////
#define ZNList std::vector
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
#if (defined BUILD_WIN)
#define JS_WRAP
//#define UserInterfaceClass
#endif
