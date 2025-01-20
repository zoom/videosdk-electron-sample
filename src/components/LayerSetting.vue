<template>
  <div>
    <div class="setting" @click="handleSetLayer">
      <div class="title">
        Session Settings
        <i @click="parent.isSettingLayerShown=false" class="right icon-close el-icon-close"></i>
      </div>
      <el-form label-position="top" :model="form" :rules="rules" ref="form" size="small">
        <el-form-item label="Camera">
          <el-select
            class="select-max"
            v-model="form.cameraDevice"
            placeholder="Select Camera"
            no-data-text="No Data"
            @focus="handleSetLayer"
            @change="handleCamera"
          >
            <el-option
              v-for="item in cameraOptions"
              :key="item.deviceID"
              :label="item.deviceName"
              :value="item.deviceID"
            ></el-option>
          </el-select>
          <div class="setting-checkbox">
            <el-checkbox v-model="form.isFillScreen" @change="handleFill">Fill my video to frame</el-checkbox>
          </div>
          <div class="setting-checkbox">
            <el-checkbox v-model="form.lowerThird" @change="handleLowerThird">Enable lower third</el-checkbox>
            <el-button type="text" class="right" @click="handleCustomLowerThird">Custom Lower Third</el-button>
          </div>
        </el-form-item>
        <el-form-item label="Speaker">
          <el-select
            class="select-max"
            v-model="form.speakerDevice"
            placeholder="Select Speaker"
            no-data-text="No Data"
            @focus="handleSetLayer"
            @change="handleSpeaker"
          >
            <el-option
              v-for="item in speakerOptions"
              :key="item.deviceID"
              :label="item.deviceName"
              :value="item.deviceID"
            ></el-option>
          </el-select>
        </el-form-item>
        <el-form-item label="Microphone">
          <el-select
            class="select-max"
            v-model="form.micDevice"
            placeholder="Select Microphone"
            no-data-text="No Data"
            @focus="handleSetLayer"
            @change="handleMic"
          >
            <el-option
              v-for="item in micOptions"
              :key="item.deviceID"
              :label="item.deviceName"
              :value="item.deviceID"
            ></el-option>
          </el-select>
        </el-form-item>
        <el-form-item v-if="!from || from != 'index'">
          <el-button type="primary" size="mini" class="btn-statistical" @click="handleStatistical">Show Statistics</el-button>
        </el-form-item>
        <template v-if="from && from == 'index'">
          <el-form-item label="Token" prop="token">
            <el-input v-model="form.token" placeholder="Enter Token" @change="handleToken"></el-input>
          </el-form-item>
        </template>
      </el-form>
    </div>
  </div>
</template>

<script>
const remote = window.require('@electron/remote')
const zoomVideoSdk = remote.app.zoomVideoSdk

export default {
  props: ['parent', 'from'],
  data() {
    return {
      zoomVideoSDKVideo: zoomVideoSdk.getVideoHelper(),
      zoomVideoSDKAudio: zoomVideoSdk.getAudioHelper(),
      form: {
        cameraDevice: '',
        isFillScreen: this.$store.state.isFillScreen,
        lowerThird: this.$store.state.isLowerThird,
        speakerDevice: '',
        micDevice: '',
        token: this.$store.state.token,
        showStatistic: false
      },
      rules: {
        token: [
          { required: true, message: 'token is empty', trigger: 'change' }
        ]
       },
      cameraOptions: [],
      speakerOptions: [],
      micOptions: []
    }
  },
  methods: {
    handleSetLayer () {
      this.$EventBus.$emit('change')
    },
    handleCamera () {
      this.$EventBus.$emit('change')
      const obj = {
        deviceID: this.form.cameraDevice
      }
      const selectCamera = this.zoomVideoSDKVideo.selectCamera(obj)
    },
    handleFill () {
      this.$store.commit('setFillScreen', this.form.isFillScreen)
      this.$EventBus.$emit('change')
    },
    handleLowerThird () {
      this.$store.commit('setLowerThird', this.form.lowerThird)
      this.$EventBus.$emit('change')
    },
    handleCustomLowerThird () {
      this.parent.isSettingLayerShown = false
      this.parent.isLowerThirdsLayerShown = true
    },
    handleStatistical () {
      this.$EventBus.$emit('showStatisticLayer')
      this.$EventBus.$emit('change')
      this.parent.isSettingLayerShown = false
    },
    handleSpeaker () {
      this.$EventBus.$emit('change')
      let obj = {}
      obj = this.speakerOptions.find((item) => {
        return item.deviceID === this.form.speakerDevice
      })
      const selectSpeaker = this.zoomVideoSDKAudio.selectSpeaker(obj)
    },
    handleMic () {
      this.$EventBus.$emit('change')
      let obj = {}
      obj = this.micOptions.find((item) => {
        return item.deviceID === this.form.micDevice
      })
      const selectMic = this.zoomVideoSDKAudio.selectMic(obj)
    },
    handleToken () {
      this.$store.commit('setToken', this.form.token)
    }
  },
  mounted () {
    if (this.from == 'index') {
      this.$nextTick(() => {
        this.$refs.form.validate((valid) => {
          if (!valid) {
            return false;
          }
        });
      })
    }
    this.cameraOptions = this.zoomVideoSDKVideo.getCameraList()
    for (let val of this.cameraOptions) {
      if (val.isSelectedDevice) {
        this.form.cameraDevice = val.deviceID
        break
      }
    }
    this.speakerOptions = this.zoomVideoSDKAudio.getSpeakerList()
    for (let val of this.speakerOptions) {
      if (val.isSelectedDevice) {
        this.form.speakerDevice = val.deviceID
        break
      }
    }
    this.micOptions = this.zoomVideoSDKAudio.getMicList()
    for (let val of this.micOptions) {
      if (val.isSelectedDevice) {
        this.form.micDevice = val.deviceID
        break
      }
    }
  }
}
</script>

<style lang="scss" scoped>
  .setting {
    width: 266px;
    padding: 16px;
    background: #242424;
    border: 0.5px solid rgba(0, 0, 0, 0.25);
    box-shadow: 0px 8px 24px rgba(0, 0, 0, 0.3);
    border-radius: 12px;
    .title {
      font-weight: bold;
      font-size: 16px;
      line-height: 16px;
      color: #f5f5f5;
      margin-bottom: 16px;
      .icon-close {
        cursor: pointer;
      }
    }
    .select-max {
      width: 100%;
    }
    .setting-checkbox {
      margin-top: 8px;
      .el-button--text {
        padding: 0;
        line-height: 20px;
      }
    }
    .form-item {
      height: 32px;
      display: flex;
      align-items: center;
    }
    .btn-statistical {
      border-radius: 8px;
    }
  }
</style>
<style lang="scss">
  .setting {
    align-items: center;
    .el-form-item {
      margin-bottom: 16px !important;
      &:last-child {
        margin-bottom: 0 !important;
      }
    }
    .el-checkbox,
    .el-checkbox__input.is-checked + .el-checkbox__label {
      color: #f5f5f5;
    }
    .el-form-item--small .el-form-item__content {
      line-height: 16px;
    }
    .el-form-item__label {
      font-size: 12px;
      line-height: 22px !important;
      color: rgba(255, 255, 255, 0.54);
    }
    .el-form--label-top .el-form-item__label {
      padding-bottom: 0px;
    }
    .el-input__inner {
      color: #f5f5f5;
      background: transparent;
      border-radius: 8px;
    }
  }
</style>
