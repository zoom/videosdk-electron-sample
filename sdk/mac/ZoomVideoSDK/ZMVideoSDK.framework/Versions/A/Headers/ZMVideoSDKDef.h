
typedef enum
{
    ZMVideoSDKErrors_Success = 0,///<Success.
    ZMVideoSDKErrors_Wrong_Usage,
    ZMVideoSDKErrors_Internal_Error,
    ZMVideoSDKErrors_Uninitialize,
    ZMVideoSDKErrors_Memory_Error,
    ZMVideoSDKErrors_Load_Module_Error,
    ZMVideoSDKErrors_UnLoad_Module_Error,
    ZMVideoSDKErrors_Invalid_Parameter,
    ZMVideoSDKErrors_Call_Too_Frequently,
    ZMVideoSDKErrors_No_Impl,
    ZMVideoSDKErrors_Dont_Support_Feature,
    ZMVideoSDKErrors_Unknown,
    ZMVideoSDKErrors_Remove_Folder_Fail,
    ZMVideoSDKErrors_Auth_Error = 1001,
    ZMVideoSDKErrors_Auth_Empty_Key_or_Secret,
    ZMVideoSDKErrors_Auth_Wrong_Key_or_Secret,
    ZMVideoSDKErrors_Auth_DoesNot_Support_SDK,
    ZMVideoSDKErrors_Auth_Disable_SDK,
    ZMVideoSDKErrors_JoinSession_NoSessionName = 1500,
    ZMVideoSDKErrors_JoinSession_NoSessionToken,
    ZMVideoSDKErrors_JoinSession_NoUserName,
    ZMVideoSDKErrors_JoinSession_Invalid_SessionName,
    ZMVideoSDKErrors_JoinSession_Invalid_Password,
    ZMVideoSDKErrors_JoinSession_Invalid_SessionToken,
    ZMVideoSDKErrors_JoinSession_SessionName_TooLong,
    ZMVideoSDKErrors_JoinSession_Token_MismatchedSessionName,
    ZMVideoSDKErrors_JoinSession_Token_NoSessionName,
    ZMVideoSDKErrors_JoinSession_Token_RoleType_EmptyOrWrong,
    ZMVideoSDKErrors_JoinSession_Token_UserIdentity_TooLong,
    ZMVideoSDKErrors_SessionModule_Not_Found = 2001,
    ZMVideoSDKErrors_SessionService_Invalid,
    ZMVideoSDKErrors_Session_Join_Failed,
    ZMVideoSDKErrors_Session_No_Rights,
    ZMVideoSDKErrors_Session_Already_In_Progress,
    ZMVideoSDKErrors_Session_Dont_Support_SessionType,
    ZMVideoSDKErrors_Session_Reconnecting,
    ZMVideoSDKErrors_Session_Disconnecting,
    ZMVideoSDKErrors_Session_Not_Started,
    ZMVideoSDKErrors_Session_Need_Password,
    ZMVideoSDKErrors_Session_Password_Wrong,
    ZMVideoSDKErrors_Session_Remote_DB_Error,
    ZMVideoSDKErrors_Session_Invalid_Param,
    ZMVideoSDKErrors_Session_Client_Incompatible,
    ZMVideoSDKErrors_Session_Account_FreeMinutesExceeded,
    ZMVideoSDKErrors_Session_Audio_Error = 3000,
    ZMVideoSDKErrors_Session_Audio_No_Microphone,
    ZMVideoSDKErrors_Session_Audio_No_Speaker,
    ZMVideoSDKErrors_Session_Video_Error = 4000,
    ZMVideoSDKErrors_Session_Video_Device_Error,
    ZMVideoSDKErrors_Session_Live_Stream_Error = 5000,
    ZMVideoSDKErrors_Session_Phone_Error = 5500,
    
    ZMVideoSDKErrors_RAWDATA_MALLOC_FAILED = 6001,
    ZMVideoSDKErrors_RAWDATA_NOT_IN_Session,
    ZMVideoSDKErrors_RAWDATA_NO_LICENSE,
    ZMVideoSDKErrors_RAWDATA_VIDEO_MODULE_NOT_READY,
    ZMVideoSDKErrors_RAWDATA_VIDEO_MODULE_ERROR,
    ZMVideoSDKErrors_RAWDATA_VIDEO_DEVICE_ERROR,
    ZMVideoSDKErrors_RAWDATA_NO_VIDEO_DATA,
    ZMVideoSDKErrors_RAWDATA_SHARE_MODULE_NOT_READY,
    ZMVideoSDKErrors_RAWDATA_SHARE_MODULE_ERROR,
    ZMVideoSDKErrors_RAWDATA_NO_SHARE_DATA,
    ZMVideoSDKErrors_RAWDATA_AUDIO_MODULE_NOT_READY,
    ZMVideoSDKErrors_RAWDATA_AUDIO_MODULE_ERROR,
    ZMVideoSDKErrors_RAWDATA_NO_AUDIO_DATA,
    ZMVideoSDKErrors_RAWDATA_PREPROCESS_RAWDATA_ERROR,
    ZMVideoSDKErrors_RAWDATA_NO_DEVICE_RUNNING,
    
    ZMVideoSDKErrors_RAWDATA_INIT_DEVICE,
    ZMVideoSDKErrors_RAWDATA_VIRTUAL_DEVICE,
    ZMVideoSDKErrors_RAWDATA_CANNOT_CHANGE_VIRTUAL_DEVICE_IN_PREVIEW,
    ZMVideoSDKErrors_RAWDATA_INTERNAL_ERROR,
    ZMVideoSDKErrors_RAWDATA_SEND_TOO_MUCH_DATA_IN_SINGLE_TIME,
    ZMVideoSDKErrors_RAWDATA_SEND_TOO_FREQUENTLY,
    ZMVideoSDKErrors_RAWDATA_VIRTUAL_MIC_IS_TERMINATE,
    
    ZMVideoSDKErrors_Session_Share_Error = 7001,
    ZMVideoSDKErrors_Session_Share_Module_Not_Ready,
    ZMVideoSDKErrors_Session_Share_You_Are_Not_Sharing,
    ZMVideoSDKErrors_Session_Share_Type_Is_Not_Support,
    ZMVideoSDKErrors_Session_Share_Internal_Error,
    ZMVideoSDKErrors_Dont_Support_Multi_Stream_Video_User,
    ZMVideoSDKErrors_Fail_Assign_User_Privilege,
    ZMVideoSDKErrors_No_Recording_In_Process,
    ZMVideoSDKErrors_Set_Virtual_Background_Fail,
    ZMVideoSDKErrors_Filetransfer_UnknowError = 7500,
    ZMVideoSDKErrors_Filetransfer_FileTypeBlocked,
    ZMVideoSDKErrors_Filetransfer_FileSizelimited,
    ZMVideoSDKErrors_Spotlight_NotEnoughUsers = 7600,
    ZMVideoSDKErrors_Spotlight_ToMuchSpotlightedUsers,
    ZMVideoSDKErrors_Spotlight_UserCannotBeSpotlighted,
    ZMVideoSDKErrors_Spotlight_UserWithoutVideo,
    ZMVideoSDKErrors_Spotlight_UserNotSpotlighted
}ZMVideoSDKErrors;

