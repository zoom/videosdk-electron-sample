import { ZoomVideoSDKErrors } from './zoom_video_sdk_defines.js'
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
       * Share a window
       * @method startShareView
       * @param {String} handle the window handle that will to be share
       * @param {Boolean} isWithDeviceAudio true is share computer sound when share screen/window, otherwise not.
       * @param {Boolean} isOptimizeForSharedVideo true is optimize the frame rate when share screen/window, otherwise not.
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
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
       * Share a screen
       * @method startShareScreen
       * @param {String} monitorID the screen name that will to be share
       * @param {Boolean} isWithDeviceAudio true is share computer sound when share screen/window, otherwise not.
       * @param {Boolean} isOptimizeForSharedVideo true is optimize the frame rate when share screen/window, otherwise not.
       * @return {ZoomSDKError} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
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
      * @return {ZoomSDKError} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      startShareComputerAudio: function () {
        if (_addon) {
          return _addon.StartShareComputerAudio()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Stop share
      * @method stopShare
      * @return {ZoomSDKError} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      stopShare: function () {
        if (_addon) {
          return _addon.StopShare()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Determine if myself is sharing
      * @method isSharingOut
      * @return {Boolean} true if myself is sharing. Otherwise returns false.
      */
      isSharingOut: function () {
        if (_addon) {
          return _addon.IsSharingOut()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Determine if myself is sharing screen
      * @method isScreenSharingOut
      * @return {Boolean} true if myself is sharing screen. Otherwise returns false.
      */
      isScreenSharingOut: function () {
        if (_addon) {
          return _addon.IsScreenSharingOut()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Determine if other user is sharing
      * @method isOtherSharing
      * @return {Boolean} true if other user is sharing screen. Otherwise returns false.
      */
      isOtherSharing: function () {
        if (_addon) {
          return _addon.IsOtherSharing()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Lock current share.(only host call)
      * @method lockShare
      * @param {Boolean} bLock
      * @return {ZoomSDKError} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
	      Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
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
      * Determine if share is locked
      * @method isShareLocked
      * @return {Boolean} true if share is locked. Otherwise returns false.
      */
      isShareLocked: function () {
        if (_addon) {
          return _addon.IsShareLocked()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Enable or disable the computer sound when sharing, if virtual speaker is enabled, don't support share audio.
      * @method enableShareDeviceAudio
      * @param {Boolean} bEnable, true indicates to enable. false disable.
      * @return {ZoomSDKError} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
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
      * Determine if share computer sound is enabled.
      * @method isShareDeviceAudioEnabled
      * @return {Boolean} true if enabled. Otherwise returns false.
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
      * @param {Boolean} bEnable, true indicates to enable. false disable.
      * @return {ZoomSDKError} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
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
      * @return {Boolean} true if enabled. otherwise returns false.
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
      * @param {String} cameraID, The camera ID.Warning: This must be a different camera than the one sending your primary video.
      * @return {ZoomSDKError} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
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
