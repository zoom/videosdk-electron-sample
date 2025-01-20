<template>
  <ul class="share">
    <li>
      <div @click="handleAudio">
        <IconShareMuteAudio v-if="isAudioMute" />
        <IconShareUnMuteAudio v-else />
      </div>
    </li>
    <li>
      <div @click="handleVideo">
        <IconShareMuteVideo v-if="isVideoMute" />
        <IconShareUnMuteVideo v-else />
      </div>
    </li>
    <li>
      <div @click="handleShowVideoList">
        <el-badge :value="liveOnNum>0?liveOnNum:''" class="item">
          <IconSharePeople />
        </el-badge>
      </div>
    </li>
    <li>
      <div @click="stopShare">
        <IconShareStop />
      </div>
    </li>
  </ul>
</template>

<script>
import { ZoomVideoSDKErrors } from '../../lib/zoom_video_sdk_defines'
import IconShareUnMuteAudio from '../components/Icon/IconShareUnMuteAudio'
import IconShareUnMuteVideo from '../components/Icon/IconShareUnMuteVideo'
import IconShareMuteAudio from '../components/Icon/IconShareMuteAudio'
import IconShareMuteVideo from '../components/Icon/IconShareMuteVideo'
import IconSharePeople from '../components/Icon/IconSharePeople'
import IconShareStop from '../components/Icon/IconShareStop'
const { ipcRenderer: ipc } = window.require('electron')
const remote = window.require('@electron/remote')
const zoomVideoSdk = remote.app.zoomVideoSdk

export default {
  data () {
    return {
      isAudioMute: remote.getGlobal('muteStatus').isAudioMute,
      isVideoMute: remote.getGlobal('muteStatus').isVideoMute,
      liveOnNum: remote.getGlobal('muteStatus').liveOnNum,
      zoomVideoSDKVideo: zoomVideoSdk.getVideoHelper(),
      zoomVideoSDKAudio: zoomVideoSdk.getAudioHelper(),
      zoomVideoSDKSessionInfo: zoomVideoSdk.getSessionInfo()
    }
  },
  methods: {
    handleAudio () {
      const data = {
        user: this.zoomVideoSDKSessionInfo.getMyself()
      }
      if (this.isAudioMute) {
        const unMuteAudio = this.zoomVideoSDKAudio.unMuteAudio(data)
      } else {
        const isAudioMute = this.zoomVideoSDKAudio.muteAudio (data)
      }
    },
    handleVideo () {
      if (this.isVideoMute) {
        const startVideo = this.zoomVideoSDKVideo.startVideo()
      } else {
        const stopVideo = this.zoomVideoSDKVideo.stopVideo()
      }
    },
    handleShowVideoList () {
      ipc.send('setVideoList')
    },
    stopShare () {
      const zoomVideoSdk = remote.app.zoomVideoSdk
      const zoomVideoSDKShare = zoomVideoSdk.getShareHelper()
      const stopShare = zoomVideoSDKShare.stopShare()
      if (stopShare === ZoomVideoSDKErrors.ZoomVideoSDKErrors_Success) {
        ipc.send('stop-share')
      }
    }
  },
  mounted () {
    ipc.on('getToolbarStatus', (event, params) => {
      this.isAudioMute = params.isAudioMute,
      this.isVideoMute = params.isVideoMute,
      this.liveOnNum = params.liveOnNum
    })
  },
  components: {
    IconShareUnMuteAudio,
    IconShareUnMuteVideo,
    IconShareMuteAudio,
    IconShareMuteVideo,
    IconSharePeople,
    IconShareStop
  }
}
</script>

<style lang="scss" scoped>
  .share {
    -webkit-app-region: drag;
    width: 262px;
    height: 100%;
    display: flex;
    align-items: center;
    background: rgba(26, 26, 26, 0.8);
    backdrop-filter: blur(16px);
    border-radius: 12px;
    li {
      float: left;
      height: 44px;
      display: flex;
      flex: 1;
      justify-content: center;
      align-items: center;
      cursor: pointer;
      &:first-child {
        margin-left: 5px;
      }
      &:last-child {
        margin-right: 7px;
      }
      >div {
        -webkit-app-region: no-drag;
        display: flex;
        align-items: center;
      }
    }
  }
</style>
<style lang="scss">
  .share {
    .el-badge__content {
      background: none;
      color: #747487;
      font-size: 10px;
      background: none;
      border: none;
      top: 0;
      right: 8px;
    }
  }
</style>
