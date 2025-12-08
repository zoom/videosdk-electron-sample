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
       * Send custom commands or data to other users in the current session. Limit: up to 60 custom commands per second.
       * @method sendCommand
       * @param {Object} user The user who receives the command, if receiver is set to nullptr, the command is broadcast to all users.
       * @param {String} strCmd The custom commands or data.
       * @return {Number} If the command sends successfully, the return value is ZoomVideoSDKErrors_Success. Otherwise the send command request fails.
       * @note Allows users to send commands or data (such as plain text or a binary encoded into string) to other users in the same session.
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
