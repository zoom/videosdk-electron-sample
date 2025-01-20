#include "zoom_video_sdk_native_livestream_helper_wrap_core.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"

extern ZNativeVideoSDKWrap _g_native_wrap;

ZLiveStreamHelperWrap::ZLiveStreamHelperWrap()
{

}
ZLiveStreamHelperWrap::~ZLiveStreamHelperWrap()
{

}
ZNZoomVideoSDKErrors ZLiveStreamHelperWrap::StartLiveStream(ZoomSTRING streamUrl, ZoomSTRING key, ZoomSTRING broadcastUrl)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKLiveStreamHelper* pLiveStreamHelper = pVideoSDK->getLiveStreamHelper();
		if (!pLiveStreamHelper)
		{
			break;
		}
		if (streamUrl.empty() || key.empty() || broadcastUrl.empty())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
		}
		else
		{
			err = (ZNZoomVideoSDKErrors)pLiveStreamHelper->startLiveStream(streamUrl.c_str(), key.c_str(), broadcastUrl.c_str());
		}
		
	} while (false);
	return err;	
}
ZNZoomVideoSDKErrors ZLiveStreamHelperWrap::StopLiveStream()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKLiveStreamHelper* pLiveStreamHelper = pVideoSDK->getLiveStreamHelper();
		if (pLiveStreamHelper)
		{
			err = (ZNZoomVideoSDKErrors)pLiveStreamHelper->stopLiveStream();
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZLiveStreamHelperWrap::CanStartLiveStream()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKLiveStreamHelper* pLiveStreamHelper = pVideoSDK->getLiveStreamHelper();
		if (pLiveStreamHelper)
		{
			err = (ZNZoomVideoSDKErrors)pLiveStreamHelper->canStartLiveStream();
		}
	}
	return err;
}


ZIncomingLiveStreamHelperWrap::ZIncomingLiveStreamHelperWrap()
{

}
ZIncomingLiveStreamHelperWrap::~ZIncomingLiveStreamHelperWrap()
{

}
ZNZoomVideoSDKErrors ZIncomingLiveStreamHelperWrap::BindIncomingLiveStream(ZoomSTRING strStreamKeyID)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKIncomingLiveStreamHelper* pIncomingLiveStreamHelper = pVideoSDK->getIncomingLiveStreamHelper();
		if (!pIncomingLiveStreamHelper)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pIncomingLiveStreamHelper->bindIncomingLiveStream(strStreamKeyID.c_str());

	} while (false);
	return err;	
}
ZNZoomVideoSDKErrors ZIncomingLiveStreamHelperWrap::UnbindIncomingLiveStream(ZoomSTRING strStreamKeyID)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKIncomingLiveStreamHelper* pIncomingLiveStreamHelper = pVideoSDK->getIncomingLiveStreamHelper();
		if (!pIncomingLiveStreamHelper)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pIncomingLiveStreamHelper->unbindIncomingLiveStream(strStreamKeyID.c_str());
		
	} while (false);
	return err;	
}
ZNZoomVideoSDKErrors ZIncomingLiveStreamHelperWrap::GetIncomingLiveStreamStatus()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKIncomingLiveStreamHelper* pIncomingLiveStreamHelper = pVideoSDK->getIncomingLiveStreamHelper();
		if (!pIncomingLiveStreamHelper)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pIncomingLiveStreamHelper->getIncomingLiveStreamStatus();
		
	} while (false);
	return err;	
}
ZNZoomVideoSDKErrors ZIncomingLiveStreamHelperWrap::StartIncomingLiveStream(ZoomSTRING strStreamKeyID)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKIncomingLiveStreamHelper* pIncomingLiveStreamHelper = pVideoSDK->getIncomingLiveStreamHelper();
		if (!pIncomingLiveStreamHelper)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pIncomingLiveStreamHelper->startIncomingLiveStream(strStreamKeyID.c_str());
		
	} while (false);
	return err;	
}
ZNZoomVideoSDKErrors ZIncomingLiveStreamHelperWrap::StopIncomingLiveStream(ZoomSTRING strStreamKeyID)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKIncomingLiveStreamHelper* pIncomingLiveStreamHelper = pVideoSDK->getIncomingLiveStreamHelper();
		if (!pIncomingLiveStreamHelper)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pIncomingLiveStreamHelper->stopIncomingLiveStream(strStreamKeyID.c_str());
		
	} while (false);
	return err;	
}