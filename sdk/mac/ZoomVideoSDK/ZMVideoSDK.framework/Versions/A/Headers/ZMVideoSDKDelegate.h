/**
 * @file ZMVideoSDKDelegate.h
 * @brief This file defines the \link ZMVideoSDKDelegate \endlink protocol,
 * which contains callback methods related to session lifecycle, user join/leave,
 * audio/video status changes, error notifications, and other session events.
 */

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
@class ZMVideoSDKSubSessionKit;
@class ZMVideoSDKSubSessionUser;
@class ZMVideoSDKSubSessionManager;
@class ZMVideoSDKSubSessionParticipant;
@class ZMVideoSDKSubSessionUserHelpRequestHandler;
@class ZMVideoSDKWhiteboardHelper;
/**
 * @protocol ZMVideoSDKDelegate
 * @brief Delegate protocol to receive session related callbacks.
 */
@protocol ZMVideoSDKDelegate <NSObject>
@optional
    
/**
 * @brief Callback: Invoked when the current user joins the session.
 */
- (void)onSessionJoin;
    
/**
 * @brief Callback: Invoked when the current user leaves the session.
 * @deprecated Use \link ZMVideoSDKDelegate::onSessionLeave: \endlink instead.
 */
- (void)onSessionLeave DEPRECATED_MSG_ATTRIBUTE("Use -onSessionLeave: instead");

/**
 * @brief Invoked when the current user leaves the session with reason.
 * @param reason The leave reason.
 */
- (void)onSessionLeave:(ZMVideoSDKSessionLeaveReason)reason;

/**
 * @brief Callback: Invoked when errors occur.
 * @param ErrorType Provides error code associated with the error.
 * @param details Detailed errorCode.
 */
- (void)onError:(ZMVideoSDKErrors)ErrorType detail:(int)details;
    
/**
 * @brief Callback: Invoked when a user joins the session.
 * @param userHelper User help utility.
 * @param userArray List of users who have just joined the session.
 */
- (void)onUserJoin:(ZMVideoSDKUserHelper* _Nonnull)userHelper userList:(NSArray<ZMVideoSDKUser *>* _Nullable)userArray;
    
/**
 * @brief Triggered when other users leave session.
 * @param userHelper The pointer of user helper object.
 * @param userArray An array contains the users leaved.
 */
- (void)onUserLeave:(ZMVideoSDKUserHelper* _Nonnull)userHelper userList:(NSArray<ZMVideoSDKUser *>* _Nullable)userArray;
    
/**
 * @brief Callback: Invoked when a user makes changes to their video, such as starting or stopping their video.
 * @param videoHelper The pointer of video helper object.
 * @param userArray The array contain user objoct.
 */
- (void)onUserVideoStatusChanged:(ZMVideoSDKVideoHelper* _Nonnull)videoHelper userList:(NSArray<ZMVideoSDKUser *>* _Nullable)userArray;
    
/**
 * @brief Callback: Invoked when a user makes changes to their audio, such as muting or unmuting their audio.
 * @param audioHelper The pointer of audio helper object.
 * @param userArray The array contain user objoct.
 */
- (void)onUserAudioStatusChanged:(ZMVideoSDKAudioHelper* _Nonnull)audioHelper userList:(NSArray<ZMVideoSDKUser *>* _Nullable)userArray;
    
/**
 * @brief Invoked when a user makes changes to their sharing status, such as starting screen sharing, starting view sharing, or stopping sharing.
 * @param shareHelper The pointer to a share helper object.
 * @param user The pointer to a user object.
 * @param shareAction The pointer to a ZMVideoSDKShareAction object.
 */
- (void)onUserShareStatusChanged:(ZMVideoSDKShareHelper* _Nonnull)shareHelper user:(ZMVideoSDKUser* _Nullable)user shareAction:(ZMVideoSDKShareAction* _Nullable)shareAction;

/**
 * @brief Invoked when the share content size has changed.
 * @param shareHelper The pointer to a share helper object.
 * @param user The pointer to a user object.
 * @param shareAction The pointer to a ZMVideoSDKShareAction object.
 * @note A share content size change may occur in two cases: 
 *       when the first frame of shared content is received (from no content to having a size), 
 *       or when the content size actually changes during sharing.
 */
