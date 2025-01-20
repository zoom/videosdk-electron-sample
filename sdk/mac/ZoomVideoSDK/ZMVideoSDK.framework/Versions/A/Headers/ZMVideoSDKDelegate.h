//
//  ZMVideoSDKDelegate.h
//  ZMVideoSDK
//
#import <AppKit/AppKit.h>
#import <ZMVideoSDK/ZMVideoSDKDef.h>

NS_ASSUME_NONNULL_BEGIN
@class ZMVideoSDKUserHelper;
@class ZMVideoSDKVideoHelper;
@class ZMVideoSDKAudioHelper;
@class ZMVideoSDKShareHelper;
@class ZMVideoSDKLiveStreamHelper;
@class ZMVideoSDKChatHelper;
@class ZMVideoSDKAudioRawData;
@class ZMVideoSDKUser;
@class ZMVideoSDKChatMessage;
@class ZMVideoSDKPasswordHandler;
@class ZMVideoSDKCameraControlRequestHandler;
@class ZMVideoSDKRawDataPipe;
@class ZMVideoSDKLiveTranscriptionLanguage;
@class ZMVideoSDKSSLCertificateInfo;
@class ZMVideoSDKProxySettingHandler;
@class ZMVideoSDKRecordingConsentHandler;
@class ZMVideoSDKLiveTranscriptionMessageInfo;
@class ZMVideoSDKAnnotationHelper;
@class ZMVideoSDKVideoCanvas;
@class ZMVideoSDKSendFile;
@class ZMVideoSDKReceiveFile;
@class ZMVideoSDKRemoteControlRequestHandler;
@class ZMVideoSDKShareAction;


/**
 @brief A listener class that groups together the callbacks related to a session.
 */
@protocol ZMVideoSDKDelegate <NSObject>
@optional
    
/**
 @brief Callback: Invoked when the current user joins the session.
 */
- (void)onSessionJoin;
    
/**
 @brief Callback: Invoked when the current user leaves the session.
 */
- (void)onSessionLeave DEPRECATED_MSG_ATTRIBUTE("Use -onSessionLeave: instead");

/**
 @brief Invoked when the current user leaves the session with reason.
 @param reason For more details, see {@link ZMVideoSDKSessionLeaveReason}
 */
- (void)onSessionLeave:(ZMVideoSDKSessionLeaveReason)reason;

/**
 @brief Callback: Invoked when errors occur.
 @param ErrorType Provides error code associated with the error. See {@link ZMVideoSDKErrors} for more information.
 @param details Detailed errorCode.
 */
- (void)onError:(ZMVideoSDKErrors)ErrorType detail:(int)details;
    
/**
 @brief Callback: Invoked when a user joins the session.
 @param userHelper User help utility.
 @param userArray List of users who have just joined the session.
 */
- (void)onUserJoin:(ZMVideoSDKUserHelper* _Nonnull)userHelper userList:(NSArray<ZMVideoSDKUser *>* _Nullable)userArray;
    
/**
 @brief Triggered when other users leave session.
 @param userHelper The pointer of user helper object.
 @param userArray An array contains the users leaved.
 */
- (void)onUserLeave:(ZMVideoSDKUserHelper* _Nonnull)userHelper userList:(NSArray<ZMVideoSDKUser *>* _Nullable)userArray;
    
/**
 @brief Callback: Invoked when a user makes changes to their video, such as starting or stopping their video.
 @param videoHelper The pointer of video helper object.
 @param userArray The array contain user objoct.
 */
- (void)onUserVideoStatusChanged:(ZMVideoSDKVideoHelper* _Nonnull)videoHelper userList:(NSArray<ZMVideoSDKUser *>* _Nullable)userArray;
    
/**
 @brief Callback: Invoked when a user makes changes to their audio, such as muting or unmuting their audio.
 @param audioHelper The pointer of audio helper object.
 @param userArray The array contain user objoct.
 */
