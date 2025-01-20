//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 @brief Helper class for using cloud recording in the session.
 */
@interface ZMVideoSDKRecordingHelper : NSObject

/**
 @brief Checks if the current user meets the requirements to start cloud recording.
 * The following are the prerequisites to use the helper class:
 * <ul>
 *     <li>A cloud recording add-on plan</li>
 *     <li>Cloud recording feature enabled on the Web portal</li>
 * </ul>
 @return ZMVideoSDKErrors_Success if the current user meets the requirements to start cloud recording. Otherwise, the current user does not meeting the requirements to start recording. See error codes defined in {@link ZMVideoSDKErrors}.
 */
-(ZMVideoSDKErrors)canStartRecording;

/**
 @brief Start cloud recording.
 @note Since cloud recording involves asynchronous operations, a return value of ZMVideoSDKErrors_Success does not guarantee that the recording will start. See {@link ZMVideoSDKDelegate onCloudRecordingStatus:recordingConsentHandler:} for information on how to confirm that recording has commenced.
 @return ZMVideoSDKErrors_Success if the start cloud recording request was successful. Otherwise, the start cloud recording request failed. See error codes defined in {@link ZMVideoSDKErrors}.
 */
-(ZMVideoSDKErrors)startCloudRecording;

/**
 @brief Stop cloud recording.
 @note Since cloud recording involves asynchronous operations, a return value of ZMVideoSDKErrors_Success does not guarantee that the recording will stop. See {@link ZMVideoSDKDelegate onCloudRecordingStatus:recordingConsentHandler:} for information on how to confirm that recording has ended.
 @return ZMVideoSDKErrors_Success if the stop cloud recording request was successful. Otherwise, the stop cloud recording request failed. See error codes defined in {@link ZMVideoSDKErrors}.
 */
-(ZMVideoSDKErrors)stopCloudRecording;

/**
 @brief Pause the ongoing cloud recording.
 @note Since cloud recording involves asynchronous operations, a return value of ZMVideoSDKErrors_Success  does not guarantee that the recording will pause. See {@link ZMVideoSDKDelegate onCloudRecordingStatus:recordingConsentHandler:} for information on how to confirm that recording has paused.
 @return ZMVideoSDKErrors_Success if the pause cloud recording request was successful. Otherwise, the pause cloud recording request failed.
 */
-(ZMVideoSDKErrors)pauseCloudRecording;

/**
 @brief Resume the previously paused cloud recording.
 @note Since cloud recording involves asynchronous operations, a return value of ZMVideoSDKErrors_Success does not guarantee that the recording will resume. See {@link ZMVideoSDKDelegate onCloudRecordingStatus:recordingConsentHandler:} for information on how to confirm that recording has resumed.
 @return ZMVideoSDKErrors_Success if the resume cloud recording request was successful. Otherwise, the resume cloud recording request failed.
 */
-(ZMVideoSDKErrors)resumeCloudRecording;

/**
 @brief Get the current status of cloud recording.
 @param recordStatus Cloud recording status value defined in ZMRecordingStatus.
 @return ZMVideoSDKErrors_Success if the get cloud recording status request was successful. Otherwise, the get cloud recording status request failed.
 */
-(ZMVideoSDKErrors)getCloudRecordingStatus:(ZMRecordingStatus*)recordStatus;
@end

NS_ASSUME_NONNULL_END
