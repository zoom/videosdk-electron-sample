#pragma once

#include "zoom_video_sdk_native_sdk_wrap_core_def.h"
#include "zoom_video_sdk_sinks_wrap_class.h"

class ZShareHelperWrap
{
public:
	ZShareHelperWrap();
	virtual ~ZShareHelperWrap();

	ZNZoomVideoSDKErrors StartShareView(ZoomSTRING handle, ZNZoomVideoSDKShareOption option);
	ZNZoomVideoSDKErrors StartShareScreen(ZoomSTRING monitorID, ZNZoomVideoSDKShareOption option);
	ZNZoomVideoSDKErrors StartShareComputerAudio();
	ZNZoomVideoSDKErrors StopShare();
	bool IsSharingOut();
	bool IsScreenSharingOut();
	bool IsOtherSharing();
	ZNZoomVideoSDKErrors LockShare(bool lock);
	bool IsShareLocked();
	ZNZoomVideoSDKErrors EnableShareDeviceAudio(bool bEnable);
	bool IsShareDeviceAudioEnabled();
	ZNZoomVideoSDKErrors EnableOptimizeForSharedVideo(bool bEnable);
	bool IsOptimizeForSharedVideoEnabled();
	ZNZoomVideoSDKErrors StartShare2ndCamera(ZoomSTRING cameraID);
	unsigned long long GetRecvHandle();
private:
	unsigned long long m_recv_handle;

};
