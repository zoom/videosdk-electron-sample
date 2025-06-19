
/**
 * @brief Enumerates all  errors in the VideoSDK.
 */
typedef enum
{
    /** Success. */
    ZMVideoSDKErrors_Success = 0,
    /** Wrong usage. */
    ZMVideoSDKErrors_Wrong_Usage,
    /** Internal error. */
    ZMVideoSDKErrors_Internal_Error,
    /** SDK is not initialized. */
    ZMVideoSDKErrors_Uninitialize,
    /** Memory allocation error. */
    ZMVideoSDKErrors_Memory_Error,
    /** Failed to load module. */
    ZMVideoSDKErrors_Load_Module_Error,
    /** Failed to unload module. */
    ZMVideoSDKErrors_UnLoad_Module_Error,
    /** One or more parameters are invalid. */
    ZMVideoSDKErrors_Invalid_Parameter,
    /** API called too frequently. */
    ZMVideoSDKErrors_Call_Too_Frequently,
    /** Function not implemented. */
    ZMVideoSDKErrors_No_Impl,
    /** Feature not supported. */
    ZMVideoSDKErrors_Dont_Support_Feature,
    /** Unknown error. */
    ZMVideoSDKErrors_Unknown,
    /** Failed to remove folder. */
    ZMVideoSDKErrors_Remove_Folder_Fail,
    
    /** Authorization related errors */
    /** Authorization failure. */
    ZMVideoSDKErrors_Auth_Error = 1001,
    /** App key or secret is empty. */
    ZMVideoSDKErrors_Auth_Empty_Key_or_Secret,
    /** App key or secret is incorrect. */
    ZMVideoSDKErrors_Auth_Wrong_Key_or_Secret,
    /** Not support SDK. */
    ZMVideoSDKErrors_Auth_DoesNot_Support_SDK,
    /** SDK is disabled. */
    ZMVideoSDKErrors_Auth_Disable_SDK,
    
    /** Join session errors */
    /** Session name is missing. */
    ZMVideoSDKErrors_JoinSession_NoSessionName = 1500,
    /** Session token is missing. */
    ZMVideoSDKErrors_JoinSession_NoSessionToken,
    /** Username is missing. */
    ZMVideoSDKErrors_JoinSession_NoUserName,
    /** Session name is invalid. */
    ZMVideoSDKErrors_JoinSession_Invalid_SessionName,
    /** Password is incorrect. */
    ZMVideoSDKErrors_JoinSession_Invalid_Password,
    /** Session token is invalid. */
    ZMVideoSDKErrors_JoinSession_Invalid_SessionToken,
    /** Session name is too long.*/
    ZMVideoSDKErrors_JoinSession_SessionName_TooLong,
    /** Token does not match session name. */
    ZMVideoSDKErrors_JoinSession_Token_MismatchedSessionName,
    /** Token does not contain a session name. */
    ZMVideoSDKErrors_JoinSession_Token_NoSessionName,
    /** Role type in token is empty or incorrect. */
    ZMVideoSDKErrors_JoinSession_Token_RoleType_EmptyOrWrong,
    /** User identity in token is too long. */
    ZMVideoSDKErrors_JoinSession_Token_UserIdentity_TooLong,
    
    /** Session-related errors */
    /** Session module not found. */
    ZMVideoSDKErrors_SessionModule_Not_Found = 2001,
    /** Invalid session service. */
    ZMVideoSDKErrors_SessionService_Invalid,
    /** Failed to join session. */
    ZMVideoSDKErrors_Session_Join_Failed,
    /** No permission to join session. */
    ZMVideoSDKErrors_Session_No_Rights,
    /** Already in progress. */
    ZMVideoSDKErrors_Session_Already_In_Progress,
    /** Unsupported session type. */
    ZMVideoSDKErrors_Session_Dont_Support_SessionType,
    /** Session is reconnecting. */
    ZMVideoSDKErrors_Session_Reconnecting,
    /** Session is disconnecting. */
    ZMVideoSDKErrors_Session_Disconnecting,
    /** Session has not started. */
    ZMVideoSDKErrors_Session_Not_Started,
    /** Password is required to join. */
    ZMVideoSDKErrors_Session_Need_Password,
    /** Incorrect session password. */
    ZMVideoSDKErrors_Session_Password_Wrong,
    /** Remote database error. */
    ZMVideoSDKErrors_Session_Remote_DB_Error,
    /** Invalid parameter. */
    ZMVideoSDKErrors_Session_Invalid_Param,
    /** Client version is incompatible. */
    ZMVideoSDKErrors_Session_Client_Incompatible,
    /** Free minutes exceeded. */
    ZMVideoSDKErrors_Session_Account_FreeMinutesExceeded,
    
    /** Audio errors */
    /** General audio error. */
    ZMVideoSDKErrors_Session_Audio_Error = 3000,
    /** No microphone detected. */
    ZMVideoSDKErrors_Session_Audio_No_Microphone,
    /** No speaker detected. */
    ZMVideoSDKErrors_Session_Audio_No_Speaker,
    
    /** Video errors. */
    /** General video error. */
    ZMVideoSDKErrors_Session_Video_Error = 4000,
    /** Video device error. */
    ZMVideoSDKErrors_Session_Video_Device_Error,
    
    /** Live stream error. */
    ZMVideoSDKErrors_Session_Live_Stream_Error = 5000,
    
    /** Phone error. */
    ZMVideoSDKErrors_Session_Phone_Error = 5500,
    
    /** Raw data errors */
    /** Memory allocation for raw data failed. */
    ZMVideoSDKErrors_RAWDATA_MALLOC_FAILED = 6001,
    /** Not in session. */
    ZMVideoSDKErrors_RAWDATA_NOT_IN_Session,
    /** No raw data license. */
    ZMVideoSDKErrors_RAWDATA_NO_LICENSE,
    /** Video module not ready. */
    ZMVideoSDKErrors_RAWDATA_VIDEO_MODULE_NOT_READY,
    /** Video module error. */
    ZMVideoSDKErrors_RAWDATA_VIDEO_MODULE_ERROR,
    /** Video device error. */
    ZMVideoSDKErrors_RAWDATA_VIDEO_DEVICE_ERROR,
    /** No video data available. */
    ZMVideoSDKErrors_RAWDATA_NO_VIDEO_DATA,
    /** Share module not ready. */
    ZMVideoSDKErrors_RAWDATA_SHARE_MODULE_NOT_READY,
    /** Share module error. */
    ZMVideoSDKErrors_RAWDATA_SHARE_MODULE_ERROR,
    /** No shared data available. */
    ZMVideoSDKErrors_RAWDATA_NO_SHARE_DATA,
    /** Audio module not ready. */
    ZMVideoSDKErrors_RAWDATA_AUDIO_MODULE_NOT_READY,
    /** Audio module error. */
    ZMVideoSDKErrors_RAWDATA_AUDIO_MODULE_ERROR,
    /** No audio data available. */
    ZMVideoSDKErrors_RAWDATA_NO_AUDIO_DATA,
    /** Raw data pre-processing failed. */
    ZMVideoSDKErrors_RAWDATA_PREPROCESS_RAWDATA_ERROR,
    /** No device is running. */
    ZMVideoSDKErrors_RAWDATA_NO_DEVICE_RUNNING,
    /** Failed to initialize media device. */
    ZMVideoSDKErrors_RAWDATA_INIT_DEVICE,
    /** Virtual device error. */
    ZMVideoSDKErrors_RAWDATA_VIRTUAL_DEVICE,
    /** Cannot change virtual device during preview. */
    ZMVideoSDKErrors_RAWDATA_CANNOT_CHANGE_VIRTUAL_DEVICE_IN_PREVIEW,
    /** Internal raw data error. */
    ZMVideoSDKErrors_RAWDATA_INTERNAL_ERROR,
    /** Too much data sent at once. */
    ZMVideoSDKErrors_RAWDATA_SEND_TOO_MUCH_DATA_IN_SINGLE_TIME,
    /** Data sent too frequently. */
    ZMVideoSDKErrors_RAWDATA_SEND_TOO_FREQUENTLY,
    /** Virtual microphone has been terminated. */
    ZMVideoSDKErrors_RAWDATA_VIRTUAL_MIC_IS_TERMINATE,
    
    
    /** Session sharing errors */
    /** General sharing error. */
    ZMVideoSDKErrors_Session_Share_Error = 7001,
    /** Share module not ready. */
    ZMVideoSDKErrors_Session_Share_Module_Not_Ready,
    /** You are not sharing. */
    ZMVideoSDKErrors_Session_Share_You_Are_Not_Sharing,
    /** Unsupported share type. */
    ZMVideoSDKErrors_Session_Share_Type_Is_Not_Support,
    /** Internal share error. */
    ZMVideoSDKErrors_Session_Share_Internal_Error,
    /** Multi-stream video not supported for user. */
    ZMVideoSDKErrors_Dont_Support_Multi_Stream_Video_User,
    /** Failed to assign user privilege. */
    ZMVideoSDKErrors_Fail_Assign_User_Privilege,
    /** No recording in progress. */
    ZMVideoSDKErrors_No_Recording_In_Process,
    /** Failed to set virtual background. */
    ZMVideoSDKErrors_Set_Virtual_Background_Fail,
    /** Camera video not started for share. */
    ZMVideoSDKErrors_Session_Share_Camera_Video_Not_Start,
    /** Camera conflicts with video effects. */
    ZMVideoSDKErrors_Session_Share_Camera_Conflict_With_Video_Effects,
    
    /** File transfer errors. */
    /** Unknown file transfer error. */
    ZMVideoSDKErrors_Filetransfer_UnknowError = 7500,
    /** File type is blocked. */
    ZMVideoSDKErrors_Filetransfer_FileTypeBlocked,
    /** File size exceeds limit. */
    ZMVideoSDKErrors_Filetransfer_FileSizelimited,
    
    /** Spotlight errors */
    /** Not enough users to spotlight. */
    ZMVideoSDKErrors_Spotlight_NotEnoughUsers = 7600,
    /** Too many spotlighted users. */
    ZMVideoSDKErrors_Spotlight_ToMuchSpotlightedUsers,
    /** User cannot be spotlighted. */
    ZMVideoSDKErrors_Spotlight_UserCannotBeSpotlighted,
    /** User has no video to spotlight. */
    ZMVideoSDKErrors_Spotlight_UserWithoutVideo,
    /** User is not spotlighted. */
    ZMVideoSDKErrors_Spotlight_UserNotSpotlighted
}ZMVideoSDKErrors;


