
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <ZMVideoSDK/ZMVideoSDKAnnotationHelper.h>
#import <ZMVideoSDK/ZMVideoSDKRemoteControlHelper.h>

NS_ASSUME_NONNULL_BEGIN


@interface ZMVideoSDKShareAction : NSObject
/**
 @brief Share source ID.
 */
@property (nonatomic, assign, readonly) unsigned int                  shareSourceId;
/**
 @brief Share status.
 */
@property (nonatomic, assign, readonly) ZMVideoSDKShareStatus         shareStatus;
/**
 @brief Share type.
 */
@property (nonatomic, assign, readonly) ZMVideoSDKShareType           shareType;
/**
 @brief The subscribe fail reason.
 */
@property (nonatomic, assign, readonly) ZMVideoSDKSubscribeFailReason subscribeFailReason;
/**
 @brief Determine whether annotation privilege is enabled.
 */
@property (nonatomic, assign, readonly) BOOL                          isAnnotationPrivilegeEnabled;

/**
 @brief Get the share raw data pipe.
 @return The share pipe. For more information, see {@link ZMVideoSDKRawDataPipe}.
 */
- (ZMVideoSDKRawDataPipe* _Nullable)getSharePipe;

/**
 @brief Gets the render canvas object.
 @return If the function succeeds, the return value is the ZMVideoSDKVideoCanvas object. Otherwise this function fails and returns nil, see {@link ZMVideoSDKVideoCanvas}.
 */
- (ZMVideoSDKVideoCanvas* _Nullable)getShareCanvas;

/**
 @brief Get the helper class instance to access remote control. Only available for controller side.
 @return If the function succeeds, it will return the remote control helper object. For more information, see {@link ZMVideoSDKRemoteControlHelper}.
 */
- (ZMVideoSDKRemoteControlHelper* _Nullable)getRemoteControlHelper;

/**
 @brief Get the list of users I (the controlling user) have agreed to control. Only available for the controlling user.
 @return If the function succeeds, the return value is the list of users I have agreed to control. Otherwise returns nil.
 */
- (NSArray<ZMVideoSDKUser *>* _Nullable)getRemoteControlApprovedUserList;

/**
 @brief Get back all the authority of remote control. Only available for the user themselves.
 @return If the function succeeds, the return value is ZMVideoSDKErrors_Success. Otherwise failed.
 */
- (ZMVideoSDKErrors)revokeRemoteControl;

/**
 @brief Get the controller ID who is currently controlling me (the controlled user). Only available for the controlled user.
 @return If the function succeeds, the return value is the user currently controlling by long-distance. Otherwise returns nil.
 */
- (ZMVideoSDKUser * _Nullable)getCurrentRemoteController;

@end



/**
@brief Share sender interface.
*/
@interface ZMVideoSDKShareSender : NSObject

/**
 @brief Send one frame data.
 @param frameBuffer FrameBuffer YUVI420 buffer.
 @param width Frame width.
 @param height Frame height.
 @param frameLength Buffer length.
 @param format Raw data format.
 @return If the function succeeds, the return value is ZMVideoSDKErrors_Success, otherwise failed. To get extended error information, see {@link ZMVideoSDKErrors}.
 */
- (ZMVideoSDKErrors)sendShareFrame:(char* _Nullable)frameBuffer width:(int)width height:(int)height frameLength:(int)frameLength format:(ZMVideoSDKFrameDataFormat)format;
@end

/**
@brief Share source sink interface.
*/
@protocol ZMVideoSDKShareSource <NSObject>
/**
 @brief Callback for share source can start send raw data.
 @param sender See {@link ZMVideoSDKShareSender}.
 */
-(void)onShareSendStarted:(ZMVideoSDKShareSender* _Nonnull)sender;
/**
 @brief Callback for share source stop send raw data.
 */
-(void)onShareSendStopped;
@end

