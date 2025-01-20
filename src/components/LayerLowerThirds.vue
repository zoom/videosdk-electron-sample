<template>
  <div class="setting">
    <div class="title">
      Lower Thirds
      <i @click="parent.isLowerThirdsLayerShown=false" class="right icon-close el-icon-close"></i>
    </div>
    <div class="preview">
      <img src="../assets/images/preview.png" />
      <MeetingLowerThirds :userLowerThirdMap="[form.name, form.desc, colorList[activeIndex]]" />
    </div>
    <el-form label-position="top" size="small" ref="form" :model="form" :rules="rules">
      <el-form-item label="Your Name" prop="name">
        <el-input v-model="form.name" maxlength="20" placeholder="e.g. Username"></el-input>
      </el-form-item>
      <el-form-item label="Description">
        <el-input v-model="form.desc" maxlength="24" placeholder="e.g. Product Manager@Company"></el-input>
      </el-form-item>
      <el-form-item label="Brand Color">
        <ul class="color-group">
          <li v-for="(item, index) in colorList" :key="index" :style="{'background': item}"
            :class="{'color-active': activeIndex == index, 'black-border': index == 6}" @click="activeIndex=index">
            <IconLowerThirdsNoneColor v-if="index == 0" />
          </li>
        </ul>
      </el-form-item>
      <div class="btn-bottom right">
        <el-button type="primary" size="small" :disabled="!form.name" class="btn-start btn-disabled" @click="handleCmd">{{myLowerThird?'Update':'Save'}}</el-button>
        <el-button size="small" class="btn-cancel" @click="handleCancel">Cancel</el-button>
      </div>
    </el-form>
  </div>
</template>

<script>
import { CmdTypes } from '../assets/js/cmd_defines'
import IconLowerThirdsNoneColor from './Icon/IconLowerThirdsNoneColor'
import MeetingLowerThirds from '../components/MeetingLowerThirds'
const remote = window.require('@electron/remote')
const zoomVideoSdk = remote.app.zoomVideoSdk
const zoomVideoSDKCmd = zoomVideoSdk.getCmdHelper()
const zoomVideoSDKSessionInfo = zoomVideoSdk.getSessionInfo()

export default {
  props: ['parent'],
  data() {
    return {
      myselfInfo: zoomVideoSDKSessionInfo.getMyself(),
      form: {
        name: '',
        desc: ''
      },
      rules: {
        name: [
          { required: true, message: 'username is empty', trigger: 'change' }
        ]
      },
      colorList: ['#444B53', '#1E71D6', '#FD3D4A', '#66CC84', '#FF8422', '#493AB7', '#A477FF', '#FFBF39'],
      activeIndex: 0,
      myLowerThird: undefined
    }
  },
  methods: {
    handleCmd() {
      this.$refs.form.validate((valid) => {
        if (valid) {
          let strCmd = `${CmdTypes.cmd_lowerthird}|${this.form.name}|${this.form.desc}|${this.colorList[this.activeIndex]}`
          let sendCommand = zoomVideoSDKCmd.sendCommand({strCmd})
          this.parent.isLowerThirdsLayerShown = false
          let newLowerthird = {
            [this.myselfInfo.pUser]: [this.form.name, this.form.desc, this.colorList[this.activeIndex]]
          }
          let lowerThirdObj = {...this.$store.state.cmdLowerThirdMap, ...newLowerthird}
          this.$store.commit('setLowerThirdMap', lowerThirdObj)
          console.log('sendCommand', sendCommand, strCmd)
        } else {
          console.log('error submit!!');
          return false;
        }
      })
    },
    handleCancel() {
      this.parent.isLowerThirdsLayerShown = false
      this.parent.isSettingLayerShown = true
    }
  },
  mounted() {
    if (this.myselfInfo) {
      this.myLowerThird = this.$store.state.cmdLowerThirdMap[this.myselfInfo.pUser]
      if (this.myLowerThird) {
        this.form.name = this.myLowerThird[0]
        this.form.desc = this.myLowerThird[1]
        for (let index in this.colorList) {
          if (this.colorList[index] == this.myLowerThird[2]) {
            this.activeIndex = index
            break
          }
        }
      } else {
        this.form.name = this.myselfInfo.username
      }
    }
  },
  components: {
    IconLowerThirdsNoneColor,
    MeetingLowerThirds
  }
}
</script>

<style lang="scss" scoped>
  .setting {
    width: 350px;
    padding: 24px 24px 70px;
    background: #1A1A1A;
    border: 0.5px solid rgba(0, 0, 0, 0.25);
    box-shadow: 0px 8px 24px rgba(0, 0, 0, 0.3);
    border-radius: 12px;
    .title {
      font-weight: 500;
      font-size: 20px;
      line-height: 24px;
      color: #f5f5f5;
      margin-bottom: 16px;
      .icon-close {
        cursor: pointer;
      }
    }
    .preview {
      position: relative;
      img {
        width: 100%;
      }
    }
    .color-group {
      margin-top: 5px;
      display: flex;
      justify-content: space-between;
      li {
        width: 40px;
        height: 40px;
        border: 0.5px solid rgba(82, 82, 128, 0.09);
        box-sizing: border-box;
        border-radius: 50%;
        cursor: pointer;
        display: flex;
        justify-content: center;
        align-items:center;
      }
      .color-active {
        border: 2px solid #0E72ED !important;
      }
      .black-border {
        border: 1px solid rgba(255, 255, 255, 0.54);
      }
    }
    .btn-bottom {
      margin-top: 20px;
      button {
        color: #fff;
        border-radius: 8px;
      }
      .btn-cancel {
        background: rgba(255, 255, 255, 0.03);
      }
    }
  }
</style>