- (void)onUserAudioStatusChanged:(ZMVideoSDKAudioHelper* _Nonnull)audioHelper userList:(NSArray<ZMVideoSDKUser *>* _Nullable)userArray;
    
/**
 @brief Invoked when a user makes changes to their sharing status, such as starting screen sharing, starting view sharing, or stopping sharing.
 @param shareHelper The pointer to a share helper object, see {@link ZMVideoSDKShareHelper}.
 @param user The pointer to a user object.
 @param shareAction The pointer to a ZMVideoSDKShareAction object. For more details, refer to {@link ZMVideoSDKShareAction}.
 */
- (void)onUserShareStatusChanged:(ZMVideoSDKShareHelper* _Nonnull)shareHelper user:(ZMVideoSDKUser* _Nullable)user shareAction:(ZMVideoSDKShareAction* _Nullable)shareAction;

/**
 @brief Invoked when a user failed to start sharing.
 @param shareHelper The pointer to a share helper object, see {@link ZMVideoSDKShareHelper}.
 @param user The pointer to a user object.
 */
- (void)onFailedToStartShare:(ZMVideoSDKShareHelper* _Nonnull)shareHelper user:(ZMVideoSDKUser* _Nullable)user;

/**
 @brief Callback: Invoked when a user makes changes to their live stream status.
 @param liveStreamHelper The pointer of live stream helper object.
 @param status The current status of live stream.
 */
- (void)onLiveStreamStatusChanged:(ZMVideoSDKLiveStreamHelper* _Nonnull)liveStreamHelper liveStreamStatus:(ZMVideoSDKLiveStreamStatus)status;

/**
 @brief Callback: Invoked when receiving a chat message.
 @param chatHelper The pointer of chat helper object.
 @param chatMessage The pointer of chat message object.
 */
- (void)onChatNewMessageNotify:(ZMVideoSDKChatHelper* _Nonnull)chatHelper chatMessage:(ZMVideoSDKChatMessage* _Nullable)chatMessage;
    
/**
 @brief Callback: Invoked when the session host changes.
 @param userHelper The pointer of user helper object.
 @param user The pointer of user object.
 */
- (void)onUserHostChanged:(ZMVideoSDKUserHelper* _Nonnull)userHelper user:(ZMVideoSDKUser* _Nullable)user;
    
/**
 @brief Callback: Invoked when the active audio changes.
 @param audioHelper The pointer of audio helper object.
 @param userArray Active audio list.
 */
- (void)onUserActiveAudioChanged:(ZMVideoSDKAudioHelper* _Nonnull)audioHelper userList:(NSArray<ZMVideoSDKUser *>* _Nullable)userArray;
    
/**
 @brief Callback: Invoked when the session requires a password to join.
 @param handle The pointer to password handler object.
 */
- (void)onSessionNeedPassword:(ZMVideoSDKPasswordHandler* _Nonnull)handle;
    
/**
 @brief Callback: Invoked when the provided session password is wrong or invalid.
 @param handle The pointer to password handler object.
 */
- (void)onSessionPasswordWrong:(ZMVideoSDKPasswordHandler* _Nonnull)handle;
    
/**
 @brief Callback: Invoked when mixed (all users) audio raw data received.
 @param data The pointer of audio raw data.
 */
- (void)onMixedAudioRawDataReceived:(ZMVideoSDKAudioRawData* _Nonnull)data;
    
/**
 @brief Callback: Invoked when individual user's audio raw data received.
 @param data Raw audio data. {@link ZMVideoSDKAudioRawData}.
 @param user The user object associated with the raw audio data.
 */
- (void)onOneWayAudioRawDataReceived:(ZMVideoSDKAudioRawData* _Nonnull)data user:(ZMVideoSDKUser* _Nullable)user;
    
/**
 @brief Callback: Invoked when the manager of the session changes.
 @param user The pointer of user object.
 */
- (void)onUserManagerChanged:(ZMVideoSDKUser* _Nullable)user;
    
