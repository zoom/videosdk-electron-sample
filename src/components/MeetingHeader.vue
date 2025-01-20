<template>
  <div class="header">
    <div class="left-drag"></div>
    <div class="right-drag"></div>
    <div class="icon">
      <svg width="16" height="16" class="el-icon-header" @click="handleClose" viewBox="0 0 16 16" fill="none" xmlns="http://www.w3.org/2000/svg">
      <path fill-rule="evenodd" clip-rule="evenodd" d="M12.1543 13.0381C12.3983 13.2822 12.7941 13.2822 13.0381 13.0381C13.2822 12.7941 13.2822 12.3983 13.0381 12.1543L8.88389 8L13.0381 3.84576C13.2822 3.60168 13.2822 3.20595 13.0381 2.96187C12.7941 2.71779 12.3983 2.71779 12.1543 2.96187L8.00001 7.11612L3.84575 2.96187C3.60167 2.71779 3.20595 2.71779 2.96187 2.96187C2.71779 3.20594 2.71779 3.60167 2.96187 3.84575L7.11612 8L2.96187 12.1543C2.71779 12.3983 2.71779 12.7941 2.96187 13.0381C3.20594 13.2822 3.60167 13.2822 3.84575 13.0381L8.00001 8.88389L12.1543 13.0381Z" fill="white" fill-opacity="0.54"/>
      </svg>
      <svg width="16" height="16" class="el-icon-header" @click="handleWindow('min')" viewBox="0 0 16 16" fill="none" xmlns="http://www.w3.org/2000/svg">
      <path fill-rule="evenodd" clip-rule="evenodd" d="M13.625 8C13.625 8.34518 13.3452 8.625 13 8.625H3C2.65482 8.625 2.375 8.34518 2.375 8C2.375 7.65482 2.65482 7.375 3 7.375H13C13.3452 7.375 13.625 7.65482 13.625 8Z" fill="white" fill-opacity="0.54"/>
      </svg>
    </div>
    <div class="dropdown" v-if="sessionName">
      <el-dropdown trigger="click">
        <span class="el-dropdown-link">
          {{sessionName}}<i class="el-icon-arrow-down el-icon--right"></i>
        </span>
        <el-dropdown-menu :class="['meeting-header-dropdown',isParticipantsVideoShown?'dropdown-min':'dropdown-max']" slot="dropdown">
          <el-dropdown-item><span class="dropdown-title">Session Name</span>{{sessionName}}</el-dropdown-item>
          <el-dropdown-item v-if="sessionPassword"><span class="dropdown-title">Password</span>{{sessionPassword}}</el-dropdown-item>
          <el-dropdown-item><span class="dropdown-title">Participants</span>{{liveOnNum}}</el-dropdown-item>
        </el-dropdown-menu>
      </el-dropdown>
    </div>
    <div class="right">
      <div class="icon icon-right">
        <span class="time">{{dateTime}}</span>
        <div class="scale right" @click="handleWindow('toggle')" >
          <svg width="16" height="16" viewBox="0 0 16 16" fill="none" xmlns="http://www.w3.org/2000/svg">
          <path d="M10 2H14M14 2V6M14 2L9.33333 6.66667M6 14H2M2 14V10M2 14L6.66667 9.33333" stroke="white" stroke-opacity="0.62" stroke-width="1.25" stroke-linecap="round" stroke-linejoin="round"/>
          </svg>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
const { ipcRenderer: ipc } = window.require('electron')
const remote = window.require('@electron/remote')
const zoomVideoSdk = remote.app.zoomVideoSdk

export default {
  props: ['isParticipantsVideoShown', 'isInSession', 'liveOnNum'],
  data () {
    return {
      dateTime: '',
      timer: null,
      path: this.$route.path,
      sessionName: '',
      sessionPassword: ''
    }
  },
  watch: {
    isInSession: {
      handler (val, objVal) {
        if (val) {
          let sessionInfo = zoomVideoSdk.getSessionInfo()
          this.sessionName = sessionInfo.getSessionName()
          this.sessionPassword = sessionInfo.getSessionPassword()
        }
      }
    }
  },
  methods: {
    handleClose () {
      if (!this.isInSession) {
        ipc.send('close')
      } else {
        this.$EventBus.$emit('close')
      }
    },
    handleWindow (val) {
      ipc.send(val)
    },
    getDateTime () {
      var date = new Date()
      var hours = date.getHours()
      var minute = date.getMinutes()
      this.dateTime = this.formatTime(hours) + ':' + this.formatTime(minute)
    },
    formatTime (str) {
      return str > 9 ? str : '0' + str
    }
  },
  created () {
    this.getDateTime()
    this.timer = setInterval(() => {
      this.getDateTime()
    }, 1000)
  },
  beforeDestroy () {
    clearInterval(this.timer)
  }
}
</script>

