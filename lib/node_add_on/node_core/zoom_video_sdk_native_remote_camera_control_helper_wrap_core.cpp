#include "zoom_video_sdk_node_rawdata_helper_mgr_class.h"
#include "zoom_video_sdk_native_remote_camera_control_helper_wrap_core.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"

extern ZNativeVideoSDKWrap _g_native_wrap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ZRemoteCameraControlHelperWrap::ZRemoteCameraControlHelperWrap()
{

}
ZRemoteCameraControlHelperWrap::~ZRemoteCameraControlHelperWrap()
{

}
ZNZoomVideoSDKErrors ZRemoteCameraControlHelperWrap::RequestControlRemoteCamera(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		if (!_g_native_wrap.IsValidUser(pUser))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRemoteCameraControlHelper* pRemoteCameraControlHelper = pUser->getRemoteCameraControlHelper();
		if (!pRemoteCameraControlHelper)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pRemoteCameraControlHelper->requestControlRemoteCamera();
	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZRemoteCameraControlHelperWrap::GiveUpControlRemoteCamera(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		if (!_g_native_wrap.IsValidUser(pUser))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRemoteCameraControlHelper* pRemoteCameraControlHelper = pUser->getRemoteCameraControlHelper();
		if (!pRemoteCameraControlHelper)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pRemoteCameraControlHelper->giveUpControlRemoteCamera();
	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZRemoteCameraControlHelperWrap::TurnLeft(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, unsigned int range)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		if (!_g_native_wrap.IsValidUser(pUser))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRemoteCameraControlHelper* pRemoteCameraControlHelper = pUser->getRemoteCameraControlHelper();
		if (!pRemoteCameraControlHelper)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pRemoteCameraControlHelper->turnLeft(range);
	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZRemoteCameraControlHelperWrap::TurnRight(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, unsigned int range)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		if (!_g_native_wrap.IsValidUser(pUser))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRemoteCameraControlHelper* pRemoteCameraControlHelper = pUser->getRemoteCameraControlHelper();
		if (!pRemoteCameraControlHelper)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pRemoteCameraControlHelper->turnRight(range);
	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZRemoteCameraControlHelperWrap::TurnUp(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, unsigned int range)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		if (!_g_native_wrap.IsValidUser(pUser))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRemoteCameraControlHelper* pRemoteCameraControlHelper = pUser->getRemoteCameraControlHelper();
		if (!pRemoteCameraControlHelper)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pRemoteCameraControlHelper->turnUp(range);
	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZRemoteCameraControlHelperWrap::TurnDown(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, unsigned int range)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		if (!_g_native_wrap.IsValidUser(pUser))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRemoteCameraControlHelper* pRemoteCameraControlHelper = pUser->getRemoteCameraControlHelper();
		if (!pRemoteCameraControlHelper)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pRemoteCameraControlHelper->turnDown(range);
	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZRemoteCameraControlHelperWrap::ZoomIn(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, unsigned int range)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		if (!_g_native_wrap.IsValidUser(pUser))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRemoteCameraControlHelper* pRemoteCameraControlHelper = pUser->getRemoteCameraControlHelper();
		if (!pRemoteCameraControlHelper)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pRemoteCameraControlHelper->zoomIn(range);
	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZRemoteCameraControlHelperWrap::ZoomOut(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, unsigned int range)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		if (!_g_native_wrap.IsValidUser(pUser))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRemoteCameraControlHelper* pRemoteCameraControlHelper = pUser->getRemoteCameraControlHelper();
		if (!pRemoteCameraControlHelper)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pRemoteCameraControlHelper->zoomOut(range);
	} while (false);
	return err;
}
