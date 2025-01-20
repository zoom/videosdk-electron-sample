#pragma once

#include "zoom_video_sdk_native_sdk_wrap_core_def.h"
#include "zoom_video_sdk_sinks_wrap_class.h"

class ZShareSettingWrap
{
public:
	ZShareSettingWrap();
	virtual ~ZShareSettingWrap();

	ZNZoomVideoSDKErrors SetScreenCaptureMode(ZNZoomVideoSDKScreenCaptureMode captureMode);
	ZNZoomVideoSDKErrors GetScreenCaptureMode(ZNZoomVideoSDKScreenCaptureMode& zn_captureMode);
	ZNZoomVideoSDKErrors EnableGreenBorder(bool bEnable);
	bool IsGreenBorderEnabled();
#if (defined _WIN32)
	ZNZoomVideoSDKErrors EnableAdminRemoteControl(bool bEnable);
	bool IsRemoteControlAllApplicationsEnabled();
#endif
};
