/**
 * @file zoom_video_sdk_delegate_interface.h
 * @brief ZOOM Video SDK callback handler.
 */

#ifndef _ZOOM_VIDEO_SDK_DELEGATE_INTERFACE_H_
#define _ZOOM_VIDEO_SDK_DELEGATE_INTERFACE_H_
#include "zoom_video_sdk_def.h"
#include "zoom_video_sdk_vector_interface.h"
#include "helpers/zoom_video_sdk_phone_helper_interface.h"
#include "helpers/zoom_video_sdk_recording_helper_interface.h"
#include "helpers/zoom_video_sdk_audio_setting_interface.h"
#include "helpers/zoom_video_sdk_user_helper_interface.h"
#include "helpers/zoom_video_sdk_video_helper_interface.h"
#include "helpers/zoom_video_sdk_audio_helper_interface.h"
#include "helpers/zoom_video_sdk_share_helper_interface.h"
#include "helpers/zoom_video_sdk_livestream_helper_interface.h"
#include "helpers/zoom_video_sdk_livetranscription_helper_interface.h"
#include "helpers/zoom_video_sdk_chat_helper_interface.h"
#include "helpers/zoom_video_sdk_network_connection_helper_interface.h"
#include "helpers/zoom_video_sdk_crc_helper_interface.h"
#include "helpers/zoom_video_sdk_subsession_interface.h"
#include "helpers/zoom_video_sdk_broadcast_streaming_controller_interface.h"
#include "helpers/zoom_video_sdk_broadcast_streaming_viewer_interface.h"
#include "helpers/zoom_video_sdk_whiteboard_helper_interface.h"
#if !defined (__linux) || defined ANDROID
#include "helpers/zoom_video_sdk_rtms_helper_interface.h"
#endif
BEGIN_ZOOM_VIDEO_SDK_NAMESPACE
class IZoomVideoSDKChatMessage;
class IZoomVideoSDKPasswordHandler;
class IZoomVideoSDKRecordingConsentHandler;
class IZoomVideoSDKCameraControlRequestHandler;
class IZoomVideoSDKRemoteControlRequestHandler;
/**
 * @class IZoomVideoSDKDelegate
 * @brief A listener class that groups together the callbacks related to a session.
 */
class IZoomVideoSDKDelegate
{
public:
    /**
	 * @brief Notification of joining the session.
	 */
    virtual void onSessionJoin() = 0;
    
    /**
	 * @brief Notification of leaving the session.
	 * @deprecated This interface is marked as deprecated. Use \link onSessionLeave(ZoomVideoSDKSessionLeaveReason eReason) \endlink instead.
	 */
    virtual void onSessionLeave() = 0;
    
    /**
	 * @brief Notification of leaving the session with reason.
	 * @param eReason.
	 */
    virtual void onSessionLeave(ZoomVideoSDKSessionLeaveReason eReason) = 0;
    
    /**
	 * @brief Notification of errors occur when join session.
	 * @param errorCode.
	 * @param detailErrorCode Detailed errorCode.
	 */
    virtual void onError(ZoomVideoSDKErrors errorCode, int detailErrorCode) = 0;
	
    /**
	 * @brief Notification of a user joins the session.
	 * @param pUserHelper User helper utility.
	 * @param userList List of users who have just joined the session.
	 */
	virtual void onUserJoin(IZoomVideoSDKUserHelper* pUserHelper, IVideoSDKVector<IZoomVideoSDKUser*>* userList) = 0;
	
    /**
	 * @brief Notification of a user leaves the session
	 * @param pUserHelper User helper utility.
	 * @param userList List of users who have just left the session.
	 */
	virtual void onUserLeave(IZoomVideoSDKUserHelper* pUserHelper, IVideoSDKVector<IZoomVideoSDKUser*>* userList) = 0;
	
