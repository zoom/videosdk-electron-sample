<template>
  <div :class="['switch-camera', {'when-camera-controlled': isCameraControlled}]" v-if="cameraOptions.length>0">
    <template v-if="cameraOptions.length>1">
      <el-dropdown @visible-change="getCameraOptions" @command="handleCommand">
        <span class="el-dropdown-link">
          <IconShareSwitchCamera class="icon" />
        </span>
        <el-dropdown-menu class="camera-dropdown" slot="dropdown">
          <el-dropdown-item v-for="(item, index) in cameraOptions" :key="index" :command="item.deviceID">{{item.deviceName}}</el-dropdown-item>
        </el-dropdown-menu>
      </el-dropdown>
    </template>
    <span @click="switchCamera" v-else>
      <IconShareSwitchCamera class="icon" />
    </span>
  </div>
</template>

<script>
import { ZoomVideoSDKErrors } from '../../lib/zoom_video_sdk_defines'
import IconShareSwitchCamera from '../components/Icon/IconShareSwitchCamera'
const remote = window.require('@electron/remote')
const zoomVideoSdk = remote.app.zoomVideoSdk

export default {
  props: ['sharingCameraID', 'isCameraControlled'],
  data() {
    return {
      zoomVideoSDKVideo: zoomVideoSdk.getVideoHelper(),
      zoomVideoSDKShare: zoomVideoSdk.getShareHelper(),
      cameraOptions: []
    }
  },
  methods: {
    getCameraOptions(visible) {
      if (visible) {
        let cameraList = this.zoomVideoSDKVideo.getCameraList()
        this.cameraOptions = cameraList.filter(item => {
          return !item.isSelectedDevice && item.deviceID != this.sharingCameraID
        })
      }
    },
    switchCamera() {
      this.handleCommand(this.cameraOptions[0].deviceID)
      setTimeout(() => {
        this.getCameraOptions(true)
      }, 300);
    },
    handleCommand(command) {
      if (command == this.sharingCameraID) {
        return
      }
      this.$emit('updateSecondCameraStatus', 'isSwitchShareCamera', true)
      this.zoomVideoSDKShare.stopShare()
      let param = {
        cameraID: command
      }
      let startShare2ndCamera = this.zoomVideoSDKShare.startShare2ndCamera(param)
      if (startShare2ndCamera == ZoomVideoSDKErrors.ZoomVideoSDKErrors_Success) {
        this.$parent.subscribeMainVideo({ user: this.$parent.myselfInfo, isSharing: true })
        this.$emit('updateSecondCameraStatus', 'sharingCameraID', param.cameraID)
        this.$emit('updateSecondCameraStatus', 'isSharingSecondCamera', true)
      } else {
        this.$emit('updateSecondCameraStatus', 'sharingCameraID', undefined)
        this.$emit('updateSecondCameraStatus', 'isSharingSecondCamera', false)
      }
    }
  },
  mounted() {
    this.getCameraOptions(true)
  },
  components: {
    IconShareSwitchCamera
  }
}
</script>

<style lang="scss" scoped>
.switch-camera {
  position: absolute;
  top: 38px;
  left: 8px;
  cursor: pointer;
}
.when-camera-controlled {
  left: 38px;
}
</style>
<style lang="scss">
.camera-dropdown {
  color: rgba(255, 255, 255, 0.8) !important;
  background-color: rgba(0, 0, 0, 0.8) !important;
  border: 1px solid rgba(255, 255, 255, 0.12);
  box-shadow: 0px 8px 24px rgba(0, 0, 0, 0.3);
  backdrop-filter: blur(20px);
  border-radius: 8px;
  margin-top: 4px !important;
  margin-left: 3px !important;
  .popper__arrow {
    display: none;
  }
  .el-dropdown-menu__item:not(.is-disabled):hover {
    background-color: transparent;
  }
}
</style>