- (void)onShareContentSizeChanged:(ZMVideoSDKShareHelper* _Nonnull)shareHelper user:(ZMVideoSDKUser* _Nullable)user shareAction:(ZMVideoSDKShareAction* _Nullable)shareAction;

/**
 * @brief Callback: Invoked when a user makes changes to their share content type, such as switching camera share to normal share.
 * Find the share type in \link ZMVideoSDKShareType \endlink.
 * @param shareHelper The pointer to share helper object.
 * @param user current start or stop share userInfo.
 * @param shareAction The pointer to a ZMVideoSDKShareAction object.
 */
- (void)onShareContentChanged:(ZMVideoSDKShareHelper* _Nonnull)shareHelper user:(ZMVideoSDKUser *)user shareAction:(ZMVideoSDKShareAction* _Nullable)shareAction;

/**
 * @brief Invoked when the list of unsharing windows changes.
 * @param windowsList An array of window IDs (`CGWindowID`) representing the windows that are not being shared. Each window ID is wrapped in an `NSNumber`.
 * @param shareHelper The pointer to the share helper object.
 * @param user The user who is sharing.
 * @param shareAction The pointer to a ZMVideoSDKShareAction object.
 */
- (void)onUnsharingWindowsChanged:(NSArray<NSNumber*>*)windowsList shareHelper:(ZMVideoSDKShareHelper* _Nonnull)shareHelper user:(ZMVideoSDKUser *)user shareAction:(ZMVideoSDKShareAction* _Nullable)shareAction;

/**
 * @brief Invoked when a user failed to start sharing.
 * @param shareHelper The pointer to a share helper object.
 * @param user The pointer to a user object.
 */
- (void)onFailedToStartShare:(ZMVideoSDKShareHelper* _Nonnull)shareHelper user:(ZMVideoSDKUser* _Nullable)user;

/**
 * @brief Notification of the share setting has changed.
 * @param setting The share setting, see \link ZMVideoSDKShareSetting \endlink
 */
- (void)onShareSettingChanged:(ZMVideoSDKShareSetting)setting;

/**
 * @brief Callback: Invoked when a user makes changes to their live stream status.
 * @param liveStreamHelper The pointer of live stream helper object.
 * @param status The current status of live stream.
 */
- (void)onLiveStreamStatusChanged:(ZMVideoSDKLiveStreamHelper* _Nonnull)liveStreamHelper liveStreamStatus:(ZMVideoSDKLiveStreamStatus)status;

/**
 * @brief Callback: Invoked when receiving a chat message.
 * @param chatHelper The pointer of chat helper object.
 * @param chatMessage The pointer of chat message object.
 */
- (void)onChatNewMessageNotify:(ZMVideoSDKChatHelper* _Nonnull)chatHelper chatMessage:(ZMVideoSDKChatMessage* _Nullable)chatMessage;
    
/**
 * @brief Callback: Invoked when the session host changes.
 * @param userHelper The pointer of user helper object.
 * @param user The pointer of user object.
 */
- (void)onUserHostChanged:(ZMVideoSDKUserHelper* _Nonnull)userHelper user:(ZMVideoSDKUser* _Nullable)user;
    
/**
 * @brief Callback: Invoked when the active audio changes.
 * @param audioHelper The pointer of audio helper object.
 * @param userArray Active audio list.
 */
- (void)onUserActiveAudioChanged:(ZMVideoSDKAudioHelper* _Nonnull)audioHelper userList:(NSArray<ZMVideoSDKUser *>* _Nullable)userArray;
    
/**
 * @brief Callback: Invoked when the session requires a password to join.
 * @param handle The pointer to password handler object.
 */
- (void)onSessionNeedPassword:(ZMVideoSDKPasswordHandler* _Nonnull)handle;
    
/**
 * @brief Callback: Invoked when the provided session password is wrong or invalid.
 * @param handle The pointer to password handler object.
 */
- (void)onSessionPasswordWrong:(ZMVideoSDKPasswordHandler* _Nonnull)handle;
    
/**
 * @brief Callback: Invoked when mixed (all users) audio raw data received.
 * @param data The pointer of audio raw data.
 */
- (void)onMixedAudioRawDataReceived:(ZMVideoSDKAudioRawData* _Nonnull)data;
    
