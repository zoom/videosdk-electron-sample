/**
 * @file ZMVideoSDKRTMSHelper.h
 * @brief This file defines the interfaces for managing real-time media streams
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZMVideoSDKRTMSHelper
 * @brief Helper class for managing real-time media streams.
 */
@interface ZMVideoSDKRTMSHelper : NSObject

/**
 * @brief Determine if the session supports the real-time media streams feature.
 * @return YES indicates the real-time media streams feature is supported, otherwise NO.
 */
- (BOOL)isSupportRealTimeMediaStreams;

/**
 * @brief Checks if the current user meets the requirements to start real-time media streams.
 * @note Only the host is permitted to start real-time media streams.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success. Otherwise failed.
 */
- (ZMVideoSDKErrors)canStartRealTimeMediaStreams;

/**
 * @brief Start real-time media streams.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success. Otherwise failed.
 */
- (ZMVideoSDKErrors)startRealTimeMediaStreams;

/**
 * @brief Pause real-time media streams.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success. Otherwise failed.
 */
- (ZMVideoSDKErrors)pauseRealTimeMediaStreams;

/**
 * @brief Resume real-time media streams.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success. Otherwise failed.
 */
- (ZMVideoSDKErrors)resumeRealTimeMediaStreams;

/**
 * @brief Stop real-time media streams.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success. Otherwise failed.
 */
- (ZMVideoSDKErrors)stopRealTimeMediaStreams;

@end

NS_ASSUME_NONNULL_END
