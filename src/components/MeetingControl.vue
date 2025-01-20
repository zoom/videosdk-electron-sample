<template>
  <div>
    <ul class="btn-group">
      <li @click="handleAudio">
        <IconMeetingMuteAudio v-if="isAudioMute" />
        <IconMeetingUnMuteAudio v-else />
      </li>
      <li @click="handleVideo">
        <IconMeetingMuteVideo v-if="isVideoMute" />
        <IconMeetingUnMuteVideo v-else />
      </li>
      <li class="meeting-participant" @click="handleShowVideoList">
        <el-badge :value="liveOnNum>0?liveOnNum:''">
          <IconMeetingParticipants />
        </el-badge>
      </li>
      <li @click="handleShowLeaveMeeting">
        <IconMeetingEnd />
      </li>
      <li @click="handleShowShare">
        <IconMeetingShare />
      </li>
      <li ref="reaction" @click="handleShowReaction">
        <IconMeetingReaction />
      </li>
      <li class="meeting-submit" @click="handleShowFeedback" v-if="myselfInfo.isHost">
        <el-badge :value="totalSubmit>0?totalSubmit:''">
          <IconMeetingFeedback />
        </el-badge>
      </li>
      <li ref="more" @click="handleShowFeedbackBtn" v-else>
        <IconMeetingMore />
      </li>
    </ul>
    <div class="control-layer" v-if="isLeaveMeetingLayerShown">
      <LayerLeaveMeeting :parent="this" :myselfInfo="myselfInfo" />
    </div>
    <div class="control-layer" v-if="isShareLayerShown">
      <LayerShare :isOtherUserSharing="isOtherUserSharing" :appsList="appsList" :monitorsList="monitorsList" :activeSharingUserName="activeSharingUserName"
       @updateShareLayerStatus="handleShareLayerStatus" />
    </div>
    <div class="reaction-layer" v-if="isReactionLayerShown">
      <LayerReaction :parent="this" :myselfInfo="myselfInfo" />
    </div>
    <div class="icon-setting" @click="handleShowSetting">
      <IconMeetingSet />
    </div>
    <div class="setting-layer" v-if="isSettingLayerShown">
      <LayerSetting :parent="this" />
    </div>
    <div class="setting-layer" v-if="isLowerThirdsLayerShown">
      <LayerLowerThirds :parent="this" />
    </div>
    <div class="feedback-layer" v-show="isFeedbackLayerShown">
      <LayerFeedbackHost :parent="this" :feedbackSubmitMap="feedbackSubmitMap" :totalSubmit="totalSubmit" v-if="myselfInfo.isHost" />
      <LayerFeedbackParticipant :parent="this" :isStartFeedback="isStartFeedback" v-else />
    </div>
    <div class="more-feedback" @click="handleShowFeedback" :style="{'left': moreBtnLeftPosition}" v-if="isParticipantFeedbackBtnShown">
      Feedback This Session 
      <svg width="16" height="16" viewBox="0 0 16 16" fill="none" xmlns="http://www.w3.org/2000/svg">
      <path fill-rule="evenodd" clip-rule="evenodd" d="M10.6668 9.33333C13.2441 9.33333 15.3335 7.244 15.3335 4.66667C15.3335 2.08934 13.2441 0 10.6668 0C8.08946 0 6.00012 2.08934 6.00012 4.66667C6.00012 7.244 8.08946 9.33333 10.6668 9.33333ZM12.6667 4C12.6667 4.36819 12.3682 4.66667 12 4.66667C11.6319 4.66667 11.3334 4.36819 11.3334 4C11.3334 3.63181 11.6319 3.33333 12 3.33333C12.3682 3.33333 12.6667 3.63181 12.6667 4ZM10.0001 4.00004C10.0001 4.36823 9.70165 4.66671 9.33346 4.66671C8.96527 4.66671 8.66679 4.36823 8.66679 4.00004C8.66679 3.63185 8.96527 3.33337 9.33346 3.33337C9.70165 3.33337 10.0001 3.63185 10.0001 4.00004ZM8.77491 6.01351C8.62922 5.67013 8.89962 5.33333 9.23135 5.33333H12.1022C12.4339 5.33333 12.7043 5.67013 12.5587 6.01351C12.3594 6.48322 12.0762 6.81886 11.7369 7.03488C11.3991 7.24997 11.0263 7.33333 10.6668 7.33333C10.3073 7.33333 9.9345 7.24997 9.59665 7.03488C9.25734 6.81886 8.9742 6.48322 8.77491 6.01351ZM4.00004 3.33337H5.50141C5.41839 3.65591 5.36479 3.99025 5.34362 4.33337H4.00004C3.07957 4.33337 2.33337 5.07957 2.33337 6.00004V10.0067C2.33337 10.9235 3.07659 11.6667 3.99339 11.6667C4.5494 11.6667 5.00004 12.1174 5.00004 12.6734V13.5858L6.33337 12.2525C6.70845 11.8774 7.21716 11.6667 7.74759 11.6667H12C12.9205 11.6667 13.6667 10.9205 13.6667 10V9.07696C14.0359 8.82532 14.3719 8.52852 14.6667 8.19451V10C14.6667 11.4728 13.4728 12.6667 12 12.6667H7.74759C7.48237 12.6667 7.22802 12.7721 7.04048 12.9596L4.68288 15.3172C4.4309 15.5692 4.00004 15.3907 4.00004 15.0344V12.6734C4.00004 12.6697 3.99706 12.6667 3.99339 12.6667C2.5243 12.6667 1.33337 11.4758 1.33337 10.0067V6.00004C1.33337 4.52728 2.52728 3.33337 4.00004 3.33337Z" fill="white" fill-opacity="0.54"/>
      </svg>
    </div>
    <img :src="require(`../assets/images/tip_reaction.png`)" class="reaction-tip" :style="{'left': reactionTipPosition}" v-if="!hasShownReactionTip" @click="handleReactionTip" />
  </div>