/**
 * @brief Callback: Invoked when individual user's audio raw data received.
 * @param data Raw audio data.
 * @param user The user object associated with the raw audio data.
 */
- (void)onOneWayAudioRawDataReceived:(ZMVideoSDKAudioRawData* _Nonnull)data user:(ZMVideoSDKUser* _Nullable)user;
    
/**
 * @brief Callback: Invoked when the manager of the session changes.
 * @param user The pointer of user object.
 */
- (void)onUserManagerChanged:(ZMVideoSDKUser* _Nullable)user;
    
/**
 * @brief Callback: Invoked when a user changes their name.
 * @param user The pointer of user object.
 */
- (void)onUserNameChanged:(ZMVideoSDKUser* _Nullable)user;

/**
 * @brief Callback: Invoked when receiving shared raw audio data.
 * @param data Raw audio data.
 */
- (void)onSharedAudioRawDataReceived:(ZMVideoSDKAudioRawData* _Nullable)data;

/**
 * @brief Callback: Invoked when cloud recording status has paused, stopped, resumed, or otherwise changed.
 * @param status Cloud recording status.
 * @param handler When the cloud recording starts, this object is used to let the user choose whether to accept or not.
 */
- (void)onCloudRecordingStatus:(ZMRecordingStatus)status recordingConsentHandler:(ZMVideoSDKRecordingConsentHandler * _Nullable)handler;

/**
 * @brief Invoked when a user consents to individual recording.
 * @param user The pointer to the user object.
 */
- (void)onUserRecordingConsent:(ZMVideoSDKUser * _Nullable)user;
/**
 * @brief Once the command channel is active, this callback is triggered each time a message is received.
 * @param commandContent Received command.
 * @param user The user who sent the command.
 */
- (void)onCommandReceived:(NSString* _Nullable)commandContent senderUser:(ZMVideoSDKUser* _Nullable)user;

/**
 * @brief Callback for when the current user is granted camera control access.
 * @param user The pointer to the user who received the request.
 * @param isApproved The result of the camera control request.
 * @note Once the current user sends the camera control request, this callback will be triggered with the result of the request.
 */
- (void)onCameraControlRequestResult:(ZMVideoSDKUser* _Nullable)user approved:(BOOL)isApproved;

/**
 * @brief Callback interface for when the current user has received a camera control request.
 * @param user The pointer to the user who sent the request.
 * @param requestType The request type.
 * @param cameraControlRequestHandler The pointer to the helper instance of the camera controller.
 * @note This will be triggered when another user requests control of the current users camera.
 */
- (void)onCameraControlRequestReceived:(ZMVideoSDKUser* _Nullable)user cameraControlRequestType:(ZMVideoSDKCameraControlRequestType)requestType requestHandler:(ZMVideoSDKCameraControlRequestHandler* _Nullable)cameraControlRequestHandler;

/**
 * @brief When the SDK attempts to establish a connection for the command channel when joining a session, this callback is triggered once the connection attempt for the command channel is completed.
 * @param isSuccess YES: Success, command channel is ready to be used. NO: Failure, command channel was unable to connect.
 */
- (void)onCommandChannelConnectResult:(BOOL)isSuccess;

/**
 * @brief Callback: Invoked when a host requests you to unmute yourself.
 */
- (void)onHostAskUnmute;

/**
 * @brief Callback: Invoked when the invite by phone status changes to any other valid status such as Calling, Ringing, Success, or Failed.
 * @param status Invite by phone status.
 * @param reason Invite by phone failed reason.
 */
- (void)onInviteByPhoneStatus:(ZMPhoneStatus)status reason:(ZMPhoneFailedReason)reason;

/**
 * @brief Callback: Invoked when the invite by phone user joined session success.
 * @param user success joined user.
 * @param phoneNumber Phone number of callout.
 */
- (void)onCalloutJoinSuccess:(ZMVideoSDKUser * _Nullable)user phoneNumber:(NSString * _Nullable)phoneNumber;

/**
 * @brief Callback: Invoked when someone in a given session enables or disables multi-camera. All participants in the session receive this callback.
 * @param status The status of camera.
 * @param user The user who enabled multi-camera.
 * @param videoPipe The data pipe for the multi-camera.
 */
