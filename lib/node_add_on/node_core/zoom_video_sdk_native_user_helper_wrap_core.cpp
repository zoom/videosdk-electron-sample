#include "zoom_video_sdk_native_user_helper_wrap_core.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"

extern ZNativeVideoSDKWrap _g_native_wrap;

ZUserHelperWrap::ZUserHelperWrap()
{

}
ZUserHelperWrap::~ZUserHelperWrap()
{

}

bool ZUserHelperWrap::ChangeName(ZoomSTRING name, ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser)
{
	bool bSucc = false;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		if (!_g_native_wrap.IsValidUser(pUser))
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUserHelper* pUserHelper = pVideoSDK->getUserHelper();
		if (!pUserHelper)
		{
			break;
		}
		bSucc = pUserHelper->changeName(name.c_str(), pUser);
	} while (false);
	return bSucc;
}
bool ZUserHelperWrap::MakeHost(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser)
{
	bool bSucc = false;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		if (!_g_native_wrap.IsValidUser(pUser))
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUserHelper* pUserHelper = pVideoSDK->getUserHelper();
		if (!pUserHelper)
		{
			break;
		}
		bSucc = pUserHelper->makeHost(pUser);
	} while (false);
	return bSucc;
}
bool ZUserHelperWrap::MakeManager(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser)
{
	bool bSucc = false;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		if (!_g_native_wrap.IsValidUser(pUser))
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUserHelper* pUserHelper = pVideoSDK->getUserHelper();
		if (!pUserHelper)
		{
			break;
		}
		bSucc = pUserHelper->makeManager(pUser);
	} while (false);
	return bSucc;
}
bool ZUserHelperWrap::RevokeManager(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser)
{
	bool bSucc = false;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		if (!_g_native_wrap.IsValidUser(pUser))
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUserHelper* pUserHelper = pVideoSDK->getUserHelper();
		if (!pUserHelper)
		{
			break;
		}
		bSucc = pUserHelper->revokeManager(pUser);
	} while (false);
	return bSucc;
}
bool ZUserHelperWrap::RemoveUser(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser)
{
	bool err = false;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		if (!_g_native_wrap.IsValidUser(pUser))
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUserHelper* pUserHelper = pVideoSDK->getUserHelper();
		if (!pUserHelper)
		{
			break;
		}
		err = pUserHelper->removeUser(pUser);
	} while (false);
	return err;
}



