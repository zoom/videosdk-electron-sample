#include "zoom_video_sdk_native_video_raw_data_helper.h"
#include "zoom_video_sdk_node_rawdata_helper_mgr_class.h"


extern ZoomVideoNodePipeServerMgr _g_video_pipe_server;
extern ZoomVideoNodePipeServerMgr _g_share_pipe_server;
extern ZNativeVideoSDKWrap _g_native_wrap;

ZNativeVideoSDKVideoRawDataHelper::ZNativeVideoSDKVideoRawDataHelper()
{
	m_recv_handle = 0xffffffff;
	m_rawdataType = ZOOM_VIDEO_SDK_NAMESPACE::RAW_DATA_TYPE_VIDEO;
}
ZNativeVideoSDKVideoRawDataHelper::~ZNativeVideoSDKVideoRawDataHelper()
{
	m_recv_handle = 0xffffffff;
	m_rawdataType = ZOOM_VIDEO_SDK_NAMESPACE::RAW_DATA_TYPE_VIDEO;
}


void ZNativeVideoSDKVideoRawDataHelper::onRawDataFrameReceived(YUVRawDataI420* data_)
{}



#define max_cache_frame 10
void ZNativeVideoSDKInternalMagicCallback::onGlobalRawDataFrameReceived(YUVRawDataI420* data_, ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<unsigned long long>* recv_handle, bool is_video)
{
	if (NULL == data_ || NULL == recv_handle)
		return;

	int num = recv_handle->GetCount();
	unsigned long long* recv_handle_list = new unsigned long long[num];
	for (int index = 0; index < num; index++)//fix me
	{
		ZNativeVideoSDKVideoRawDataHelper* real_obj = (ZNativeVideoSDKVideoRawDataHelper*)(recv_handle->GetItem(index));
		if (real_obj)
		{
			recv_handle_list[index] = real_obj->GetRecvHandle();
		}
	}
	if (is_video)
	{
		if (_g_video_pipe_server._uv_ipc_server.HasClientConnected() && data_)
		{
			{
				std::lock_guard<std::mutex> lock_(_g_video_pipe_server._cached_raw_data_count_map_mutex);
				std::map<unsigned int, int>::iterator iter = _g_video_pipe_server._cached_raw_data_count_map.find(data_->GetSourceID());
				if (_g_video_pipe_server._cached_raw_data_count_map.end() != iter)
				{
					if (iter->second > max_cache_frame)
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
					_g_video_pipe_server._cached_raw_data_count_map.insert(std::make_pair(data_->GetSourceID(), 1));
				}
			}
			UVIPCMessage* rawdata_msg = MakeUVIPCMsg(data_, recv_handle_list, num, TYPE_VIDEO);
			if (rawdata_msg)
			{
				_g_video_pipe_server._uv_ipc_server.SendMessage(rawdata_msg);
			}
			else//error case
			{
				std::lock_guard<std::mutex> lock_(_g_video_pipe_server._cached_raw_data_count_map_mutex);
				std::map<unsigned int, int>::iterator iter = _g_video_pipe_server._cached_raw_data_count_map.find(data_->GetSourceID());
				if (_g_video_pipe_server._cached_raw_data_count_map.end() != iter)
				{
					--iter->second;
				}
			}
		}
	}
	else
	{
		if (_g_share_pipe_server._uv_ipc_server.HasClientConnected() && data_)
		{
			{
				std::lock_guard<std::mutex> lock_(_g_share_pipe_server._cached_raw_data_count_map_mutex);
				std::map<unsigned int, int>::iterator iter = _g_share_pipe_server._cached_raw_data_count_map.find(data_->GetSourceID());
				if (_g_share_pipe_server._cached_raw_data_count_map.end() != iter)
				{
					if (iter->second > max_cache_frame)
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
					_g_share_pipe_server._cached_raw_data_count_map.insert(std::make_pair(data_->GetSourceID(), 1));
				}
			}
			UVIPCMessage* rawdata_msg = MakeUVIPCMsg(data_, recv_handle_list, num, TYPE_SHARE);
			if (rawdata_msg)
			{
				_g_share_pipe_server._uv_ipc_server.SendMessage(rawdata_msg);
			}
			else//error case
			{
				std::lock_guard<std::mutex> lock_(_g_share_pipe_server._cached_raw_data_count_map_mutex);
				std::map<unsigned int, int>::iterator iter = _g_share_pipe_server._cached_raw_data_count_map.find(data_->GetSourceID());
				if (_g_share_pipe_server._cached_raw_data_count_map.end() != iter)
				{
					--iter->second;
				}
			}
		}
	}
	if (recv_handle_list)
		delete[] recv_handle_list;
}

