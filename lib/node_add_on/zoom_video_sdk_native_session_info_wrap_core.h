#pragma once
#include "zoom_video_sdk_native_sdk_wrap_core_def.h"
#include "zoom_video_sdk_sinks_wrap_class.h"
#include "electron_zoomvideosdk.pb.h"

class ZSessionInfoWrap
{
public:
	ZSessionInfoWrap();
	virtual ~ZSessionInfoWrap();
	//
	ZoomSTRING GetSessionName();
	ZoomSTRING GetSessionPassword();
	ZoomSTRING GetSessionHostName();
	ZoomSTRING GetSessionID();
	
	
	void GetSessionHost(com::electron::zoomvideo::sdk::proto::VideoSDKUser& _sessionHost);
	void GetRemoteUsers(com::electron::zoomvideo::sdk::proto::UserList& _remoteUsers);
	void GetMyself(com::electron::zoomvideo::sdk::proto::VideoSDKUser& _mySelf);

	ZNZoomVideoSDKErrors GetSessionAudioStatisticInfo(com::electron::zoomvideo::sdk::proto::VideoSDKSessionAudioStatisticInfoList& _infoList);
	ZNZoomVideoSDKErrors GetSessionVideoStatisticInfo(com::electron::zoomvideo::sdk::proto::VideoSDKSessionASVStatisticInfoList& _infoList);
	ZNZoomVideoSDKErrors GetSessionShareStatisticInfo(com::electron::zoomvideo::sdk::proto::VideoSDKSessionASVStatisticInfoList& _infoList);
};