/**
 * @brief Enumerates the status of sharing.
 */
typedef enum
{
    /** No view or screen share available. */
    ZMVideoSDKShareStatus_None,
    /** User started sharing. */
    ZMVideoSDKShareStatus_Start,
    /** User paused sharing. */
    ZMVideoSDKShareStatus_Pause,
    /** User resumed sharing. */
    ZMVideoSDKShareStatus_Resume,
    /** User stopped sharing. */
    ZMVideoSDKShareStatus_Stop
}ZMVideoSDKShareStatus;

/**
 * @brief Enumerates the statuses of live streaming.
 */
typedef enum
{
    /** The live stream status is none */
    ZMVideoSDKLiveStreamStatus_None,
    /** The live stream status is currently in progress */
    ZMVideoSDKLiveStreamStatus_InProgress,
    /** The live stream status is in the process of connecting */
    ZMVideoSDKLiveStreamStatus_Connecting,
    /** The live stream failed due to a timeout. */
    ZMVideoSDKLiveStreamStatus_FailedTimeout,
    /** The live stream failed to start. */
    ZMVideoSDKLiveStreamStatus_StartFailed,
    /** The live stream has ended. */
    ZMVideoSDKLiveStreamStatus_Ended
}ZMVideoSDKLiveStreamStatus;

