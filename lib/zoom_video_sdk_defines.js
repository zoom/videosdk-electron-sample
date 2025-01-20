/**
 * @alias ZoomVideoSDKErrors
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKErrors = {
  ZoomVideoSDKErrors_Success: 0,
  ZoomVideoSDKErrors_Wrong_Usage: 1,
  ZoomVideoSDKErrors_Internal_Error: 2,
  ZoomVideoSDKErrors_Uninitialize: 3,
  ZoomVideoSDKErrors_Memory_Error: 4,
  ZoomVideoSDKErrors_Load_Module_Error: 5,
  ZoomVideoSDKErrors_UnLoad_Module_Error: 6,
  ZoomVideoSDKErrors_Invalid_Parameter: 7,
  ZoomVideoSDKErrors_Call_Too_Frequently: 8,
  ZoomVideoSDKErrors_No_Impl: 9,
  ZoomVideoSDKErrors_Dont_Support_Feature: 10,
  ZoomVideoSDKErrors_Unknown: 11,
  ZoomVideoSDKErrors_Auth_Base: 1000,
  ZoomVideoSDKErrors_Auth_Error: 1001,
  ZoomVideoSDKErrors_Auth_Empty_Key_or_Secret: 1002,
  ZoomVideoSDKErrors_Auth_Wrong_Key_or_Secret: 1003,
  ZoomVideoSDKErrors_Auth_DoesNot_Support_SDK: 1004,
  ZoomVideoSDKErrors_Auth_Disable_SDK: 1005,
  ZoomVideoSDKErrors_JoinSession_NoSessionName: 1500,
  ZoomVideoSDKErrors_JoinSession_NoSessionToken: 1501,
  ZoomVideoSDKErrors_JoinSession_NoUserName: 1502,
  ZoomVideoSDKErrors_JoinSession_Invalid_SessionName: 1503,
  ZoomVideoSDKErrors_JoinSession_Invalid_Password: 1504,
  ZoomVideoSDKErrors_JoinSession_Invalid_SessionToken: 1505,
  ZoomVideoSDKErrors_JoinSession_SessionName_TooLong: 1506,
  ZoomVideoSDKErrors_JoinSession_Token_MismatchedSessionName: 1507,
  ZoomVideoSDKErrors_JoinSession_Token_NoSessionName: 1508,
  ZoomVideoSDKErrors_JoinSession_Token_RoleType_EmptyOrWrong: 1509,
  ZoomVideoSDKErrors_JoinSession_Token_UserIdentity_TooLong: 1510,
  ZoomVideoSDKErrors_Session_Base: 2000,
  ZoomVideoSDKErrors_SessionModule_Not_Found: 2001,
  ZoomVideoSDKErrors_SessionService_Invalid: 2002,
  ZoomVideoSDKErrors_Session_Join_Failed: 2003,
  ZoomVideoSDKErrors_Session_No_Rights: 2004,
  ZoomVideoSDKErrors_Session_Already_In_Progress: 2005,
  ZoomVideoSDKErrors_Session_Dont_Support_SessionType: 2006,
  ZoomVideoSDKErrors_Session_Reconncting: 2007,
  ZoomVideoSDKErrors_Session_Disconncting: 2008,
  ZoomVideoSDKErrors_Session_Not_Started: 2010,
  ZoomVideoSDKErrors_Session_Need_Password: 2011,
  ZoomVideoSDKErrors_Session_Password_Wrong: 2012,
  ZoomVideoSDKErrors_Session_Remote_DB_Error: 2013,
  ZoomVideoSDKErrors_Session_Invalid_Param: 2014,
  ZoomVideoSDKErrors_Session_Client_Incompatible: 2015,
  ZoomVideoSDKErrors_Session_Audio_Error: 3000,
  ZoomVideoSDKErrors_Session_Audio_No_Microphone: 3001,
  ZoomVideoSDKErrors_Session_Audio_No_Speaker: 3002,
  ZoomVideoSDKErrors_Session_Video_Error: 4000,
  ZoomVideoSDKErrors_Session_Video_Device_Error: 4001,
  ZoomVideoSDKErrors_Session_Live_Stream_Error: 5000,
  ZoomVideoSDKErrors_Session_Phone_Error: 5500,
  ZoomVideoSDKErrors_RAWDATA_MALLOC_FAILED: 6001,
  ZoomVideoSDKErrors_RAWDATA_NOT_IN_Session: 6002,
  ZoomVideoSDKErrors_RAWDATA_NO_LICENSE: 6003,
  ZoomVideoSDKErrors_RAWDATA_VIDEO_MODULE_NOT_READY: 6004,
  ZoomVideoSDKErrors_RAWDATA_VIDEO_MODULE_ERROR: 6005,
  ZoomVideoSDKErrors_RAWDATA_VIDEO_DEVICE_ERROR: 6006,
  ZoomVideoSDKErrors_RAWDATA_NO_VIDEO_DATA: 6007,
  ZoomVideoSDKErrors_RAWDATA_SHARE_MODULE_NOT_READY: 6008,
  ZoomVideoSDKErrors_RAWDATA_SHARE_MODULE_ERROR: 6009,
  ZoomVideoSDKErrors_RAWDATA_NO_SHARE_DATA: 6010,
  ZoomVideoSDKErrors_RAWDATA_AUDIO_MODULE_NOT_READY: 6011,
  ZoomVideoSDKErrors_RAWDATA_AUDIO_MODULE_ERROR: 6012,
  ZoomVideoSDKErrors_RAWDATA_NO_AUDIO_DATA: 6013,
  ZoomVideoSDKErrors_RAWDATA_PREPROCESS_RAWDATA_ERROR: 6014,
  ZoomVideoSDKErrors_RAWDATA_NO_DEVICE_RUNNING: 6015,
  ZoomVideoSDKErrors_RAWDATA_INIT_DEVICE: 6016,
  ZoomVideoSDKErrors_RAWDATA_VIRTUAL_DEVICE: 6017,
  ZoomVideoSDKErrors_RAWDATA_CANNOT_CHANGE_VIRTUAL_DEVICE_IN_PREVIEW: 6018,
  ZoomVideoSDKErrors_RAWDATA_INTERNAL_ERROR: 6019,
  ZoomVideoSDKErrors_RAWDATA_SEND_TOO_MUCH_DATA_IN_SINGLE_TIME: 6020,
  ZoomVideoSDKErrors_RAWDATA_SEND_TOO_FREQUENTLY: 6021,
  ZoomVideoSDKErrors_RAWDATA_VIRTUAL_MIC_IS_TERMINATE: 6022,
  ZoomVideoSDKErrors_Session_Share_Error: 7001,
  ZoomVideoSDKErrors_Session_Share_Module_Not_Ready: 7002,
  ZoomVideoSDKErrors_Session_Share_You_Are_Not_Sharing: 7003,
  ZoomVideoSDKErrors_Session_Share_Type_Is_Not_Support: 7004,
  ZoomVideoSDKErrors_Session_Share_Internal_Error: 7005,
  ZoomVideoSDKErrors_Dont_Support_Multi_Stream_Video_User: 7006,
  ZoomVideoSDKErrors_Fail_Assign_User_Privilege: 7007,
  ZoomVideoSDKErrors_No_Recording_In_Process: 7008,
  ZoomVideoSDKErrors_Set_Virtual_Background_Fail: 7009,
  ZoomVideoSDKErrors_Filetransfer_UnknowError: 7500,
  ZoomVideoSDKErrors_Filetransfer_FileTypeBlocked: 7501,
  ZoomVideoSDKErrors_Filetransfer_FileSizelimited: 7502,
  ZoomVideoSDKErrors_Spotlight_NotEnoughUsers: 7600,
  ZoomVideoSDKErrors_Spotlight_ToMuchSpotlightedUsers: 7601,
  ZoomVideoSDKErrors_Spotlight_UserCannotBeSpotlighted: 7602,
  ZoomVideoSDKErrors_Spotlight_UserWithoutVideo: 7603,
  ZoomVideoSDKErrors_Spotlight_UserNotSpotlighted: 7604
}

/**
 * @alias ZoomVideoSDKSessionLeaveReason
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKSessionLeaveReason = {
  ZoomVideoSDKSessionLeaveReason_Unknown: 0,
  ZoomVideoSDKSessionLeaveReason_BySelf: 1,
  ZoomVideoSDKSessionLeaveReason_KickByHost: 2,
  ZoomVideoSDKSessionLeaveReason_EndByHost: 3,
  ZoomVideoSDKSessionLeaveReason_NetworkError: 4,
}

/**
 * @alias ZoomVideoSDKRawDataMemoryMode
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKRawDataMemoryMode = {
  ZoomVideoSDKRawDataMemoryModeStack: 0,
  ZoomVideoSDKRawDataMemoryModeHeap: 1
}

/**
 * @alias ZoomVideoSDKResolution
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKResolution = {
  ZoomVideoSDKResolution_90P: 0,
  ZoomVideoSDKResolution_180P: 1,
  ZoomVideoSDKResolution_360P: 2,
  ZoomVideoSDKResolution_720P: 3,
  ZoomVideoSDKResolution_1080P: 4,
  ZoomVideoSDKResolution_NoUse: 100
}

/**
 * @alias ZoomVideoSDKUserInfoType
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKUserInfoType = {
  UserInfoType_FAKE: 0,
  UserInfoType_REAL: 1,
  UserInfoType_ALL: 1048575
};

/**
 * @alias ZoomVideoSDKShareStatus
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKShareStatus = {
  ZoomVideoSDKShareStatus_None: 0,
  ZoomVideoSDKShareStatus_Start: 1,
  ZoomVideoSDKShareStatus_Pause: 2,
  ZoomVideoSDKShareStatus_Resume: 3,
  ZoomVideoSDKShareStatus_Stop: 4
}

/**
 * @alias ZoomVideoSDKSubscribeFailReason
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKSubscribeFailReason = {
	ZoomVideoSDKSubscribeFailReason_None: 0,
	ZoomVideoSDKSubscribeFailReason_HasSubscribe1080POr720P: 1,
	ZoomVideoSDKSubscribeFailReason_HasSubscribeTwo720P: 2,
	ZoomVideoSDKSubscribeFailReason_HasSubscribeExceededLimit: 3,
	ZoomVideoSDKSubscribeFailReason_HasSubscribeTwoShare: 4,
	ZoomVideoSDKSubscribeFailReason_HasSubscribeVideo1080POr720PAndOneShare: 5
}

/**
 * @alias ZoomVideoSDKRawDataType
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKRawDataType = {
  RAW_DATA_TYPE_VIDEO: 0,
  RAW_DATA_TYPE_SHARE: 1
}

/**
 * @alias ZoomVideoSDKShareAppInfo
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKShareAppInfo = {
  appName: 0,
  appHandle: 1 
}

/**
 * @alias ZoomVideoSDKRawDataStatus
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKRawDataStatus = {
  RawData_On: 0,
  RawData_Off: 1 
}

/**
 * @alias ZoomVideoSDKCallback
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKCallback = {
  onSessionJoin: 0,
  onSessionLeave: 1,
  onError: 2,
  onUserJoin: 3,
  onUserLeave: 4,
  onUserVideoStatusChanged: 5,
  onUserAudioStatusChanged: 6,
  onUserShareStatusChanged: 7,
  onLiveStreamStatusChanged: 8,
  onChatNewMessageNotify: 9,
  onUserHostChanged: 10,
  onUserActiveAudioChanged: 11,
  onSessionNeedPassword: 12,
  onSessionPasswordWrong: 13,
  onInitialize: 14,
  onPropertyChange: 15,
  onStartSend: 16,
  onStopSend: 17,
  onUninitialized: 18,
  onRawDataStatusChanged: 19,
  onUserManagerChanged: 20,
  onUserNameChanged: 21,
  /** 22, Callback for when the current user is granted camera control access. Once the current user sends the camera control request, this callback will be triggered with the result of the request. */
  onCommandReceived: 22,
  onCloudRecordingStatus: 23,
  onCameraControlRequestResult: 24,
  onCameraControlRequestReceived: 25,
  /** 26, Callback interface for when the current user has received a camera control request. This will be triggered when another user requests control of the current users camera. */
  onCommandChannelConnectResult: 26,
  onHostAskUnmute: 27,
  onInviteByPhoneStatus: 28,
  /** 29, When someone enables multi-camera, all participants receive the callback event. */
  onMultiCameraStreamStatusChanged: 29,
  /** 30, Notify the current mic or speaker volume when testing. */
  onMicSpeakerVolumeChanged: 30,
  onAudioDeviceStatusChanged: 31,
  onTestMicStatusChanged: 32,
  onSelectedAudioDeviceChanged: 33,
  onLiveTranscriptionStatus: 34,
  onLiveTranscriptionMsgError: 36,
  onChatMsgDeleteNotification: 37,
  onLiveTranscriptionMsgInfoReceived: 38,
  onOriginalLanguageMsgReceived: 39,
  /** 40, Invoked when the callout user successfully joins the meeting. */
  onCalloutJoinSuccess: 40,
  /** 42, Callback for when the remote control status changes. */
  onRemoteControlStatus: 42,
  /** 43, Callback for when the current user has received a remote control request. */
  onRemoteControlRequestReceived: 43,
  /** 44, Callback after the first invocation of enableAdminRemoteControl(true). */
  onRemoteControlServiceInstallResult: 44,
  onSpotlightVideoChanged: 45,
  /** 46, Callback event that binds the incoming live stream. */
  onBindIncomingLiveStreamResponse: 46,
  /** 47, Callback event that unbinds the incoming live stream. */
  onUnbindIncomingLiveStreamResponse: 47,
  /** 48, Callback event that gets the streams status. */
  onIncomingLiveStreamStatusResponse: 48,
  /** 49, Callback event that starts the bound stream. */
  onStartIncomingLiveStreamResponse: 49,
  /** 50, Callback event that stops the bound stream. */
  onStopIncomingLiveStreamResponse: 50,
  /** 51, Invoked when a user failed to start sharing. */
  onFailedToStartShare: 51
}

