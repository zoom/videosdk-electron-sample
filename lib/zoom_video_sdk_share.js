import { ZoomVideoSDKErrors, ZoomVideoSDKSharePreprocessType } from './zoom_video_sdk_defines.js'
import messages from './electron_zoomvideosdk_pb.js'

export default (function () {
  var instance
  /**
    * Return an instance to manage screen sharing during a video SDK session.
    * @module zoom_video_sdk_share
    * @return {ZoomVideoSDKShare}
    */
  function init (opts) {
    const clientOpts = {...opts}
    // Private methods and variables
    if (!clientOpts.addon) {
      return null
    }
    const _addon = clientOpts.addon.GetShareHelper() || null

    return {
      // Public methods and variables
      /**
       * Share a selected window, if virtual speaker is enabled, don't support share audio.
       * @method startShareView
       * @param {String} handle The window handle that will to be share.
       * @param {Boolean} isWithDeviceAudio True is share computer sound when share screen/window, otherwise not.
       * @param {Boolean} isOptimizeForSharedVideo True is optimize the frame rate when share screen/window, otherwise not.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       */
      startShareView: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const handle = clientOpts.handle
            const isWithDeviceAudio = clientOpts.isWithDeviceAudio || false
            const isOptimizeForSharedVideo = clientOpts.isOptimizeForSharedVideo || false
            const StartShareViewParams = new messages.StartShareViewParams()
            StartShareViewParams.setZnHandle(handle)
            StartShareViewParams.setIswithdeviceaudio(isWithDeviceAudio)
            StartShareViewParams.setIsoptimizeforsharedvideo(isOptimizeForSharedVideo)
            const bytes = StartShareViewParams.serializeBinary()
            return _addon.StartShareView(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Share a selected screen, if virtual speaker is enabled, don't support share audio.
       * @method startShareScreen
       * @param {String} monitorID The screen name that will to be share.
       * @param {Boolean} isWithDeviceAudio True is share computer sound when share screen/window, otherwise not.
       * @param {Boolean} isOptimizeForSharedVideo True is optimize the frame rate when share screen/window, otherwise not.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       */
      startShareScreen: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const monitorID = clientOpts.monitorID
            const isWithDeviceAudio = clientOpts.isWithDeviceAudio || false
            const isOptimizeForSharedVideo = clientOpts.isOptimizeForSharedVideo || false
            const StartShareScreenParams = new messages.StartShareScreenParams()
            StartShareScreenParams.setZnMonitorid(monitorID)
            StartShareScreenParams.setIswithdeviceaudio(isWithDeviceAudio)
            StartShareScreenParams.setIsoptimizeforsharedvideo(isOptimizeForSharedVideo)
            const bytes = StartShareScreenParams.serializeBinary()
            return _addon.StartShareScreen(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Start sharing only the computer audio.
       * @method startShareComputerAudio
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       */
      startShareComputerAudio: function () {
        if (_addon) {
          return _addon.StartShareComputerAudio()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Stop share.
       * @method stopShare
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       */
      stopShare: function () {
        if (_addon) {
          return _addon.StopShare()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Determine whether the current user is sharing.
       * @method isSharingOut
       * @return {Boolean} True if myself is sharing. Otherwise returns false.
       */
      isSharingOut: function () {
        if (_addon) {
          return _addon.IsSharingOut()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Determine whether the current user is sharing the screen.
       * @method isScreenSharingOut
       * @return {Boolean} True if myself is sharing screen. Otherwise returns false.
       */
      isScreenSharingOut: function () {
        if (_addon) {
          return _addon.IsScreenSharingOut()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Determine if other user is sharing.
       * @method isOtherSharing
       * @return {Boolean} True if other user is sharing screen. Otherwise returns false.
       */
      isOtherSharing: function () {
        if (_addon) {
          return _addon.IsOtherSharing()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Lock sharing the view or screen. Only the host can call this method.
       * @method lockShare
       * @param {Boolean} bLock True to lock sharing.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       */
      lockShare: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const bLock = clientOpts.bLock
            const LockShareParams = new messages.LockShareParams()
            LockShareParams.setZnBlock(bLock)
            const bytes = LockShareParams.serializeBinary()
            return _addon.LockShare(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Determine whether sharing is locked.
       * @method isShareLocked
       * @return {Boolean} True if share is locked. Otherwise returns false.
       */
      isShareLocked: function () {
        if (_addon) {
          return _addon.IsShareLocked()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Pause share
       * @method pauseShare
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       */
      pauseShare: function () {
        if (_addon) {
          return _addon.PauseShare()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Resume share
       * @method resumeShare
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       */
      resumeShare: function () {
        if (_addon) {
          return _addon.ResumeShare()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Enable or disable the computer sound when sharing. The SDK does not support sharing device audio, for example, when you've enabled virtual speaker.
       * @method enableShareDeviceAudio
       * @param {Boolean} bEnable True indicates to enable. False disable.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       */
      enableShareDeviceAudio: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const bEnable = clientOpts.bEnable
            const EnableShareDeviceAudioParams = new messages.EnableShareDeviceAudioParams()
            EnableShareDeviceAudioParams.setEnable(bEnable)
            const bytes = EnableShareDeviceAudioParams.serializeBinary()
            return _addon.EnableShareDeviceAudio(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Determine if the SDK has enabled share device sound. This reflects the execution status of `enableShareDeviceAudio` instead of `startShareComputerAudio`.
       * @method isShareDeviceAudioEnabled
       * @return {Boolean} True if enabled. Otherwise returns false.
       */
      isShareDeviceAudioEnabled: function () {
        if (_addon) {
          return _addon.IsShareDeviceAudioEnabled()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Enable or disable the optimization of frame rate, you can enable it when there is video in shared content.
       * @method enableOptimizeForSharedVideo
       * @param {Boolean} bEnable True indicates to enable. False disable.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       */
      enableOptimizeForSharedVideo: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const bEnable = clientOpts.bEnable
            const EnableOptimizeForSharedVideoParams = new messages.EnableOptimizeForSharedVideoParams()
            EnableOptimizeForSharedVideoParams.setEnable(bEnable)
            const bytes = EnableOptimizeForSharedVideoParams.serializeBinary()
            return _addon.EnableOptimizeForSharedVideo(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Determine if optimization for shared video is enabled.
       * @method isOptimizeForSharedVideoEnabled
       * @return {Boolean} True if enabled. Otherwise returns false.
       */
      isOptimizeForSharedVideoEnabled: function () {
        if (_addon) {
          return _addon.IsOptimizeForSharedVideoEnabled()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Start sharing a camera feed specified by the cameraID as the second camera.
       * @method startShare2ndCamera
       * @param {String} cameraID The camera ID. Warning: This must be a different camera than the one sending your primary video.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       */
      startShare2ndCamera: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const cameraID = clientOpts.cameraID
            const StartShare2ndCameraParams = new messages.StartShare2ndCameraParams()
            StartShare2ndCameraParams.setZnCameraid(cameraID)
            const bytes = StartShare2ndCameraParams.serializeBinary()
            return _addon.StartShare2ndCamera(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Start share preprocessing.
       * @method startShareWithPreprocessing
       * @param {Number} type The share pre-process type.
       * @param {String} handle The window handle that to share and pre-process.
       * @param {String} monitorID The screen name that to share and pre-process.
       * @param {Number} processID The process ID that to share and pre-process, only for mac platform.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       */
      startShareWithPreprocessing: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const type = clientOpts.type || ZoomVideoSDKSharePreprocessType.ZoomVideoSDKSharePreprocessType_none
            const handle = clientOpts.handle
            const monitorID = clientOpts.monitorID
            const processID = clientOpts.processID
            const StartShareWithPreprocessingParams = new messages.StartShareWithPreprocessingParams()
            StartShareWithPreprocessingParams.setType(type)
            StartShareWithPreprocessingParams.setHandle(handle)
            StartShareWithPreprocessingParams.setMonitorid(monitorID)
            StartShareWithPreprocessingParams.setProcessid(processID)
            const bytes = StartShareWithPreprocessingParams.serializeBinary()
            return _addon.StartShareWithPreprocessing(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Send preprocessed data.
       * @method sendPreprocessedData
       * @param {Array} buffer Raw data buffer.
       * @param {Number} dataHandle Receive dataHandle from onCapturedRawDataReceived callback data_format param.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       */
      sendPreprocessedData: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const buffer = clientOpts.buffer
            const dataHandle = clientOpts.dataHandle
            const SendPreprocessedDataParams = new messages.SendPreprocessedDataParams()
            SendPreprocessedDataParams.setBuffer(buffer)
            SendPreprocessedDataParams.setDatahandle(dataHandle)
            const bytes = SendPreprocessedDataParams.serializeBinary()
            return _addon.SendPreprocessedData(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Creates annotation helper based on a shared view. Only available for self share.
       * @method createAnnotationHelper
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       * @warning The view passed in this function should be subscribed share view. If the share view aspect mode is set to ZoomVideoSDKVideoAspect_Full_Filled, annotation is not supported.
       */
      createAnnotationHelper: function () {
        if (_addon) {
          return _addon.CreateAnnotationHelper()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Destroys annotation helper.
       * @method destroyAnnotationHelper
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       */
      destroyAnnotationHelper: function () {
        if (_addon) {
          return _addon.DestroyAnnotationHelper()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Sets the vanishing tool time.
       * @method setAnnotationVanishingToolTime
       * @param {Number} displayTime The time in milliseconds the tool remains visible before fading.
       * @param {Number} vanishingTime The time in milliseconds for the tool to fade out after displayTime.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.
       * @note This setting only takes effect for the user's own share. The displayTime can be 0 or up to 15000 milliseconds (15 seconds), 
       *       and the vanishingTime must be greater than 1000 milliseconds (1 second) and less than or equal to 15000 milliseconds (15 seconds).
      */
      setAnnotationVanishingToolTime: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const displayTime = clientOpts.displayTime
            const vanishingTime = clientOpts.vanishingTime
            const SetAnnotationVanishingToolTimeParams = new messages.SetAnnotationVanishingToolTimeParams()
            SetAnnotationVanishingToolTimeParams.setDisplaytime(displayTime)
            SetAnnotationVanishingToolTimeParams.setVanishingtime(vanishingTime)
            const bytes = SetAnnotationVanishingToolTimeParams.serializeBinary()
            return _addon.SetAnnotationVanishingToolTime(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Gets the current vanishing tool time settings.
       * @method getAnnotationVanishingToolTime
       * @return {Object} If the function succeeds, returns an object with the following members:
       *   - {Number} err - If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.
       *   - {Number} displayTime - The time in milliseconds the tool remains visible before fading.
       *   - {Number} vanishingTime - The time in milliseconds for the tool to fade out after displayTime.
       * @note This function can only retrieve the time settings for your own share.
       */
      getAnnotationVanishingToolTime: function () {
        if (_addon) {
          return _addon.GetAnnotationVanishingToolTime()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Starts sharing a specific application process.
       * @method startShareApplication
       * @param {Number} processID The process identifier of the target application. Must be valid in the current user session.
       * @param {Boolean} isWithDeviceAudio True is share computer sound when share screen/window, otherwise not.
       * @param {Boolean} isOptimizeForSharedVideo True is optimize the frame rate when share screen/window, otherwise not.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise the method failed.
       * @note This API is only supported on macOS.
       */
      startShareApplication: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const processID  = Number(clientOpts.processID)
            const isWithDeviceAudio = clientOpts.isWithDeviceAudio || false
            const isOptimizeForSharedVideo = clientOpts.isOptimizeForSharedVideo || false
            const StartShareApplicationParams = new messages.StartShareApplicationParams()
            StartShareApplicationParams.setProcessid(processID)
            StartShareApplicationParams.setIswithdeviceaudio(isWithDeviceAudio)
            StartShareApplicationParams.setIsoptimizeforsharedvideo(isOptimizeForSharedVideo)
            const bytes = StartShareApplicationParams.serializeBinary()
            return _addon.StartShareApplication(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get the list of applications available for sharing.
       * @method getAppList
       * @return {Array} Array of application objects with the following properties:
       *   - {Number} handle - window handle
       *   - {String} title - window title
       *   - {Number} processId - Application process ID
       *   - {String} appName - Application name
       * @note This method is only available on Windows and macOS platforms. On other platforms return an empty array.
       */
      getAppList: function () {
        if (_addon) {
          return _addon.GetAppList()
        }
        return []
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
