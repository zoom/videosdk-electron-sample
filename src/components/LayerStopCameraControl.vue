<template>
  <div class="camera-control">
    <div class="tip">
      Stop camera control?
    </div>
    <div class="right">
      <el-button type="danger" size="mini" class="btn-control btn-decline" @click="handleNotStop">Don't Stop</el-button>
      <el-button class="btn-control btn-approve" size="samll" @click="handleStop">Stop</el-button>
    </div>
  </div>
</template>

<script>
import { ZoomVideoSDKErrors } from '../../lib/zoom_video_sdk_defines'
const remote = window.require('@electron/remote')
const zoomVideoSdk = remote.app.zoomVideoSdk
const zoomVideoSDKRemoteCameraControl = zoomVideoSdk.getRemoteCameraControlHelper()

export default {
  props: ['controlledParticipant'],
  methods: {
    handleNotStop () {
      this.$emit('updateRemoteControlStatus', 'isStopCameraControlLayerShown', false)
    },
    handleStop () {
      let obj = {
        user: this.controlledParticipant
      }
      const ret = zoomVideoSDKRemoteCameraControl.giveUpControlRemoteCamera(obj)
      if (ret == ZoomVideoSDKErrors.ZoomVideoSDKErrors_Success) {
        this.$emit('updateRemoteControlStatus', 'isMeetingRemoteControlLayerShown', false)
        this.$emit('updateRemoteControlStatus', 'isStopCameraControlLayerShown', false)
        this.$emit('updateRemoteControlStatus', 'controlledParticipant', {})
        this.$emit('updateNotification', `You can no longer control ${this.controlledParticipant.username}'s camera because permissions have been revoked`)
      }
    }
  }
}
</script>

<style lang="scss" scoped>
  .camera-control {
    position: absolute;
    left: 50%;
    bottom: 50%;
    transform: translate(-50%, -50%);
    z-index: 10;
    width: 350px;
    padding: 24px;
    background: #242424;
    border: 0.5px solid rgba(0, 0, 0, 0.25);
    box-shadow: 0px 8px 24px rgba(0, 0, 0, 0.3);
    border-radius: 12px;
    position: relative;
    overflow: hidden;
    .tip {
      font-weight: 700;
      font-size: 16px;
      line-height: 24px;
      color: #F5F5F5;
    }
    .btn-control {
      border-radius: 8px;
      border: none;
      color: #fff;
      font-size: 14px;
      padding: 9px 16px;
      margin-top: 24px;
    }
    .btn-decline {
      background: #252A30;
    }
    .btn-approve {
      background: #E8173D;
    }
  }
</style>
