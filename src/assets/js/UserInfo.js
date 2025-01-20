import { ZoomVideoSDKShareStatus } from '../../../lib/zoom_video_sdk_defines'
import { getAvatarName } from './util'

class UserInfo {
  constructor(user, color) {
    this.user = user
    this.avatarName = getAvatarName(user.username)
    this.color = color
    this.isVideoOn = false
    this.isAudioMuted = false
    this.isSharing = false
    this.statusText = ''
  }

  setColor (color) {
    this.color = color
  }
  
  setVideoStatus (isVideoOn) {
    this.isVideoOn = isVideoOn
  }
  
  setAudioStatus (isAudioMuted) {
    this.isAudioMuted = isAudioMuted
  }
  
  setShareStatus (shareStatus) { 
    switch (shareStatus) {
      case ZoomVideoSDKShareStatus.ZoomVideoSDKShareStatus_Start: case ZoomVideoSDKShareStatus.ZoomVideoSDKShareStatus_Resume:
        this.isSharing = true
        this.statusText = 'is sharing'
        break;
      case ZoomVideoSDKShareStatus.ZoomVideoSDKShareStatus_Pause:
        this.isSharing = true
        this.statusText = 'pause share'
        break;
      default:
        this.isSharing = false
        this.statusText = ''
        break;
    }
  }
}
 
export default UserInfo