/**
 * @file ZMVideoSDKBroadcastStreamingViewer.h
 * @brief This file defines the interfaces for broadcast streaming viewer.
 */


#import <Foundation/Foundation.h>
#import <ZMVideoSDK/ZMVideoSDKUserHelper.h>
#import <ZMVideoSDK/ZMVideoSDKAudioHelper.h>
#import <ZMVideoSDK/ZMVideoSDKDef.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZMVideoSDKSteamingJoinContext
 * @brief Interface for join broadcast streaming params.
 */
@interface ZMVideoSDKSteamingJoinContext : NSObject

/**
 * @brief JWT token.
 */
@property(nonatomic, copy, readwrite, nullable)NSString* token;

/**
 * @brief Broadcast channel ID.
 */
@property(nonatomic, copy, readwrite, nullable)NSString* channelID;

@end

/**
 * @protocol ZMVideoSDKBroadcastStreamingVideoDelegate
 * @brief Video callback for broadcast streaming.
 */
@protocol ZMVideoSDKBroadcastStreamingVideoDelegate <NSObject>

/**
 * @brief Called when subscribed video data is received.
 * @param rawData The video data object.
 */
- (void)onVideoFrameReceived:(ZMVideoSDKYUVRawDataI420* __nullable)rawData;

@end

/**
 * @protocol ZMVideoSDKBroadcastStreamingAudioDelegate
 * @brief Audio callback for broadcast streaming.
 */
@protocol ZMVideoSDKBroadcastStreamingAudioDelegate <NSObject>

/**
 * @brief Called when subscribed audio data is received.
 * @param audioRawData The audio data object.
 */
- (void)onAudioRawDataReceived:(ZMVideoSDKAudioRawData* __nullable)audioRawData;

@end

/**
 * @class ZMVideoSDKBroadcastStreamingViewer
 * @brief Broadcast streaming viewer interface.
 */
@interface ZMVideoSDKBroadcastStreamingViewer : NSObject

/**
 * @brief Joins broadcast streaming asynchronously. Result is notified via \link ZMVideoSDKDelegate onStreamingJoinStatusChanged \endlink.
 * @param joinContext The join context containing token and channel ID.
 * @return If the function succeeds, the return value is @c ZMVideoSDKErrors_Success. Otherwise failed.
 */
- (ZMVideoSDKErrors)joinStreaming:(ZMVideoSDKSteamingJoinContext*)joinContext;

/**
 * @brief Leaves broadcast streaming asynchronously. Result is notified through via \link ZMVideoSDKDelegate onStreamingJoinStatusChanged \endlink.
 * @return If the function succeeds, the return value is @c ZMVideoSDKErrors_Success. Otherwise failed.
 */
- (ZMVideoSDKErrors)leaveStreaming;

/**
 * @brief The join status.
 * @return join status.
 */
- (ZMVideoSDKStreamingJoinStatus)getStreamingJoinStatus;

/**
 * @brief Subscribes to streaming video.
 * @param resolution The desired video resolution. Supported: ZMVideoSDKResolution_180P, ZMVideoSDKResolution_360P, ZMVideoSDKResolution_720P, ZMVideoSDKResolution_1080P.
 * @param delegate the raw video data callback object, see \link ZMVideoSDKBroadcastStreamingVideoDelegate \endlink.
 * @return If the function succeeds, the return value is @c ZMVideoSDKErrors_Success. Otherwise failed.
 */
- (ZMVideoSDKErrors)subscribeVideo:(ZMVideoSDKResolution)resolution broadcastStreamingVideoCallback:(id <ZMVideoSDKBroadcastStreamingVideoDelegate>)delegate;

/**
 * @brief Unsubscribes from streaming video raw data.
 * @param delegate The video raw data callback object.
 * @return If the function succeeds, the return value is @c ZMVideoSDKErrors_Success. Otherwise failed.
 */
- (ZMVideoSDKErrors)unSubscribeVideo:(id <ZMVideoSDKBroadcastStreamingVideoDelegate>)delegate;

/**
 * @brief Subscribes to streaming audio.
 * @param delegate The raw audio data callback object.
 * @return If the function succeeds, the return value is @c ZMVideoSDKErrors_Success. Otherwise failed.
 */
- (ZMVideoSDKErrors)subscribeAudio:(id <ZMVideoSDKBroadcastStreamingAudioDelegate>)delegate;

/**
 * @brief Unsubscribes from streaming audio raw data.
 * @return If the function succeeds, the return value is @c ZMVideoSDKErrors_Success. Otherwise failed.
 */
- (ZMVideoSDKErrors)unSubscribeAudio;

@end

NS_ASSUME_NONNULL_END
