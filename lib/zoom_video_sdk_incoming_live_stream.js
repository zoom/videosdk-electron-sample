import { ZoomVideoSDKErrors } from './zoom_video_sdk_defines.js'
import messages from './electron_zoomvideosdk_pb.js'

export default (function () {
  var instance
  /**
    * Return an instance to manage incoming live streaming during a video SDK session. Currently only supports one stream.
    * @module zoom_video_sdk_incoming_live_stream
    * @return {ZoomVideoSDKIncomingLiveStream}
    */
  function init (opts) {
    const clientOpts = {...opts}
    // Private methods and variables
    if (!clientOpts.addon) {
      return null
    }
    const _addon = clientOpts.addon.GetIncomingLiveStreamHelper()

    return {
      // Public methods and variables
      /**
       * Bind incoming live stream with a stream key ID.
       * @method bindIncomingLiveStream
       * @param {String} strStreamKeyID strStreamKeyID The stream key ID to bind.
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
          Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
       */
      bindIncomingLiveStream: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const strStreamKeyID = clientOpts.strStreamKeyID
            const IncomingLiveStreamParams = new messages.IncomingLiveStreamParams()
            IncomingLiveStreamParams.setStrstreamkeyid(strStreamKeyID)
            const bytes = IncomingLiveStreamParams.serializeBinary()
            return _addon.BindIncomingLiveStream(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Unbind the bound incoming live stream.
       * @method unbindIncomingLiveStream
       * @param {String} strStreamKeyID The stream key ID to unbind.
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
          Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
       */
      unbindIncomingLiveStream: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const strStreamKeyID = clientOpts.strStreamKeyID
            const IncomingLiveStreamParams = new messages.IncomingLiveStreamParams()
            IncomingLiveStreamParams.setStrstreamkeyid(strStreamKeyID)
            const bytes = IncomingLiveStreamParams.serializeBinary()
            return _addon.UnbindIncomingLiveStream(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
       /**
       * Get the status of bound streams.
       * @method getIncomingLiveStreamStatus
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
          Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
       */
      getIncomingLiveStreamStatus: function () {
        if (_addon) {
          return _addon.GetIncomingLiveStreamStatus()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Start the bound stream as a special participant.
       * @method startIncomingLiveStream
       * @param {String} strStreamKeyID The stream key ID to start.
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
          Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
       */
      startIncomingLiveStream: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const strStreamKeyID = clientOpts.strStreamKeyID
            const IncomingLiveStreamParams = new messages.IncomingLiveStreamParams()
            IncomingLiveStreamParams.setStrstreamkeyid(strStreamKeyID)
            const bytes = IncomingLiveStreamParams.serializeBinary()
            return _addon.StartIncomingLiveStream(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Stop the bound stream as a special participant.
       * @method stopIncomingLiveStream
       * @param {String} strStreamKeyID The stream key ID to stop.
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
          Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
       */
      stopIncomingLiveStream: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const strStreamKeyID = clientOpts.strStreamKeyID
            const IncomingLiveStreamParams = new messages.IncomingLiveStreamParams()
            IncomingLiveStreamParams.setStrstreamkeyid(strStreamKeyID)
            const bytes = IncomingLiveStreamParams.serializeBinary()
            return _addon.StopIncomingLiveStream(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
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