/**
 * @brief Enumeration of raw data types.
 */
typedef enum
{
    /** Video raw data. */
    ZMVideoSDKRawDataType_Video = 0,
    /** Share raw data. */
    ZMVideoSDKRawDataType_Share
}ZMVideoSDKRawDataType;

/**
 * @brief Enumeration of render resolution.
 */
typedef enum
{
    /** The resolution is 90p. */
    ZMVideoSDKResolution_90P = 0,
    /** The resolution is 180p. */
    ZMVideoSDKResolution_180P,
    /** The resolution is 360p. */
    ZMVideoSDKResolution_360P,
    /** The resolution is 720p. Video resolution might be 1080p based on the user's network condition and device specs. */
    ZMVideoSDKResolution_720P,
    /** The resolution is 1080p. Video resolution might be 720p based on the user's network condition and device specs. */
    ZMVideoSDKResolution_1080P,
    /** The resolution is changed automatically according to the size of the view, only avaliable for video canvas. */
    ZMVideoSDKResolution_Auto = 100
}ZMVideoSDKResolution;

/**
 * @brief Enumeration of memory modes for raw data handling.
 */
typedef enum
{
    /** The memory mode is srack. */
    ZMVideoSDKRawDataMemoryMode_Stack,
    /** The memory mode is heap. */
    ZMVideoSDKRawDataMemoryMode_Heap
}ZMVideoSDKRawDataMemoryMode;

/**
 * @brief Enumeration the statuses of raw data.
 */
typedef enum
{
    /** The raw data status is on. */
    ZMVideoSDKRawData_On,
    /** The raw data status if off. */
    ZMVideoSDKRawData_Off
}ZMVideoSDKRawDataStatus;

/**
 * @brief Enumerates the types of audio.
 */
typedef enum {
    /** Audio type is VOIP (Voice over IP). */
    ZMVideoSDKAudioType_VOIP,
    /** Audio type is telephony. */
    ZMVideoSDKAudioType_TELEPHONY,
    /** No audio type. */
    ZMVideoSDKAudioType_None
}ZMVideoSDKAudioType;

/**
 * @brief Enumerates the video rotation angles.
 */
typedef enum
{
    /** Video rotation is 0 degrees. */
    ZMVideoRotation_0,
    /** Video rotation is 90 degrees. */
    ZMVideoRotation_90,
    /** Video rotation is 180 degrees. */
    ZMVideoRotation_180,
    /** Video rotation is 270 degrees. */
    ZMVideoRotation_270
}ZMVideoRotation;

/**
 * @brief Enumerates the video preference modes.
 */
typedef enum
{
    /** Balance mode. */
    ZMVideoSDKVideoPreferenceMode_Balance,
    /** Sharpness mode, prioritizing video clarity. */
    ZMVideoSDKVideoPreferenceMode_Sharpness,
    /** Smoothness mode, focusing on a smooth video experience. */
    ZMVideoSDKVideoPreferenceMode_Smoothness,
    /** Custom mode, allowing user-defined video preferences. */
    ZMVideoSDKVideoPreferenceMode_Custom
}ZMVideoSDKVideoPreferenceMode;


/**
 * @brief Enumerates the statuses of recording.
 */
typedef enum
{
    /** The recording has successfully started or successfully resumed. */
    ZMRecording_Start,
    /** The recording has stopped. */
    ZMRecording_Stop,
    /** Recording is unsuccessful due to insufficient storage space. Please try to free up storage space or purchase additional storage space. */
    ZMRecording_DiskFull,
    /** The recording has paused. */
    ZMRecording_Pause
}ZMRecordingStatus;


