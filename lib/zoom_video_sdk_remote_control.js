import { ZoomVideoSDKErrors } from './zoom_video_sdk_defines.js'
import messages from './electron_zoomvideosdk_pb.js'
import { setUserInfo } from './zoom_video_sdk_user_util.js'

export default (function () {
  var instance
  /**
    * Get the helper class instance to access remote control. Only available for controller side.
    * @module zoom_video_sdk_remote_control
    * @return {ZoomVideoSDKRemoteControl}
    */
  function init(opts) {
    const clientOpts = {...opts}
    // Private methods and variables
    if (!clientOpts.addon) {
      return null
    }
    const _addon = clientOpts.addon.GetRemoteCtrlHelper()
    const _handler = clientOpts.addon.GetRemoteControlRequestHandler()

    return {
      // Public methods and variables
      /**
      * Determine if the user is able to ask to remote control the specified user.
      * @method canRequestControl
      * @param {Object} user
      * @return {Boolean} If the user is able to request to remote control the specified user, the return value is true. Otherwise false.
      */
      canRequestControl: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const user = setUserInfo(clientOpts.user)
            const RemoteControlParams = new messages.RemoteControlParams()
            RemoteControlParams.setUser(user)
            const bytes = RemoteControlParams.serializeBinary()
            return _addon.CanRequestControl(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Send the remote control request to the specified user.
       * @method requestRemoteControl
       * @param {Object} user
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
          Otherwise failed. To get extended error information, see {@link ZoomVideoSDKErrors} enum.
       */
      requestRemoteControl: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const user = setUserInfo(clientOpts.user)
            const RemoteControlParams = new messages.RemoteControlParams()
            RemoteControlParams.setUser(user)
            const bytes = RemoteControlParams.serializeBinary()
            return _addon.RequestRemoteControl(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * End the remote control of the specified user.
      * @method endRemoteControl
      * @param {Object} user
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      endRemoteControl: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const user = setUserInfo(clientOpts.user)
            const RemoteControlParams = new messages.RemoteControlParams()
            RemoteControlParams.setUser(user)
            const bytes = RemoteControlParams.serializeBinary()
            return _addon.EndRemoteControl(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Determine if the user is able to remote control the specified user.
      * @method canRemoteControl
      * @param {Object} user
      * @return {Boolean} If the user is able to remote control the specified user, the return value is true. Otherwise false.
      */
      canRemoteControl: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const user = setUserInfo(clientOpts.user)
            const RemoteControlParams = new messages.RemoteControlParams()
            RemoteControlParams.setUser(user)
            const bytes = RemoteControlParams.serializeBinary()
            return _addon.CanRemoteControl(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Remote control the specified user.
      * @method enterRemoteControl
      * @param {Object} user
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      enterRemoteControl: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const user = setUserInfo(clientOpts.user)
            const RemoteControlParams = new messages.RemoteControlParams()
            RemoteControlParams.setUser(user)
            const bytes = RemoteControlParams.serializeBinary()
            return _addon.EnterRemoteControl(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Determine if the specified user is in the process of being remotely controlled.
      * @method isRemoteControlling
      * @param {Object} user
      * @return {Boolean} If the specified user is being remotely controled, the return value is true. Otherwise false.
      */
      isRemoteControlling: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const user = setUserInfo(clientOpts.user)
            const RemoteControlParams = new messages.RemoteControlParams()
            RemoteControlParams.setUser(user)
            const bytes = RemoteControlParams.serializeBinary()
            return _addon.IsRemoteControlling(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * The user has temporarily paused remote control, to continue, there is no need to request remote control again.
      * @method leaveRemoteControl
      * @param {Object} user
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      leaveRemoteControl: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const user = setUserInfo(clientOpts.user)
            const RemoteControlParams = new messages.RemoteControlParams()
            RemoteControlParams.setUser(user)
            const bytes = RemoteControlParams.serializeBinary()
            return _addon.LeaveRemoteControl(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Approve the remote control request.
      * @method approve
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      approve: function () {
        if (_handler) {
          return _handler.Approve()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Decline the remote control request.
      * @method deny
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      deny: function () {
        if (_handler) {
          return _handler.Deny()
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
