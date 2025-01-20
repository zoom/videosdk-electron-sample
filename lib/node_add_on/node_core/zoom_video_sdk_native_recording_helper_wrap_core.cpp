#include "zoom_video_sdk_native_recording_helper_wrap_core.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"

extern ZNativeVideoSDKWrap _g_native_wrap;

ZRecordingHelperWrap::ZRecordingHelperWrap()
{

}
ZRecordingHelperWrap::~ZRecordingHelperWrap()
{

}

ZNZoomVideoSDKErrors ZRecordingHelperWrap::CanStartRecording()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRecordingHelper* pRecordingHelper = pVideoSDK->getRecordingHelper();
		if (pRecordingHelper)
		{
			err = (ZNZoomVideoSDKErrors)pRecordingHelper->canStartRecording();
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZRecordingHelperWrap::StartCloudRecording()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRecordingHelper* pRecordingHelper = pVideoSDK->getRecordingHelper();
		if (pRecordingHelper)
		{
			err = (ZNZoomVideoSDKErrors)pRecordingHelper->startCloudRecording();
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZRecordingHelperWrap::StopCloudRecording()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRecordingHelper* pRecordingHelper = pVideoSDK->getRecordingHelper();
		if (pRecordingHelper)
		{
			err = (ZNZoomVideoSDKErrors)pRecordingHelper->stopCloudRecording();
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZRecordingHelperWrap::PauseCloudRecording()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRecordingHelper* pRecordingHelper = pVideoSDK->getRecordingHelper();
		if (pRecordingHelper)
		{
			err = (ZNZoomVideoSDKErrors)pRecordingHelper->pauseCloudRecording();
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZRecordingHelperWrap::ResumeCloudRecording()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRecordingHelper* pRecordingHelper = pVideoSDK->getRecordingHelper();
		if (pRecordingHelper)
		{
			err = (ZNZoomVideoSDKErrors)pRecordingHelper->resumeCloudRecording();
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZRecordingHelperWrap::GetCloudRecordingStatus(ZNRecordingStatus& record_status)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRecordingHelper* pRecordingHelper = pVideoSDK->getRecordingHelper();
		if (pRecordingHelper)
		{
			ZOOM_VIDEO_SDK_NAMESPACE::RecordingStatus tmp_status;
			err = (ZNZoomVideoSDKErrors)pRecordingHelper->getCloudRecordingStatus(tmp_status);
			record_status = (ZNRecordingStatus)tmp_status;
		}
	}
	return err;
}
