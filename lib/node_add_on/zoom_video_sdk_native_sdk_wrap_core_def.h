#ifndef _zoom_video_sdk_native_sdk_wrap_core_def_h_
#define _zoom_video_sdk_native_sdk_wrap_core_def_h_
#include <string>
#include <vector>
#include "export_h/zoom_video_sdk_api.h"
#include "export_h/zoom_video_sdk_interface.h"
#include "export_h/helpers/zoom_video_sdk_user_helper_interface.h"
#include "export_h/zoom_video_sdk_delegate_interface.h"
#include "export_h/zoom_video_sdk_session_info_interface.h"
#include "export_h/helpers/zoom_video_sdk_annotation_helper_interface.h"
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
/**
 * @brief Enumeration of common Zoom Video SDK errors.
 */
typedef enum
{
	/** Success. */
	ZNZoomVideoSDKErrors_Success = 0,
	/** Incorrect usage of the feature. */
	ZNZoomVideoSDKErrors_Wrong_Usage,
	/** Internal SDK error. */
	ZNZoomVideoSDKErrors_Internal_Error,
	/** SDK is not initialized before usage. */
	ZNZoomVideoSDKErrors_Uninitialize,
	/** No memory is allocated or memory allocation failed. */
	ZNZoomVideoSDKErrors_Memory_Error,
	/** Failed to load module. */
	ZNZoomVideoSDKErrors_Load_Module_Error,
	/** Failed to unload module. */
	ZNZoomVideoSDKErrors_UnLoad_Module_Error,
	/** Invalid parameter passed to a function. */
	ZNZoomVideoSDKErrors_Invalid_Parameter,
	/** API is being called too frequently. */
	ZNZoomVideoSDKErrors_Call_Too_Frequently,
	/** The requested feature is not implemented. */
	ZNZoomVideoSDKErrors_No_Impl,
	/** The current session does not support the feature. */
	ZNZoomVideoSDKErrors_Dont_Support_Feature,
	/** Unknown error occurred. */
	ZNZoomVideoSDKErrors_Unknown,
	/** Failed to remove folder. */
	ZNZoomVideoSDKErrors_Remove_Folder_Fail,
	/** General authorization failure. */
	ZNZoomVideoSDKErrors_Auth_Error = 1001,
	/** Authorization failed due to missing key or secret. */
	ZNZoomVideoSDKErrors_Auth_Empty_Key_or_Secret,
	/** Authorization failed due to invalid key or secret. */
	ZNZoomVideoSDKErrors_Auth_Wrong_Key_or_Secret,
	/** Authorization does not support SDK. */
	ZNZoomVideoSDKErrors_Auth_DoesNot_Support_SDK,
	/** Authorization disable SDK. */
	ZNZoomVideoSDKErrors_Auth_Disable_SDK,
	/** Session name is missing when joining session. */
	ZNZoomVideoSDKErrors_JoinSession_NoSessionName = 1500,
	/** Session token is missing when joining session. */
	ZNZoomVideoSDKErrors_JoinSession_NoSessionToken,
	/** User name is missing when joining session. */
	ZNZoomVideoSDKErrors_JoinSession_NoUserName,
	/** Session name is invalid. */
	ZNZoomVideoSDKErrors_JoinSession_Invalid_SessionName,
	/** Session password is invalid. */
	ZNZoomVideoSDKErrors_JoinSession_Invalid_Password,
	/** Session token is invalid. */
	ZNZoomVideoSDKErrors_JoinSession_Invalid_SessionToken,
	/** Session name exceeds the allowed length. */
	ZNZoomVideoSDKErrors_JoinSession_SessionName_TooLong,
	/** Token does not match the session name. */
	ZNZoomVideoSDKErrors_JoinSession_Token_MismatchedSessionName,
	/** Token does not include session name. */
	ZNZoomVideoSDKErrors_JoinSession_Token_NoSessionName,
	/** Token has empty or invalid role type. */
	ZNZoomVideoSDKErrors_JoinSession_Token_RoleType_EmptyOrWrong,
	/** Token includes a user identity that is too long. */
	ZNZoomVideoSDKErrors_JoinSession_Token_UserIdentity_TooLong,
	/** Failed to find session module. */
	ZNZoomVideoSDKErrors_SessionModule_Not_Found = 2001,
	/** Invalid session service. */
	ZNZoomVideoSDKErrors_SessionService_Invalid,
	/** Failed to join the session. */
	ZNZoomVideoSDKErrors_Session_Join_Failed,
	/** User does not have the rights to join the session. */
	ZNZoomVideoSDKErrors_Session_No_Rights,
	/** Session is already in progress. */
	ZNZoomVideoSDKErrors_Session_Already_In_Progress,
	/** The current session type is not supported. */
	ZNZoomVideoSDKErrors_Session_Dont_Support_SessionType,
	/** SDK is reconnecting to the session. */
	ZNZoomVideoSDKErrors_Session_Reconnecting,
	/** SDK is disconnecting from the session. */
	ZNZoomVideoSDKErrors_Session_Disconnecting,
	/** Session has not started yet. */
	ZNZoomVideoSDKErrors_Session_Not_Started,
	/** Session requires a password. */
	ZNZoomVideoSDKErrors_Session_Need_Password,
	/** Incorrect session password. */
	ZNZoomVideoSDKErrors_Session_Password_Wrong,
	/** Error from remote database. */
	ZNZoomVideoSDKErrors_Session_Remote_DB_Error,
	/** Invalid session parameter. */
	ZNZoomVideoSDKErrors_Session_Invalid_Param,
	/** Client is incompatible with the session. */
	ZNZoomVideoSDKErrors_Session_Client_Incompatible,
	/** Session ended due to exceeding free minutes. */
	ZNZoomVideoSDKErrors_Session_Account_FreeMinutesExceeded,
	/** Join session failed because the account's free credit has been exceeded. */
	ZNZoomVideoSDKErrors_Session_Account_FreeCreditExceeded,
	/** Audio module error. */
	ZNZoomVideoSDKErrors_Session_Audio_Error = 3000,
	/** No microphone detected. */
	ZNZoomVideoSDKErrors_Session_Audio_No_Microphone,
	/** No speaker detected. */
	ZNZoomVideoSDKErrors_Session_Audio_No_Speaker,
	/** Bluetooth sco connect fail. Android Only. */
	ZNZoomVideoSDKErrors_Session_Bluetooth_SCO_Connection_Failed,
	/** General video error. */
	ZNZoomVideoSDKErrors_Session_Video_Error = 4000,
	/** Video device error. */
	ZNZoomVideoSDKErrors_Session_Video_Device_Error,
	/** Live stream error. */
	ZNZoomVideoSDKErrors_Session_Live_Stream_Error = 5000,
	/** Phone connection error. */
	ZNZoomVideoSDKErrors_Session_Phone_Error = 5500,

	/** Failed to allocate memory for raw data. */
	ZNZoomVideoSDKErrors_RAWDATA_MALLOC_FAILED = 6001,
	/** Not in a session for raw data access. */
	ZNZoomVideoSDKErrors_RAWDATA_NOT_IN_Session,
	/** No raw data license available. */
	ZNZoomVideoSDKErrors_RAWDATA_NO_LICENSE,
	/** Video module not ready for raw data. */
	ZNZoomVideoSDKErrors_RAWDATA_VIDEO_MODULE_NOT_READY,
	/** Video module error. */
	ZNZoomVideoSDKErrors_RAWDATA_VIDEO_MODULE_ERROR,
	/** Video device error. */
	ZNZoomVideoSDKErrors_RAWDATA_VIDEO_DEVICE_ERROR,
	/** No video data available. */
	ZNZoomVideoSDKErrors_RAWDATA_NO_VIDEO_DATA,
	/** Share module not ready. */
	ZNZoomVideoSDKErrors_RAWDATA_SHARE_MODULE_NOT_READY,
	/** Share module error. */
	ZNZoomVideoSDKErrors_RAWDATA_SHARE_MODULE_ERROR,
	/** No shared data available. */
	ZNZoomVideoSDKErrors_RAWDATA_NO_SHARE_DATA,
	/** Audio module not ready. */
	ZNZoomVideoSDKErrors_RAWDATA_AUDIO_MODULE_NOT_READY,
	/** Audio module error. */
	ZNZoomVideoSDKErrors_RAWDATA_AUDIO_MODULE_ERROR,
	/** No audio data available. */
	ZNZoomVideoSDKErrors_RAWDATA_NO_AUDIO_DATA,
	/** Raw data preprocessing error. */
	ZNZoomVideoSDKErrors_RAWDATA_PREPROCESS_RAWDATA_ERROR,
	/** No media device is currently running. */
	ZNZoomVideoSDKErrors_RAWDATA_NO_DEVICE_RUNNING,
	/** Failed to initialize media device. */
	ZNZoomVideoSDKErrors_RAWDATA_INIT_DEVICE,
	/** Using a virtual device. */
	ZNZoomVideoSDKErrors_RAWDATA_VIRTUAL_DEVICE,
	/** Cannot change virtual device during preview. */
	ZNZoomVideoSDKErrors_RAWDATA_CANNOT_CHANGE_VIRTUAL_DEVICE_IN_PREVIEW,
	/** Internal raw data error. */
	ZNZoomVideoSDKErrors_RAWDATA_INTERNAL_ERROR,
	/** Sending too much raw data in a single call. */
	ZNZoomVideoSDKErrors_RAWDATA_SEND_TOO_MUCH_DATA_IN_SINGLE_TIME,
	/** Sending raw data too frequently. */
	ZNZoomVideoSDKErrors_RAWDATA_SEND_TOO_FREQUENTLY,
	/** Virtual microphone has been terminated. */
	ZNZoomVideoSDKErrors_RAWDATA_VIRTUAL_MIC_IS_TERMINATE,
	/** The share preprocessing data object is invalid. */
	ZNZoomVideoSDKErrors_RAWDATA_INVALID_SHARE_PREPROCESSING_DATA_OBJECT,
	/** Share preprocessing has stopped. */
	ZNZoomVideoSDKErrors_RAWDATA_SHARE_PREPROCESSING_IS_STOPPED,
	/** General share error. */
	ZNZoomVideoSDKErrors_Session_Share_Error = 7001,
	/** Share module is not ready. */
	ZNZoomVideoSDKErrors_Session_Share_Module_Not_Ready,
	/** You are not sharing. */
	ZNZoomVideoSDKErrors_Session_Share_You_Are_Not_Sharing,
	/** Share type is not supported. */
	ZNZoomVideoSDKErrors_Session_Share_Type_Is_Not_Support,
	/** Internal sharing error. */
	ZNZoomVideoSDKErrors_Session_Share_Internal_Error,
	/** Multi-stream video users are not supported. */
	ZNZoomVideoSDKErrors_Dont_Support_Multi_Stream_Video_User,
	/** Failed to assign user privilege. */
	ZNZoomVideoSDKErrors_Fail_Assign_User_Privilege,
	/** No recording in process. */
	ZNZoomVideoSDKErrors_No_Recording_In_Process,
	/** Recording is connecting. */
	ZNZoomVideoSDKErrors_Recording_Is_Connecting,
	/** Failed to set virtual background. */
	ZNZoomVideoSDKErrors_Set_Virtual_Background_Fail,
	/** Failed to start camera share due to video not started. */
	ZNZoomVideoSDKErrors_Session_Share_Camera_Video_Not_Start,
	/** Camera share conflicts with video effects. */
	ZNZoomVideoSDKErrors_Session_Share_Camera_Conflict_With_Video_Effects,
	/** Share conflicts with whiteboard share. */
	ZNZoomVideoSDKErrors_Session_Share_Conflict_With_Whiteboard,
	/** Unknown file transfer error. */
	ZNZoomVideoSDKErrors_Filetransfer_UnknowError = 7500,
	/** File type is blocked for transfer. */
	ZNZoomVideoSDKErrors_Filetransfer_FileTypeBlocked,
	/** File size exceeds the transfer limit. */
	ZNZoomVideoSDKErrors_Filetransfer_FileSizelimited,
	/** Not enough users for spotlighting. */
	ZNZoomVideoSDKErrors_Spotlight_NotEnoughUsers = 7600,
	/** Too many users are spotlighted. */
	ZNZoomVideoSDKErrors_Spotlight_ToMuchSpotlightedUsers,
	/** User cannot be spotlighted. */
	ZNZoomVideoSDKErrors_Spotlight_UserCannotBeSpotlighted,
	/** User does not have video to be spotlighted. */
	ZNZoomVideoSDKErrors_Spotlight_UserWithoutVideo,
	/** User is not currently spotlighted. */
	ZNZoomVideoSDKErrors_Spotlight_UserNotSpotlighted
}ZNZoomVideoSDKErrors;

