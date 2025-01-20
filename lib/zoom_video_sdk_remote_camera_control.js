import { ZoomVideoSDKErrors } from './zoom_video_sdk_defines.js'
import messages from './electron_zoomvideosdk_pb.js'
import { setUserInfo } from './zoom_video_sdk_user_util.js'

function checkCameraCtrlRange(range) {
  if (range < 10) {
    return 10
  } else if (range > 100) {
    return 100
  } else {
    return range
  }
}

export default (function () {
  var instance
  /**
    * Get the helper class instance to access the remote camera control.
    * @module zoom_video_sdk_remote_camera_control
    * @return {ZoomVideoSDKRemoteCameraControl}
    */
  function init(opts) {
    const clientOpts = {...opts}
    // Private methods and variables
    if (!clientOpts.addon) {
      return null
    }
    const _addon = clientOpts.addon.GetRemoteCameraCtrlHelper()

    return {
      // Public methods and variables
      /**
      * Request to control remote camera.
      * @method requestControlRemoteCamera
      * @param {Object} user
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      requestControlRemoteCamera: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const user = setUserInfo(clientOpts.user)
            const RequestControlRemoteCameraParams = new messages.RequestControlRemoteCameraParams()
            RequestControlRemoteCameraParams.setUser(user)
            const bytes = RequestControlRemoteCameraParams.serializeBinary()
            return _addon.RequestControlRemoteCamera(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Give up control of the remote camera.
       * @method giveUpControlRemoteCamera
       * @param {Object} user
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
          Otherwise failed. To get extended error information, see {@link ZoomVideoSDKErrors} enum.
       */
      giveUpControlRemoteCamera: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const user = setUserInfo(clientOpts.user)
            const GiveUpControlRemoteCameraParams = new messages.GiveUpControlRemoteCameraParams()
            GiveUpControlRemoteCameraParams.setUser(user)
            const bytes = GiveUpControlRemoteCameraParams.serializeBinary()
            return _addon.GiveUpControlRemoteCamera(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Turn the camera to the left.
      * @method turnLeft
      * @param {Number} range, 10 <= rotation range <= 100.
      * @param {Object} user
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      turnLeft: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            let range = checkCameraCtrlRange(clientOpts.range)
            const user = setUserInfo(clientOpts.user)
            const RemoteCameraCtrlTurnLeftParams = new messages.RemoteCameraCtrlTurnLeftParams()
            RemoteCameraCtrlTurnLeftParams.setRange(range)
            RemoteCameraCtrlTurnLeftParams.setUser(user)
            const bytes = RemoteCameraCtrlTurnLeftParams.serializeBinary()
            return _addon.TurnLeft(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Turn the camera to the right.
      * @method turnRight
      * @param {Number} range, 10 <= rotation range <= 100.
      * @param {Object} user
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      turnRight: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const range = checkCameraCtrlRange(clientOpts.range)
            const user = setUserInfo(clientOpts.user)
            const RemoteCameraCtrlTurnRightParams = new messages.RemoteCameraCtrlTurnRightParams()
            RemoteCameraCtrlTurnRightParams.setRange(range)
            RemoteCameraCtrlTurnRightParams.setUser(user)
            const bytes = RemoteCameraCtrlTurnRightParams.serializeBinary()
            return _addon.TurnRight(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Turn the camera up.
      * @method turnUp
      * @param {Number} range, 10 <= rotation range <= 100.
      * @param {Object} user
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      turnUp: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const range = checkCameraCtrlRange(clientOpts.range)
            const user = setUserInfo(clientOpts.user)
            const RemoteCameraCtrlTurnUpParams = new messages.RemoteCameraCtrlTurnUpParams()
            RemoteCameraCtrlTurnUpParams.setRange(range)
            RemoteCameraCtrlTurnUpParams.setUser(user)
            const bytes = RemoteCameraCtrlTurnUpParams.serializeBinary()
            return _addon.TurnUp(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Turn the camera down.
      * @method turnDown
      * @param {Number} range, 10 <= rotation range <= 100.
      * @param {Object} user
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      turnDown: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const range = checkCameraCtrlRange(clientOpts.range)
            const user = setUserInfo(clientOpts.user)
            const RemoteCameraCtrlTurnDownParams = new messages.RemoteCameraCtrlTurnDownParams()
            RemoteCameraCtrlTurnDownParams.setRange(range)
            RemoteCameraCtrlTurnDownParams.setUser(user)
            const bytes = RemoteCameraCtrlTurnDownParams.serializeBinary()
            return _addon.TurnDown(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Zoom the camera in.
      * @method zoomIn
      * @param {Number} range, 10 <= zoom range <= 100.
      * @param {Object} user
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      zoomIn: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const range = checkCameraCtrlRange(clientOpts.range)
            const user = setUserInfo(clientOpts.user)
            const RemoteCameraCtrlZoomInParams = new messages.RemoteCameraCtrlZoomInParams()
            RemoteCameraCtrlZoomInParams.setRange(range)
            RemoteCameraCtrlZoomInParams.setUser(user)
            const bytes = RemoteCameraCtrlZoomInParams.serializeBinary()
            return _addon.ZoomIn(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Zoom the camera out.
      * @method zoomOut
      * @param {Number} range, 10 <= zoom range <= 100.
      * @param {Object} user
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      zoomOut: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const range = checkCameraCtrlRange(clientOpts.range)
            const user = setUserInfo(clientOpts.user)
            const RemoteCameraCtrlZoomOutParams = new messages.RemoteCameraCtrlZoomOutParams()
            RemoteCameraCtrlZoomOutParams.setRange(range)
            RemoteCameraCtrlZoomOutParams.setUser(user)
            const bytes = RemoteCameraCtrlZoomOutParams.serializeBinary()
            return _addon.ZoomOut(bytes)
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
