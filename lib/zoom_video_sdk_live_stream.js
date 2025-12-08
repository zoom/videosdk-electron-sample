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
       * Start live stream.
       * @method startLiveStream
       * @param {String} streamUrl The live stream url.
       * @param {String} key The live stream key.
       * @param {String} broadcastUrl The live stream broadcast url.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.
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
       * Stop live stream.
       * @method stopLiveStream
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.
       */
      stopLiveStream: function () {
        if (_addon) {
          return _addon.StopLiveStream()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Determine if can start the live stream.
       * @method canStartLiveStream
       * @return {Boolean} true if the user can start the live stream, false otherwise.
       */
      canStartLiveStream: function () {
        if (_addon) {
          return _addon.CanStartLiveStream()
        }
        return false
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