<style lang="scss" scoped>
  $colorPrimary: #0E72ED;
  .header {
    -webkit-app-region: drag;
    width: 100%;
    height: 36px;
    font-size: 12px;
    color: #fff;
    background: linear-gradient(180deg, rgba(0, 0, 0, 0.24) 0%, rgba(0, 0, 0, 0) 100%);
    overflow: hidden;
    position: relative;
    .left-drag, .right-drag{
      -webkit-app-region:no-drag;
      height: 20px;
      width: 50px;
      position: absolute;
      top: 0;
    }
    .left-drag{
      left:0;
    }
    .right-drag{
      right:0;
    }
    div {
      display: inline-block;
    }
    .icon {
      -webkit-app-region: no-drag;
      width: 52px;
      height: 22px;
      margin: 9px 8px 0;
      background: rgba(26, 26, 26, 0.8);
      border: 1px solid rgba(255, 255, 255, 0.09);
      backdrop-filter: blur(16px);
      border-radius: 6px;
      display: inline-block;
      cursor: pointer;
      .el-icon-header {
        margin: 3px 5px;
      }
    }
    .icon-right {
      width: 73px;
      .time {
        display: inline-block;
        width: calc(100% - 31px);
        text-align: center;
        line-height: 22px;
        font-size: 12px;
        color: rgba(255, 255, 255, 0.62);
      }
      .scale {
        display: inline-block;
        height: 100%;
        border-left: 1px solid rgba(255, 255, 255, 0.09);
        svg {
          margin: 3px 5px 3px 7px;
        }
      }
    }
    .dropdown {
      -webkit-app-region: no-drag;
      position: absolute;
      left: 50%;
      transform: translateX(-50%);
      line-height: 22px;
      .el-dropdown-link {
        outline: none;
        height: 22px;
        margin-top: 9px;
        padding: 0 7px;
        background: rgba(26, 26, 26, 0.8);
        border: 1px solid rgba(255, 255, 255, 0.09);
        backdrop-filter: blur(16px);
        border-radius: 6px;
        display: inline-block;
      }
    }
  }
</style>
<style lang="scss">
  .header {
    .dropdown {
      .el-dropdown {
        font-size: 12px;
        color: #fff;
        cursor: pointer;
        outline: none;
        text-shadow: 0px 0px 2px rgba(0, 0, 0, 0.45);
      }
    }
  }
  .meeting-header-dropdown.el-dropdown-menu {
    width: 240px;
    outline: none;
    background-color: rgba(26, 26, 26, 0.8) !important;
    backdrop-filter: blur(4px) !important;
    border-radius: 12px !important;
    border: none !important;
    top: 25px !important;
    left: calc(50% - 72px) !important;
    .popper__arrow {
      left: 50% !important;
      &::after {
        border-bottom-color: rgba(26, 26, 26, 0.8) !important;
      }
    }
    .el-dropdown-menu__item {
      cursor: default;
      color: #F5F5F5;
      font-size: 12px;
      line-height: 30px;
      .dropdown-title {
        display: inline-block;
        width: 99px;
        color: rgba(255, 255, 255, 0.54);
      }
    }
    .el-dropdown-menu__item:not(.is-disabled):hover {
      background-color: transparent;
      color: #F5F5F5;
    }
  }
  .meeting-header-dropdown.dropdown-min {
    left: calc(50% - 195px) !important;
  }
  .meeting-header-dropdown.dropdown-max {
    left: calc(50% - 107px) !important;
  } 
  .el-popper[x-placement^="bottom"] {
    margin-top: 16px;
    .popper__arrow {
      top: -7px !important;
      border-bottom-color: transparent !important;
    }
  }
</style>
