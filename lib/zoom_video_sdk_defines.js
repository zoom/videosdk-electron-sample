/**
 * @alias ZoomVideoSDKErrors
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKErrors = {
  /** Success. */
  ZoomVideoSDKErrors_Success: 0,
  /** Incorrect usage of the feature. */
  ZoomVideoSDKErrors_Wrong_Usage: 1,
  /** Internal SDK error. */
  ZoomVideoSDKErrors_Internal_Error: 2,
  /** SDK is not initialized before usage. */
  ZoomVideoSDKErrors_Uninitialize: 3,
  /** No memory is allocated or memory allocation failed. */
  ZoomVideoSDKErrors_Memory_Error: 4,
  /** Failed to load module. */
  ZoomVideoSDKErrors_Load_Module_Error: 5,
  /** Failed to unload module. */
  ZoomVideoSDKErrors_UnLoad_Module_Error: 6,
  /** Invalid parameter passed to a function. */
  ZoomVideoSDKErrors_Invalid_Parameter: 7,
  /** API is being called too frequently. */
  ZoomVideoSDKErrors_Call_Too_Frequently: 8,
  /** The requested feature is not implemented. */
  ZoomVideoSDKErrors_No_Impl: 9,
  /** The current session does not support the feature. */
  ZoomVideoSDKErrors_Dont_Support_Feature: 10,
  /** Unknown error occurred. */
  ZoomVideoSDKErrors_Unknown: 11,
  /** Failed to remove folder. */
  ZoomVideoSDKErrors_Remove_Folder_Fail: 12,
  /** General authorization failure. */
  ZoomVideoSDKErrors_Auth_Error: 1001,
  /** Authorization failed due to missing key or secret. */
  ZoomVideoSDKErrors_Auth_Empty_Key_or_Secret: 1002,
  /** Authorization failed due to invalid key or secret. */
  ZoomVideoSDKErrors_Auth_Wrong_Key_or_Secret: 1003,
  /** Authorization does not support SDK. */
  ZoomVideoSDKErrors_Auth_DoesNot_Support_SDK: 1004,
  /** Authorization disable SDK. */
  ZoomVideoSDKErrors_Auth_Disable_SDK: 1005,
  /** Session name is missing when joining session. */
  ZoomVideoSDKErrors_JoinSession_NoSessionName: 1500,
  /** Session token is missing when joining session. */
  ZoomVideoSDKErrors_JoinSession_NoSessionToken: 1501,
  /** User name is missing when joining session. */
  ZoomVideoSDKErrors_JoinSession_NoUserName: 1502,
  /** Session name is invalid. */
  ZoomVideoSDKErrors_JoinSession_Invalid_SessionName: 1503,
  /** Session password is invalid. */
  ZoomVideoSDKErrors_JoinSession_Invalid_Password: 1504,
  /** Session token is invalid. */
  ZoomVideoSDKErrors_JoinSession_Invalid_SessionToken: 1505,
  /** Session name exceeds the allowed length. */
  ZoomVideoSDKErrors_JoinSession_SessionName_TooLong: 1506,
  /** Token does not match the session name. */
  ZoomVideoSDKErrors_JoinSession_Token_MismatchedSessionName: 1507,
  /** Token does not include session name. */
  ZoomVideoSDKErrors_JoinSession_Token_NoSessionName: 1508,
  /** Token has empty or invalid role type. */
  ZoomVideoSDKErrors_JoinSession_Token_RoleType_EmptyOrWrong: 1509,
  /** Token includes a user identity that is too long. */
  ZoomVideoSDKErrors_JoinSession_Token_UserIdentity_TooLong: 1510,
  /** Failed to find session module. */
  ZoomVideoSDKErrors_SessionModule_Not_Found: 2001,
  /** Invalid session service. */
  ZoomVideoSDKErrors_SessionService_Invalid: 2002,
  /** Failed to join the session. */
  ZoomVideoSDKErrors_Session_Join_Failed: 2003,
  /** User does not have the rights to join the session. */
  ZoomVideoSDKErrors_Session_No_Rights: 2004,
  /** Session is already in progress. */
  ZoomVideoSDKErrors_Session_Already_In_Progress: 2005,
  /** The current session type is not supported. */
  ZoomVideoSDKErrors_Session_Dont_Support_SessionType: 2006,
  /** SDK is reconnecting to the session. */
  ZoomVideoSDKErrors_Session_Reconnecting: 2007,
  /** SDK is disconnecting from the session. */
  ZoomVideoSDKErrors_Session_Disconnecting: 2008,
  /** Session has not started yet. */
  ZoomVideoSDKErrors_Session_Not_Started: 2009,
  /** Session requires a password. */
  ZoomVideoSDKErrors_Session_Need_Password: 2010,
  /** Incorrect session password. */
  ZoomVideoSDKErrors_Session_Password_Wrong: 2011,
  /** Error from remote database. */
  ZoomVideoSDKErrors_Session_Remote_DB_Error: 2012,
  /** Invalid session parameter. */
  ZoomVideoSDKErrors_Session_Invalid_Param: 2013,
  /** Client is incompatible with the session. */
  ZoomVideoSDKErrors_Session_Client_Incompatible: 2014,
  /** Session ended due to exceeding free minutes. */
  ZoomVideoSDKErrors_Session_Account_FreeMinutesExceeded: 2015,
  /** Join session failed because the account's free credit has been exceeded. */
  ZoomVideoSDKErrors_Session_Account_FreeCreditExceeded: 2016,
  /** Audio module error. */
  ZoomVideoSDKErrors_Session_Audio_Error: 3000,
  /** No microphone detected. */
  ZoomVideoSDKErrors_Session_Audio_No_Microphone: 3001,
  /** No speaker detected. */
  ZoomVideoSDKErrors_Session_Audio_No_Speaker: 3002,
  /** Bluetooth sco connect fail. Android Only. */
  ZoomVideoSDKErrors_Session_Bluetooth_SCO_Connection_Failed: 3003,
  /** General video error. */
  ZoomVideoSDKErrors_Session_Video_Error: 4000,
  /** Video device error. */
  ZoomVideoSDKErrors_Session_Video_Device_Error: 4001,
  /** Live stream error. */
  ZoomVideoSDKErrors_Session_Live_Stream_Error: 5000,
  /** Phone connection error. */
  ZoomVideoSDKErrors_Session_Phone_Error: 5500,
  /** Failed to allocate memory for raw data. */
  ZoomVideoSDKErrors_RAWDATA_MALLOC_FAILED: 6001,
  /** Not in a session for raw data access. */
  ZoomVideoSDKErrors_RAWDATA_NOT_IN_Session: 6002,
  /** No raw data license available. */
  ZoomVideoSDKErrors_RAWDATA_NO_LICENSE: 6003,
  /** Video module not ready for raw data. */
  ZoomVideoSDKErrors_RAWDATA_VIDEO_MODULE_NOT_READY: 6004,
  /** Video module error. */
  ZoomVideoSDKErrors_RAWDATA_VIDEO_MODULE_ERROR: 6005,
  /** Video device error. */
  ZoomVideoSDKErrors_RAWDATA_VIDEO_DEVICE_ERROR: 6006,
  /** No video data available. */
  ZoomVideoSDKErrors_RAWDATA_NO_VIDEO_DATA: 6007,
  /** Share module not ready. */
  ZoomVideoSDKErrors_RAWDATA_SHARE_MODULE_NOT_READY: 6008,
  /** Share module error. */
  ZoomVideoSDKErrors_RAWDATA_SHARE_MODULE_ERROR: 6009,
  /** No shared data available. */
  ZoomVideoSDKErrors_RAWDATA_NO_SHARE_DATA: 6010,
  /** Audio module not ready. */
  ZoomVideoSDKErrors_RAWDATA_AUDIO_MODULE_NOT_READY: 6011,
  /** Audio module error. */
  ZoomVideoSDKErrors_RAWDATA_AUDIO_MODULE_ERROR: 6012,
  /** No audio data available. */
  ZoomVideoSDKErrors_RAWDATA_NO_AUDIO_DATA: 6013,
  /** Raw data preprocessing error. */
  ZoomVideoSDKErrors_RAWDATA_PREPROCESS_RAWDATA_ERROR: 6014,
  /** No media device is currently running. */
  ZoomVideoSDKErrors_RAWDATA_NO_DEVICE_RUNNING: 6015,
  /** Failed to initialize media device. */
  ZoomVideoSDKErrors_RAWDATA_INIT_DEVICE: 6016,
  /** Using a virtual device. */
  ZoomVideoSDKErrors_RAWDATA_VIRTUAL_DEVICE: 6017,
  /** Cannot change virtual device during preview. */
  ZoomVideoSDKErrors_RAWDATA_CANNOT_CHANGE_VIRTUAL_DEVICE_IN_PREVIEW: 6018,
  /** Internal raw data error. */
  ZoomVideoSDKErrors_RAWDATA_INTERNAL_ERROR: 6019,
  /** Sending too much raw data in a single call. */
  ZoomVideoSDKErrors_RAWDATA_SEND_TOO_MUCH_DATA_IN_SINGLE_TIME: 6020,
  /** Sending raw data too frequently. */
  ZoomVideoSDKErrors_RAWDATA_SEND_TOO_FREQUENTLY: 6021,
  /** Virtual microphone has been terminated. */
  ZoomVideoSDKErrors_RAWDATA_VIRTUAL_MIC_IS_TERMINATE: 6022,
  /** The share preprocessing data object is invalid. */
  ZoomVideoSDKErrors_RAWDATA_INVALID_SHARE_PREPROCESSING_DATA_OBJECT: 6023,
  /** Share preprocessing has stopped. */
  ZoomVideoSDKErrors_RAWDATA_SHARE_PREPROCESSING_IS_STOPPED: 6024,
  /** General share error. */
  ZoomVideoSDKErrors_Session_Share_Error: 7001,
  /** Share module is not ready. */
  ZoomVideoSDKErrors_Session_Share_Module_Not_Ready: 7002,
  /** You are not sharing. */
  ZoomVideoSDKErrors_Session_Share_You_Are_Not_Sharing: 7003,
  /** Share type is not supported. */
  ZoomVideoSDKErrors_Session_Share_Type_Is_Not_Support: 7004,
  /** Internal sharing error. */
  ZoomVideoSDKErrors_Session_Share_Internal_Error: 7005,
  /** Multi-stream video users are not supported. */
  ZoomVideoSDKErrors_Dont_Support_Multi_Stream_Video_User: 7006,
  /** Failed to assign user privilege. */
  ZoomVideoSDKErrors_Fail_Assign_User_Privilege: 7007,
  /** No recording in process. */
  ZoomVideoSDKErrors_No_Recording_In_Process: 7008,
  /** Recording is connecting. */
  ZoomVideoSDKErrors_Recording_Is_Connecting: 7009,
  /** Failed to set virtual background. */
  ZoomVideoSDKErrors_Set_Virtual_Background_Fail: 7010,
  /** Failed to start camera share due to video not started. */
  ZoomVideoSDKErrors_Session_Share_Camera_Video_Not_Start: 7011,
  /** Camera share conflicts with video effects. */
  ZoomVideoSDKErrors_Session_Share_Camera_Conflict_With_Video_Effects: 7012,
  /** Share conflicts with whiteboard share. */
  ZoomVideoSDKErrors_Session_Share_Conflict_With_Whiteboard: 7013,
  /** Unknown file transfer error. */
  ZoomVideoSDKErrors_Filetransfer_UnknowError: 7500,
  /** File type is blocked for transfer. */
  ZoomVideoSDKErrors_Filetransfer_FileTypeBlocked: 7501,
  /** File size exceeds the transfer limit. */
  ZoomVideoSDKErrors_Filetransfer_FileSizelimited: 7502,
  /** Not enough users for spotlighting. */
  ZoomVideoSDKErrors_Spotlight_NotEnoughUsers: 7600,
  /** Too many users are spotlighted. */
  ZoomVideoSDKErrors_Spotlight_ToMuchSpotlightedUsers: 7601,
  /** User cannot be spotlighted. */
  ZoomVideoSDKErrors_Spotlight_UserCannotBeSpotlighted: 7602,
  /** User does not have video to be spotlighted. */
  ZoomVideoSDKErrors_Spotlight_UserWithoutVideo: 7603,
  /** User is not currently spotlighted. */
  ZoomVideoSDKErrors_Spotlight_UserNotSpotlighted: 7604
}