/**
 * @brief Enumerates the types of remote camera control requests.
 */
typedef enum
{
    /** Request remote camera control. */
    ZMVideoSDKCameraControlRequestType_RequestControl = 0,
    /** Give up remote camera control. */
    ZMVideoSDKCameraControlRequestType_GiveUpControl
}ZMVideoSDKCameraControlRequestType;


/**
 * @brief Enumerates the statuses of a phone call.
 */
typedef enum
{
    /** For initialization. */
    ZMPhoneStatus_None,
    /** In the process of calling out. */
    ZMPhoneStatus_Calling,
    /** In the process of ringing. */
    ZMPhoneStatus_Ringing,
    /** Call has been accepted. */
    ZMPhoneStatus_Accepted,
    /** Call was successful. */
    ZMPhoneStatus_Success,
    /** Call failed. */
    ZMPhoneStatus_Failed,
    /** In process of canceling the response to the previous state. */
    ZMPhoneStatus_Canceling,
    /** The call has been successfully canceled. */
    ZMPhoneStatus_Canceled,
    /** The attempt to cancel the call has failed. */
    ZMPhoneStatus_Cancel_Failed,
    /** The call attempt has timed out. */
    ZMPhoneStatus_Timeout
}ZMPhoneStatus;

/**
 * @brief Enumerates the various reasons for a phone call failure.
 */
typedef enum
{
    /** For initialization. */
    ZMPhoneFailedReason_None,
    /** The telephone number is currently busy. */
    ZMPhoneFailedReason_Busy,
    /** The telephone number is out of service. */
    ZMPhoneFailedReason_Not_Available,
    /** The user manually hung up the call. */
    ZMPhoneFailedReason_User_Hangup,
    /** Other reasons. */
    ZMPhoneFailedReason_Other_Fail,
    /** The user did not answer the call within the allowed time. */
    ZMPhoneFailedReason_No_Answer,
    /** The call invitation was blocked by the system due to an absent host. */
    ZMPhoneFailedReason_Block_No_Host,
    /** The call-out attempt was blocked by the system due to the high rates or cost. */
    ZMPhoneFailedReason_Block_High_Rate,
  
    /** To join the session, the invitee would press one on the phone.
    An invitee who fails to respond will encounter a timeout.
    If there are too many invitee timeouts, the call invitation feature for this session will be blocked. */
    ZMPhoneFailedReason_Block_Too_Frequent
}ZMPhoneFailedReason;


/**
 * @brief Enumeration of background noise suppression levels. For more information, please visit <https://support.zoom.com/hc/en/article?id=zm_kb&sysparm_article=KB0059985>.
 */
typedef enum
{
    /** Automatically adjust noise suppression. */
    ZMVideoSDKSuppressBackgroundNoiseLevel_Auto = 0,
    /** Low level suppression. Allows faint background. */
    ZMVideoSDKSuppressBackgroundNoiseLevel_Low,
    /** Medium level suppression. Filters out moderate noise like computer fan or desk taps. */
    ZMVideoSDKSuppressBackgroundNoiseLevel_Medium,
    /** High level suppression. Eliminates most background speech and persistent noise. */
    ZMVideoSDKSuppressBackgroundNoiseLevel_High
}ZMVideoSDKSuppressBackgroundNoiseLevel;

/**
 * @brief Enumeration of echo cancellation level. For more information, please visit <https://support.zoom.com/hc/en/article?id=zm_kb&sysparm_article=KB0066398>.
 */
typedef enum {
    /** Automatically adjust echo cancellation, balancing CPU and performance. */
    ZMVideoSDKEchoCancellationLevel_Default = 0,
    /** Better echo limitation, taking into account multiple people talking at the same time, low CPU utilization. */
    ZMVideoSDKEchoCancellationLevel_Aggressive
}ZMVideoSDKEchoCancellationLevel;


/**
 * @brief Enumerates the status of multi-camera streams.
 */
typedef enum{
    /** Current user only. Sent when the current user attempts to use multiple cameras in the session. */
    ZMVideoSDKMultiCameraStreamStatus_JoinStart,
    /** Current user only. Sent when the current user fails to use multiple cameras in the session. */
    ZMVideoSDKMultiCameraStreamStatus_JoinFail,
    /** Broadcast to all users. Sent when a new camera has been successfully added to the session as the multiple cameras. */
    ZMVideoSDKMultiCameraStreamStatus_Joined,
    /** Broadcast to all users. Sent after a camera that is being used as the multiple cameras leaves the session. */
    ZMVideoSDKMultiCameraStreamStatus_Left,
    /** Broadcast to all users. Sent when a multiple camera is started. */
    ZMVideoSDKMultiCameraStreamStatus_VideoOn,
    /** Broadcast to all users. Sent when a multiple camera is stopped. */
    ZMVideoSDKMultiCameraStreamStatus_VideoOff
}ZMVideoSDKMultiCameraStreamStatus;


/**
 * @brief Enumerates the microphone test statuses.
 */
typedef enum{
    /** The microphone is ready to start a test. */
    ZMVideoSDKMicTestStatus_CanTest = 0,
    /** The microphone is currently recording audio for the test. */
    ZMVideoSDKMicTestStatus_Recording,
    /** The recorded audio is ready for playback. */
    ZMVideoSDKMicTestStatus_CanPlay
}ZMVideoSDKMicTestStatus;


