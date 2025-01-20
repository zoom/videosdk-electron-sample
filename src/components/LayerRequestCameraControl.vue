<template>
  <div class="camera-control">
    <div class="tip">
      {{requestControlUser.username}} is requesting control of your camera
    </div>
    <div class="right">
      <el-button type="danger" size="mini" class="btn-control btn-decline" @click="handleDecline">Decline</el-button>
      <el-button class="btn-control btn-approve" size="samll" @click="handleApprove">Approve</el-button>
    </div>
  </div>
</template>

<script>
const remote = window.require('@electron/remote')
const zoomVideoSdk = remote.app.zoomVideoSdk
const zoomVideoCameraControlRequest = zoomVideoSdk.getCameraControlRequestHelper()

export default {
  props: ['requestControlUser'],
  methods: {
    handleDecline () {
      zoomVideoCameraControlRequest.decline()
      this.$emit('updateRemoteControlStatus', 'isCameraControlled', false)
      this.$emit('updateRemoteControlStatus', 'isRequestCameraControlLayerShown', false)
    },
    handleApprove () {
      zoomVideoCameraControlRequest.approve()
      this.$emit('updateRemoteControlStatus', 'isCameraControlled', true)
      this.$emit('updateRemoteControlStatus', 'isRequestCameraControlLayerShown', false)
    }
  }
}
</script>

<style lang="scss" scoped>
  $colorPrimary: #0E72ED;
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
      background: $colorPrimary;
    }
  }
</style>