/**
 * @alias ZoomVideoSDKSessionLeaveReason
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKSessionLeaveReason = {
  /** Unknown reason for leaving the session. */
  ZoomVideoSDKSessionLeaveReason_Unknown: 0,
  /** User left the session by themselves. */
  ZoomVideoSDKSessionLeaveReason_BySelf: 1,
  /** User was removed from the session by the host. */
  ZoomVideoSDKSessionLeaveReason_KickByHost: 2,
  /** Host ended the session. */
  ZoomVideoSDKSessionLeaveReason_EndByHost: 3,
  /** User was disconnected due to network error. */
  ZoomVideoSDKSessionLeaveReason_NetworkError: 4,
}

/**
 * @alias ZoomVideoSDKRawDataMemoryMode
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKRawDataMemoryMode = {
  /** Raw data is allocated on the stack. */
  ZoomVideoSDKRawDataMemoryModeStack: 0,
  /** Raw data is allocated on the heap. */
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
  /** No sharing activity. */
  ZoomVideoSDKShareStatus_None: 0,
  /** Sharing has started. */
  ZoomVideoSDKShareStatus_Start: 1,
  /** Sharing has been paused. */
  ZoomVideoSDKShareStatus_Pause: 2,
  /** Sharing has resumed after being paused. */
  ZoomVideoSDKShareStatus_Resume: 3,
  /** Sharing has been stopped. */
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
  ZoomVideoSDKSubscribeFailReason_HasSubscribeVideo1080POr720PAndOneShare: 5,
  ZoomVideoSDKSubscribeFailReason_TooFrequentCall: 6
}

