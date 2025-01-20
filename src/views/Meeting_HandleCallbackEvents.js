import messages from '../../lib/electron_zoomvideosdk_pb.js'
import { getUserInfo } from '../../lib/zoom_video_sdk_user_util'
import { ZoomVideoSDKShareStatus, ZoomVideoSDKErrors, ZoomVideoSDKCallback, ZoomVideoSDKRawDataStatus, ZoomVideoSDKResolution, ZoomVideoSDKCameraControlRequestType } from '../../lib/zoom_video_sdk_defines'
import UserInfo from '../assets/js/UserInfo.js'
import { findKey } from '../assets/js/util'
import { CmdTypes, FeedbackTypes } from '../assets/js/cmd_defines'
const { ipcRenderer } = window.require('electron')
const remote = window.require('@electron/remote')
const zoomVideoSdk = remote.app.zoomVideoSdk

export const Meeting_HandleCallbackEvents = {
  methods: {
    onSessionJoin() {
      if (this.isInSession) {
        this.clearUserList()
      }
      this.isInSession = true
      let isHost = this.zoomVideoSDKSessionInfo.getMyself().isHost
      this.$set(this.myselfInfo, 'isHost', isHost)
    },
    onSessionLeave(data) {
      const eReason = data.getEreason()
      console.log('onSessionLeave', eReason)
      this.$store.commit('setReactionMap', {})
      this.$store.commit('setRaisedHandMap', {})
      this.$store.commit('setLowerThirdMap', {})
      this.$store.commit('setStartFeedback', false)
      this.$store.commit('setFeedbackSubmitMap', {})
      let routeName = this.$route.name
      if (routeName == 'create' || routeName == 'error') {
        return
      }
      this.$router.push('/')
    },
    onError(data) {
      let errorCode = data.getErrorcode()
      console.log('onError', errorCode)
      if (errorCode === ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter) {
        this.sessionNameErrorMsg = 'Incorrect session name. Please choose another name.'
        return
      }
      if (this.$route.name == 'meeting') {
        this.stopShare()
        if (errorCode === ZoomVideoSDKErrors.ZoomVideoSDKErrors_Session_Reconncting || errorCode === ZoomVideoSDKErrors.ZoomVideoSDKErrors_Session_Disconncting) {
          this.clearUserList()
          this.initMeeting()
          this.isInSession = false
          this.isParticipantsVideoShown = false
          return
        }
      }
      this.$router.push({ path: '/error', query: { type: this.$route.query.type, errorCode: errorCode } })
    },
    onUserJoin(userList) {
      let need_sub_list = []
      let participantsVideoUserListLength = this.participantsVideoUserList.filter(item => item).length
      let needSubNewUserCount = participantsVideoUserListLength < this.currentParticipantsVideoCount ? (this.currentParticipantsVideoCount - participantsVideoUserListLength) : 0
      for (let val of userList) {
        let userInfo = getUserInfo(val)
        let userColor = userInfo.pUser == this.myselfInfo.pUser ? this.myselfInfo.color : this.generateUserColor()
        let newUser = new UserInfo(userInfo, userColor)
        this.allUserList.push(newUser)
        if (this.isParticipantsVideoShown && needSubNewUserCount > 0) {
          need_sub_list.push(newUser)
          --needSubNewUserCount
        }
      }
      for (let index = 0; index < need_sub_list.length; index++) {
        let subscribeObj = {
          user: need_sub_list[index].user,
          recv_handle: participantsVideoUserListLength + index,
          resolution: ZoomVideoSDKResolution.ZoomVideoSDKResolution_90P,
          dataType: 0
        }
        this.zoomVideoSDKUser.subscribe(subscribeObj)
        this.$set(this.participantsVideoHandleMap, subscribeObj.user.pUser, subscribeObj.recv_handle)
        this.$set(this.participantsVideoUserList, subscribeObj.recv_handle, need_sub_list[index])
      }
      if (need_sub_list.length > 0) {
        this.updateMeetingViewPorts()
      }
      let allUserListLength = this.allUserList.filter(item => item).length
      this.totalPageCount = Math.floor(allUserListLength / this.currentParticipantsVideoCount) + (allUserListLength % this.currentParticipantsVideoCount > 0 ? 1 : 0)
      this.$set(this.toolbarStatus, 'liveOnNum', allUserListLength)
      ipcRenderer.send('setToolbarStatus', this.toolbarStatus)
    },
    onUserLeave(userList) {
      const MAGIC_MAX_RECV_HANDLE_INDEX = 0xEFFFFFFF
      let min_changed_recv_handle_index = MAGIC_MAX_RECV_HANDLE_INDEX
      let is_main_video_left = false
      for (let index = 0; index < userList.length; index++) {
        let userInfo = getUserInfo(userList[index])
        let currentIndex = this.allUserList.findIndex(val => val && val.user.pUser == userInfo.pUser)
        let recv_handle = this.participantsVideoHandleMap[userInfo.pUser]
        if (userInfo.pUser === this.mainVideoUser.user.pUser) {
          is_main_video_left = true
        }
        if (recv_handle < min_changed_recv_handle_index) {
          min_changed_recv_handle_index = recv_handle
        }
        this.allUserList.splice(currentIndex, 1)
        if (this.remoteControl.controlledParticipant.pUser && userInfo.pUser == this.remoteControl.controlledParticipant.pUser) {
          this.$set(this.remoteControl, 'controlledParticipant', {})
          this.$set(this.remoteControl, 'isMeetingRemoteControlLayerShown', false)  
        }
        if (this.remoteControl.requestControlUser.pUser && userInfo.pUser == this.remoteControl.requestControlUser.pUser) {
          this.$set(this.remoteControl, 'requestControlUser', {})
          this.$set(this.remoteControl, 'isCameraControlled', false)
          this.$set(this.remoteControl, 'isRequestCameraControlLayerShown', false)
        }
      }
      let allUserList = [...this.allUserList.filter(item => item)]

      /* if main video left, we slect the first user in user list.
        if you want to change this design, please change this logic
      */
      if (is_main_video_left) {
        let unSubscribeObj = {
          user: this.mainVideoUser.user,
          recv_handle: this.mainVideoRecvHandle,
          dataType: this.mainVideo.dataType
        }
        this.zoomVideoSDKUser.unSubscribe(unSubscribeObj)
        this.subscribeMainVideo(this.allUserList[0])
      }

      /* select new user for plist video */
      if (this.isParticipantsVideoShown) {
        if (MAGIC_MAX_RECV_HANDLE_INDEX != min_changed_recv_handle_index) {
          /* remove user for plist video */
          let recv_handle_index = min_changed_recv_handle_index
          let need_unsub_list = this.participantsVideoUserList.filter(item => item).splice(recv_handle_index)
          for (let index = 0; index < need_unsub_list.length; index++) {
            let pUser = need_unsub_list[index].user.pUser
            let recv_handle = this.participantsVideoHandleMap[pUser]
            let unSubscribeObj = {
              user: need_unsub_list[index].user,
              recv_handle: recv_handle,
              dataType: this.participantsVideo[recv_handle].dataType
            }
            this.zoomVideoSDKUser.unSubscribe(unSubscribeObj)
            this.participantsVideo[recv_handle].setDrawVideoStatus(false)
            delete this.participantsVideoHandleMap[unSubscribeObj.user.pUser]
            this.$set(this.participantsVideoUserList, recv_handle_index++, null)
          }

          /* add new user for plist video */
          let need_sub_list = allUserList.splice(this.currentParticipantsVideoCount * this.currentPageIndex + min_changed_recv_handle_index,
            this.currentParticipantsVideoCount - min_changed_recv_handle_index)
          if (need_sub_list.length == 0 && min_changed_recv_handle_index == 0 && this.currentPageIndex > 0) { 
            need_sub_list = allUserList.splice(this.currentParticipantsVideoCount * (this.currentPageIndex - 1), this.currentParticipantsVideoCount)
          }

          /* subscribe new users */
          for (let index = 0; index < need_sub_list.length; index++) {
            let subscribeObj = {
              user: need_sub_list[index].user,
              recv_handle: min_changed_recv_handle_index + index,
              resolution: ZoomVideoSDKResolution.ZoomVideoSDKResolution_90P,
              dataType: 0
            }
            this.zoomVideoSDKUser.subscribe(subscribeObj)
            this.$set(this.participantsVideoHandleMap, subscribeObj.user.pUser, subscribeObj.recv_handle)
            this.$set(this.participantsVideoUserList, subscribeObj.recv_handle, need_sub_list[index])
          }
          if (need_unsub_list.length > 0) {
            this.updateMeetingViewPorts()
          }
          let first_user_in_current_page = this.participantsVideoUserList[0]
          let currentIndex = this.allUserList.findIndex(val => val && val.user.pUser == first_user_in_current_page.user.pUser)
          this.currentPageIndex = Math.floor(currentIndex / this.currentParticipantsVideoCount) + (currentIndex % this.currentParticipantsVideoCount > 0 ? 1 : 0)
          this.totalPageCount = Math.floor(this.allUserList.length / this.currentParticipantsVideoCount) + (this.allUserList.length % this.currentParticipantsVideoCount > 0 ? 1 : 0)
        }
      }
      this.$set(this.toolbarStatus, 'liveOnNum', this.allUserList.length)
      ipcRenderer.send('setToolbarStatus', this.toolbarStatus)
    },
    onUserVideoStatusChanged(videoList) {
      this.cameraList = this.zoomVideoSDKVideo.getCameraList()
      if (this.cameraList.length === 0) {
        this.isVideoMute = true
      }
      for (let video of videoList) {
        const userInfo = getUserInfo(video)
        const myPUser = this.myselfInfo.pUser
        if (userInfo.pUser === myPUser) {
          this.isVideoMute = !userInfo.isVideoOn
          this.$set(this.toolbarStatus, 'isVideoMute', !userInfo.isVideoOn)
          ipcRenderer.send('setToolbarStatus', this.toolbarStatus)
        }
        if (userInfo.pUser === myPUser && userInfo.isVideoOn) {
          this.subscribeMainVideo(this.mainVideoUser)
        }
      }
      this.$EventBus.$emit('statistics')
    },
    onUserAudioStatusChanged(audioList) {
      this.micList = this.zoomVideoSDKAudio.getMicList()
      if (this.micList.length === 0) {
        this.isAudioMute = true
      }
      for (let audio of audioList) {
        const userInfo = getUserInfo(audio)
        const myPUser = this.myselfInfo.pUser
        if (userInfo.pUser === myPUser) {
          this.isAudioMute = userInfo.isAudioMuted
          this.$set(this.toolbarStatus, 'isAudioMute', userInfo.isAudioMuted)
          ipcRenderer.send('setToolbarStatus', this.toolbarStatus)
          if (this.isAudioMute) {
            this.notificationContent = 'You are muted now'
          } else {
            this.notificationContent = 'You are unmuted now'
          }
        }
        this.updateUserInfo('Audio', userInfo.isAudioMuted, userInfo.pUser)
      }
    },
    onUserShareStatusChanged(data) {
      let userInfo = getUserInfo(data.getUser())
      let shareStatus = data.getShareaction().getSharestatus()
      let type = data.getShareaction().getSharetype()
      const myPUser = this.myselfInfo.pUser
      switch (shareStatus) {
        case ZoomVideoSDKShareStatus.ZoomVideoSDKShareStatus_Start: case ZoomVideoSDKShareStatus.ZoomVideoSDKShareStatus_Resume:
          if (userInfo.pUser === myPUser) {
            this.$set(this.myselfInfo, 'ShareStatus', 1)
            ipcRenderer.send('share')
            if (!this.shareSecondCamera.isSharingSecondCamera) {
              setTimeout(() => {
                ipcRenderer.send('min')
              }, 500)
            }
          }
          if (userInfo && userInfo.username) {
            this.notificationContent = `${userInfo.username} is Sharing`
            this.activeSharingUserName = userInfo.username
          }
          this.$set(this.shareSecondCamera, 'isSwitchShareCamera', false)
          break;
        case ZoomVideoSDKShareStatus.ZoomVideoSDKShareStatus_Stop:
          if (this.shareSecondCamera.isSwitchShareCamera) {
            return
          }
          if (userInfo && userInfo.username) {
            this.notificationContent = `${userInfo.username} sharing stopped`
          }
          if (userInfo.pUser === myPUser) {
            this.$set(this.myselfInfo, 'ShareStatus', 0)
            ipcRenderer.send('stop-share')
          }
          if (this.shareSecondCamera.isSharingSecondCamera) {
            this.subscribeMainVideo(this.mainVideoUser)
            this.$set(this.shareSecondCamera, 'isSharingSecondCamera', false)
          }
          break;
        }
      this.updateUserInfo('Share', shareStatus, userInfo.pUser)
      if (!this.shareSecondCamera.isSharingSecondCamera && userInfo.pUser === this.mainVideoUser.user.pUser) {
        this.mainVideoUser.setShareStatus(shareStatus)
        this.subscribeMainVideo(this.mainVideoUser)
      }
      this.$EventBus.$emit('statistics')
    },
    onFailedToStartShare(data) {
      const userInfo = getUserInfo(data.getUser())
      console.log('onFailedToStartShare', userInfo)
    },
    onRawDataStatusChanged(data) {
      let recv_handle = data.getRecvHandle()
      let status = data.getStatus()
      console.log(recv_handle, status)
      if (this.$route.name == 'meeting') {
        if (recv_handle == this.mainVideoRecvHandle) {
          this.mainVideo.setDrawVideoStatus(status == 0)
        } else {
          this.participantsVideo[recv_handle].setDrawVideoStatus(status == 0)
          if (this.participantsVideoUserList[recv_handle]) {
            this.updateUserInfo('Video', status == 0, this.participantsVideoUserList[recv_handle].user.pUser)
          }
        }
        if (status == ZoomVideoSDKRawDataStatus.RawData_Off) {
          window.requestAnimationFrame(this.drawMeetingVideo)
        }
      }
    },
    onSessionNeedPassword() {
      this.$router.push({ path: '/create', query: { type: 'Join', needPassword: true } })
    },
    onSessionPasswordWrong() {
      this.$router.push({ path: '/create', query: { type: 'Join', passwordWrong: true } })
    },
    onCommandReceived(data) {
      let sender = getUserInfo(data.getPsender())
      let strCmd = data.getStrcmd()
      let cmdList = strCmd.split('|')
      let cmdType = findKey(CmdTypes, cmdList.shift())
      let pUser = sender.pUser
      console.log(sender, strCmd, cmdType)
      switch (cmdType) {
        case 'cmd_reaction':
          let reaction = cmdList[0]
          if (reaction == 'raisehand') {
            let reactionObj = this.$store.state.cmdReactionMap
            if (reactionObj[pUser]) {
              let newReaction = {
                [pUser]: null
              }
              let newReactionObj = {...this.$store.state.cmdReactionMap, ...newReaction}
              this.$store.commit('setReactionMap', newReactionObj)
            }
            let handStatus = {
              [pUser]: reaction
            }
            let newRaisedHandObj = {...this.$store.state.cmdRaisedHandMap, ...handStatus}
            this.$store.commit('setRaisedHandMap', newRaisedHandObj)
          } else if (reaction == 'lowerhand') {
            let handStatus = {
              [pUser]: null
            }
            let newRaisedHandObj = {...this.$store.state.cmdRaisedHandMap, ...handStatus}
            this.$store.commit('setRaisedHandMap', newRaisedHandObj)
          } else {
            clearTimeout(this.reactionTimer)
            let newReaction = {
              [pUser]: reaction
            }
            let newReactionObj = {...this.$store.state.cmdReactionMap, ...newReaction}
            this.$store.commit('setReactionMap', newReactionObj)
            this.reactionTimer = setTimeout(() => {
              let newReaction = {
                [pUser]: null
              }
              newReactionObj = {...this.$store.state.cmdReactionMap, ...newReaction}
              this.$store.commit('setReactionMap', newReactionObj)
            }, 5000)
          }
          break
        case 'cmd_feedback_push':
          this.$store.commit('setStartFeedback', true)
          break
        case 'cmd_feedback_submit':
          let newSubmit = {
            [pUser]: FeedbackTypes[cmdList[0]]
          }
          let feedbackSubmitObj = {...this.$store.state.cmdFeedbackSubmitMap, ...newSubmit}
          this.$store.commit('setFeedbackSubmitMap', feedbackSubmitObj)
          break
        case 'cmd_lowerthird':
          let newLowerthird = {
            [pUser]: cmdList
          }
          let lowerThirdObj = {...this.$store.state.cmdLowerThirdMap, ...newLowerthird}
          this.$store.commit('setLowerThirdMap', lowerThirdObj)
          break
      }
    },
    onCommandChannelConnectResult (data) {
      let isCmdSuccess = data.getIssuccess()
      console.log('isCmdSuccess', isCmdSuccess)
    },
    onHostAskUnmute (data) {
      this.notificationContent = 'The host would like you to unmute'
    },
    onCameraControlRequestReceived(data) {
      let userInfo = getUserInfo(data.getPuser())
      let requestType = data.getRequesttype()
      if (requestType == ZoomVideoSDKCameraControlRequestType.ZoomVideoSDKCameraControlRequestType_RequestControl) {
        this.$set(this.remoteControl, 'requestControlUser', userInfo)
        this.$set(this.remoteControl, 'isRequestCameraControlLayerShown', true)
      } else if (requestType == ZoomVideoSDKCameraControlRequestType.ZoomVideoSDKCameraControlRequestType_GiveUpControl) {
        this.$set(this.remoteControl, 'requestControlUser', {})
        this.$set(this.remoteControl, 'isCameraControlled', false)
        this.notificationContent = `${userInfo.username} stopped controlling your camera`
      }
    },
    onCameraControlRequestResult(data) {
      let userInfo = getUserInfo(data.getPuser())
      let isApproved = data.getIsapproved()
      this.isRequestingCameraControl = false
      if (isApproved) {
        this.$set(this.remoteControl, 'controlledParticipant', userInfo)
        this.notificationContent = `You can now control ${userInfo.username}'s camera`
        this.$set(this.remoteControl, 'isMeetingRemoteControlLayerShown', true)
      } else {
        this.$set(this.remoteControl, 'controlledParticipant', {})
        this.notificationContent = `${userInfo.username} declined your request`
        this.$set(this.remoteControl, 'isMeetingRemoteControlLayerShown', false)
      }
    },
    onNodeAddonCallbacks(result) {
      let message = messages.CallbackBody.deserializeBinary(result)
      let callback = findKey(ZoomVideoSDKCallback, message.getMsgtype())
      console.log('callback', callback)
      switch (callback) {
        case 'onSessionJoin':
          this.onSessionJoin()
          break;
        case 'onSessionLeave':
          this.onSessionLeave(message.getOnsessionleaveparam())
          break;
        case 'onError':
          this.onError(message.getOnerrorparam())
          break;
        case 'onUserJoin':
          this.onUserJoin(message.getOnuserjoinparam().getZnUserlist().getUserList())
          break;
        case 'onUserLeave':
          this.onUserLeave(message.getOnuserleaveparam().getZnUserlist().getUserList())
          break;
        case 'onUserVideoStatusChanged':
          this.onUserVideoStatusChanged(message.getOnuservideostatuschangedparam().getZnUserlist().getUserList())
          break;
        case 'onUserAudioStatusChanged':
          this.onUserAudioStatusChanged(message.getOnuseraudiostatuschangedparam().getZnUserlist().getUserList())
          break;
        case 'onUserShareStatusChanged':
          this.onUserShareStatusChanged(message.getOnusersharestatuschangedparam())
          break;
        case 'onFailedToStartShare':
          this.onFailedToStartShare(message.getOnfailedtostartshareparam())
          break;
        case 'onChatNewMessageNotify':
          this.$refs.chat.onChatNewMessageNotify(message.getOnchatnewmessagenotifyparam())
          break;
        case 'onSessionNeedPassword':
          this.onSessionNeedPassword()
          break;
        case 'onSessionPasswordWrong':
          this.onSessionPasswordWrong()
          break;
        case 'onRawDataStatusChanged':
          this.onRawDataStatusChanged(message.getOnrawdatastatuschangedparam())
          break;
        case 'onCommandReceived':
          this.onCommandReceived(message.getOncommandreceivedparam())
          break;
        case 'onCommandChannelConnectResult':
          this.onCommandChannelConnectResult(message.getOncommandchannelconnectresultparam())
          break;
        case 'onHostAskUnmute':
          this.onHostAskUnmute(message.getOnhostaskunmuteparam())
          break;
        case 'onCameraControlRequestReceived':
          this.onCameraControlRequestReceived(message.getOncameracontrolrequestreceivedparam())
          break;
        case 'onCameraControlRequestResult':
          this.onCameraControlRequestResult(message.getOncameracontrolrequestresultparam())
          break;
      }
    }
  },
  created() {
    zoomVideoSdk.setNodeAddonCallbacks(this.onNodeAddonCallbacks)
  }
}