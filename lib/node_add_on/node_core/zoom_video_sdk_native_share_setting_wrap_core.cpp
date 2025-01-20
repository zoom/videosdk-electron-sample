#include "zoom_video_sdk_native_share_setting_wrap_core.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"


extern ZNativeVideoSDKWrap _g_native_wrap;

ZShareSettingWrap::ZShareSettingWrap()
{
}
ZShareSettingWrap::~ZShareSettingWrap()
{
}
ZNZoomVideoSDKErrors ZShareSettingWrap::SetScreenCaptureMode(ZNZoomVideoSDKScreenCaptureMode captureMode)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKShareSettingHelper* pShareSetting = pVideoSDK->getShareSettingHelper();
		if (pShareSetting)
		{
			err = (ZNZoomVideoSDKErrors)pShareSetting->setScreenCaptureMode((ZoomVideoSDKScreenCaptureMode)captureMode);
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZShareSettingWrap::GetScreenCaptureMode(ZNZoomVideoSDKScreenCaptureMode& zn_captureMode)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKShareSettingHelper* pShareSetting = pVideoSDK->getShareSettingHelper();
		if (pShareSetting)
		{
			ZoomVideoSDKScreenCaptureMode sdk_captureMode = ZoomVideoSDKScreenCaptureMode_Auto;
			err = (ZNZoomVideoSDKErrors)pShareSetting->getScreenCaptureMode(sdk_captureMode);
			if (ZNZoomVideoSDKErrors_Success == err)
			{
				zn_captureMode = (ZNZoomVideoSDKScreenCaptureMode)sdk_captureMode;
			}
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZShareSettingWrap::EnableGreenBorder(bool bEnable)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKShareSettingHelper* pShareSetting = pVideoSDK->getShareSettingHelper();
		if (pShareSetting)
		{
			err = (ZNZoomVideoSDKErrors)pShareSetting->enableGreenBorder(bEnable);
		}
	}
	return err;
}
bool ZShareSettingWrap::IsGreenBorderEnabled()
{
	bool bRet = false;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKShareSettingHelper* pShareSetting = pVideoSDK->getShareSettingHelper();
		if (pShareSetting)
		{
			bRet = pShareSetting->isGreenBorderEnabled();
		}
	}
	return bRet;
}
#if (defined _WIN32)
ZNZoomVideoSDKErrors ZShareSettingWrap::EnableAdminRemoteControl(bool bEnable)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKShareSettingHelper* pShareSetting = pVideoSDK->getShareSettingHelper();
		if (pShareSetting)
		{
			err = (ZNZoomVideoSDKErrors)pShareSetting->enableAdminRemoteControl(bEnable);
		}
	}
	return err;
}
bool ZShareSettingWrap::IsRemoteControlAllApplicationsEnabled()
{
	bool bRet = false;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKShareSettingHelper* pShareSetting = pVideoSDK->getShareSettingHelper();
		if (pShareSetting)
		{
			bRet = pShareSetting->isRemoteControlAllApplicationsEnabled();
		}
	}
	return bRet;
}
#endif