/**
 * @alias ZoomVideoSDKRawDataType
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKRawDataType = {
  /** Raw video data. */
  RAW_DATA_TYPE_VIDEO: 0,
  /** Raw share data (e.g., screen or application). */
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
  /** Notification of joining the session. */
  onSessionJoin: 0,
  /** Notification of leaving the session with reason. */
  onSessionLeave: 1,
  /** Notification of errors occur when join session. */
  onError: 2,
  /** Notification of a user joins the session. */
  onUserJoin: 3,
  /** Notification of a user leaves the session. */
  onUserLeave: 4,
  /** Notification of a user makes changes to their video, such as starting or stopping their video. */
  onUserVideoStatusChanged: 5,
  /** Notification of a user makes changes to their audio, such as muting or unmuting their audio. */
  onUserAudioStatusChanged: 6,
  /** Notification of a user makes changes to their sharing status, such as starting screen sharing, starting view sharing, or stopping sharing. */
  onUserShareStatusChanged: 7,
  /** Notification of a user makes changes to their live stream status. */
  onLiveStreamStatusChanged: 8,
  /** Notification of receiving a chat message. */
  onChatNewMessageNotify: 9,
  /** Notification of the session host changes. */
  onUserHostChanged: 10,
  /** Notification of the active audio changes. */
  onUserActiveAudioChanged: 11,
  /** Notification of the session requires a password to join. */
  onSessionNeedPassword: 12,
  /** Notification of the provided session password is wrong or invalid. */
  onSessionPasswordWrong: 13,
  /** Initialize callback. */
  onInitialize: 14,
  /** Property change callback. */
  onPropertyChange: 15,
  /** Start send callback. */
  onStartSend: 16,
  /** Stop send callback. */
  onStopSend: 17,
  /** Uninitialized callback. */
  onUninitialized: 18,
  /** Raw data status changed callback. */
  onRawDataStatusChanged: 19,
  /** Notification of the manager of the session changes. */
  onUserManagerChanged: 20,
  /** Notification of user name changed. */
  onUserNameChanged: 21,
  /** Notification of receiving a message, data, or a command from the command channel. */
  onCommandReceived: 22,
  /** Notification of cloud recording status has paused, stopped, resumed, or otherwise changed. */
  onCloudRecordingStatus: 23,
  /** Notification of the current user is granted camera control access. */
  onCameraControlRequestResult: 24,
  /** Notification of the current user has received a camera control request. */
  onCameraControlRequestReceived: 25,
  /** Notification of the command channel is ready to be used. */
  onCommandChannelConnectResult: 26,
  /** Notification of a host requests you to unmute yourself. */
  onHostAskUnmute: 27,
  /** Notification of the invite by phone status changes to any other valid status such as Calling, Ringing, Success, or Failed. */
  onInviteByPhoneStatus: 28,
  /** Notification of someone in a given session enables or disables multi-camera. All participants in the session receive this callback. */
  onMultiCameraStreamStatusChanged: 29,
  /** Notification of the current mic or speaker volume changed. */
  onMicSpeakerVolumeChanged: 30,
  /** Notification of mic device or speaker device status changed. */
  onAudioDeviceStatusChanged: 31,
  /** Notification of the mic status changed when testing. */
  onTestMicStatusChanged: 32,
  /** Notification of the selected mic/speaker device is changed when testing. */
  onSelectedAudioDeviceChanged: 33,
  /** Notification of live transcription status changes. */
  onLiveTranscriptionStatus: 34,
  /** Live transcription message error callback. */
  onLiveTranscriptionMsgError: 36,
  /** Notification of a user deletes a chat message. */
  onChatMsgDeleteNotification: 37,
  /** Notification of a live transcription message is received. */
  onLiveTranscriptionMsgInfoReceived: 38,
  /** Notification of original language message received. */
  onOriginalLanguageMsgReceived: 39,
  /** Notification of the callout user successfully joins the meeting. */
  onCalloutJoinSuccess: 40,
  /** Remote control status callback. */
  onRemoteControlStatus: 42,
  /** Notification of the current user has received a remote control request. */
  onRemoteControlRequestReceived: 43,
  /** Callback after the first invocation of enableAdminRemoteControl(true). */
  onRemoteControlServiceInstallResult: 44,
  /** Notification of spotlighted video user changed. */
  onSpotlightVideoChanged: 45,
  /** Notification of the response that binding the incoming live stream. */
  onBindIncomingLiveStreamResponse: 46,
  /** Notification of the response that unbinding the incoming live stream. */
  onUnbindIncomingLiveStreamResponse: 47,
  /** Notification of the response that gets the streams status. */
  onIncomingLiveStreamStatusResponse: 48,
  /** Notification of the response that starts the bound stream. */
  onStartIncomingLiveStreamResponse: 49,
  /** Notification of the response that stops the bound stream. */
  onStopIncomingLiveStreamResponse: 50,
  /** Notification of a user failed to start sharing. */
  onFailedToStartShare: 51,
  /** Notification of the camera list has changed. */
  onCameraListChanged: 52,
  /** Notification of a user makes changes to their share content type, such as camera share switch to normal share. */
  onShareContentChanged: 53,
  /** Notification of the share content size has changed.
   * @note A share content size change may occur in two cases:
   *       when the first frame of shared content is received (from no content to having a size),
   *       or when the content size actually changes during sharing.
   */
  onShareContentSizeChanged: 54,
  /** Raw data received callback. */
  onCapturedRawDataReceived: 55,
  /** Receive this callback when call 'stopShare' successfully. */
  onCapturedShareStopped: 56,
  /** Notification of share setting changed. */
  onShareSettingChanged: 57,
  /** Notification of the current user's share network quality changes. */
  onShareNetworkStatusChanged: 58,
  /** Notification of the audio level changes for a participant (excluding self). */
  onAudioLevelChanged: 59,
  /** Notification of user's network status changes for a specific data type. */
  onUserNetworkStatusChanged: 60,
  /** Notification of user's overall network status changes. */
  onUserOverallNetworkStatusChanged: 61,
  /** Notification of the real-time media stream's status changed. */
  onRealTimeMediaStreamsStatus: 62,
  /** Notification of the real-time media stream failure reason. */
  onRealTimeMediaStreamsFail: 63,
  /** Notification of the list of unsharing windows has changed.
   * @note This callback is only supported on macOS.
   */
  onUnsharingWindowsChanged: 64
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
  /** Start recording on local computer or on cloud. */
  Recording_Start: 0,
  /** Stop recording on local computer or on cloud. */
  Recording_Stop: 1,
  /** There is no space to store for cloud recording. */
  Recording_DiskFull: 2,
  /** Pause recording on local or on cloud. */
  Recording_Pause: 3,
  /** 4, The recording is connecting. */
  Recording_Connecting: 4
};

