/**
 * @file ZMVideoSDKUserHelper.h
 * @brief Defines user-related interfaces and functionalities in Zoom Video SDK.
 */

#import <Foundation/Foundation.h>
#import <ZMVideoSDK/ZMVideoSDKDef.h>
#import <ZMVideoSDK/ZMVideoSDKVideoCanvas.h>

@class ZMVideoSDKShareAction;

NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZMVideoSDKVideoStatus
 * @brief ZMVideoSDKVideoStatus provides information on the user's video device (the detected compatible video camera device), and status (whether video is turned on or off).
 */
@interface ZMVideoSDKVideoStatus : NSObject

/**
 * @brief Query if the user's device has a compatible camera. YES : compatible camera detected, NO : no compatible camera detected.
 */
@property (nonatomic, assign, readonly) BOOL isHasVideoDevice;
    
/**
 * @brief Query if the camera is turned on. YES : camera turned on, NO : camera turned off.
 */
@property (nonatomic, assign, readonly) BOOL isOn;
@end

/**
 * @class ZMVideoSDKAudioStatus
 * @brief Audio status interface.
 */
@interface ZMVideoSDKAudioStatus : NSObject
    
/**
 * @brief Get audio type: VOIP (Voice over IP), Telephony, or None.
 */
@property (nonatomic, assign, readonly) ZMVideoSDKAudioType audioType;
    
/**
 * @brief Determine whether the audio is muted.
 */
@property (nonatomic, assign, readonly) BOOL isMuted;
    
/**
 * @brief Determine whether the user is talking.
 */
@property (nonatomic, assign, readonly) BOOL isTalking;
@end

/**
 * @class ZMVideoSDKVideoStatisticInfo
 * @brief Video statistic information interface.
 */
@interface ZMVideoSDKVideoStatisticInfo : NSObject

/**
 * @brief Get the width of video data size.
 */
@property (nonatomic, assign, readonly) int width;
    
/**
 * @brief Get the height of video data size.
 */
@property (nonatomic, assign, readonly) int height;
    
/**
 * @brief Get video fps.
 */
@property (nonatomic, assign, readonly) int fps;
    
/**
 * @brief Get video Bpf.
 */
@property (nonatomic, assign, readonly) int bpf;

/**
 * @brief Get video network status.
 */
@property (nonatomic, assign, readonly) ZMVideoSDKNetworkStatus videoNetworkStatus;
@end

/**
 * @class ZMVideoSDKShareStatisticInfo
 * @brief Share statistic infomation interface.
 */
@interface ZMVideoSDKShareStatisticInfo : NSObject

/**
 * @brief Get the width of share data size.
 */
@property (nonatomic, assign, readonly) int width;
    
/**
 * @brief Get the height of share data size.
 */
@property (nonatomic, assign, readonly) int height;
    
/**
 * @brief Get share fps.
 */
@property (nonatomic, assign, readonly) int fps;
    
/**
 * @brief Get share Bpf.
 */
@property (nonatomic, assign, readonly) int bpf;

/**
 * @brief Get share network status.
 */
@property (nonatomic, assign, readonly) ZMVideoSDKNetworkStatus shareNetworkStatus;
@end

/**
 * @class ZMVideoSDKYUVRawDataI420
 * @brief YUV raw data 420 infomation interface.
 */
@interface ZMVideoSDKYUVRawDataI420 : NSObject

/**
 * @brief Get the YUVI420 Y buffer. The Y component represents the luma or brightness values.
 */
@property (nonatomic, assign, readonly) char* _Nullable yBuffer;

/**
 * @brief Get the YUVI420 U buffer. The U component represents the chroma values.
 */
@property (nonatomic, assign, readonly) char* _Nullable uBuffer;

/**
 * @brief Get the YUVI420 V buffer. The V component represents the chroma values.
 */
@property (nonatomic, assign, readonly) char* _Nullable vBuffer;

/**
 * @brief The buffer data.
 */
@property (nonatomic, assign, readonly) char* _Nullable buffer;