- (void)onMultiCameraStreamStatusChanged:(ZMVideoSDKMultiCameraStreamStatus)status user:(ZMVideoSDKUser * _Nullable)user rawDataPipe:(ZMVideoSDKRawDataPipe * _Nullable)videoPipe;

/**
 * @brief Notification of the audio level changes for a participant (excluding self).
 * @param level The current audio level of the user, in the range [0, 9].
 * @param bAudioSharing YES if the audio level is from shared audio, such as computer audio; otherwise it's from the microphone.
 * @param pUser The user whose audio level has changed.
 */
- (void)onAudioLevelChanged:(unsigned int)level audioSharing:(BOOL)bAudioSharing user:(ZMVideoSDKUser * _Nullable)user;

/**
 * @brief Notify the current mic or speaker volume when testing.
 * @param micVolume Specify the volume of the mic when testing or in session.
 * @param speakerVolume Specify the volume of the speaker when testing.
 */
- (void)onMicSpeakerVolumeChanged:(unsigned int)micVolume speakerVolume:(unsigned int)speakerVolume;

/**
 * @brief Notify that either mic device or speaker device status changed.
 * @param type The audio device type.
 * @param status The audio device status.
 */
- (void)onAudioDeviceStatusChanged:(ZMVideoSDKAudioDeviceType)type status:(ZMVideoSDKAudioDeviceStatus)status;

/**
 * @brief Notify the mic status when testing.
 * @param status The mic status.
 */
- (void)onTestMicStatusChanged:(ZMVideoSDKMicTestStatus)status;

/**
 * @brief Notify the user that a mic/speaker device is selected when testing. Then the SDK will close the mic/speaker testing. The user shall restart the test manually if he still wants to test.
 */
- (void)onSelectedAudioDeviceChanged;

/**
 * @brief Notify that the camera list has updated.
 */
- (void)onCameraListChanged;

/**
 * @brief Callback: Invoked when live transcription status changes.
 * @param status The live transcription status.
 */
- (void)onLiveTranscriptionStatus:(ZMVideoSDKLiveTranscriptionStatus)status;

/**
 * @brief Callback: Invoked when a live transcription message is received.
 * @param messageInfo The live transcription message.
 */
- (void)onLiveTranscriptionMsgInfoReceived:(ZMVideoSDKLiveTranscriptionMessageInfo* _Nullable)messageInfo;

/**
 * @brief Original language message received callback.
 * @param messageInfo The spoken language message.
 */
- (void)onOriginalLanguageMsgReceived:(ZMVideoSDKLiveTranscriptionMessageInfo* _Nullable)messageInfo;

/**
 * @brief Callback: Invoked when a live translation error occurs.
 * @param spokenLanguage The spoken message language.
 * @param transcriptLanguage The message language you want to translate.
 */
- (void)onLiveTranscriptionMsgError:(ZMVideoSDKLiveTranscriptionLanguage* _Nullable)spokenLanguage transcriptLanguage:(ZMVideoSDKLiveTranscriptionLanguage* _Nullable)transcriptLanguage;

/**
 * @brief Notification of the spoken language has changed.
 * @param spokenLanguage The spoken message language.
 */
- (void)onSpokenLanguageChanged:(ZMVideoSDKLiveTranscriptionLanguage* _Nullable)spokenLanguage;

/**
 * @brief Callback: Invoked when a user deletes a chat message.
 * @param chatHelper The pointer to chat helper object.
 * @param msgID The deleted message's ID.
 * @param type Indicates by whom the message was deleted.
 */
- (void)onChatMsgDeleteNotification:(ZMVideoSDKChatHelper* _Nonnull)chatHelper messageID:(NSString * _Nullable)msgID deleteBy:(ZMVideoSDKChatMessageDeleteType)type;

/**
 * @brief Callback event of the chat privilege of participant has changed.
 * @param chatHelper The pointer to chat helper object.
 * @param privilege The new chat privilege.
 */
- (void)onChatPrivilegeChanged:(ZMVideoSDKChatHelper* _Nonnull)chatHelper chatPrivilegeType:(ZMVideoSDKChatPrivilegeType)privilege;

/**
 * @brief Notification callback of completing the proxy detection.
 */
