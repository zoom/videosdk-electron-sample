
#include "zoom_video_sdk_node_libuv_addon.h"
#include "uv_ipc_common.h"
#include "raw_data_format.h"
#include <iostream>
#include <string>
#include "electron_zoomvideosdk.pb.h"
#include "zoom_video_sdk_napi_util_exporter.h"

#define USING_IPC_IN_SUB_THREAD

static void CreateVideoSDKLibuvObject(const v8::FunctionCallbackInfo<v8::Value>& args) {
	VideoNodeLibuvAddonData* data =
		reinterpret_cast<VideoNodeLibuvAddonData*>(args.Data().As<v8::External>()->Value());
	data->zoomNodeWrapInstance = ZoomVideoNodeLibuvWrap::GetNewInstance(args);
	args.GetReturnValue().Set(data->zoomNodeWrapInstance);
}

NODE_MODULE_INIT(/* exports, module, context */) {
	v8::Isolate* isolate = context->GetIsolate();

	ZoomVideoNodeLibuvWrap::Init(exports->GetIsolate());
	ZoomVideoNodeVideoRawDataLibuvClientWrap::Init(exports->GetIsolate());
	ZoomVideoNodeAudioRawDataLibuvClientWrap::Init(exports->GetIsolate());

	VideoNodeLibuvAddonData* data = new VideoNodeLibuvAddonData(isolate);

	v8::Local<v8::External> external = v8::External::New(isolate, data);

	exports->Set(context,
		v8::String::NewFromUtf8(isolate, "exports", v8::NewStringType::kNormal)
		.ToLocalChecked(),
		v8::FunctionTemplate::New(isolate, CreateVideoSDKLibuvObject, external)
		->GetFunction(context).ToLocalChecked()).FromJust();
}

v8::Persistent<v8::Function> ZoomVideoNodeLibuvWrap::constructor;
v8::Persistent<v8::Function> ZoomVideoNodeVideoRawDataLibuvClientWrap::constructor;
v8::Persistent<v8::Function> ZoomVideoNodeAudioRawDataLibuvClientWrap::constructor;

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

void ZoomVideoNodeLibuvWrap::GetVideoLibuvClientObj(const v8::FunctionCallbackInfo<v8::Value>& args) {
	ZoomVideoNodeVideoRawDataLibuvClientWrap::NewInstance(args);
	if (!ZoomNodeAPIUtilHelper::GetInst().m_bInit)
	{
		ZoomNodeAPIUtilHelper::GetInst().ExportNAPIUtilFunc();
	}
}

