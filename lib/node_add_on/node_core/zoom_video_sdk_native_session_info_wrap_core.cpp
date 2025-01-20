#include "zoom_video_sdk_node_rawdata_helper_mgr_class.h"
#include "zoom_video_sdk_native_session_info_wrap_core.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"


extern ZNativeVideoSDKWrap _g_native_wrap;

///////////////////////////////////////////////////////////////////////////////////
ZSessionInfoWrap::ZSessionInfoWrap()
{
}
ZSessionInfoWrap::~ZSessionInfoWrap()
{
}


ZoomSTRING ZSessionInfoWrap::GetSessionName()
{	
	ZoomSTRING sessionName;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKSession* pSessionInfo = pVideoSDK->getSessionInfo();
		if (pSessionInfo)
		{
			sessionName = pSessionInfo->getSessionName();
		}
	}
	return sessionName;
}
ZoomSTRING ZSessionInfoWrap::GetSessionPassword()
{
	ZoomSTRING sessionPwd;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKSession* pSessionInfo = pVideoSDK->getSessionInfo();
		if (pSessionInfo)
		{
			sessionPwd = pSessionInfo->getSessionPassword();
		}
	}
	return sessionPwd;
}
ZoomSTRING ZSessionInfoWrap::GetSessionID()
{
	ZoomSTRING sessionID;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKSession* pSessionInfo = pVideoSDK->getSessionInfo();
		if (pSessionInfo)
		{
			sessionID = pSessionInfo->getSessionID();
		}
	}
	return sessionID;
}
ZoomSTRING ZSessionInfoWrap::GetSessionHostName()
{
	ZoomSTRING sessionHostName;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKSession* pSessionInfo = pVideoSDK->getSessionInfo();
		if (pSessionInfo)
		{
			sessionHostName = pSessionInfo->getSessionHostName();
		}
	}
	return sessionHostName;
}

void ZSessionInfoWrap::GetSessionHost(com::electron::zoomvideo::sdk::proto::VideoSDKUser& sessionHost)
{
	do 
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			return;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKSession* pSessionInfo = pVideoSDK->getSessionInfo();
		if (!pSessionInfo)
		{
			return;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pSessionHost = pSessionInfo->getSessionHost();
		if (!pSessionHost)
		{
			return;
		}
		
		ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKUserToProtoUser(pSessionHost, &sessionHost);

	} while (false);
	
}
void ZSessionInfoWrap::GetRemoteUsers(com::electron::zoomvideo::sdk::proto::UserList& _remoteUsers)
{
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			return;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKSession* pSessionInfo = pVideoSDK->getSessionInfo();
		if (!pSessionInfo)
		{
			return;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser*>* pRemoteUsers = pSessionInfo->getRemoteUsers();
		if (!pRemoteUsers)
		{
			return;
		}
		
		for (int i = 0; i < pRemoteUsers->GetCount(); ++i)
		{
			IZoomVideoSDKUser* pUserTemp = pRemoteUsers->GetItem(i);
			com::electron::zoomvideo::sdk::proto::VideoSDKUser* protoVideoSDKUser = _remoteUsers.add_user();
			if (!pUserTemp || !protoVideoSDKUser)
			{
				continue;
			}
			ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKUserToProtoUser(pUserTemp, protoVideoSDKUser);
		}
	} while (false);
}

void ZSessionInfoWrap::GetMyself(com::electron::zoomvideo::sdk::proto::VideoSDKUser& _mySelf)
{
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			return;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKSession* pSessionInfo = pVideoSDK->getSessionInfo();
		if (!pSessionInfo)
		{
			return;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pMySelf = pSessionInfo->getMyself();
		if (!pMySelf)
		{
			return;
		}

		ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKUserToProtoUser(pMySelf, &_mySelf);

	} while (false);
}

