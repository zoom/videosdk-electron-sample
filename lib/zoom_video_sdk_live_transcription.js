import { ZoomVideoSDKErrors } from './zoom_video_sdk_defines.js'
import messages from './electron_zoomvideosdk_pb.js'
import { setUserInfo } from './zoom_video_sdk_user_util.js'

export default (function () {
  var instance
  /**
    * live transcription helper.
    * @module zoom_video_sdk_live_transcription
    * @return {ZoomVideoSDKLiveTranscription}
    */
  function init (opts) {
    const clientOpts = {...opts}
    // Private methods and variables
    if (!clientOpts.addon) {
      return null
    }
    const _addon = clientOpts.addon.GetLiveTranscriptionHelper()

    return {
      // Public methods and variables
      /**
       * Query if the user can start live transcription.
       * @method canStartLiveTranscription
       * @return {Boolean}
       */
      canStartLiveTranscription: function () {
        if (_addon) {
          try {
            return _addon.CanStartLiveTranscription()
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get the current live transcription status.
       * @method getLiveTranscriptionStatus
       * @return {Object} the current live transcription status. For more details, see {@link ZoomVideoSDKLiveTranscriptionStatus} enum.
       */
      getLiveTranscriptionStatus: function () {
        if (_addon) {
          try {
            return _addon.GetLiveTranscriptionStatus()
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * If the session allows multi-language transcription, all users can start live transcription.
       * @method startLiveTranscription
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
          Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
       */
      startLiveTranscription: function () {
        if (_addon) {
          try {
            return _addon.StartLiveTranscription()
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * If the session allows multi-language transcription,all users can stop live transcription.
       * @method stopLiveTranscription
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
          Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
       */
      stopLiveTranscription: function () {
        if (_addon) {
          try {
            return _addon.StopLiveTranscription()
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get the list of all available spoken languages in session.
       * @method getAvailableSpokenLanguages
       * @return {Array} If the function succeeds, the return value is the list of the available spoken languages in a session. Otherwise failed, the return value is NULL.	
       */
      getAvailableSpokenLanguages: function () {
        if (_addon) {
          try {
            const result = _addon.GetAvailableSpokenLanguages()
            const message = new messages.LTTLanguagesList.deserializeBinary(result)
            const tempList = message.getLttlanguageinfoList()
            let lttLanguageList = []
            for (let val of tempList) {
              let obj = {
                lttLanguageID: val.getLttlanguageid(),
                lttLanguageName: val.getLttlanguagename()
              }
              lttLanguageList.push(obj)
            }
            return lttLanguageList
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get the list of all available translation languages in a session.
       * @method GetAvailableTranslationLanguages
       * @return {Array} If the function succeeds, the return value is the list of all available translation languages in a session. Otherwise failed, the return value is NULL.
       */
      getAvailableTranslationLanguages: function () {
        if (_addon) {
          try {
            const result = _addon.GetAvailableTranslationLanguages()
            const message = new messages.LTTLanguagesList.deserializeBinary(result)
            const tempList = message.getLttlanguageinfoList()
            let lttLanguageList = []
            for (let val of tempList) {
              let obj = {
                lttLanguageID: val.getLttlanguageid(),
                lttLanguageName: val.getLttlanguagename()
              }
              lttLanguageList.push(obj)
            }
            return lttLanguageList
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Set the spoken language of the current user.
       * @method setSpokenLanguage
       * @param {Number} languageID The spoken language ID.
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
          Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
       */
      setSpokenLanguage: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const languageID = clientOpts.languageID
            const SetSpokenLanguageParams = new messages.SetSpokenLanguageParams()
            SetSpokenLanguageParams.setLanguageid(languageID)
            const bytes = SetSpokenLanguageParams.serializeBinary()
            return _addon.SetSpokenLanguage(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Set the translation language of the current user.	
       * @method setTranslationLanguage
       * @param {Number} languageID The translation language ID. If the language id is set to -1, live translation will be disabled.
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
          Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
       */
      setTranslationLanguage: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const languageID = clientOpts.languageID
            const SetTranslationLanguageParams = new messages.SetTranslationLanguageParams()
            SetTranslationLanguageParams.setLanguageid(languageID)
            const bytes = SetTranslationLanguageParams.serializeBinary()
            return _addon.SetTranslationLanguage(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get the spoken language of the current user.
       * @method getSpokenLanguage
       * @return {Object} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
          Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
       */
      getSpokenLanguage: function () {
        if (_addon) {
          try {
            return _addon.GetSpokenLanguage()
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get the translation language of the current user.
       * @method getTranslationLanguage
       * @return {Object} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
          Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
       */
      getTranslationLanguage: function () {
        if (_addon) {
          try {
            return _addon.GetTranslationLanguage()
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
