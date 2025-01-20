<template>
  <div class="index-wrap">
    <div class="index-header">
      <span class="btn-close" @click="isSettingLayerShown=!isSettingLayerShown">
        <i class="el-icon-s-tools"></i>
      </span>
      <span class="right btn-close" @click="handleWindow('close')">
        <i class="el-icon-close"></i>
      </span>
    </div>
    <div class="content">
      <div class="logo">
        <IconSDKLogo width="200" height="200" :animate="false" />
      </div>
      <div>
        <el-button type="primary" class="btn-start btn-create" @click="handleSession('Create')">Create a Session</el-button>
      </div>
      <div>
        <el-button class="btn-start btn-join" @click="handleSession('Join')">Join a Session</el-button>
      </div>
    </div>
    <div class="version">
      Version: {{SDKVersion}}
    </div>
    <div class="setting-layer" v-if="isSettingLayerShown">
      <LayerSetting :parent="this" from="index" />
    </div>
    <div class="setting-layer" v-if="isLowerThirdsLayerShown">
      <LayerLowerThirds :parent="this" />
    </div>
  </div>
</template>

<script>
import IconSDKLogo from '../components/Icon/IconSDKLogo'
import LayerSetting from '../components/LayerSetting'
import LayerLowerThirds from '../components/LayerLowerThirds'
const { ipcRenderer: ipc } = window.require('electron')
const remote = window.require('@electron/remote')
const zoomVideoSdk = remote.app.zoomVideoSdk

export default {
  data () {
    return {
      isSettingLayerShown: false,
      isLowerThirdsLayerShown: false,
      SDKVersion: ''
    }
  },
  methods: {
    handleWindow (val) {
      ipc.send(val)
    },
    handleSession(val) {
      if (!this.$store.state.token) {
        this.isSettingLayerShown = true
        return
      }
      this.$router.push(`/create?type=${val}`)
    }
  },
  mounted () {
    this.SDKVersion = zoomVideoSdk.getSDKVersion()
  },
  components: {
    IconSDKLogo,
    LayerSetting,
    LayerLowerThirds
  }
}
</script>

<style lang="scss" scoped>
  $colorPrimary: #0E72ED;
  .index-wrap {
    width: 100%;
    height: 100%;
    border-radius: 8px;
    .toast {
      z-index: 100;
    }
    .index-header {
      -webkit-app-region: drag;
      height: 28px;
      color: #fff;
    }
    .content {
      width: 240px;
      position: absolute;
      top: 50%;
      left: 50%;
      transform: translate(-50%, -50%);
      .logo {
        text-align: center;
        margin: 0 auto 60px;
      }
      .btn-start {
        width: 100%;
        border-radius: 10px;
        margin-top: 24px;
      }
      .btn-create {
        background-color: $colorPrimary;
      }
      .btn-join {
        color: #F5F5F5;
        border-color: #707070;
        background-color: transparent;
      }
    }
    .version {
      font-size: 13px;
      line-height: 17px;
      text-align: center;
      letter-spacing: 0.25px;
      color: rgba(255, 255, 255, 0.54);
      position: absolute;
      bottom: 32px;
      left: 50%;
      transform: translateX(-50%);
    }
    .setting-layer {
      position: relative;
      top: 5px;
      left: 9px;
    }
  }
</style>