/**
 * @alias ZoomVideoSDKCameraControlRequestType
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKCameraControlRequestType = {
  /** Request camera control. */
  ZoomVideoSDKCameraControlRequestType_RequestControl: 0,
  /** Give up camera control. */
  ZoomVideoSDKCameraControlRequestType_GiveUpControl: 1
};

/**
 * @alias ZoomVideoSDKRemoteControlStatus
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKRemoteControlStatus = {
  /** For initialization. */
  ZoomVideoSDKRemoteControlStatus_None: 0,
  /** Remote control information. I can enable the remote control. */
  ZoomVideoSDKRemoteControlStatus_CanRequestControl: 1,
  /** Remote control information. I have received a refused information of remote control. */
  ZoomVideoSDKRemoteControlStatus_RequestDenied: 2,
  /** The authority of remote control. I get control when remote control begins. */
  ZoomVideoSDKRemoteControlStatus_GotControl: 3,
  /** The authority of remote control. I lose control when remote control ends. */
  ZoomVideoSDKRemoteControlStatus_LostControl: 4,
  /** The status of remote control. I am remotely controlling another. */
  ZoomVideoSDKRemoteControlStatus_ControlStart: 5,
  /** The status of remote control. I am not remotely controlling another. */
  ZoomVideoSDKRemoteControlStatus_ControlStop: 6,
  /** The status of remote control. I can be controlled by the specified user. */
  ZoomVideoSDKRemoteControlStatus_GiveControlTo: 7,
  /** The status of remote control. I have revoked remote control. */
  ZoomVideoSDKRemoteControlStatus_ControlRevoked: 8,
  /** The status of remote control. I am being controlled by the specified user. */
  ZoomVideoSDKRemoteControlStatus_ControlledBy: 9,
  /** The status of remote control. I am not being controlled. */
  ZoomVideoSDKRemoteControlStatus_NotControlled: 10
};

