/**
 * @file ZMVideoSDKShareHelper.h
 * @brief Defines interfaces and classes for managing screen and window sharing, share preprocessing, remote control, annotation, and audio sharing features in the Zoom Video SDK.
 */


#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <ZMVideoSDK/ZMVideoSDKAnnotationHelper.h>
#import <ZMVideoSDK/ZMVideoSDKRemoteControlHelper.h>
#import <ZMVideoSDK/ZMVideoSDKWhiteboardHelper.h>
NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZMVideoSDKSharePreprocessParam
 * @brief Parameters for share preprocessing including the type and screen/window identifiers.
 */
@interface ZMVideoSDKSharePreprocessParam : NSObject
/**
 * @brief The share pre-process type.
 */
@property(nonatomic,assign)ZMVideoSDKSharePreprocessType type;
/**
 * @brief The screen id that to share and pre-process.
 */
@property(nonatomic,assign)CGDirectDisplayID monitorID;
/**
 * @brief The window handle that to share and pre-process.
 */
@property(nonatomic,assign)CGWindowID windowID;
/**
 * @brief The application process id that to share and pre-process.
 */
@property(nonatomic,assign)pid_t processID;
@end


/**
 * @class ZMVideoSDKSharePreprocessSender
 * @brief Interface to send preprocessed YUV raw data frames back to the SDK.
 */
@interface ZMVideoSDKSharePreprocessSender : NSObject
/**
 * @brief Send preprocessed data.
 * @param rawdata The processed data object.
 * @return If the function succeeds, the return value is @c ZMVideoSDKErrors_Success, otherwise failed.
 */
- (ZMVideoSDKErrors)sendPreprocessedData:(ZMVideoSDKYUVRawDataI420*)rawdata;
@end


/**
 * @protocol ZMVideoSDKSharePreprocessor
 * @brief Protocol to handle preprocessing of raw share data before sending it out. Implement this protocol to receive raw YUV data frames during screen sharing for custom preprocessing.
 */
@protocol ZMVideoSDKSharePreprocessor <NSObject>
/**
 * @brief You will receive this callback when calling 'startShareWithPreprocessing' successfully.
 * @param rawdata You can get the YUV data address through this object and then pre-process the data.
 * @param sender Use this object to send the processed data out.
 */
- (void)onCapturedRawDataReceived:(ZMVideoSDKYUVRawDataI420*)rawdata sharePreprocessSender:(ZMVideoSDKSharePreprocessSender * _Nonnull)sender;

/**
 * @brief You will receive this callback when call 'stopShare' successfully. In this event notification, you can perform some stop and destroy actions if necessary.
 */
- (void)onShareStopped;
@end


/**
 * @class ZMVideoSDKShareAction
 * @brief Represents the state and control interfaces of a share action in a Zoom session.
 */
@interface ZMVideoSDKShareAction : NSObject
/**
 * @brief Share source ID.
 */
@property (nonatomic, assign, readonly) unsigned int                  shareSourceId;
/**
 * @brief Share status.
 */
@property (nonatomic, assign, readonly) ZMVideoSDKShareStatus         shareStatus;
/**
 * @brief Share type.
 */
@property (nonatomic, assign, readonly) ZMVideoSDKShareType           shareType;
/**
 * @brief Gets the reason why the share capture is paused.
 * @note If sharing is not paused, the return value is @c ZMVideoSDKShare_Capture_Pause_None.
 */
@property (nonatomic, assign, readonly) ZMVideoSDKShareCapturePauseReason shareCapturePauseReason;

/**
 * @brief The subscribe fail reason.
 */
@property (nonatomic, assign, readonly) ZMVideoSDKSubscribeFailReason subscribeFailReason;
/**
 * @brief Determine whether annotation privilege is enabled.
 */
@property (nonatomic, assign, readonly) BOOL                          isAnnotationPrivilegeEnabled;

/**
 * @brief Get the size of the share content.
 * @return The size of share content.
 */
- (NSSize)getShareSourceContentSize;

/**
 * @brief Get the share raw data pipe.
 * @return If the function succeeds, the return value is the share pipe object. Otherwise this function fails and returns nil.
 */
- (ZMVideoSDKRawDataPipe* _Nullable)getSharePipe;

/**
 * @brief Gets the render canvas object.
 * @return If the function succeeds, the return value is the ZMVideoSDKVideoCanvas object. Otherwise this function fails and returns nil.
 */
- (ZMVideoSDKVideoCanvas* _Nullable)getShareCanvas;

