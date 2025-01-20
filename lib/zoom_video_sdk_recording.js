import { ZoomVideoSDKErrors } from './zoom_video_sdk_defines.js'
import messages from './electron_zoomvideosdk_pb.js'

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
       * Checks whether the current user has permission to start cloud recording.
       * @method canStartRecording
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
          Otherwise failed. To get extended error information, see {@link ZoomVideoSDKErrors} enum.
       */
      canStartRecording: function () {
        if (_addon) {
          return _addon.CanStartRecording()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Start cloud recording.
       * @method startCloudRecording
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
          Otherwise failed. To get extended error information, see {@link ZoomVideoSDKErrors} enum.
       */
      startCloudRecording: function () {
        if (_addon) {
          return _addon.StartCloudRecording()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Stop cloud recording.
       * @method stopCloudRecording
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
          Otherwise failed. To get extended error information, see {@link ZoomVideoSDKErrors} enum.
       */
      stopCloudRecording: function () {
        if (_addon) {
          return _addon.StopCloudRecording()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Pause cloud recording.
       * @method pauseCloudRecording
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
          Otherwise failed. To get extended error information, see {@link ZoomVideoSDKErrors} enum.
       */
      pauseCloudRecording: function () {
        if (_addon) {
          return _addon.PauseCloudRecording()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Resume cloud recording.
       * @method resumeCloudRecording
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
          Otherwise failed. To get extended error information, see {@link ZoomVideoSDKErrors} enum.
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
      * @return {Number|Object} If the function succeed, the return value is recordingStatus.
          Otherwise return value is err Object. To get extended error information, see {@link ZoomVideoSDKErrors} enum.
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
