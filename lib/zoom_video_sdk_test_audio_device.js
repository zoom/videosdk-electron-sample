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
      * Start to test the mic. The function is disabled if no event handler is set.
      * @method startMicTestRecording
      * @param {String} deviceID Specify to test a mic device. If the param is a wrong mic ID, the SDK will return an error. Otherwise the SDK tests the specified device and sets it as selected. The SDK will test the default device if no parameter is input.
      * @return {Object} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
	      Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
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
      * Stop the mic test. The SDK will return an error if there is no mic test. The function is disabled if no event handler is set.
      * @method stopMicTestRecording
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
	      Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
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
      * Play the mic recorded sound. If there is no mic testing, SDK return an error. The function is disabled if no event handler is set.
      * @method playMicTestRecording
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
	      Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
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
      * Start to test the speaker. The function is disabled if no event handler is set.
      * @method startSpeakerTest
      * @param {String} deviceID deviceID Specify to test a speaker device. If the param is a wrong speaker ID, the SDK will return an error. Otherwise the SDK tests the specified device and sets it as selected. The SDK will test the default device if no parameter is input.
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
	      Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
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
      * Stop the speaker test. The SDK will return an error if there is no speaker test. The function is disabled if no event handler is set.
      * @method stopSpeakerTest
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
	      Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
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
      * Set the time interval for audio test. This interface will stop the mic/speaker test(if there is). It is suggested to call it before audio test.
      * @method setTimerInterval
      * @param {Number} timerInterval timerInterval Usually the SDK sends the mic and speaker volumes every 200 ms by default via onMicSpeakerVolumeChanged callback. With this function, the user can modify the time interval instead of 200. The time interval varies only from 50 to 1000 in millisecond.
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
	      Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
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