/**
 * @brief Enumerates the types of audio devices.
 */
typedef enum
{
    /** Represents a microphone device used for audio input. */
    ZMVideoSDKAudioDeviceType_Microphone = 0,
    /** Represents a speaker device used for audio output. */
    ZMVideoSDKAudioDeviceType_Speaker
}ZMVideoSDKAudioDeviceType;

/**
 * @brief Enumerates the statuses related to audio device state and availability.
 */
typedef enum {
    /** An unknown device error has occurred. */
    ZMVideoSDKAudioDeviceStatus_Device_Error_Unknow = 0,
    /** No audio device is currently available. */
    ZMVideoSDKAudioDeviceStatus_No_Device,
    /** The list of available audio devices has been updated. */
    ZMVideoSDKAudioDeviceStatus_Device_List_Update,
    /** No audio input is being detected from the current device. */
    ZMVideoSDKAudioDeviceStatus_Audio_No_Input,
    /** Audio was disconnected automatically due to detected echo. */
    ZMVideoSDKAudioDeviceStatus_Audio_Disconnect_As_Detected_Echo
}ZMVideoSDKAudioDeviceStatus;


/**
 * @brief Enumerates the types of content that can be shared in a session.
 */
typedef enum
{
    ZMVideoSDKShareType_None,
    /** Application or desktop share. */
    ZMVideoSDKShareType_Normal,
    /** Pure computer audio share. */
    ZMVideoSDKShareType_PureAudio,
    /** Camera share. */
    ZMVideoSDKShareType_Camera
}ZMVideoSDKShareType;


/**
 * @brief Enumerates the data modes for video source frames.
 */
typedef enum
{
    /** Default mode for general use cases (single image per frame). */
    ZMVideoSDKVideoSourceDataMode_None = 0,
    /** Special mode where each video frame consists of two horizontally arranged images. */
    ZMVideoSDKVideoSourceDataMode_Horizontal,
    /** Special mode where each video frame consists of two vertically stacked images. */
    ZMVideoSDKVideoSourceDataMode_Vertical
}ZMVideoSDKVideoSourceDataMode;

/**
 * @brief Enumerates the status of live transcription.
 */
typedef enum
{
    /** Live transcription is currently stopped. */
    ZMVideoSDKLiveTranscription_Status_Stop = 0,
    /** Live transcription is currently active. */
    ZMVideoSDKLiveTranscription_Status_Start = 1
}ZMVideoSDKLiveTranscriptionStatus;

/**
 * @brief Enumerates the types of operations related to live transcription.
 */
typedef enum
{
    /** No operation specified. */
    ZMVideoSDKLiveTranscription_OperationType_None = 0,
    /** Live transcription operation type is added. */
    ZMVideoSDKLiveTranscription_OperationType_Add,
    /** Live transcription operation type is updated. */
    ZMVideoSDKLiveTranscription_OperationType_Update,
    /** Live transcription operation type is deleted. */
    ZMVideoSDKLiveTranscription_OperationType_Delete,
    /** Live transcription operation type is marked as complete. */
    ZMVideoSDKLiveTranscription_OperationType_Complete,
    /** Live transcription operation type is not supported. */
    ZMVideoSDKLiveTranscription_OperationType_NotSupported
}ZMVideoSDKLiveTranscriptionOperationType;

/**
 * @brief The chat message delete type are sent in the ZMVideoSDKDelegate#onChatMsgDeleteNotification callback.
 */
typedef enum
{
    /** For initialization. */
    ZMVideoSDKChatMessageDeleteType_None = 0,
    /** Message is deleted by the sender (self deletion). */
    ZMVideoSDKChatMessageDeleteType_BySelf,
    /** Message is deleted by the session host. */
    ZMVideoSDKChatMessageDeleteType_ByHost,
    /** Message is deleted by Data Loss Prevention (DLP) system for violating compliance policies. */
    ZMVideoSDKChatMessageDeleteType_ByDlp
}ZMVideoSDKChatMessageDeleteType;

/**
 * @brief Enumerates the types of virtual backgrounds.
 */
typedef enum
{
    /** No virtual background is applied. */
    ZMVideoSDKVirtualBackgroundDataType_None,
    /** An image is used as the virtual background. */
    ZMVideoSDKVirtualBackgroundDataType_Image,
    /** A blur effect is applied to the background. */
    ZMVideoSDKVirtualBackgroundDataType_Blur
}ZMVideoSDKVirtualBackgroundDataType;

/**
 * @brief Enumeration of the number types for calling to join the audio into a meeting.
 */
typedef enum
{
    /** For initialization. */
    ZMVideoSDKDialInNumType_None,
    /** Paid (toll) number. */
    ZMVideoSDKDialInNumType_Toll,
    /** Toll-free number. */
    ZMVideoSDKDialInNumType_TollFree
}ZMVideoSDKDialInNumType;

/**
 * @brief Enumerates the network statuses.
 */