- (void)onProxyDetectComplete;

/**
 * @brief The callback will be triggered if the proxy requests to input the username and password. Use the handler to configure the related information.
 * @param handler A handler used to configure proxy credentials. The handler will be destroyed once the function calls end.
 */
- (void)onProxySettingNotification:(ZMVideoSDKProxySettingHandler * _Nonnull)handler;

/**
 * @brief The callback will be triggered when the SSL is verified. Use the handler to check the related information.
 * @param info A certificate information object for verification failure. The object will be destroyed once the function calls end.
 */
- (void)onSSLCertVerifiedFailNotification:(ZMVideoSDKSSLCertificateInfo * _Nonnull)info;

/**
 * @brief Callback event of the user's video network quality changes.
 * @param status Video network quality.
 * @param user The pointer to a user object.
 * @deprecated Use \link ZMVideoSDKDelegate::onUserNetworkStatusChanged:level:user: \endlink instead.
 */
- (void)onUserVideoNetworkStatusChanged:(ZMVideoSDKNetworkStatus)status user:(ZMVideoSDKUser * _Nullable)user DEPRECATED_MSG_ATTRIBUTE("Use -onUserNetworkStatusChanged:level:user: instead");

/**
 * @brief Callback event of the current user's share network quality changes.
 * @param status share network quality.
 * @param isSendingShare Indicates the direction of the share. If YES, it refers to the sending share; if NO, it refers to the receiving share.
 * @deprecated Use \link ZMVideoSDKDelegate::onUserNetworkStatusChanged:level:user: \endlink instead.
 */
- (void)onShareNetworkStatusChanged:(ZMVideoSDKNetworkStatus)status isSendingShare:(BOOL)isSendingShare DEPRECATED_MSG_ATTRIBUTE("Use -onUserNetworkStatusChanged:level:user: instead");

/**
 * @brief Called when a user's network status changes for a specific data type.
 * @param type The data type whose network status changed.
 * @param level The new network quality level for the specified data type.
 * @param user The user whose network status has changed.
 */
- (void)onUserNetworkStatusChanged:(ZMVideoSDKDataType)type level:(ZMVideoSDKNetworkStatus)level user:(ZMVideoSDKUser *)user;

/**
 * @brief Called when a user's overall network status changes.
 * @param level The new overall network quality level.
 * @param user The user whose overall network status has changed.
 */
- (void)onUserOverallNetworkStatusChanged:(ZMVideoSDKNetworkStatus)level user:(ZMVideoSDKUser *)user;

/**
 * @brief Callback event of the call CRC device's status.
 * @param status The call status.
 */
- (void)onCallCRCDeviceStatusChanged:(ZMVideoSDKCRCCallStatus)status;

/**
 * @brief Callback event for the vidoe canvas that failed to subscribe.
 * @param failReason The fail reason.
 * @param user The pointer to the user object whose view we would like to subscribe to.
 * @param view The view that failed to subscribe.
 */
- (void)onVideoCanvasSubscribeFail:(ZMVideoSDKSubscribeFailReason)failReason user:(ZMVideoSDKUser* _Nullable)user view:(NSView* _Nullable)view;

/**
 * @brief Callback event for the subscribed user's share view failure reason.
 * @param user The pointer to a user object whose view we would like to subscribe to.
 * @param view The view that failed to subscribe.
 * @param shareAction The pointer to the ZMVideoSDKShareAction object.
 */
- (void)onShareCanvasSubscribeFail:(ZMVideoSDKUser* _Nullable)user view:(NSView* _Nullable)view  shareAction:(ZMVideoSDKShareAction* _Nullable)shareAction;

/**
 * @brief Callback for the annotation helper clean up. SDK will release the ZoomVideoSDKAnnotationHelper object as well.
 * @param helper The helper clean up object.
 */
- (void)onAnnotationHelperCleanUp:(ZMVideoSDKAnnotationHelper* _Nullable)helper;

/**
 * @brief Callback for the annotation privilege change.
 * @param user The pointer to a user object who changed viewer's annotation privilege.
 * @param shareAction The pointer to a ZMVideoSDKShareAction object.
 */