/**
 @brief Callback: Invoked when a user changes their name.
 @param user The pointer of user object.
 */
- (void)onUserNameChanged:(ZMVideoSDKUser* _Nullable)user;

/**
 @brief Callback: Invoked when receiving shared raw audio data.
 @param data Raw audio data. {@link ZMVideoSDKAudioRawData}.
 */
- (void)onSharedAudioRawDataReceived:(ZMVideoSDKAudioRawData* _Nullable)data;

/**
 @brief Callback: Invoked when cloud recording status has paused, stopped, resumed, or otherwise changed.
 @param status Cloud recording status defined in {@link ZMRecordingStatus}.
 @param handler When the cloud recording starts, this object is used to let the user choose whether to accept or not.
 */
- (void)onCloudRecordingStatus:(ZMRecordingStatus)status recordingConsentHandler:(ZMVideoSDKRecordingConsentHandler * _Nullable)handler;

/**
 @brief Invoked when a user consents to individual recording.
 @param user The pointer to the user object.
 */
- (void)onUserRecordingConsent:(ZMVideoSDKUser * _Nullable)user;
/**
 @brief Once the command channel is active, this callback is triggered each time a message is received.
 @param commandContent Received command.
 @param user The user who sent the command.
 */
- (void)onCommandReceived:(NSString* _Nullable)commandContent senderUser:(ZMVideoSDKUser* _Nullable)user;

/**
 @brief Callback for when the current user is granted camera control access.
 @note Once the current user sends the camera control request, this callback will be triggered with the result of the request.
 @param user The pointer to the user who received the request.
 @param isApproved The result of the camera control request.
 */
- (void)onCameraControlRequestResult:(ZMVideoSDKUser* _Nullable)user approved:(BOOL)isApproved;

/**
 @brief Callback interface for when the current user has received a camera control request.
 @note This will be triggered when another user requests control of the current users camera.
 @param user The pointer to the user who sent the request.
 @param requestType The request type.
 @param cameraControlRequestHandler The pointer to the helper instance of the camera controller. See {@link ZMVideoSDKCameraControlRequestHandler}.
 */
- (void)onCameraControlRequestReceived:(ZMVideoSDKUser* _Nullable)user cameraControlRequestType:(ZMVideoSDKCameraControlRequestType)requestType requestHandler:(ZMVideoSDKCameraControlRequestHandler* _Nullable)cameraControlRequestHandler;

/**
 @brief When the SDK attempts to establish a connection for the command channel when joining a session, this callback is triggered once the connection attempt for the command channel is completed.
 @param isSuccess YES: Success, command channel is ready to be used. NO: Failure, command channel was unable to connect.
 */
- (void)onCommandChannelConnectResult:(BOOL)isSuccess;

/**
 @brief Callback: Invoked when a host requests you to unmute yourself.
 */
- (void)onHostAskUnmute;

/**
 @brief Callback: Invoked when the invite by phone status changes to any other valid status such as Calling, Ringing, Success, or Failed.
 @param status Invite by phone status. See {@link ZMPhoneStatus}.
 @param reason Invite by phone failed reason. See {@link ZMPhoneFailedReason}.
 */
- (void)onInviteByPhoneStatus:(ZMPhoneStatus)status reason:(ZMPhoneFailedReason)reason;

/**
 @brief Callback: Invoked when the invite by phone user joined session success.
 @param user success joined user,  See {@link ZMVideoSDKUser}.
 @param phoneNumber Phone number of callout.
 */
- (void)onCalloutJoinSuccess:(ZMVideoSDKUser * _Nullable)user phoneNumber:(NSString * _Nullable)phoneNumber;

/**
 @brief Callback: Invoked when someone in a given session enables or disables multi-camera. All participants in the session receive this callback.
 @param status The status of camera, refer to {@link ZMVideoSDKMultiCameraStreamStatus}.
 @param user The user who enabled multi-camera. See {@link ZMVideoSDKUser}.
 @param videoPipe The data pipe for the multi-camera. See {@link ZMVideoSDKMultiCameraStreamStatus}.
 */
