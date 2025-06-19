#include "zoom_video_sdk_native_share_preprocessor_helper_wrap_core.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"
#include "zoom_video_sdk_node_rawdata_helper_mgr_class.h"

extern ZoomVideoNodePipeServerMgr _g_share_preprocessor_pipe_server;
extern ZNativeVideoSDKWrap _g_native_wrap;
const size_t MAX_MSG_DATA_MAP_SIZE = 1000;


ZSharePreprocessorHelperWrap::ZSharePreprocessorHelperWrap()
{
	m_pSender = nullptr;
}
ZSharePreprocessorHelperWrap::~ZSharePreprocessorHelperWrap()
{
	m_pSender = nullptr;
}

void ZSharePreprocessorHelperWrap::onCapturedRawDataReceived(YUVRawDataI420* pRawData, ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKSharePreprocessSender* pSender)
{
	if (!pRawData || !pSender)
	{
		return;
	}

	if (_g_share_preprocessor_pipe_server._uv_ipc_server.GetMessageRawDataSize() > MAX_MSG_DATA_MAP_SIZE)
	{
		return;
	}

	m_pSender = pSender;

	if (_g_share_preprocessor_pipe_server._uv_ipc_server.HasClientConnected())
	{
		UVIPCMessage* rawdata_msg = MakeUVIPCMsg(pRawData, TYPE_SHARE_PREPROCESSOR);
		if (rawdata_msg)
		{
			_g_share_preprocessor_pipe_server._uv_ipc_server.SendMessage(rawdata_msg);
		}
	}
}
void ZSharePreprocessorHelperWrap::onShareStopped()
{
	if (ZoomNodeVideoSinkHelper::GetInst().onNodeAddonCallbacks.IsEmpty())
	{
		return;
	}

	_g_share_preprocessor_pipe_server._uv_ipc_server.ClearMessageRawData();
	
	com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
	callBackBody.set_msgtype(CallMessageType_onCapturedShareStopped);

	auto isolate = v8::Isolate::GetCurrent();
	v8::HandleScope scope(isolate);
	auto context = isolate->GetCurrentContext();
	auto global = context->Global();

	size_t _size = callBackBody.ByteSizeLong();
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

ZNZoomVideoSDKErrors ZSharePreprocessorHelperWrap::StartShareWithPreprocessing(ZNZoomVideoSDKSharePreprocessType zn_type, ZoomSTRING zn_handle, ZoomSTRING zn_monitorid, ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKSharePreprocessor* preprocessor)
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

		ZoomVideoSDKSharePreprocessParam param;
		param.type = (ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKSharePreprocessType)zn_type;
		if (ZNZoomVideoSDKSharePreprocessType_screen == zn_type)
		{
			param.monitorID = zn_monitorid.c_str();
		}
		else if (ZNZoomVideoSDKSharePreprocessType_view == zn_type)
		{
#ifdef WIN32
			int sdk_share_handle = std::stoi(zn_handle, nullptr, 16);
			param.handle = (void*)sdk_share_handle;
#elif __linux
			param.handle = (void *)&zn_handle[0];
#else
			long windowid = strtol(zn_handle.c_str(), nullptr, 10);
			param.handle = (void *)windowid;
#endif  
		}

		err = (ZNZoomVideoSDKErrors)pShareHelper->startShareWithPreprocessing(param, preprocessor);
	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZSharePreprocessorHelperWrap::SendPreprocessedData(char* buffer, std::string dataHandle)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		if (!m_pSender)
		{
			break;
		}
		
		MessageRawDataMap map = _g_share_preprocessor_pipe_server._uv_ipc_server.GetMessageRawData(dataHandle);
		if (map.data) {
			unsigned int width = map.data->GetStreamWidth();
			unsigned int height = map.data->GetStreamHeight();
			memcpy(map.data->GetBuffer(), buffer, width * height * 3 / 2); //checked safe
			err = (ZNZoomVideoSDKErrors)m_pSender->sendPreprocessedData(map.data);
			_g_share_preprocessor_pipe_server._uv_ipc_server.EraseMessageRawData(dataHandle);
		}

	} while (false);

	return err;
}