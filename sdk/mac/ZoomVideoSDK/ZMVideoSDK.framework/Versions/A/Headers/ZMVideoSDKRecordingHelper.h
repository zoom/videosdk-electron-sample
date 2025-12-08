/**
 * @file ZMVideoSDKRecordingHelper.h
 * @brief Defines the interface for controlling cloud recording in a Zoom Video SDK session.
 */


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZMVideoSDKRecordingHelper
 * @brief Helper class for using cloud recording in the session.
 * @note Cloud recording requires:
 * - A valid cloud recording add-on plan
 * - The cloud recording feature enabled on the Zoom Web portal
 */
@interface ZMVideoSDKRecordingHelper : NSObject

/**
 * @brief Checks if the current user meets the requirements to start cloud recording.
 *
 * The following are the prerequisites to use the helper class:
 * - A cloud recording add-on plan
 * - Cloud recording feature enabled on the Web portal
 *
 * @return @c ZMVideoSDKErrors_Success if the current user meets the requirements to start cloud recording. Otherwise, the current user does not meeting the requirements to start recording.
 */
- (ZMVideoSDKErrors)canStartRecording;

/**
 * @brief Start cloud recording.
 * @return @c ZMVideoSDKErrors_Success if the start cloud recording request was successful. Otherwise, the start cloud recording request failed.
 * @note Since cloud recording involves asynchronous operations, a return value of @c ZMVideoSDKErrors_Success does not guarantee that the recording will start. See \link ZMVideoSDKDelegate onCloudRecordingStatus:recordingConsentHandler: \endlink for information on how to confirm that recording has commenced.
 */
- (ZMVideoSDKErrors)startCloudRecording;

/**
 * @brief Stop cloud recording.
 * @return @c ZMVideoSDKErrors_Success if the stop cloud recording request was successful. Otherwise, the stop cloud recording request failed.
 * @note Since cloud recording involves asynchronous operations, a return value of @c ZMVideoSDKErrors_Success does not guarantee that the recording will stop. See \link ZMVideoSDKDelegate onCloudRecordingStatus:recordingConsentHandler: \endlink for information on how to confirm that recording has ended.
 */
- (ZMVideoSDKErrors)stopCloudRecording;

/**
 * @brief Pause the ongoing cloud recording.
 * @return @c ZMVideoSDKErrors_Success if the pause cloud recording request was successful. Otherwise, the pause cloud recording request failed.
 * @note Since cloud recording involves asynchronous operations, a return value of @c ZMVideoSDKErrors_Success  does not guarantee that the recording will pause. See \link ZMVideoSDKDelegate onCloudRecordingStatus:recordingConsentHandler: \endlink for information on how to confirm that recording has paused.
 */
- (ZMVideoSDKErrors)pauseCloudRecording;

/**
 * @brief Resume the previously paused cloud recording.
 * @return @c ZMVideoSDKErrors_Success if the resume cloud recording request was successful. Otherwise, the resume cloud recording request failed.
 * @note Since cloud recording involves asynchronous operations, a return value of @c ZMVideoSDKErrors_Success does not guarantee that the recording will resume. See \link ZMVideoSDKDelegate onCloudRecordingStatus:recordingConsentHandler: \endlink for information on how to confirm that recording has resumed.
 */
- (ZMVideoSDKErrors)resumeCloudRecording;

/**
 * @brief Get the current status of cloud recording.
 * @param recordStatus Cloud recording status value defined in ZMRecordingStatus.
 * @return ZMVideoSDKErrors_Success if the get cloud recording status request was successful. Otherwise, the get cloud recording status request failed.
 */
- (ZMVideoSDKErrors)getCloudRecordingStatus:(ZMRecordingStatus*)recordStatus;
@end

NS_ASSUME_NONNULL_END