/**
 * @brief Enumeration of session leave reasons in Zoom Video SDK.
 */
typedef enum
{
	/** Unknown reason for leaving the session. */
	ZNZoomVideoSDKSessionLeaveReason_Unknown = 0,
	/** User left the session by themselves. */
	ZNZoomVideoSDKSessionLeaveReason_BySelf,
	/** User was removed from the session by the host. */
	ZNZoomVideoSDKSessionLeaveReason_KickByHost,
	/** Host ended the session. */
	ZNZoomVideoSDKSessionLeaveReason_EndByHost,
	/** User was disconnected due to network error. */
	ZNZoomVideoSDKSessionLeaveReason_NetworkError,
}ZNZoomVideoSDKSessionLeaveReason;

/**
 * @brief Enumeration of sharing status in Zoom Video SDK.
 */
typedef enum
{
	/** No sharing activity. */
	ZNZoomVideoSDKShareStatus_None,
	/** Sharing has started. */
	ZNZoomVideoSDKShareStatus_Start,
	/** Sharing has been paused. */
	ZNZoomVideoSDKShareStatus_Pause,
	/** Sharing has resumed after being paused. */
	ZNZoomVideoSDKShareStatus_Resume,
	/** Sharing has been stopped. */
	ZNZoomVideoSDKShareStatus_Stop,
}ZNZoomVideoSDKShareStatus;

