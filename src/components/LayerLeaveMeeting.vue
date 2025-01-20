<template>
  <div class="leave">
    <i @click="parent.isLeaveMeetingLayerShown=false" class="icon-close el-icon-close"></i>
    <div class="tip">
      Do you want to leave this session?
    </div>
    <div v-if="myselfInfo.isHost">
      <el-button type="danger" class="btn-max btn-end" @click="handleLeave(true)">End Session for All</el-button>
    </div>
    <div>
      <el-button class="btn-max btn-leave" @click="handleLeave(false)">Leave Session</el-button>
    </div>
  </div>
</template>

<script>
const { ipcRenderer: ipc } = window.require('electron')
const remote = window.require('@electron/remote')

export default {
  props: ['parent', 'myselfInfo'],
  methods: {
    handleLeave (val) {
      const obj = {
        bEnd: val
      }
      const zoomVideoSdk = remote.app.zoomVideoSdk
      const ret = zoomVideoSdk.leaveSession(obj)
      console.log('leaveSession', ret)
      if (ret === 0) {
        ipc.send('stop-share')
      }
    }
  }
}
</script>

<style lang="scss" scoped>
  $colorPrimary: #0E72ED;
  .leave {
    width: 232px;
    padding: 24px;
    background: #242424;
    border: 0.5px solid rgba(0, 0, 0, 0.25);
    box-shadow: 0px 8px 24px rgba(0, 0, 0, 0.3);
    border-radius: 12px;
    position: relative;
    .el-icon-close {
      color: #F5F5F5;
      position: absolute;
      top: 11.4px;
      right: 11.4px;
      cursor: pointer;
    }
    .tip {
      font-weight: bold;
      font-size: 16px;
      height: 42px;
      line-height: 130%;
      color: #F5F5F5;
      word-spacing: 1px;
    }
    .btn-max {
      width: 100%;
      border-radius: 8px;
      border: none;
      color: #fff;
      font-weight: bold;
      font-size: 14px;
      margin-top: 12px;
    }
    .btn-end {
      background: #DE2828;
    }
    .btn-leave {
      background: $colorPrimary;
    }
  }
</style>
