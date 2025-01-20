#include "zoom_video_sdk_native_share_helper_wrap_core.h"
#if (defined WIN32)   || (defined __linux)
#include "zoom_video_sdk_native_shareinfo_helper_wrap_core.h"
#endif
#include "zoom_video_sdk_native_sdk_wrap_core.h"

extern ZNativeVideoSDKWrap _g_native_wrap;

ZShareHelperWrap::ZShareHelperWrap()
{
	m_recv_handle = 0xffffffff;
}
ZShareHelperWrap::~ZShareHelperWrap()
{
	m_recv_handle = 0xffffffff;
}
ZNZoomVideoSDKErrors ZShareHelperWrap::StartShareView(ZoomSTRING handle, ZNZoomVideoSDKShareOption option)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKShareHelper* pShareHelper = pVideoSDK->getShareHelper();
		if (!pShareHelper)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKShareOption sdk_shareOption;
		sdk_shareOption.isWithDeviceAudio = option.isWithDeviceAudio;
		sdk_shareOption.isOptimizeForSharedVideo = option.isOptimizeForSharedVideo;
		if (!handle.empty())
		{
#ifdef WIN32
			int sdk_share_handle = std::stoi(handle, nullptr, 16);
			err = (ZNZoomVideoSDKErrors)pShareHelper->startShareView((void*)sdk_share_handle, sdk_shareOption);
#elif __linux
			err = (ZNZoomVideoSDKErrors)pShareHelper->startShareView((void *)&handle[0], sdk_shareOption);
#else
            int windowid = atoi(handle.c_str());
            err = (ZNZoomVideoSDKErrors)pShareHelper->startShareView((void *)windowid, sdk_shareOption);
#endif
		}

	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZShareHelperWrap::StartShareScreen(ZoomSTRING monitorID, ZNZoomVideoSDKShareOption option)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKShareHelper* pShareHelper = pVideoSDK->getShareHelper();
		if (pShareHelper)
		{
			ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKShareOption sdk_shareOption;
			sdk_shareOption.isWithDeviceAudio = option.isWithDeviceAudio;
			sdk_shareOption.isOptimizeForSharedVideo = option.isOptimizeForSharedVideo;
			err = (ZNZoomVideoSDKErrors)pShareHelper->startShareScreen(monitorID.c_str(), sdk_shareOption);
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZShareHelperWrap::StartShareComputerAudio()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKShareHelper* pShareHelper = pVideoSDK->getShareHelper();
		if (pShareHelper)
		{
			err = (ZNZoomVideoSDKErrors)pShareHelper->startShareComputerAudio();
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZShareHelperWrap::StopShare()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKShareHelper* pShareHelper = pVideoSDK->getShareHelper();
		if (pShareHelper)
		{
			err = (ZNZoomVideoSDKErrors)pShareHelper->stopShare();
		}
	}
	return err;
}
bool ZShareHelperWrap::IsSharingOut()
{
	bool bRet = false;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKShareHelper* pShareHelper = pVideoSDK->getShareHelper();
		if (pShareHelper)
		{
			bRet = pShareHelper->isSharingOut();
		}
	}
	return bRet;
}
bool ZShareHelperWrap::IsScreenSharingOut()
{
	bool bRet = false;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKShareHelper* pShareHelper = pVideoSDK->getShareHelper();
		if (pShareHelper)
		{
			bRet = pShareHelper->isScreenSharingOut();
		}
	}
	return bRet;
}
bool ZShareHelperWrap::IsOtherSharing()
{
	bool bRet = false;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKShareHelper* pShareHelper = pVideoSDK->getShareHelper();
		if (pShareHelper)
		{
			bRet = pShareHelper->isOtherSharing();
		}
	}
	return bRet;
}
ZNZoomVideoSDKErrors ZShareHelperWrap::LockShare(bool lock)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKShareHelper* pShareHelper = pVideoSDK->getShareHelper();
		if (pShareHelper)
		{
			err = (ZNZoomVideoSDKErrors)pShareHelper->lockShare(lock);
		}
	}
	return err;
}
bool ZShareHelperWrap::IsShareLocked()
{
	bool bRet = false;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKShareHelper* pShareHelper = pVideoSDK->getShareHelper();
		if (pShareHelper)
		{
			bRet = pShareHelper->isShareLocked();
		}
	}
	return bRet;
}
ZNZoomVideoSDKErrors ZShareHelperWrap::EnableShareDeviceAudio(bool bEnable)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKShareHelper* pShareHelper = pVideoSDK->getShareHelper();
		if (pShareHelper)
		{
			err = (ZNZoomVideoSDKErrors)pShareHelper->enableShareDeviceAudio(bEnable);
		}
	}
	return err;
}
bool ZShareHelperWrap::IsShareDeviceAudioEnabled()
{
	bool bRet = false;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKShareHelper* pShareHelper = pVideoSDK->getShareHelper();
		if (pShareHelper)
		{
			bRet = pShareHelper->isShareDeviceAudioEnabled();
		}
	}
	return bRet;
}
ZNZoomVideoSDKErrors ZShareHelperWrap::EnableOptimizeForSharedVideo(bool bEnable)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKShareHelper* pShareHelper = pVideoSDK->getShareHelper();
		if (pShareHelper)
		{
			err = (ZNZoomVideoSDKErrors)pShareHelper->enableOptimizeForSharedVideo(bEnable);
		}
	}
	return err;
}
bool ZShareHelperWrap::IsOptimizeForSharedVideoEnabled()
{
	bool bRet = false;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKShareHelper* pShareHelper = pVideoSDK->getShareHelper();
		if (pShareHelper)
		{
			bRet = pShareHelper->isOptimizeForSharedVideoEnabled();
		}
	}
	return bRet;
}
ZNZoomVideoSDKErrors ZShareHelperWrap::StartShare2ndCamera(ZoomSTRING cameraID)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKShareHelper* pShareHelper = pVideoSDK->getShareHelper();
		if (pShareHelper)
		{
			err = (ZNZoomVideoSDKErrors)pShareHelper->startShare2ndCamera(cameraID.c_str());
		}
	}
	return err;
}
unsigned long long ZShareHelperWrap::GetRecvHandle()
{
	return m_recv_handle;
}
///////////////////////////////////////////////////////////////////////////////////////////
#ifdef WIN32
ZShareInfoHelperWrap::ZShareInfoHelperWrap()
{
}
ZShareInfoHelperWrap::~ZShareInfoHelperWrap()
{
	m_monitorsList.clear();
}