/**
 * @brief Get the helper class instance to access remote control. Only available for controller side.
 * @return If the function succeeds, it will return the remote control helper object. Otherwise returns nil.
 */
- (ZMVideoSDKRemoteControlHelper* _Nullable)getRemoteControlHelper;

/**
 * @brief Get the list of users I (the controlling user) have agreed to control. Only available for the controlling user.
 * @return If the function succeeds, the return value is the list of users I have agreed to control. Otherwise returns nil.
 */
- (NSArray<ZMVideoSDKUser *>* _Nullable)getRemoteControlApprovedUserList;

/**
 * @brief Get back all the authority of remote control. Only available for the user themselves.
 * @return If the function succeeds, the return value is ZMVideoSDKErrors_Success. Otherwise failed.
 */
- (ZMVideoSDKErrors)revokeRemoteControl;

/**
 * @brief Get the controller ID who is currently controlling me (the controlled user). Only available for the controlled user.
 * @return If the function succeeds, the return value is the user currently controlling by long-distance. Otherwise returns nil.
 */
- (ZMVideoSDKUser * _Nullable)getCurrentRemoteController;

@end



/**
 * @class ZMVideoSDKShareSender
 * @brief Interface to send video share frame data.
 */
@interface ZMVideoSDKShareSender : NSObject

/**
 * @brief Send one frame data.
 * @param frameBuffer FrameBuffer YUVI420 buffer.
 * @param width Frame width.
 * @param height Frame height.
 * @param frameLength Buffer length.
 * @param format Raw data format.
 * @return If the function succeeds, the return value is @c ZMVideoSDKErrors_Success, otherwise failed.
 */
- (ZMVideoSDKErrors)sendShareFrame:(char* _Nullable)frameBuffer width:(int)width height:(int)height frameLength:(int)frameLength format:(ZMVideoSDKFrameDataFormat)format;
@end


/**
 * @protocol ZMVideoSDKShareSource
 * @brief Protocol for external share source to send raw data.
 */
@protocol ZMVideoSDKShareSource <NSObject>
/**
 * @brief Callback for share source can start send raw data.
 * @param sender The object used to send share data.
 */
- (void)onShareSendStarted:(ZMVideoSDKShareSender* _Nonnull)sender;
/**
 * @brief Callback for share source stop send raw data.
 */
- (void)onShareSendStopped;
@end


/**
 * @class ZMVideoSDKShareAudioSender
 * @brief Interface to send share audio raw data.
 */
@interface ZMVideoSDKShareAudioSender : NSObject
/**
 * @brief Sends audio raw data.
 * @param data The audio data address.
 * @param length The audio data length. It must be even numbers.
 * @param rate The audio data sampling rate.
 * @param channel The channel type. Default type is ZoomVideoSDKAudioChannel_Mono.
 * @return If the function succeeds, the return value is @c ZMVideoSDKErrors_Success, otherwise failed.
 * @note Support sample Rate 44100/48000/50000/50400/.
 */
- (ZMVideoSDKErrors)sendShareAudio:(char * _Nullable)data dataLength:(unsigned int)length sampleRate:(int)rate audioChannel:(ZMVideoSDKAudioChannel)channel;
@end


/**
 * @protocol ZMVideoSDKShareAudioSource
 * @brief Protocol for external share audio source.
 */
@protocol ZMVideoSDKShareAudioSource <NSObject>

/**
 * @brief Callback for audio source to start sending raw data.
 * @param sender The object used to send raw audio data.
 */
- (void)onStartSendAudio:(ZMVideoSDKShareAudioSender * _Nonnull)sender;

/**
 * @brief Callback for audio source to stop sending raw data.
 */
- (void)onStopSendAudio;
@end


/**
 * @class ZMVideoSDKShareOption
 * @brief Configuration options for sharing.
 */
@interface ZMVideoSDKShareOption : NSObject
/**
 * @brief Share option, YES means share computer sound when share screen/window, otherwise not.
 */
@property (nonatomic, assign, readwrite) BOOL isWithDeviceAudio;

/**
 * @brief Share option, YES means optimize the frame rate when share screen/window, otherwise not.
 */
@property (nonatomic, assign, readwrite) BOOL isOptimizeForSharedVideo;

@end


/**
 * @class ZMVideoSDKShareHelper
 * @brief Main helper class managing sharing.
 */
@interface ZMVideoSDKShareHelper : NSObject

/**
 * @brief Start Share a window.
 * @param windowID The App window id.
 * @param option It is a share option object, contain all option of share.
 * @return If the function succeeds, the return value is @c ZMVideoSDKErrors_Success, otherwise failed.
 * @note The CGWindowID contains a unique value within the user session representing a window.
 */