    /**
	 * @brief Notification of a user makes changes to their video, such as starting or stopping their video.
	 * @param pVideoHelper The pointer to video helper object.
	 * @param userList The pointer to user object list.
	 */
	virtual void onUserVideoStatusChanged(IZoomVideoSDKVideoHelper* pVideoHelper, IVideoSDKVector<IZoomVideoSDKUser*>* userList) = 0;
	
    /**
	 * @brief Notification of a user makes changes to their audio, such as muting or unmuting their audio.
	 * @param pAudioHelper The pointer to audio helper object.
	 * @param userList The pointer to user object list.
	 */
	virtual void onUserAudioStatusChanged(IZoomVideoSDKAudioHelper* pAudioHelper, IVideoSDKVector<IZoomVideoSDKUser*>* userList) = 0;
	
    /**
	 * @brief Notification of a user makes changes to their sharing status, such as starting screen sharing, starting view sharing, or stopping sharing.
	 * @param pShareHelper The pointer to share helper object.
	 * @param pUser The pointer to user object.
	 * @param IZoomVideoSDKShareAction The pointer to share object.	
	 */
	virtual void onUserShareStatusChanged(IZoomVideoSDKShareHelper* pShareHelper, IZoomVideoSDKUser* pUser, IZoomVideoSDKShareAction* pShareAction) = 0;

    /**
	 * @brief Notification of a user makes changes to their share content type, such as camera share switch to normal share. The share type can be found in \link ZoomVideoSDKShareType \endlink.
	 * @param pShareHelper The pointer to share helper object.
	 * @param pUser The pointer to user object.
	 * @param IZoomVideoSDKShareAction The pointer to share object.
	 */
	virtual void onShareContentChanged(IZoomVideoSDKShareHelper* pShareHelper, IZoomVideoSDKUser* pUser, IZoomVideoSDKShareAction* pShareAction) = 0;

    /**
     * @brief Notification of a user failed to start sharing.
     * @param pShareHelper The pointer to share helper object.
     * @param pUser The pointer to user object.
	 */
    virtual void onFailedToStartShare(IZoomVideoSDKShareHelper* pShareHelper, IZoomVideoSDKUser* pUser) = 0;
    
    /**
     * @brief Notification of share setting changed.
     * @param setting The share setting.
     */
    virtual void onShareSettingChanged(ZoomVideoSDKShareSetting setting) = 0;
    
    /**
	 * @brief Notification of a user consents to individual recording.
	 * @param pUser The pointer to user object.
	 */
	virtual void onUserRecordingConsent(IZoomVideoSDKUser* pUser) = 0;
	
    /**
	 * @brief Notification of a user makes changes to their live stream status.
	 * @param pLiveStreamHelper The pointer to live stream helper object.
	 * @param status The current status of live stream.
	 */
    virtual void onLiveStreamStatusChanged(IZoomVideoSDKLiveStreamHelper* pLiveStreamHelper, ZoomVideoSDKLiveStreamStatus status) = 0;
	
    /**
	 * @brief Notification of receiving a chat message.
	 * @param pChatHelper The pointer to chat helper object.
	 * @param messageItem The pointer to message object.
	 */
    virtual void onChatNewMessageNotify(IZoomVideoSDKChatHelper* pChatHelper, IZoomVideoSDKChatMessage* messageItem) = 0;
	
    /**
	 * @brief Notification of the session host changes.
	 * @param pUserHelper The pointer to user helper object.
	 * @param pUser The pointer to user object.
	 */
	virtual void onUserHostChanged(IZoomVideoSDKUserHelper* pUserHelper, IZoomVideoSDKUser* pUser) = 0;
	
    /**
	 * @brief Notification of the active audio changes.
	 * @param pAudioHelper Audio helper utility.
	 * @param list Active audio list.
	 */
	virtual void onUserActiveAudioChanged(IZoomVideoSDKAudioHelper* pAudioHelper, IVideoSDKVector<IZoomVideoSDKUser*>* list) = 0;
	