/**
 * @brief Get video alpha mask data buffer.
 */
@property (nonatomic, assign, readonly, nullable) char* alphaBuffer;

/**
 * @brief The buffer length of this data.
 */
@property (nonatomic, assign, readonly) unsigned int bufferLen;

/**
 * @brief Get the alpha buffer length.
 */
@property (nonatomic, assign, readonly) unsigned int alphaBufferLen;

/**
 * @brief Get if this data is limited I420 format.
 */
@property (nonatomic, assign, readonly) BOOL isLimitedI420;

/**
 * @brief Query stream width.
 */
@property (nonatomic, assign, readonly) unsigned int streamWidth;

/**
 * @brief Get the stream height.
 */
@property (nonatomic, assign, readonly) unsigned int streamHeight;

/**
 * @brief Query the video raw data rotation.
 */
@property (nonatomic, assign, readonly) unsigned int rotation;

/**
 * @brief Get the source_id of current YUV raw data.
 */
@property (nonatomic, assign, readonly) unsigned int resourceID;

/**
 * @brief Millisecond timestamp.
 */
@property (nonatomic, assign, readonly) long long timeStamp;
/**
 * @brief Determine if the reference count for accessing the raw data buffer can be increased.
 * @return If you addRef(), the SDK will try to hold the raw data buffer until the reference becomes 0. When you finish using the raw data buffer, you must call releaseRef;
 */
- (BOOL)canAddRef;

/**
 * @brief Increase reference count by 1. Adding a reference will ensure that the raw data buffer will not be released.
 * @return If you addRef, the SDK will try to hold the raw data buffer until the reference becomes 0. When you finish using the raw data buffer, you must call releaseRef.
 */
- (BOOL)addRef;

/**
 * @brief Decrease reference count by 1. When you finish using the raw data buffer, you must call releaseRef.
 * @return If the function succeeds, it will return reference count of this object.
 */
- (int)releaseRef;
@end


/**
 * @class ZMVideoSDKShareCursorData
 * @brief Represents the cursor position data during screen sharing.
 */
@interface ZMVideoSDKShareCursorData : NSObject

/**
 * @brief The source id of the share cursor.
 */
@property (nonatomic, assign, readonly) unsigned int sourceID;

/**
 * @brief The x value of the coordinate.
 */
@property (nonatomic, assign, readonly) int x;

/**
 * @brief The y value of the coordinate.
 */
@property (nonatomic, assign, readonly) int y;
@end

/**
 * @protocol ZMVideoSDKRawDataPipeDelegate
 * @brief Raw data pipe delegate interface.
 */
@protocol ZMVideoSDKRawDataPipeDelegate <NSObject>
@optional
    
/**
 * @brief Notify if subscribed data received.
 * @param data The pointer of ZMVideoSDKYUVRawDataI420 object.
 */
- (void)onRawDataFrameReceived:(ZMVideoSDKYUVRawDataI420*)data;
    
/**
 * @brief Notify if subscribed data status changed.
 * @param status The rawData status.
 */
- (void)onRawDataStatusChanged:(ZMVideoSDKRawDataStatus)status;

/**
 * @brief Callback when the cursor data of share received.
 * @param info Share cursor data object.
 */
- (void)onShareCursorDataReceived:(ZMVideoSDKShareCursorData *)info;
@end

/**
 * @class ZMVideoSDKRawDataPipe
 * @brief Video/share raw data pipe interface.
 */
@interface ZMVideoSDKRawDataPipe : NSObject

/**
 * @brief Subscribe video/share raw data.
 * @param resolution The subscribe size.
 * @param listener The callback sink object.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)subscribe:(ZMVideoSDKResolution)resolution listener:(id<ZMVideoSDKRawDataPipeDelegate>)listener;
    
/**
 * @brief Unsubscribe video/share raw data.
 * @param listener The callback sink object.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)unSubscribe:(id<ZMVideoSDKRawDataPipeDelegate>)listener;

/**
 * @brief Get the raw data data type.
 * @return Share or Video data type.
 */
