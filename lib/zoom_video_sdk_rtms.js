import { ZoomVideoSDKErrors } from './zoom_video_sdk_defines.js'

export default (function () {
  var instance;
  
  /**
   * Zoom Video SDKRTMS
   * @module zoom_video_sdk_rtms
   * @return {ZoomVideoSDKRTMS}
   */
  function init(opts) {
    const clientOpts = {...opts}
    // Private methods and variables
    if (!clientOpts.addon) {
      return null
    }
    let _addon = clientOpts.addon.GetRTMSHelper()

    return {
      // Public methods and variables      
      /**
       * Determine if the session supports the real-time media streams feature.
       * @method isSupportRealTimeMediaStreams
       * @return {Boolean} True indicates the real-time media streams feature is supported, otherwise it is not.
       */
      isSupportRealTimeMediaStreams: function () {
        if (_addon) {
          return _addon.IsSupportRealTimeMediaStreams()
        }
        return false
      },      
      /**
       * Checks if the current user meets the requirements to start real-time media streams.
       * @method canStartRealTimeMediaStreams
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise it failed.
       */
      canStartRealTimeMediaStreams: function () {
        if (_addon) {
          return _addon.CanStartRealTimeMediaStreams()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },      
      /**
       * Start real-time media streams.
       * @method startRealTimeMediaStreams
       * @note Call canStartRealTimeMediaStreams() first to verify permissions.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.
       */
      startRealTimeMediaStreams: function () {
        if (_addon) {
          return _addon.StartRealTimeMediaStreams()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },      
      /**
       * Pause real-time media streams.
       * @method pauseRealTimeMediaStreams
       * @note Can only be called after startRealTimeMediaStreams() has succeeded.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.
       */
      pauseRealTimeMediaStreams: function () {
        if (_addon) {
          return _addon.PauseRealTimeMediaStreams()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },      
      /**
       * Resume real-time media streams.
       * @method resumeRealTimeMediaStreams
       * @note Can only be called after pauseRealTimeMediaStreams() has been called.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.
       */
      resumeRealTimeMediaStreams: function () {
        if (_addon) {
          return _addon.ResumeRealTimeMediaStreams()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },      
      /**
       * Stop real-time media streams.
       * @method stopRealTimeMediaStreams
       * @note Can be called when stream is in any active state.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.
       */
      stopRealTimeMediaStreams: function () {
        if (_addon) {
          return _addon.StopRealTimeMediaStreams()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      }
    }
  }

  return {
    getInstance: function (opts) {
      if (!instance) {
        instance = init(opts)
      }
      return instance
    }
  }
})()