typedef enum
{
    //No view or screen share available.
    ZMVideoSDKShareStatus_None,
    //User started sharing.
    ZMVideoSDKShareStatus_Start,
    //User paused sharing.
    ZMVideoSDKShareStatus_Pause,
    //User resumed sharing.
    ZMVideoSDKShareStatus_Resume,
    //User stopped sharing.
    ZMVideoSDKShareStatus_Stop,
}ZMVideoSDKShareStatus;

typedef enum
{
    //The live stream status is none.
    ZMVideoSDKLiveStreamStatus_None,
    //The live stream status is in progress.
    ZMVideoSDKLiveStreamStatus_InProgress,
    //The live stream status is connecting.
    ZMVideoSDKLiveStreamStatus_Connecting,
    //The live stream status is failed.
    ZMVideoSDKLiveStreamStatus_FailedTimeout,
    //The live stream status is start failed.
    ZMVideoSDKLiveStreamStatus_StartFailed,
    //The live stream status is end.
    ZMVideoSDKLiveStreamStatus_Ended,
}ZMVideoSDKLiveStreamStatus;

typedef enum
{
    //Raw data type is video.
    ZMVideoSDKRawDataType_Video = 0,
    //Raw data type is share.
    ZMVideoSDKRawDataType_Share,
}ZMVideoSDKRawDataType;