- (ZMVideoSDKRawDataType)getRawdataType;

/**
 * @brief Get video status.
 * @return If the function succeeds, the return value is pointer of video status object, otherwise returns nil.
 */
- (ZMVideoSDKVideoStatus* _Nullable)getVideoStatus;

/**
 * @brief Get video device name.
 * @return If the function succeeds, the return value is the video device name, otherwise returns nil.
 */
- (NSString* _Nullable)getVideoDeviceName;

/**
 * @brief Get share status.
 * @return If the function succeeds, the return value is current share status.
 */
- (ZMVideoSDKShareStatus)getShareStatus;

/**
 * @brief Gets the reason why the share capture is paused.
 * @return The current pause reason of the ongoing share.
 * @note If sharing is not paused, the return value is @c ZMVideoSDKShare_Capture_Pause_None.
 */
- (ZMVideoSDKShareCapturePauseReason)getShareCapturePauseReason;

/**
 * @brief Get share type.
 * @return If the function succeeds, the return value is current share type.
 */
- (ZMVideoSDKShareType)getShareType;

/**
 * @brief Get video statistic information.
 * @return If the function succeeds, the return value is the object of ZMVideoSDKVideoStatisticInfo.
 */
- (ZMVideoSDKVideoStatisticInfo* _Nullable)getVideoStatisticInfo;
@end

/**
 * @class ZMVideoSDKCameraControlRequestHandler
 * @brief Camera control request handler object interface.
 */
@interface ZMVideoSDKCameraControlRequestHandler : NSObject

/**
 * @brief Approve the remote camera control request.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)approve;

/**
 * @brief Decline the remote camera control request.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)decline;
@end

/**
 * @class ZMVideoSDKRemoteCameraControlHelper
 * @brief Remote camera control helper object interface.
 */
@interface ZMVideoSDKRemoteCameraControlHelper : NSObject

/**
 * @brief Request to control remote camera.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)requestControlRemoteCamera;

/**
 * @brief Give up control of the remote camera.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)giveUpControlRemoteCamera;

/**
 * @brief Turn the camera to the left.
 * @param range The rotation range, 10 <= range <= 100.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)turnLeft:(unsigned int)range;

/**
 * @brief Turn the camera to the right.
 * @param range rotation range, 10 <= range <= 100.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)turnRight:(unsigned int)range;

/**
 * @brief Turn the camera up.
 * @param range rotation range, 10 <= range <= 100.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)turnUp:(unsigned int)range;

/**
 * @brief Turn the camera down.
 * @param range rotation range, 10 <= range <= 100.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)turnDown:(unsigned int)range;

/**
 * @brief Zoom the camera in.
 * @param range rotation range, 10 <= range <= 100.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)zoomIn:(unsigned int)range;

/**
 * @brief Zoom the camera out.
 * @param range rotation range, 10 <= range <= 100.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)zoomOut:(unsigned int)range;
@end


/**
 * @class ZMVideoSDKUser
 * @brief Zoom Video SDK user information.
 */
@interface ZMVideoSDKUser : NSObject
/**
 * @brief Get the user's id.
 * @return If the function succeeds, the return value is user id, otherwise returns nil.
 */
- (NSString* _Nullable)getUserID;

/**
 * @brief Get the user's custom identity.
 * @return If the function succeeds, the return value is custom id, otherwise returns nil.
 */
- (NSString* _Nullable)getCustomIdentity;

/**
 * @brief Get the name of the user in the session.
 * @return If the function succeeds, the return value is user name, otherwise returns nil.
 */
- (NSString* _Nullable)getUserName;

/**
 * @brief Get the user's reference.
 */
- (NSString* _Nullable)getUserReference;

/**
 * @brief Get the user's audio status.
 * @return Audio status object.
 */
- (ZMVideoSDKAudioStatus* _Nullable)getAudioStatus;
    
/**
 * @brief Determine whether the user is the host.
 * @return YES indicates that the user is the host, otherwise NO.
 */