/**
 * @alias PhoneStatus
 * @readonly
 * @enum {Number} Status of telephone.
*/
const PhoneStatus = {
  /** No status. */
  PhoneStatus_None: 0,
  /** In process of calling out. */
  PhoneStatus_Calling: 1,
  /** In process of ringing. */
  PhoneStatus_Ringing: 2,
  /** Accept the call. */
  PhoneStatus_Accepted: 3,
  /** Call successful. */
  PhoneStatus_Success: 4,
  /** Call failed. */
  PhoneStatus_Failed: 5,
  /** In process of canceling the response to the previous state. */
  PhoneStatus_Canceling: 6,
  /** Cancel successfully. */
  PhoneStatus_Canceled: 7,
  /** Cancel fails. */
  PhoneStatus_Cancel_Failed: 8,
  /** Timeout. */
  PhoneStatus_Timeout: 9
};

/**
 * @alias PhoneFailedReason
 * @readonly
 * @enum {Number} The reason for the failure of the telephone call.
*/
const PhoneFailedReason = {
  /** For initialization. */
  PhoneFailedReason_None: 0,
  /** The telephone service is busy. */
  PhoneFailedReason_Busy: 1,
  /** The telephone is out of the service. */
  PhoneFailedReason_Not_Available: 2,
  /** The user hangs up. */
  PhoneFailedReason_User_Hangup: 3,
  /** Other reasons. */
  PhoneFailedReason_Other_Fail: 4,
  /** The telephone does not reply. */
  PhoneFailedReason_No_Answer: 5,
  /** Disable the function of international call-out before the host joins the session. */
  PhoneFailedReason_Block_No_Host: 6,
  /** The call-out is blocked by the system due to the high cost. */
  PhoneFailedReason_Block_High_Rate: 7,
  /** All the invitees invited by the call should press the button one(1) to join the session. In case that many invitees do not press the button that leads to time out, the call invitation for this session shall be banned. */
  PhoneFailedReason_Block_Too_Frequent: 8
};

