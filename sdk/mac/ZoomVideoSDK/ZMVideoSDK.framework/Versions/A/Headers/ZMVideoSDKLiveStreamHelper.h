/**
 * @file ZMVideoSDKLiveStreamHelper.h
 * @brief This file defines the interfaces for managing outgoing and incoming live streaming
 */


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZMVideoSDKLiveStreamSetting
 * @brief Live stream settings configuration class for Zoom Video SDK.
 * This class contains layout and close caption settings for live streaming.
 */
@interface ZMVideoSDKLiveStreamSetting : NSObject

/**
 * The layout type for the live stream.
 */
@property(nonatomic, assign) ZMVideoSDKLiveStreamLayout layout;

/**
 * The close caption setting for the live stream.
 */
@property(nonatomic, assign) ZMVideoSDKLiveStreamCloseCaption closeCaption;
@end

/**
 * @class ZMVideoSDKLiveStreamParams
 * @brief Live stream parameters for starting live stream.
 * This class contains all the necessary parameters to configure and start a live stream.
 */
@interface ZMVideoSDKLiveStreamParams : NSObject

/**
 * The live stream URL where the stream will be sent (e.g., YouTube, Facebook Live).
 */
@property(nonatomic, copy, nullable) NSString* streamUrl;

/**
 * The live stream key for authentication with the streaming platform.
 */
@property(nonatomic, copy, nullable) NSString* key;

/**
 * The live stream broadcast URL where viewers can watch the stream.
 */
@property(nonatomic, copy, nullable) NSString* broadcastUrl;

/**
 * Live stream settings including layout and close caption options.
 */
@property(nonatomic, strong, nullable) ZMVideoSDKLiveStreamSetting* setting;
@end

/**
 * @class ZMVideoSDKLiveStreamHelper
 * @brief Helper class for managing outgoing live stream.
 */
@interface ZMVideoSDKLiveStreamHelper : NSObject

/**
 * @brief Start live stream.
 * @param streamUrl The live stream url.
 * @param url The live stream broadcast url.
 * @param key The live stream key.
 * @return If the function succeeds, it will return @c ZMVideoSDKErrors_Success.
 * @deprecated Use \link startLiveStreamWithParams: \endlink instead.
 */
- (ZMVideoSDKErrors)startLiveStream:(NSString *)streamUrl broadcastUrl:(NSString *)url liveStreamKey:(NSString *)key DEPRECATED_MSG_ATTRIBUTE("Use -startLiveStreamWithParams: instead");
    
/**
 * @brief Stop live stream.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)stopLiveStream;
    
/**
 * @brief Determine if can start living stream.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)canStartLiveStream;

/**
 * @brief Start a live stream of the current session using ZMVideoSDKLiveStreamParams.
 * @param param The live stream parameters containing URL, key, broadcast URL and settings.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)startLiveStreamWithParams:(ZMVideoSDKLiveStreamParams *)param;

/**
 * @brief Get the current live stream settings for the current session.
 * @return The current live stream settings. Returns nil if no live stream is active.
 */
- (ZMVideoSDKLiveStreamSetting * _Nullable)getCurrentLiveStreamSetting;

/**
 * @brief Update the live stream settings for the current session.
 * @param setting The new live stream settings to apply.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)updateLiveStreamSetting:(ZMVideoSDKLiveStreamSetting *)setting;

/**
 * @brief Check if the current user can get or update live stream settings.
 * @return YES if the user can get or update live stream settings, NO otherwise.
 * @note Live stream must be started, and only the person who started the live stream can get or update the setting.
 */
- (BOOL)canGetOrUpdateLiveStreamSetting;
@end


/**
 * @class ZMVideoSDKIncomingLiveStreamStatus
 * @brief Status information for an incoming live stream.
 */
@interface ZMVideoSDKIncomingLiveStreamStatus : NSObject
/**
 * @brief The incoming live stream ID.
 */
@property(nonatomic, copy, readonly, nullable)NSString* strStreamKeyID;
/**
 * @brief Is the streaming software (such as OBS) connected to the Zoom platform.
 */
@property(nonatomic, assign, readonly)BOOL isRTMPConnected;
/**
 * @brief Has the video stream been pushed to the session.
 */
@property(nonatomic, assign, readonly)BOOL isStreamPushed;

@end


/**
 * @class ZMVideoSDKIncomingLiveStreamHelper
 * @brief Interface for managing incoming live streams.
 */
@interface ZMVideoSDKIncomingLiveStreamHelper : NSObject
/**
 * @brief Bind incoming live stream with a stream key ID.
 * @param strStreamKeyID The stream key ID to bind.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)bindIncomingLiveStream:(NSString *)strStreamKeyID;
/**
 * @brief Unbind the bound incoming live stream.
 * @param strStreamKeyID The stream key ID you want to unbind.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)unbindIncomingLiveStream:(NSString *)strStreamKeyID;
/**
 * @brief Get the status of the bound streams.
 * @return If the function succeeds, it will return @c ZMVideoSDKErrors_Success, otherwise failed.
 * @note Will receive callback "-onIncomingLiveStreamStatusResponse:"
 */
- (ZMVideoSDKErrors)getIncomingLiveStreamStatus;
/**
 * @brief Start the bound stream as a special participant.
 * @param strStreamKeyID The stream key ID you want to start.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)startIncomingLiveStream:(NSString *)strStreamKeyID;
/**
 * @brief Stop the bound stream as a special participant.
 * @param strStreamKeyID The stream key ID to stop.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)stopIncomingLiveStream:(NSString *)strStreamKeyID;
@end
NS_ASSUME_NONNULL_END
