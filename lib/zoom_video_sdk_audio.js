import { ZoomVideoSDKErrors } from './zoom_video_sdk_defines.js'
import messages from './electron_zoomvideosdk_pb.js'
import { setUserInfo } from './zoom_video_sdk_user_util.js'

export default (function () {
  var instance
  /**
    * Return an instance to manage audio controls related to the current video SDK session.
    * @module zoom_video_sdk_audio
    * @return {ZoomVideoSDKAudio}
    */
  function init (opts) {
    const clientOpts = {...opts}
    // Private methods and variables
    if (!clientOpts.addon) {
      return null
    }
    const _addon = clientOpts.addon.GetAudioHelper()

    return {
      // Public methods and variables
      /**
       * Start audio with voip.
       * @method startAudio
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       */
      startAudio: function () {
        if (_addon) {
          return _addon.StartAudio()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Stop voip.
       * @method stopAudio
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       */
      stopAudio: function () {
        if (_addon) {
          return _addon.StopAudio()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Mute user's voip audio. 0 means current user (myself).
       * @method muteAudio
       * @param {Object} user The user which you want to mute.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       */
      muteAudio: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const user = setUserInfo(clientOpts.user)
            const MuteAudioParams = new messages.MuteAudioParams()
            MuteAudioParams.setUser(user)
            const bytes = MuteAudioParams.serializeBinary()
            return _addon.MuteAudio(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Unmute user's voip audio.
       * @method unMuteAudio
       * @param {Object} user The user which you want to unMute.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       * @note This function will trigger the callback onHostAskUnmute().
       */
      unMuteAudio: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const user = setUserInfo(clientOpts.user)
            const UnMuteAudioParams = new messages.UnMuteAudioParams()
            UnMuteAudioParams.setUser(user)
            const bytes = UnMuteAudioParams.serializeBinary()
            return _addon.UnMuteAudio(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get speaker device list.
       * @method getSpeakerList
       * @return {Array} If the function succeeds, the return value is speaker device list containing:
       *   - deviceID: The speaker device ID
       *   - deviceName: The speaker device name
       *   - isSelectedDevice: Whether the speaker is the selected device
       *   Otherwise null.
       */
      getSpeakerList: function () {
        if (_addon) {
          const result = _addon.GetSpeakerList()
          const message = messages.GetSpeakerList.deserializeBinary(result)
          const tempList = message.getSpeakerinfoList()
          let speakerList = []
          for (let val of tempList) {
            let obj = {
              deviceID: val.getDeviceid(),
              deviceName: val.getDevicename(),
              isSelectedDevice: val.getIsselecteddevice()
            }
            speakerList.push(obj)
          }
          return speakerList
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get mic device list.
       * @method getMicList
       * @return {Array} If the function succeeds, the return value is mic device list containing:
       *   - deviceID: The mic device ID
       *   - deviceName: The mic device name
       *   - isSelectedDevice: Whether the mic is the selected device
       *   Otherwise null.
       */
      getMicList: function () {
        if (_addon) {
          const result = _addon.GetMicList()
          const message = new messages.GetMicList.deserializeBinary(result)
          const tempList = message.getMicinfoList()
          let micList = []
          for (let val of tempList) {
            let obj = {
              deviceID: val.getDeviceid(),
              deviceName: val.getDevicename(),
              isSelectedDevice: val.getIsselecteddevice()
            }
            micList.push(obj)
          }
          return micList
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Select some speaker device as default device.
       * @method selectSpeaker
       * @param {String} deviceID Device ID.
       * @param {String} deviceName Device name.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       */
      selectSpeaker: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const deviceID = clientOpts.deviceID
            const deviceName = clientOpts.deviceName
            const SelectSpeakerParams = new messages.SelectSpeakerParams()
            SelectSpeakerParams.setZnDeviceid(deviceID)
            SelectSpeakerParams.setZnDevicename(deviceName)
            const bytes = SelectSpeakerParams.serializeBinary()
            return _addon.SelectSpeaker(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Select some mic device as default device.
       * @method selectMic
       * @param {String} deviceID Device ID.
       * @param {String} deviceName Device name.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       */
      selectMic: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const deviceID = clientOpts.deviceID
            const deviceName = clientOpts.deviceName
            const SelectMicParams = new messages.SelectMicParams()
            SelectMicParams.setZnDeviceid(deviceID)
            SelectMicParams.setZnDevicename(deviceName)
            const bytes = SelectMicParams.serializeBinary()
            return _addon.SelectMic(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Subscribe audio raw data.
       * @method subscribe
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       */
      subscribe: function () {
        if (_addon) {
          return _addon.Subscribe()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * UnSubscribe audio raw data.
       * @method unSubscribe
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       */
      unSubscribe: function () {
        if (_addon) {
          return _addon.UnSubscribe()
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