typedef enum
{
    /** For initialization. */
    ZMVideoSDKNetworkStatus_None,
    /** The network connection is poor, affecting video quality. */
    ZMVideoSDKNetworkStatus_Bad,
    /** The network connection is stable with typical performance. */
    ZMVideoSDKNetworkStatus_Normal,
    /** The network connection is strong and stable, providing optimal performance. */
    ZMVideoSDKNetworkStatus_Good
}ZMVideoSDKNetworkStatus;


/**
 * @brief Enumerates the types of consent for cloud recording.
 */
typedef enum
{
    /** Invalid type. */
    ZMVideoSDKConsentType_Invalid,
    /** In this case, 'accept' means agree to be recorded to gallery and speaker mode, 'decline' means leave session. */
    ZMVideoSDKConsentType_Traditional,
    /** In this case, 'accept' means agree to be recorded to a separate file, 'decline' means stay in session and can't be recorded. */
    ZMVideoSDKConsentType_Individual
}ZMVideoSDKConsentType;


/**
 * @brief Enumeration of the mode for screen capture. For more information, please visit <https://support.zoom.com/hc/en/article?id=zm_kb&sysparm_article=KB0063824>.
 */
typedef enum
{
    /** Automatically choose the best method to use for screen share. */
    ZMVideoSDKScreenCaptureMode_Auto,
    /** This mode can be applicable if you are not on the latest operating systems, or don't have certain video drivers. If this option isn't enabled, a blank screen may appear on participants' screens while the host shares their screen. */
    ZMVideoSDKScreenCaptureMode_Legacy,
    /** This mode will share your screen without showing windows from the app. */
    ZMVideoSDKScreenCaptureMode_Filtering,
    /** This mode will share your screen, include motion detection (when you move a window or play a movie), and will not show windows from the app. */
    ZMVideoSDKScreenCaptureMode_ADA_Filtering,
    /** This mode will share your screen, include motion detection (when you move a window or play a movie), and will show windows from the app. */
    ZMVideoSDKScreenCaptureMode_ADA_Without_Filtering
}ZMVideoSDKScreenCaptureMode;


/**
 * @brief Enumeration of the video aspect ratio.
 */
typedef enum
{
    /** Display the captured data without any cropping or scaling. */
    ZMVideoSDKVideoAspect_Original,
    /** Stretch both horizontally and vertically to fill the display (may cause distortion). */
    ZMVideoSDKVideoAspect_Full_Filled,
    /** Add black bars to maintain aspect ratio (e.g., 16:9 content on a 4:3 display or vice versa). */
    ZMVideoSDKVideoAspect_LetterBox,
    /** Crop the sides or top/bottom to fill the screen (e.g., cut sides for 16:9 on 4:3, or top/bottom for 4:3 on 16:9). */
    ZMVideoSDKVideoAspect_PanAndScan,
}ZMVideoSDKVideoAspect;

/**
 * @brief Enumeration of the zoom render type.
 */
typedef enum
{
    /** Video Camera data. This type represents video data captured from the camera. */
    ZMVideoSDKCanvasType_VideoData = 1,
    /** Share data. */
    ZMVideoSDKCanvasType_ShareData,
}ZMVideoSDKCanvasType;

/**
 * @brief Enumeration of raw data formats. Defines the color space format and color range for video frames.
 */
typedef enum
{
    /** I420 format with Limited color range. */
    ZMVideoSDKFrameDataFormat_I420_Limited,
    /** I420 format with Full color range. */
    ZMVideoSDKFrameDataFormat_I420_Full,
}ZMVideoSDKFrameDataFormat;

/**
 * @brief Enumerates the types of Call CRC (Circuit-Reliable Communication).
 */
typedef enum
{
   /** H.323 type. */
    ZMVideoSDKCRCProtocol_H323,
   /** SIP type. */
    ZMVideoSDKCRCProtocol_SIP
}ZMVideoSDKCRCProtocol;

/**
 * @brief Enumerates the statuses of a CRC call.
 */
typedef enum
{
    /** The call was successfully established. */
    ZMVideoSDKCRCCallStatus_Success = 0,
    /** The call is ringing (waiting to be answered). */
    ZMVideoSDKCRCCallStatus_Ring,
    /** The call has timed out. */
    ZMVideoSDKCRCCallStatus_Timeout,
    /** The line is busy. */
    ZMVideoSDKCRCCallStatus_Busy,
    /** The call was declined by the recipient. */
    ZMVideoSDKCRCCallStatus_Decline,
    /** The call failed. */
    ZMVideoSDKCRCCallStatus_Failed
}ZMVideoSDKCRCCallStatus;

/**
 * @brief Enumerates the reasons for a failed video subscription attempt.
 */
typedef enum{
    /** No subscription failure (initial state). */
    ZMVideoSDKSubscribeFailReason_None = 0,
    /** The subscription attempt failed because has already subscribed to a 1080P or 720P video stream. */
    ZMVideoSDKSubscribeFailReason_HasSubscribe1080POr720P,
    /** The subscription attempt failed because has already subscribed to two 720P video streams. */
    ZMVideoSDKSubscribeFailReason_HasSubscribeTwo720P,
    /** The subscription attempt failed because has exceeded the maximum allowed subscription limit. */
    ZMVideoSDKSubscribeFailReason_HasSubscribeExceededLimit,
    /** The subscription attempt failed because has already subscribed to two shared video streams. */
    ZMVideoSDKSubscribeFailReason_HasSubscribeTwoShare,
    /** The subscription attempt failed because has already subscribed to one 1080P or 720P video stream and one shared video stream. */
    ZMVideoSDKSubscribeFailReason_HasSubscribeVideo1080POr720PAndOneShare,
    /** The subscription attempt failed because subscription requests were made too frequently in a short period of time. */
    ZMVideoSDKSubscribeFailReason_TooFrequentCall
} ZMVideoSDKSubscribeFailReason;

