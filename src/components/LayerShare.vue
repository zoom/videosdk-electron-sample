<template>
  <div :class="['share', isOtherUserSharing?'other-share':appsList.length>10?'share-max':'']" @mouseover="handleHover">
    <i @click="handleClose" class="icon-close el-icon-close"></i>
    <template v-if="isOtherUserSharing">
      <div class="tip">
        {{activeSharingUserName}} is sharing. You can not share now.
      </div>
      <div class="btn-group">
        <el-button class="btn btn-share" @click="handleShare(false)">OK</el-button>
      </div>
    </template>
    <template v-else>
      <div class="share-content">
        <div class="app-box">
          <template v-for="(item, index) in monitorsList">
            <div @click="handleApp(item, 'monitor')" :key="item.id" :class="['app-name', item.active?'app-active':'']">
              <img :src="item.src" /> 
              <div class="name">
                Desktop {{index + 1}}
              </div>
            </div>
          </template>
          <div @click="handleApp(secondCameraItem, 'camera')" :class="['app-name', secondCameraItem.active?'app-active':'']" v-if="canShareSecondCamera">
            <IconShareCameraActive v-if="secondCameraItem.active" />
            <IconShareCamera v-else />
            <div class="name">
              Content from 2nd Camera
            </div>
          </div>
        </div>
        <div class="app-box">
          <template v-for="(item, index) in appsList">
            <div v-if="item.shareAppHandle" :key="item.id" :class="['app-name', item.active?'app-active':'']" :title="item.shareAppName" @click="handleApp(item, 'app')">
              <img :src="item.src" /> 
              <div class="name">
                {{item.name}}
              </div>
            </div>
          </template>
        </div>
      </div>
      <div class="btn-group">
        <el-button class="btn" @click="handleShare(false)">Cancel</el-button>
        <el-button class="btn btn-share" type="primary" :disabled="!this.selectedObj.type" @click="handleShare(true)">Share</el-button>
      </div>
    </template>
  </div>
</template>

<script>
import IconShareCamera from './Icon/IconShareCamera'
import IconShareCameraActive from './Icon/IconShareCameraActive'
const remote = window.require('@electron/remote')
const zoomVideoSdk = remote.app.zoomVideoSdk

export default {
  props: ['isOtherUserSharing', 'appsList', 'monitorsList', 'activeSharingUserName'],
  data () {
    return {
      zoomVideoSDKVideo: zoomVideoSdk.getVideoHelper(),
      zoomVideoShare: zoomVideoSdk.getShareHelper(),
      selectedObj: {},
      secondCameraItem: {type: 'camera'},
      canShareSecondCamera: false
    }
  },
  methods: {
    handleHover () {
      this.$EventBus.$emit('change')
    },
    handleClose () {
      this.$emit('updateShareLayerStatus', false)
    },
    handleShare (val) {
      this.handleClose()
      if (val) {
        this.$EventBus.$emit('share', this.selectedObj)
      }
    },
    handleApp (item, type) {
      this.appsList.forEach(item => {
        this.$set(item, 'active', false)
      })
      this.monitorsList.forEach(item => {
        this.$set(item, 'active', false)
      })
      this.$set(this.secondCameraItem, 'active', false)
      this.$set(item, 'active', true)
      this.selectedObj = {
        item: item,
        type: type
      }
    }
  },
  mounted() {
    let cameraDeviceList = this.zoomVideoSDKVideo.getCameraList()
    if (cameraDeviceList && cameraDeviceList.length > 1) {
      this.canShareSecondCamera = true
    }
    if (!this.isOtherUserSharing) {
      this.handleApp(this.monitorsList[0], 'monitor')
    }
  },
  components: {
    IconShareCamera,
    IconShareCameraActive
  }
}
</script>

<style lang="scss" scoped>
  $colorPrimary: #0E72ED;
  .other-share {
    min-width: 320px !important;
    width: 320px;
  }
  .share-max {
    min-width: 772px;
  }
  .share {
    min-width: 530px;
    overflow: hidden;
    padding: 24px 27px;
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
      font-family: SF Pro Text;
      font-style: normal;
      font-weight: bold;
      font-size: 16px;
      line-height: 130%;
      color: #F5F5F5;
      margin-left: 5px;
    }
    .share-content {
      max-height: 300px;
      overflow-y: auto;
      &::-webkit-scrollbar {
        width: 6px;
      }
      &::-webkit-scrollbar-thumb {
        background-color: #c2c2c2;
        border-radius:6px;
      }
      .app-box {
        display: flex;
        flex-wrap: wrap;
        margin: 5px 0;
        .app-name {
          display: inline-block;
          font-size: 13px;
          line-height: 16px;
          text-align: center;
          color: rgba(255, 255, 255, 0.54);
          border: 1px solid #707070;
          box-sizing: border-box;
          border-radius: 8px;
          padding: 10px;
          margin: 5px 5px 0 5px;
          width: calc(33.3% - 10px);
          overflow: hidden;
          text-overflow:ellipsis;
          white-space: nowrap;
          cursor: pointer;
          position: relative;
          &:nth-of-type(3n) {
            margin: 5px 5px 0 0;
          }
          img {
            width: 100%;
            margin-bottom: 8px;
          }
          .name {
            font-size: 12px;
            max-width: 90%;
            position: absolute;
            bottom: 2px;
            left: 50%;
            transform: translateX(-50%);
            text-align: center;
            overflow: hidden;
            text-overflow:ellipsis;
            white-space: nowrap;
          }
        }
        .app-active {
          color: #fff;
          background: #0E71EB;
          border: 1px solid #0E71EB;
        }
      }
    }
    .btn-group {
      display: flex;
      float: right;
      margin-top: 32px;
    }
    .btn {
      width: 78px;
      height: 32px;
      background: transparent;
      border: 1px solid #707070;
      box-sizing: border-box;
      border-radius: 8px;
      font-family: SF Pro Text;
      font-weight: normal;
      font-size: 14px;
      line-height: 17px;
      text-align: center;
      color: #F5F5F5;
      padding: 0em;
    }
    .btn-share {
      font-weight: bold;
      line-height: 16px;
      color: #FFFFFF;
      border: none;
      background: $colorPrimary;
      margin-left: 16px;
    }
  }
</style>
