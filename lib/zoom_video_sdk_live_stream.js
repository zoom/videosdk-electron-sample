import { ZoomVideoSDKErrors } from './zoom_video_sdk_defines.js'
import messages from './electron_zoomvideosdk_pb.js'

export default (function () {
  var instance
  /**
    * Return an instance to manage live streaming during a video SDK session.
    * @module zoom_video_sdk_live_stream
    * @return {ZoomVideoSDKLiveStream}
    */
  function init (opts) {
    const clientOpts = {...opts}
    // Private methods and variables
    if (!clientOpts.addon) {
      return null
    }
    const _addon = clientOpts.addon.GetLiveStreamHelper()

    return {
      // Public methods and variables
      /**
       * start live steam
       * @method startLiveStream
       * @param {String} streamUrl the live stream url
       * @param {String} msgContent the live stream key
       * @param {String} broadcastUrl the live stream broadcast url
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
          Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
       */
      startLiveStream: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const streamUrl = clientOpts.streamUrl
            const key = clientOpts.key
            const broadcastUrl = clientOpts.broadcastUrl
            const StartLiveStreamParams = new messages.StartLiveStreamParams()
            StartLiveStreamParams.setZnStreamurl(streamUrl)
            StartLiveStreamParams.setZnKey(key)
            StartLiveStreamParams.setZnBroadcasturl(broadcastUrl)
            const bytes = StartLiveStreamParams.serializeBinary()
            return _addon.StartLiveStream(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * stop live steam
       * @method stopLiveStream
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
          Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
       */
      stopLiveStream: function () {
        if (_addon) {
          return _addon.StopLiveStream()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Can start live steam
       * @method canStartLiveStream
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
          Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
       */
      canStartLiveStream: function () {
        if (_addon) {
          return _addon.CanStartLiveStream()
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