@interface ZMVideoSDKShareAudioSender : NSObject
/**
 @brief Sends audio raw data.
 @param data The audio data address.
 @param length The audio data length. It must be even numbers.
 @param rate The audio data sampling rate.
 @param channel The channel type. Default type is ZoomVideoSDKAudioChannel_Mono.
 @return If the function succeeds, the return value is ZMVideoSDKErrors_Success, otherwise failed. To get extended error information, see {@link ZMVideoSDKErrors}.
 @note Support sample Rate 44100/48000/50000/50400/.
 */
-(ZMVideoSDKErrors)sendShareAudio:(char * _Nullable)data dataLength:(unsigned int)length sampleRate:(int)rate audioChannel:(ZMVideoSDKAudioChannel)channel;
@end

@protocol ZMVideoSDKShareAudioSource <NSObject>

/**
 @brief Callback for audio source to start sending raw data.
 @param sender See {@link ZMVideoSDKShareAudioSender}.
 */
-(void)onStartSendAudio:(ZMVideoSDKShareAudioSender * _Nonnull)sender;

/**
 @brief Callback for audio source to stop sending raw data.
 */
-(void)onStopSendAudio;
@end

/**
@brief Share option interface.
*/
@interface ZMVideoSDKShareOption : NSObject
/**
 @brief Share option, YES means share computer sound when share screen/window, otherwise not.
 */
@property (nonatomic, assign, readwrite) BOOL isWithDeviceAudio;

/**
 @brief Share option, YES means optimize the frame rate when share screen/window, otherwise not.
 */
@property (nonatomic, assign, readwrite) BOOL isOptimizeForSharedVideo;

@end
/**
 @brief Share helper interface.
 */
@interface ZMVideoSDKShareHelper : NSObject

/**
 @brief Start Share a window.
 @param windowID The App window id.
 @note The CGWindowID contains a unique value within the user session
 representing a window.
 @param option It is a share option object, contain all option of share.
 @return If the function succeeds, the return value is ZMVideoSDKErrors_Success, otherwise failed. To get extended error information, see {@link ZMVideoSDKErrors}.
 */
- (ZMVideoSDKErrors)startShareView:(CGWindowID)windowID shareOption:(ZMVideoSDKShareOption* _Nullable)option;

/**
 @brief Determine if the application's window ID can be shared.
 @return YES indicates the current application window can be shared, otherwise means the app's window handle can't be shared.
 */
- (BOOL)isShareViewValid:(CGWindowID)windowID;

/**
 @brief Start share screen.
 @param monitorID The ID of the monitor that you want to display the shared content.
 @param option It is a share option object, contain all option of share.
 @return If the function succeeds, the return value is ZMVideoSDKErrors_Success. Otherwise failed. To get extended error information, see {@link ZMVideoSDKErrors}.
 */
- (ZMVideoSDKErrors)startShareScreen:(CGDirectDisplayID)monitorID shareOption:(ZMVideoSDKShareOption* _Nullable)option;

/**
 @brief Start share multi-screen.
 @param monitorIDs The IDs of the monitor that you want to display the shared content.
 @param option It is a share option object, contain all option of share.
 @return If the function succeeds, the return value is ZMVideoSDKErrors_Success. Otherwise failed. To get extended error information, see {@link ZMVideoSDKErrors}.
 */
- (ZMVideoSDKErrors)startShareMultiScreen:(NSArray <NSNumber *>*)monitorIDs shareOption:(ZMVideoSDKShareOption* _Nullable)option;
 
/**
 @brief Start sharing the computer audio only.
 @return If the function succeeds, the return value is ZMVideoSDKErrors_Success. Otherwise failed. To get extended error information, see {@link ZMVideoSDKErrors}.
 */
- (ZMVideoSDKErrors)startShareComputerAudio;

/**
 @brief Stop view or screen share.
 @return If the function succeeds, the return value is ZMVideoSDKErrors_Success. Otherwise failed. To get extended error information, see {@link ZMVideoSDKErrors}.
 */
- (ZMVideoSDKErrors)stopShare;
  
/**
 @brief Pause share.
 @return If the function succeeds, the return value is ZMVideoSDKErrors_Success. Otherwise failed. To get extended error information, see {@link ZMVideoSDKErrors}.
 */
- (ZMVideoSDKErrors)pauseShare;

