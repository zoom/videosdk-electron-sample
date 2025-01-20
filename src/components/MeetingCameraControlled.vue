<template>
  <div class="switch-camera">
    <el-popover
      ref="popover"
      placement="top-start"
      width="190"
      trigger="hover"
      popper-class="camera-controlled-popover"
      :content="`${requestControlUser.username} can now control your camera`">
    </el-popover>
    <IconMeetingCameraControlled v-popover:popover class="icon" />
  </div>
</template>

<script>
import IconMeetingCameraControlled from '../components/Icon/IconMeetingCameraControlled'
const remote = window.require('@electron/remote')
const zoomVideoSdk = remote.app.zoomVideoSdk

export default {
  props: ['requestControlUser'],
  data() {
    return {
      zoomVideoSDKVideo: zoomVideoSdk.getVideoHelper()
    }
  },
  components: {
    IconMeetingCameraControlled
  }
}
</script>

<style lang="scss" scoped>
.switch-camera {
  position: absolute;
  top: 38px;
  left: 8px;
}
</style>
<style lang="scss">
  .camera-controlled-popover {
    padding: 5px 8px !important;
    background: #131619;
    border: 1px solid #252A30;
    border-radius: 8px;
    color: #fff;
    font-size: 12px;
    word-break: keep-all;
    margin-top: 10px !important;
    .popper__arrow::after {
      border-bottom-color: #131619 !important;
    }
  }
</style>