- (ZMVideoSDKErrors)startShareView:(CGWindowID)windowID shareOption:(ZMVideoSDKShareOption* _Nullable)option;

/**
 * @brief Starts sharing a specific application process.
 * @param processID The process identifier of the target application. Must be valid in the current user session.
 * @param option An optional share settings object containing configuration options for the share.
 * @return If the function succeeds, the return value is @c ZMVideoSDKErrors_Success. Otherwise the method failed.
 * @note The @c processID must be a valid process identifier in the current user session.
 */
- (ZMVideoSDKErrors)startShareApplication:(pid_t)processID shareOption:(ZMVideoSDKShareOption* _Nullable)option;

/**
 * @brief Determine if the application's window ID can be shared.
 * @param windowID The App window ID to be checked.
 * @return YES indicates the current application window can be shared, otherwise means the app's window handle can't be shared.
 */
- (BOOL)isShareViewValid:(CGWindowID)windowID;

/**
 * @brief Start share screen.
 * @param monitorID The ID of the monitor that you want to display the shared content.
 * @param option It is a share option object, contain all option of share.
 * @return If the function succeeds, the return value is @c ZMVideoSDKErrors_Success. Otherwise failed.
 */
- (ZMVideoSDKErrors)startShareScreen:(CGDirectDisplayID)monitorID shareOption:(ZMVideoSDKShareOption* _Nullable)option;

/**
 * @brief Start share multi-screen.
 * @param monitorIDs The IDs of the monitor that you want to display the shared content.
 * @param option It is a share option object, contain all option of share.
 * @return If the function succeeds, the return value is @c ZMVideoSDKErrors_Success. Otherwise failed.
 */
- (ZMVideoSDKErrors)startShareMultiScreen:(NSArray <NSNumber *>*)monitorIDs shareOption:(ZMVideoSDKShareOption* _Nullable)option;
 
/**
 * @brief Start sharing the computer audio only.
 * @return If the function succeeds, the return value is @c ZMVideoSDKErrors_Success. Otherwise failed.
 */
- (ZMVideoSDKErrors)startShareComputerAudio;

/**
 * @brief Stop view or screen share.
 * @return If the function succeeds, the return value is @c ZMVideoSDKErrors_Success. Otherwise failed.
 */
- (ZMVideoSDKErrors)stopShare;
  
/**
 * @brief Pause share.
 * @return If the function succeeds, the return value is @c ZMVideoSDKErrors_Success. Otherwise failed.
 */
- (ZMVideoSDKErrors)pauseShare;

/**
 * @brief Resume share.
 * @return If the function succeeds, the return value is @c ZMVideoSDKErrors_Success. Otherwise failed.
 */
- (ZMVideoSDKErrors)resumeShare;

/**
 * @brief Determine whether the current user is sharing.
 * @return YES indicates the current user is sharing, otherwise NO.
 */
- (BOOL)isSharingOut;
    
/**
 * @brief Determine whether the current user is sharing the screen.
 * @return YES indicates the current user is sharing the screen, otherwise NO.
 */
- (BOOL)isScreenSharingOut;
    
/**
 * @brief Determine whether other user is sharing.
 * @return YES indicates another user is sharing, otherwise NO.
 */
- (BOOL)isOtherSharing;
    
/**
 * @brief Lock sharing the view or screen. Only the host can call this method.
 * @param lock YES to lock sharing.
 * @return If the function succeeds, the return value is @c ZMVideoSDKErrors_Success, otherwise failed.
 */
- (ZMVideoSDKErrors)lockShare:(BOOL)lock;
    
/**
 * @brief Determine whether sharing the view or screen is locked.
 * @return YES indicates that sharing is locked, otherwise NO.
 */
- (BOOL)isShareLocked;

/**
 * @brief Enable or disable participants can share simultaneously.
 * @param enable YES to enable. NO to disable.
 * @return If the function succeeds, the return value is @c ZMVideoSDKErrors_Success, otherwise failed.
 * @warning When you switch multi share from enable to disable, all sharing will be stopped when session has two or more users is sharing.
 */
- (ZMVideoSDKErrors)enableMultiShare:(BOOL)enable;

/**
 * @brief Determine whether multi share is enabled or not.
 * @return YES indicates enabled, otherwise NO.
 */
- (BOOL)isMultiShareEnabled;

