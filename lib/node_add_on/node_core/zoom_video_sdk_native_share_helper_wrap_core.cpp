#include "zoom_video_sdk_native_share_helper_wrap_core.h"
#if (defined WIN32) || (defined __linux)
#include "zoom_video_sdk_native_shareinfo_helper_wrap_core.h"
#endif
#include "zoom_video_sdk_native_sdk_wrap_core.h"

#ifdef WIN32
#include <windows.h>
#include <wrl/client.h>
#include <vector>
#include <dwmapi.h>
#pragma comment(lib, "Dwmapi.lib")
#include <shobjidl.h>
#include <combaseapi.h>
#endif

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
			long windowid = std::stol(handle);
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
			ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAnnotationHelper* pAnnotationHelper = ZShareHelperWrap::GetAnnotationHelper();
			if (pAnnotationHelper)
			{
				ZShareHelperWrap::DestroyAnnotationHelper();
			}
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
ZNZoomVideoSDKErrors ZShareHelperWrap::PauseShare()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKShareHelper* pShareHelper = pVideoSDK->getShareHelper();
		if (pShareHelper)
		{
			err = (ZNZoomVideoSDKErrors)pShareHelper->pauseShare();
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZShareHelperWrap::ResumeShare()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKShareHelper* pShareHelper = pVideoSDK->getShareHelper();
		if (pShareHelper)
		{
			err = (ZNZoomVideoSDKErrors)pShareHelper->resumeShare();
		}
	}
	return err;
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
ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAnnotationHelper* ZShareHelperWrap::GetAnnotationHelper()
{
	return m_AnnotationHelper;
}
ZNZoomVideoSDKErrors ZShareHelperWrap::CreateAnnotationHelper()
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
		if (pShareHelper->isOtherSharing())
		{
			err = ZNZoomVideoSDKErrors_Wrong_Usage;
			break;
		}
#ifdef __linux
		err = ZNZoomVideoSDKErrors_Dont_Support_Feature;
#else
		m_AnnotationHelper = pShareHelper->createAnnotationHelper(NULL);
