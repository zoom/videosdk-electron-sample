#pragma once

#include "zoom_video_sdk_native_sdk_wrap_core_def.h"
#include "zoom_video_sdk_sinks_wrap_class.h"


class ZAudioHelperWrap
{
public:
	ZAudioHelperWrap();
	virtual ~ZAudioHelperWrap();

	ZNZoomVideoSDKErrors StartAudio(); 
	ZNZoomVideoSDKErrors StopAudio();
	ZNZoomVideoSDKErrors MuteAudio(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser);
	ZNZoomVideoSDKErrors UnMuteAudio(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser);
	void GetSpeakerList(com::electron::zoomvideo::sdk::proto::GetSpeakerList& _speakerList);
	void GetMicList(com::electron::zoomvideo::sdk::proto::GetMicList& _micList);
	ZNZoomVideoSDKErrors SelectSpeaker(ZoomSTRING deviceId, ZoomSTRING deviceName);
	ZNZoomVideoSDKErrors SelectMic(ZoomSTRING deviceId, ZoomSTRING deviceName);
	ZNZoomVideoSDKErrors Subscribe();
	ZNZoomVideoSDKErrors UnSubscribe();
};