/**
 * @alias ZoomVideoSDKVideoPreferenceMode
 * @readonly
 * @enum {Number} video preference mode types. Here are more detailed structural descriptions.
*/
const ZoomVideoSDKVideoPreferenceMode = {
  /** Balance mode. */
  ZoomVideoSDKVideoPreferenceMode_Balance: 0,
  /** Sharpness mode. */
  ZoomVideoSDKVideoPreferenceMode_Sharpness: 1,
  /** Smoothness mode. */
  ZoomVideoSDKVideoPreferenceMode_Smoothness : 2,
  /** Custom mode. */
  ZoomVideoSDKVideoPreferenceMode_Custom : 3
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
  ZoomVideoSDKEchoCancellationLevel_Low: 1,
  ZoomVideoSDKEchoCancellationLevel_High: 2
}

/**
 * @alias ZoomVideoSDKMultiStreamStatus
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKMultiStreamStatus = {
  /** Current user only. This status is received when the current user starts the attempt to use multiple cameras in the session. */
  ZoomVideoSDKMultiCameraStreamStatus_JoinStart: 0,
  /** Current user only. This status is received when the current user fails the attempt to use multiple cameras in the session. */
  ZoomVideoSDKMultiCameraStreamStatus_JoinFail: 1,
  /** Broadcasted to all users. This status is received when a new camera has been successfully added to the session as the multiple cameras. */
  ZoomVideoSDKMultiCameraStreamStatus_Joined: 2,
  /** Broadcasted to all users. This status is received when a camera that is being used as the multiple cameras has left the session. */
  ZoomVideoSDKMultiCameraStreamStatus_Left: 3,
  /** Broadcast to all users. Sent when a multiple camera is started. */
  ZoomVideoSDKMultiCameraStreamStatus_VideoOn: 4,
  /** Broadcast to all users. Sent when a multiple camera is stopped. */
  ZoomVideoSDKMultiCameraStreamStatus_VideoOff: 5,
}

/**
 * @alias ZoomVideoSDKTestMicStatus
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKTestMicStatus = {
  /** Test the mic via TestMicStartRecording. It is useless to call TestMicStopTesting/TestMicPlayRecording in this status. */
  ZoomVideoSDKMic_CanTest: 0,
  /** Test the mic via TestMicStopTesting/TestMicPlayRecording. It is useless to call TestMicStartRecording in this status. */
  ZoomVideoSDKMic_Recording: 1,
  /** Test the mic via TestMicStopTesting/TestMicPlayRecording. It is useless call TestMicStartRecording in this status. */
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
  ZoomVideoSDK_Audio_Disconnect_As_Detected_Echo: 4,
  ZoomVideoSDK_Audio_Talk_While_Muted: 5
}

