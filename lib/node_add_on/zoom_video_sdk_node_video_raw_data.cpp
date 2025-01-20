#include "zoom_video_sdk_node_video_raw_data.h"
#include "zoom_video_sdk_native_video_raw_data_helper.h"
#include <mutex>
#define dalay_run_timer_interval 2000 //simple set the interval timer to be 2 seconds

extern ZoomVideoNodePipeServerMgr _g_video_pipe_server;

void TimerFunc()
{
	ZoomVideoNodeSDKDelayGC::GetInst().Hearbeat();
}

ZoomVideoNodeSDKVideoRenderWrap::ZoomVideoNodeSDKVideoRenderWrap()
{
}
ZoomVideoNodeSDKVideoRenderWrap::~ZoomVideoNodeSDKVideoRenderWrap()
{
}

void ZoomVideoNodeSDKVideoRenderWrap::Subscribe(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors err = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Internal_Error;
	
	
	do
	{
		com::electron::zoomvideo::sdk::proto::SubscribeParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::SubscribeParams >(args, proto_param))
		{
			err = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_zn_recv_handle() ||
			!proto_param.has_zn_user() ||
			!proto_param.has_zn_type() ||
			!proto_param.has_zn_resolution()
			)
		{
			err = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		int zn_type = (int)proto_param.zn_type();
		unsigned long long zn_recv_handle = (unsigned long long)proto_param.zn_recv_handle();
		std::map<unsigned long long, ZNativeVideoSDKVideoRawDataHelper*>::iterator iter = ZoomVideoNodeRawDataHelperMgr::GetInst().m_videorawdatahelper_map.find(zn_recv_handle);
		if (ZoomVideoNodeRawDataHelperMgr::GetInst().m_videorawdatahelper_map.end() == iter)
		{
			ZNativeVideoSDKVideoRawDataHelper* pRawDataHelper = new ZNativeVideoSDKVideoRawDataHelper;
			if (pRawDataHelper)
			{
				std::pair <std::map<unsigned long long, ZNativeVideoSDKVideoRawDataHelper*>::iterator, bool> ret_pair = ZoomVideoNodeRawDataHelperMgr::GetInst().m_videorawdatahelper_map.insert(std::make_pair(zn_recv_handle, pRawDataHelper));
				if (!ret_pair.second)
				{
					break;
				}
				iter = ret_pair.first;
			}
			else
			{
				break;
			}
		}
		com::electron::zoomvideo::sdk::proto::VideoSDKUser _User = proto_param.zn_user();

		
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* zn_pUser = (ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser*)_User.p_user();
		ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKResolution zn_resolution = (ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKResolution)proto_param.zn_resolution();
		ZNativeVideoSDKVideoRawDataHelper* pTempHelper = (*iter).second;
		if (pTempHelper)
		{
			err = pTempHelper->Subscribe(zn_pUser, zn_recv_handle, (ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKRawDataType)zn_type, zn_resolution);
		}
		else
		{
			break;
		}

	} while (false);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeSDKVideoRenderWrap::UnSubscribe(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors err = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Internal_Error;
	do
	{
		com::electron::zoomvideo::sdk::proto::UnSubscribeParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::UnSubscribeParams >(args, proto_param))
		{
			err = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_zn_recv_handle() ||
			!proto_param.has_zn_user() ||
			!proto_param.has_zn_type()
			)
		{
			err = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		unsigned long long zn_recv_handle = (unsigned long long)proto_param.zn_recv_handle();

		com::electron::zoomvideo::sdk::proto::VideoSDKUser _User = proto_param.zn_user();

		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* zn_pUser = (ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser*)_User.p_user();
		ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKRawDataType zn_type = (ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKRawDataType)proto_param.zn_type();
		std::map<unsigned long long, ZNativeVideoSDKVideoRawDataHelper*>::iterator iter = ZoomVideoNodeRawDataHelperMgr::GetInst().m_videorawdatahelper_map.find(zn_recv_handle);
		if (ZoomVideoNodeRawDataHelperMgr::GetInst().m_videorawdatahelper_map.end() != iter)
		{
			ZNativeVideoSDKVideoRawDataHelper* pTempHelper = (*iter).second;
			if (pTempHelper)
			{
				err = pTempHelper->UnSubscribe(zn_pUser, zn_type);
				if (ZoomVideoSDKErrors_Success == err)
				{
					ZoomVideoNodeSDKDelayGC::GetInst().AddToPotentialDeleteList((unsigned long long)pTempHelper);
					ZoomVideoNodeRawDataHelperMgr::GetInst().m_videorawdatahelper_map.erase(zn_recv_handle);
				}
			}
		}
		else
		{
			err = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Invalid_Parameter;
		}
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
//////////////////////////////////////////////////////////////////////////////////////
void ZoomVideoNodeSDKVideoRenderWrap::SubscribeMultiCameraStream(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors err = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Internal_Error;
	
	do
	{
		com::electron::zoomvideo::sdk::proto::SubscribeMultiCameraStreamParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::SubscribeMultiCameraStreamParams >(args, proto_param))
		{
			err = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_zn_recv_handle() ||
			!proto_param.has_zn_user() ||
			!proto_param.has_camerastreamid() ||
			!proto_param.has_zn_resolution()
			)
		{
			err = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}


		unsigned long long zn_recv_handle = (unsigned long long)proto_param.zn_recv_handle();
		ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKResolution zn_resolution = (ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKResolution)proto_param.zn_resolution();
		com::electron::zoomvideo::sdk::proto::VideoSDKUser _User = proto_param.zn_user();
		int64_t zn_pUser = (int64_t)_User.p_user();
		std::map<int64_t, std::map<int32_t, int64_t > >::iterator iter_user = ZoomVideoNodeMultiCameraStreamHelperMgr::GetInst().m_multicamerastreamhelper_map.find(zn_pUser);
		if (ZoomVideoNodeMultiCameraStreamHelperMgr::GetInst().m_multicamerastreamhelper_map.end() == iter_user)
		{
			err = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		std::map<int32_t, int64_t >::iterator iter_camerastreamid = iter_user->second.find((int32_t)proto_param.camerastreamid());
		if (iter_user->second.end() == iter_camerastreamid)
		{
			err = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		std::map<unsigned long long, ZNativeVideoSDKVideoRawDataHelper*>::iterator iter = ZoomVideoNodeRawDataHelperMgr::GetInst().m_videorawdatahelper_map.find(zn_recv_handle);
		if (ZoomVideoNodeRawDataHelperMgr::GetInst().m_videorawdatahelper_map.end() == iter)
		{
			ZNativeVideoSDKVideoRawDataHelper* pRawDataHelper = new ZNativeVideoSDKVideoRawDataHelper;
			if (pRawDataHelper)
			{
				std::pair <std::map<unsigned long long, ZNativeVideoSDKVideoRawDataHelper*>::iterator, bool> ret_pair = ZoomVideoNodeRawDataHelperMgr::GetInst().m_videorawdatahelper_map.insert(std::make_pair(zn_recv_handle, pRawDataHelper));
				if (!ret_pair.second)
				{
					break;
				}
				iter = ret_pair.first;
			}
			else
			{
				break;
			}
		}
		
		ZNativeVideoSDKVideoRawDataHelper* pTempHelper = (*iter).second;
		if (pTempHelper)
		{
			err = pTempHelper->SubscribeMultiCameraStream((ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser*)_User.p_user(), zn_recv_handle, (ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRawDataPipe*)iter_camerastreamid->second, zn_resolution);
		}
		else
		{
			break;
		}

	} while (false);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeSDKVideoRenderWrap::UnSubscribeMultiCameraStream(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors err = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Internal_Error;
	
	do
	{
		com::electron::zoomvideo::sdk::proto::UnSubscribeMultiCameraStreamParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::UnSubscribeMultiCameraStreamParams >(args, proto_param))
		{
			err = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_zn_recv_handle() ||
			!proto_param.has_zn_user() ||
			!proto_param.has_camerastreamid()
			)
		{
			err = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		unsigned long long zn_recv_handle = (unsigned long long)proto_param.zn_recv_handle();

		com::electron::zoomvideo::sdk::proto::VideoSDKUser _User = proto_param.zn_user();
		int64_t zn_pUser = (int64_t)_User.p_user();
		std::map<int64_t, std::map<int32_t, int64_t > >::iterator iter_user = ZoomVideoNodeMultiCameraStreamHelperMgr::GetInst().m_multicamerastreamhelper_map.find(zn_pUser);
		if (ZoomVideoNodeMultiCameraStreamHelperMgr::GetInst().m_multicamerastreamhelper_map.end() == iter_user)
		{
			err = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		std::map<int32_t, int64_t >::iterator iter_camerastreamid = iter_user->second.find((int32_t)proto_param.camerastreamid());
		if (iter_user->second.end() == iter_camerastreamid)
		{
			err = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		std::map<unsigned long long, ZNativeVideoSDKVideoRawDataHelper*>::iterator iter = ZoomVideoNodeRawDataHelperMgr::GetInst().m_videorawdatahelper_map.find(zn_recv_handle);
		if (ZoomVideoNodeRawDataHelperMgr::GetInst().m_videorawdatahelper_map.end() != iter)
		{
			ZNativeVideoSDKVideoRawDataHelper* pTempHelper = (*iter).second;
			if (pTempHelper)
			{
				err = pTempHelper->UnSubscribeMultiCameraStream((ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser*)_User.p_user(), (ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRawDataPipe*)iter_camerastreamid->second);
				if (ZoomVideoSDKErrors_Success == err)
				{
					ZoomVideoNodeSDKDelayGC::GetInst().AddToPotentialDeleteList((unsigned long long)pTempHelper);
					ZoomVideoNodeRawDataHelperMgr::GetInst().m_videorawdatahelper_map.erase(zn_recv_handle);
				}
			}
		}
		else
		{
			err = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Invalid_Parameter;
		}
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeSDKVideoRenderWrap::GetMultiCameraStreamList(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	v8::Isolate* isolate = args.GetIsolate();
	com::electron::zoomvideo::sdk::proto::GetMultiCameraStreamList proto_param;
	if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::GetMultiCameraStreamList >(args, proto_param))
	{
		err = ZNZoomVideoSDKErrors_Invalid_Parameter;
	}

	if (!proto_param.has_user())
	{
		err = ZNZoomVideoSDKErrors_Invalid_Parameter;
	}
	com::electron::zoomvideo::sdk::proto::VideoSDKUser _User = proto_param.user();

	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* zn_pUser = (ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser*)_User.p_user();
	com::electron::zoomvideo::sdk::proto::MultiCameraStreamList _MultiCameraStreamLst;
	if (err == ZNZoomVideoSDKErrors_Success)
	{
		_g_native_wrap.GetVideoHelperWrap().GetMultiCameraStreamList(_MultiCameraStreamLst, zn_pUser);
	}
	size_t _size = _MultiCameraStreamLst.ByteSize();
	auto array_buf = v8::ArrayBuffer::New(isolate, _size);
	char* char_temp_param = nullptr;
	size_t sz_temp_param = 0;
	fnGetRawArrayBufferPtr pGetRawArrayBufferPtr = NULL;
	pGetRawArrayBufferPtr = ZoomNodeAPIUtilHelper::GetInst().m_fnGetRawArrayBufferPtr;
	if (!pGetRawArrayBufferPtr)
	{
		return;
	}
	pGetRawArrayBufferPtr(array_buf, (void**)(&char_temp_param), sz_temp_param);
	_MultiCameraStreamLst.SerializeToArray(char_temp_param, _size);
	v8::Local<v8::Uint8Array> uint8_array_buf = v8::Uint8Array::New(array_buf, 0, _size);

	args.GetReturnValue().Set(uint8_array_buf);
}
//////////////////////////////////////////////////////////////
ZoomVideoNodeSDKDelayGC::ZoomVideoNodeSDKDelayGC()
{
	StartTimer();
}
ZoomVideoNodeSDKDelayGC::~ZoomVideoNodeSDKDelayGC()
{
	StopTimer();
	m_mutex.lock();
	if (m_realDeleteMap.size() > 0)
	{
		std::map<unsigned long long, bool>::iterator iter = m_realDeleteMap.begin();
		for (; m_realDeleteMap.end() != iter; iter++)
		{
			ZNativeVideoSDKVideoRawDataHelper* pTempHelper = (ZNativeVideoSDKVideoRawDataHelper*)(*iter).first;
			if (pTempHelper)
			{
				delete pTempHelper;
			}
			std::map<unsigned long long, bool>::iterator iter_potential = m_potentialDeleteMap.find((*iter).first);
			if (iter_potential != m_potentialDeleteMap.end())
			{
				m_potentialDeleteMap.erase(iter_potential);
			}
		}
		m_realDeleteMap.clear();
	}
	if (m_potentialDeleteMap.size() > 0)
	{
		std::map<unsigned long long, bool>::iterator iter = m_potentialDeleteMap.begin();
		for (; m_potentialDeleteMap.end() != iter; iter++)
		{
			ZNativeVideoSDKVideoRawDataHelper* pTempHelper = (ZNativeVideoSDKVideoRawDataHelper*)(*iter).first;
			if (pTempHelper)
			{
				delete pTempHelper;
			}
		}
		m_potentialDeleteMap.clear();
	}
	m_mutex.unlock();
}
void ZoomVideoNodeSDKDelayGC::StartTimer()
{
	m_timer.StartTimer(dalay_run_timer_interval, std::bind(TimerFunc));
}

void ZoomVideoNodeSDKDelayGC::StopTimer()
{
	m_timer.StopTimer();
}

void ZoomVideoNodeSDKDelayGC::Hearbeat()
{
	if (m_realDeleteMap.size() <= 0)
		return;
	m_mutex.lock();
	std::map<unsigned long long, bool> tmp_delete;
	std::map<unsigned long long, bool> tmp_try_to_delete;
	tmp_try_to_delete.swap(m_realDeleteMap);
	std::map<unsigned long long, bool>::iterator iter = tmp_try_to_delete.begin();
	for (; tmp_try_to_delete.end() != iter; iter++)
	{
		bool bNeedDelete = (*iter).second;
		if (bNeedDelete)
		{
			ZNativeVideoSDKVideoRawDataHelper* pTempHelper = (ZNativeVideoSDKVideoRawDataHelper*)(*iter).first;
			if (pTempHelper)
			{
				delete pTempHelper;
			}
			std::map<unsigned long long, bool>::iterator iter_potential = m_potentialDeleteMap.find((*iter).first);
			if (iter_potential != m_potentialDeleteMap.end())
			{
				m_potentialDeleteMap.erase(iter_potential);
			}
		}
		else
		{
			tmp_delete.insert(std::make_pair(iter->first, true));
		}
	}
	m_potentialDeleteMap.clear();
	m_potentialDeleteMap.swap(tmp_delete);
	m_mutex.unlock();
}

void ZoomVideoNodeSDKDelayGC::AddToRealDeleteList(unsigned long long rawDataHelper)
{
	m_mutex.lock();
	std::map<unsigned long long, bool>::iterator iter = m_potentialDeleteMap.find(rawDataHelper);
	if(iter != m_potentialDeleteMap.end())
	{
		m_realDeleteMap.insert(std::make_pair(rawDataHelper, false));
	}
	m_mutex.unlock();
}

void ZoomVideoNodeSDKDelayGC::AddToPotentialDeleteList(unsigned long long rawDataHelper)
{
	m_mutex.lock();
	std::map<unsigned long long, bool>::iterator iter = m_potentialDeleteMap.find(rawDataHelper);
	if (iter != m_potentialDeleteMap.end())
	{
		m_potentialDeleteMap.insert(std::make_pair(rawDataHelper, false));
	}
	m_mutex.unlock();
}