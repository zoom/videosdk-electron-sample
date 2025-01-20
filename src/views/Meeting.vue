<template>
  <div class="meeting">
    <canvas width="1920" height="1080" id="canvas"></canvas>
    <div :class="['meeting-wrap', isParticipantsVideoShown?'meeting-min':'meeting-max']">
      <MeetingHeader class="meeting-header" :isParticipantsVideoShown="isParticipantsVideoShown" :isInSession="isInSession" :liveOnNum="toolbarStatus.liveOnNum" />
      <div class="connecting-content" v-if="!isInSession">
        Connecting…
      </div>
      <div class="main-window">
        <section class="meeting-render">
          <div class="meeting-name" :style="{'color': mainVideoUser.color}" v-if="!mainVideo.isDrawVideo && mainVideoUser">
            {{mainVideoUser.avatarName}}
          </div>
        </section>
        <MeetingSwitchCamera :sharingCameraID="shareSecondCamera.sharingCameraID" @updateSecondCameraStatus="handleSecondCameraStatus"
         :isCameraControlled="remoteControl.isCameraControlled" v-if="shareSecondCamera.isSharingSecondCamera" />
        <MeetingCameraControlled :requestControlUser="remoteControl.requestControlUser" v-if="remoteControl.isCameraControlled" />
        <LayerNotification :notificationContent="notificationContent" v-if="isNotificationLayerShown" />
        <MeetingLowerThirds v-if="isLowerThird && mainVideoUser.user && lowerThirdMap[mainVideoUser.user.pUser]" :userLowerThirdMap="lowerThirdMap[mainVideoUser.user.pUser]"
          :isCameraControlled="remoteControl.isCameraControlled" :isSharingSecondCamera="shareSecondCamera.isSharingSecondCamera" />
        <span :class="['emoji', {'emoji-position': isLowerThird && mainVideoUser.user && lowerThirdMap[mainVideoUser.user.pUser]}]" v-if="mainVideoUser.user">
          <img :src="require(`../assets/images/raisehand.png`)" v-if="raisedHandMap[mainVideoUser.user.pUser] && !reactionMap[mainVideoUser.user.pUser]" />
          <img :src="require(`../assets/images/${reactionMap[mainVideoUser.user.pUser]}.png`)" v-if="reactionMap[mainVideoUser.user.pUser]" />
        </span>
        <MeetingChat ref="chat" :isFocusWindow="isFocusWindow" :isChatShown="isChatShown" :allUserList="allUserList" @updateInputStatus="handleInputStatus" :myselfInfo="myselfInfo" v-show="isInSession" />
        <MeetingControl @control="toggleParticipantsVideo" :isFocusWindow="isFocusWindow" :isAudioMute="isAudioMute" :isVideoMute="isVideoMute" :cameraList="cameraList"
          :micList="micList" :ShareStatus="myselfInfo.ShareStatus" :activeSharingUserName="activeSharingUserName" :parent="this" :liveOnNum="toolbarStatus.liveOnNum" :myselfInfo="myselfInfo"
          @updateNotification="handleNotification"  @updateStatisticStatus="handleStatisticStatus" @updateSecondCameraStatus="handleSecondCameraStatus" v-show="isInSession && isFocusWindow" />
        <LayerMeetingRemoteControl :controlledParticipant="remoteControl.controlledParticipant" @updateRemoteControlStatus="handleRemoteControlStatus" v-if="remoteControl.isMeetingRemoteControlLayerShown" />
      </div>
    </div>
    <section class="video-list" v-if="isParticipantsVideoShown">
      <div class="video-list-background"></div>
      <div class="video-page" @click="handleParticipantsPageChange(currentPageIndex - 1)" v-if="currentPageIndex > 0">
        <i class="el-icon-arrow-up"></i>
      </div>
      <ul>
        <template v-for="(item, index) in participantsVideoUserList">
          <li :key="index" v-if="item" :id='`texture${index}`' :class="{'video-active': mainVideoUser.user.pUser == item.user.pUser}"
           @click="subscribeMainVideo(item)" @mouseenter="handleOverParticipant(item)" @mouseleave="handleOutParticipant(item)">
            <div class="video-name" :style="{'color': item.color}" v-if="!item.isVideoOn">
              {{item.avatarName}}
            </div>
            <span class="emoji">
              <img :src="require(`../assets/images/raisehand.png`)" v-if="raisedHandMap[item.user.pUser] && !reactionMap[item.user.pUser]" />
              <img :src="require(`../assets/images/${reactionMap[item.user.pUser]}.png`)" v-if="reactionMap[item.user.pUser]" />
            </span>
            <MeetingParticipantsMore :participant="item" :controlledParticipant="remoteControl.controlledParticipant" @changeRemoteControlShown="handleRemoteControl" v-if="myselfInfo&&item.user.pUser!=myselfInfo.pUser" />
            <template v-if="isLowerThird && lowerThirdMap[item.user.pUser]">
              <span class="video-tag name-tag lower-third lower-third-hoverd" :style="{'background': lowerThirdMap[item.user.pUser][2]}" v-if="item.isHoverd">
                <div class="lower-third-user text-overflow">{{lowerThirdMap[item.user.pUser][0]}}</div>
                <div class="lower-third-title text-overflow">{{lowerThirdMap[item.user.pUser][1]}}</div>
                <div class="lower-third-mute lower-third-mute-hover" v-if="item.isAudioMuted"><IconMeetingParticipantsMuteAudio class="icon-muted" /></div>
              </span>
              <span class="video-tag name-tag lower-third lower-third-oneline" :style="{'background': lowerThirdMap[item.user.pUser][2]}" v-else>
                <span class="lower-third-mute" v-if="item.isAudioMuted"><IconMeetingParticipantsMuteAudio class="icon-muted" /></span>
                <span class="user-desc" v-if="lowerThirdMap[item.user.pUser][1]">
                  <span class="text-overflow">{{lowerThirdMap[item.user.pUser][0]}}</span> <span class="text-overflow">|</span> <span class="text-overflow">{{lowerThirdMap[item.user.pUser][1]}}</span>
                </span> 
                <span class="user-name text-overflow" v-else>{{lowerThirdMap[item.user.pUser][0]}}</span>
              </span>
            </template>
            <span class="video-tag name-tag text-overflow" v-else>
              <IconMeetingParticipantsMuteAudio class="icon-muted" v-if="item.isAudioMuted" />
              {{item.user.username}} {{item.statusText}}
            </span>
          </li>
        </template>
      </ul>
      <div class="video-page" @click="handleParticipantsPageChange(currentPageIndex + 1)" v-if="currentPageIndex + 1 < totalPageCount">
        <i class="el-icon-arrow-down"></i>
      </div>
    </section>
    <div class="statistic-layer" v-if="isStatisticLayerShown">
      <LayerStatistic @updateStatisticStatus="handleStatisticStatus" />
    </div>
    <LayerRequestCameraControl :requestControlUser="remoteControl.requestControlUser" @updateRemoteControlStatus="handleRemoteControlStatus" v-if="remoteControl.isRequestCameraControlLayerShown" />
    <LayerStopCameraControl :controlledParticipant="remoteControl.controlledParticipant" @updateRemoteControlStatus="handleRemoteControlStatus" @updateNotification="handleNotification" v-if="remoteControl.isStopCameraControlLayerShown" />
  </div>