ZNZoomVideoSDKErrors ZSessionInfoWrap::GetSessionAudioStatisticInfo(com::electron::zoomvideo::sdk::proto::VideoSDKSessionAudioStatisticInfoList& _infoList)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKSession* pSessionInfo = pVideoSDK->getSessionInfo();
		if (!pSessionInfo)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKSessionAudioStatisticInfo sdk_send_info;
		ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKSessionAudioStatisticInfo sdk_recv_info;
		err = (ZNZoomVideoSDKErrors)pSessionInfo->getSessionAudioStatisticInfo(sdk_send_info, sdk_recv_info);
		if (ZNZoomVideoSDKErrors_Success == err)
		{
			com::electron::zoomvideo::sdk::proto::VideoSDKSessionAudioStatisticInfo* proto_send_info = _infoList.add_audiostatisticinfo();
			com::electron::zoomvideo::sdk::proto::VideoSDKSessionAudioStatisticInfo* proto_recv_info = _infoList.add_audiostatisticinfo();
			if (!proto_send_info || !proto_recv_info)
			{
				err = ZNZoomVideoSDKErrors_Internal_Error;
				break;
			}
			proto_send_info->set_frequency(sdk_send_info.frequency);
			proto_send_info->set_jitter(sdk_send_info.Jitter);
			proto_send_info->set_latency(sdk_send_info.latency);
			proto_send_info->set_packetlossavg(sdk_send_info.packetLossAvg);
			proto_send_info->set_packetlossmax(sdk_send_info.packetLossMax);

			proto_recv_info->set_frequency(sdk_recv_info.frequency);
			proto_recv_info->set_jitter(sdk_recv_info.Jitter);
			proto_recv_info->set_latency(sdk_recv_info.latency);
			proto_recv_info->set_packetlossavg(sdk_recv_info.packetLossAvg);
			proto_recv_info->set_packetlossmax(sdk_recv_info.packetLossMax);
		}

	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZSessionInfoWrap::GetSessionVideoStatisticInfo(com::electron::zoomvideo::sdk::proto::VideoSDKSessionASVStatisticInfoList& _infoList)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKSession* pSessionInfo = pVideoSDK->getSessionInfo();
		if (!pSessionInfo)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKSessionASVStatisticInfo sdk_send_info;
		ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKSessionASVStatisticInfo sdk_recv_info;
		err = (ZNZoomVideoSDKErrors)pSessionInfo->getSessionVideoStatisticInfo(sdk_send_info, sdk_recv_info);
		if (ZNZoomVideoSDKErrors_Success == err)
		{
			com::electron::zoomvideo::sdk::proto::VideoSDKSessionASVStatisticInfo* proto_send_info = _infoList.add_asvstatisticinfo();
			com::electron::zoomvideo::sdk::proto::VideoSDKSessionASVStatisticInfo* proto_recv_info = _infoList.add_asvstatisticinfo();
			if (!proto_send_info || !proto_recv_info)
			{
				err = ZNZoomVideoSDKErrors_Internal_Error;
				break;
			}
			proto_send_info->set_fps(sdk_send_info.fps);
			proto_send_info->set_frame_height(sdk_send_info.frame_height);
			proto_send_info->set_frame_width(sdk_send_info.frame_width);
			proto_send_info->set_jitter(sdk_send_info.Jitter);
			proto_send_info->set_latency(sdk_send_info.latency);
			proto_send_info->set_packetlossavg(sdk_send_info.packetLossAvg);
			proto_send_info->set_packetlossmax(sdk_send_info.packetLossMax);

			proto_recv_info->set_fps(sdk_recv_info.fps);
			proto_recv_info->set_frame_height(sdk_recv_info.frame_height);
			proto_recv_info->set_frame_width(sdk_recv_info.frame_width);
			proto_recv_info->set_jitter(sdk_recv_info.Jitter);
			proto_recv_info->set_latency(sdk_recv_info.latency);
			proto_recv_info->set_packetlossavg(sdk_recv_info.packetLossAvg);
			proto_recv_info->set_packetlossmax(sdk_recv_info.packetLossMax);
		}

	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZSessionInfoWrap::GetSessionShareStatisticInfo(com::electron::zoomvideo::sdk::proto::VideoSDKSessionASVStatisticInfoList& _infoList)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKSession* pSessionInfo = pVideoSDK->getSessionInfo();
		if (!pSessionInfo)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKSessionASVStatisticInfo sdk_send_info;
		ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKSessionASVStatisticInfo sdk_recv_info;
		err = (ZNZoomVideoSDKErrors)pSessionInfo->getSessionShareStatisticInfo(sdk_send_info, sdk_recv_info);
		if (ZNZoomVideoSDKErrors_Success == err)
		{
			com::electron::zoomvideo::sdk::proto::VideoSDKSessionASVStatisticInfo* proto_send_info = _infoList.add_asvstatisticinfo();
			com::electron::zoomvideo::sdk::proto::VideoSDKSessionASVStatisticInfo* proto_recv_info = _infoList.add_asvstatisticinfo();
			if (!proto_send_info || !proto_recv_info)
			{
				err = ZNZoomVideoSDKErrors_Internal_Error;
				break;
			}
			proto_send_info->set_fps(sdk_send_info.fps);
			proto_send_info->set_frame_height(sdk_send_info.frame_height);
			proto_send_info->set_frame_width(sdk_send_info.frame_width);
			proto_send_info->set_jitter(sdk_send_info.Jitter);
			proto_send_info->set_latency(sdk_send_info.latency);
			proto_send_info->set_packetlossavg(sdk_send_info.packetLossAvg);
			proto_send_info->set_packetlossmax(sdk_send_info.packetLossMax);

			proto_recv_info->set_fps(sdk_recv_info.fps);
			proto_recv_info->set_frame_height(sdk_recv_info.frame_height);
			proto_recv_info->set_frame_width(sdk_recv_info.frame_width);
			proto_recv_info->set_jitter(sdk_recv_info.Jitter);
			proto_recv_info->set_latency(sdk_recv_info.latency);
			proto_recv_info->set_packetlossavg(sdk_recv_info.packetLossAvg);
			proto_recv_info->set_packetlossmax(sdk_recv_info.packetLossMax);
		}

	} while (false);
	return err;
}