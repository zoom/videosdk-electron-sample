#pragma once

#include "zoom_video_sdk_native_sdk_wrap_core_def.h"
#include "zoom_video_sdk_sinks_wrap_class.h"

class ZRTMSHelperWrap
{
public:
	ZRTMSHelperWrap();
	virtual ~ZRTMSHelperWrap();

	bool IsSupportRealTimeMediaStreams();
	ZNZoomVideoSDKErrors CanStartRealTimeMediaStreams();
	ZNZoomVideoSDKErrors StartRealTimeMediaStreams();
	ZNZoomVideoSDKErrors PauseRealTimeMediaStreams();
	ZNZoomVideoSDKErrors ResumeRealTimeMediaStreams();
	ZNZoomVideoSDKErrors StopRealTimeMediaStreams();
};