/**
 * @alias RendererMode
 * @readonly
 * @enum {Number}
*/
const RendererMode = {
  videoSDKRenderMode_None: 0,
  videoSDKRenderMode_FullRect: 1,
  videoSDKRenderMode_AspectRatio: 2
};

/**
 * @alias RecordingStatus
 * @readonly
 * @enum {Number}
*/
const RecordingStatus = {
  /** 0, Start recording on local computer or on cloud. */
  Recording_Start: 0,
  /** 1, Stop recording on local computer or on cloud. */
  Recording_Stop: 1,
  /** 2, There is no space to store for cloud recording. */
  Recording_DiskFull: 2,
  /** 3, Pause recording on local or on cloud. */
  Recording_Pause: 3
};

/**
 * @alias ZoomVideoSDKCameraControlRequestType
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKCameraControlRequestType = {
  ZoomVideoSDKCameraControlRequestType_RequestControl: 0,
  ZoomVideoSDKCameraControlRequestType_GiveUpControl: 1
};

/**
 * @alias ZoomVideoSDKRemoteControlStatus
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKRemoteControlStatus = {
  /** 0, For initialization. */
  ZoomVideoSDKRemoteControlStatus_None: 0,
  /** 1, Remote control information. I can enable the remote control. */
  ZoomVideoSDKRemoteControlStatus_CanRequestControl: 1,
  /** 2, Remote control information. I have received a refused information of remote control. */
  ZoomVideoSDKRemoteControlStatus_RequestDenied: 2,
  /** 3, The authority of remote control. I get control when remote control begins. */
  ZoomVideoSDKRemoteControlStatus_GotControl: 3,
  /** 4, The authority of remote control. I lose control when remote control ends. */
  ZoomVideoSDKRemoteControlStatus_LostControl: 4,
  /** 5, The status of remote control. I am remotely controlling another. */
  ZoomVideoSDKRemoteControlStatus_ControlStart: 5,
  /** 6, The status of remote control. I am not remotely controlling another. */
  ZoomVideoSDKRemoteControlStatus_ControlStop: 6,
  /** 7, The status of remote control. I can be controlled by the specified user. */
  ZoomVideoSDKRemoteControlStatus_GiveControlTo: 7,
  /** 8, The status of remote control. I have revoked remote control. */
  ZoomVideoSDKRemoteControlStatus_ControlRevoked: 8,
  /** 9, The status of remote control. I am being controlled by the specified user. */
  ZoomVideoSDKRemoteControlStatus_ControlledBy: 9,
  /** 10, The status of remote control. I am not being controlled. */
  ZoomVideoSDKRemoteControlStatus_NotControlled: 10
};

