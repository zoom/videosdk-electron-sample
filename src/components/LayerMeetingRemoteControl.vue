<template>
  <div class="remote-control-layer">
    <div class="remote-control">
      <div class="left-section">
        <div class="close" @click="handleClose">
          <svg width="16" height="16" viewBox="0 0 16 16" fill="none" xmlns="http://www.w3.org/2000/svg">
          <path fill-rule="evenodd" clip-rule="evenodd" d="M12.1547 13.0381C12.3988 13.2822 12.7945 13.2822 13.0386 13.0381C13.2827 12.7941 13.2827 12.3983 13.0386 12.1543L8.88438 8L13.0386 3.84576C13.2827 3.60168 13.2827 3.20595 13.0386 2.96187C12.7945 2.71779 12.3988 2.71779 12.1547 2.96187L8.00049 7.11612L3.84624 2.96187C3.60216 2.71779 3.20643 2.71779 2.96236 2.96187C2.71828 3.20594 2.71828 3.60167 2.96236 3.84575L7.11661 8L2.96236 12.1543C2.71828 12.3983 2.71828 12.7941 2.96236 13.0381C3.20643 13.2822 3.60216 13.2822 3.84624 13.0381L8.00049 8.88389L12.1547 13.0381Z" fill="#FF5C5C"/>
          </svg>
        </div>
        <div class="zoom-control">
          <span @click="handleZoomIn">
            <svg width="16" height="16" viewBox="0 0 16 16" fill="none" xmlns="http://www.w3.org/2000/svg">
            <path fill-rule="evenodd" clip-rule="evenodd" d="M8.625 3C8.625 2.65482 8.34518 2.375 8 2.375C7.65482 2.375 7.375 2.65482 7.375 3V7.375H3C2.65482 7.375 2.375 7.65482 2.375 8C2.375 8.34518 2.65482 8.625 3 8.625H7.375V13C7.375 13.3452 7.65482 13.625 8 13.625C8.34518 13.625 8.625 13.3452 8.625 13V8.625H13C13.3452 8.625 13.625 8.34518 13.625 8C13.625 7.65482 13.3452 7.375 13 7.375H8.625V3Z" fill="white" fill-opacity="0.62"/>
            </svg>
          </span>
          <span @click="handleZoomOut">
            <svg width="16" height="16" viewBox="0 0 16 16" fill="none" xmlns="http://www.w3.org/2000/svg">
            <path fill-rule="evenodd" clip-rule="evenodd" d="M13.625 8C13.625 8.34518 13.3452 8.625 13 8.625H3C2.65482 8.625 2.375 8.34518 2.375 8C2.375 7.65482 2.65482 7.375 3 7.375H13C13.3452 7.375 13.625 7.65482 13.625 8Z" fill="white" fill-opacity="0.62"/>
            </svg>
          </span>
        </div> 
      </div>
      <div class="right-section">
        <svg width="76" height="76" viewBox="0 0 76 76" fill="none" xmlns="http://www.w3.org/2000/svg">
        <path fill-rule="evenodd" clip-rule="evenodd" d="M26 8C26 4.68629 28.6863 2 32 2H44C47.3137 2 50 4.68629 50 8V24C50 25.1046 50.8954 26 52 26H68C71.3137 26 74 28.6863 74 32V44C74 47.3137 71.3137 50 68 50H52C50.8954 50 50 50.8954 50 52V68C50 71.3137 47.3137 74 44 74H32C28.6863 74 26 71.3137 26 68V52C26 50.8954 25.1046 50 24 50H8C4.68629 50 2 47.3137 2 44V32C2 28.6863 4.68629 26 8 26H24C25.1046 26 26 25.1046 26 24V8ZM38 28C43.5228 28 48 32.4772 48 38C48 43.5228 43.5228 48 38 48C32.4772 48 28 43.5228 28 38C28 32.4772 32.4772 28 38 28Z" fill="white" fill-opacity="0.09"/>
        </svg>
        <span class="up" @click="handleTurnUp">
          <svg width="16" height="16" viewBox="0 0 16 16" fill="none" xmlns="http://www.w3.org/2000/svg">
          <path fill-rule="evenodd" clip-rule="evenodd" d="M3.55806 10.4419C3.31398 10.1979 3.31398 9.80214 3.55806 9.55806L7.55806 5.55806C7.80214 5.31398 8.19786 5.31398 8.44194 5.55806L12.4419 9.55806C12.686 9.80214 12.686 10.1979 12.4419 10.4419C12.1979 10.686 11.8021 10.686 11.5581 10.4419L8 6.88388L4.44194 10.4419C4.19786 10.686 3.80214 10.686 3.55806 10.4419Z" fill="white" fill-opacity="0.54"/>
          </svg>
        </span>
        <span class="down" @click="handleTurnDown">
          <svg width="16" height="16" viewBox="0 0 16 16" fill="none" xmlns="http://www.w3.org/2000/svg">
          <path fill-rule="evenodd" clip-rule="evenodd" d="M12.4419 5.55806C12.686 5.80214 12.686 6.19786 12.4419 6.44194L8.44194 10.4419C8.19786 10.686 7.80214 10.686 7.55806 10.4419L3.55806 6.44194C3.31398 6.19786 3.31398 5.80214 3.55806 5.55806C3.80214 5.31398 4.19786 5.31398 4.44194 5.55806L8 9.11612L11.5581 5.55806C11.8021 5.31398 12.1979 5.31398 12.4419 5.55806Z" fill="white" fill-opacity="0.8"/>
          </svg>
        </span>
        <span class="left" @click="handleTurnLeft">
          <svg width="16" height="16" viewBox="0 0 16 16" fill="none" xmlns="http://www.w3.org/2000/svg">
          <path fill-rule="evenodd" clip-rule="evenodd" d="M10.4419 12.4419C10.1979 12.686 9.80214 12.686 9.55806 12.4419L5.55806 8.44194C5.31398 8.19786 5.31398 7.80214 5.55806 7.55806L9.55806 3.55806C9.80214 3.31398 10.1979 3.31398 10.4419 3.55806C10.686 3.80214 10.686 4.19786 10.4419 4.44194L6.88388 8L10.4419 11.5581C10.686 11.8021 10.686 12.1979 10.4419 12.4419Z" fill="white" fill-opacity="0.8"/>
          </svg>
        </span>
        <span class="right" @click="handleTurnRight">
          <svg width="16" height="16" viewBox="0 0 16 16" fill="none" xmlns="http://www.w3.org/2000/svg">
          <path fill-rule="evenodd" clip-rule="evenodd" d="M5.55806 3.55806C5.80214 3.31398 6.19786 3.31398 6.44194 3.55806L10.4419 7.55806C10.686 7.80214 10.686 8.19786 10.4419 8.44194L6.44194 12.4419C6.19786 12.686 5.80214 12.686 5.55806 12.4419C5.31398 12.1979 5.31398 11.8021 5.55806 11.5581L9.11612 8L5.55806 4.44194C5.31398 4.19786 5.31398 3.80214 5.55806 3.55806Z" fill="white" fill-opacity="0.8"/>
          </svg>
        </span>
      </div> 
    </div>
  </div> 