/**
 * @brief Enumerates the types of chat privileges.
 */
typedef enum{
    /** Unknown. */
    ZMVideoSDKChatPrivilegeType_Unknown = 0,
    /** The user has the privilege to chat both publicly and privately. */
    ZMVideoSDKChatPrivilegeType_Publicly_And_Privately,
    /** The user has no chat privileges. */
    ZMVideoSDKChatPrivilegeType_No_One,
    /** The user has the privilege to chat publicly only. */
    ZMVideoSDKChatPrivilegeType_Publicly,
} ZMVideoSDKChatPrivilegeType;

/**
 * @brief Enumeration of the type for annotation tool. For more information, please visit <https://support.zoom.com/hc/en/article?id=zm_kb&sysparm_article=KB0067931>.
 */
typedef enum{
    /** Switch to mouse cursor. For initialization. */
    ZMVideoSDKAnnotationToolType_None,
    /** Pen */
    ZMVideoSDKAnnotationToolType_Pen,
    /** Highlighter. */
    ZMVideoSDKAnnotationToolType_HighLighter,
    /** A straight line changes automatically in pace with the mouse cursor. */
    ZMVideoSDKAnnotationToolType_AutoLine,
    /** A rectangle changes automatically in pace with the mouse cursor. */
    ZMVideoSDKAnnotationToolType_AutoRectangle,
    /** An ellipse changes automatically in pace with the mouse cursor. */
    ZMVideoSDKAnnotationToolType_AutoEllipse,
    /** An arrow changes automatically in pace with the mouse cursor. */
    ZMVideoSDKAnnotationToolType_AutoArrow,
    /** A filled rectangle. */
    ZMVideoSDKAnnotationToolType_AutoRectangleFill,
    /** A filled ellipse. */
    ZMVideoSDKAnnotationToolType_AutoEllipseFill,
    /** Only available if you started the shared screen or whiteboard. Displays your mouse pointer to all participants when your mouse is within the area being shared. Use this to point out parts of the screen to other participants. */
    ZMVideoSDKAnnotationToolType_SpotLight,
    /** Displays a small arrow instead of your mouse pointer. Each subsequent click will remove the previous arrow placed. */
    ZMVideoSDKAnnotationToolType_Arrow,
    /** Erase parts of your annotation. */
    ZMVideoSDKAnnotationToolType_ERASER,
    /** Insert a textbox to input letters. */
    ZMVideoSDKAnnotationToolType_Textbox,
    /** Only available if you started the shared screen or whiteboard. Select , move, or resize your annotations. */
    ZMVideoSDKAnnotationToolType_Picker,
    /** A fair rectangle changes automatically in pace with the mouse cursor. */
    ZMVideoSDKAnnotationToolType_AutoRectangleSemiFill,
    /** A fair ellipse changes automatically in pace with the mouse cursor. */
    ZMVideoSDKAnnotationToolType_AutoEllipseSemiFill,
    /** A line with a double-arrow. */
    ZMVideoSDKAnnotationToolType_AutoDoubleArrow,
    /** An unfilled rhombus. */
    ZMVideoSDKAnnotationToolType_AutoDiamond,
    /** A fixed-size arrow for marking. */
    ZMVideoSDKAnnotationToolType_AutoStampArrow,
    /** A sign marking that something is correct. */
    ZMVideoSDKAnnotationToolType_AutoStampCheck,
    /** A sign marking that something is incorrect. */
    ZMVideoSDKAnnotationToolType_AutoStampX,
    /** A star for marking. */
    ZMVideoSDKAnnotationToolType_AutoStampStar,
    /** A heart for marking. */
    ZMVideoSDKAnnotationToolType_AutoStampHeart,
    /** A sign for interrogation. */
    ZMVideoSDKAnnotationToolType_AutoStampQm
}ZMVideoSDKAnnotationToolType;

/**
 * @brief Enumeration of the type for clear annotation.
 */
typedef enum{
    /** Clear all annotations. Hosts, managers and shared meeting owners can use. */
    ZMVideoSDKAnnotationClearType_All,
    /** Clear only the others' annotations. Only shared meeting owners can use. */
    ZMVideoSDKAnnotationClearType_Others,
    /** Clear only your own annotations. Everyone can use. */
    ZMVideoSDKAnnotationClearType_My
}ZMVideoSDKAnnotationClearType;


/**
 * @brief Enumeration of file transfer status.
 */
