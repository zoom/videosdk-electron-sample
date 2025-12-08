import { ZoomVideoSDKErrors, ZoomVideoSDKSuppressBackgroundNoiseLevel, ZoomVideoSDKEchoCancellationLevel } from './zoom_video_sdk_defines.js'
import messages from './electron_zoomvideosdk_pb.js'

export default (function () {
  var instance
  /**
    * Zoom Video SDK Audio Setting
    * @module zoom_video_sdk_audio_setting
    * @return {ZoomVideoSDKAudioSetting}
    */
  function init (opts) {
    const clientOpts = {...opts}
    // Private methods and variables
    if (!clientOpts.addon) {
      return null
    }
    const _addon = clientOpts.addon.GetAudioSetting()

    return {
      // Public methods and variables
      /**
       * Get the suppress background noise level.
       * @method getSuppressBackgroundNoiseLevel
       * @return {Object} If the function succeeds, the return value is object containing:
       *   - err: Error code, ZoomVideoSDKErrors_Success if successful
       *   - level: The suppress background noise level, {@link ZoomVideoSDKSuppressBackgroundNoiseLevel} enum
       */
      getSuppressBackgroundNoiseLevel: function () {
        if (_addon) {
          try {
            return _addon.GetSuppressBackgroundNoiseLevel()
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Set the suppress background noise level.
       * @method setSuppressBackgroundNoiseLevel
       * @param {Number} level The new suppress background noise level to be set, {@link ZoomVideoSDKSuppressBackgroundNoiseLevel} enum.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       */
      setSuppressBackgroundNoiseLevel: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const level = clientOpts.level || ZoomVideoSDKSuppressBackgroundNoiseLevel.ZoomVideoSDKSuppressBackgroundNoiseLevel_Auto
            const SetSuppressBackgroundNoiseLevelParams = new messages.SetSuppressBackgroundNoiseLevelParams()
            SetSuppressBackgroundNoiseLevelParams.setLevel(level)
            const bytes = SetSuppressBackgroundNoiseLevelParams.serializeBinary()
            return _addon.SetSuppressBackgroundNoiseLevel(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Call this method to enable or disable the original input of mic.
       * @method enableMicOriginalInput
       * @param {Boolean} bEnable True to enable the original input of microphone or false to disable it.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       */
      enableMicOriginalInput: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const bEnable = clientOpts.bEnable
            const EnableMicOriginalInputParams = new messages.EnableMicOriginalInputParams()
            EnableMicOriginalInputParams.setBenable(bEnable)
            const bytes = EnableMicOriginalInputParams.serializeBinary()
            return _addon.EnableMicOriginalInput(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Determine whether the original input of the microphone is enabled.
       * @method isMicOriginalInputEnable
       * @return {Object} If the function succeeds, the return value is object containing:
       *   - err: Error code, ZoomVideoSDKErrors_Success if successful
       *   - bEnable: True if the original input of the microphone is enabled, otherwise false
       */
      isMicOriginalInputEnable: function () {
        if (_addon) {
          try {
            return _addon.IsMicOriginalInputEnable()
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Set whether to enable the function of high fidelity music mode or not.
       * @method enableHighFidelityMusicMode
       * @param {Boolean} bEnable True means to enable the function, FALSE not.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       * @note This function is valid only if mic original input is enabled, otherwise invalid.
       */
      enableHighFidelityMusicMode: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const bEnable = clientOpts.bEnable
            const EnableHighFidelityMusicModeParams = new messages.EnableHighFidelityMusicModeParams()
            EnableHighFidelityMusicModeParams.setBenable(bEnable)
            const bytes = EnableHighFidelityMusicModeParams.serializeBinary()
            return _addon.EnableHighFidelityMusicMode(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Check whether the high fidelity music mode is enabled or not.
       * @method isHighFidelityMusicModeEnable
       * @return {Object} If the function succeeds, the return value is object containing:
       *   - err: Error code, ZoomVideoSDKErrors_Success if successful
       *   - bEnable: True if the high fidelity music mode is enabled, otherwise false
       */
      isHighFidelityMusicModeEnable: function () {
        if (_addon) {
          try {
            return _addon.IsHighFidelityMusicModeEnable()
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Set whether to disable the function of echo cancellation or not.
       * @method enableEchoCancellation
       * @param {Boolean} bEnable True means to enable the function, FALSE not.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       * @note This function is valid only if mic original input is enabled, otherwise invalid.
       */
      enableEchoCancellation: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const bEnable = clientOpts.bEnable
            const EnableEchoCancellationParams = new messages.EnableEchoCancellationParams()
            EnableEchoCancellationParams.setBenable(bEnable)
            const bytes = EnableEchoCancellationParams.serializeBinary()
            return _addon.EnableEchoCancellation(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Check whether the echo cancellation is enabled or not.
       * @method isEchoCancellationEnable
       * @return {Object} If the function succeeds, the return value is object containing:
       *   - err: Error code, ZoomVideoSDKErrors_Success if successful
       *   - bEnable: True if the echo cancellation is enabled, otherwise false
       */
      isEchoCancellationEnable: function () {
        if (_addon) {
          try {
            return _addon.IsEchoCancellationEnable()
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Enable or disable the stereo audio.
       * @method enableStereoAudio
       * @param {Boolean} bEnable True indicates to enable the stereo audio.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       * @note This function is valid only if mic original input is enabled, otherwise invalid.
       */
      enableStereoAudio: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const bEnable = clientOpts.bEnable
            const EnableStereoAudioParams = new messages.EnableStereoAudioParams()
            EnableStereoAudioParams.setBenable(bEnable)
            const bytes = EnableStereoAudioParams.serializeBinary()
            return _addon.EnableStereoAudio(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get the flag to enable/disable the stereo audio.
       * @method isStereoAudioEnable
       * @return {Object} If the function succeeds, the return value is object containing:
       *   - err: Error code, ZoomVideoSDKErrors_Success if successful
       *   - bEnable: True if the stereo audio is enabled, otherwise false
       */
      isStereoAudioEnable: function () {
        if (_addon) {
          try {
            return _addon.IsStereoAudioEnable()
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get the echo cancellation level.
       * @method getEchoCancellationLevel
       * @return {Object} If the function succeeds, the return value is object containing:
       *   - err: Error code, ZoomVideoSDKErrors_Success if successful
       *   - level: The echo cancellation level, {@link ZoomVideoSDKEchoCancellationLevel} enum
       */
      getEchoCancellationLevel: function () {
        if (_addon) {
          try {
            return _addon.GetEchoCancellationLevel()
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Set the echo cancellation level.
       * @method setEchoCancellationLevel
       * @param {Number} level The new echo cancellation level to be set, {@link ZoomVideoSDKEchoCancellationLevel} enum.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       */
      setEchoCancellationLevel: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const level = clientOpts.level || ZoomVideoSDKEchoCancellationLevel.ZoomVideoSDKEchoCancellationLevel_Default
            const SetEchoCancellationLevelParams = new messages.SetEchoCancellationLevelParams()
            SetEchoCancellationLevelParams.setLevel(level)
            const bytes = SetEchoCancellationLevelParams.serializeBinary()
            return _addon.SetEchoCancellationLevel(bytes)
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