</template>

<script>
import IconShareSwitchCamera from '../components/Icon/IconShareSwitchCamera'
const remote = window.require('@electron/remote')
const zoomVideoSdk = remote.app.zoomVideoSdk

export default {
  props: ['controlledParticipant'],
  data() {
    return {
      zoomVideoSDKRemoteCameraControl: zoomVideoSdk.getRemoteCameraControlHelper(),
      modifyRange: 50
    }
  },
  methods: {
    handleClose() {
      this.$emit('updateRemoteControlStatus', 'isStopCameraControlLayerShown', true)
    },
    handleTurnUp() {
      let params =  {
        user: this.controlledParticipant,
        range: this.modifyRange
      }
      this.zoomVideoSDKRemoteCameraControl.turnUp(params)
    },
    handleTurnDown() {
      let params =  {
        user: this.controlledParticipant,
        range: this.modifyRange
      }
      this.zoomVideoSDKRemoteCameraControl.turnDown(params)
    },
    handleTurnLeft() {
      let params =  {
        user: this.controlledParticipant,
        range: this.modifyRange
      }
      this.zoomVideoSDKRemoteCameraControl.turnLeft(params)
    },
    handleTurnRight() {
      let params =  {
        user: this.controlledParticipant,
        range: this.modifyRange
      }
      this.zoomVideoSDKRemoteCameraControl.turnRight(params)
    },
    handleZoomIn() {
      let params =  {
        user: this.controlledParticipant,
        range: this.modifyRange
      }
      this.zoomVideoSDKRemoteCameraControl.zoomIn(params)
    },
    handleZoomOut() {
      let params =  {
        user: this.controlledParticipant,
        range: this.modifyRange
      }
      this.zoomVideoSDKRemoteCameraControl.zoomOut(params)
    }
  },
  components: {
    IconShareSwitchCamera
  }
}
</script>

<style lang="scss" scoped>
.remote-control {
  display: flex;
  justify-content: space-between;
  align-items: center;
  width: 152px;
  height: 96px;
  background: rgba(0, 0, 0, 0.8);
  border: 1px solid rgba(255, 255, 255, 0.12);
  box-shadow: 0px 8px 24px rgba(0, 0, 0, 0.2);
  backdrop-filter: blur(20px);
  border-radius: 12px;
  padding: 8px;
  .left-section {
    height: 100%;
    position: relative;
    .close {
      width: 48px;
      height: 24px;
      background: rgba(255, 255, 255, 0.09);
      border-radius: 6px;
      display: flex;
      justify-content: center;
      align-items: center;
      cursor: pointer;
      &:hover {
        background: rgba(255, 255, 255, 0.18);
      }
      &:active {
        background: rgba(255, 255, 255, 0.27);
      }
    }
    .zoom-control {
      position: absolute;
      bottom: 0;
      width: 48px;
      display: flex;
      justify-content: center;
      background: rgba(255, 255, 255, 0.09);
      border-radius: 6px;
      span {
        width: 22px;
        height: 22px;
        border-radius: 5px;
        display: flex;
        justify-content: center;
        align-items: center;
        &:hover {
          background: rgba(255, 255, 255, 0.18);
        }
        &:active {
          background: rgba(255, 255, 255, 0.27);
        }
      }
    }
  }
  .right-section {
    width: 80px;
    height: 80px;
    background: rgba(26, 26, 26, 0.5);
    border-radius: 12px;
    display: flex;
    justify-content: center;
    align-items: center;
    position: relative;
    span {
      width: 20px;
      height: 20px;
      border-radius: 5px;
      display: flex;
      justify-content: center;
      align-items: center;
      position: absolute;
      cursor: pointer;
      &:hover {
        background: rgba(255, 255, 255, 0.18);
      }
      &:active {
        background: rgba(255, 255, 255, 0.27);
      }
    }
    .up {
      top: 6px;
      left: 30px;
    }
    .down {
      bottom: 6px;
      left: 30px;
    }
    .left {
      top: 30px;
      left: 6px;
    }
    .right {
      top: 30px;
      right: 6px;
    }
  }
}
</style>