BOOL CALLBACK MyInfoEnumProc(HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData)
{
	MONITORINFOEX iMonitor;
	iMonitor.cbSize = sizeof(MONITORINFOEX);
	GetMonitorInfo(hMonitor, &iMonitor);

	if (iMonitor.dwFlags == DISPLAY_DEVICE_MIRRORING_DRIVER)
	{
		return true;
	}
	else
	{
		ZoomSTRING temp_monitorDevice;
		utf8to16(iMonitor.szDevice, temp_monitorDevice);
		reinterpret_cast< std::vector<std::wstring>* >(dwData)->push_back(temp_monitorDevice.c_str());
		return true;
	}
}

ZNList<ZoomSTRING> ZShareInfoHelperWrap::GetMonitorsList()
{
	m_monitorsList.clear();
	EnumDisplayMonitors(NULL, NULL, &MyInfoEnumProc, reinterpret_cast<LPARAM>(&m_monitorsList));
	return m_monitorsList;
}
#elif (defined __linux)
ZShareInfoHelperWrap::ZShareInfoHelperWrap()
{
}
ZShareInfoHelperWrap::~ZShareInfoHelperWrap()
{
	m_monitorsList.clear();
}

ZNList<ZoomSTRING> ZShareInfoHelperWrap::GetMonitorsList()
{
	return m_monitorsList;
}
#endif