- (void)onMultiCameraStreamStatusChanged:(ZMVideoSDKMultiCameraStreamStatus)status user:(ZMVideoSDKUser * _Nullable)user rawDataPipe:(ZMVideoSDKRawDataPipe * _Nullable)videoPipe;

/**
 @brief Notify the current mic or speaker volume when testing.
 @param micVolume Specify the volume of the mic when testing or in session.
 @param speakerVolume Specify the volume of the speaker when testing.
 */
- (void)onMicSpeakerVolumeChanged:(unsigned int)micVolume speakerVolume:(unsigned int)speakerVolume;

/**
 @brief Notify that either mic device or speaker device status changed.
 @param type The audio device type.
 @param status The audio device status.
 */
- (void)onAudioDeviceStatusChanged:(ZMVideoSDKAudioDeviceType)type status:(ZMVideoSDKAudioDeviceStatus)status;

/**
 @brief Notify the mic status when testing.
 @param status The mic status.
 */
- (void)onTestMicStatusChanged:(ZMVideoSDKMicTestStatus)status;

/**
 @brief Notify the user that a mic/speaker device is selected when testing. Then the SDK will close the mic/speaker testing. The user shall restart the test manually if he still wants to test.
 */
- (void)onSelectedAudioDeviceChanged;

/**
 @brief Notify that the camera list has updated.
 */
- (void)onCameraListChanged;

/**
 @brief Callback: Invoked when live transcription status changes.
 @param status The live transcription status. See {@link ZMVideoSDKLiveTranscriptionStatus}.
 */
- (void)onLiveTranscriptionStatus:(ZMVideoSDKLiveTranscriptionStatus)status;

/**
 @brief Callback: Invoked when a live transcription message is received.
 @param messageInfo The live transcription message, refer to {@link ZMVideoSDKLiveTranscriptionMessageInfo}.
 */
- (void)onLiveTranscriptionMsgInfoReceived:(ZMVideoSDKLiveTranscriptionMessageInfo* _Nullable)messageInfo;

/**
 @brief Original language message received callback.
 @param messageInfo The spoken language message, see {@link ZMVideoSDKLiveTranscriptionMessageInfo}.
 */
- (void)onOriginalLanguageMsgReceived:(ZMVideoSDKLiveTranscriptionMessageInfo* _Nullable)messageInfo;

/**
 @brief Callback: Invoked when a live translation error occurs.
 @param spokenLanguage The spoken message language.
 @param transcriptLanguage The message language you want to translate.
 */
- (void)onLiveTranscriptionMsgError:(ZMVideoSDKLiveTranscriptionLanguage* _Nullable)spokenLanguage transcriptLanguage:(ZMVideoSDKLiveTranscriptionLanguage* _Nullable)transcriptLanguage;

/**
 @brief Callback: Invoked when a user deletes a chat message.
 @param chatHelper The pointer to chat helper object.
 @param msgID The deleted message's ID.
 @param type Indicates by whom the message was deleted, which is defined in {@link ZMVideoSDKChatMessageDeleteType}.
 */
- (void)onChatMsgDeleteNotification:(ZMVideoSDKChatHelper* _Nonnull)chatHelper messageID:(NSString * _Nullable)msgID deleteBy:(ZMVideoSDKChatMessageDeleteType)type;

/**
 @brief Callback event of the chat privilege of participant has changed.
 @param chatHelper The pointer to chat helper object.
 @param privilege The new chat privilege.
 */
- (void)onChatPrivilegeChanged:(ZMVideoSDKChatHelper* _Nonnull)chatHelper chatPrivilegeType:(ZMVideoSDKChatPrivilegeType)privilege;

/**
 @brief Notification callback of completing the proxy detection.
 */
- (void)onProxyDetectComplete;

