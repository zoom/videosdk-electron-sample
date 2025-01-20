#pragma once

#include "zoom_video_sdk_native_sdk_wrap_core_def.h"
#include "zoom_video_sdk_sinks_wrap_class.h"

class ZLiveStreamHelperWrap
{
public:
	ZLiveStreamHelperWrap();
	virtual ~ZLiveStreamHelperWrap();

	ZNZoomVideoSDKErrors StartLiveStream(ZoomSTRING streamUrl, ZoomSTRING key, ZoomSTRING broadcastUrl);
	ZNZoomVideoSDKErrors StopLiveStream();
	ZNZoomVideoSDKErrors CanStartLiveStream();
};


class ZIncomingLiveStreamHelperWrap
{
public:
	ZIncomingLiveStreamHelperWrap();
	virtual ~ZIncomingLiveStreamHelperWrap();

	ZNZoomVideoSDKErrors BindIncomingLiveStream(ZoomSTRING strStreamKeyID);
	ZNZoomVideoSDKErrors UnbindIncomingLiveStream(ZoomSTRING strStreamKeyID);
	ZNZoomVideoSDKErrors GetIncomingLiveStreamStatus();
	ZNZoomVideoSDKErrors StartIncomingLiveStream(ZoomSTRING strStreamKeyID);
	ZNZoomVideoSDKErrors StopIncomingLiveStream(ZoomSTRING strStreamKeyID);
};
