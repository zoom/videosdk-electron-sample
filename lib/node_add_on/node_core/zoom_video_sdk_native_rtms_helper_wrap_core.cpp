#include "zoom_video_sdk_native_rtms_helper_wrap_core.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"

extern ZNativeVideoSDKWrap _g_native_wrap;

ZRTMSHelperWrap::ZRTMSHelperWrap()
{
	
}
ZRTMSHelperWrap::~ZRTMSHelperWrap()
{
	
}
bool ZRTMSHelperWrap::IsSupportRealTimeMediaStreams()
{
	bool bIs = false;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (!pVideoSDK)
	{
		return bIs;
	}
	
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRTMSHelper* pRTMSHelper = pVideoSDK->getRealTimeMediaStreamsHelper();
	if (!pRTMSHelper)
	{
		return bIs;
	}
	
	bIs = pRTMSHelper->isSupportRealTimeMediaStreams();
	return bIs;
}
ZNZoomVideoSDKErrors ZRTMSHelperWrap::CanStartRealTimeMediaStreams()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (!pVideoSDK)
	{
		return err;
	}
	
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRTMSHelper* pRTMSHelper = pVideoSDK->getRealTimeMediaStreamsHelper();
	if (!pRTMSHelper)
	{
		return err;
	}
	
	err = (ZNZoomVideoSDKErrors)pRTMSHelper->canStartRealTimeMediaStreams();
	return err;
}
ZNZoomVideoSDKErrors ZRTMSHelperWrap::StartRealTimeMediaStreams()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (!pVideoSDK)
	{
		return err;
	}
	
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRTMSHelper* pRTMSHelper = pVideoSDK->getRealTimeMediaStreamsHelper();
	if (!pRTMSHelper)
	{
		return err;
	}
	
	err = (ZNZoomVideoSDKErrors)pRTMSHelper->startRealTimeMediaStreams();
	return err;
}
ZNZoomVideoSDKErrors ZRTMSHelperWrap::PauseRealTimeMediaStreams()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (!pVideoSDK)
	{
		return err;
	}
	
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRTMSHelper* pRTMSHelper = pVideoSDK->getRealTimeMediaStreamsHelper();
	if (!pRTMSHelper)
	{
		return err;
	}
	
	err = (ZNZoomVideoSDKErrors)pRTMSHelper->pauseRealTimeMediaStreams();
	return err;
}
ZNZoomVideoSDKErrors ZRTMSHelperWrap::ResumeRealTimeMediaStreams()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (!pVideoSDK)
	{
		return err;
	}
	
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRTMSHelper* pRTMSHelper = pVideoSDK->getRealTimeMediaStreamsHelper();
	if (!pRTMSHelper)
	{
		return err;
	}
	
	err = (ZNZoomVideoSDKErrors)pRTMSHelper->resumeRealTimeMediaStreams();
	return err;
}
ZNZoomVideoSDKErrors ZRTMSHelperWrap::StopRealTimeMediaStreams()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (!pVideoSDK)
	{
		return err;
	}
	
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRTMSHelper* pRTMSHelper = pVideoSDK->getRealTimeMediaStreamsHelper();
	if (!pRTMSHelper)
	{
		return err;
	}
	
	err = (ZNZoomVideoSDKErrors)pRTMSHelper->stopRealTimeMediaStreams();
	return err;
}