typedef enum
{
    /** The file transfer has no state. */
    ZMVideoSDKFileTransferStatus_None = 0,
    /** The file transfer is ready to start. */
    ZMVideoSDKFileTransferStatus_ReadyToTransfer,
    /** The file transfer is in progress. */
    ZMVideoSDKFileTransferStatus_Transfering,
    /** The file transfer failed. */
    ZMVideoSDKFileTransferStatus_TransferFailed,
    /** The file transfer completed successfully. */
    ZMVideoSDKFileTransferStatus_TransferDone
}ZMVideoSDKFileTransferStatus;

/**
 * @brief Enumeration of audio channel types.
 */
typedef enum
{
    /** Mono audio channel. */
    ZMVideoSDKAudioChannel_Mono = 0,
    /** Stereo audio channel. */
    ZMVideoSDKAudioChannel_Stereo
}ZMVideoSDKAudioChannel;

/**
 * @brief Enumerates the possible reasons for leaving a session.
 */
typedef enum
{
    /** Unknown */
    ZMVideoSDKSessionLeaveReason_Unknown = 0,
    /** Leave session by self. */
    ZMVideoSDKSessionLeaveReason_BySelf,
    /** Kicked by host. */
    ZMVideoSDKSessionLeaveReason_KickByHost,
    /** Ended by host. */
    ZMVideoSDKSessionLeaveReason_EndByHost,
    /** Network is broken. */
    ZMVideoSDKSessionLeaveReason_NetworkError
}ZMVideoSDKSessionLeaveReason;

/**
 * @brief Enumerates the statuses for remote control.
 */
typedef enum
{
    /** For initialization. */
    ZMVideoSDKRemoteControlStatus_None = 0,
    /** Remote control information. I can enable the remote control. */
    ZMVideoSDKRemoteControlStatus_CanRequestControl,
    /** Remote control information. I have received a refused information of remote control. */
    ZMVideoSDKRemoteControlStatus_RequestDenied,
    /** The authority of remote control. I get control when remote control begins. */
    ZMVideoSDKRemoteControlStatus_GotControl,
    /** The authority of remote control. I lose control when remote control ends. */
    ZMVideoSDKRemoteControlStatus_LostControl,
    /** The status of remote control. I am remotely controlling another. */
    ZMVideoSDKRemoteControlStatus_ControlStart,
    /** The status of remote control. I am not remotely controlling another. */
    ZMVideoSDKRemoteControlStatus_ControlStop,
    /** The status of remote control. I can be controlled by the specified user. */
    ZMVideoSDKRemoteControlStatus_GiveControlTo,
    /** The status of remote control. I have revoked remote control. */
    ZMVideoSDKRemoteControlStatus_ControlRevoked,
    /** The status of remote control. I am being controlled by the specified user. */
    ZMVideoSDKRemoteControlStatus_ControlledBy,
    /** The status of remote control. I am not being controlled. */
    ZMVideoSDKRemoteControlStatus_NotControlled
}ZMVideoSDKRemoteControlStatus;

/**
 * @brief Enumeration of subsession statuses.
 */
typedef enum
{
    /** The Initialized status. */
    ZMVideoSDKSubSessionStatus_None,
    /** When a subsession is committed. */
    ZMVideoSDKSubSessionStatus_Committed,
    /** When a subsession is withdrawn. */
    ZMVideoSDKSubSessionStatus_Withdrawn,
    /** When the subsession is started. */
    ZMVideoSDKSubSessionStatus_Started,
    /** When the subsession is stopping. */
    ZMVideoSDKSubSessionStatus_Stopping,
    /** When the subsession is stopped. */
    ZMVideoSDKSubSessionStatus_Stopped,
    /** When commit subsession failed. */
    ZMVideoSDKSubSessionStatus_CommitFailed,
    /** When withdraw subsession failed. */
    ZMVideoSDKSubSessionStatus_WithdrawFailed,
    /** When start subsession failed. */
    ZMVideoSDKSubSessionStatus_StartFailed,
    /** When stop subsession failed. */
    ZMVideoSDKSubSessionStatus_StopFailed
}ZMVideoSDKSubSessionStatus;

/**
 * @brief Enumeration of session type.
 */
typedef enum
{
    /** The session type is main session. */
    ZMVideoSDKSessionType_MainSession = 0,
    /** The session type is subsession. */
    ZMVideoSDKSessionType_SubSession
}ZMVideoSDKSessionType;

/**
 * @brief Enumeration of subsession user help request results.
 */
typedef enum
{
    /** The host has received the help request, and no one else is currently requesting help. */
    ZMVideoSDKUserHelpRequestResult_Idle,
    /** The host is handling another user's request with the request dialog. */
    ZMVideoSDKUserHelpRequestResult_Busy,
    /** The host is handling another user's request. */
    ZMVideoSDKUserHelpRequestResult_Ignore,
    /** The host is already in this subsession. */
    ZMVideoSDKUserHelpRequestResult_HostAlreadyInSubSession
}ZMVideoSDKUserHelpRequestResult;

/**
 * @brief Enumeration of share preprocess types.
 */
typedef enum
{
    /** For initialization. */
    ZMVideoSDKSharePreprocessType_None = 0,
    /** For share screen(monitor). */
    ZMVideoSDKSharePreprocessType_Screen,
    /** For share view(application window). */
    ZMVideoSDKSharePreprocessType_View
}ZMVideoSDKSharePreprocessType;