    /**
	 * @brief Notification of the session requires a password to join.
	 * @param handler The pointer to password handler object.
	 */
    virtual void onSessionNeedPassword(IZoomVideoSDKPasswordHandler* handler) = 0;
	
    /**
	 * @brief Notification of the provided session password is wrong or invalid.
	 * @param handler The pointer to password handler object.
	 */
    virtual void onSessionPasswordWrong(IZoomVideoSDKPasswordHandler* handler) = 0;
	
    /**
	 * @brief Notification of mixed (all users) audio raw data received 
	 * @param data_ The pointer to audio raw data.
	 */
	virtual void onMixedAudioRawDataReceived(AudioRawData* data_) = 0;

    /**
	 * @brief Notification of individual user's audio raw data received
	 * @param data_ Raw audio data.
	 * @param pUser The pointer to user object associated with the raw audio data.
	 */
	virtual void onOneWayAudioRawDataReceived(AudioRawData* data_, IZoomVideoSDKUser* pUser) = 0;

    /**
	 * @brief Notification of receiving shared raw audio data.
	 * @param data_ Raw audio data. 
	 */
	virtual void onSharedAudioRawDataReceived(AudioRawData* data_) = 0;
	
    /**
	 * @brief Notification of the manager of the session changes.
	 * @param pUser The pointer to user object.
	 */
	virtual void onUserManagerChanged(IZoomVideoSDKUser* pUser) = 0;
	
    /**
	 * @brief Notification of user name changed.
	 * @param pUser The pointer to user object.
	 */
	virtual void onUserNameChanged(IZoomVideoSDKUser* pUser) = 0;

    /**
	 * @brief Notification of the current user is granted camera control access.
	 * @note Once the current user sends the camera control request, this callback will be triggered with the result of the request.
	 * @param pUser The pointer to the user who received the request.
	 * @param isApproved The result of the camera control request
	 */
	virtual void onCameraControlRequestResult(IZoomVideoSDKUser* pUser, bool isApproved) = 0;

    /**
	 * @brief Notification of the current user has received a camera control request.
	 * @note This will be triggered when another user requests control of the current user's camera.
	 * @param pUser The pointer to the user who sent the request.
	 * @param requestType The request type.
	 * @param pCameraControlRequestHandler The pointer to the helper instance of the camera controller.
	 */
	virtual void onCameraControlRequestReceived(IZoomVideoSDKUser* pUser, 
		ZoomVideoSDKCameraControlRequestType requestType, 
		IZoomVideoSDKCameraControlRequestHandler* pCameraControlRequestHandler) = 0;

#if defined(WIN32) || defined(__MACOS__)
    /**
	 * @brief Notification of the remote control status changes. 
	 * @param pUser The remote control user.
	 * @param pShareAction The pointer to share object.
	 * @param status The value of remote control status.
	 */
	virtual void onRemoteControlStatus(IZoomVideoSDKUser* pUser, IZoomVideoSDKShareAction* pShareAction, ZoomVideoSDKRemoteControlStatus status) = 0;

    /**
	 * @brief Notification of the current user has received a remote control request.
	 * @note This will be triggered when another user requests control of the current user's screen.
	 * @param pShareAction The pointer to share object.	
	 * @param pUser The pointer to the user who sent the request.
	 * @param pRemoteControlRequestHandler The pointer to the helper instance of the remote controller.
	 */
	virtual void onRemoteControlRequestReceived(IZoomVideoSDKUser* pUser, IZoomVideoSDKShareAction* pShareAction,
		IZoomVideoSDKRemoteControlRequestHandler* pRemoteControlRequestHandler) = 0;
#endif

#if defined(WIN32)
    /**
	 * @brief Callback after the first invocation of IZoomVideoSDKShareSettingHelper::enableAdminRemoteControl(true).
	 * @param bSuccess The installation result of the remote control service.
	 */
	virtual void onRemoteControlServiceInstallResult(bool bSuccess) = 0;
#endif
	
