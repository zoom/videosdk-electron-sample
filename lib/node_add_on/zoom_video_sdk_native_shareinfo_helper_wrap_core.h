#pragma once
#ifdef WIN32
#include "zoom_video_sdk_native_sdk_wrap_core_def.h"
#endif
#include "zoom_video_sdk_sinks_wrap_class.h"


struct AppInfo
{
	uint64_t handle;
	int32_t processId;
	ZoomSTRING appName;
	ZoomSTRING title;
	AppInfo()
	{
		handle = -1;
		processId = -1;
	}
};

typedef std::vector<AppInfo> AppList;

enum WindowsMajorVersions 
{
	kWindows10 = 10,
};

class ZShareInfoHelperWrap
{
public:
	ZShareInfoHelperWrap();
	virtual ~ZShareInfoHelperWrap();

	ZNList<ZoomSTRING> GetMonitorsList();
	ZNList<AppInfo> GetAppList();
private:
	ZNList<ZoomSTRING> m_monitorsList;
	ZNList<AppInfo> m_appsList;
};