/**
 * @brief Enable or disable the computer sound when sharing, the SDK does not support sharing raw data audio, for example, when you've enabled virtual speaker.
 * @param enable YES to enable. NO to disable.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)enableShareDeviceAudio:(BOOL)enable;

/**
 * @brief Determine if the SDK has enabled share computer sound. This reflects the execution status of 'enableShareDeviceAudio' instead of 'startShareComputerAudio'.
 * @return YES if enabled, otherwise not.
 */
- (BOOL)isShareDeviceAudioEnabled;

/**
 * @brief Enable or disable the optimization of frame rate, you can enable it when there is video in shared content.
 * @param enable YES indicates to enable. NO disable.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)enableOptimizeForSharedVideo:(BOOL)enable;

/**
 * @brief Determine if optimization for video is enabled.
 * @return YES means enabled. Otherwise not.
 */
- (BOOL)isOptimizeForSharedVideoEnabled;

/**
 * @brief Start sharing a camera feed specified by the cameraID as the second camera.
 * @param cameraID The camera ID.
 * @return If the function succeeds, it will return @c ZMVideoSDKErrors_Success.
 * @note This cameraID must be a different camera than the one sending your primary video.
 */
- (ZMVideoSDKErrors)startShare2ndCamera:(NSString* _Nullable)cameraID;

/**
 * @brief Subscribe to the raw data stream of the camera that is shared as the second camera.
 * @param dataHandler The callback sink object.
 * @return If the function succeeds, it will return @c ZMVideoSDKErrors_Success.
 * @deprecated Use \link ZMVideoSDKRawDataPipe::subscribe:listener: \endlink instead.
 */
- (ZMVideoSDKErrors)subscribeMyShareCamera:(id<ZMVideoSDKRawDataPipeDelegate> _Nonnull)dataHandler DEPRECATED_MSG_ATTRIBUTE("Use [ZMVideoSDKRawDataPipe subscribe: listener:] instead");

/**
 * @brief Unsubscribe to the raw data stream of the camera that is shared as the second camera.
 * @return If the function succeeds, it will return @c ZMVideoSDKErrors_Success.
 * @deprecated Use \link ZMVideoSDKRawDataPipe::unSubscribe: \endlink instead.
 */
- (ZMVideoSDKErrors)unSubscribeMyShareCamera DEPRECATED_MSG_ATTRIBUTE("Use [ZMVideoSDKRawDataPipe: unSubscribe:] instead");

/**
 * @brief Shares an external source.
 * @param shareSource External share source.
 * @param audioSource External audio source.
 * @return If the function succeeds, it will return @c ZMVideoSDKErrors_Success. Otherwise failed.
 * @note If audioSource is non-null, it means share user-defined audio at the same time.
 * @deprecated Use \link ZMVideoSDKShareHelper::startSharingExternalSource:audioSource:isPlaying: \endlink instead.
 */
- (ZMVideoSDKErrors)startSharingExternalSource:(id<ZMVideoSDKShareSource> _Nonnull)shareSource audioSource:(id<ZMVideoSDKShareAudioSource> _Nullable)audioSource DEPRECATED_MSG_ATTRIBUTE("Use -startSharingExternalSource: audioSource: isPlaying: instead");

/**
 * @brief Shares an external source.
 * @param shareSource External share source.
 * @param audioSource External audio source.
 * @param isPlaying YES to play shared audio raw data, false not to play.
 * @return If the function succeeds, it will return @c ZMVideoSDKErrors_Success. Otherwise failed.
 * @note If audioSource is non-null, it means share user-defined audio at the same time.
 */
- (ZMVideoSDKErrors)startSharingExternalSource:(id<ZMVideoSDKShareSource> _Nonnull)shareSource audioSource:(id<ZMVideoSDKShareAudioSource> _Nullable)audioSource isPlaying:(BOOL)isPlaying;
/**
 * @brief Starts sharing the pure external audio source.
 * @param audioSource the pointer of external audio source object.
 * @return If the function succeeds, it will return @c ZMVideoSDKErrors_Success. Otherwise failed.
 * @deprecated Use \link ZMVideoSDKShareHelper::startSharePureAudioSource:isPlaying: \endlink instead.
 */
- (ZMVideoSDKErrors)startSharePureAudioSource:(id<ZMVideoSDKShareAudioSource> _Nonnull)audioSource DEPRECATED_MSG_ATTRIBUTE("Use -startSharePureAudioSource: isPlaying: instead");

