#pragma once

#include "zoom_video_sdk_native_sdk_wrap_core_def.h"
#include "zoom_video_sdk_sinks_wrap_class.h"

class ZCmdChannelHelperWrap
{
public:
	ZCmdChannelHelperWrap();
	virtual ~ZCmdChannelHelperWrap();

	ZNZoomVideoSDKErrors SendCommand(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* receiver, ZoomSTRING strCmd);
};