    /**
	 * @brief Notification of receiving a message, data, or a command from the command channel. 
	 * @note Once the command channel is active, this callback is triggered each time a message is received.
	 * @param pSender The user who sent the command.
	 * @param strCmd Received command.
	 */
	virtual void onCommandReceived(IZoomVideoSDKUser* sender, const zchar_t* strCmd) = 0;

    /**
	 * @brief Notification of the command channel is ready to be used.
	 * @note When the SDK attempts to establish a connection for the command channel when joining a session.
	 * This callback is triggered once the connection attempt for the command channel is completed.
	 * @param isSuccess true: success, command channel is ready to be used.
	 * false: Failure, command channel was unable to connect.
	 */
	virtual void onCommandChannelConnectResult(bool isSuccess) = 0;
	
    /**
	 * @brief Notification of the invite by phone status changes to any other valid status such as Calling, Ringing, Success, or Failed.
	 * @param status Invite by phone status.
	 * @param reason IInvite by phone failed reason.
	 */
	virtual void onInviteByPhoneStatus(PhoneStatus status, PhoneFailedReason reason) = 0;

    /**
	 * @brief Notification of the callout user successfully joins the meeting.
     * @param pUser The invited user who joined the meeting.
     * @param phoneNumber The phone number involved in the callout.
	 */
	virtual void onCalloutJoinSuccess(IZoomVideoSDKUser* pUser, const zchar_t* phoneNumber) = 0;

    /**
	 * @brief Notification of cloud recording status has paused, stopped, resumed, or otherwise changed.
	 * @param status Cloud recording status.
	 * @param pHandler When the cloud recording starts, this object is used to let the user choose whether to accept or not.
	 */
	virtual void onCloudRecordingStatus(RecordingStatus status, IZoomVideoSDKRecordingConsentHandler* pHandler) = 0;

    /**
	 * @brief Notification of a host requests you to unmute yourself.
	 */
	virtual void onHostAskUnmute() = 0;

    /**
	 * @brief Notification of someone in a given session enables or disables multi-camera. All participants in the session receive this callback.
	 * @param status. 
	 * @param pUser The user who enabled multi-camera. 
	 * @param pVideoPipe The data pipe for the multi-camera.
     */
	virtual void onMultiCameraStreamStatusChanged(ZoomVideoSDKMultiCameraStreamStatus status, IZoomVideoSDKUser* pUser, IZoomVideoSDKRawDataPipe* pVideoPipe) = 0;

    /**
	 * @brief Notification of the current mic or speaker volume changed.
	 * @param micVolume Specify the volume of the mic when testing or in session.
	 * @param speakerVolume Specify the volume of the speaker when testing.
	 */
	virtual void onMicSpeakerVolumeChanged(unsigned int micVolume, unsigned int speakerVolume) = 0;

    /**
     * @brief Notification of the audio level changes for a participant (excluding self).
     * @param level The current audio level of the user, in the range [0, 9].
     * @param bAudioSharing true if the audio level is from shared audio, such as computer audio; otherwise it's from the microphone.
     * @param pUser The user whose audio level has changed.
     */
    virtual void onAudioLevelChanged(unsigned int level, bool bAudioSharing, IZoomVideoSDKUser* pUser) = 0;
    
    /**
	 * @brief Notification of mic device or speaker device status changed.
	 * @param type. 
	 * @param status. 
	 */
	virtual void onAudioDeviceStatusChanged(ZoomVideoSDKAudioDeviceType type, ZoomVideoSDKAudioDeviceStatus status) = 0;

    /**
	 * @brief Notification of the mic status changed when testing.
	 * @param status The mic status.
	 * @note The enuCanPlay status indicates that the SDK has recorded the microphone sound for the longest time (6 seconds).customers can decide for themselves whether to stop test mic or play microphone sound.
	 */
	virtual void onTestMicStatusChanged(ZoomVideoSDK_TESTMIC_STATUS status) = 0;

