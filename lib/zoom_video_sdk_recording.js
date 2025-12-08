import { ZoomVideoSDKErrors } from './zoom_video_sdk_defines.js'

export default (function () {
  var instance
  /**
    * Return an instance to manage cloud recordings during a video SDK session.
    * @module zoom_video_sdk_recording
    * @return {ZoomVideoSDKLocalRecording}
    */
  function init(opts) {
    const clientOpts = {...opts}
    // Private methods and variables
    if (!clientOpts.addon) {
      return null
    }
    const _addon = clientOpts.addon.GetRecordingHelper()

    return {
      // Public methods and variables
      /**
       * Checks if the current user meets the requirements to start cloud recording.
       * The following are the prerequisites to use the helper class:
       *  A cloud recording add-on plan
       *  Cloud recording feature enabled on the Web portal
       * @method canStartRecording
       * @return {Number} ZoomVideoSDKErrors_Success if the current user meets the requirements to start cloud recording. Otherwise, the current user does not meeting the requirements to start recording.
       */
      canStartRecording: function () {
        if (_addon) {
          return _addon.CanStartRecording()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Start cloud recording.
       * Since cloud recording involves asynchronous operations, 
       * a return value of ZoomVideoSDKErrors_Success does not guarantee that the recording will start.
       * See onCloudRecordingStatus for information on how to confirm that recording has commenced.
       * @method startCloudRecording
       * @return {Number} ZoomVideoSDKErrors_Success if the start cloud recording request was successful. Otherwise, the start cloud recording request failed.
       */
      startCloudRecording: function () {
        if (_addon) {
          return _addon.StartCloudRecording()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Stop cloud recording.
       * Since cloud recording involves asynchronous operations, 
       * a return value of ZoomVideoSDKErrors_Success does not guarantee that the recording will stop.
       * See onCloudRecordingStatus for information on how to confirm that recording has stopped.
       * @method stopCloudRecording
       * @return {Number} ZoomVideoSDKErrors_Success if the stop cloud recording request was successful. Otherwise, the stop cloud recording request failed.
       */
      stopCloudRecording: function () {
        if (_addon) {
          return _addon.StopCloudRecording()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Pause the ongoing cloud recording.
       * Since cloud recording involves asynchronous operations, 
       * a return value of ZoomVideoSDKErrors_Success does not guarantee that the recording will pause.
       * See onCloudRecordingStatus for information on how to confirm that recording has paused.
       * @method pauseCloudRecording
       * @return {Number} ZoomVideoSDKErrors_Success if the pause cloud recording request was successful. Otherwise, the pause cloud recording request failed.
       */
      pauseCloudRecording: function () {
        if (_addon) {
          return _addon.PauseCloudRecording()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Resume the previously paused cloud recording.
       * Since cloud recording involves asynchronous operations, 
       * a return value of ZoomVideoSDKErrors_Success does not guarantee that the recording will resume.
       * See onCloudRecordingStatus for information on how to confirm that recording has resumed.
       * @method resumeCloudRecording
       * @return {Number} ZoomVideoSDKErrors_Success if the resume cloud recording request was successful. Otherwise, the resume cloud recording request failed.
       */
      resumeCloudRecording: function () {
        if (_addon) {
          return _addon.ResumeCloudRecording()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get the current status of cloud recording.
       * @method getCloudRecordingStatus
       * @return {Object} Returns an object with the following properties:
       *   - {Number} err - If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.
       *   - {Number} recordingStatus - The current recording status {@link RecordingStatus} enum.
       */
      getCloudRecordingStatus: function () {
        if (_addon) {
          let {err, recordingStatus} = _addon.GetCloudRecordingStatus()
          if (err == ZoomVideoSDKErrors.ZoomVideoSDKErrors_Success) {
            return recordingStatus
          } else {
            return {err}
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      }
    }
  };

  return {
    getInstance: function (opts) {
      if (!instance) {
        instance = init(opts)
      }
      return instance
    }
  }
})()