void ZoomVideoNodeLibuvWrap::GetAudioLibuvClientObj(const v8::FunctionCallbackInfo<v8::Value>& args) {
	ZoomVideoNodeAudioRawDataLibuvClientWrap::NewInstance(args);
	if (!ZoomNodeAPIUtilHelper::GetInst().m_bInit)
	{
		ZoomNodeAPIUtilHelper::GetInst().ExportNAPIUtilFunc();
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
v8::Persistent<v8::Function> g_cb_onPainterVideoRawDataReceived;

v8::Persistent<v8::Function> g_cb_onMixedAudioRawDataReceived;
v8::Persistent<v8::Function> g_cb_onOneWayAudioRawDataReceived;
v8::Persistent<v8::Function> g_cb_onSharedAudioRawDataReceived;

void HandleFreeDataBufferNotification(void* hint)
{
    UVIPCMessage* msg = (UVIPCMessage*)hint;
    if (msg)
    {
        msg->Release();
    }
}

void SendPingPongMsg(int type, unsigned int source_id);
void RunVideoFormatDataCB(char* msg_buf, int type, UVIPCMessage* msg)
{
	if ((TYPE_VIDEO != type && TYPE_SHARE != type) || NULL == msg_buf || NULL == msg)
	{
		return;
	}
	if (TYPE_VIDEO == type && g_cb_onPainterVideoRawDataReceived.IsEmpty())
	{
		return;
	}
	if (TYPE_SHARE == type && g_cb_onPainterVideoRawDataReceived.IsEmpty())
	{
		return;
	}
	fnCallbackVideoFormatDataToJS pCallbackVideoFormatDataToJS = NULL;
	pCallbackVideoFormatDataToJS = ZoomNodeAPIUtilHelper::GetInst().m_fnCallbackVideoFormatDataToJS;
	if (!pCallbackVideoFormatDataToJS)
	{
		return;
	}

	auto isolate = v8::Isolate::GetCurrent();
	v8::HandleScope scope(isolate);
	auto context = isolate->GetCurrentContext();
	auto global = context->Global();

	VideoRawDataHeader& header = *(VideoRawDataHeader*)msg_buf;
	char format_[200] = { 0 };
	//type islimit width height rotation yoffset uoffset voffset
	sprintf(format_, "%s;%d;%d;%d;%d;%llu;%llu;%llu", "yuvi420", header.isLimitedI420,     //checked safe
		header.width, header.height, header.rotation, header.y_offset, header.u_offset, header.v_offset);

	int recv_list_len = header.recv_handle_len;
	unsigned long long* recv_list_ptr = (unsigned long long*)(msg_buf + sizeof(VideoRawDataHeader));
	char* data_buf_ptr = msg_buf + sizeof(VideoRawDataHeader) + sizeof(unsigned long long) * recv_list_len;

	for (int index = 0; index < recv_list_len; index++)
	{
		switch (type)
		{
		case TYPE_VIDEO:
		{
			auto fn = v8::Local<v8::Function>::New(isolate, g_cb_onPainterVideoRawDataReceived);
            msg->AddRef();
			pCallbackVideoFormatDataToJS((uint64_t)recv_list_ptr[index], std::string(format_), data_buf_ptr, header.dataBufferLen, fn, HandleFreeDataBufferNotification, msg);
		}
		break;
		case TYPE_SHARE:
		{
            msg->AddRef();
			auto fn = v8::Local<v8::Function>::New(isolate, g_cb_onPainterVideoRawDataReceived);
			pCallbackVideoFormatDataToJS((uint64_t)recv_list_ptr[index], std::string(format_), data_buf_ptr, header.dataBufferLen, fn, HandleFreeDataBufferNotification, msg);
		}
		break;
		default:
			break;
		}
	}
	
	SendPingPongMsg(type, header.source_id);
}
//
void RunAudioFormatDataCB(char* msg_buf, UVIPCMessage* msg)
{
	if ((g_cb_onMixedAudioRawDataReceived.IsEmpty() && g_cb_onOneWayAudioRawDataReceived.IsEmpty() && g_cb_onSharedAudioRawDataReceived.IsEmpty() )
		|| NULL == msg_buf || NULL == msg)
	{
		return;
	}
	fnCallbackMixedAudioFormatDataToJS pCallbackMixedAudioFormatDataToJS = NULL;
	fnCallbackOnewayAudioFormatDataToJS pCallbackOnewayAudioFormatDataToJS = NULL;
	pCallbackMixedAudioFormatDataToJS = ZoomNodeAPIUtilHelper::GetInst().m_fnCallbackMixedAudioFormatDataToJS;
	pCallbackOnewayAudioFormatDataToJS = ZoomNodeAPIUtilHelper::GetInst().m_fnCallbackOnewayAudioFormatDataToJS;
	if (!pCallbackMixedAudioFormatDataToJS)
	{
		return;
	}
	if (!pCallbackOnewayAudioFormatDataToJS)
	{
		return;
	}
	auto isolate = v8::Isolate::GetCurrent();
	v8::HandleScope scope(isolate);
	auto context = isolate->GetCurrentContext();
	auto global = context->Global();
	AudioRawDataHeader& header = *(AudioRawDataHeader*)msg_buf;
	if (header.type == AudioRawDataType_Mixed && g_cb_onMixedAudioRawDataReceived.IsEmpty())
		return;
	if (header.type == AudioRawDataType_OneWay && g_cb_onOneWayAudioRawDataReceived.IsEmpty())
		return;
	if (header.type == AudioRawDataType_Shared && g_cb_onSharedAudioRawDataReceived.IsEmpty())
		return;
	char format_[200] = { 0 };
	//type buffer_len sample_rate channel_num 
	sprintf(format_, "%s;%d;%d;%d;", "AudioRawData", header.dataBufferLen, header.sampleRate, header.channelNum);    //checked safe
	
	//buffer
	char* audio_data_buf_ptr = msg_buf + sizeof(AudioRawDataHeader);
	if (header.type == AudioRawDataType_Mixed)
	{
        msg->AddRef();
		auto fn = v8::Local<v8::Function>::New(isolate, g_cb_onMixedAudioRawDataReceived);
		pCallbackMixedAudioFormatDataToJS(std::string(format_), audio_data_buf_ptr, header.dataBufferLen, fn, HandleFreeDataBufferNotification, msg);
	}
	if (header.type == AudioRawDataType_OneWay)
	{
        msg->AddRef();
		auto fn = v8::Local<v8::Function>::New(isolate, g_cb_onOneWayAudioRawDataReceived);
		pCallbackOnewayAudioFormatDataToJS(header.userid, std::string(format_), audio_data_buf_ptr, header.dataBufferLen, fn, HandleFreeDataBufferNotification, msg);
	}
	if (header.type == AudioRawDataType_Shared)
	{
		msg->AddRef();
		auto fn = v8::Local<v8::Function>::New(isolate, g_cb_onSharedAudioRawDataReceived);
		pCallbackMixedAudioFormatDataToJS(std::string(format_), audio_data_buf_ptr, header.dataBufferLen, fn, HandleFreeDataBufferNotification, msg);
	}
}
class UVIPCClientSink : public UVIPCSink
{
public:
	friend class ZoomVideoNodeVideoRawDataLibuvClientWrap;
	UVIPCClientSink()
	{
		
	}
	~UVIPCClientSink()
	{
		
	}
	virtual void onMessageRecvNotification(UVIPCMessage* msg)
	{
		char* msg_buf = msg->GetBuf();
		if (NULL == msg_buf)
			return;

		RawDataCommonHeader common_header;
		memcpy(&common_header, msg_buf, sizeof(RawDataCommonHeader));   //checked safe
		switch (common_header.type)
		{
		case TYPE_VIDEO:
		case TYPE_SHARE:
			RunVideoFormatDataCB(msg_buf, common_header.type, msg);
			break;
		case TYPE_AUDIO:
			RunAudioFormatDataCB(msg_buf, msg);
			break;
		default:
			break;
		}
	}
	virtual void onConnect()
	{
		
	}
	virtual void onDisconnect()
	{
		
	}
	virtual void onIdle()
	{
		
	}

public:
	uv_loop_t* _uv_loop;
#if (defined USING_IPC_IN_SUB_THREAD)
	UVIPCInSubThread _uv_ipc_client;
#else
	UVIPC _uv_ipc_client;
#endif
};
UVIPCClientSink g_ipcSinkClientVideo;
UVIPCClientSink g_ipcSinkClientShare;
UVIPCClientSink g_ipcSinkClientAudio;
//
void SendPingPongMsg(int type, unsigned int source_id)
{
	switch (type)
	{
	case TYPE_VIDEO:
	{
		UVIPCMessage* msg = new UVIPCMessage((const char*)&source_id, sizeof(unsigned int));
		g_ipcSinkClientVideo._uv_ipc_client.SendMessage(msg);
	}
	break;
	case TYPE_SHARE:
	{
		UVIPCMessage* msg = new UVIPCMessage((const char*)&source_id, sizeof(unsigned int));
		g_ipcSinkClientShare._uv_ipc_client.SendMessage(msg);
	}
	break;
	default:
		break;
	}
	
}


void ZoomVideoNodeVideoRawDataLibuvClientWrap::SetPainterVideoRawDataCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		if (args.Length() < 1) 
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		if (args[0]->IsNull())
		{
			g_cb_onPainterVideoRawDataReceived.Clear();
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		if (!args[0]->IsFunction())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		g_cb_onPainterVideoRawDataReceived.Reset(isolate, cbfunc);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomVideoNodeVideoRawDataLibuvClientWrap::Start(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool err_video_pipe = false;
	bool err_share_pipe = false;
	bool bSuccess = false;

	g_ipcSinkClientVideo._uv_loop = uv_default_loop();
#if (defined USING_IPC_IN_SUB_THREAD)
	err_video_pipe = g_ipcSinkClientVideo._uv_ipc_client.StartInSubThread(VIDEO_PIPE_NAME, false, &g_ipcSinkClientVideo, g_ipcSinkClientVideo._uv_loop);
#else
	err_video_pipe = g_ipcSinkClientVideo._uv_ipc_client.Start(VIDEO_PIPE_NAME, false, g_ipcSinkClientVideo._uv_loop, &g_ipcSinkClientVideo);
#endif
	uv_run(g_ipcSinkClientVideo._uv_loop, UV_RUN_NOWAIT);

	g_ipcSinkClientShare._uv_loop = uv_default_loop();
#if (defined USING_IPC_IN_SUB_THREAD)
	err_share_pipe = g_ipcSinkClientShare._uv_ipc_client.StartInSubThread(SHARE_PIPE_NAME, false, &g_ipcSinkClientShare, g_ipcSinkClientShare._uv_loop);
#else
	err_share_pipe = g_ipcSinkClientShare._uv_ipc_client.Start(SHARE_PIPE_NAME, false, g_ipcSinkClientShare._uv_loop, &g_ipcSinkClientShare);
#endif
	uv_run(g_ipcSinkClientShare._uv_loop, UV_RUN_NOWAIT);

	if (err_video_pipe && err_share_pipe)
	{
		bSuccess = true;
	}

	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, bSuccess);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeVideoRawDataLibuvClientWrap::Stop(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool err_video_pipe = false;
	bool err_share_pipe = false;
	bool bSuccess = false;
	err_video_pipe = g_ipcSinkClientVideo._uv_ipc_client.Stop();
	err_share_pipe = g_ipcSinkClientShare._uv_ipc_client.Stop();

	if (err_video_pipe && err_share_pipe)
	{
		bSuccess = true;
	}

	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, bSuccess);
	args.GetReturnValue().Set(bret);
}
//

//
void ZoomVideoNodeAudioRawDataLibuvClientWrap::SetRenderAudioRawDataCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		if (args.Length() < 3) 
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		bool wrongArguments = false;
		if (args[0]->IsNull())
		{
			g_cb_onMixedAudioRawDataReceived.Clear();
		}
		else
		{
			if (!args[0]->IsFunction())
				wrongArguments = true;
			else
			{
				v8::Local<v8::Function> cbfunc_mix = v8::Local<v8::Function>::Cast(args[0]);
				g_cb_onMixedAudioRawDataReceived.Reset(isolate, cbfunc_mix);
			}
		}
		if (args[1]->IsNull())
		{
			g_cb_onOneWayAudioRawDataReceived.Clear();
		}
		else
		{
			if (!args[1]->IsFunction())
				wrongArguments = true;
			else
			{
				v8::Local<v8::Function> cbfunc_oneway = v8::Local<v8::Function>::Cast(args[1]);
				g_cb_onOneWayAudioRawDataReceived.Reset(isolate, cbfunc_oneway);
			}
		}
		if (args[2]->IsNull())
		{
			g_cb_onSharedAudioRawDataReceived.Clear();
		}
		else
		{
			if (!args[2]->IsFunction())
				wrongArguments = true;
			else
			{
				v8::Local<v8::Function> cbfunc_shared = v8::Local<v8::Function>::Cast(args[2]);
				g_cb_onSharedAudioRawDataReceived.Reset(isolate, cbfunc_shared);
			}
		}
		if (wrongArguments)
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomVideoNodeAudioRawDataLibuvClientWrap::Start(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool err = false;

	g_ipcSinkClientAudio._uv_loop = uv_default_loop();

#if (defined USING_IPC_IN_SUB_THREAD)
	err = g_ipcSinkClientAudio._uv_ipc_client.StartInSubThread(AUDIO_PIPE_NAME, false, &g_ipcSinkClientAudio, g_ipcSinkClientAudio._uv_loop);
#else
	err = g_ipcSinkClientAudio._uv_ipc_client.Start(AUDIO_PIPE_NAME, false, g_ipcSinkClientAudio._uv_loop, &g_ipcSinkClientAudio);
#endif
	uv_run(g_ipcSinkClientAudio._uv_loop, UV_RUN_NOWAIT);

	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeAudioRawDataLibuvClientWrap::Stop(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool err = false;
	err = g_ipcSinkClientAudio._uv_ipc_client.Stop();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);
}