typedef enum
{
	ZNZoomVideoSDKSubscribeFailReason_None = 0,
	ZNZoomVideoSDKSubscribeFailReason_HasSubscribe1080POr720P,
	ZNZoomVideoSDKSubscribeFailReason_HasSubscribeTwo720P,
	ZNZoomVideoSDKSubscribeFailReason_HasSubscribeExceededLimit,
	ZNZoomVideoSDKSubscribeFailReason_HasSubscribeTwoShare,
	ZNZoomVideoSDKSubscribeFailReason_HasSubscribeVideo1080POr720PAndOneShare,
	ZNZoomVideoSDKSubscribeFailReason_TooFrequentCall,
}ZNZoomVideoSDKSubscribeFailReason;

/**
 * @brief Enumeration of sharing types in Zoom Video SDK.
 */
typedef enum
{
	/** No sharing type specified. */
	ZNZoomVideoSDKShareType_None,
	/** Application or desktop sharing. */
	ZNZoomVideoSDKShareType_Normal,
	/** Pure computer audio sharing. */
	ZNZoomVideoSDKShareType_PureAudio,
	/** Camera sharing. */
	ZNZoomVideoSDKShareType_Camera,
}ZNZoomVideoSDKShareType;

/**
 * @brief Enumeration of reasons why screen sharing capture is paused in the Zoom Video SDK.
 */
typedef enum
{
    /** No pause reason; used for initialization. */
    ZNZoomVideoSDKShare_Capture_Pause_None,
    /** Sharing is paused because the shared window is being moved. */
    ZNZoomVideoSDKShare_Capture_Pause_WindowMoving,
    /** Sharing is paused because the shared window is covered by another window. */
    ZNZoomVideoSDKShare_Capture_Pause_WindowCovered,
    /** Sharing is paused because the shared window is minimized. */
    ZNZoomVideoSDKShare_Capture_Pause_WindowMinimized
}ZNZoomVideoSDKShareCapturePauseReason;

/**
 * @brief Enumeration of live streaming status in Zoom Video SDK.
 */
typedef enum
{
	/** No live streaming activity. */
	ZNZoomVideoSDKLiveStreamStatus_None,
	/** Live streaming is currently in progress. */
	ZNZoomVideoSDKLiveStreamStatus_InProgress,
	/** Live streaming is connecting. */
	ZNZoomVideoSDKLiveStreamStatus_Connecting,
	/** Live streaming failed due to timeout. */
	ZNZoomVideoSDKLiveStreamStatus_FailedTimeout,
	/** Live streaming failed to start. */
	ZNZoomVideoSDKLiveStreamStatus_StartFailed,
	/** Live streaming has ended. */
	ZNZoomVideoSDKLiveStreamStatus_Ended,
}ZNZoomVideoSDKLiveStreamStatus;

/**
 * @brief Enumeration of raw data memory mode in Zoom Video SDK.
 */
typedef enum
{
	/** Raw data is allocated on the stack. */
	ZNZoomVideoSDKRawDataMemoryModeStack = 0,
	/** Raw data is allocated on the heap. */
	ZNZoomVideoSDKRawDataMemoryModeHeap,
}ZNZoomVideoSDKRawDataMemoryMode;

/**
 * @brief The extended parameters for Zoom Video SDK initialization.
 */
struct ZNZoomVideoSDKExtendParams
{
	/**
	 * The file path for speaker test playback.
	 * Only supports MP3 format. The file size must not exceed 1 MB.
	 */
	ZoomSTRING speakerTestFilePath;
	int wrapperType;
#if defined __MACOS__
	bool disableKeychainAccess;
#endif

	ZNZoomVideoSDKExtendParams()
	{
		wrapperType = 3;
#if defined __MACOS__
		disableKeychainAccess = false;
#endif
	}
};

/**
 * @brief The initialization parameters for Zoom Video SDK.
 */
struct ZNZoomVideoSDKInitParams
{
	/** The web domain used by the SDK. This is a required parameter. */
	ZoomSTRING domain;
	/** Prefix for the generated log file names. Optional. If not set, a default prefix will be used. */
	ZoomSTRING logFilePrefix;
	/** Whether to enable SDK logging. Optional. Default is false. */
	bool  enableLog;
#if defined(WIN32)
	/** Whether to enable per-monitor awareness mode. Optional. Default is false.
	 *	This parameter is ignored if the application is already enabled high-DPI awareness or per-monitor DPI awareness.
	 */
	bool  permonitorAwarenessMode;
#endif
	/** Memory allocation mode for audio raw data (stack or heap). Optional. Default is stack. */
	ZNZoomVideoSDKRawDataMemoryMode audioRawDataMemoryMode;
	/** Memory allocation mode for video raw data (stack or heap). Optional. Default is stack. */
	ZNZoomVideoSDKRawDataMemoryMode videoRawDataMemoryMode;
	/** Memory allocation mode for share raw data (stack or heap). Optional. Default is stack. */
	ZNZoomVideoSDKRawDataMemoryMode shareRawDataMemoryMode;

	/** Extended optional parameters for SDK initialization. */
	ZNZoomVideoSDKExtendParams extendParam;
	ZNZoomVideoSDKInitParams()
	{
		enableLog = false;
#if defined(WIN32)
		permonitorAwarenessMode = false;
#endif
		audioRawDataMemoryMode = ZNZoomVideoSDKRawDataMemoryModeStack;
		videoRawDataMemoryMode = ZNZoomVideoSDKRawDataMemoryModeStack;
		shareRawDataMemoryMode = ZNZoomVideoSDKRawDataMemoryModeStack;
	}
};

