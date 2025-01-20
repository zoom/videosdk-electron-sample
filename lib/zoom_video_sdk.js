import messages from './electron_zoomvideosdk_pb.js'
import ZoomVideoSDKSessionInfo from './zoom_video_sdk_session_info.js'
import ZoomVideoSDKAudio from './zoom_video_sdk_audio.js'
import ZoomVideoSDKAudioSetting from './zoom_video_sdk_audio_setting.js'
import ZoomVideoSDKTestAudioDevice from './zoom_video_sdk_test_audio_device.js'
import ZoomVideoSDKShare from './zoom_video_sdk_share.js'
import ZoomVideoSDKVideo from './zoom_video_sdk_video.js'
import ZoomVideoSDKUser from './zoom_video_sdk_user.js'
import ZoomVideoSDKChat from './zoom_video_sdk_chat.js'
import ZoomVideoSDKLiveStream from './zoom_video_sdk_live_stream.js'
import ZoomVideoSDKIncomingLiveStream from './zoom_video_sdk_incoming_live_stream.js'
import ZoomVideoSDKCmd from './zoom_video_sdk_cmd.js'
import ZoomVideoSDKRecording from './zoom_video_sdk_recording.js'
import ZoomVideoSDKRemoteCameraControl from './zoom_video_sdk_remote_camera_control.js'
import ZoomVideoSDKCameraControlRequestHandler from './zoom_video_sdk_camera_control_request_handler.js'
import ZoomVideoSDKPhone from './zoom_video_sdk_phone.js'
import ZoomVideoSDKLiveTranscription from './zoom_video_sdk_live_transcription.js'
import ZoomVideoSDKShareSetting from './zoom_video_sdk_share_setting.js'
import ZoomVideoSDKRemoteControl from './zoom_video_sdk_remote_control.js'
import { ZoomVideoSDKErrors } from './zoom_video_sdk_defines.js'
const { platform, arch } = process

