<template>
  <div id="app">
    <router-view></router-view>
  </div>
</template>

<script>
const remote = window.require('@electron/remote')
const { platform, arch } = remote.app
let nativeSdkPath, addon, renderAddon
try {
  switch (`${platform}:${arch}`) {
    case 'win32:ia32':
      nativeSdkPath = 'sdk/win32'
      break;
    case 'win32:x64':
      nativeSdkPath = 'sdk/win64'
      break;
    case 'darwin:x64': 
    case 'darwin:arm64':
      nativeSdkPath = 'sdk/mac'
      break;
    case 'linux:x64': 
      nativeSdkPath = 'sdk/linux'
      break;
  }
  require(`../${nativeSdkPath}/zoomvideosdk_napi_util.node`)
  addon = require(`../${nativeSdkPath}/zoomvideosdk_libuv.node`).exports()
  renderAddon = addon.GetVideoLibuvClientObj()
} catch (error) {
  console.log(error)
}
export default {
  name: 'app',
  mounted () {
    setTimeout(() => {
      const Start = renderAddon.Start()
      console.log('Start', Start)
    }, 500)
    this.$store.commit('setRenderAddon', renderAddon)
  },
  beforeDestroy () {
    const Stop = renderAddon.Stop()
    console.log('Stop', Stop)
  }
}
</script>

<style>
</style>
