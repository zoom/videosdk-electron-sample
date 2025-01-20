#pragma once
#ifdef WIN32
#include "zoom_video_sdk_native_sdk_wrap_core_def.h"
#endif
#include "zoom_video_sdk_sinks_wrap_class.h"

class ZShareInfoHelperWrap
{
public:
	ZShareInfoHelperWrap();
	virtual ~ZShareInfoHelperWrap();

	ZNList<ZoomSTRING> GetMonitorsList();
private:
	ZNList<ZoomSTRING> m_monitorsList;

};