struct ZNZoomVideoSDKShareOption
{
	/** share option, true: share computer sound when share screen/window, otherwise not. */
	bool isWithDeviceAudio;
	/** share option, true: optimize the frame rate when share screen/window, otherwise not. */
	bool isOptimizeForSharedVideo;
	ZNZoomVideoSDKShareOption()
	{
		isWithDeviceAudio = false;
		isOptimizeForSharedVideo = false;
	}
};

/**
*@brief Video option used by ZoomVideoSDKSessionContext.
*/
struct ZNZoomVideoSDKVideoOption
{
	/**
	 * @brief Indicates whether the local video should be turned on by default.
	 * @note Default value is true.
	 */
    bool localVideoOn;
	ZNZoomVideoSDKVideoOption()
	{
		localVideoOn = true;
	}
};

/**
*@brief Aduio option used by ZoomVideoSDKSessionContext.
*/
struct ZNZoomVideoSDKAudioOption
{
	/**
	 * @brief Whether to connect the local audio when joining a session.
	 * @note Default is true.
	 */
    bool connect; ///<Whether to connect local audio or not.
	/**
	 * @brief Whether to mute the audio initially.
	 * @note Default is false.
	 */
    bool mute;
	ZNZoomVideoSDKAudioOption()
	{
		connect = true;
		mute = false;
	}
};

/**
 * @brief Configuration context for joining a Zoom Video SDK session.
 */
struct ZNZoomVideoSDKSessionContext
{
	/**
	 * @brief The name of the session to join.
	 * @note This is required.
	 */
    ZoomSTRING sessionName;
	/**
	 * @brief The password for the session.
	 * @note Optional.
	 */
    ZoomSTRING sessionPassword;
	/**
	 * @brief The display name of the user in the session.
	 * @note This is required.
	 */
    ZoomSTRING userName;
	 /**
	 * @brief The JWT token used for session authentication.
	 * @note This is required.
	 */
    ZoomSTRING token;
	/**
	 * @brief Video configuration options.
	 * @note Optional.
	 */
    ZNZoomVideoSDKVideoOption videoOption;
	/**
	 * @brief Audio configuration options.
	 * @note Optional.
	 */
    ZNZoomVideoSDKAudioOption audioOption;
	/**
	 * @brief Pointer to the camera data preprocessor object.
	 * @note Optional.
	 */
	bool preProcessor;
	/**
	 * @brief Pointer to the virtual camera source object.
	 * Use this to provide your own external video stream.
	 * @note Optional.
	 */
	bool externalVideoSource;
	/**
	 * @brief The duration (in minutes) before an idle session times out.
	 * If set to 0, the session will never timeout automatically.
	 * @note Optional. Default is 40 minutes.
	 */
	unsigned int sessionIdleTimeoutMins;
	ZNZoomVideoSDKSessionContext()
	{
		preProcessor = false;
		externalVideoSource = false;
		sessionIdleTimeoutMins = 40;
	}
};

/**
 * @brief Camera device struct.
 */
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

/**
 * @brief Enumeration of raw data types in Zoom Video SDK.
 */
