import { ZoomVideoSDKErrors, ZoomVideoSDKUserInfoType } from './zoom_video_sdk_defines.js'
import messages from './electron_zoomvideosdk_pb.js'
import { getUserInfo } from './zoom_video_sdk_user_util'

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
       * Get the session name
       * @method getSessionName
       * @return {String} If the function succeed, the return value is session name. Otherwise returns NULL.
       */
      getSessionName: function () {
        if (_addon) {
          return _addon.GetSessionName()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get Session Password
       * @method getSessionPassword
       * @return {String} sessionPwd
       */
      getSessionPassword: function () {
        if (_addon) {
          return _addon.GetSessionPassword()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get the session host name
       * @method getSessionHostName
       * @return {String} If the function succeed, the return value is session host name. Otherwise returns NULL.
       */
      getSessionHostName: function () {
        if (_addon) {
          return _addon.GetSessionHostName()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get the session host user object
       * @method getSessionHost
       * @return {Object} If the function succeed, the return value is session host user object. Otherwise returns NULL.
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
       * Get the session all users list
       * @method getRemoteUsers
       * @param {Number} options
       * @return {Array} If the function succeed, the return value is session all user list object(userid, username, customIdentity, userReference, emailAddress, isHasVideoDevice, isVideoOn, audioType, isAudioMuted, isTalking, shareStatus, isHost, isManager, isVideoSpotLighted, isIncomingLiveStreamUser, videoStatisticInfo_height, videoStatisticInfo_width, videoStatisticInfo_bpf, videoStatisticInfo_fps, shareStatisticInfo_height, shareStatisticInfo_width, shareStatisticInfo_bpf, shareStatisticInfo_fps). Otherwise returns NULL.
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
       * Get myself object
       * @method getMyself
       * @return {Object} If the function succeed, the return value is myself object. Otherwise returns NULL.
       */
      getMyself: function () {
        if (_addon) {
          const message = new messages.VideoSDKUser.deserializeBinary(_addon.GetMyself())
          return getUserInfo(message)
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get session audio statistic information
       * @method getSessionAudioStatisticInfo
       * @return {Array} send_info, recv_info
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
       * Get session video statistic information
       * @method getSessionVideoStatisticInfo
       * @return {Array} send_info, recv_info
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
       * Get session share statistic information
       * @method getSessionShareStatisticInfo
       * @return {Array} send_info, recv_info
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
       * Get the session ID, this interface is only valid for the host.
       * @method getSessionID
       * @return {String} return If the function succeeds, the return value is session ID. Otherwise returns NULL.
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