/**
 * @brief Starts sharing the pure external audio source.
 * @param audioSource the pointer of external audio source object.
 * @param isPlaying YES to play shared audio raw data, false not to play.
 * @return If the function succeeds, it will return @c ZMVideoSDKErrors_Success. Otherwise failed.
 */
- (ZMVideoSDKErrors)startSharePureAudioSource:(id<ZMVideoSDKShareAudioSource> _Nonnull)audioSource isPlaying:(BOOL)isPlaying;

/**
 * @brief Whether annotation feature is supported or not.
 * @return YES if support. Otherwise not.
 */
- (BOOL)isAnnotationFeatureSupport;

/**
 * @brief Disable or enable viewer's annotation by the share owner.
 * @param disable YES mean disable, NO, mean enable.
 * @return If the function succeeds, it will return @c ZMVideoSDKErrors_Success. Otherwise failed.
 * @warning Only the share owner can call this function.
 */
- (ZMVideoSDKErrors)disableViewerAnnotation:(BOOL)disable;

/**
 * @brief Whether annotation on current sharing is disabled or not.
 * @return YES if disable. Otherwise not.
 * @warning Only the share owner can call this function.
 */
- (BOOL)isViewerAnnotationDisabled;

/**
 * @brief Creates annotation helper based on shared view.
 * @param view The shared view. Pass the nil will return the helper for self sharing.
 * @return If the function succeeds, it will return the object of ZMVideoSDKAnnotationHelper. Otherwise nil.
 * @warning When the share owner not  support the feature of annotate, the others should not do annotate in that case.
 * @warning If the video aspect mode is set to ZMVideoSDKVideoAspect_Full_Filled, this function will return nil.
 */
- (ZMVideoSDKAnnotationHelper* _Nullable)createAnnotationHelper:(NSView* _Nullable)view;

/**
 * @brief Destroys annotation helper.
 * @param helper The object of ZMVideoSDKAnnotationHelper.
 * @return If the function succeeds, it will return @c ZMVideoSDKErrors_Success. Otherwise failed.
 */
- (ZMVideoSDKErrors)destroyAnnotationHelper:(ZMVideoSDKAnnotationHelper* _Nonnull)helper;

/**
 * @brief Sets the vanishing tool time.
 * @param displayTime The time in milliseconds the tool remains visible before fading.
 * @param vanishingTime The time in milliseconds for the tool to fade out after displayTime.
 * @return If the function succeeds, it will return @c ZMVideoSDKErrors_Success. Otherwise failed.
 * @note This setting only takes effect for the user's own share.
 *       The displayTime can be 0 or up to 15000 milliseconds (15 seconds).
 *       The vanishingTime must be greater than 1000 milliseconds (1 second) and less than or equal to 15000 milliseconds (15 seconds).
 */
- (ZMVideoSDKErrors)setAnnotationVanishingToolTime:(unsigned int)displayTime vanishingTime:(unsigned int)vanishingTime;

 /**
  * @brief Gets the current vanishing tool time settings.
  * @param displayTime [out] The time in milliseconds the tool remains visible before fading.
  * @param vanishingTime [out] The time in milliseconds for the tool to fade out after displayTime.
  * @note This function can only retrieve the timer settings for your own share.
  * @return If the function succeeds, it will return ZMVideoSDKErrors_Success. Otherwise failed.
  */
- (ZMVideoSDKErrors)getAnnotationVanishingToolTime:(unsigned int*)displayTime vanishingTime:(unsigned int*)vanishingTime;

/**
 * @brief Enable or disable local playback of shared audio raw data.
 * @param bPlay YES to play shared audio raw data, false not to play it.
 * @return If the function succeeds, it will return @c ZMVideoSDKErrors_Success. Otherwise failed.
 */
- (ZMVideoSDKErrors)enablePlaySharingAudioRawdata:(BOOL)bPlay;

/**
 * @brief Start share preprocessing.
 * @param param The share preprocessing parameters.
 * @param preprocessor Object that handles preprocessing events.
 * @return If the function succeeds, it will return  @c ZMVideoSDKErrors_Success. Otherwise failed.
 */
- (ZMVideoSDKErrors)startShareWithPreprocessing:(ZMVideoSDKSharePreprocessParam* _Nonnull)param sharePreprocessor:(id<ZMVideoSDKSharePreprocessor> _Nonnull)preprocessor;

/**
 @brief Returns an instance to manage whiteboard during a video SDK session.
 @return If the function succeeds, it will return the whiteboard helper object.
 */
- (ZMVideoSDKWhiteboardHelper* _Nullable)getWhiteboardHelper;
@end
NS_ASSUME_NONNULL_END
