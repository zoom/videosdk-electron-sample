#pragma once

#include "zoom_video_sdk_native_sdk_wrap_core_def.h"
#include "zoom_video_sdk_sinks_wrap_class.h"

class ZRecordingHelperWrap
{
public:
	ZRecordingHelperWrap();
	virtual ~ZRecordingHelperWrap();

	ZNZoomVideoSDKErrors CanStartRecording();
	ZNZoomVideoSDKErrors StartCloudRecording();
	ZNZoomVideoSDKErrors StopCloudRecording();
	ZNZoomVideoSDKErrors PauseCloudRecording();
	ZNZoomVideoSDKErrors ResumeCloudRecording();
	ZNZoomVideoSDKErrors GetCloudRecordingStatus(ZNRecordingStatus& record_status);
};