export default (() => {
  let instance
  /**
   * Zoom Video SDK API manager. Main singleton object that controls the video session creation, event callbacks and other main features of video SDK.
   * @module zoom_video_sdk
   * @param {Function} onNodeAddonCallbacks callback receives the session callback event.
   * @return {ZoomVideoSDK}
   */
  function init (opts) {
    // Private methods and variables
    const clientOpts = opts || {}
    let nativeSdkPath, addon
    try {
      switch (`${platform}:${arch}`) {
        case 'darwin:x64': 
        case 'darwin:arm64':
          nativeSdkPath = 'sdk/mac'
          break;
        case 'win32:ia32':
          nativeSdkPath = 'sdk/win32'
          break;
        case 'win32:x64':
          nativeSdkPath = 'sdk/win64'
          break;
        case 'linux:x64': 
          nativeSdkPath = 'sdk/linux'
          break;
      }
      require(`../${nativeSdkPath}/zoomvideosdk_napi_util.node`)
      addon = require(`../${nativeSdkPath}/zoomvideosdk.node`).exports()
    } catch (error) {
      console.log(error)
    }
    let _isSDKInitialized = false

    let _onNodeAddonCallbacks = clientOpts.onNodeAddonCallbacks || null
    
    /**
      callback receives the session callback event.
      @event onNodeAddonCallbacks
    */
    function onNodeAddonCallbacks (data) {
      if (_onNodeAddonCallbacks) {
        _onNodeAddonCallbacks(data)
      }
    }

    return {
      // Public methods and variables
      /**
       * set session callback event.
       * @method setNodeAddonCallbacks
       * @param {Function} onNodeAddonCallbacks callback receives all the callbacks related to a session.
       * @return {Boolean}
       */
      setNodeAddonCallbacks: function (onNodeAddonCallbacks) {
        if (onNodeAddonCallbacks && onNodeAddonCallbacks instanceof Function) {
          _onNodeAddonCallbacks = onNodeAddonCallbacks
          return true
        }
        return false
      },
      /**
       * Get Zoom video sdk object.
       * @method createZoomVideoSDKObj
       * @param {String} path
       * @return {Number} If the function succeed, the return value is Zoom video sdk object. Otherwise NULL.
       */
      createZoomVideoSDKObj: function (opts) {
        if (addon) {
          const clientOpts = opts || {}
          const path = clientOpts.path || ''
          try {
            const CreateVideoSDKObjParam = new messages.CreateVideoSDKObjParam()
            CreateVideoSDKObjParam.setPath(path)
            const bytes = CreateVideoSDKObjParam.serializeBinary()
            return addon.CreateZoomVideoSDKObj(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Destroy Zoom video sdk object.
      * @method destroyZoomVideoSDKObj
      * @return {Number}
      */
      destroyZoomVideoSDKObj: function () {
        if (addon) {
          return addon.DestroyZoomVideoSDKObj()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Initialize the Zoom SDK with the appropriate parameters.
       * @method Initialize
       * @param {String} domain
       * @param {String} logFilePrefix
       * @param {Boolean} enableLog
       * @param {Number} audioRawDataMemoryMode  Defined in: <a href="../files/lib_settings.js.html#l42">ZoomVideoSDKRawDataMemoryMode</a>
       * @param {Number} videoRawDataMemoryMode
       * @param {Number} shareRawDataMemoryMode
       * @param {String} speakerTestFilePath only support mp3 format,The size cannot exceed 1M
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
	        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
       */
      initialize: function (opts) {
        if (addon) {
          const clientOpts = opts || {}
          const domain = clientOpts.domain || 'https://www.zoom.us'
          const logFilePrefix = clientOpts.logFilePrefix
          const enableLog = clientOpts.enableLog
          const audioRawDataMemoryMode = Number(clientOpts.audioRawDataMemoryMode)
          const videoRawDataMemoryMode = Number(clientOpts.videoRawDataMemoryMode)
          const shareRawDataMemoryMode = Number(clientOpts.shareRawDataMemoryMode)
          const speakerTestFilePath = clientOpts.speakerTestFilePath
          try {
            const VideoSDKInitParams = new messages.VideoSDKInitParams()
            VideoSDKInitParams.setDomain(domain)
            VideoSDKInitParams.setLogfileprefix(logFilePrefix)
            VideoSDKInitParams.setEnablelog(enableLog)
            VideoSDKInitParams.setAudiorawdatamemorymode(audioRawDataMemoryMode)
            VideoSDKInitParams.setZnVideorawdatamemorymode(videoRawDataMemoryMode)
            VideoSDKInitParams.setZnSharerawdatamemorymode(shareRawDataMemoryMode)
            VideoSDKInitParams.setSpeakertestfilepath(speakerTestFilePath)
            const bytes = VideoSDKInitParams.serializeBinary()
            addon.SetNodeAddonCallbacks(onNodeAddonCallbacks)
            const ret = addon.Initialize(bytes)
            if (ZoomVideoSDKErrors.ZoomVideoSDKErrors_Success === ret) {
              _isSDKInitialized = true
            } else {
              _isSDKInitialized = false
            }
            return ret
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Clean up Zoom Video SDK.
       * @method cleanup
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
	        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
       */
      cleanup: function () {
        if (addon) {
          return addon.CleanUp()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Call this method to join a session with the appropriate parameters. When successful, the SDK will attempt to join a session. Use the callbacks to confirm whether the SDK actually joined.
       * @method Join Session
       * @param {String} sessionName
       * @param {String} sessionPassword
       * @param {String} token
       * @param {String} userName
       * @param {Boolean} localVideoOn
       * @param {Boolean} connect
       * @param {Boolean} mute
       * @param {Boolean} preProcessor
       * @param {Boolean} externalVideoSource
       * @param {Boolean} sessionIdleTimeoutMins, [Optional] The amount of time in minutes after which an idle session will end. If the value is 0, the session will stay alive indefinitely.
       * @return {Number} If the function succeed, the return value is the pointer to IZoomVideoSDKSession object.
	        Otherwise NULL. To get extended error information, {@link IZoomVideoSDKSession} enum.
       */
      joinSession: function (opts) {
        if (addon) {
          const clientOpts = {...opts}
          const sessionName = clientOpts.sessionName
          const sessionPassword = clientOpts.sessionPassword
          const token = clientOpts.token
          const username = clientOpts.username
          const localVideoOn = clientOpts.localVideoOn
          const connect = clientOpts.connect
          const mute = clientOpts.mute
          const preProcessor = clientOpts.preProcessor
          const externalVideoSource = clientOpts.externalVideoSource
          const sessionIdleTimeoutMins = clientOpts.sessionIdleTimeoutMins
          try {
            const VideoSDKSessionContext = new messages.VideoSDKSessionContext()
            VideoSDKSessionContext.setSessionname(sessionName)
            VideoSDKSessionContext.setSessionpassword(sessionPassword)
            VideoSDKSessionContext.setToken(token)
            VideoSDKSessionContext.setUsername(username)
            VideoSDKSessionContext.setLocalvideoon(localVideoOn)
            VideoSDKSessionContext.setConnect(connect)
            VideoSDKSessionContext.setMute(mute)
            VideoSDKSessionContext.setPreprocessor(preProcessor)
            VideoSDKSessionContext.setExternalvideosource(externalVideoSource)
            VideoSDKSessionContext.setSessionidletimeoutmins(sessionIdleTimeoutMins)
            const bytes = VideoSDKSessionContext.serializeBinary()
            return addon.JoinSession(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Call this method to leave a session previously joined through joinSession method call. When successful, the SDK will attempt to leave a session. Use the callbacks to confirm whether the SDK actually left.
       * @method leaveSession
       * @param {Boolean} bEnd true if the host should end the entire session, or false if the host should just leave the session. 
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
	        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
       */
      leaveSession: function (opts) {
        if (addon) {
          const clientOpts = {...opts}
          const bEnd = clientOpts.bEnd
          try {
            const LeaveSessionParams = new messages.LeaveSessionParams()
            LeaveSessionParams.setZnBend(bEnd)
            const bytes = LeaveSessionParams.serializeBinary()
            return addon.LeaveSession(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Check if there is an active session between participants.
       * @method isInSession
       * @return {Boolean} true if there is; false if not
       */
      isInSession: function () {
        if (addon) {
          return addon.IsInSession()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Return Zoom SDK internal version.
       * @method getSDKVersion
       * @return {String} SDK version.
       */
      getSDKVersion: function () {
        if (addon) {
          return addon.GetSDKVersion()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Input session password
       * @method inputSessionPassword
       * @param {String} password is the session password
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
          Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
       */
      inputSessionPassword: function (opts) {
        if (addon) {
          const clientOpts = {...opts}
          try {
            const password = clientOpts.password
            const SessionPasswordParams = new messages.SessionPasswordParams()
            SessionPasswordParams.setZnPassword(password)
            const bytes = SessionPasswordParams.serializeBinary()
            return addon.InputSessionPassword(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Cancel input password.
       * @method leaveSessionIgnorePassword
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
	        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
       */
      leaveSessionIgnorePassword: function () {
        if (addon) {
          return addon.LeaveSessionIgnorePassword()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      getSessionInfo: function (opts) {
        if (_isSDKInitialized) {
          const clientOpts = opts || {}
          clientOpts.addon = addon
          return ZoomVideoSDKSessionInfo.getInstance(clientOpts)
        }
        return null
      },
      getAudioHelper: function (opts) {
        if (_isSDKInitialized) {
          const clientOpts = opts || {}
          clientOpts.addon = addon
          return ZoomVideoSDKAudio.getInstance(clientOpts)
        }
        return null
      },
      getAudioSettingHelper: function (opts) {
        if (_isSDKInitialized) {
          const clientOpts = opts || {}
          clientOpts.addon = addon
          return ZoomVideoSDKAudioSetting.getInstance(clientOpts)
        }
        return null
      },
      getTestAudioDeviceHelper: function (opts) {
        if (_isSDKInitialized) {
          const clientOpts = opts || {}
          clientOpts.addon = addon
          return ZoomVideoSDKTestAudioDevice.getInstance(clientOpts)
        }
        return null
      },
      getVideoHelper: function (opts) {
        if (_isSDKInitialized) {
          const clientOpts = opts || {}
          clientOpts.addon = addon
          return ZoomVideoSDKVideo.getInstance(clientOpts)
        }
        return null
      },
      getShareHelper: function (opts) {
        if (_isSDKInitialized) {
          const clientOpts = opts || {}
          clientOpts.addon = addon
          return ZoomVideoSDKShare.getInstance(clientOpts)
        }
        return null
      },
      getUserHelper: function (opts) {
        if (_isSDKInitialized) {
          const clientOpts = opts || {}
          clientOpts.addon = addon
          return ZoomVideoSDKUser.getInstance(clientOpts)
        }
        return null
      },
      getChatHelper: function (opts) {
        if (_isSDKInitialized) {
          const clientOpts = opts || {}
          clientOpts.addon = addon
          return ZoomVideoSDKChat.getInstance(clientOpts)
        }
        return null
      },
      getLiveStreamHelper: function (opts) {
        if (_isSDKInitialized) {
          const clientOpts = opts || {}
          clientOpts.addon = addon
          return ZoomVideoSDKLiveStream.getInstance(clientOpts)
        }
        return null
      },
      getIncomingLiveStreamHelper: function (opts) {
        if (_isSDKInitialized) {
          const clientOpts = opts || {}
          clientOpts.addon = addon
          return ZoomVideoSDKIncomingLiveStream.getInstance(clientOpts)
        }
        return null
      },
      getCmdHelper: function (opts) {
        if (_isSDKInitialized) {
          const clientOpts = opts || {}
          clientOpts.addon = addon
          return ZoomVideoSDKCmd.getInstance(clientOpts)
        }
        return null
      },
      getRecordingHelper: function (opts) {
        if (_isSDKInitialized) {
          const clientOpts = opts || {}
          clientOpts.addon = addon
          return ZoomVideoSDKRecording.getInstance(clientOpts)
        }
        return null
      },
      getRemoteCameraControlHelper: function (opts) {
        if (_isSDKInitialized) {
          const clientOpts = opts || {}
          clientOpts.addon = addon
          return ZoomVideoSDKRemoteCameraControl.getInstance(clientOpts)
        }
        return null
      },
      getCameraControlRequestHelper: function (opts) {
        if (_isSDKInitialized) {
          const clientOpts = opts || {}
          clientOpts.addon = addon
          return ZoomVideoSDKCameraControlRequestHandler.getInstance(clientOpts)
        }
        return null
      },
      getPhoneHelper: function (opts) {
        if (_isSDKInitialized) {
          const clientOpts = opts || {}
          clientOpts.addon = addon
          return ZoomVideoSDKPhone.getInstance(clientOpts)
        }
        return null
      },
      getLiveTranscriptionHelper: function (opts) {
        if (_isSDKInitialized) {
          const clientOpts = opts || {}
          clientOpts.addon = addon
          return ZoomVideoSDKLiveTranscription.getInstance(clientOpts)
        }
        return null
      },
      getShareSettingHelper: function (opts) {
        if (_isSDKInitialized) {
          const clientOpts = opts || {}
          clientOpts.addon = addon
          return ZoomVideoSDKShareSetting.getInstance(clientOpts)
        }
        return null
      },
      getRemoteControlHelper: function (opts) {
        if (_isSDKInitialized && platform != 'linux') {
          const clientOpts = opts || {}
          clientOpts.addon = addon
          return ZoomVideoSDKRemoteControl.getInstance(clientOpts)
        }
        return null
      }
    }
  }
  return {
    getInstance: (opts) => {
      if (!instance) {
        instance = init(opts)
      }
      return instance
    }
  }
})()