typedef enum
{
    //The resolution is 90p.
    ZMVideoSDKResolution_90P = 0,
    //The resolution is 180p.
    ZMVideoSDKResolution_180P,
    //The resolution is 360p.
    ZMVideoSDKResolution_360P,
    //The resolution is 720p. Video resolution might be 1080p based on the user's network condition and device specs.
    ZMVideoSDKResolution_720P,
    //The resolution is 1080p. Video resolution might be 720p based on the user's network condition and device specs.
    ZMVideoSDKResolution_1080P,
    //The resolution is changed automatically according to the size of the view, only avaliable for video canvas.
    ZMVideoSDKResolution_Auto = 100,
}ZMVideoSDKResolution;

typedef enum
{
    //The memory mode is srack.
    ZMVideoSDKRawDataMemoryMode_Stack,
    //The memory mode is heap.
    ZMVideoSDKRawDataMemoryMode_Heap,
}ZMVideoSDKRawDataMemoryMode;

typedef enum
{
    //The raw data status is on.
    ZMVideoSDKRawData_On,
    //The raw data status if off.
    ZMVideoSDKRawData_Off,
}ZMVideoSDKRawDataStatus;

//Audio type
typedef enum {
    //Audio type is voip.
    ZMVideoSDKAudioType_VOIP,
    //Audio type is telephony.
    ZMVideoSDKAudioType_TELEPHONY,
    //Audio type is none.
    ZMVideoSDKAudioType_None,
}ZMVideoSDKAudioType;

//Video Rotation
typedef enum
{
    //Video rotation is 0.
    ZMVideoRotation_0,
    //Video rotation is 90.
    ZMVideoRotation_90,
    //Video rotation is 180.
    ZMVideoRotation_180,
    //Video rotation is 270.
    ZMVideoRotation_270,
}ZMVideoRotation;

typedef enum
{
    //Balance mode.
    ZMVideoSDKVideoPreferenceMode_Balance,
    //Sharpness mode.
    ZMVideoSDKVideoPreferenceMode_Sharpness,
    //Smoothness mode.
    ZMVideoSDKVideoPreferenceMode_Smoothness,
    //Custom mode.
    ZMVideoSDKVideoPreferenceMode_Custom,
}ZMVideoSDKVideoPreferenceMode;

typedef enum
{
    //The recording has successfully started or successfully resumed.
    ZMRecording_Start,
    //The recording has stopped.
    ZMRecording_Stop,
    //Recording is unsuccessful due to insufficient storage space. Please try to free up storage space or purchase additional storage space.
    ZMRecording_DiskFull,
    //The recording has paused.
    ZMRecording_Pause,
}ZMRecordingStatus;

typedef enum
{
    //Request remote camera control.
    ZMVideoSDKCameraControlRequestType_RequestControl = 0,
    //Give up remote camera control.
    ZMVideoSDKCameraControlRequestType_GiveUpControl,
}ZMVideoSDKCameraControlRequestType;

typedef enum
{
    //For initialize.
    ZMPhoneStatus_None,
    //In process of calling out.
    ZMPhoneStatus_Calling,
    //In process of ringing.
    ZMPhoneStatus_Ringing,
    //Accept the call.
    ZMPhoneStatus_Accepted,
    //Call successful.
    ZMPhoneStatus_Success,
    //Call failed.
    ZMPhoneStatus_Failed,
    //In process of canceling the response to the previous state.
    ZMPhoneStatus_Canceling,
    //Cancel successfully.
    ZMPhoneStatus_Canceled,
    //Cancel failed.
    ZMPhoneStatus_Cancel_Failed,
    //Timeout.
    ZMPhoneStatus_Timeout,
}ZMPhoneStatus;