typedef enum
{
	/** Raw video data. */
	ZNZoomVideoSDKRawDataType_VIDEO = 0,
	/** Raw share data (e.g., screen or application). */
	ZNZoomVideoSDKRawDataType_SHARE,
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

/**
 * @brief Share cursor information.
 */
typedef struct
{
	unsigned int source_id;
	int x;
	int y;
}ZNZoomVideoSDKShareCursorData;

/**
 * @brief Video status information on the user's video device (the detected compatible video camera device), and status (whether video is turned on or off).
 */
typedef struct tagZNZoomVideoSDKVideoStatus
{
	/** Determine if the user's device has a compatible camera. */
	bool isHasVideoDevice;
	/** Determine if the camera is turned on. */
	bool isOn;

	tagZNZoomVideoSDKVideoStatus()
	{
		isHasVideoDevice = false;
		isOn = false;
	}
}ZNZoomVideoSDKVideoStatus;

/**
 * @brief Audio type: VOIP (Voice over IP), Telephony, or None.
 */
typedef enum {
	ZNZoomVideoSDKAudioType_VOIP,
	ZNZoomVideoSDKAudioType_TELEPHONY,
	ZNZoomVideoSDKAudioType_None,
}ZNZoomVideoSDKAudioType;

/**
 * @brief Audio status information.
 */
struct ZNZoomVideoSDKAudioStatus
{
	ZNZoomVideoSDKAudioType audioType;
	bool isMuted;
	bool isTalking;
	ZNZoomVideoSDKAudioStatus()
	{
		audioType = ZNZoomVideoSDKAudioType_None;
		isMuted = false;
		isTalking = false;
	}
};

/**
 * @brief Video statistic information.
 */
struct ZNZoomVideoSDKVideoStatisticInfo
{
	int width;
	int height;
	int fps;
	int bpf;
};

typedef enum
{
	ZNZoomVideoSDKNetwork_None,
	ZNZoomVideoSDKNetwork_Bad,
	ZNZoomVideoSDKNetwork_Normal,
	ZNZoomVideoSDKNetwork_Good,
}ZNZoomVideoSDKNetworkStatus;

/**
 * @brief Share statistic information.
 */
struct ZNZoomVideoSDKShareStatisticInfo
{
	int width;
	int height;
	int fps;
	int bpf;
	ZNZoomVideoSDKNetworkStatus shareNetworkStatus;

	ZNZoomVideoSDKShareStatisticInfo()
	{
		width = 0;
		height = 0;
		fps = 0;
		bpf = 0;
		shareNetworkStatus = ZNZoomVideoSDKNetwork_None;
	}
};

typedef enum {
	ZNUserInfoType_FAKE,
	ZNUserInfoType_REAL,
}ZNUserInfoType;

typedef struct _ZNShareAction
{
	/** Share source ID. */
	unsigned int shareSourceId;
	/** Share status. */
	ZNZoomVideoSDKShareStatus shareStatus;
	/** Subscribe fail reason. */
	ZNZoomVideoSDKSubscribeFailReason subscribeFailReason;
	/** Whether annotation privilege is enabled. */
	bool isAnnotationPrivilegeEnabled;
	/** Share type. */
	ZNZoomVideoSDKShareType shareType;
	_ZNShareAction()
	{
		shareStatus = ZNZoomVideoSDKShareStatus_None;
		isAnnotationPrivilegeEnabled = false;
	}
}ZNShareAction;

/**
 * @brief User object structure.
 */
typedef struct tagZNZoomVideoSDKUserInfo
{
	/** The user's id. */
	unsigned int userID;
	/** The user's custom id. */
	ZoomSTRING customIdentity;
	/** The user's name. */
	ZoomSTRING userName;
	/** The user's reference info. */
	ZoomSTRING userReference;
	//ZoomSTRING emailAddress;
	/** The user's video status. */
	ZNZoomVideoSDKVideoStatus videoStatus;
	/** The user's audio status. */
	ZNZoomVideoSDKAudioStatus audioStatus;
	/** The user's share-action list. */
	std::vector<ZNShareAction> shareActionList;
	/** Whether the user is the host. */
	bool isHost;
	/** Whether the user is the manager(coHost). */
	bool isManager;
	/** Whether the user is spotLighted. */
	bool isVideoSpotLighted;
	/** Whether the user is incoming live stream user. */
	bool isIncomingLiveStreamUser;
	/** Video statistic information. */
	ZNZoomVideoSDKVideoStatisticInfo videoStatisticInfo;
	/** Share statistic information. */
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
	/** Notification of joining the session. */
	CallMessageType_onSessionJoin = 0,
	/** Notification of leaving the session with reason. */
	CallMessageType_onSessionLeave,
	/** Notification of errors occur when join session. */
	CallMessageType_onError,
	/** Notification of a user joins the session. */
	CallMessageType_onUserJoin,
	/** Notification of a user leaves the session */
	CallMessageType_onUserLeave,
	/** Notification of a user makes changes to their video, such as starting or stopping their video. */
	CallMessageType_onUserVideoStatusChanged,
	/** Notification of a user makes changes to their audio, such as muting or unmuting their audio. */
	CallMessageType_onUserAudioStatusChanged,
	/** Notification of a user makes changes to their sharing status, such as starting screen sharing, starting view sharing, or stopping sharing. */
	CallMessageType_onUserShareStatusChanged,
	/** Notification of a user makes changes to their live stream status. */
	CallMessageType_onLiveStreamStatusChanged,
	/** Notification of receiving a chat message. */
	CallMessageType_onChatNewMessageNotify,
	/** Notification of the session host changes. */
	CallMessageType_onUserHostChanged,
	/** Notification of the active audio changes. */
	CallMessageType_onUserActiveAudioChanged,
	/** Notification of the session requires a password to join. */
	CallMessageType_onSessionNeedPassword,
	/** Notification of the provided session password is wrong or invalid. */
	CallMessageType_onSessionPasswordWrong,

	/** Video source initialize event. */
	CallMessageType_onVideoSourceInitialize,
	/** Property change event. */
	CallMessageType_onPropertyChange,
	/** Start send event. */
	CallMessageType_onStartSend,
	/** Stop send event. */
	CallMessageType_onStopSend,
	/** Uninitialized event. */
	CallMessageType_onUninitialized,
	/** Raw data status changed event. */
	CallMessageType_onRawDataStatusChanged,

	/** Notification of the manager of the session changes. */
	CallMessageType_onUserManagerChanged,
	/** Notification of user name changed. */
	CallMessageType_onUserNameChanged,
	/** Notification of receiving a message, data, or a command from the command channel. */
	CallMessageType_onCommandReceived,
	/** Notification of cloud recording status has paused, stopped, resumed, or otherwise changed. */
	CallMessageType_onCloudRecordingStatus,
	/** Notification of the current user is granted camera control access. */
	CallMessageType_onCameraControlRequestResult,
	/** Notification of the current user has received a camera control request. */
	CallMessageType_onCameraControlRequestReceived,
	/** Notification of the command channel is ready to be used. */
	CallMessageType_onCommandChannelConnectResult,
	/** Notification of a host requests you to unmute yourself. */
	CallMessageType_onHostAskUnmute,
	/** Notification of the invite by phone status changes to any other valid status such as Calling, Ringing, Success, or Failed. */
	CallMessageType_onInviteByPhoneStatus,
	/** Notification of someone in a given session enables or disables multi-camera. All participants in the session receive this callback. */
	CallMessageType_onMultiCameraStreamStatusChanged,
	/** Notification of the current mic or speaker volume changed. */
	CallMessageType_onMicSpeakerVolumeChanged,
	/** Notification of mic device or speaker device status changed. */
	CallMessageType_onAudioDeviceStatusChanged,
	/** Notification of the mic status changed when testing. */
	CallMessageType_onTestMicStatusChanged,
	/** Notification of the selected mic/speaker device is changed when testing. Then the SDK will close the mic/speaker testing. The user shall restart the test manually if he still wants to test. */
	CallMessageType_onSelectedAudioDeviceChanged,
	/** Notification of live transcription status changes. */
	CallMessageType_onLiveTranscriptionStatus,
	/** Notification of a live translation error occurs. */
	CallMessageType_onLiveTranscriptionMsgError = 36,
	/** Notification of a user deletes a chat message. */
	CallMessageType_onChatMsgDeleteNotification,
	/** Notification of a live transcription message is received. */
	CallMessageType_onLiveTranscriptionMsgInfoReceived,
	/** Notification of the spoken language has changed. */
	CallMessageType_onOriginalLanguageMsgReceived,
	/** Notification of the callout user successfully joins the meeting. */
	CallMessageType_onCalloutJoinSuccess,
	/** Notification of share cursor data received. */
	CallMessageType_onShareCursorDataReceived,
	/** Notification of the remote control status changes. */
	CallMessageType_onRemoteControlStatus,
	/** Notification of the current user has received a remote control request. */
	CallMessageType_onRemoteControlRequestReceived,
	/** Callback after the first invocation of IZoomVideoSDKShareSettingHelper::enableAdminRemoteControl(true). */
	CallMessageType_onRemoteControlServiceInstallResult,
	/** Notification of spotlighted video user changed. */
	CallMessageType_onSpotlightVideoChanged,
	/** Notification of the response that binding the incoming live stream. */
	CallMessageType_onBindIncomingLiveStreamResponse,
	/** Notification of the response that unbinding the incoming live stream. */
	CallMessageType_onUnbindIncomingLiveStreamResponse,
	/** Notification of the response that gets the streams status. */
	CallMessageType_onIncomingLiveStreamStatusResponse,
	/** Notification of the response that starts the bound stream. */
	CallMessageType_onStartIncomingLiveStreamResponse,
	/** Notification of the response that stops the bound stream. */
	CallMessageType_onStopIncomingLiveStreamResponse,
	/** Notification of a user failed to start sharing. */
	CallMessageType_onFailedToStartShare,
	/** Notification of the camera list has changed. */
	CallMessageType_onCameraListChanged,
	/** Notification of a user makes changes to their share content type, such as camera share switch to normal share. The share type can be found in \link ZNZoomVideoSDKShareType \endlink. */
	CallMessageType_onShareContentChanged,
	/** Notification of the share content size has changed.
	 * @note A share content size change may occur in two cases:
	 *       when the first frame of shared content is received (from no content to having a size),
	 *       or when the content size actually changes during sharing.
	 */
	CallMessageType_onShareContentSizeChanged,
	/** You will receive this callback when calling 'startShareWithPreprocessing' successfully. */
	CallMessageType_onCapturedRawDataReceived,
	/** In this event notification, you can perform some stop and destroy actions if necessary. */
	CallMessageType_onCapturedShareStopped,
	/** Notification of share setting changed. */
	CallMessageType_onShareSettingChanged,
	/** Notification of the current user's share network quality changes. */
	CallMessageType_onShareNetworkStatusChanged,
	/** Notification of the audio level changes for a participant (excluding self). */
	CallMessageType_onAudioLevelChanged,
	/** Notification of the current user's share network quality changes. */
	CallMessageType_onUserNetworkStatusChanged,
	/** Notification of user's overall network status changes. */
	CallMessageType_onUserOverallNetworkStatusChanged,
	/** Notification of the real-time media stream's status changed. */
	CallMessageType_onRealTimeMediaStreamsStatus,
	/** Notification of the real-time media stream failure reason. */
	CallMessageType_onRealTimeMediaStreamsFail,
	/** Notification of the list of unsharing windows has changed.
	 * @note This callback is only supported on macOS.
	 */
	CallMessageType_onUnsharingWindowsChanged,
}ZNCallMessageType;

/**
 * @brief Status of telephone.
 * Here are more detailed structural descriptions.
 */
typedef enum {
	/** No status. */
	ZNPhoneStatus_None,
	/** In process of calling out. */
	ZNPhoneStatus_Calling,
	/** In process of ringing. */
	ZNPhoneStatus_Ringing,
	/** Accept the call. */
	ZNPhoneStatus_Accepted,
	/** Call successful. */
	ZNPhoneStatus_Success,
	/** Call failed. */
	ZNPhoneStatus_Failed,
	/** In process of canceling the response to the previous state. */
	ZNPhoneStatus_Canceling,
	/** Cancel successfully. */
	ZNPhoneStatus_Canceled,
	/** Cancel fails. */
	ZNPhoneStatus_Cancel_Failed,
	/** Timeout. */
	ZNPhoneStatus_Timeout,
}ZNPhoneStatus;

/**
 * @brief The reason for the failure of the telephone call.
 * Here are more detailed structural descriptions.
 */
typedef enum {
	/** For initialization. */
	ZNPhoneFailedReason_None,
	/** The telephone service is busy. */
	ZNPhoneFailedReason_Busy,
	/** The telephone is out of the service. */
	ZNPhoneFailedReason_Not_Available,
	/** The user hangs up. */
	ZNPhoneFailedReason_User_Hangup,
	/** Other reasons. */
	ZNPhoneFailedReason_Other_Fail,
	/** The telephone does not reply. */
	ZNPhoneFailedReason_No_Answer,
	/** Disable the function of international call-out before the host joins the session. */
	ZNPhoneFailedReason_Block_No_Host,
	/** The call-out is blocked by the system due to the high cost. */
	ZNPhoneFailedReason_Block_High_Rate,
	/** All the invitees invited by the call should press the button one(1) to join the session. In case that many invitees do not press the button that leads to time out, the call invitation for this meeting shall be banned. */
	ZNPhoneFailedReason_Block_Too_Frequent,
}ZNPhoneFailedReason;

/**
 * @brief Enumeration representing the status of recording.
 */
enum ZNRecordingStatus
{
	/** The recording has successfully started or resumed. */
	ZNRecording_Start,
	/** The recording has been stopped. */
	ZNRecording_Stop,
	/** The recording failed due to insufficient disk space. */
	ZNRecording_DiskFull,
	/** The recording has been paused. */
	ZNRecording_Pause,
	/** The recording is connecting. */
	ZNRecording_Connecting
};

/**
 * @brief Enumeration of camera control request types in Zoom Video SDK.
 */
typedef enum
{
	/** Request camera control. */
	ZNZoomVideoSDKCameraControlRequestType_RequestControl = 0,
	/** Give up camera control. */
	ZNZoomVideoSDKCameraControlRequestType_GiveUpControl

}ZNZoomVideoSDKCameraControlRequestType;

/**
 * @brief Enumeration of remote control status in Zoom Video SDK.
 */
enum ZNZoomVideoSDKRemoteControlStatus
{
	/** For initialization. */
	ZNZoomVideoSDKRemoteControlStatus_None = 0,
	/** Remote control information. I can enable the remote control. */
	ZNZoomVideoSDKRemoteControlStatus_CanRequestControl,
	/** Remote control information. I have received a refused information of remote control. */
	ZNZoomVideoSDKRemoteControlStatus_RequestDenied,
	/** The authority of remote control. I get control when remote control begins. */
	ZNZoomVideoSDKRemoteControlStatus_GotControl,
	/** The authority of remote control. I lose control when remote control ends. */
	ZNZoomVideoSDKRemoteControlStatus_LostControl,
	 /** The status of remote control. I am remotely controlling another. */
	ZNZoomVideoSDKRemoteControlStatus_ControlStart,
	/** The status of remote control. I am not remotely controlling another. */
	ZNZoomVideoSDKRemoteControlStatus_ControlStop,
	/** The status of remote control. I can be controlled by the specified user. */
	ZNZoomVideoSDKRemoteControlStatus_GiveControlTo,
	/** The status of remote control. I have revoked remote control. */
	ZNZoomVideoSDKRemoteControlStatus_ControlRevoked,
	/** The status of remote control. I am being controlled by the specified user. */
	ZNZoomVideoSDKRemoteControlStatus_ControlledBy,
	/** The status of remote control. I am not being controlled. */
	ZNZoomVideoSDKRemoteControlStatus_NotControlled,
};

/**
 * @brief video preference mode types
 * Here are more detailed structural descriptions.
 */
typedef enum
{
	/** Balance mode. */
	ZNZoomVideoSDKVideoPreferenceMode_Balance,
	/** Sharpness mode. */
	ZNZoomVideoSDKVideoPreferenceMode_Sharpness,
	/** Smoothness mode. */
	ZNZoomVideoSDKVideoPreferenceMode_Smoothness,
	/** Custom mode. */
	ZNZoomVideoSDKVideoPreferenceMode_Custom
}ZNZoomVideoSDKVideoPreferenceMode;

/**
 * @brief When setting custom modes, the maximum and minimum frame rates are provided by the developer.
 * If the current bandwidth cannot maintain the minimum frame rate, the video system will drop to the next lower resolution.
 * The default maximum and minimum frame rates for other modes are 0.
 */
typedef struct tagZNVideoPreferenceSetting
{
	/** 0: Balance mode; 1: Smoothness mode; 2: Sharpness mode; 3: Custom mode. */
	ZNZoomVideoSDKVideoPreferenceMode mode;
	/** 0 for the default value, minimum_frame_rate should be less than maximum_frame_rate, range: from 0 to 30. Out of range for frame-rate will use default frame-rate of Zoom. */
	uint32_t minimum_frame_rate;
	/** 0 for the default value, maximum_frame_rate should be less and equal than 30, range: from 0 to 30. Out of range for frame-rate will use default frame-rate of Zoom. */
	uint32_t maximum_frame_rate;
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
	ZNZoomVideoSDKEchoCancellationLevel_Low,
    ZNZoomVideoSDKEchoCancellationLevel_High
}ZNZoomVideoSDKEchoCancellationLevel;

typedef enum {
	/** Current user only. Sent when the current user attempts to use multiple cameras in the session. */
	ZNZoomVideoSDKMultiCameraStreamStatus_JoinStart,
	/** Current user only. Sent when the current user fails to use multiple cameras in the session. */
	ZNZoomVideoSDKMultiCameraStreamStatus_JoinFail,
	/** Broadcast to all users. Sent when a new camera has been successfully added to the session as the multiple cameras. */
	ZNZoomVideoSDKMultiCameraStreamStatus_Joined,
	/** Broadcast to all users. Sent after a camera that is being used as the multiple cameras leaves the session. */
	ZNZoomVideoSDKMultiCameraStreamStatus_Left,
	/** Broadcast to all users. Sent when a multiple camera is started. */
	ZNZoomVideoSDKMultiCameraStreamStatus_VideoOn,
	/** Broadcast to all users. Sent when a multiple camera is stopped. */
	ZNZoomVideoSDKMultiCameraStreamStatus_VideoOff,
}ZNZoomVideoSDKMultiStreamStatus;

/**
 * @brief Enumeration of the microphone test status in Zoom Video SDK.
 */
typedef	enum
{
	/** Test the mic via TestMicStartRecording. It is useless to call TestMicStopTesting/TestMicPlayRecording in this status. */
	ZNZoomVideoSDKMic_CanTest = 0,
	/** Test the mic via TestMicStopTesting/TestMicPlayRecording. It is useless to call TestMicStartRecording in this status. */
	ZNZoomVideoSDKMic_Recording,
	/** Test the mic via TestMicStopTesting/TestMicPlayRecording. It is useless call TestMicStartRecording in this status. */
	ZNZoomVideoSDKMic_CanPlay,
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
	ZNZoomVideoSDK_Audio_Disconnect_As_Detected_Echo,
	ZNZoomVideoSDK_Audio_Talk_While_Muted
}ZNZoomVideoSDKAudioDeviceStatus;

enum ZNVideoSourceDataMode
{
	/** For general usage scenarios. */
	ZNVideoSourceDataMode_None = 0,
	/** Special usage scenarios, each frame of video is organized around two images. */
	ZNVideoSourceDataMode_Horizontal,
	/** Special usage scenarios, each frame of video is two images organized up and down together. */
	ZNVideoSourceDataMode_Vertical
};

/**
 * @brief Video source capability information.
 */
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
	/** not start */
	ZNZoomVideoSDKLiveTranscription_Status_Stop = 0,
	/** start */
	ZNZoomVideoSDKLiveTranscription_Status_Start = 1,
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

/**
 * @brief Live transcription language structure.
 */
typedef struct tagZNLiveTranscriptionLanguage
{
	/** The id of the language. */
	int lttLanguageID;
	/** The name of the language. */
	ZoomSTRING lttLanguageName;

	tagZNLiveTranscriptionLanguage()
	{
		lttLanguageID = 0;
	}
}ZNLiveTranscriptionLanguage;

/**
 * @brief The chat message delete type are sent in the \link onChatMsgDeleteNotification  \endlink callback.
 */
typedef enum {
	/** None. */
	ZNZoomVideoSDKChatDelete_None = 0,
	/** Indicates that the message was deleted by myself. */
	ZNZoomVideoSDKChatDelete_BySelf,
	/** Indicates that the message was deleted by the session host. */
    ZNZoomVideoSDKChatDelete_ByHost,
	/** Indicates that the message was deleted by Data Loss Prevention (dlp). This happens when the message goes against the host organization's compliance policies. */
    ZNZoomVideoSDKChatDelete_ByDlp,
}ZNZoomVideoSDKChatMessageDeleteType;

/**
 * @brief live transcription message structure.
 */
typedef struct tagZNLiveTranscriptionMessageInfo
{
	/** The timestamp of the current message. */
	time_t timeStamp;
	/** The message ID of the current message. */
	ZoomSTRING messageID;
	/** The content of the current message. */
	ZoomSTRING messageContent;
	/** The speaker's name. */
	ZoomSTRING speakerName;
	/** The speaker's ID. */
	ZoomSTRING speakerID;
	/** The type of the current message. */
	ZNZoomVideoSDKLiveTranscriptionOperationType messageType;

	tagZNLiveTranscriptionMessageInfo()
	{
		messageType = ZNZoomVideoSDKLiveTranscription_OperationType_None;
	}
}ZNLiveTranscriptionMessageInfo;

/**
 * @brief The info for InvitePhoneUser
 */
struct ZNInvitePhoneUserInfo
{
	/** InvitePhoneUserInfo, The country code of the specified user must be in the support list. */
	ZoomSTRING countryCode;
	/** InvitePhoneUserInfo, The phone number of specified user. */
	ZoomSTRING phoneNumber;
	/** InvitePhoneUserInfo, The screen name of the specified user in the session. */
	ZoomSTRING name;
	/** InvitePhoneUserInfo , true: Need press number one to agree to join the session, otherwise not. */
	bool bPressOne;
	/** InvitePhoneUserInfo, true: When joining the session, play a greeting prompt tone., otherwise not. */
	bool bGreeting;

	ZNInvitePhoneUserInfo()
	{
		bPressOne = true;
		bGreeting = true;
	}
};

typedef enum {
	/** Screen capture mode is automatically. */
	ZNZoomVideoSDKScreenCaptureMode_Auto = 0,
	/** Screen capture mode is legacy operating systems. */
	ZNZoomVideoSDKScreenCaptureMode_Legacy,
	/** Screen capture mode is capture with window filtering. */
	ZNZoomVideoSDKScreenCaptureMode_Filtering,
	/** Screen capture mode is advanced share with window filtering. */
	ZNZoomVideoSDKScreenCaptureMode_ADA_Filtering,
	/** Screen capture mode is advanced share without window filtering. */
	ZNZoomVideoSDKScreenCaptureMode_ADA_Without_Filtering,
	/** Screen capture mode is secure share with window filtering. */
	ZNZoomVideoSDKScreenCaptureMode_Secure_Filtering,
}ZNZoomVideoSDKScreenCaptureMode;

enum ZNZoomVideoSDKSharePreprocessType
{
	/** For initialization. */
	ZNZoomVideoSDKSharePreprocessType_none,
	/** For share screen(monitor). */
	ZNZoomVideoSDKSharePreprocessType_screen,
	/** For share view(application window). */
	ZNZoomVideoSDKSharePreprocessType_view,
#if defined(__MACOS__)
    /** For share process(application). */
    ZNZoomVideoSDKSharePreprocessType_process
#endif
};

struct ZNZoomVideoSDKSharePreprocessParam
{
	/** The share pre-process type. */
	ZNZoomVideoSDKSharePreprocessType type;
	/** The window handle that to share and pre-process. */
	ZoomSTRING handle;
	/** The screen name that to share and pre-process. */
	ZoomSTRING monitorID;
	uint32_t processID;

	ZNZoomVideoSDKSharePreprocessParam()
	{
		type = ZNZoomVideoSDKSharePreprocessType_none;
		processID = 0;
	}
};

enum ZNZoomVideoSDKAnnotationToolType
{
	ZNZoomVideoSDKAnnotationToolType_None,
	ZNZoomVideoSDKAnnotationToolType_Pen,
	ZNZoomVideoSDKAnnotationToolType_HighLighter,
	ZNZoomVideoSDKAnnotationToolType_AutoLine,
	ZNZoomVideoSDKAnnotationToolType_AutoRectangle,
	ZNZoomVideoSDKAnnotationToolType_AutoEllipse,
	ZNZoomVideoSDKAnnotationToolType_AutoArrow,
	ZNZoomVideoSDKAnnotationToolType_AutoRectangleFill,
	ZNZoomVideoSDKAnnotationToolType_AutoEllipseFill,
	ZNZoomVideoSDKAnnotationToolType_SpotLight,
	ZNZoomVideoSDKAnnotationToolType_Arrow,
	ZNZoomVideoSDKAnnotationToolType_ERASER,
	ZNZoomVideoSDKAnnotationToolType_Textbox,
	ZNZoomVideoSDKAnnotationToolType_Picker,
	ZNZoomVideoSDKAnnotationToolType_AutoRectangleSemiFill,
	ZNZoomVideoSDKAnnotationToolType_AutoEllipseSemiFill,
	ZNZoomVideoSDKAnnotationToolType_AutoDoubleArrow,
	ZNZoomVideoSDKAnnotationToolType_AutoDiamond,
	ZNZoomVideoSDKAnnotationToolType_AutoStampArrow,
	ZNZoomVideoSDKAnnotationToolType_AutoStampCheck,
	ZNZoomVideoSDKAnnotationToolType_AutoStampX,
	ZNZoomVideoSDKAnnotationToolType_AutoStampStar,
	ZNZoomVideoSDKAnnotationToolType_AutoStampHeart,
	ZNZoomVideoSDKAnnotationToolType_AutoStampQm,
	ZNZoomVideoSDKAnnotationToolType_VanishingPen,
	ZNZoomVideoSDKAnnotationToolType_VanishingArrow,
	ZNZoomVideoSDKAnnotationToolType_VanishingDoubleArrow,
	ZNZoomVideoSDKAnnotationToolType_VanishingDiamond,
	ZNZoomVideoSDKAnnotationToolType_VanishingEllipse,
	ZNZoomVideoSDKAnnotationToolType_VanishingRectangle,
};

typedef enum {
	/** Clear all annotations. */
	ZNZoomVideoSDKAnnotationClearType_All,
	/** Clear only the others' annotations. */
	ZNZoomVideoSDKAnnotationClearType_Others,
	/** Clear only your own annotations. */
	ZNZoomVideoSDKAnnotationClearType_My,
}ZNZoomVideoSDKAnnotationClearType;

/**
 * @brief Enumeration of Zoom Video SDK share setting types.
 */
enum ZNZoomVideoSDKShareSetting
{
    /** For initialization. */
    ZNZoomVideoSDKShareSetting_None = 0,
    /** Only host and manager can share. */
    ZNZoomVideoSDKShareSetting_LockedShare,
    /** Anyone can share, but only one at a time. Only host and manager can take over. */
    ZNZoomVideoSDKShareSetting_SingleShare,
    /** Multiple participants can share simultaneously. */
    ZNZoomVideoSDKShareSetting_MultiShare
};

/**
 * @brief Enumeration of the data type for network quality monitoring.
 */
enum ZNZoomVideoSDKDataType
{
    /** Unknown data type. */
    ZNZoomVideoSDKDataType_Unknown,
    /** Audio data type. */
    ZNZoomVideoSDKDataType_Audio,
    /** Video data type. */
    ZNZoomVideoSDKDataType_Video,
    /** Share data type. */
    ZNZoomVideoSDKDataType_Share
};

/**
 * @brief real-time media streams status.
 */
enum ZNRealTimeMediaStreamsStatus
{
	/** No real-time media streams activity. */
	ZNRealTimeMediaStreams_None,
	/** Real-time media streams has started. */
	ZNRealTimeMediaStreams_Start,
	/** Real-time media streams has been paused. */
	ZNRealTimeMediaStreams_Pause,
	/** Real-time media streams has been stopped. */
	ZNRealTimeMediaStreams_Stop,
};

/**
 * @brief Failure reasons for RealTimeMediaStreams.
 */
enum ZNRealTimeMediaStreamsFailReason
{
	/** Default value, no error (initial state) */
	ZNRealTimeMediaStreamsFailReason_None,
	/** No users have subscribed to the RTMS */
	ZNRealTimeMediaStreamsFailReason_NoSubscription,
	/** Failed to start the RTMS */
	ZNRealTimeMediaStreamsFailReason_StartFail
};


////////////////////////////////////////////////////////////////////////////////////////////////////////
#define ZNList std::vector
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
#if (defined BUILD_WIN)
#define JS_WRAP
//#define UserInterfaceClass
#endif