    /**
	 * @brief Notification of the selected mic/speaker device is changed when testing. Then the SDK will close the mic/speaker testing. The user shall restart the test manually if he still wants to test.
	 */
	virtual void onSelectedAudioDeviceChanged() = 0;
    
    /**
     * @brief Notification of the camera list has changed.
	 */
    virtual void onCameraListChanged() = 0;

    /**
	 * @brief Notification of live transcription status changes.
	 * @param status The live transcription status.
	 */
	virtual void onLiveTranscriptionStatus(ZoomVideoSDKLiveTranscriptionStatus status) = 0;

    /**
	 * @brief Notification of original language message received.
	 * @param messageInfo The spoken language message.
	 */
	virtual void onOriginalLanguageMsgReceived(ILiveTranscriptionMessageInfo* messageInfo) = 0;

    /**
	 * @brief Notification of a live transcription message is received.	
	 * @param messageInfo The live transcription message. 
	 */
	virtual void onLiveTranscriptionMsgInfoReceived(ILiveTranscriptionMessageInfo* messageInfo) = 0;

    /**
	 * @brief Notification of a live translation error occurs.
	 * @param spokenLanguage The spoken message language. 
	 * @param transcriptLanguage The message language you want to translate.
	 */
	virtual void onLiveTranscriptionMsgError(ILiveTranscriptionLanguage* spokenLanguage, ILiveTranscriptionLanguage* transcriptLanguage) = 0;

	/**
	 * @brief Notification of the spoken language has changed.
	 * @param spokenLanguage The spoken message language.
	 */
	virtual void onSpokenLanguageChanged(ILiveTranscriptionLanguage* spokenLanguage) = 0;

    /**
	 * @brief Notification of a user deletes a chat message.
	 * @param pChatHelper Chat helper utility.
	 * @param MsgID The deleted message's ID.
	 * @param deleteBy Indicates by whom the message was deleted.
	 */
	virtual void onChatMsgDeleteNotification(IZoomVideoSDKChatHelper* pChatHelper, const zchar_t* msgID, ZoomVideoSDKChatMessageDeleteType deleteBy) = 0;

    /**
	 * @brief Notification of the chat privilege of participant has changed.
	 * @param pChatHelper The pointer to chat helper object.
	 * @param privilege The new chat privilege.
	 */
	virtual void onChatPrivilegeChanged(IZoomVideoSDKChatHelper* pChatHelper, ZoomVideoSDKChatPrivilegeType privilege) = 0;

    /**
	 * @brief Notification of send file status make change
	 * @param file The pointer to send file object.
	 * @param status The status of file transfer.
	 */
	virtual void onSendFileStatus(IZoomVideoSDKSendFile* file, const FileTransferStatus& status) = 0;

    /**
	 * @brief Notification of receive file status changed.
	 * @param file The pointer to receive file object.
	 * @param status The status of file transfer.
	 */
	virtual void onReceiveFileStatus(IZoomVideoSDKReceiveFile* file, const FileTransferStatus& status) = 0;

    /**
	 * @brief Notification of completing the proxy detection.
	 */
	virtual void onProxyDetectComplete() = 0;

    /**
	 * @brief Notification of the proxy requests to input the username and password.
	 * @note Use the handler to configure the related information.  
	 * @param handler The pointer to the IZoomVideoSDKProxySettingHandler.
	 */
	virtual void onProxySettingNotification(IZoomVideoSDKProxySettingHandler* handler) = 0;

    /**
	 * @brief Notification of the SSL verified fail.
	 * @param info The info of SSL certificate related information.
	 */
	virtual void onSSLCertVerifiedFailNotification(IZoomVideoSDKSSLCertificateInfo* info) = 0;

    /**
	 * @brief Notification of the user's video network quality changes.
	 * @param status video network quality.
	 * @param pUser The pointer to a user object. 	
     * @deprecated This interface is marked as deprecated. Use \link onUserNetworkStatusChanged(ZoomVideoSDKDataType type, ZoomVideoSDKNetworkStatus level, IZoomVideoSDKUser *pUser) \endlink instead.
	 */
	virtual void onUserVideoNetworkStatusChanged(ZoomVideoSDKNetworkStatus status, IZoomVideoSDKUser* pUser) = 0;