typedef enum
{
    //For initialization.
    ZMPhoneFailedReason_None,
    //The telephone number is busy.
    ZMPhoneFailedReason_Busy,
    //The telephone number is out of service.
    ZMPhoneFailedReason_Not_Available,
    //The user hangs up.
    ZMPhoneFailedReason_User_Hangup,
    //Other reasons.
    ZMPhoneFailedReason_Other_Fail,
    //The user did not answer the call.
    ZMPhoneFailedReason_No_Answer,
    //The invitation by phone is blocked by the system due to an absent host.
    ZMPhoneFailedReason_Block_No_Host,
    //The call-out is blocked by the system due to the high cost.
    ZMPhoneFailedReason_Block_High_Rate,
  
    // To join the session, the invitee would press one on the phone.
    // An invitee who fails to respond will encounter a timeout.
    // If there are too many invitee timeouts, the call invitation feature for this session will be blocked.
    ZMPhoneFailedReason_Block_Too_Frequent, 
}ZMPhoneFailedReason;

typedef enum
{
    ZMVideoSDKSuppressBackgroundNoiseLevel_Auto = 0,
    ZMVideoSDKSuppressBackgroundNoiseLevel_Low,
    ZMVideoSDKSuppressBackgroundNoiseLevel_Medium,
    ZMVideoSDKSuppressBackgroundNoiseLevel_High,
}ZMVideoSDKSuppressBackgroundNoiseLevel;

typedef enum {
    ZMVideoSDKEchoCancellationLevel_Default = 0,
    ZMVideoSDKEchoCancellationLevel_Aggressive,
}ZMVideoSDKEchoCancellationLevel;


typedef enum{
    //Current user only. Sent when the current user attempts to use multiple cameras in the session.
    ZMVideoSDKMultiCameraStreamStatus_JoinStart,
    //Current user only. Sent when the current user fails to use multiple cameras in the session.
    ZMVideoSDKMultiCameraStreamStatus_JoinFail,
    //Broadcast to all users. Sent when a new camera has been successfully added to the session as the multiple cameras.
    ZMVideoSDKMultiCameraStreamStatus_Joined,
    //Broadcast to all users. Sent after a camera that is being used as the multiple cameras leaves the session.
    ZMVideoSDKMultiCameraStreamStatus_Left,
    //Broadcast to all users. Sent when a multiple camera is started.
    ZMVideoSDKMultiCameraStreamStatus_VideoOn,
    //Broadcast to all users. Sent when a multiple camera is stopped.
    ZMVideoSDKMultiCameraStreamStatus_VideoOff,
}ZMVideoSDKMultiCameraStreamStatus;

typedef enum{
    //Microphone status is can start test.
    ZMVideoSDKMicTestStatus_CanTest = 0,
    //Microphone status is recording.
    ZMVideoSDKMicTestStatus_Recording,
    //Microphone status is can be played.
    ZMVideoSDKMicTestStatus_CanPlay,
}ZMVideoSDKMicTestStatus;

typedef enum
{
    ZMVideoSDKAudioDeviceType_Microphone = 0,
    ZMVideoSDKAudioDeviceType_Speaker,
}ZMVideoSDKAudioDeviceType;

typedef enum {
    ZMVideoSDKAudioDeviceStatus_Device_Error_Unknow = 0,
    ZMVideoSDKAudioDeviceStatus_No_Device,
    ZMVideoSDKAudioDeviceStatus_Device_List_Update,
    ZMVideoSDKAudioDeviceStatus_Audio_No_Input,
    ZMVideoSDKAudioDeviceStatus_Audio_Disconnect_As_Detected_Echo,
}ZMVideoSDKAudioDeviceStatus;

typedef enum
{
    ZMVideoSDKShareType_None,
    //Application or desktop share.
    ZMVideoSDKShareType_Normal,
    //Pure computer audio share.
    ZMVideoSDKShareType_PureAudio,
}ZMVideoSDKShareType;