#endif
	} while (false);

	if (m_AnnotationHelper)
	{
		return ZNZoomVideoSDKErrors_Success;
	}
	return err;
}
ZNZoomVideoSDKErrors ZShareHelperWrap::DestroyAnnotationHelper()
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
		if (m_AnnotationHelper)
		{
			err = (ZNZoomVideoSDKErrors)pShareHelper->destroyAnnotationHelper(m_AnnotationHelper);
			m_AnnotationHelper = nullptr;
		}

	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZShareHelperWrap::SetAnnotationVanishingToolTime(unsigned int displayTime, unsigned int vanishingTime)
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

		err = (ZNZoomVideoSDKErrors)pShareHelper->setAnnotationVanishingToolTime(displayTime, vanishingTime);
	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZShareHelperWrap::GetAnnotationVanishingToolTime(unsigned int& zn_displayTime, unsigned int& zn_vanishingTime)
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
		unsigned int displayTime = 0;
		unsigned int vanishingTime = 0;
		err = (ZNZoomVideoSDKErrors)pShareHelper->getAnnotationVanishingToolTime(displayTime, vanishingTime);
		if (ZNZoomVideoSDKErrors_Success == err)
		{
			zn_displayTime = displayTime;
			zn_vanishingTime = vanishingTime;
		}
	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZShareHelperWrap::StartShareApplication(uint32_t processID, ZNZoomVideoSDKShareOption option)
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
		if (processID > 0)
		{
			err = (ZNZoomVideoSDKErrors)pShareHelper->startShareApplication(processID, sdk_shareOption);
		}

	} while (false);
	return err;
}
///////////////////////////////////////////////////////////////////////////////////////////
#ifdef WIN32
ZShareInfoHelperWrap::ZShareInfoHelperWrap()
{
}
ZShareInfoHelperWrap::~ZShareInfoHelperWrap()
{
	m_monitorsList.clear();
	m_appsList.clear();
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

bool IsWindowResponding(HWND window) 
{
	const UINT uTimeoutMs = 50;
	return SendMessageTimeout(window, WM_NULL, 0, 0, SMTO_ABORTIFHUNG, uTimeoutMs, nullptr);
}
bool CanSafelyMakeBlockingCalls(HWND hwnd) 
{
	DWORD process_id;
	GetWindowThreadProcessId(hwnd, &process_id);
	if (process_id != GetCurrentProcessId() || IsWindowResponding(hwnd)) 
	{
		return true;
	}
	return false;
}
bool IsWindowValidAndVisible(HWND window) 
{
	return IsWindow(window) && IsWindowVisible(window) && !IsIconic(window);
}
bool GetOsVersion(int* major, int* minor, int* build)
{
	OSVERSIONINFO info = { 0 };
	info.dwOSVersionInfoSize = sizeof(info);
	if (GetVersionEx(&info)) {
		if (major)
			*major = info.dwMajorVersion;
		if (minor)
			*minor = info.dwMinorVersion;
		if (build)
			*build = info.dwBuildNumber;
		return true;
	}
	return false;
}
bool IsWindows10OrLater() 
{
	int major;
	return (GetOsVersion(&major, nullptr, nullptr) && (major >= kWindows10));
}
bool IsWindowOnCurrentDesktop(HWND hwnd) 
{
	BOOL on_current_desktop = TRUE;
	Microsoft::WRL::ComPtr<IVirtualDesktopManager> virtual_desktop_manager;
	if (IsWindows10OrLater()) 
	{
		HRESULT hr = ::CoCreateInstance(CLSID_VirtualDesktopManager, nullptr, CLSCTX_ALL, IID_PPV_ARGS(&virtual_desktop_manager));
		if (FAILED(hr)) {
			return on_current_desktop;
		}
		virtual_desktop_manager->IsWindowOnCurrentVirtualDesktop(hwnd, &on_current_desktop);
	}
	return on_current_desktop;
}
bool IsWindowCloaked(HWND hwnd) 
{
	int res = 0;
	DwmGetWindowAttribute(hwnd, DWMWA_CLOAKED, &res, sizeof(res));
	return res != 0;
}
bool IsWindowVisibleOnCurrentDesktop(HWND hwnd) 
{
	return IsWindowValidAndVisible(hwnd) && IsWindowOnCurrentDesktop(hwnd) && !IsWindowCloaked(hwnd);
}
BOOL CALLBACK GetAppListHandler(HWND hwnd, LPARAM param) {
	AppList* app_list = reinterpret_cast<AppList*>(param);
	if (!IsWindowVisible(hwnd) || IsIconic(hwnd)) 
	{
		return TRUE;
	}

	LONG_PTR wnd_style_ex = GetWindowLongPtr(hwnd, GWL_EXSTYLE);
	if ((WS_EX_APPWINDOW & wnd_style_ex) == WS_EX_APPWINDOW)
	{
		return TRUE;
	}
	if (!IsWindowResponding(hwnd)) 
	{
		return TRUE;
	}
	AppInfo app;
	app.handle = reinterpret_cast<uint64_t>(hwnd);

	DWORD processId = 0;
	GetWindowThreadProcessId(hwnd, &processId);
	app.processId = static_cast<uint32_t>(processId);

	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processId);
	if (hProcess) {
		WCHAR processName[MAX_PATH] = L"";
		DWORD size = MAX_PATH;
		if (QueryFullProcessImageNameW(hProcess, 0, processName, &size)) {
			WCHAR* fileName = wcsrchr(processName, L'\\');
			if (fileName) {
				fileName++; // Skip backslash
				app.appName = fileName;
			} else {
				app.appName = processName;
			}
		}
		CloseHandle(hProcess);
	}

	if (CanSafelyMakeBlockingCalls(hwnd))
	{
		const size_t kTitleLength = 500;
		WCHAR window_title[kTitleLength] = L"";
		if (GetWindowTextLength(hwnd) != 0 &&
			GetWindowTextW(hwnd, window_title, kTitleLength) > 0) 
		{
			app.title = window_title;
		}
	}

	if (app.appName.empty() || app.title.empty())
	{
		return TRUE;
	}

	const size_t kMaxClassNameLength = 256;
	WCHAR class_name[kMaxClassNameLength] = L"";
	const int class_name_length = GetClassNameW(hwnd, class_name, kMaxClassNameLength);
	if (class_name_length < 1)
		return TRUE;

	// Skip Program Manager window.
	if (wcscmp(class_name, L"Progman") == 0) {
		return TRUE;
	}

	if (wcscmp(class_name, L"Button") == 0) {
		return TRUE;
	}
	app_list->push_back(app);
	return TRUE;
}
AppList ZShareInfoHelperWrap::GetAppList()
{
	m_appsList.clear();
	EnumWindows(&GetAppListHandler, reinterpret_cast<LPARAM>(&m_appsList));

	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (!pVideoSDK)
	{
		return AppList();
	}
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKShareHelper* pShareHelper = pVideoSDK->getShareHelper();
	if (!pShareHelper)
	{
		return AppList();
	}

	for (auto iter = m_appsList.begin(); iter != m_appsList.end();)
	{
		if (!IsWindowVisibleOnCurrentDesktop(reinterpret_cast<HWND>(iter->handle)) ||
			!pShareHelper->isShareViewValid(reinterpret_cast<void*>(iter->handle)))
		{
			iter = m_appsList.erase(iter);
		}
		else 
		{
			++iter;
		}
	}
	return m_appsList;
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
