<template>
  <div class="switch-camera">
    <el-dropdown @visible-change="handleVisible" @command="handleCommand" placement="bottom">
      <span class="el-dropdown-link">
        <IconMeetingParticipantsMore class="icon" />
      </span>
      <el-dropdown-menu class="participant-dropdown" slot="dropdown">
        <el-dropdown-item command="stopCameraControl" class="stop-camera-control" v-if="participant.user.pUser==controlledParticipant.pUser">Stop Camera Control</el-dropdown-item>
        <el-dropdown-item command="requestCameraControl" v-else-if="participant.user.pUser!=myselfInfo.pUser">Request Camera Control</el-dropdown-item>
        <el-dropdown-item command="remove" v-if="isCanRemoveParticipant">Remove</el-dropdown-item>
      </el-dropdown-menu>
    </el-dropdown>
  </div>
</template>

<script>
import IconMeetingParticipantsMore from '../components/Icon/IconMeetingParticipantsMore'
import { ZoomVideoSDKErrors } from '../../lib/zoom_video_sdk_defines'
const remote = window.require('@electron/remote')
const zoomVideoSdk = remote.app.zoomVideoSdk
const zoomVideoSDKSessionInfo = zoomVideoSdk.getSessionInfo()

export default {
  props: ['participant', 'controlledParticipant'],
  data() {
    return {
      zoomVideoSDKRemoteCameraControl: zoomVideoSdk.getRemoteCameraControlHelper(),
      zoomVideoSDKUser: zoomVideoSdk.getUserHelper(),
      myselfInfo: {}
    }
  },
  computed: {
    isCanRemoveParticipant () {
      if ((this.myselfInfo.isHost || this.myselfInfo.isManager) 
          && this.participant.user.pUser != this.myselfInfo.pUser
          && !this.participant.user.isHost
          && !this.participant.user.isManager
        ) {
        return true
      } else {
        return false
      }
    }
  },
  methods: {
    handleVisible(visible) {
      if (visible) {
        this.myselfInfo = zoomVideoSDKSessionInfo.getMyself()
      }
    },
    handleCommand(command) {
      switch (command) {
        case 'requestCameraControl':
          const requestControlRemoteCamera = this.zoomVideoSDKRemoteCameraControl.requestControlRemoteCamera(this.participant)
          if (requestControlRemoteCamera == ZoomVideoSDKErrors.ZoomVideoSDKErrors_Success) {
            this.$emit('changeRemoteControlShown', true, this.participant)
          }
          break
        case 'stopCameraControl':
          this.$emit('changeRemoteControlShown', false, {})
          break
        case 'remove':
          this.zoomVideoSDKUser.removeUser(this.participant)
          break
      }
    }
  },
  components: {
    IconMeetingParticipantsMore
  }
}
</script>

<style lang="scss" scoped>
.switch-camera {
  position: absolute;
  top: 3px;
  right: 3px;
  .el-dropdown-link {
    overflow: hidden;
    cursor: pointer;
  }
}
</style>
<style lang="scss">
.participant-dropdown {
  color: rgba(255, 255, 255, 0.8);
  background: rgba(0, 0, 0, 0.8);
  border: 1px solid rgba(255, 255, 255, 0.12);
  box-shadow: 0px 8px 24px rgba(0, 0, 0, 0.3);
  backdrop-filter: blur(20px);
  border-radius: 8px;
  margin-top: 0px !important;
  margin-right: 6px !important;
  .popper__arrow {
    display: none;
  }
  .el-dropdown-menu__item {
    color: rgba(255, 255, 255, 0.8);
    &:not(.is-disabled):hover {
      background-color: transparent;
    }
  }
  .stop-camera-control {
    color: #ED4D6A;
  }
}
</style>