</template>

<script>
import LayerSetting from './LayerSetting'
import LayerLowerThirds from './LayerLowerThirds'
import LayerLeaveMeeting from './LayerLeaveMeeting'
import LayerShare from './LayerShare'
import LayerReaction from './LayerReaction'
import LayerFeedbackHost from './LayerFeedbackHost'
import LayerFeedbackParticipant from './LayerFeedbackParticipant'
import IconMeetingUnMuteAudio from './Icon/IconMeetingUnMuteAudio'
import IconMeetingMuteAudio from './Icon/IconMeetingMuteAudio'
import IconMeetingUnMuteVideo from './Icon/IconMeetingUnMuteVideo'
import IconMeetingMuteVideo from './Icon/IconMeetingMuteVideo'
import IconMeetingEnd from './Icon/IconMeetingEnd'
import IconMeetingParticipants from './Icon/IconMeetingParticipants'
import IconMeetingShare from './Icon/IconMeetingShare'
import IconMeetingReaction from './Icon/IconMeetingReaction'
import IconMeetingFeedback from './Icon/IconMeetingFeedback'
import IconMeetingMore from './Icon/IconMeetingMore'
import IconMeetingSet from './Icon/IconMeetingSet'
import { ZoomVideoSDKErrors } from '../../lib/zoom_video_sdk_defines'
import config from '../../config.json'
const fs = window.require('fs')
const remote = window.require('@electron/remote')
const zoomVideoSdk = remote.app.zoomVideoSdk
const desktopCapturer = remote.desktopCapturer