/**
 @brief Resume share.
 @return If the function succeeds, the return value is ZMVideoSDKErrors_Success. Otherwise failed. To get extended error information, see {@link ZMVideoSDKErrors}.
 */
- (ZMVideoSDKErrors)resumeShare;

/**
 @brief Determine whether the current user is sharing.
 @return YES indicates the current user is sharing, otherwise NO.
 */
- (BOOL)isSharingOut;
    
/**
 @brief Determine whether the current user is sharing the screen.
 @return YES indicates the current user is sharing the screen, otherwise NO.
 */
- (BOOL)isScreenSharingOut;
    
/**
 @brief Determine whether other user is sharing.
 @return YES indicates another user is sharing, otherwise NO.
 */
- (BOOL)isOtherSharing;
    
/**
 @brief Lock sharing the view or screen. Only the host can call this method.
 @param lock YES to lock sharing.
 @return If the function succeeds, the return value is ZMVideoSDKErrors_Success, otherwise failed. To get extended error information, see {@link ZMVideoSDKErrors}.
 */
- (ZMVideoSDKErrors)lockShare:(BOOL)lock;
    
/**
 @brief Determine whether sharing the view or screen is locked.
 @return YES indicates that sharing is locked, otherwise NO.
 */
- (BOOL)isShareLocked;

/**
 @brief Enable or disable participants can share simultaneously.
 @param enable True to enable. False to disable.
 @warning When you switch multi share from enable to disable, all sharing will be stopped when session has two or more users is sharing.
 @return If the function succeeds, the return value is ZMVideoSDKErrors_Success, otherwise failed. To get extended error information, see {@link ZMVideoSDKErrors}.
 */
- (ZMVideoSDKErrors)enableMultiShare:(BOOL)enable;

/**
 @brief Determine whether multi share is enabled or not.
 @return YES indicates enabled, otherwise NO.
 */
- (BOOL)isMultiShareEnabled;

/**
 @brief Enable or disable the computer sound when sharing, the SDK does not support sharing raw data audio, for example, when you've enabled virtual speaker.
 @param enable YES to enable. NO to disable.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)enableShareDeviceAudio:(BOOL)enable;

/**
 @brief Determine if the SDK has enabled share computer sound. This reflects the execution status of 'enableShareDeviceAudio' instead of 'startShareComputerAudio'.

 @return YES if enabled, otherwise not.
 */
- (BOOL)isShareDeviceAudioEnabled;

/**
 @brief Enable or disable the optimization of frame rate, you can enable it when there is video in shared content.
 @param enable YES indicates to enable. NO disable.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)enableOptimizeForSharedVideo:(BOOL)enable;

/**
 @brief Determine if optimization for video is enabled.
 @return YES means enabled. Otherwise not.
 */
- (BOOL)isOptimizeForSharedVideoEnabled;

/**
 @brief Start sharing a camera feed specified by the cameraID as the second camera.
 @param cameraID The camera ID.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 @note This cameraID must be a different camera than the one sending your primary video.
 */
- (ZMVideoSDKErrors)startShare2ndCamera:(NSString* _Nullable)cameraID;

/**
 @brief Subscribe to the raw data stream of the camera that is shared as the second camera.
 @param dataHandler The callback sink object.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)subscribeMyShareCamera:(id<ZMVideoSDKRawDataPipeDelegate> _Nonnull)dataHandler DEPRECATED_MSG_ATTRIBUTE("Use [ZMVideoSDKRawDataPipe subscribe: listener:] instead");

/**
 @brief Unsubscribe to the raw data stream of the camera that is shared as the second camera.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)unSubscribeMyShareCamera DEPRECATED_MSG_ATTRIBUTE("Use [ZMVideoSDKRawDataPipe: unSubscribe:] instead");

/**
 @brief Shares an external source.
 @param shareSource External share source. To get extended error information, see {@link ZMVideoSDKShareSource}.
 @param audioSource External audio source. To get extended error information, see {@link ZMVideoSDKShareAudioSource}.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success. Otherwise failed. To get extended error information, see {@link ZMVideoSDKErrors}.
 @note If audioSource is non-null, it means share user-defined audio at the same time.
 */
