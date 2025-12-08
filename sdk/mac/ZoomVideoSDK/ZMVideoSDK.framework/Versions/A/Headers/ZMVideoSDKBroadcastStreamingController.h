/**
 * @file ZMVideoSDKBroadcastStreamingController.h
 * @brief This file defines the interfaces for managing start and stop broadcast streaming.
 */


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZMVideoSDKBroadcastStreamingController
 * @brief Interface for Broadcast streaming.
 */
@interface ZMVideoSDKBroadcastStreamingController : NSObject

/**
 * @brief Checks if the session supports broadcast streaming.
 * @return YES if supported; NO if not.
 */
- (BOOL)isBroadcastStreamingSupported;

/**
 * @brief Checks if the user has permission to start a broadcast.
 * @return YES if supported; NO if not.
 */
- (BOOL)canStartBroadcast;

/**
 * @brief Start broadcast streaming asynchronously. The result is notified via the callback \link ZMVideoSDKDelegate onStartBroadcastResponse \endlink.
 * @return If the function succeeds, the return value is @c ZMVideoSDKErrors_Success. Otherwise failed.
 */
- (ZMVideoSDKErrors)startBroadcast;

/**
 * @brief Stops broadcast streaming asynchronously. The result is notified via the callback \link ZMVideoSDKDelegate onStopBroadcastResponse \endlink.
 * @param channelID The broadcast streaming channel ID.
 * @return If the function succeeds, the return value is @c ZMVideoSDKErrors_Success. Otherwise failed.
 */
- (ZMVideoSDKErrors)stopBroadcast:(NSString*)channelID;

/**
 * @brief Gets the broadcast status asynchronously. The result is notified via the callback \link ZMVideoSDKDelegate onGetBroadcastControlStatus \endlink.
 * @param channelID The broadcast streaming channel ID.
 * @return If the function succeeds, the return value is @c ZMVideoSDKErrors_Success. Otherwise failed.
 */
- (ZMVideoSDKErrors)getBroadcastStatus:(NSString*)channelID;
@end

NS_ASSUME_NONNULL_END