/**
 * @alias ZoomVideoSDKShareType
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKShareType = {
  /** No sharing type specified. */
  ZoomVideoSDKShareType_None: 0,
  /** Application or desktop sharing. */
  ZoomVideoSDKShareType_Normal: 1,
  /** Pure computer audio sharing. */
  ZoomVideoSDKShareType_PureAudio: 2,
  /** Camera sharing. */
  ZoomVideoSDKShareType_Camera: 3
}

/**
 * @alias ZoomVideoSDKShareCapturePauseReason
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKShareCapturePauseReason = {
  /** No pause reason; used for initialization. */
  ZoomVideoSDKShare_Capture_Pause_None: 0,
  /** Sharing is paused because the shared window is being moved. */
  ZoomVideoSDKShare_Capture_Pause_WindowMoving: 1,
  /** Sharing is paused because the shared window is covered by another window. */
  ZoomVideoSDKShare_Capture_Pause_WindowCovered: 2,
  /** Sharing is paused because the shared window is minimized. */
  ZoomVideoSDKShare_Capture_Pause_WindowMinimized: 3
}

/**
 * @alias ZoomVideoSDKVideoSourceDataMode
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKVideoSourceDataMode = {
  /** For general usage scenarios. */
  VideoSourceDataMode_None: 0,
  /** Special usage scenarios, each frame of video is organized around two images. */
  VideoSourceDataMode_Horizontal: 1,
  /** Special usage scenarios, each frame of video is two images organized up and down together. */
  VideoSourceDataMode_Vertical: 2
}

/**
 * @alias ZoomVideoSDKLiveTranscriptionStatus
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKLiveTranscriptionStatus = {
  /** not start */
  ZoomVideoSDKLiveTranscription_Status_Stop: 0,
  /** start */
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
  /** None. */
  ZoomVideoSDKChatDelete_None: 0,
  /** Indicates that the message was deleted by myself. */
  ZoomVideoSDKChatDelete_BySelf: 1,  
  /** Indicates that the message was deleted by the session host. */
  ZoomVideoSDKChatDelete_ByHost: 2,
  /** Indicates that the message was deleted by Data Loss Prevention (dlp). This happens when the message goes against the host organization's compliance policies. */
  ZoomVideoSDKChatDelete_ByDlp: 3
}

/**
 * @alias ZoomVideoSDKScreenCaptureMode
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKScreenCaptureMode = {
  /** Screen capture mode is automatically. */
  ZoomVideoSDKScreenCaptureMode_Auto: 0,
  /** Screen capture mode is legacy operating systems. */
  ZoomVideoSDKScreenCaptureMode_Legacy: 1,  
  /** Screen capture mode is capture with window filtering. */
  ZoomVideoSDKScreenCaptureMode_Filtering: 2,
  /** Screen capture mode is advanced share with window filtering. */
  ZoomVideoSDKScreenCaptureMode_ADA_Filtering: 3,
  /** Screen capture mode is advanced share without window filtering. */
  ZoomVideoSDKScreenCaptureMode_ADA_Without_Filtering: 4,
  /** Screen capture mode is secure share with window filtering. */
  ZoomVideoSDKScreenCaptureMode_Secure_Filtering: 5
}

/**
 * @alias ZoomVideoSDKSharePreprocessType
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKSharePreprocessType = {
  /** For initialization. */
  ZoomVideoSDKSharePreprocessType_none: 0,
  /** For share screen(monitor). */
  ZoomVideoSDKSharePreprocessType_screen: 1,  
  /** For share view(application window). */
  ZoomVideoSDKSharePreprocessType_view: 2,
  /** For share process(application), only for mac platform. */
  ZoomVideoSDKSharePreprocessType_process: 3
}