/**
 * @alias PhoneStatus
 * @readonly
 * @enum {Number} Status of telephone.
*/
const PhoneStatus = {
  /** 0, No status. */
  PhoneStatus_None: 0,
  /** 1, In process of calling out. */
  PhoneStatus_Calling: 1,
  /** 2, In process of ringing. */
  PhoneStatus_Ringing: 2,
  /** 3, Accept the call. */
  PhoneStatus_Accepted: 3,
  /** 4, Accept the call. */
  PhoneStatus_Success: 4,
  /** 5, Call failed. */
  PhoneStatus_Failed: 5,
  /** 6, In process of canceling the response to the previous state. */
  PhoneStatus_Canceling: 6,
  /** 7, Cancel successfully. */
  PhoneStatus_Canceled: 7,
  /** 8, Cancel fails. */
  PhoneStatus_Cancel_Failed: 8,
  PhoneStatus_Timeout: 9
};

/**
 * @alias PhoneFailedReason
 * @readonly
 * @enum {Number} The reason for the failure of the telephone call.
*/
const PhoneFailedReason = {
  /** 0, For initialization. */
  PhoneFailedReason_None: 0,
  /** 1, The telephone service is busy. */
  PhoneFailedReason_Busy: 1,
  /** 2, The telephone is out of the service. */
  PhoneFailedReason_Not_Available: 2,
  /** 3, The user hangs up. */
  PhoneFailedReason_User_Hangup: 3,
  /** 4, Other reasons. */
  PhoneFailedReason_Other_Fail: 4,
  /** 5, The telephone does not reply. */
  PhoneFailedReason_No_Answer: 5,
  /** 6, Disable the function of international call-out before the host joins the session. */
  PhoneFailedReason_Block_No_Host: 6,
  /** 7, The call-out is blocked by the system due to the high cost. */
  PhoneFailedReason_Block_High_Rate: 7,
  /** 8, All the invitees invited by the call should press the button one(1) to join the session. In case that many invitees do not press the button that leads to time out, the call invitation for this session shall be banned. */
  PhoneFailedReason_Block_Too_Frequent: 8
};