	/**
	 * @brief Notification of the current user's share network quality changes.
	 * @param shareNetworkStatus share network quality.
	 * @param isSendingShare Indicates the direction of the share. If true, it refers to the sending share; if false, it refers to the receiving share.
     * @deprecated This interface is marked as deprecated. Use \link onUserNetworkStatusChanged(ZoomVideoSDKDataType type, ZoomVideoSDKNetworkStatus level, IZoomVideoSDKUser *pUser) \endlink instead.
	 */
	virtual void onShareNetworkStatusChanged(ZoomVideoSDKNetworkStatus shareNetworkStatus, bool isSendingShare) = 0;

    /**
     * @brief Notification of user's network status changes for a specific data type.
     * @param type The data type whose network status changed.
     * @param level The new network quality level for the specified data type.
     * @param pUser The user whose network status has changed.
     */
    virtual void onUserNetworkStatusChanged(ZoomVideoSDKDataType type, ZoomVideoSDKNetworkStatus level, IZoomVideoSDKUser *pUser) = 0;
    
    /**
     * @brief Notification of user's overall network status changes.
     * @param level The new overall network quality level.
     * @param pUser The user whose overall network status has changed.
     */
    virtual void onUserOverallNetworkStatusChanged(ZoomVideoSDKNetworkStatus level, IZoomVideoSDKUser *pUser) = 0;
    
    /**
	 * @brief Notification of the call CRC device's status changed.
	 * @param status The call status.
	 */
	virtual void onCallCRCDeviceStatusChanged(ZoomVideoSDKCRCCallStatus status) = 0;

#if !defined __linux
    /**
	 * @brief Notification of the subscribed user's video failure reason.
	 * @param fail_reason The user's video subscribe failure reason.
	 * @param pUser The pointer to a user object.  
	 * @param handle The window handle that failed to subscribe.
	 */
	virtual void onVideoCanvasSubscribeFail(ZoomVideoSDKSubscribeFailReason fail_reason, IZoomVideoSDKUser* pUser, void* handle) = 0;

    /**
	 * @brief Notification of the subscribed user's share view failure reason.
	 * @param pUser The pointer to a user object.  
	 * @param handle The window handle that failed to subscribe.
	 * @param IZoomVideoSDKShareAction The pointer to share object.
	 */
	virtual void onShareCanvasSubscribeFail(IZoomVideoSDKUser* pUser, void* handle, IZoomVideoSDKShareAction* pShareAction) = 0;
#endif
    
    /**
	 * @brief Notification of the annotation helper clean up.
	 * @param helper The clean up object.
	 * @note After this callback, SDK will release the ZoomVideoSDKAnnotationHelper as well.
	 */
	virtual void onAnnotationHelperCleanUp(IZoomVideoSDKAnnotationHelper* helper) = 0;

    /**
	 * @brief Notification of the annotation privilege change.	
	 * @param pUser The pointer to a user object. 
	 * @param IZoomVideoSDKShareAction The pointer to share object.	
	 */
	virtual void onAnnotationPrivilegeChange(IZoomVideoSDKUser* pUser, IZoomVideoSDKShareAction* pShareAction) = 0;
	
    /**
	 * @brief Notification of the annotation helper activated. Notify that annotation windows have been created.	
	 * @param handle The window handle that annotating.
	 */
	virtual void onAnnotationHelperActived(void* handle) = 0;

    /**
	 * @brief Notification of video alpha channel mode changed.
	 * @param isAlphaModeOn Indicates the state of the alpha channel mode. If true, it is enabled; if false, it is disabled.
	 */
	virtual void onVideoAlphaChannelStatusChanged(bool isAlphaModeOn) = 0;