</template>

<script>
import MeetingHeader from '../components/MeetingHeader'
import MeetingChat from '../components/MeetingChat'
import MeetingControl from '../components/MeetingControl'
import LayerStatistic from '../components/LayerStatistic'
import LayerMeetingRemoteControl from '../components/LayerMeetingRemoteControl'
import MeetingLowerThirds from '../components/MeetingLowerThirds'
import IconMeetingParticipantsMuteAudio from '../components/Icon/IconMeetingParticipantsMuteAudio'
import MeetingSwitchCamera from '../components/MeetingSwitchCamera'
import MeetingCameraControlled from '../components/MeetingCameraControlled'
import MeetingParticipantsMore from '../components/MeetingParticipantsMore'
import LayerNotification from '../components/LayerNotification'
import LayerRequestCameraControl from '../components/LayerRequestCameraControl'
import LayerStopCameraControl from '../components/LayerStopCameraControl'
import { debounce, getAvatarName } from '../assets/js/util'
import { ZoomVideoSDKResolution, ZoomVideoSDKRawDataType, ZoomVideoSDKErrors } from '../../lib/zoom_video_sdk_defines'
import { setUserInfo } from '../../lib/zoom_video_sdk_user_util'
import RenderItem from '../assets/js/RenderItem.js'
import UserInfo from '../assets/js/UserInfo.js'
import { Meeting_HandleCallbackEvents } from './Meeting_HandleCallbackEvents.js'
const { ipcRenderer } = window.require('electron')
const remote = window.require('@electron/remote')
const zoomVideoSdk = remote.app.zoomVideoSdk