export default {
  props: ['parent', 'isFocusWindow', 'isAudioMute', 'isVideoMute', 'cameraList', 'micList', 'ShareStatus', 'activeSharingUserName', 'liveOnNum', 'myselfInfo'],
  data () {
    return {
      zoomVideoSDKVideo: zoomVideoSdk.getVideoHelper(),
      zoomVideoSDKAudio: zoomVideoSdk.getAudioHelper(),
      zoomVideoSDKSessionInfo: zoomVideoSdk.getSessionInfo(),
      zoomVideoSDKShare: zoomVideoSdk.getShareHelper(),
      isSettingLayerShown: false,
      isLowerThirdsLayerShown: false,
      isLeaveMeetingLayerShown: false,
      isShareLayerShown: false,
      isOtherUserSharing: false,
      isReactionLayerShown: false,
      isFeedbackLayerShown: false,
      isParticipantFeedbackBtnShown: false,
      appsList: [],
      monitorsList: [],
      moreBtnLeftPosition: '',
      totalSubmit: 0,
      reactionTipPosition: '',
      hasShownReactionTip: config.hasShownReactionTip
    }
  },
  watch: {
    isFocusWindow (val, oldVal) {
      if (!val) {
        this.isLeaveMeetingLayerShown = val
        this.isSettingLayerShown = val
        this.isLowerThirdsLayerShown = val
        this.isShareLayerShown = val
        this.isReactionLayerShown = val
      }
      if (val) {
        this.computeReactionTipPostion()
      }
    },
    isStartFeedback (val, oldVal) {
      if (val && !this.myselfInfo.isHost) {
        this.isFeedbackLayerShown = true
        this.$parent.focusFloatWindow()
      }
    },
    isFeedbackLayerShown (val, oldVal) {
      if (!val) {
        this.$store.commit('setStartFeedback', false)
      }
    }
  },
  computed: {
    isStartFeedback () {
      return this.$store.state.isStartFeedback
    },
    feedbackSubmitMap () {
      let submitMap = this.$store.state.cmdFeedbackSubmitMap
      let obj = {}
      for (let key in submitMap) {
        let item = submitMap[key]
        if (!obj[item]) {
          obj[item] = 1
        } else {
          obj[item]++
        }
      }
      this.totalSubmit = Object.keys(submitMap).length
      return obj
    }
  },
  methods: {
    handleAudio () {
      if (this.micList.length === 0) {
        this.$emit('updateNotification', 'You have no microphone')
        return
      }
      const isAudioMute = !this.isAudioMute
      const data = {
        user: this.zoomVideoSDKSessionInfo.getMyself()
      }
      if (isAudioMute) {
        const isAudioMute = this.zoomVideoSDKAudio.muteAudio(data)
      } else {
        const unMuteAudio = this.zoomVideoSDKAudio.unMuteAudio(data)
      }
    },
    handleVideo () {
      if (this.cameraList.length === 0) {
        this.$emit('updateNotification', 'You have no camera')
        return
      }
      const isVideoMute = !this.isVideoMute
      if (isVideoMute) {
        const stopVideo = this.zoomVideoSDKVideo.stopVideo()
      } else {
        const startVideo = this.zoomVideoSDKVideo.startVideo()
        if (startVideo === ZoomVideoSDKErrors.ZoomVideoSDKErrors_Session_Video_Error) {
          this.$emit('updateNotification', 'Please select another video camera in settings')
        }
      }
    },
    handleShowVideoList () {
      this.$emit('control', 'showList')
      this.isParticipantFeedbackBtnShown = false
    },
    handleShowShare () {
      if (this.ShareStatus == 1) {
        this.$emit('updateNotification', 'You are sharing now')
        return
      }
      this.isOtherUserSharing = this.zoomVideoSDKShare.isOtherSharing()
      this.isSettingLayerShown = false
      this.isLowerThirdsLayerShown = false
      this.isLeaveMeetingLayerShown = false
      this.isReactionLayerShown = false
      this.isFeedbackLayerShown = false
      this.$emit('updateStatisticStatus', false)
      if (!this.isOtherUserSharing) {
        desktopCapturer.getSources({ types: ['screen'] }).then(async sources => {
          this.monitorsList = []
          console.log(sources)
          for (let i in sources) {
            let obj = {...sources[i]}
            obj.src = sources[i].thumbnail.toDataURL()
            obj.shareMonitorID = obj.id.split(':')[1]
            if (window.navigator.userAgent.indexOf('Windows') > -1) {
              obj.shareMonitorID = `\\\\.\\DISPLAY${Number(obj.id.split(':')[1]) + 1}`
            } else if (window.navigator.userAgent.indexOf('Linux') > -1) {
              obj.shareMonitorID = `${remote.app.display}-${obj.id.split(':')[2]}${remote.app.screenArea}-0`
            }
            this.monitorsList.push(obj)
          }
          this.isShareLayerShown = !this.isShareLayerShown
        })
        desktopCapturer.getSources({ types: ['window'] }).then(async sources => {
          this.appsList = []
          for (let i in sources) {
            let obj = {...sources[i]}
            obj.src = sources[i].thumbnail.toDataURL()
            obj.shareAppHandle = obj.id.split(':')[1]
            if (window.navigator.userAgent.indexOf('Windows') > -1) {
              obj.shareAppHandle = Number(obj.id.split(':')[1]).toString(16)
            } else if (window.navigator.userAgent.indexOf('Linux') > -1) {
              obj.shareAppHandle = `${remote.app.display}-${obj.id.split(':')[2]}${remote.app.screenArea}-${obj.id.split(':')[1]}`
            }
            if (obj.src.length > 22 && obj.name !== 'electron-video-sdk') {
              this.appsList.push(obj)
            }
          }
        })
      } else {
        this.isShareLayerShown = !this.isShareLayerShown
      }
    },
    handleShareLayerStatus(is_shown) {
      this.isShareLayerShown = is_shown
    },
    handleShowReaction () {
      this.handleReactionTip()
      this.isLeaveMeetingLayerShown = false
      this.isShareLayerShown = false
      this.$emit('updateStatisticStatus', false)
      this.isSettingLayerShown = false
      this.isLowerThirdsLayerShown = false
      this.isFeedbackLayerShown = false
      this.isReactionLayerShown = !this.isReactionLayerShown
    },
    handleShowFeedback () {
      this.isLeaveMeetingLayerShown = false
      this.isShareLayerShown = false
      this.$emit('updateStatisticStatus', false)
      this.isSettingLayerShown = false
      this.isLowerThirdsLayerShown = false
      this.isReactionLayerShown = false
      this.isFeedbackLayerShown = !this.isFeedbackLayerShown
      this.isParticipantFeedbackBtnShown = false
    },
    handleShowFeedbackBtn () {
      const morePosition = this.$refs.more.getBoundingClientRect()
      this.moreBtnLeftPosition = morePosition.left + 'px'
      this.isLeaveMeetingLayerShown = false
      this.isShareLayerShown = false
      this.$emit('updateStatisticStatus', false)
      this.isSettingLayerShown = false
      this.isLowerThirdsLayerShown = false
      this.isReactionLayerShown = false
      this.isFeedbackLayerShown = false
      this.isParticipantFeedbackBtnShown = !this.isParticipantFeedbackBtnShown
    },
    handleShowSetting () {
      this.isLeaveMeetingLayerShown = false
      this.isShareLayerShown = false
      this.isReactionLayerShown = false
      this.isLowerThirdsLayerShown = false
      this.isFeedbackLayerShown = false
      this.$emit('updateStatisticStatus', false)
      this.isSettingLayerShown = !this.isSettingLayerShown
    },
    handleShowLeaveMeeting () {
      let isHost = this.zoomVideoSDKSessionInfo.getMyself().isHost
      this.$set(this.parent.myselfInfo, 'isHost', isHost)
      this.isSettingLayerShown = false
      this.isLowerThirdsLayerShown = false
      this.isShareLayerShown = false
      this.isReactionLayerShown = false
      this.isFeedbackLayerShown = false
      this.$emit('updateStatisticStatus', false)
      this.isLeaveMeetingLayerShown = !this.isLeaveMeetingLayerShown
    },
    computeReactionTipPostion () {
      if (!this.hasShownReactionTip) {
        const reactionPosition = this.$refs.reaction.getBoundingClientRect()
        this.reactionTipPosition = (reactionPosition.left - 120) + 'px'
      }
    },
    handleReactionTip () {
      if(!this.hasShownReactionTip) {
        this.hasShownReactionTip = true
        const configPath = './config.json'
        let config = fs.readFileSync(configPath)
        config = JSON.parse(config)
        config.hasShownReactionTip = true
        fs.writeFileSync(configPath, JSON.stringify(config, null, 2))
      }
    }
  },
  mounted () {
    this.$EventBus.$on('close', () => {
      this.handleShowLeaveMeeting()
    })
    this.$EventBus.$on('share', (obj) => {
      let startShareScreen
      if (obj.type == 'app') {
        const data = {
          handle: obj.item.shareAppHandle
        }
        startShareScreen = this.zoomVideoSDKShare.startShareView(data)
      } else if (obj.type == 'camera') {
        let cameraOptions = this.zoomVideoSDKVideo.getCameraList()
        let shareItem = cameraOptions.find(item => !item.isSelectedDevice)
        let param = {
          cameraID: shareItem.deviceID
        }
        startShareScreen = this.zoomVideoSDKShare.startShare2ndCamera(param)
        if (startShareScreen == ZoomVideoSDKErrors.ZoomVideoSDKErrors_Success) {
          this.$parent.subscribeMainVideo({ user: this.$parent.myselfInfo, isSharing: true })
          this.$emit('updateSecondCameraStatus', 'sharingCameraID', param.cameraID)
          this.$emit('updateSecondCameraStatus', 'isSharingSecondCamera', true)
        } else {
          this.$emit('updateSecondCameraStatus', 'sharingCameraID', undefined)
          this.$emit('updateSecondCameraStatus', 'isSharingSecondCamera', false)
        }
      } else {
        const data = {
          monitorID: obj.item.shareMonitorID
        }
        startShareScreen = this.zoomVideoSDKShare.startShareScreen(data)
      }
      if (startShareScreen != ZoomVideoSDKErrors.ZoomVideoSDKErrors_Success) {
        if (!this.activeSharingUserName) {
          this.parent.activeSharingUserName = 'someone'
        }
        this.isOtherUserSharing = true
      }
    })
  },
  beforeDestroy () {
    this.$EventBus.$off('close')
    this.$EventBus.$off('share')
  },
  components: {
    LayerSetting,
    LayerLowerThirds,
    LayerLeaveMeeting,
    LayerShare,
    LayerReaction,
    LayerFeedbackHost,
    LayerFeedbackParticipant,
    IconMeetingUnMuteAudio,
    IconMeetingMuteAudio,
    IconMeetingUnMuteVideo,
    IconMeetingMuteVideo,
    IconMeetingEnd,
    IconMeetingParticipants,
    IconMeetingShare,
    IconMeetingReaction,
    IconMeetingFeedback,
    IconMeetingMore,
    IconMeetingSet
  }
}
</script>

