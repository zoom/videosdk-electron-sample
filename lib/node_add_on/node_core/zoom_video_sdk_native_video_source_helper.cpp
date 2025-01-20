#include "zoom_video_sdk_native_video_source_helper.h"
#include "zoom_video_sdk_node_rawdata_helper_mgr_class.h"

extern ZoomInstantNodePipeServerMgr _g_video_pipe_server;
extern ZNativeInstantSDKWrap _g_native_wrap;

ZNativeInstantVideoSourcePreProcessor::ZNativeInstantVideoSourcePreProcessor()
{

}
ZNativeInstantVideoSourcePreProcessor::~ZNativeInstantVideoSourcePreProcessor()
{
	
}
#define max_cache_frame_ 10
#define pre_process_rawdata_source_id 0
void ZNativeInstantVideoSourcePreProcessor::onPreProcessRawData(YUVProcessDataI420* rawData)
{
	if (_g_video_pipe_server._uv_ipc_server.HasClientConnected() && rawData)
	{
		{
			std::lock_guard<std::mutex> lock_(_g_video_pipe_server._cached_raw_data_count_map_mutex);
			std::map<unsigned int, int>::iterator iter = _g_video_pipe_server._cached_raw_data_count_map.find(pre_process_rawdata_source_id);
			if (_g_video_pipe_server._cached_raw_data_count_map.end() != iter)
			{
				if (iter->second > max_cache_frame_)
				{
					return;
				}
				else
				{
					++iter->second;
				}
			}
			else
			{
				_g_video_pipe_server._cached_raw_data_count_map.insert(std::make_pair(pre_process_rawdata_source_id, 1));
			}
		}
		UVIPCMessage* rawdata_msg = MakeUVIPCMsg(rawData, 0, TYPE_VIDEO);
		_g_video_pipe_server._uv_ipc_server.SendMessage(rawdata_msg);
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//ZNativeInstantVideoSource::ZNativeInstantVideoSource()
//{
//	m_pVideoSender = NULL;
//	m_pVideoCapabilityHelper = NULL;
//}
//ZNativeInstantVideoSource::~ZNativeInstantVideoSource()
//{
//	m_pVideoSender = NULL;
//	m_pVideoCapabilityHelper = NULL;
//}
//
//void ZNativeInstantVideoSource::onInitialize(ZOOM_INSTANT_SDK_NAMESPACE::IZoomInstantSDKVideoSender* sender, ZOOM_INSTANT_SDK_NAMESPACE::IZoomInstantSDKVideoCapabilityHelper* helper)
//{
//	//fix me
//	if (sender)
//	{
//		m_pVideoSender = sender;
//	}
//	if (helper)
//	{
//		m_pVideoCapabilityHelper = helper;
//		
//		ZNList<ZNZoomInstantSDKVideoCapability> zn_videocapability_list;
//		unsigned int nCount = helper->getMaxCapabilityCount();
//		for (int i = 0; i < nCount; ++i)
//		{
//			ZOOM_INSTANT_SDK_NAMESPACE::IZoomInstantSDKVideoCapability* pCapability = helper->getCapability(i);
//			ZNZoomInstantSDKVideoCapability zn_videoCap;
//			if (pCapability)
//			{
//				zn_videoCap.isEfficient = pCapability->isEfficient();
//				zn_videoCap.width = pCapability->getWidth();
//				zn_videoCap.height = pCapability->getHeight();
//				zn_videoCap.frame = pCapability->getFrame();
//			}
//			zn_videocapability_list.push_back(zn_videoCap);
//		}
//	}
//	//m_pSink->OnVideoSourceInitialize(zn_videocapability_list);
//	
//}
//void ZNativeInstantVideoSource::onPropertyChange(ZOOM_INSTANT_SDK_NAMESPACE::IZoomInstantSDKVideoCapability* item)
//{
//	//fix me
//	
//	if (item)
//	{
//		ZNZoomInstantSDKVideoCapability zn_videoCap;
//		zn_videoCap.isEfficient = item->isEfficient();
//		zn_videoCap.width = item->getWidth();
//		zn_videoCap.height = item->getHeight();
//		zn_videoCap.frame = item->getFrame();
//		//m_pSink->onPropertyChange(zn_videoCap);
//	}
//	
//}
//void ZNativeInstantVideoSource::onStartSend()
//{
//	//fix me
//}
//void ZNativeInstantVideoSource::onStopSend()
//{
//	//fix me
//}
//void ZNativeInstantVideoSource::onUninitialized()
//{
//	//fix me
//}
//

///////////////////////