    /**
	 * @brief Notification of spotlighted video user changed.
	 * @param pVideoHelper The pointer to video helper object.
	 * @param userList List of users who has been spotlighted.
	 */
	virtual void onSpotlightVideoChanged(IZoomVideoSDKVideoHelper* pVideoHelper, IVideoSDKVector<IZoomVideoSDKUser*>* userList) = 0;

    /**
	 * @brief Notification of the response that binding the incoming live stream.
	 * @param bSuccess true: success, otherwise false.
	 * @param strStreamKeyID Corresponding stream key ID.
	 */
	virtual void onBindIncomingLiveStreamResponse(bool bSuccess, const zchar_t* strStreamKeyID) = 0;

    /**
	 * @brief Notification of the response that unbinding the incoming live stream.
	 * @param bSuccess true: success, otherwise false.
	 * @param strStreamKeyID Corresponding stream key ID.
	 */
	virtual void onUnbindIncomingLiveStreamResponse(bool bSuccess, const zchar_t* strStreamKeyID) = 0;

    /**
	 * @brief Notification of the response that gets the streams status.
	 * @param bSuccess true: success, otherwise false.
	 * @param pStreamsStatusList The streams status list.
	 */
	virtual void onIncomingLiveStreamStatusResponse(bool bSuccess, IVideoSDKVector<IncomingLiveStreamStatus>* pStreamsStatusList) = 0;

    /**
	 * @brief Notification of the response that starts the bound stream.
	 * @param bSuccess true: success, otherwise false.
	 * @param strStreamKeyID Corresponding stream key ID.
	 */
	virtual void onStartIncomingLiveStreamResponse(bool bSuccess, const zchar_t* strStreamKeyID) = 0;

    /**
	 * @brief Notification of the response that stops the bound stream.
	 * @param bSuccess true: success, otherwise false.
	 * @param strStreamKeyID Corresponding stream key ID.
	 */
	virtual void onStopIncomingLiveStreamResponse(bool bSuccess, const zchar_t* strStreamKeyID) = 0;
    
    /**
	 * @brief Notification of the share content size has changed.
     * @param pShareHelper The pointer to the share helper object.
     * @param pUser The pointer to a user object.
     * @param pShareAction The pointer to the share object.
     * @note A share content size change may occur in two cases: 
     *       when the first frame of shared content is received (from no content to having a size), 
     *       or when the content size actually changes during sharing.
     */
    virtual void onShareContentSizeChanged(IZoomVideoSDKShareHelper* pShareHelper, IZoomVideoSDKUser* pUser, IZoomVideoSDKShareAction* pShareAction) = 0;

    /**
     * @brief Notification of the list of unsharing windows changes.
     * @param windowsList A list of window handles (`void*`) representing the windows that are not being shared.
     * @param pShareHelper The pointer to the share helper object.
     * @param pUser The user who is sharing.
     * @param pShareAction The pointer to a ZMVideoSDKShareAction object.
     * @note This callback is only supported on macOS.
     */
    virtual void onUnsharingWindowsChanged(IVideoSDKVector<void*>* windowsList, IZoomVideoSDKShareHelper* pShareHelper, IZoomVideoSDKUser* pUser, IZoomVideoSDKShareAction* pShareAction) = 0;
    
    /**
	 * @brief Notification of the subsession status changed.
	 * @param status The subsession status.
	 * @param pSubSessionKitList The new subsession list.
	 */
	virtual void onSubSessionStatusChanged(ZoomVideoSDKSubSessionStatus status, IVideoSDKVector<ISubSessionKit*>* pSubSessionKitList) = 0;

    /**
	 * @brief Notification of the user has subsession manager privilege.
	 * @param pManager The subsession manager object.
	 */
	virtual void onSubSessionManagerHandle(IZoomVideoSDKSubSessionManager* pManager) = 0;

    /**
	 * @brief Notification of a user gains or loses subsession participant privileges.
	 * @param  pParticipant The subsession participant object, when the user loses participant privileges, pParticipant is NULL.
     */
	virtual void onSubSessionParticipantHandle(IZoomVideoSDKSubSessionParticipant* pParticipant) = 0;