/**
 * @alias ZoomVideoSDKVideoPreferenceMode
 * @readonly
 * @enum {Number} video preference mode types. Here are more detailed structural descriptions.
*/
const ZoomVideoSDKVideoPreferenceMode = {
  /** 0, Balance mode. */
  ZoomVideoSDKVideoPreferenceMode_Balance: 0,
  /** 1, Sharpness mode. */
  ZoomVideoSDKVideoPreferenceMode_Sharpness: 1,
  /** 2, Smoothness mode. */
  ZoomVideoSDKVideoPreferenceMode_Smoothness : 2,
  /** 3, Custom mode. */
  ZoomVideoSDKVideoPreferenceMode_Custom : 2
};

/**
 * @alias ZoomVideoSDKSuppressBackgroundNoiseLevel
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKSuppressBackgroundNoiseLevel = {
  ZoomVideoSDKSuppressBackgroundNoiseLevel_Auto: 0,
  ZoomVideoSDKSuppressBackgroundNoiseLevel_Low: 1,
  ZoomVideoSDKSuppressBackgroundNoiseLevel_Medium: 2,
  ZoomVideoSDKSuppressBackgroundNoiseLevel_High: 3
}

/**
 * @alias ZoomVideoSDKEchoCancellationLevel
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKEchoCancellationLevel = {
  ZoomVideoSDKEchoCancellationLevel_Default: 0,
  ZoomVideoSDKEchoCancellationLevel_Aggressive: 1
}

/**
 * @alias ZoomVideoSDKMultiStreamStatus
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKMultiStreamStatus = {
  /** 0, Current user only. This status is received when the current user starts the attempt to use multiple cameras in the session. */
  ZoomVideoSDKMultiCameraStreamStatus_JoinStart: 0,
  /** 1, Current user only. This status is received when the current user fails the attempt to use multiple cameras in the session. */
  ZoomVideoSDKMultiCameraStreamStatus_JoinFail: 1,
  /** 2, Broadcasted to all users. This status is received when a new camera has been successfully added to the session as the multiple cameras. */
  ZoomVideoSDKMultiCameraStreamStatus_Joined: 2,
  /** 3, Broadcasted to all users. This status is received when a camera that is being used as the multiple cameras has left the session. */
  ZoomVideoSDKMultiCameraStreamStatus_Left: 3
}

