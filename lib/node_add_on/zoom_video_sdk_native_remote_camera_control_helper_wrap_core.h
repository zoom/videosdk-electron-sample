#pragma once

#include "zoom_video_sdk_native_sdk_wrap_core_def.h"
#include "zoom_video_sdk_sinks_wrap_class.h"

class ZRemoteCameraControlHelperWrap
{
public:
	ZRemoteCameraControlHelperWrap();
	virtual ~ZRemoteCameraControlHelperWrap();

	ZNZoomVideoSDKErrors RequestControlRemoteCamera(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser);
	ZNZoomVideoSDKErrors GiveUpControlRemoteCamera(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser);
	ZNZoomVideoSDKErrors TurnLeft(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, unsigned int range);
	ZNZoomVideoSDKErrors TurnRight(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, unsigned int range);
	ZNZoomVideoSDKErrors TurnUp(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, unsigned int range);
	ZNZoomVideoSDKErrors TurnDown(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, unsigned int range);
	ZNZoomVideoSDKErrors ZoomIn(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, unsigned int range);
	ZNZoomVideoSDKErrors ZoomOut(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, unsigned int range);
};