typedef enum
{
    //For general usage scenarios.
    ZMVideoSDKVideoSourceDataMode_None = 0,
    //Special usage scenarios, each frame of video is organized around two images.
    ZMVideoSDKVideoSourceDataMode_Horizontal,
    //Special usage scenarios, each frame of video is two images organized up and down together.
    ZMVideoSDKVideoSourceDataMode_Vertical
}ZMVideoSDKVideoSourceDataMode;

/**
 * @brief Enumerations of the type for live transcription status.
 */
typedef enum
{
    //Live transcription status is stop.
    ZMVideoSDKLiveTranscription_Status_Stop = 0,
    //Live transcription status is start.
    ZMVideoSDKLiveTranscription_Status_Start = 1,
}ZMVideoSDKLiveTranscriptionStatus;

/**
 * @brief Enumerations of the type for live transcription operation type.
 */
typedef enum
{
    //Live transcription operation type is none.
    ZMVideoSDKLiveTranscription_OperationType_None = 0,
    //Live transcription operation type is add.
    ZMVideoSDKLiveTranscription_OperationType_Add,
    //Live transcription operation type is update.
    ZMVideoSDKLiveTranscription_OperationType_Update,
    //Live transcription operation type is delete.
    ZMVideoSDKLiveTranscription_OperationType_Delete,
    //Live transcription operation type is complete.
    ZMVideoSDKLiveTranscription_OperationType_Complete,
    //Live transcription operation type is not support.
    ZMVideoSDKLiveTranscription_OperationType_NotSupported,
}ZMVideoSDKLiveTranscriptionOperationType;

/**
 * @brief The chat message delete type are sent in the ZMVideoSDKDelegate#onChatMsgDeleteNotification callback.
 */
typedef enum
{
    //None.
    ZMVideoSDKChatMessageDeleteType_None = 0,
    //Indicates that the message was deleted by myself.
    ZMVideoSDKChatMessageDeleteType_BySelf,
    //Indicates that the message was deleted by the session host.
    ZMVideoSDKChatMessageDeleteType_ByHost,
    //Indicates that the message was deleted by Data Loss Prevention (dlp). This happens when the message goes against the host organization's compliance policies.
    ZMVideoSDKChatMessageDeleteType_ByDlp,
}ZMVideoSDKChatMessageDeleteType;

/**
 * @brief Enumerations of the type for virtual background.
 */
typedef enum
{
    ZMVideoSDKVirtualBackgroundDataType_None,
    ZMVideoSDKVirtualBackgroundDataType_Image,
    ZMVideoSDKVirtualBackgroundDataType_Blur,
}ZMVideoSDKVirtualBackgroundDataType;

/**
 * @brief Type of telephone call.
 */
typedef enum
{
    //For initialization.
    ZMVideoSDKDialInNumType_None,
    //Paid.
    ZMVideoSDKDialInNumType_Toll,
    //Free.
    ZMVideoSDKDialInNumType_TollFree,
}ZMVideoSDKDialInNumType;

/**
 * @brief Type of video network status.
 */
typedef enum
{
    ZMVideoSDKNetworkStatus_None,
    ZMVideoSDKNetworkStatus_Bad,
    ZMVideoSDKNetworkStatus_Normal,
    ZMVideoSDKNetworkStatus_Good,
}ZMVideoSDKNetworkStatus;

/**
 * @brief Cloud record agree type.
 */
typedef enum
{
    // Invalid type.
    ZMVideoSDKConsentType_Invalid,
    // In this case, 'accept' means agree to be recorded to gallery and speaker mode, 'decline' means leave session.
    ZMVideoSDKConsentType_Traditional,
    // In this case, 'accept' means agree to be recorded to a separate file, 'decline' means stay in session and can't be recorded.
    ZMVideoSDKConsentType_Individual,
}ZMVideoSDKConsentType;


/**
 * @brief Screen capture mode.
 */
typedef enum
{
    //Screen capture mode is automatically.
    ZMVideoSDKScreenCaptureMode_Auto,
    //Screen capture mode is previous operating systems.
    ZMVideoSDKScreenCaptureMode_Legacy,
    //Screen capture mode is capture with window filtering.
    ZMVideoSDKScreenCaptureMode_Filtering,
    //Screen capture mode is advanced copy with window filtering.
    ZMVideoSDKScreenCaptureMode_ADA_Filtering,
    //Screen capture mode is advanced copy without window filtering.
    ZMVideoSDKScreenCaptureMode_ADA_Without_Filtering,
}ZMVideoSDKScreenCaptureMode;


