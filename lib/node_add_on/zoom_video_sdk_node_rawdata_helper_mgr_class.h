#ifndef _zoom_video_sdk_node_rawdata_helper_mgr_class_h_
#define _zoom_video_sdk_node_rawdata_helper_mgr_class_h_
#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_singleton_wrap_class.h"
#include "zoom_video_sdk_native_sdk_wrap_core_def.h"
#include "zoom_video_sdk_native_video_raw_data_helper.h"

#include <mutex>
#include <thread>
#include <map>
#include <iostream>
#include <string>
#include "raw_data_uv_ipc_server.h"
#include "raw_data_format.h"

////////////////////////////////////////////////////////////////////////////////
class ZoomVideoNodeRawDataHelperMgr
{
public:
	std::map<unsigned long long, ZNativeVideoSDKVideoRawDataHelper* > m_videorawdatahelper_map;

public:
	static ZoomVideoNodeRawDataHelperMgr& GetInst()
	{
		static ZoomVideoNodeRawDataHelperMgr inst;
		return inst;
	}
	~ZoomVideoNodeRawDataHelperMgr()
	{
		std::map<unsigned long long, ZNativeVideoSDKVideoRawDataHelper*>::iterator iter;
		for (iter = m_videorawdatahelper_map.begin(); iter != m_videorawdatahelper_map.end(); )
		{
			delete iter->second;
			m_videorawdatahelper_map.erase(iter++);
		}
		m_videorawdatahelper_map.clear();
	}
private:
	ZoomVideoNodeRawDataHelperMgr() {}

};
class ZoomVideoNodeUtilityHelper
{
public:
	static ZoomVideoNodeUtilityHelper& GetInst()
	{
		static ZoomVideoNodeUtilityHelper inst;
		return inst;
	}
	~ZoomVideoNodeUtilityHelper(){}
	void ConvertSDKUserToProtoUser(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pSdkUser, com::electron::zoomvideo::sdk::proto::VideoSDKUser* pProtoUser);
	void ConvertSDKShareActionToProtoShareAction(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKShareAction* pShareAction, com::electron::zoomvideo::sdk::proto::ShareAction* pProtoShareAction);
private:
	ZoomVideoNodeUtilityHelper() {}
};

class ZoomVideoNodePipeServerMgr : public UVIPCSink
{
public:
	ZoomVideoNodePipeServerMgr() {}
	~ZoomVideoNodePipeServerMgr() {}

	virtual void onConnect() 
	{
		
	}
	virtual void onDisconnect() 
	{
		
	}
	virtual void onMessageRecvNotification(UVIPCMessage* msg);
	virtual void onIdle() {}

public:
	RawDataUVIPCServer _uv_ipc_server;
	std::mutex _cached_raw_data_count_map_mutex;
	std::map<unsigned int, int > _cached_raw_data_count_map;
};
class ZoomVideoNodeMultiCameraStreamHelperMgr
{
public:
	std::map<int64_t, std::map<int32_t, int64_t > > m_multicamerastreamhelper_map;
	void Clear()
	{
		std::map<int64_t, std::map<int32_t, int64_t > >::iterator iter_user;
		for (iter_user = m_multicamerastreamhelper_map.begin(); iter_user != m_multicamerastreamhelper_map.end(); )
		{
			std::map<int32_t, int64_t >::iterator iter_camerastreamid;
			for (iter_camerastreamid = iter_user->second.begin(); iter_camerastreamid != iter_user->second.end();)
			{
				iter_user->second.erase(iter_camerastreamid++);
			}
			iter_user->second.clear();
			m_multicamerastreamhelper_map.erase(iter_user++);
		}
		m_multicamerastreamhelper_map.clear();
	}

public:
	static ZoomVideoNodeMultiCameraStreamHelperMgr& GetInst()
	{
		static ZoomVideoNodeMultiCameraStreamHelperMgr inst;
		return inst;
	}
	~ZoomVideoNodeMultiCameraStreamHelperMgr()
	{
		Clear();
	}
private:
	ZoomVideoNodeMultiCameraStreamHelperMgr() {}

};
#endif 
