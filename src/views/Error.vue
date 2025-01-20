<template>
  <div class="error">
    <div class="error-header">
      <span class="right btn-close" @click="handleWindow('close')">
        <i class="el-icon-close"></i>
      </span>
    </div>
    <div class="content">
      <div>
        Unable to {{type}} session. Please try again. <span v-if="errorCode">(Error Code: {{errorCode}})</span>
      </div>
      <el-button class="btn-ok" @click="$router.push('/')">OK</el-button>
    </div>
  </div>
</template>

<script>
const { ipcRenderer: ipc } = window.require('electron')

export default {
  data () {
    return {
      type: this.$route.query.type ? this.$route.query.type.toLowerCase() : 'create',
      errorCode: this.$route.query.errorCode
    }
  },
  methods: {
    handleWindow (val) {
      ipc.send(val)
    }
  }
}
</script>

<style lang="scss" scoped>
  .error {
    width: 100%;
    height: 100%;
    color: #fff;
    border-radius: 8px;
    .error-header {
      -webkit-app-region: drag;
      height: 28px;
      color: #fff;
    }
    .content {
      width: calc(100% - 80px);
      position: absolute;
      top: 50%;
      left: 50%;
      transform: translate(-50%, -50%);
      text-align: center;
      .btn-ok {
        margin-top: 50px;
        width: 72px;
        color: #f5f5f5;
        background-color: transparent;
        border-color: #707070;
        border-radius: 10px;
      }
    }
  }
</style>