<style lang="scss" scoped>
  .btn-group {
    width: 456px;
    height: 48px;
    position: absolute;
    left: 50%;
    bottom: 18px;
    transform: translateX(-50%);
    li {
      float: left;
      display: flex;
      justify-content: center;
      align-items: center;
      cursor: pointer;
      margin: 0 10px;
      &:first-child {
        margin-left: 0;
      }
      &:last-child {
        margin-right: 0;
      }
    }
  }
  .icon-setting {
    width: 48px;
    height: 48px;
    display: inline-block;
    position: absolute;
    bottom: 18px;
    right: 12px;
    cursor: pointer;
  }
  .control-layer {
    position: absolute;
    left: 50%;
    bottom: 90px;
    transform: translateX(-50%);
    z-index: 10;
  }
  .reaction-layer {
    position: absolute;
    left: calc(50% + 80px);
    bottom: 90px;
    z-index: 10;
  }
  .setting-layer {
    position: absolute;
    right: 15px;
    bottom: 90px;
    z-index: 10;
  }
  .feedback-layer {
    position: absolute;
    left: 50%;
    bottom: 90px;
    z-index: 10;
  }
  .more-feedback {
    position: absolute;
    left: 50%;
    bottom: 90px;
    z-index: 10;
    padding: 16px;
    background: #242424;
    border: 0.5px solid rgba(0, 0, 0, 0.5);
    box-shadow: 0px 8px 24px rgba(0, 0, 0, 0.3);
    border-radius: 8px;
    font-size: 13px;
    line-height: 16px;
    color: #F5F5F5;
    cursor: pointer;
  }
  .reaction-tip {
    width: 283px;
    position: absolute;
    left: 50%;
    bottom: 50px;
    cursor: pointer;
  }
</style>
<style lang="scss">
  .meeting .btn-group {
    .meeting-participant {
      .el-badge__content {
        color: #747487;
        font-size: 10px;
        background: none;
        border: none;
        top: 11px;
        right: 15px;
        padding: 0;
      }
    }
    .meeting-submit {
      .el-badge__content {
        font-size: 10px;
        border: none;
        top: 6px;
        right: 10px;
        padding: 0 3px;
      }
    }
  }
</style>