    /**
	 * @brief Notification of the subsession users are updated..
	 * @param pSubSessionKit The subsession kit object.
	 */
	virtual void onSubSessionUsersUpdate(ISubSessionKit* pSubSessionKit) = 0;

    /**
	 * @brief Notification of the user receives a main session broadcast message.
	 * @param sMessage The message content.
	 * @param sUserName The name of the user who broadcasted this message.
	 */
	virtual void onBroadcastMessageFromMainSession(const zchar_t* sMessage, const zchar_t* sUserName) = 0;

    /**
	 * @brief Notification of the user receives a help request from a subsession.
	 * @param pHandler The request handler object.
	 */
	virtual void onSubSessionUserHelpRequest(ISubSessionUserHelpRequestHandler* pHandler) = 0;

    /**
	 * @brief Notification of the result of the help request.
	 * @param eResult The result of help request.
	 */
	virtual void onSubSessionUserHelpRequestResult(ZoomVideoSDKUserHelpRequestResult eResult) = 0;

	/**
	* @brief Notification the response of starting broadcast streaming.
	* @param bSuccess true if broadcast streaming started successfully; otherwise false.
	* @param channelID This broadcast streaming channel ID returned by the backend.
	*/
	virtual void onStartBroadcastResponse(bool bSuccess, const zchar_t* channelID) = 0;

	/**
	* @brief Notification the response of stopping broadcast streaming.
	* @param bSuccess true if broadcast stopped successfully; otherwise false.
	*/
	virtual void onStopBroadcastResponse(bool bSuccess) = 0;
	
	/**
	* @brief Notification the response of getting broadcast status.
	* @param bSuccess true if the request succeeded; otherwise false.
	* @param status The current broadcast status, see \link ZoomVideoSDKBroadcastControlStatus \endlink.
	*/
	virtual void onGetBroadcastControlStatus(bool bSuccess, ZoomVideoSDKBroadcastControlStatus status) = 0;

	/**
	* @brief Notification when the viewer's join status changes.
	* @param status The current join status. See \link ZoomVideoSDKStreamingJoinStatus \endlink.
	*/
	virtual void onStreamingJoinStatusChanged(ZoomVideoSDKStreamingJoinStatus status) = 0;

#if !defined (__linux) || defined ANDROID
	/**
	 * @brief Callback invoked when a whiteboard file export completes.
	 * @param format The export format. See \link ZoomVideoSDKExportFormat \endlink.
	 * @param data The export whiteboard data as a byte array.
	 * @param length The length of the export whiteboard data.
	 */
	virtual void onWhiteboardExported(ZoomVideoSDKExportFormat format, unsigned char* data, long length) = 0;



	/**
	 * @brief Callback invoked when a user changes their whiteboard sharing status, such as starting or stopping whiteboard sharing.
	 * @param pUser The user who's whiteboard sharing status changed. Check the current status via \link IZoomVideoSDKUser \endlink. 
	 * @param pWhiteboardHelper The whiteboard helper object.
	 */
	virtual void onUserWhiteboardShareStatusChanged(IZoomVideoSDKUser* pUser, IZoomVideoSDKWhiteboardHelper* pWhiteboardHelper) = 0;

	/**
	 * @brief Notification of the real-time media stream's status changed.
	 * @param status The real-time media streams status. For more details, see \link RealTimeMediaStreamsStatus \endlink enum.
	 */
	virtual void onRealTimeMediaStreamsStatus(RealTimeMediaStreamsStatus status) = 0;

	/**
	 * @brief Notification of the real-time media stream failure reason.
	 * @param failReason The real-time media stream failure reason.
	 */
	virtual void onRealTimeMediaStreamsFail(RealTimeMediaStreamsFailReason failReason) = 0;
#endif
};
END_ZOOM_VIDEO_SDK_NAMESPACE
#endif