- (BOOL)isHost;
    
/**
 * @brief Determine whether the user is the manager.
 * @return YES indicates that the user is the manager, otherwise NO.
 */
- (BOOL)isManager;
    
/**
 * @brief Get the user's video statistic information.
 * @return Video statistic information object.
 */
- (ZMVideoSDKVideoStatisticInfo* _Nullable)getVideoStatisticInfo;
    
/**
 * @brief Get the user's share statistic information.
 * @return Share statistic information object.
 */
- (ZMVideoSDKShareStatisticInfo* _Nullable)getShareStatisticInfo;
    
/**
 * @brief Get the user's video pipe.
 * @return Video pipe object.
 */
- (ZMVideoSDKRawDataPipe* _Nullable)getVideoPipe;

/**
 * @brief Gets the user's video canvas.
 * @return If the function succeeds, it will return a ZMVideoSDKVideoCanvas object, otherwise returns nil.
 */
- (ZMVideoSDKVideoCanvas * _Nullable)getVideoCanvas;

/**
 * @brief Get the user's share-action list.
 * @return A list of all share action object.
 */
- (NSArray<ZMVideoSDKShareAction*>* _Nullable)getShareActionList;

/**
 * @brief Get the helper class instance to access the remote camera control.
 * @return If the function succeeds, it will return a remote camera control object, otherwise returns nil.
 */
- (ZMVideoSDKRemoteCameraControlHelper * _Nullable)getRemoteCameraControlHelper;

/**
 * @brief Get the user's multi-camera stream list.
 * @return A list of all streaming cameras pipe object.
 */
- (NSArray<ZMVideoSDKRawDataPipe *>* _Nullable)getMultiCameraStreamList;

/**
 * @brief Set the user's local volume. This does not affect how other participants hear the user.
 * @param volume Value can be >= 0 and <=10. If volume is 0, the user won't be able to hear the related audio.
 * @param isSharingAudio YES means sets the volume of shared audio (such as shared computer audio), otherwise sets the volume of the microphone.
 * @return If successful return YES, otherwise NO.
 * @deprecated Use \link setUserPlaybackVolume:isSharingAudio: \endlink instead.
 */
- (BOOL)setUserVolume:(float)volume isSharingAudio:(BOOL)isSharingAudio DEPRECATED_MSG_ATTRIBUTE("Use -setUserPlaybackVolume:isSharingAudio: instead");

/**
 * @brief Get user volume.
 * @param volume The user volume.
 * @param isSharingAudio YES means gets the volume of shared audio (such as shared computer audio), otherwise gets the volume of the microphone.
 * @return If success return YES, otherwise NO.
 * @deprecated Use \link getUserPlaybackVolume:isSharingAudio: \endlink instead.
 */
- (BOOL)getUserVolume:(float*)volume isSharingAudio:(BOOL)isSharingAudio DEPRECATED_MSG_ATTRIBUTE("Use -getUserPlaybackVolume:isSharingAudio: instead");

/**
 * @brief Determine which audio you can set, shared audio or microphone.
 * @param isShareAudio YES means checks whether you can set the volume of shared audio, otherwise you can set the volume of the microphone.
 * @return If success return YES, otherwise NO.
 * @deprecated Use \link canSetUserPlaybackVolume: \endlink instead.
 */
- (BOOL)canSetUserVolume:(BOOL)isShareAudio DEPRECATED_MSG_ATTRIBUTE("Use -canSetUserPlaybackVolume: instead");

/**
 * @brief Sets the user's local volume. This does not affect how other participants hear the user.
 * @param volume Value can between 0 and 10. If 0, the user won't hear the related audio.
 * @param isSharingAudio YES to set the volume of shared audio (such as shared computer audio; otherwise, sets the microphone volume.
 * @return YES if the operation succeeds; otherwise, NO.
 */
- (BOOL)setUserPlaybackVolume:(float)volume isSharingAudio:(BOOL)isSharingAudio;

