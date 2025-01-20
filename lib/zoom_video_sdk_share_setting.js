import { ZoomVideoSDKErrors, ZoomVideoSDKScreenCaptureMode } from './zoom_video_sdk_defines.js'
import messages from './electron_zoomvideosdk_pb.js'
const { platform } = process

export default (function () {
  var instance
  /**
    * Zoom Video SDK Share Setting
    * @module zoom_video_sdk_share_setting
    * @return {ZoomVideoSDKShareSetting}
    */
  function init (opts) {
    const clientOpts = {...opts}
    // Private methods and variables
    if (!clientOpts.addon) {
      return null
    }
    const _addon = clientOpts.addon.GetShareSetting()

    return {
      // Public methods and variables
      /**
      * Set screen capture mode.
      * @method setScreenCaptureMode
      * @param {Number} captureMode captureMode The mode to be set, {@link ZoomVideoSDKScreenCaptureMode} enum.
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
	      Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      setScreenCaptureMode: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const captureMode = clientOpts.captureMode || ZoomVideoSDKScreenCaptureMode.ZoomVideoSDKScreenCaptureMode_Auto
            const SetScreenCaptureModeParams = new messages.SetScreenCaptureModeParams()
            SetScreenCaptureModeParams.setCapturemode(captureMode)
            const bytes = SetScreenCaptureModeParams.serializeBinary()
            return _addon.SetScreenCaptureMode(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Get the screen capture mode.
      * @method getScreenCaptureMode
      * @return {Object} contains err and captureMode. captureMode value is the screen capture mode. {@link ZoomVideoSDKScreenCaptureMode} enum.
      */
      getScreenCaptureMode: function () {
        if (_addon) {
          try {
            return _addon.GetScreenCaptureMode()
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Set the visibility of the green border when sharing the screen.
      * @method enableGreenBorder
      * @param {Boolean} bEnable True indicates to display the green border. False hide.
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
	      Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      enableGreenBorder: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const bEnable = clientOpts.bEnable
            const EnableGreenBorderParams = new messages.EnableGreenBorderParams()
            EnableGreenBorderParams.setBenable(bEnable)
            const bytes = EnableGreenBorderParams.serializeBinary()
            return _addon.EnableGreenBorder(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Determine if the green border is enabled when user shares the screen.
      * @method isGreenBorderEnabled
      * @return {Boolean} True indicates enabled. False not.
      */
      isGreenBorderEnabled: function () {
        if (_addon) {
          try {
            return _addon.IsGreenBorderEnabled()
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Enable/disable remote control of all applications that require admin privileges such as Task Manager. only support windows platform
      * @method enableAdminRemoteControl
      * @param {Boolean} bEnable bEnable TRUE indicates to enable the remote control. FALSE not.
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
	      Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      enableAdminRemoteControl: function (opts) {
        if (_addon) {
          if (platform != 'win32') {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_No_Impl
          }
          const clientOpts = {...opts}
          try {
            const bEnable = clientOpts.bEnable
            const EnableAdminRemoteControlParams = new messages.EnableAdminRemoteControlParams()
            EnableAdminRemoteControlParams.setBenable(bEnable)
            const bytes = EnableAdminRemoteControlParams.serializeBinary()
            return _addon.EnableAdminRemoteControl(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Determine if remote control of all applications is enabled, including those that require admin privileges. only support windows platform
      * @method isRemoteControlAllApplicationsEnabled
      * @return {Boolean} TRUE indicates enabled. FALSE not.
      */
      isRemoteControlAllApplicationsEnabled: function () {
        if (_addon) {
          try {
            if (platform != 'win32') {
              return false
            }
            return _addon.IsRemoteControlAllApplicationsEnabled()
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
