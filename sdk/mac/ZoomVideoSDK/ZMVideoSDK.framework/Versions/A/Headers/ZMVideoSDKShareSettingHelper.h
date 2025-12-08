/**
 * @file ZMVideoSDKShareSettingHelper.h
 * @brief Interface for managing share settings in Zoom Video SDK.
 */


#import <Foundation/Foundation.h>
#import <ZMVideoSDK/ZMVideoSDKDef.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZMVideoSDKShareSettingHelper
 * @brief Helper class to manage share-related settings.
 */
@interface ZMVideoSDKShareSettingHelper : NSObject

/**
 * @brief Set screen capture mode.
 * @param captureMode The mode to be set.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success, otherwise not.
 */
- (ZMVideoSDKErrors)setScreenCaptureMode:(ZMVideoSDKScreenCaptureMode)captureMode;

/**
 * @brief Get the screen capture mode.
 * @param captureMode The screen capture mode.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success, otherwise not.
 */
- (ZMVideoSDKErrors)getScreenCaptureMode:(ZMVideoSDKScreenCaptureMode*)captureMode;

/**
 * @brief Set the visibility of the green border when sharing the screen.
 * @param bEnable YES to display the green border. NO to hide.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success, otherwise not.
 */
- (ZMVideoSDKErrors)enableGreenBorder:(BOOL)bEnable;

/**
 * @brief Determine if the green border is enabled when user shares the screen.
 * @return YES if the green border is enabled. Otherwise NO.
 */
- (BOOL)isGreenBorderEnabled;
@end

NS_ASSUME_NONNULL_END
