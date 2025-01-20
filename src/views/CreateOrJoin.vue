<template>
  <div class="outer">
    <div class="createing-content" v-if="creating">
      <div class="logo">
        <IconSDKLogo width="100" height="100" :animate="true" />
      </div>
      <div class="tip">
        <span v-if="type === 'Create'">creating…</span>  
        <span v-else>joining…</span>
      </div>
      <el-button class="btn-cancel" @click="handleCancel">Cancel</el-button>
    </div>
    <div v-else>
      <div class="start-header">
        <span class="right btn-close" @click="handleWindow('close')">
          <i class="el-icon-close"></i>
        </span>
      </div>
      <div class="content">
        <div class="title">{{type}} a Session</div>
        <el-form label-position="top" :model="form">
          <el-form-item label="Session Name" :error="sessionNameErrorMsg">
            <el-input v-model="form.sessionName" placeholder="Enter session name" @input="sessionNameErrorMsg=''"></el-input>
          </el-form-item>
          <el-form-item label="Your Name">
            <el-input v-model="form.username" maxlength="64" placeholder="Enter your name"></el-input>
          </el-form-item>
          <el-form-item label="Password (Optional)" v-if="!dialogVisible">
            <el-input v-model="form.sessionPassword" type="password" maxlength="10" placeholder="Enter password"></el-input>
          </el-form-item>
          <div class="checkbox-video">
            <el-checkbox v-model="form.isVideoMute">Turn off my video</el-checkbox>
          </div>
          <div>
            <el-checkbox v-model="form.mute">Mute my audio</el-checkbox>
          </div>
          <div class="btn-bottom">
            <span class="btn-back" @click="$router.push('/')">
              <i class="el-icon-arrow-left"></i> Back
            </span>
            <el-button type="info" disabled class="btn-start right btn-disabled" v-if="disabled">{{type}}</el-button>
            <el-button type="primary" class="btn-start right" @click="handleMeeting" v-else>{{type}}</el-button>
          </div>
        </el-form>
      </div>
    </div>
    <el-dialog
      :visible.sync="dialogVisible"
      title="Enter Password"
      :modal="showClose"
      :show-close="showClose"
      :close-on-click-modal="showClose"
      :close-on-press-escape="showClose"
      top="0"
      width="90%">
      <el-form :model="form">
        <el-form-item :error="passwordErrorMsg">
          <el-input class="layer-password" v-model="form.sessionPassword" type="password" size="medium" maxlength="10"
           @input="passwordErrorMsg=''" placeholder="Enter password"></el-input>
        </el-form-item>
      </el-form>
      <span slot="footer" class="dialog-footer">
        <el-button class="layer-password" size="medium" @click="cancelSessionPassword">Cancel</el-button>
        <el-button class="layer-password" :disabled="!form.sessionPassword" type="primary" size="medium" @click="handleSessionPassword">Continue</el-button>
      </span>
    </el-dialog>
  </div>
</template>

<script>
import { ZoomVideoSDKErrors } from '../../lib/zoom_video_sdk_defines'
import { Meeting_HandleCallbackEvents } from './Meeting_HandleCallbackEvents.js'
import IconSDKLogo from '../components/Icon/IconSDKLogo'
const { ipcRenderer: ipc } = window.require('electron')
const remote = window.require('@electron/remote')
const zoomVideoSdk = remote.app.zoomVideoSdk

export default {
  mixins: [Meeting_HandleCallbackEvents],
  data () {
    return {
      creating: false,
      form: {
        sessionName: '',
        username: '',
        sessionPassword: '',
        isVideoMute : false,
        mute: false,
        token: this.$store.state.token
      },
      disabled: true,
      type: this.$route.query.type ? this.$route.query.type : 'Create',
      showClose: false,
      dialogVisible: this.$route.query.needPassword || this.$route.query.passwordWrong ? true : false,
      isPasswordWrong: this.$route.query.passwordWrong,
      sessionNameErrorMsg: '',
      passwordErrorMsg: ''
    }
  },
  watch: {
    form: {
      handler (val, oldVal) {
        if (val.sessionName && val.username) {
          this.disabled = false
        } else {
          this.disabled = true
        }
      },
      deep: true
    }
  },
  methods: {
    handleCancel () {
      const obj = {
        bEnd: this.type === 'Create'
      }
      const ret = zoomVideoSdk.leaveSession(obj)
      console.log('leaveSession', ret)
      this.creating = false
    },
    handleWindow (val) {
      ipc.send(val)
    },
    handleMeeting () {
      this.creating = true
      const data = { ...this.form }
      data.localVideoOn = !this.form.isVideoMute
      const ret = zoomVideoSdk.joinSession(data)
      let toolbarStatus = {
        isVideoMute: this.form.isVideoMute,
        isAudioMute: this.form.mute
      }
      this.$store.commit('setToolbarStatus', toolbarStatus)
      this.$store.commit('setJoinSessionParams', this.form)
      console.log('joinSession', ret, data)
      if (ret === ZoomVideoSDKErrors.ZoomVideoSDKErrors_Success) {
        this.$router.push(`/meeting?type=${this.type}`)
      } else {
        this.creating = false
      }
    },
    cancelSessionPassword () {
      zoomVideoSdk.leaveSessionIgnorePassword()
      this.$router.push('/')
    },
    handleSessionPassword () {
      let data = {
        password: this.form.sessionPassword
      }
      zoomVideoSdk.inputSessionPassword(data)
      this.$router.push(`/meeting?type=${this.type}`)
    }
  },
  mounted () {
    if (this.dialogVisible) {
      this.form = this.$store.state.joinSessionParams
      if (this.isPasswordWrong) {
        this.passwordErrorMsg = 'Wrong password. Please enter again.'
      }
    }
  },
  components: {
    IconSDKLogo
  }
}
</script>

<style lang="scss" scoped>
  .outer {
    width: 100%;
    height: 100%;
    backdrop-filter: blur(45px);
    border-radius: 8px;
    .createing-content {
      width: 100px;
      position: absolute;
      left: 50%;
      transform: translateX(-50%);
      margin-top: 236px;
      .logo {
        width: 100px;
        height: 100px;
      }
      .tip {
        color: rgba(255, 255, 255, 0.8);
        font-size: 16px;
        text-align: center;
      }
      .btn-cancel {
        margin-top: 183px;
        width: 91px;
        position: relative;
        left: 50%;
        transform: translateX(-50%);
        color: #f5f5f5;
        background-color: transparent;
        border-color: #707070;
        border-radius: 10px;
      }
    }
    .start-header {
      -webkit-app-region: drag;
      height: 28px;
      color: #fff;
    }
    .content {
      width: 320px;
      position: absolute;
      top: 50%;
      left: 50%;
      transform: translate(-50%, -50%);
      .title {
        color: #fff;
        font-family: SF Pro Text;
        font-weight: bold;
        font-size: 28px;
        margin: 60px 0 31px;
      }
      .checkbox-video {
        margin: 5px 0 16px;
      }
      .el-select {
        width: 100%;
      }
      .btn-bottom {
        margin-top: 70px;
        overflow: auto;
        .btn-back {
          display: inline-block;
          color: #fff;
          font-size: 16px;
          line-height: 19px;
          margin-top: 10.5px;
          cursor: pointer;
        }
        .btn-start {
          border-radius: 10px;
        }
        .btn-disabled {
          cursor: not-allowed;
          background: rgba(255, 255, 255, 0.09);
          border-color: rgba(255, 255, 255, 0.09);
        }
      }
    }
    .layer-password {
      border-radius: 10px;
    }
  }
</style>