/**
 * @alias ZoomVideoSDKAnnotationToolType
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKAnnotationToolType = {
  ZoomVideoSDKAnnotationToolType_None: 0,
  ZoomVideoSDKAnnotationToolType_Pen: 1,
  ZoomVideoSDKAnnotationToolType_HighLighter: 2,
  ZoomVideoSDKAnnotationToolType_AutoLine: 3,
  ZoomVideoSDKAnnotationToolType_AutoRectangle: 4,
  ZoomVideoSDKAnnotationToolType_AutoEllipse: 5,
  ZoomVideoSDKAnnotationToolType_AutoArrow: 6,
  ZoomVideoSDKAnnotationToolType_AutoRectangleFill: 7,
  ZoomVideoSDKAnnotationToolType_AutoEllipseFill: 8,
  ZoomVideoSDKAnnotationToolType_SpotLight: 9,
  ZoomVideoSDKAnnotationToolType_Arrow: 10,
  ZoomVideoSDKAnnotationToolType_ERASER: 11,
  ZoomVideoSDKAnnotationToolType_Textbox: 12,
  ZoomVideoSDKAnnotationToolType_Picker: 13,
  ZoomVideoSDKAnnotationToolType_AutoRectangleSemiFill: 14,
  ZoomVideoSDKAnnotationToolType_AutoEllipseSemiFill: 15,
  ZoomVideoSDKAnnotationToolType_AutoDoubleArrow: 16,
  ZoomVideoSDKAnnotationToolType_AutoDiamond: 17,
  ZoomVideoSDKAnnotationToolType_AutoStampArrow: 18,
  ZoomVideoSDKAnnotationToolType_AutoStampCheck: 19,
  ZoomVideoSDKAnnotationToolType_AutoStampX: 20,
  ZoomVideoSDKAnnotationToolType_AutoStampStar: 21,
  ZoomVideoSDKAnnotationToolType_AutoStampHeart: 22,
  ZoomVideoSDKAnnotationToolType_AutoStampQm: 23,
  ZoomVideoSDKAnnotationToolType_VanishingPen: 24,
  ZoomVideoSDKAnnotationToolType_VanishingArrow: 25,
  ZoomVideoSDKAnnotationToolType_VanishingDoubleArrow: 26,
  ZoomVideoSDKAnnotationToolType_VanishingDiamond: 27,
  ZoomVideoSDKAnnotationToolType_VanishingEllipse: 28,
  ZoomVideoSDKAnnotationToolType_VanishingRectangle: 29
};

/**
 * @alias ZoomVideoSDKAnnotationClearType
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKAnnotationClearType = {
  /** Clear all annotations. */
  ZoomVideoSDKAnnotationClearType_All: 0,
  /** Clear only the others' annotations. */
  ZoomVideoSDKAnnotationClearType_Others: 1,
  /** Clear only your own annotations. */
  ZoomVideoSDKAnnotationClearType_My: 2,
}

/**
 * @alias ZoomVideoSDKDataType
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKDataType = {
  /** Unknown data type. */
  ZoomVideoSDKDataType_Unknown: 0,
  /** Audio data type. */
  ZoomVideoSDKDataType_Audio: 1,
  /** Video data type. */
  ZoomVideoSDKDataType_Video: 2,
  /** Share data type. */
  ZoomVideoSDKDataType_Share: 3
};

/**
 * @alias ZoomVideoSDKNetworkStatus
 * @readonly
 * @enum {Number}
*/
const ZoomVideoSDKNetworkStatus = {
  ZoomVideoSDKNetwork_None: 0,
  ZoomVideoSDKNetwork_Bad: 1,
  ZoomVideoSDKNetwork_Normal: 2,
  ZoomVideoSDKNetwork_Good: 3
}

/**
 * @alias RealTimeMediaStreamsStatus
 * @readonly
 * @enum {Number}
*/
const RealTimeMediaStreamsStatus = {
  /** No real-time media streams activity. */
  RealTimeMediaStreams_None: 0,
  /** Real-time media streams has started. */
  RealTimeMediaStreams_Start: 1,
  /** Real-time media streams has been paused. */
  RealTimeMediaStreams_Pause: 2,
  /** Real-time media streams has been stopped. */
  RealTimeMediaStreams_Stop: 3
}

/**
 * @alias RealTimeMediaStreamsFailReason
 * @readonly
 * @enum {Number}
*/
const RealTimeMediaStreamsFailReason = {
  /** Default value, no error (initial state) */
  RealTimeMediaStreamsFailReason_None: 0,
  /** No users have subscribed to the RTMS */
  RealTimeMediaStreamsFailReason_NoSubscription: 1,
  /** Failed to start the RTMS */
  RealTimeMediaStreamsFailReason_StartFail: 2
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
  ZoomVideoSDKShareCapturePauseReason,
  ZoomVideoSDKVideoSourceDataMode,
  ZoomVideoSDKLiveTranscriptionStatus,
  ZoomVideoSDKLiveTranscriptionOperationType,
  ZoomVideoSDKChatMessageDeleteType,
  ZoomVideoSDKScreenCaptureMode,
  ZoomVideoSDKSharePreprocessType,
  ZoomVideoSDKAnnotationToolType,
  ZoomVideoSDKAnnotationClearType,
  ZoomVideoSDKDataType,
  ZoomVideoSDKNetworkStatus,
  RealTimeMediaStreamsStatus,
  RealTimeMediaStreamsFailReason
}