- (void)onAnnotationPrivilegeChange:(ZMVideoSDKUser* _Nullable)user shareAction:(ZMVideoSDKShareAction* _Nullable)shareAction;

/**
 * @brief Callback for the annotation helper activated. Notify that annotation windows have been created.
 * @param view The view that annotating.
 */
- (void)onAnnotationHelperActived:(NSView* _Nullable)view;

/**
 * @brief Invoked when send file status make change.
 * @param sendFile The pointer to send file object.
 * @param status The status of file transfer.
 */
- (void)onSendFile:(ZMVideoSDKSendFile * _Nullable)sendFile status:(ZMVideoSDKFileTransferStatus)status;

/**
 * @brief Invoked when receive file status make change.
 * @param receiveFile The pointer to receive file object.
 * @param status The status of file transfer.
 */
- (void)onReceiveFile:(ZMVideoSDKReceiveFile * _Nullable)receiveFile status:(ZMVideoSDKFileTransferStatus)status;

/**
 * @brief Callback event of alpha channel mode changes.
 * @param isAlphaModeOn YES means it's in alpha channel mode. Otherwise, it's not.
 */
- (void)onVideoAlphaChannelStatusChanged:(BOOL)isAlphaModeOn;

/**
 * @brief Callback for when the remote control status changes.
 * @param status The value of the remote control status.
 * @param user The remote control user.
 * @param shareAction The pointer to a ZMVideoSDKShareAction object.
 */
- (void)onRemoteControlStatus:(ZMVideoSDKRemoteControlStatus)status user:(ZMVideoSDKUser *)user shareAction:(ZMVideoSDKShareAction* _Nullable)shareAction;

/**
 * @brief Callback for when the current user has received a remote control request. This will be triggered when another user requests control of the current user's screen.
 * @param user The pointer to a user who sent the request.
 * @param shareAction The pointer to a ZMVideoSDKShareAction object.
 * @param handler The pointer to a helper instance of the remote controller.
 */
- (void)onRemoteControlRequestReceived:(ZMVideoSDKUser *)user shareAction:(ZMVideoSDKShareAction* _Nullable)shareAction handler:(ZMVideoSDKRemoteControlRequestHandler *)handler;

/**
 * @brief Callback event of spotlighted video user changes.
 * @param videoHelper The pointer of video helper object.
 * @param userlist List of users who has been spotlighted.
 */
- (void)onSpotlightVideoChanged:(ZMVideoSDKVideoHelper*)videoHelper userList:(NSArray<ZMVideoSDKUser*>*_Nullable)userlist;

/**
 * @brief Callback event that binds incoming live stream.
 * @param bSuccess YES is success, otherwise false.
 * @param streamKeyID Corresponding stream key id.
 */
- (void)onBindIncomingLiveStreamResponse:(BOOL)bSuccess streamKeyID:(NSString*)streamKeyID;

/**
 * @brief Callback event that unbinds incoming live stream.
 * @param bSuccess YES is success, otherwise false.
 * @param streamKeyID Corresponding stream key id.
 */
- (void)onUnbindIncomingLiveStreamResponse:(BOOL)bSuccess streamKeyID:(NSString*)streamKeyID;

/**
 * @brief Callback event that gets streams status.
 * @param bSuccess YES is success, otherwise false.
 * @param streamsStatusList The streams status list.
 */
- (void)onIncomingLiveStreamStatusResponse:(BOOL)bSuccess streamsStatusList:(NSArray*)streamsStatusList;

/**
 * @brief Callback event that starts the binded stream.
 * @param bSuccess YES is success, otherwise false.
 * @param streamKeyID Corresponding stream key id.
 */
- (void)onStartIncomingLiveStreamResponse:(BOOL)bSuccess streamKeyID:(NSString*)streamKeyID;

/**
 * @brief Callback event that stops the binded stream.
 * @param bSuccess YES is success, otherwise false.
 * @param streamKeyID Corresponding stream key id.
 */
- (void)onStopIncomingLiveStreamResponse:(BOOL)bSuccess streamKeyID:(NSString*)streamKeyID;

/**
 * @brief Callback event for when the subsession status changes.
 * @param status The subsession status.
 * @param subSessionKitList The subsession which status has changed. It has value only when status is Committed/Withdrawn/WithdrawFailed.
 */