void ZNativeVideoSDKVideoRawDataHelper::onRawDataStatusChanged(RawDataStatus status)
{
	
	if (ZoomNodeVideoSinkHelper::GetInst().onNodeAddonCallbacks.IsEmpty())
		return;

	com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
	com::electron::zoomvideo::sdk::proto::CallbackBody_onRawDataStatusChangedParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onRawDataStatusChangedParams;
	callBackBody_temp_param->set_recv_handle(m_recv_handle);
	callBackBody_temp_param->set_status(status);

	callBackBody.set_allocated_onrawdatastatuschangedparam(callBackBody_temp_param);
	callBackBody.set_msgtype(CallMessageType_onRawDataStatusChanged);

	auto isolate = v8::Isolate::GetCurrent();
	v8::HandleScope scope(isolate);
	auto context = isolate->GetCurrentContext();
	auto global = context->Global();

	size_t _size = callBackBody.ByteSize();
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
	callBackBody.SerializeToArray(char_temp_param, _size);
	v8::Local<v8::Uint8Array> uint8_array_buf = v8::Uint8Array::New(array_buf, 0, _size);
	

	int argc = 1;
	v8::Local<v8::Value> argv[1] = { uint8_array_buf };
	auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeVideoSinkHelper::GetInst().onNodeAddonCallbacks);
	
	fn->Call(context, global, argc, argv);
	
}

void ZNativeVideoSDKVideoRawDataHelper::onShareCursorDataReceived(ZoomVideoSDKShareCursorData info)
{
}

ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors ZNativeVideoSDKVideoRawDataHelper::Subscribe(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, unsigned long long recv_handle, ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKRawDataType rawDataType, ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKResolution resolution)
{
	ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors err = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Internal_Error;
	do
	{
		if (!_g_native_wrap.IsValidUser(pUser))
		{
			err = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRawDataPipe* pPipe = NULL;
		if (ZOOM_VIDEO_SDK_NAMESPACE::RAW_DATA_TYPE_VIDEO == rawDataType)
		{
			pPipe = pUser->GetVideoPipe();
			
		}
		if (ZOOM_VIDEO_SDK_NAMESPACE::RAW_DATA_TYPE_SHARE == rawDataType)
		{
			IVideoSDKVector<IZoomVideoSDKShareAction*>* shareActionList = pUser->getShareActionList();
			if (!shareActionList || shareActionList->GetCount() == 0) {
				break;
			}
			pPipe = shareActionList->GetItem(0)->getSharePipe();
		}
		if (!pPipe)
		{
			break;
		}
		m_recv_handle = recv_handle;
		m_rawdataType = rawDataType;
		err = pPipe->subscribe(resolution, dynamic_cast<ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRawDataPipeDelegate* >(this));

	} while (false);

	return err;
}
ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors ZNativeVideoSDKVideoRawDataHelper::UnSubscribe(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKRawDataType rawDataType)
{
	ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors err = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Internal_Error;
	do
	{
		if (!_g_native_wrap.IsValidUser(pUser))
		{
			err = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRawDataPipe* pPipe = NULL;
		if (ZOOM_VIDEO_SDK_NAMESPACE::RAW_DATA_TYPE_VIDEO == rawDataType)
		{
			pPipe = pUser->GetVideoPipe();
		}
		if (ZOOM_VIDEO_SDK_NAMESPACE::RAW_DATA_TYPE_SHARE == rawDataType)
		{
			IVideoSDKVector<IZoomVideoSDKShareAction*>* shareActionList = pUser->getShareActionList();
			if (!shareActionList || shareActionList->GetCount() == 0) {
				break;
			}
			pPipe = shareActionList->GetItem(0)->getSharePipe();
		}
		if (!pPipe)
		{
			break;
		}
		err = pPipe->unSubscribe(this);

	} while (false);

	return err;
}
void ZNativeVideoSDKVideoRawDataHelper::SetRecvHandle(unsigned long long recv_handle)
{
	m_recv_handle = recv_handle;
}
ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors ZNativeVideoSDKVideoRawDataHelper::SubscribeMultiCameraStream(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, unsigned long long recv_handle, ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRawDataPipe* pPipe, ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKResolution resolution)
{
	ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors err = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Internal_Error;
	do
	{
		if (!_g_native_wrap.IsValidUser(pUser) || !pPipe)
		{
			err = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		IVideoSDKVector<IZoomVideoSDKRawDataPipe*>* pPipeList = pUser->getMultiCameraStreamList();
		bool bIsValidPipe = false;
		for (int i = 0; i < pPipeList->GetCount(); ++i)
		{
			IZoomVideoSDKRawDataPipe* pPipeItem = pPipeList->GetItem(i);
			if (pPipeItem == pPipe)
			{
				bIsValidPipe = true;
				break;
			}
		}
		if (bIsValidPipe)
		{
			m_recv_handle = recv_handle;
			err = pPipe->subscribe(resolution, dynamic_cast<ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRawDataPipeDelegate*>(this));
		}
		else
		{
			err = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Invalid_Parameter;
		}
	} while (false);

	return err;
}
ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors ZNativeVideoSDKVideoRawDataHelper::UnSubscribeMultiCameraStream(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRawDataPipe* pPipe)
{
	ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors err = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Internal_Error;
	do
	{
		if (!_g_native_wrap.IsValidUser(pUser) || !pPipe)
		{
			err = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		IVideoSDKVector<IZoomVideoSDKRawDataPipe*>* pPipeList = pUser->getMultiCameraStreamList();
		bool bIsValidPipe = false;
		for (int i = 0; i < pPipeList->GetCount(); ++i)
		{
			IZoomVideoSDKRawDataPipe* pPipeItem = pPipeList->GetItem(i);
			if (pPipeItem == pPipe)
			{
				bIsValidPipe = true;
				break;
			}
		}
		if (bIsValidPipe)
		{
			err = pPipe->unSubscribe(this);
		}
		else
		{
			err = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Invalid_Parameter;
		}
	} while (false);

	return err;
}