/**
 * @alias ZoomVideoSDKTestMicStatus
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKTestMicStatus = {
  /** 0, Test the mic via StartMicTestRecording. It is useless to call StopMicTestRecording/PlayMicTestRecording in this status. */
  ZoomVideoSDKMic_CanTest: 0,
  /** 1, Test the mic via StopMicTestRecording/PlayMicTestRecording. It is useless to call StartMicTestRecording in this status. */
  ZoomVideoSDKMic_Recording: 1,
  /** 2, Test the mic via StopMicTestRecording/PlayMicTestRecording. It is useless call StartMicTestRecording in this status. */
  ZoomVideoSDKMic_CanPlay: 2
}

/**
 * @alias ZoomVideoSDKAudioDeviceType
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKAudioDeviceType = {
  ZoomVideoSDKDevice_Microphone: 0,
  ZoomVideoSDKDevice_Speaker: 1
}

/**
 * @alias ZoomVideoSDKAudioDeviceStatus
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKAudioDeviceStatus = {
  ZoomVideoSDK_Device_Error_Unknow: 0,
  ZoomVideoSDK_No_Device: 1,
  ZoomVideoSDK_Device_List_Update: 2,
  ZoomVideoSDK_Audio_No_Input: 3,
  ZoomVideoSDK_Audio_Disconnect_As_Detected_Echo: 4
}

/**
 * @alias ZoomVideoSDKShareType
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKShareType = {
  ZoomVideoSDKShareType_None: 0,
  ZoomVideoSDKShareType_Normal: 1,
  ZoomVideoSDKShareType_PureAudio: 2
}

/**
 * @alias ZoomVideoSDKVideoSourceDataMode
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKVideoSourceDataMode = {
  /** 0, For general usage scenarios. */
  VideoSourceDataMode_None: 0,
  /** 1, Special usage scenarios, each frame of video is organized around two images. */
  VideoSourceDataMode_Horizontal: 1,
  /** 2, Special usage scenarios, each frame of video is two images organized up and down together. */
  VideoSourceDataMode_Vertical: 2
}