/**
 @brief An enumeration of the video aspect ratio.
 */
typedef enum
{
    //Original aspect ratio
    ZMVideoSDKVideoAspect_Original,
    //Full filled
    ZMVideoSDKVideoAspect_Full_Filled,
    //Letter box
    ZMVideoSDKVideoAspect_LetterBox,
    //Pan and scan
    ZMVideoSDKVideoAspect_PanAndScan,
}ZMVideoSDKVideoAspect;

/**
 @brief An enumeration of the video type.
 */
typedef enum
{
    //Video Camera data
    ZMVideoSDKCanvasType_VideoData = 1,
    //Share data
    ZMVideoSDKCanvasType_ShareData,
}ZMVideoSDKCanvasType;

/**
 @brief An enumeration of raw data formate.
 */
typedef enum
{
    ZMVideoSDKFrameDataFormat_I420_Limited,
    ZMVideoSDKFrameDataFormat_I420_Full,
}ZMVideoSDKFrameDataFormat;

/**
 @brief Call CRC protocol.
 */
typedef enum
{
   //H.323 type.
    ZMVideoSDKCRCProtocol_H323,
   //SIP type.
    ZMVideoSDKCRCProtocol_SIP
}ZMVideoSDKCRCProtocol;

/**
 @brief CRC call status.
 */
typedef enum
{
    //Call out successfully.
    ZMVideoSDKCRCCallStatus_Success = 0,
    //Bell during the call.
    ZMVideoSDKCRCCallStatus_Ring,
    //Call timeout.
    ZMVideoSDKCRCCallStatus_Timeout,
    //Busy.
    ZMVideoSDKCRCCallStatus_Busy,
    //Decline.
    ZMVideoSDKCRCCallStatus_Decline,
    //Call fails.
    ZMVideoSDKCRCCallStatus_Failed
}ZMVideoSDKCRCCallStatus;

/**
 * @brief Enumerations for the video subscribe failed reason.
 */
typedef enum{
    ZMVideoSDKSubscribeFailReason_None = 0,
    ZMVideoSDKSubscribeFailReason_HasSubscribe1080POr720P,
    ZMVideoSDKSubscribeFailReason_HasSubscribeTwo720P,
    ZMVideoSDKSubscribeFailReason_HasSubscribeExceededLimit,
    ZMVideoSDKSubscribeFailReason_HasSubscribeTwoShare,
    ZMVideoSDKSubscribeFailReason_HasSubscribeVideo1080POr720PAndOneShare
} ZMVideoSDKSubscribeFailReason;

/**
 * @brief Enumerations of the type for chat privilege.
 */
typedef enum{
    ZMVideoSDKChatPrivilegeType_Unknown = 0,
    ZMVideoSDKChatPrivilegeType_Publicly_And_Privately,
    ZMVideoSDKChatPrivilegeType_No_One,
    ZMVideoSDKChatPrivilegeType_Publicly,
} ZMVideoSDKChatPrivilegeType;

/**
 * @brief Enumerations of the type for annotation tool.
 */
