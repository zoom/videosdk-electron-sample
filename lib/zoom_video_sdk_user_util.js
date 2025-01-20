import { ZoomVideoSDKErrors } from './zoom_video_sdk_defines.js'
import messages from './electron_zoomvideosdk_pb.js'

export function setUserInfo (data) {
  try {
    const VideoSDKUser = new messages.VideoSDKUser()
    VideoSDKUser.setPUser(data.pUser)
    return VideoSDKUser
  } catch (error) {
    return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
  }
}

export function getUserInfo (data) {
  try {
    let userObj = {}
    let message = data
    let shareActionList = []
    if (message.getZnShareactionlist()) {
      const shareActionProtoList = message.getZnShareactionlist().getShareactionList() // A list of all share information.
      for (let item of shareActionProtoList) {
        const obj = {
          shareSourceId: item.getSharesourceid(), // The user ID of the user object.
          shareStatus: item.getSharestatus(),
          subscribeFailReason: item.getSubscribefailreason(),
          isAnnotationPrivilegeEnabled: item.getIsannotationprivilegeenabled(),
          shareType: item.getSharetype()
        }
        shareActionList.push(obj)
      }
    }
    userObj.pUser = message.getPUser()
    userObj.custom_identity = message.getCustomIdentity() // The Custom id of the user object.
    userObj.username = data.getUsername() // The name of the user object.
    userObj.userReference = data.getUserreference() // user's reference info.
    userObj.isHasVideoDevice = message.getIshasvideodevice()
    userObj.isVideoOn = message.getIsvideoon()
    userObj.audioType = message.getAudiotype()
    userObj.isAudioMuted = message.getIsaudiomuted()
    userObj.isAudioTalking = message.getIsaudiotalking()
    userObj.shareActionList = shareActionList
    userObj.isHost = message.getIshost() // True indicates that the user is the host, otherwise false.
    userObj.isManager = message.getIsmanager() // True indicates that the user is the manager(coHost), otherwise false.
    userObj.isVideoSpotLighted = message.getIsvideospotlighted() // True indicates that the user is spotLighted, otherwise false.
    userObj.isIncomingLiveStreamUser = message.getIsincominglivestreamuser() // True indicates that the user is an incoming live stream user, otherwise false.
    userObj.VideoStatisticInfo_width = message.getVideostatisticinfoWidth()
    userObj.VideoStatisticInfo_height = message.getVideostatisticinfoHeight()
    userObj.VideoStatisticInfo_fps = message.getVideostatisticinfoFps()
    userObj.VideoStatisticInfo_bpf = message.getVideostatisticinfoBpf()
    userObj.ShareStatisticInfo_width = message.getSharestatisticinfoWidth()
    userObj.ShareStatisticInfo_height = message.getSharestatisticinfoHeight()
    userObj.ShareStatisticInfo_fps = message.getSharestatisticinfoFps()
    userObj.ShareStatisticInfo_bpf = message.getSharestatisticinfoBpf()
    userObj.userid = message.getUserid() // The user id of the user object.
    return userObj
  } catch (error) {
    return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
  }
}