export default {
  mixins: [Meeting_HandleCallbackEvents],
  data () {
    return {
      renderAddon: this.$store.state.renderAddon,
      zoomVideoSDKShare: zoomVideoSdk.getShareHelper(),
      zoomVideoSDKSessionInfo: zoomVideoSdk.getSessionInfo(),
      zoomVideoSDKVideo: zoomVideoSdk.getVideoHelper(),
      zoomVideoSDKAudio: zoomVideoSdk.getAudioHelper(),
      zoomVideoSDKUser: zoomVideoSdk.getUserHelper(),
      toolbarStatus: this.$store.state.toolbarStatus,
      isVideoMute: this.$store.state.toolbarStatus.isVideoMute,
      isAudioMute: this.$store.state.toolbarStatus.isAudioMute,
      myselfInfo: {},
      canvas: '',
      mainVideo: {},
      mainVideoUser: {},
      mainVideoRecvHandle: 0xFFFFFF,
      participantsVideo: [],
      participantsVideoHandleMap: {},
      participantsVideoUserList: [],
      allUserList: [],
      participantsStyle: {
        participantsLeftOffset: 1,
        participantsTopOffset: 0.5,
        participantsWidth: 160,
        participantsHeight: 90,
        participantsContentHeight: 96
      },
      timer: null,
      cameraList: [],
      micList: [],
      maxParticipantsVideoCount: 6,
      currentParticipantsVideoCount: 0,
      currentPageIndex: 0,
      totalPageCount: 0,
      activeSharingUserName: '',
      isInputing: false,
      isFocusWindow: true,
      isParticipantsVideoShown: false,
      isStatisticLayerShown: false,
      isChatShown: false,
      isInSession: false,
      redrawMsgFired: false,
      isMinimize: false,
      notificationTimer: null,
      isNotificationLayerShown: false,
      notificationContent: '',
      remoteControl: {
        isMeetingRemoteControlLayerShown: false,
        isRequestCameraControlLayerShown: false,
        isCameraControlled: false,
        isStopCameraControlLayerShown: false,
        isRequestingCameraControl: false,
        requestingNotificationContent: '',
        requestControlUser: {},
        controlledParticipant: {}
      },
      shareSecondCamera: {
        isSharingSecondCamera: false,
        isSwitchShareCamera: false,
        sharingCameraID: undefined
      },
    }
  },
  watch: {
    notificationContent(val, oldVal) {
      if (val) {
        this.isNotificationLayerShown = false
        this.$nextTick(() => {
          clearTimeout(this.notificationTimer)
          this.isNotificationLayerShown = true
          this.notificationTimer = setTimeout(() => {
            if (this.isRequestingCameraControl) {
              this.notificationContent = this.requestingNotificationContent
            } else {
              this.notificationContent = ''
              this.isNotificationLayerShown = false
            }
          }, 5000)
        })
      }
    }
  },
  computed: {
    isFillScreen () {
      return this.$store.state.isFillScreen
    },
    isLowerThird () {
      return this.$store.state.isLowerThird
    },
    raisedHandMap () {
      this.updateMeetingViewPorts()
      return this.$store.state.cmdRaisedHandMap
    },
    reactionMap () {
      this.updateMeetingViewPorts()
      return this.$store.state.cmdReactionMap
    },
    lowerThirdMap () {
      this.updateMeetingViewPorts()
      return this.$store.state.cmdLowerThirdMap
    }
  },
  methods: {
    focusFloatWindow (e) {
      if (e && e.type && e.type === 'input') {
        this.isInputing = true
      }
      clearTimeout(this.timer)
      this.isFocusWindow = true 
      if (this.isInputing) {
        return
      }
      this.timer = setTimeout(() => {
        this.isFocusWindow = false
      }, 5000)
    },
    resizeMeetingWindow () {
      console.log('resizeMeetingWindow')
      const clientWidth = document.body.clientWidth
      const clientHeight = document.body.clientHeight
      this.canvas.style.maxHeight = window.screen.availHeight === clientHeight ? '100%' : null
      const participantsMargin = 30
      const participantsHeight = clientHeight - participantsMargin
      const tempParticipantsVideoCount = Math.floor(participantsHeight / this.participantsStyle.participantsContentHeight)
      let newParticipantsVideoCount = tempParticipantsVideoCount >= this.maxParticipantsVideoCount
        ? this.maxParticipantsVideoCount 
        : tempParticipantsVideoCount

      /* if clientWidth lower than 920, hide chat module */
      if (this.isParticipantsVideoShown && clientWidth <= 920) {
        this.isChatShown = false
      } else {
        this.isChatShown = true
      }

      /* change main video resolution */
      let mainResolution
      if (clientHeight >= 1080) {
        mainResolution = ZoomVideoSDKResolution.ZoomVideoSDKResolution_1080P
      } else if (clientHeight >= 720 && clientHeight < 1080) {
        mainResolution = ZoomVideoSDKResolution.ZoomVideoSDKResolution_720P
      } else if (clientHeight >= 360 && clientHeight < 720) {
        mainResolution = ZoomVideoSDKResolution.ZoomVideoSDKResolution_360P
      } else if (clientHeight >= 180 && clientHeight < 360) {
        mainResolution = ZoomVideoSDKResolution.ZoomVideoSDKResolution_180P
      } else {
        mainResolution = ZoomVideoSDKResolution.ZoomVideoSDKResolution_90P
      }
      if (this.mainVideo.isDrawVideo && this.mainVideo.resolution !== mainResolution) {
        let subscribeObj = {
          user: this.mainVideoUser.user,
          recv_handle: this.mainVideoRecvHandle,
          resolution: mainResolution,
          dataType: this.mainVideo.dataType    
        }
        let ret = this.zoomVideoSDKUser.subscribe(subscribeObj)
        console.log('mainVideoResolution:subscribe', ret, subscribeObj)
        this.mainVideo.setResolution(mainResolution)
      }
      let allUserList = [...this.allUserList.filter(item => item)]
      this.totalPageCount = Math.floor(allUserList.length / newParticipantsVideoCount) + (allUserList.length % newParticipantsVideoCount > 0 ? 1 : 0)
      this.currentParticipantsVideoCount = newParticipantsVideoCount
      if (this.isParticipantsVideoShown) {
        let participantsVideoUserList = [...this.participantsVideoUserList.filter(item => item)]
        let mainUserIndex = participantsVideoUserList.findIndex(val => val && val.user.pUser == this.mainVideoUser.user.pUser)
        let spotUser = this.mainVideoUser
        if (participantsVideoUserList.length > 0 && mainUserIndex == -1) {
          spotUser = participantsVideoUserList[0]
        } 
        let currentIndex = allUserList.findIndex(val => val && val.user.pUser == spotUser.user.pUser)
        this.currentPageIndex = Math.floor(currentIndex / newParticipantsVideoCount)
        let resizedUserList = [...allUserList.splice(newParticipantsVideoCount * this.currentPageIndex, newParticipantsVideoCount)]
        resizedUserList.forEach(item => item.needScribe = true)
        for (let i = 0; i < participantsVideoUserList.length; i++) {
          if (resizedUserList[i] && participantsVideoUserList[i].user.pUser == resizedUserList[i].user.pUser) {
            resizedUserList[i].needScribe = false
          } else {
            let recv_handle = this.participantsVideoHandleMap[participantsVideoUserList[i].user.pUser]
            let unSubscribeObj = {
              user: participantsVideoUserList[i].user,
              recv_handle: recv_handle,
              dataType: this.participantsVideo[recv_handle].dataType       
            }
            this.zoomVideoSDKUser.unSubscribe(unSubscribeObj)
            delete this.participantsVideoHandleMap[unSubscribeObj.user.pUser]
            this.$set(this.participantsVideoUserList, recv_handle, null)
          }
        }
        for (let index = 0; index < resizedUserList.length; index++) {
          if (resizedUserList[index].needScribe) {
            let subscribeObj = {
              user: resizedUserList[index].user,
              recv_handle: index,
              resolution: ZoomVideoSDKResolution.ZoomVideoSDKResolution_90P,
              dataType: 0       
            }
            this.zoomVideoSDKUser.subscribe(subscribeObj)
            this.$set(this.participantsVideoUserList, subscribeObj.recv_handle, resizedUserList[index])
            this.$set(this.participantsVideoHandleMap, subscribeObj.user.pUser, subscribeObj.recv_handle)
          }
        }
      }
    },
    generateUserColor (count = 0) {
      let r = Math.floor(Math.random() * 100 + 150)
      let g = Math.floor(Math.random() * 100 + 150)
      let b = Math.floor(Math.random() * 100 + 150)
      let color = `#${r.toString(16)}${g.toString(16)}${b.toString(16)}`
      if (this.allUserList.find(item => color == item.color) === color && count < 30) {
        this.generateUserColor(count++)
      }
      return color
    },
    subscribeMainVideo (newUser) {
      const newUserInfo = {...newUser}
      const dataType = newUserInfo.isSharing 
        ? ZoomVideoSDKRawDataType.RAW_DATA_TYPE_SHARE  
        : ZoomVideoSDKRawDataType.RAW_DATA_TYPE_VIDEO 
      if (newUserInfo.user.pUser == this.mainVideoUser.user.pUser && dataType == this.mainVideo.dataType) {
        return
      }
      let subscribeObj = {
        user: newUserInfo.user,
        recv_handle: this.mainVideoRecvHandle,
        resolution: this.mainVideo.resolution,
        dataType: dataType   
      }
      let SubscribeResult = this.zoomVideoSDKUser.subscribe(subscribeObj)
      console.log('subscribeMainVideo:subscribe', SubscribeResult, subscribeObj)
      if (SubscribeResult === ZoomVideoSDKErrors.ZoomVideoSDKErrors_Success) {
        delete this.mainVideoUser
        this.mainVideoUser = new UserInfo(newUserInfo.user, newUser.color)
        this.mainVideo.setDataType(dataType)
        this.mainVideo.setDrawVideoStatus((newUserInfo.user.pUser !== this.myselfInfo.pUser && newUserInfo.isSharing) ? true : newUserInfo.isVideoOn)
        this.updateMeetingViewPorts()
      }
    },
    handleOverParticipant(item) {
      this.$set(item, 'isHoverd', true)
    },
    handleOutParticipant(item) {
      this.$set(item, 'isHoverd', false)
    },
    toggleParticipantsVideo () {
      this.isParticipantsVideoShown = !this.isParticipantsVideoShown
      if (this.isParticipantsVideoShown) {
        this.currentPageIndex = 0
        this.subscribeCurrentPageUsers()
      } else {
        this.unSubscribeCurrentPageUsers()
      }
    },
    subscribeCurrentPageUsers () {
      let allUserList = [...this.allUserList.filter(item => item)]
      let need_sub_list = allUserList.splice(this.currentParticipantsVideoCount * this.currentPageIndex, this.currentParticipantsVideoCount)
      for (let index = 0; index < need_sub_list.length; index++) {
        let subscribeObj = {
          user: need_sub_list[index].user,
          recv_handle: index,
          resolution: ZoomVideoSDKResolution.ZoomVideoSDKResolution_90P,
          dataType: 0       
        }
        this.zoomVideoSDKUser.subscribe(subscribeObj)
        this.$set(this.participantsVideoUserList, index, need_sub_list[index])
        this.$set(this.participantsVideoHandleMap, subscribeObj.user.pUser, subscribeObj.recv_handle)
      }
    },
    unSubscribeCurrentPageUsers () {
      const need_unsub_list = [...this.participantsVideoUserList.filter(item => item)]
      for (let index = 0; index < need_unsub_list.length; index++) {
        let pUser = need_unsub_list[index].user.pUser
        let recv_handle = this.participantsVideoHandleMap[pUser]
        let unSubscribeObj = {
          user: need_unsub_list[index].user,
          recv_handle: recv_handle,
          dataType: this.participantsVideo[recv_handle].dataType       
        }
        this.zoomVideoSDKUser.unSubscribe(unSubscribeObj)
        delete this.participantsVideoHandleMap[unSubscribeObj.user.pUser]
        this.$set(this.participantsVideoUserList, index, null)
      }
    },
    handleParticipantsPageChange (page) {
      this.currentPageIndex = page
      this.unSubscribeCurrentPageUsers()
      this.$nextTick(() => {
        this.subscribeCurrentPageUsers()
      })
    },
    onPainterVideoRawDataReceived (data_format, uint64_recv_handle, uint8_array_data_buf) {
      if (this.isMinimize) {
        return
      }
      try {
        const formatList = data_format.split(';')
        let croppingParams = Object.assign({}, {
          top: 0,
          left: 0,
          width: Number(formatList[2]),
          height: Number(formatList[3]),
          rotation: Number(formatList[4])
        }) 
        let data = new Uint8Array(uint8_array_data_buf)
        if (uint64_recv_handle == this.mainVideoRecvHandle) {
          this.mainVideo.UpdateVideoTextures(croppingParams, data)
        } else {
          this.participantsVideo[uint64_recv_handle].UpdateVideoTextures(croppingParams, data)
        }
        this.computeViewPortParams(uint64_recv_handle)
        if (!this.redrawMsgFired) {
          window.requestAnimationFrame(this.drawMeetingVideo)
          this.redrawMsgFired = true
        }
      } catch (error) {
        console.log(error, `uint64_recv_handle is ${uint64_recv_handle}`)
      }
    },
    updateMeetingViewPorts (hideToolbar=false) {
      if (hideToolbar) {
        this.isFocusWindow = false
      }
      if (this.mainVideo.isDrawVideo) {
        this.computeViewPortParams(this.mainVideoRecvHandle)
      }
      for (let index = 0; index < this.participantsVideoUserList.length; index++) {
        if (this.participantsVideo[index].isDrawVideo) {
          this.computeViewPortParams(index)
        }
      }
    },
    computeViewPortParams (index) {
      const clientWidth = document.body.clientWidth
      const clientHeight = document.body.clientHeight
      let croppingParams
      let viewPortParams
      try {
        if (index == this.mainVideoRecvHandle) {
          let mainWidth = document.querySelector('.meeting-wrap').offsetWidth
          croppingParams = this.mainVideo.croppingParams
          let viewPortWidth = croppingParams.width * clientHeight / croppingParams.height
          let viewPortHeight = mainWidth * croppingParams.height / croppingParams.width
          if (croppingParams.rotation == 90 || croppingParams.rotation == 270) {
            viewPortWidth = croppingParams.height * clientHeight / croppingParams.width
            viewPortHeight = clientHeight
          }
          if (Math.round(croppingParams.width / croppingParams.height) < Math.round(clientWidth / clientHeight) 
            || (croppingParams.rotation == 90 || croppingParams.rotation == 270) && mainWidth > viewPortWidth) {
            viewPortParams = Object.assign({}, {
              x: this.isFillScreen ? 0 : (mainWidth - viewPortWidth) / 2,
              y: 0,
              width: this.isFillScreen ? mainWidth : viewPortWidth,
              height: clientHeight
            }) 
          } else {
            viewPortParams = Object.assign({}, {
              x: 0,
              y: this.isFillScreen ? 0 : (clientHeight - viewPortHeight) / 2,
              width: mainWidth,
              height: this.isFillScreen ? clientHeight : viewPortHeight
            }) 
          }
          this.mainVideo.setViewPort(viewPortParams)
        } else {
          let boundingClientRect = document.querySelector(`#texture${index}`).getBoundingClientRect()
          croppingParams = this.participantsVideo[index].croppingParams
          let positionX = boundingClientRect.left + this.participantsStyle.participantsLeftOffset
          let positionY = clientHeight - boundingClientRect.bottom + this.participantsStyle.participantsTopOffset
          let smallViewPortWidth = croppingParams.width * this.participantsStyle.participantsHeight / croppingParams.height
          let smallViewPortHeight = this.participantsStyle.participantsWidth * croppingParams.height / croppingParams.width
          if (croppingParams.rotation == 90 || croppingParams.rotation == 270) {
            smallViewPortWidth = croppingParams.height * this.participantsStyle.participantsHeight / croppingParams.width
            smallViewPortHeight = this.participantsStyle.participantsHeight
          }
          if (Math.round(croppingParams.width / croppingParams.height) < Math.round(this.participantsStyle.participantsWidth / this.participantsStyle.participantsHeight)
            || croppingParams.rotation == 90 || croppingParams.rotation == 270) {
            viewPortParams = Object.assign({}, {
              x: positionX + (this.participantsStyle.participantsWidth - smallViewPortWidth) / 2,
              y: positionY,
              width: smallViewPortWidth,
              height: this.participantsStyle.participantsHeight,
              dataType: 0
            })
          } else {
            viewPortParams = Object.assign({}, {
              x: positionX,
              y: positionY + (this.participantsStyle.participantsHeight - smallViewPortHeight) / 2,
              width: this.participantsStyle.participantsWidth,
              height: smallViewPortHeight,
              dataType: 0
            })
          }
          this.participantsVideo[index].setViewPort(viewPortParams)
        }
      } catch (error) {
        console.log(error, `uint64_recv_handle is ${index}`)
      }
      if (this.canvas) {
        this.canvas.width = clientWidth
        this.canvas.height = clientHeight
      }
    },
    drawMeetingVideo () {
      this.redrawMsgFired = false
      if (this.mainVideo.isDrawVideo) {
        this.mainVideo.DrawVideo()
      }
      for (let index = 0; index < this.participantsVideoUserList.length; index++) { 
        if (this.participantsVideo[index].isDrawVideo) {
          this.participantsVideo[index].DrawVideo()
        }
      }
    },
    initMeeting() {
      this.mainVideoUser = new UserInfo(this.myselfInfo, this.myselfInfo.color || this.generateUserColor())
      if (!this.isVideoMute) {
        this.subscribeMainVideo(this.mainVideoUser)
      }
      let param = [setUserInfo(this.myselfInfo)]
      this.onUserJoin(param)
    },
    stopShare () {
      if (this.myselfInfo.ShareStatus == 1) {
        const stopShare = this.zoomVideoSDKShare.stopShare()
        if (stopShare === 0) {
          this.$set(this.myselfInfo, 'ShareStatus', 0)
        }
        ipcRenderer.send('stop-share')
      }
    },
    updateUserInfo(key, value, pUser) {
      for (let index in this.allUserList) {
        if (this.allUserList[index] && pUser === this.allUserList[index].user.pUser) {
          switch (key) {
            case 'Video':
              this.allUserList[index].setVideoStatus(value)
              break;
            case 'Audio':
              this.allUserList[index].setAudioStatus(value)
              break;
            case 'Share':
              this.allUserList[index].setShareStatus(value)
              break;
          }
          break
        }
      }
      for (let index in this.participantsVideoUserList) {
        if (this.participantsVideoUserList[index] && pUser === this.participantsVideoUserList[index].user.pUser) {
          switch (key) {
            case 'Video':
              this.participantsVideoUserList[index].setVideoStatus(value)
              break;
            case 'Audio':
              this.participantsVideoUserList[index].setAudioStatus(value)
              break;
            case 'Share':
              this.participantsVideoUserList[index].setShareStatus(value)
              break;
          }
          break
        }
      }
    },
    clearUserList() {
      this.allUserList = []
      this.participantsVideoUserList = []
    },
    handleInputStatus(is_inputing) {
      this.isInputing = is_inputing
    },
    handleStatisticStatus(is_shown) {
      this.isStatisticLayerShown = is_shown
    },
    handleSecondCameraStatus(key, value) {
      this.$set(this.shareSecondCamera, key, value) 
    },
    handleRemoteControlStatus(key, value) {
      this.$set(this.remoteControl, key, value)
    },
    handleNotification(str) {
      this.notificationContent = str
    },
    handleRemoteControl(is_remote_control, participant) {
      if (is_remote_control) {
        this.requestingNotificationContent = `Requesting camera control from ${participant.user.username}...`
        this.notificationContent = this.requestingNotificationContent
        this.isRequestingCameraControl = true
        this.subscribeMainVideo(participant)
      } else {
        this.$set(this.remoteControl, 'isStopCameraControlLayerShown', true)
      }
    }
  },
  mounted () {
    this.canvas = document.querySelector(`#canvas`)
    this.debounceResizeMeetingWindow = debounce(this.resizeMeetingWindow, 500)
    window.addEventListener('click', this.focusFloatWindow)
    window.addEventListener('input', this.focusFloatWindow)
    window.addEventListener('resize', this.debounceResizeMeetingWindow, false)
    window.addEventListener('resize', this.updateMeetingViewPorts(true), false)
    this.focusFloatWindow()
    const SetPainterVideoRawDataCB = this.renderAddon.SetPainterVideoRawDataCB(this.onPainterVideoRawDataReceived)
    this.myselfInfo = this.zoomVideoSDKSessionInfo.getMyself()
    this.$set(this.myselfInfo, 'color', this.generateUserColor())
    this.$set(this.myselfInfo, 'avatarName', getAvatarName(this.myselfInfo.username))
    this.mainVideo = new RenderItem(this.canvas, 0)
    this.mainVideo.setDrawVideoStatus(!this.isVideoMute)
    for (let index = 0; index < this.maxParticipantsVideoCount; index++) {
      this.participantsVideo[index] = new RenderItem(this.canvas, index + 1)
    }
    this.cameraList = this.zoomVideoSDKVideo.getCameraList()
    if (this.cameraList.length === 0) {
      this.isVideoMute = true
      this.mainVideo.setDrawVideoStatus(false)
      this.$set(this.toolbarStatus, 'isVideoMute', true)
      ipcRenderer.send('setToolbarStatus', this.toolbarStatus)
    }
    this.micList = this.zoomVideoSDKAudio.getMicList()
    if (this.micList.length === 0) {
      this.isAudioMute = true
    }
    this.initMeeting()
    this.resizeMeetingWindow() 
    ipcRenderer.on('setVideoList', () => {
      this.toggleParticipantsVideo()
    })
    ipcRenderer.on('isMinimize', (e, msg) => {
      console.log('isMinimize', msg)
      this.isMinimize = msg
      if (!this.isMinimize) {
        window.requestAnimationFrame(this.drawMeetingVideo)
      }
    })
    this.$EventBus.$on('change', () => {
      this.focusFloatWindow()
    })
    this.$EventBus.$on('close', () => {
      this.focusFloatWindow()
    })
    this.$EventBus.$on('showStatisticLayer', () => {
      this.isStatisticLayerShown = true
    })
  },
  beforeDestroy () {
    window.removeEventListener('click', this.focusFloatWindow)
    window.removeEventListener('input', this.focusFloatWindow)
    window.removeEventListener('resize', this.debounceResizeMeetingWindow)
    window.removeEventListener('resize', this.updateMeetingViewPorts)
    this.$EventBus.$off('change')
    this.$EventBus.$off('close')
    this.$EventBus.$off('showStatisticLayer')
    this.stopShare()
    this.unSubscribeCurrentPageUsers()
    let unSubscribeObj = {
      user: this.mainVideoUser.user,
      recv_handle: this.mainVideoRecvHandle,
      dataType: this.mainVideo.dataType
    }
    this.zoomVideoSDKUser.unSubscribe(unSubscribeObj)
    this.clearUserList()
  },
  components: {
    MeetingHeader,
    MeetingChat,
    MeetingControl,
    LayerStatistic,
    LayerMeetingRemoteControl,
    MeetingLowerThirds,
    IconMeetingParticipantsMuteAudio,
    MeetingSwitchCamera,
    MeetingCameraControlled,
    MeetingParticipantsMore,
    LayerNotification,
    LayerRequestCameraControl,
    LayerStopCameraControl
  }
}
</script>
