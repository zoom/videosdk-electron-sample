
#include "zoom_video_sdk_node_rawdata_helper_mgr_class.h"

////////////////////////////////////////////////////////////////////////////////

void ZoomVideoNodePipeServerMgr::onMessageRecvNotification(UVIPCMessage* msg)
{
	if (NULL == msg)
		return;
	if (sizeof(unsigned int) != msg->GetLen()
		|| NULL == msg->GetBuf())
		return;
	unsigned int* p_source_id = (unsigned int*)msg->GetBuf();
	std::lock_guard<std::mutex> lock_(_cached_raw_data_count_map_mutex);
	std::map<unsigned int, int>::iterator iter = _cached_raw_data_count_map.find(*p_source_id);
	if (_cached_raw_data_count_map.end() != iter)
		--iter->second;
}
void ZoomVideoNodeUtilityHelper::ConvertSDKUserToProtoUser(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pSdkUser, com::electron::zoomvideo::sdk::proto::VideoSDKUser* pProtoUser)
{
	if (pSdkUser && pProtoUser)
	{
		ZoomSTRING temp_customIdentity = pSdkUser->getCustomIdentity();
		pProtoUser->set_custom_identity(zs2s(temp_customIdentity).c_str());

		ZoomSTRING temp_userName = pSdkUser->getUserName();
		pProtoUser->set_username(ws2s(temp_userName).c_str());

		ZoomSTRING temp_userid = pSdkUser->getUserID();
		pProtoUser->set_userid(zs2s(temp_userid).c_str());

		ZoomSTRING temp_userreference = pSdkUser->getUserReference();
		pProtoUser->set_userreference(zs2s(temp_userreference).c_str());

		pProtoUser->set_audiotype((int)pSdkUser->getAudioStatus().audioType);
		pProtoUser->set_isaudiomuted(pSdkUser->getAudioStatus().isMuted);
		pProtoUser->set_isaudiotalking(pSdkUser->getAudioStatus().isTalking);

		if (pSdkUser->GetVideoPipe())
		{
			pProtoUser->set_ishasvideodevice(pSdkUser->GetVideoPipe()->getVideoStatus().isHasVideoDevice);
			pProtoUser->set_isvideoon(pSdkUser->GetVideoPipe()->getVideoStatus().isOn);
		}

		if (pSdkUser->getShareActionList())
		{
			IVideoSDKVector<IZoomVideoSDKShareAction*>* shareActionList = pSdkUser->getShareActionList();
			com::electron::zoomvideo::sdk::proto::ShareActionList* pProtoShareActionList = new com::electron::zoomvideo::sdk::proto::ShareActionList;
			int count = shareActionList->GetCount();
			for (int i = 0; i < count; ++i)
			{
				IZoomVideoSDKShareAction* pShareAction = shareActionList->GetItem(i);
				com::electron::zoomvideo::sdk::proto::ShareAction* pProtoShareAction = pProtoShareActionList->add_shareaction();
				if (!pShareAction || !pProtoShareAction)
				{
					continue;
				}
				ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKShareActionToProtoShareAction(pShareAction, pProtoShareAction);
			}
			pProtoUser->set_allocated_zn_shareactionlist(pProtoShareActionList);
		}

		pProtoUser->set_ishost(pSdkUser->isHost());
		pProtoUser->set_ismanager(pSdkUser->isManager());
		pProtoUser->set_isvideospotlighted(pSdkUser->isVideoSpotLighted());
		pProtoUser->set_isincominglivestreamuser(pSdkUser->isIncomingLiveStreamUser());

		pProtoUser->set_videostatisticinfo_bpf(pSdkUser->getVideoStatisticInfo().bpf);
		pProtoUser->set_videostatisticinfo_fps(pSdkUser->getVideoStatisticInfo().fps);
		pProtoUser->set_videostatisticinfo_width(pSdkUser->getVideoStatisticInfo().width);
		pProtoUser->set_videostatisticinfo_height(pSdkUser->getVideoStatisticInfo().height);

		pProtoUser->set_sharestatisticinfo_bpf(pSdkUser->getShareStatisticInfo().bpf);
		pProtoUser->set_sharestatisticinfo_fps(pSdkUser->getShareStatisticInfo().fps);
		pProtoUser->set_sharestatisticinfo_width(pSdkUser->getShareStatisticInfo().width);
		pProtoUser->set_sharestatisticinfo_height(pSdkUser->getShareStatisticInfo().height);

		int64_t temp_ = (int64_t)pSdkUser;
		pProtoUser->set_p_user((int64_t)temp_);
	}
}
void ZoomVideoNodeUtilityHelper::ConvertSDKShareActionToProtoShareAction(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKShareAction* pShareAction, com::electron::zoomvideo::sdk::proto::ShareAction* pProtoShareAction)
{
	if (pShareAction && pProtoShareAction)
	{
		pProtoShareAction->set_sharesourceid((int)pShareAction->getShareSourceId());
		pProtoShareAction->set_sharestatus((int)pShareAction->getShareStatus());
		pProtoShareAction->set_subscribefailreason((int)pShareAction->getSubscribeFailReason());
		pProtoShareAction->set_isannotationprivilegeenabled(pShareAction->isAnnotationPrivilegeEnabled());
		pProtoShareAction->set_sharetype((int)pShareAction->getShareType());
	}
}
ZoomVideoNodePipeServerMgr _g_video_pipe_server;
ZoomVideoNodePipeServerMgr _g_audio_pipe_server;
ZoomVideoNodePipeServerMgr _g_share_pipe_server;