- (ZMVideoSDKErrors)startSharingExternalSource:(id<ZMVideoSDKShareSource> _Nonnull)shareSource audioSource:(id<ZMVideoSDKShareAudioSource> _Nullable)audioSource DEPRECATED_MSG_ATTRIBUTE("Use -startSharingExternalSource: audioSource: isPlaying: instead");

/**
 @brief Shares an external source.
 @param shareSource External share source. To get extended error information, see {@link ZMVideoSDKShareSource}.
 @param audioSource External audio source. To get extended error information, see {@link ZMVideoSDKShareAudioSource}.
 @param isPlaying YES to play shared audio raw data, false not to play.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success. Otherwise failed. To get extended error information, see {@link ZMVideoSDKErrors}.
 @note If audioSource is non-null, it means share user-defined audio at the same time.
 */
- (ZMVideoSDKErrors)startSharingExternalSource:(id<ZMVideoSDKShareSource> _Nonnull)shareSource audioSource:(id<ZMVideoSDKShareAudioSource> _Nullable)audioSource isPlaying:(BOOL)isPlaying;
/**
 @brief Starts sharing the pure external audio source.
 @param audioSource the pointer of external audio source object. To get extended error information, see {@link ZMVideoSDKShareAudioSource}.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success. Otherwise failed. To get extended error information, see {@link ZMVideoSDKErrors}.
 */
- (ZMVideoSDKErrors)startSharePureAudioSource:(id<ZMVideoSDKShareAudioSource> _Nonnull)audioSource DEPRECATED_MSG_ATTRIBUTE("Use -startSharePureAudioSource: isPlaying: instead");

/**
 @brief Starts sharing the pure external audio source.
 @param audioSource the pointer of external audio source object. To get extended error information, see {@link ZMVideoSDKShareAudioSource}.
 @param isPlaying YES to play shared audio raw data, false not to play.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success. Otherwise failed. To get extended error information, see {@link ZMVideoSDKErrors}.
 */
- (ZMVideoSDKErrors)startSharePureAudioSource:(id<ZMVideoSDKShareAudioSource> _Nonnull)audioSource isPlaying:(BOOL)isPlaying;

/**
 @brief Whether annotation feature is supported or not.
 @return YES if support. Otherwise not.
 */
- (BOOL)isAnnotationFeatureSupport;

/**
 @brief Disable or enable viewer's annotation by the share owner.
 @param disable YES mean disable, NO, mean enable.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success. Otherwise failed.
 @warning Only the share owner can call this function.
 */
- (ZMVideoSDKErrors)disableViewerAnnotation:(BOOL)disable;

/**
 @brief Whether annotation on current sharing is disabled or not.
 @return YES if disable. Otherwise not.
 @warning Only the share owner can call this function.
 */
- (BOOL)isViewerAnnotationDisabled;

/**
 @brief Creates annotation helper based on shared view.
 @param view The shared view. Pass the nil will return the helper for self sharing.
 @return If the function succeeds, it will return the object of ZMVideoSDKAnnotationHelper. Otherwise nil.
 @warning When the share owner not  support the feature of annotate, the others should not do annotate in that case.
 */
- (ZMVideoSDKAnnotationHelper* _Nullable)createAnnotationHelper:(NSView* _Nullable)view;

/**
 @brief Destroys annotation helper.
 @param helper The object of ZMVideoSDKAnnotationHelper.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success. Otherwise failed. To get extended error information, see {@link ZMVideoSDKErrors}.
 */
- (ZMVideoSDKErrors)destroyAnnotationHelper:(ZMVideoSDKAnnotationHelper* _Nonnull)helper;

/**
 @brief Enable or disable local playback of shared audio raw data.
 @param bPlay YES to play shared audio raw data, false not to play it.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success. Otherwise failed. To get extended error information, see {@link ZMVideoSDKErrors}.
 */
- (ZMVideoSDKErrors)enablePlaySharingAudioRawdata:(BOOL)bPlay;
@end
NS_ASSUME_NONNULL_END