typedef enum{
    ZMVideoSDKAnnotationToolType_None,
    ZMVideoSDKAnnotationToolType_Pen,
    ZMVideoSDKAnnotationToolType_HighLighter,
    ZMVideoSDKAnnotationToolType_AutoLine,
    ZMVideoSDKAnnotationToolType_AutoRectangle,
    ZMVideoSDKAnnotationToolType_AutoEllipse,
    ZMVideoSDKAnnotationToolType_AutoArrow,
    ZMVideoSDKAnnotationToolType_AutoRectangleFill,
    ZMVideoSDKAnnotationToolType_AutoEllipseFill,
    ZMVideoSDKAnnotationToolType_SpotLight,
    ZMVideoSDKAnnotationToolType_Arrow,
    ZMVideoSDKAnnotationToolType_ERASER,
    ZMVideoSDKAnnotationToolType_Textbox,
    ZMVideoSDKAnnotationToolType_Picker,
    ZMVideoSDKAnnotationToolType_AutoRectangleSemiFill,
    ZMVideoSDKAnnotationToolType_AutoEllipseSemiFill,
    ZMVideoSDKAnnotationToolType_AutoDoubleArrow,
    ZMVideoSDKAnnotationToolType_AutoDiamond,
    ZMVideoSDKAnnotationToolType_AutoStampArrow,
    ZMVideoSDKAnnotationToolType_AutoStampCheck,
    ZMVideoSDKAnnotationToolType_AutoStampX,
    ZMVideoSDKAnnotationToolType_AutoStampStar,
    ZMVideoSDKAnnotationToolType_AutoStampHeart,
    ZMVideoSDKAnnotationToolType_AutoStampQm
}ZMVideoSDKAnnotationToolType;

/**
 * @brief Enumerations of the type for clear annotation.
 */
typedef enum{
    //Clear all annotations. Hosts, managers and shared meeting owners can use.
    ZMVideoSDKAnnotationClearType_All,
    //Clear only the others' annotations. Only shared meeting owners can use.
    ZMVideoSDKAnnotationClearType_Others,
    //Clear only your own annotations. Everyone can use.
    ZMVideoSDKAnnotationClearType_My
}ZMVideoSDKAnnotationClearType;

typedef enum
{
    // The file transfer has no state.
    ZMVideoSDKFileTransferStatus_None = 0,
    // The file transfer is ready to start.
    ZMVideoSDKFileTransferStatus_ReadyToTransfer,
    // The file transfer is in progress.
    ZMVideoSDKFileTransferStatus_Transfering,
    // The file transfer failed.
    ZMVideoSDKFileTransferStatus_TransferFailed,
    // The file transfer completed successfully.
    ZMVideoSDKFileTransferStatus_TransferDone,
}ZMVideoSDKFileTransferStatus;

typedef enum
{
    ZMVideoSDKAudioChannel_Mono = 0,
    ZMVideoSDKAudioChannel_Stereo
}ZMVideoSDKAudioChannel;

typedef enum
{
    //Unknown
    ZMVideoSDKSessionLeaveReason_Unknown = 0,
    //Leave session by self.
    ZMVideoSDKSessionLeaveReason_BySelf,
    //Kicked by host.
    ZMVideoSDKSessionLeaveReason_KickByHost,
    //Ended by host.
    ZMVideoSDKSessionLeaveReason_EndByHost,
    //Network is broken.
    ZMVideoSDKSessionLeaveReason_NetworkError
}ZMVideoSDKSessionLeaveReason;

typedef enum
{
    ZMVideoSDKRemoteControlStatus_None = 0,                ///<For initialization.
    ZMVideoSDKRemoteControlStatus_CanRequestControl,    ///<Remote control information. I can enable the remote control.
    ZMVideoSDKRemoteControlStatus_RequestDenied,    ///<Remote control information. I have received a refused information of remote control.
    ZMVideoSDKRemoteControlStatus_GotControl,            ///<The authority of remote control. I get control when remote control begins.
    ZMVideoSDKRemoteControlStatus_LostControl,        ///<The authority of remote control. I lose control when remote control ends.
    ZMVideoSDKRemoteControlStatus_ControlStart,    ///<The status of remote control. I am remotely controlling another.
    ZMVideoSDKRemoteControlStatus_ControlStop,    ///<The status of remote control. I am not remotely controlling another.
    ZMVideoSDKRemoteControlStatus_GiveControlTo,        ///<The status of remote control. I can be controlled by the specified user.
    ZMVideoSDKRemoteControlStatus_ControlRevoked,        ///<The status of remote control. I have revoked remote control.
    ZMVideoSDKRemoteControlStatus_ControlledBy,        ///<The status of remote control. I am being controlled by the specified user.
    ZMVideoSDKRemoteControlStatus_NotControlled        ///<The status of remote control. I am not being controlled.
}ZMVideoSDKRemoteControlStatus;
