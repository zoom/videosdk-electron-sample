import { ZoomVideoSDKErrors } from './zoom_video_sdk_defines.js'
import messages from './electron_zoomvideosdk_pb.js'

export default (function () {
  var instance
  /**
    * Zoom Video SDK Test Audio Device
    * @module zoom_video_sdk_test_audio_device
    * @return {ZoomVideoSDKTestAudioDevice}
    */
  function init (opts) {
    const clientOpts = {...opts}
    // Private methods and variables
    if (!clientOpts.addon) {
      return null
    }
    const _addon = clientOpts.addon.GetTestAudioDevice()

    return {
      // Public methods and variables
      /**
       * Start the mic test.
       * @method startMicTestRecording
       * @param {String} deviceID Specify to test a mic device. If the param is a wrong mic ID, the SDK will return an error. Otherwise the SDK tests the specified device and sets it as selected. The SDK will test the default device if no parameter is input.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       * @note The function is disabled if no event handler is set.
       */
      startMicTestRecording: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const deviceID = clientOpts.deviceID
            const StartMicTestRecordingParams = new messages.StartMicTestRecordingParams()
            StartMicTestRecordingParams.setDeviceid(deviceID)
            const bytes = StartMicTestRecordingParams.serializeBinary()
            return _addon.StartMicTestRecording(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Stop the mic test. The SDK will return an error if there was no mic test.
       * @method stopMicTestRecording
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       * @note The function is disabled if no event handler is set.
       */
      stopMicTestRecording: function () {
        if (_addon) {
          try {
            return _addon.StopMicTestRecording()
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Play the mic recorded sound. If there was no mic test, the SDK returns an error.
       * @method playMicTestRecording
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       * @note The function is disabled if no event handler is set.
       */
      playMicTestRecording: function () {
        if (_addon) {
          try {
            return _addon.PlayMicTestRecording()
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Start the speaker test.
       * @method startSpeakerTest
       * @param {String} deviceID Specify to test a speaker device. If the param is a wrong speaker ID, the SDK will return an error. Otherwise the SDK tests the specified device and sets it as selected. The SDK will test the default device if no parameter is input.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       * @note The function is disabled if no event handler is set.
       */
      startSpeakerTest: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const deviceID = clientOpts.deviceID
            const StartSpeakerTestParams = new messages.StartSpeakerTestParams()
            StartSpeakerTestParams.setDeviceid(deviceID)
            const bytes = StartSpeakerTestParams.serializeBinary()
            return _addon.StartSpeakerTest(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Stop the speaker test. The SDK will return an error if there was no speaker test.
       * @method stopSpeakerTest
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       * @note The function is disabled if no event handler is set.
       */
      stopSpeakerTest: function () {
        if (_addon) {
          try {
            return _addon.StopSpeakerTest()
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Set the time interval for the audio test.
       * @method setTimerInterval
       * @param {Number} timerInterval Usually the SDK sends the mic and speaker volumes every 200 ms by default via onMicSpeakerVolumeChanged callback. With this function, the user can modify the time interval instead of 200. Accepted values between 50 to 1000 milliseconds.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       * @note This interface will stop the mic or speaker test (if there is ongoing). As a best practice, call it before the audio test.
       */
      setTimerInterval: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const timerInterval = clientOpts.timerInterval
            const SetTimerIntervalParams = new messages.SetTimerIntervalParams()
            SetTimerIntervalParams.setTimerinterval(timerInterval)
            const bytes = SetTimerIntervalParams.serializeBinary()
            return _addon.SetTimerInterval(bytes)
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