/**
 @brief The callback will be triggered if the proxy requests to input the username and password. Use the handler to configure the related information. For more details, see {@link ZMVideoSDKProxySettingHandler}.
 @param handler The handler will be destroyed once the function calls end.
 */
- (void)onProxySettingNotification:(ZMVideoSDKProxySettingHandler * _Nonnull)handler;

/**
 @brief The callback will be triggered when the SSL is verified. Use the handler to check the related information. For more details, see {@link ZMVideoSDKSSLCertificateInfo}.
 @param handler The handler will be destroyed once the function calls end.
 */
- (void)onSSLCertVerifiedFailNotification:(ZMVideoSDKSSLCertificateInfo * _Nonnull)info;

/**
 @brief Callback event of the user's video network quality changes.
 @param status Video network quality. For more details, see {@link ZMVideoSDKNetworkStatus}.
 @param user The pointer to a user object. For more details, refer to {@link ZMVideoSDKUser}.
 */
- (void)onUserVideoNetworkStatusChanged:(ZMVideoSDKNetworkStatus)status user:(ZMVideoSDKUser * _Nullable)user;

/**
 @brief Callback event of the call CRC device's status.
 @param status The call status. For more details, see {@link ZMVideoSDKCRCCallStatus}.
 */
- (void)onCallCRCDeviceStatusChanged:(ZMVideoSDKCRCCallStatus)status;

/**
 @brief Callback event for the vidoe canvas that failed to subscribe.
 @param failReason The fail reason. For more details, see {@link ZMVideoSDKSubscribeFailReason}.
 @param user The pointer to the user object whose view we would like to subscribe to. For more details, refer to {@link ZMVideoSDKUser}.
 @param view The view that failed to subscribe.
 */
- (void)onVideoCanvasSubscribeFail:(ZMVideoSDKSubscribeFailReason)failReason user:(ZMVideoSDKUser* _Nullable)user view:(NSView* _Nullable)view;

/**
 @brief Callback event for the subscribed user's share view failure reason.
 @param user The pointer to a user object whose view we would like to subscribe to. For more details, refer to {@link ZMVideoSDKUser}.
 @param view The view that failed to subscribe.
 @param shareAction The pointer to the ZMVideoSDKShareAction object. For more details, refer to {@link ZMVideoSDKShareAction}.
 */
- (void)onShareCanvasSubscribeFail:(ZMVideoSDKUser* _Nullable)user view:(NSView* _Nullable)view  shareAction:(ZMVideoSDKShareAction* _Nullable)shareAction;

/**
 @brief Callback for the annotation helper clean up. SDK will release the ZoomVideoSDKAnnotationHelper object as well.
 @param helper The helper clean up object.
 */
- (void)onAnnotationHelperCleanUp:(ZMVideoSDKAnnotationHelper* _Nullable)helper;

/**
 @brief Callback for the annotation privilege change.
 @param user The pointer to a user object who changed viewer's annotation privilege. For more details, refer to {@link ZMVideoSDKUser}.
 @param shareAction The pointer to a ZMVideoSDKShareAction object. For more details, refer to {@link ZMVideoSDKShareAction}.
 */
- (void)onAnnotationPrivilegeChange:(ZMVideoSDKUser* _Nullable)user shareAction:(ZMVideoSDKShareAction* _Nullable)shareAction;

/**
 @brief Callback for the annotation helper activated. Notify that annotation windows have been created.
 @param view The view that annotating.
 */
- (void)onAnnotationHelperActived:(NSView* _Nullable)view;

/**
 @brief Invoked when send file status make change.
 @param sendFile The pointer to send file object. For more details, refer to {@link ZMVideoSDKSendFile}.
 @param status The status of file transfer. For more details, refer to {@link ZMVideoSDKFileTransferStatus}.
 */
- (void)onSendFile:(ZMVideoSDKSendFile * _Nullable)sendFile status:(ZMVideoSDKFileTransferStatus)status;