/**
 * @brief Gets the local volume.
 * @param volume The user volume.
 * @param isShareAudio YES to get the volume of shared audio(such as shared computer audio); otherwise gets the microphone volume.
 * @return YES if the operation succeeds; otherwise, NO.
 */
- (BOOL)getUserPlaybackVolume:(float*)volume isSharingAudio:(BOOL)isSharingAudio;

/**
 * @brief Checks whether you can set the volume for shared audio or microphone.
 * @param isShareAudio YES to check if you can set the volume of shared audio; otherwise, you can set the volume of the microphone.
 * @return YES if you can set the volume of shared audio; otherwise, NO.
 */
- (BOOL)canSetUserPlaybackVolume:(BOOL)isShareAudio;

/**
 * @brief Gets the current audio level of a remote user.
 * @return The current audio level.
 */
- (unsigned int)getAudioLevel;

/**
 * @brief Used to determine whether I agree to individual video recording.
 * @return YES if the user has individual video recording consent. Otherwise NO.
 */
- (BOOL)hasIndividualRecordingConsent;

/**
 * @brief Send file to current user object.
 * @param filePath The local path of the file.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)transferFile:(NSString *)filePath;

/**
 * @brief check if user is spotlighted.
 * @return If the function succeeds, the return value is YES. Otherwise, this function returns NO.
 */
- (BOOL)isVideoSpotLighted;

/**
 * @brief Determine whether the user is incoming live stream user.
 * @return YES indicates that the user special for incoming live stream, otherwise NO.
 */
- (BOOL)isIncomingLiveStreamUser;

/**
 * @brief Determine whether the user is in a subsession.
 * @return YES indicates that the user is currently in a subsession, otherwise NO.
 */
- (BOOL)isInSubSession;

/**
 * @brief Get the whiteboard sharing status of the user.
 * @return The whiteboard sharing status.
 */
- (ZMVideoSDKWhiteboardStatus)getWhiteboardStatus;

/**
 * @brief Gets the network quality level of the specified data type for the user.
 * @param type The data type, such as audio, video, or share.
 * @return The current network status level for the specified data type.
 */
- (ZMVideoSDKNetworkStatus)getNetworkLevel:(ZMVideoSDKDataType)type;

/**
 * @brief Gets the overall network quality level of the user.
 * @return The overall network status level.
 */
- (ZMVideoSDKNetworkStatus)getOverallNetworkLevel;
@end

/**
 * @class ZMVideoSDKUserHelper
 * @brief User control interface.
 */
@interface ZMVideoSDKUserHelper: NSObject
    
/**
 * @brief Change a specific user's name.
 * @param name The new user name.
 * @param user User in the session.
 * @return YES indicates that name change is success. Otherwise, this function returns NO.
 */
- (BOOL)changeName:(NSString*)name user:(ZMVideoSDKUser*)user;
    
/**
 * @brief Assign a user as the session host.
 * @param user User in the session.
 * @return YES indicates that the user is now the host. Otherwise, this function returns NO.
 */
- (BOOL)makeHost:(ZMVideoSDKUser*)user;
    
/**
 * @brief Assign a user as the session manager.
 * @param user User in the session.
 * @return YES indicates that the user is now the manager. Otherwise, this function returns NO.
 */
- (BOOL)makeManager:(ZMVideoSDKUser*)user;
    
/**
 * @brief Revoke manager rights from a user.
 * @param user User in the session.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success, otherwise not.
 */
- (ZMVideoSDKErrors)revokeManager:(ZMVideoSDKUser*)user;
    
/**
 * @brief Remove user from session.
 * @param user User in the session.
 * @return If the function succeeds, the return value is YES. Otherwise, this function returns NO.
 */
- (BOOL)removeUser:(ZMVideoSDKUser*)user;

/**
 * @brief Reclaim host permission. Allow the user whose role_type = 1 to reclaim the host role.
 * @return If the function succeeds, the return value is YES. Otherwise, this function returns NO.
 */
- (BOOL)reclaimHost;
@end

NS_ASSUME_NONNULL_END

