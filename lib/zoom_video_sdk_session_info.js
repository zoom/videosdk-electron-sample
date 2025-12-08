import { ZoomVideoSDKErrors, ZoomVideoSDKUserInfoType } from './zoom_video_sdk_defines.js'
import messages from './electron_zoomvideosdk_pb.js'
import { getUserInfo } from './zoom_video_sdk_user_util.js'

export default (function () {
  var instance
  /**
    * Return the current session information.
    * @module zoom_video_sdk_session_info
    * @return {ZoomVideoSDKSessionInfo}
    */
  function init (opts) {
    const clientOpts = {...opts}
    // Private methods and variables
    if (!clientOpts.addon) {
      return null
    }
    const _addon = clientOpts.addon.GetSessionInfoCtrl()

    return {
      // Public methods and variables
      /**
       * Get the session name.
       * @method getSessionName
       * @return {String} If the function succeeds, the return value is session name. Otherwise returns null.
       */
      getSessionName: function () {
        if (_addon) {
          return _addon.GetSessionName()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get the session's password.
       * @method getSessionPassword
       * @return {String} If the function succeeds, the return value is session password. Otherwise returns null.
       */
      getSessionPassword: function () {
        if (_addon) {
          return _addon.GetSessionPassword()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get the host's name.
       * @method getSessionHostName
       * @return {String} If the function succeeds, the return value is session host name. Otherwise returns null.
       */
      getSessionHostName: function () {
        if (_addon) {
          return _addon.GetSessionHostName()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get the session's host user object.
       * @method getSessionHost
       * @return {Object} If the function succeeds, returns a user object with the following members:
       *   - {String} userid - Get the user's id
       *   - {String} username - Get the user's name
       *   - {String} customIdentity - Get the user's custom id
       *   - {String} userReference - Get the user's reference info
       *   - {String} emailAddress - The email address of the user
       *   - {Boolean} isHasVideoDevice - Get the user's video status
       *   - {Boolean} isVideoOn - Get the user's video status
       *   - {Number} audioType - Get the user's audio status
       *   - {Boolean} isAudioMuted - Get the user's audio status
       *   - {Boolean} isTalking - Get the user's audio status
       *   - {Number} shareStatus - Share status (0: None, 1: Start, 2: Pause, 3: Resume, 4: Stop)
       *   - {Boolean} isHost - Determine whether the user is the host
       *   - {Boolean} isManager - Determine whether the user is the manager(coHost)
       *   - {Boolean} isVideoSpotLighted - Determine whether the user is spotLighted
       *   - {Boolean} isIncomingLiveStreamUser - Determine whether the user is incoming live stream user
       *   - {Number} videoStatisticInfo_height - Get the user's video statistic information
       *   - {Number} videoStatisticInfo_width - Get the user's video statistic information
       *   - {Number} videoStatisticInfo_bpf - Get the user's video statistic information
       *   - {Number} videoStatisticInfo_fps - Get the user's video statistic information
       *   - {Number} shareStatisticInfo_height - Get the user's share statistic information
       *   - {Number} shareStatisticInfo_width - Get the user's share statistic information
       *   - {Number} shareStatisticInfo_bpf - Get the user's share statistic information
       *   - {Number} shareStatisticInfo_fps - Get the user's share statistic information
       *   Otherwise returns null.
       */
      getSessionHost: function () {
        if (_addon) {
          try {
            const message = new messages.VideoSDKUser.deserializeBinary(_addon.GetSessionHost())
            return getUserInfo(message)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get a list of the session's remote users.
       * @method getRemoteUsers
       * @param {Number} options The options for getting remote users.
       * @return {Array} If the function succeeds, returns an array of user objects with the following members:
       *   - {String} userid - Get the user's id
       *   - {String} username - Get the user's name
       *   - {String} customIdentity - Get the user's custom id
       *   - {String} userReference - Get the user's reference info
       *   - {String} emailAddress - The email address of the user
       *   - {Boolean} isHasVideoDevice - Get the user's video status
       *   - {Boolean} isVideoOn - Get the user's video status
       *   - {Number} audioType - Get the user's audio status
       *   - {Boolean} isAudioMuted - Get the user's audio status
       *   - {Boolean} isTalking - Get the user's audio status
       *   - {Number} shareStatus - Share status (0: None, 1: Start, 2: Pause, 3: Resume, 4: Stop)
       *   - {Boolean} isHost - Determine whether the user is the host
       *   - {Boolean} isManager - Determine whether the user is the manager(coHost)
       *   - {Boolean} isVideoSpotLighted - Determine whether the user is spotLighted
       *   - {Boolean} isIncomingLiveStreamUser - Determine whether the user is incoming live stream user
       *   - {Number} videoStatisticInfo_height - Get the user's video statistic information
       *   - {Number} videoStatisticInfo_width - Get the user's video statistic information
       *   - {Number} videoStatisticInfo_bpf - Get the user's video statistic information
       *   - {Number} videoStatisticInfo_fps - Get the user's video statistic information
       *   - {Number} shareStatisticInfo_height - Get the user's share statistic information
       *   - {Number} shareStatisticInfo_width - Get the user's share statistic information
       *   - {Number} shareStatisticInfo_bpf - Get the user's share statistic information
       *   - {Number} shareStatisticInfo_fps - Get the user's share statistic information
       *   Otherwise returns null.
       */
      getRemoteUsers: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          const options = Number(clientOpts.options) || ZoomVideoSDKUserInfoType.UserInfoType_ALL
          try {
            const GetRemoteUsersParams = new messages.GetRemoteUsersParams()
            GetRemoteUsersParams.setZnOptions(options)
            const bytes = GetRemoteUsersParams.serializeBinary()
            const message = messages.UserList.deserializeBinary(_addon.GetRemoteUsers(bytes))
            const tempList = message.getUserList()
            let userList = []
            for (let val of tempList) {
              let obj = getUserInfo(val)
              userList.push(obj)
            }
            return userList
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get the session's user object for myself.
       * @method getMyself
       * @return {Object} If the function succeeds, returns a user object with the following members:
       *   - {String} userid - Get the user's id
       *   - {String} username - Get the user's name
       *   - {String} customIdentity - Get the user's custom id
       *   - {String} userReference - Get the user's reference info
       *   - {String} emailAddress - The email address of the user
       *   - {Boolean} isHasVideoDevice - Get the user's video status
       *   - {Boolean} isVideoOn - Get the user's video status
       *   - {Number} audioType - Get the user's audio status
       *   - {Boolean} isAudioMuted - Get the user's audio status
       *   - {Boolean} isTalking - Get the user's audio status
       *   - {Number} shareStatus - Share status (0: None, 1: Start, 2: Pause, 3: Resume, 4: Stop)
       *   - {Boolean} isHost - Determine whether the user is the host
       *   - {Boolean} isManager - Determine whether the user is the manager(coHost)
       *   - {Boolean} isVideoSpotLighted - Determine whether the user is spotLighted
       *   - {Boolean} isIncomingLiveStreamUser - Determine whether the user is incoming live stream user
       *   - {Number} videoStatisticInfo_height - Get the user's video statistic information
       *   - {Number} videoStatisticInfo_width - Get the user's video statistic information
       *   - {Number} videoStatisticInfo_bpf - Get the user's video statistic information
       *   - {Number} videoStatisticInfo_fps - Get the user's video statistic information
       *   - {Number} shareStatisticInfo_height - Get the user's share statistic information
       *   - {Number} shareStatisticInfo_width - Get the user's share statistic information
       *   - {Number} shareStatisticInfo_bpf - Get the user's share statistic information
       *   - {Number} shareStatisticInfo_fps - Get the user's share statistic information
       *   Otherwise returns null.
       */
      getMyself: function () {
        if (_addon) {
          const message = new messages.VideoSDKUser.deserializeBinary(_addon.GetMyself())
          return getUserInfo(message)
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get session's audio statistic information.
       * @method getSessionAudioStatisticInfo
       * @return {Array} Array of audio statistic information objects containing:
       *   - frequency: The frequency in kilohertz (KHz)
       *   - latency: The audio latency in milliseconds (delay in network data transfer)
       *   - jitter: The audio jitter in milliseconds (change in latency)
       *   - packetLossAvg: The percentage of average audio packet loss
       *   - packetLossMax: The percentage of maximum audio packet loss
       */
      getSessionAudioStatisticInfo: function () {
        if (_addon) {
          const message = new messages.VideoSDKSessionAudioStatisticInfoList.deserializeBinary(_addon.GetSessionAudioStatisticInfo())
          const tempList = message.getAudiostatisticinfoList()
          let audiostatisticinfoList = []
          for (let val of tempList) {
            let obj = {
              frequency: val.getFrequency(),
              latency: val.getLatency(),
              jitter: val.getJitter(),
              packetLossAvg: val.getPacketlossavg(),
              packetLossMax: val.getPacketlossmax()
            }
            audiostatisticinfoList.push(obj)
          }
          return audiostatisticinfoList
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get session's video statistic information.
       * @method getSessionVideoStatisticInfo
       * @return {Array} Array of video statistic information objects containing:
       *   - frame_width: The frame width in pixels
       *   - frame_height: The frame height in pixels
       *   - fps: The frame rate in FPS (Frames Per Second)
       *   - latency: The video latency in milliseconds (delay in network data transfer)
       *   - jitter: The video jitter in milliseconds (change in latency)
       */
      getSessionVideoStatisticInfo: function () {
        if (_addon) {
          const message = new messages.VideoSDKSessionASVStatisticInfoList.deserializeBinary(_addon.GetSessionVideoStatisticInfo())
          const tempList = message.getAsvstatisticinfoList()
          let asvstatisticinfoList = []
          for (let val of tempList) {
            let obj = {
              frame_width: val.getFrameWidth(),
              frame_height: val.getFrameHeight(),
              fps: val.getFps(),
              latency: val.getLatency(),
              jitter: val.getJitter()
            }
            asvstatisticinfoList.push(obj)
          }
          return asvstatisticinfoList
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get session's share statistic information.
       * @method getSessionShareStatisticInfo
       * @return {Array} Array of share statistic information objects containing:
       *   - frame_width: The frame width in pixels
       *   - frame_height: The frame height in pixels
       *   - fps: The frame rate in FPS (Frames Per Second)
       *   - latency: The share latency in milliseconds (delay in network data transfer)
       *   - jitter: The share jitter in milliseconds (change in latency)
       */
      getSessionShareStatisticInfo: function () {
        if (_addon) {
          const message = new messages.VideoSDKSessionASVStatisticInfoList.deserializeBinary(_addon.GetSessionShareStatisticInfo())
          const tempList = message.getAsvstatisticinfoList()
          let asvstatisticinfoList = []
          for (let val of tempList) {
            let obj = {
              frame_width: val.getFrameWidth(),
              frame_height: val.getFrameHeight(),
              fps: val.getFps(),
              latency: val.getLatency(),
              jitter: val.getJitter()
            }
            asvstatisticinfoList.push(obj)
          }
          return asvstatisticinfoList
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get the session ID. This interface is only valid for the host.
       * @method getSessionID
       * @return {String} If the function succeeds, the return value is session ID. Otherwise returns null.
       * @note This interface is only valid for the host.
       */
      getSessionID: function () {
        if (_addon) {
          return _addon.GetSessionID()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      }
    }
  }

  return {
    getInstance: function (opts) {
      if (!instance) {
        instance = init(opts)
      }
      return instance
    }
  }
})()