/**
 * @alias ZoomVideoSDKLiveTranscriptionStatus
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKLiveTranscriptionStatus = {
  /** 0, not start. */
  ZoomVideoSDKLiveTranscription_Status_Stop: 0,
  /** 1, start. */
  ZoomVideoSDKLiveTranscription_Status_Start: 1
}

/**
 * @alias ZoomVideoSDKLiveTranscriptionOperationType
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKLiveTranscriptionOperationType = {
  ZoomVideoSDKLiveTranscription_OperationType_None: 0,
  ZoomVideoSDKLiveTranscription_OperationType_Add: 1,
  ZoomVideoSDKLiveTranscription_OperationType_Update: 2,
  ZoomVideoSDKLiveTranscription_OperationType_Delete: 3,
  ZoomVideoSDKLiveTranscription_OperationType_Complete: 4,
  ZoomVideoSDKLiveTranscription_OperationType_NotSupported: 5
}

/**
 * @alias ZoomVideoSDKChatMessageDeleteType
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKChatMessageDeleteType = {
  /** 0, none. */
  ZoomVideoSDKChatDelete_None: 0,
  /** 1, delete by self. */
  ZoomVideoSDKChatDelete_BySelf: 1,  
  /** 2, delete by host. */
  ZoomVideoSDKChatDelete_ByHost: 2,
  /** 3, delete by dlp when the message goes against the host organization's compliance policies. */
  ZoomVideoSDKChatDelete_ByDlp: 3
}