/**
 @brief Invoked when receive file status make change.
 @param receiveFile The pointer to receive file object. For more details, refer to {@link ZMVideoSDKReceiveFile}.
 @param status The status of file transfer. For more details, refer to {@link ZMVideoSDKFileTransferStatus}.
 */
- (void)onReceiveFile:(ZMVideoSDKReceiveFile * _Nullable)receiveFile status:(ZMVideoSDKFileTransferStatus)status;

/**
 * @brief Callback event of alpha channel mode changes.
 * @param isAlphaModeOn YES means it's in alpha channel mode. Otherwise, it's not.
 */
- (void)onVideoAlphaChannelStatusChanged:(BOOL)isAlphaModeOn;

/**
 * @brief Callback for when the remote control status changes.
 * @param status The value of the remote control status. For more details, refer to {@link ZMVideoSDKRemoteControlStatus}.
 * @param user The remote control user. For more details, refer to {@link ZMVideoSDKUser}.
 * @param shareAction The pointer to a ZMVideoSDKShareAction object. For more details, refer to {@link ZMVideoSDKShareAction}.
 */
- (void)onRemoteControlStatus:(ZMVideoSDKRemoteControlStatus)status user:(ZMVideoSDKUser *)user shareAction:(ZMVideoSDKShareAction* _Nullable)shareAction;

/**
 * @brief Callback for when the current user has received a remote control request. This will be triggered when another user requests control of the current user's screen.
 * @param user The pointer to a user who sent the request. For more details, refer to {@link ZMVideoSDKUser}.
 * @param shareAction The pointer to a ZMVideoSDKShareAction object. For more details, refer to {@link ZMVideoSDKShareAction}.
 * @param handler The pointer to a helper instance of the remote controller. For more details, refer to {@link ZMVideoSDKRemoteControlRequestHandler}.
 */
- (void)onRemoteControlRequestReceived:(ZMVideoSDKUser *)user shareAction:(ZMVideoSDKShareAction* _Nullable)shareAction handler:(ZMVideoSDKRemoteControlRequestHandler *)handler;

/**
 * @brief Callback event of spotlighted video user changes.
 * @param videoHelper The pointer of video helper object.
 * @param userList List of users who has been spotlighted.
 */
- (void)onSpotlightVideoChanged:(ZMVideoSDKVideoHelper*)videoHelper userList:(NSArray<ZMVideoSDKUser*>*_Nullable)userlist;

/**
 * @brief Callback event that binds incoming live stream.
 * @param success YES is success, otherwise false.
 * @param streamKeyID Corresponding stream key id.
 */
- (void)onBindIncomingLiveStreamResponse:(BOOL)bSuccess streamKeyID:(NSString*)streamKeyID;

/**
 * @brief Callback event that unbinds incoming live stream.
 * @param success YES is success, otherwise false.
 * @param streamKeyID Corresponding stream key id.
 */
- (void)onUnbindIncomingLiveStreamResponse:(BOOL)bSuccess streamKeyID:(NSString*)streamKeyID;

/**
 * @brief Callback event that gets streams status.
 * @param success YES is success, otherwise false.
 * @param streamsStatusList The streams status list.
 */
- (void)onIncomingLiveStreamStatusResponse:(BOOL)bSuccess streamsStatusList:(NSArray*)streamsStatusList;

/**
 * @brief Callback event that starts the binded stream.
 * @param success YES is success, otherwise false.
 * @param streamKeyID Corresponding stream key id.
 */
- (void)onStartIncomingLiveStreamResponse:(BOOL)bSuccess streamKeyID:(NSString*)streamKeyID;

/**
 * @brief Callback event that stops the binded stream.
 * @param success YES is success, otherwise false.
 * @param streamKeyID Corresponding stream key id.
 */
- (void)onStopIncomingLiveStreamResponse:(BOOL)bSuccess streamKeyID:(NSString*)streamKeyID;
@end
NS_ASSUME_NONNULL_END
