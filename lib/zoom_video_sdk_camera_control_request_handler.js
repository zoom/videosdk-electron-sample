import { ZoomVideoSDKErrors } from './zoom_video_sdk_defines.js'

export default (function () {
  var instance
  /**
    * Zoom Video SDK Camera Control Request Handler
    * @module zoom_video_sdk_camera_control_request_handler
    * @return {ZoomVideoSDKCameraControlRequestHandler}
    */
  function init(opts) {
    const clientOpts = {...opts}
    // Private methods and variables
    if (!clientOpts.addon) {
      return null
    }
    const _addon = clientOpts.addon.GetCameraControlRequestHandler()

    return {
      // Public methods and variables
      /**
      * Approve the remote camera control request.
      * @method approve
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      approve: function () {
        if (_addon) {
          return _addon.Approve()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Decline the remote camera control request.
      * @method decline
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      decline: function () {
        if (_addon) {
          return _addon.Decline()
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
