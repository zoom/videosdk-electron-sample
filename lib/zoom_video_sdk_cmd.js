import { ZoomVideoSDKErrors } from './zoom_video_sdk_defines.js'
import messages from './electron_zoomvideosdk_pb.js'

export default (function () {
  var instance
  /**
    * Return an instance to use command channel features during a video SDK session.
    * @module zoom_video_sdk_cmd
    * @return {ZoomVideoSDKCmd}
    */
  function init(opts) {
    const clientOpts = {...opts}
    // Private methods and variables
    if (!clientOpts.addon) {
      return null
    }
    const _addon = clientOpts.addon.GetCmdChannel()

    return {
      // Public methods and variables
      /**
      * Send custom commands to other users in the current session.
      * @method sendCommand
      * @param {Object} user, the user who will receive the command, if receiver is NULL, send to all.
      * @param {String} strCmd, the customized command.
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      sendCommand: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const user = clientOpts.user
            const strCmd = clientOpts.strCmd
            const SendCommandParams = new messages.SendCommandParams()
            SendCommandParams.setUser(user)
            SendCommandParams.setStrcmd(strCmd)
            const bytes = SendCommandParams.serializeBinary()
            return _addon.SendCommand(bytes)
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