- (void)onSubSessionStatusChanged:(ZMVideoSDKSubSessionStatus)status subSessionKit:(NSArray<ZMVideoSDKSubSessionKit*>* _Nullable)subSessionKitList;

/**
 * @brief Callback event when a user gains or loses subsession manager privileges.
 * @param manager The subsession manager object, when the user loses manager privileges, manager is nil.
 */
- (void)onSubSessionManagerHandle:(ZMVideoSDKSubSessionManager* _Nullable)manager;

/**
 * @brief Callback event when a user gains or loses subsession participant privileges.
 * @param participant The subsession participant object, when the user loses participant privileges, participant is nil.
 */
- (void)onSubSessionParticipantHandle:(ZMVideoSDKSubSessionParticipant* _Nullable)participant;

/**
 * @brief Callback event when the subsession users are updated.
 * @param subSessionKit The subSession kit object.
 */
- (void)onSubSessionUsersUpdate:(ZMVideoSDKSubSessionKit* _Nullable)subSessionKit;

/**
 * @brief Callback event when the user receives a main session broadcast message.
 * @param message The message content.
 * @param name The name of the user who broadcasted this message.
 */
- (void)onBroadcastMessageFromMainSession:(NSString*)message userName:(NSString*)name;

/**
 * @brief Callback event when the user receives a help request from a subsession.
 * @param handler The request handler object.
 */
- (void)onSubSessionUserHelpRequest:(ZMVideoSDKSubSessionUserHelpRequestHandler*)handler;

/**
 * @brief Callback event when the result of the help request.
 * @param result The result of help request.
 */
- (void)onSubSessionUserHelpRequestResult:(ZMVideoSDKUserHelpRequestResult)result;

/**
 * @brief Callback invoked when a whiteboard file export completes.
 * @param format The export format. See \link ZMVideoSDKExportFormat \endlink.
 * @param data The export whiteboard data as a byte array.
 * @param length The length of the export whiteboard data.
 */
- (void)onWhiteboardExported:(ZMVideoSDKExportFormat)format data:(unsigned char *)data dataLength:(long)length;



/**
 * @brief Callback invoked when a user changes their whiteboard sharing status, such as starting or stopping whiteboard sharing.
 * @param user The user who's whiteboard sharing status changed. Check the current status via \link ZMVideoSDKWhiteboardStatus \endlink.
 * @param whiteboardHelper The whiteboard helper object.
 */
- (void)onUserWhiteboardShareStatusChanged:(ZMVideoSDKUser *)user whiteboardHelper:(ZMVideoSDKWhiteboardHelper *)whiteboardHelper;

/**
 * @brief Notificates the response of starting broadcast streaming.
 * @param isSuccess YES if broadcast streaming started successfully; otherwise NO.
 * @param channelID The broadcast streaming channel ID returned by the backend.
 */
- (void)onStartBroadcastResponse:(BOOL)isSuccess channelID:(NSString*)channelID;

/**
 * @brief Notificates the response of stopping broadcast streaming.
 * @param isSuccess YES if broadcast stopped successfully; otherwise NO.
 */
- (void)onStopBroadcastResponse:(BOOL)isSuccess;

/**
 * @brief Notificates the response of getting broadcast status.
 * @param isSuccess YES if the request succeeded, otherwise NO.
 * @param status The current broadcast status.
 */
- (void)onGetBroadcastControlStatus:(BOOL)isSuccess broadcastControlStatus:(ZMVideoSDKBroadcastControlStatus)status;

/**
 * @brief Notificates when the viewer's join status changes.
 * @param status The current join status.
 */
- (void)onStreamingJoinStatusChanged:(ZMVideoSDKStreamingJoinStatus)status;

/**
 * @brief Callback: Invoked when the real-time media streams status changes.
 * @param status The current real-time media streams status.
 */
- (void)onRealTimeMediaStreamsStatusChanged:(ZMVideoSDKRealTimeMediaStreamsStatus)status;

/**
 * @brief Callback: Invoked when real-time media streams fails.
 * @param failReason The reason for the failure.
 */
- (void)onRealTimeMediaStreamsFail:(ZMVideoSDKRealTimeMediaStreamsFailReason)failReason;
@end
NS_ASSUME_NONNULL_END