/**
 * @alias ZoomVideoSDKScreenCaptureMode
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKScreenCaptureMode = {
  /** 0, Screen capture mode is automatically. */
  ZoomVideoSDKScreenCaptureMode_Auto: 0,
  /** 1, Screen capture mode is legacy operating systems. */
  ZoomVideoSDKScreenCaptureMode_Legacy: 1,  
  /** 2, Screen capture mode is capture with window filtering. */
  ZoomVideoSDKScreenCaptureMode_Filtering: 2,
  /** 3, Screen capture mode is advanced share with window filtering. */
  ZoomVideoSDKScreenCaptureMode_ADA_Filtering: 3,
  /** 4, Screen capture mode is advanced share without window filtering. */
  ZoomVideoSDKScreenCaptureMode_ADA_Without_Filtering: 4,
  /** 5, Screen capture mode is secure share with window filtering. */
  ZoomVideoSDKScreenCaptureMode_Secure_Filtering: 5
}

module.exports = {
  ZoomVideoSDKErrors,
  ZoomVideoSDKSessionLeaveReason,
  ZoomVideoSDKRawDataMemoryMode,
  ZoomVideoSDKResolution,
  ZoomVideoSDKUserInfoType,
  ZoomVideoSDKShareStatus,
  ZoomVideoSDKSubscribeFailReason,
  ZoomVideoSDKRawDataType,
  ZoomVideoSDKShareAppInfo,
  ZoomVideoSDKRawDataStatus,
  ZoomVideoSDKCallback,
  RendererMode,
  RecordingStatus,
  ZoomVideoSDKCameraControlRequestType,
  ZoomVideoSDKRemoteControlStatus,
  PhoneStatus,
  PhoneFailedReason,
  ZoomVideoSDKVideoPreferenceMode,
  ZoomVideoSDKSuppressBackgroundNoiseLevel,
  ZoomVideoSDKEchoCancellationLevel,
  ZoomVideoSDKMultiStreamStatus,
  ZoomVideoSDKTestMicStatus,
  ZoomVideoSDKAudioDeviceType,
  ZoomVideoSDKAudioDeviceStatus,
  ZoomVideoSDKShareType,
  ZoomVideoSDKVideoSourceDataMode,
  ZoomVideoSDKLiveTranscriptionStatus,
  ZoomVideoSDKLiveTranscriptionOperationType,
  ZoomVideoSDKChatMessageDeleteType,
  ZoomVideoSDKScreenCaptureMode
}