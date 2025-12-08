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
      const shareActionProtoList = message.getZnShareactionlist().getShareactionList()
      for (let item of shareActionProtoList) {
        const obj = {
          /** Share source ID. */
          shareSourceId: item.getSharesourceid(),
          /** Share status {@link ZoomVideoSDKShareStatus}. */
          shareStatus: item.getSharestatus(),
          /** Subscribe fail reason {@link ZoomVideoSDKSubscribeFailReason}. */
          subscribeFailReason: item.getSubscribefailreason(),
          /** Whether annotation privilege is enabled. */
          isAnnotationPrivilegeEnabled: item.getIsannotationprivilegeenabled(),
          /** Share type {@link ZoomVideoSDKShareType}. */
          shareType: item.getSharetype(),
          /** The reason why the share capture is paused {@link ZoomVideoSDKShareCapturePauseReason}. */
          shareCapturePauseReason: item.getSharecapturepausereason()
        }
        shareActionList.push(obj)
      }
    }
    userObj.pUser = message.getPUser()
    /** The user's custom id. */
    userObj.custom_identity = message.getCustomIdentity()
    /** The user's name. */
    userObj.username = data.getUsername()
    /** The user's reference info. */
    userObj.userReference = data.getUserreference()
    /** The user's video status. */
    userObj.isHasVideoDevice = message.getIshasvideodevice()
    /** The user's video status. */
    userObj.isVideoOn = message.getIsvideoon()
    /** The user's audio status. */
    userObj.audioType = message.getAudiotype()
    /** The user's audio status. */
    userObj.isAudioMuted = message.getIsaudiomuted()
    /** The user's audio status. */
    userObj.isAudioTalking = message.getIsaudiotalking()
    /** A list of all share information. */
    userObj.shareActionList = shareActionList
    /** Whether the user is the host. */
    userObj.isHost = message.getIshost()
    /** Whether the user is the manager(coHost). */
    userObj.isManager = message.getIsmanager()
    /** Whether the user is spotLighted. */
    userObj.isVideoSpotLighted = message.getIsvideospotlighted()
    /** Whether the user is incoming live stream user. */
    userObj.isIncomingLiveStreamUser = message.getIsincominglivestreamuser()
    /** The user's video statistic information. */
    userObj.VideoStatisticInfo_width = message.getVideostatisticinfoWidth()
    /** The user's video statistic information. */
    userObj.VideoStatisticInfo_height = message.getVideostatisticinfoHeight()
    /** The user's video statistic information. */
    userObj.VideoStatisticInfo_fps = message.getVideostatisticinfoFps()
    /** The user's video statistic information. */
    userObj.VideoStatisticInfo_bpf = message.getVideostatisticinfoBpf()
    /** The user's share statistic information. */
    userObj.ShareStatisticInfo_width = message.getSharestatisticinfoWidth()
    /** The user's share statistic information. */
    userObj.ShareStatisticInfo_height = message.getSharestatisticinfoHeight()
    /** The user's share statistic information. */
    userObj.ShareStatisticInfo_fps = message.getSharestatisticinfoFps()
    /** The user's share statistic information. */
    userObj.ShareStatisticInfo_bpf = message.getSharestatisticinfoBpf()
    /** The user's id. */
    userObj.userid = message.getUserid()
    /** The network quality level of audio for the user {@link ZoomVideoSDKNetworkStatus}. */
    userObj.audioNetworkLevel = message.getAudionetworklevel()
    /** The network quality level of video for the user {@link ZoomVideoSDKNetworkStatus}. */
    userObj.videoNetworkLevel = message.getVideonetworklevel()
    /** The network quality level of share for the user {@link ZoomVideoSDKNetworkStatus}. */
    userObj.shareNetworkLevel = message.getSharenetworklevel()
    /** The overall network quality level of the user {@link ZoomVideoSDKNetworkStatus}. */
    userObj.overallNetworkLevel = message.getOverallnetworklevel()
    return userObj
  } catch (error) {
    return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter
  }
}