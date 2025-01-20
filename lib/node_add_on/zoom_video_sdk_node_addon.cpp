
#include "zoom_video_sdk_node_addon.h"
#include "zoom_video_sdk_v8_to_c.h"
#include "zoom_video_sdk_node_session_info_ctrl.h"
#include "zoom_video_sdk_node_audio_helper.h"
#include "zoom_video_sdk_node_video_helper.h"
#include "zoom_video_sdk_node_share_helper.h"
#include "zoom_video_sdk_node_chat_helper.h"
#include "zoom_video_sdk_node_livestream_helper.h"
#include "zoom_video_sdk_node_user_helper.h"
#include "zoom_video_sdk_node_video_raw_data.h"
#include "zoom_video_sdk_node_rawdata_server_mgr.h"
#include "zoom_video_sdk_node_cmd_channel_helper.h"
#include "zoom_video_sdk_node_phone_helper.h"
#include "zoom_video_sdk_node_recording_helper.h"
#include "zoom_video_sdk_node_remote_camera_control_helper.h"
#include "zoom_video_sdk_node_audio_setting.h"
#include "zoom_video_sdk_node_live_transcription_helper.h"
#include "zoom_video_sdk_node_share_setting.h"
#include "zoom_video_sdk_napi_util_exporter.h"
#if (!defined __linux)
#include "zoom_video_sdk_node_remote_control_helper.h"
#endif


ZNativeVideoSDKWrap _g_native_wrap;
extern ZoomVideoNodePipeServerMgr _g_video_pipe_server;
extern ZoomVideoNodePipeServerMgr _g_share_pipe_server;
extern ZoomVideoNodePipeServerMgr _g_audio_pipe_server;

static void CreateVideoSDKNodeObject(const v8::FunctionCallbackInfo<v8::Value>& args) {
	VideoNodeAddonData* data =
		reinterpret_cast<VideoNodeAddonData*>(args.Data().As<v8::External>()->Value());
	data->zoomNodeWrapInstance = ZoomVideoNodeWrap::GetNewInstance(args);
	args.GetReturnValue().Set(data->zoomNodeWrapInstance);
}

NODE_MODULE_INIT(/* exports, module, context */) {
	v8::Isolate* isolate = context->GetIsolate();

	ZoomVideoNodeWrap::Init(exports->GetIsolate());
	ZoomVideoNodeSessionInfoCtrlWrap::Init(exports->GetIsolate());
	ZoomVideoNodeAudioHelperWrap::Init(exports->GetIsolate());
	ZoomVideoNodeVideoHelperWrap::Init(exports->GetIsolate());
	ZoomVideoNodeShareHelperWrap::Init(exports->GetIsolate());
	ZoomVideoNodeChatHelperWrap::Init(exports->GetIsolate());
	ZoomVideoNodeLiveStreamHelperWrap::Init(exports->GetIsolate());
	ZoomVideoNodeIncomingLiveStreamHelperWrap::Init(exports->GetIsolate());
	ZoomVideoNodeUserHelperWrap::Init(exports->GetIsolate());
	ZoomVideoNodeSDKVideoRenderWrap::Init(exports->GetIsolate());
	ZoomVideoNodeSDKRawdataServerMgrWrap::Init(exports->GetIsolate());
	ZoomVideoNodeCmdChannelHelperWrap::Init(exports->GetIsolate());
	ZoomVideoNodePhoneHelperWrap::Init(exports->GetIsolate());
	ZoomVideoNodeRecordingHelperWrap::Init(exports->GetIsolate());
	ZoomVideoNodeRemoteCameraControlHelperWrap::Init(exports->GetIsolate());
	ZoomVideoNodeCameraControlRequestHandlerWrap::Init(exports->GetIsolate());
	ZoomVideoNodeAudioSettingWrap::Init(exports->GetIsolate());
	ZoomVideoNodeTestAudioDeviceWrap::Init(exports->GetIsolate());
	ZoomVideoNodeLiveTranscriptionHelperWrap::Init(exports->GetIsolate());
	ZoomVideoNodeShareSettingWrap::Init(exports->GetIsolate());
#if (!defined __linux)
	ZoomVideoNodeRemoteControlHelperWrap::Init(exports->GetIsolate());
	ZoomVideoNodeRemoteControlRequestHandlerWrap::Init(exports->GetIsolate());
#endif

	VideoNodeAddonData* data = new VideoNodeAddonData(isolate);

	v8::Local<v8::External> external = v8::External::New(isolate, data);

	exports->Set(context,
		v8::String::NewFromUtf8(isolate, "exports", v8::NewStringType::kNormal)
		.ToLocalChecked(),
		v8::FunctionTemplate::New(isolate, CreateVideoSDKNodeObject, external)
		->GetFunction(context).ToLocalChecked()).FromJust();
}


v8::Persistent<v8::Function> ZoomVideoNodeWrap::constructor;
v8::Persistent<v8::Function> ZoomVideoNodeSessionInfoCtrlWrap::constructor;
v8::Persistent<v8::Function> ZoomVideoNodeAudioHelperWrap::constructor;
v8::Persistent<v8::Function> ZoomVideoNodeVideoHelperWrap::constructor;
v8::Persistent<v8::Function> ZoomVideoNodeShareHelperWrap::constructor;
v8::Persistent<v8::Function> ZoomVideoNodeChatHelperWrap::constructor;
v8::Persistent<v8::Function> ZoomVideoNodeLiveStreamHelperWrap::constructor;
v8::Persistent<v8::Function> ZoomVideoNodeIncomingLiveStreamHelperWrap::constructor;
v8::Persistent<v8::Function> ZoomVideoNodeUserHelperWrap::constructor;
v8::Persistent<v8::Function> ZoomVideoNodeSDKVideoRenderWrap::constructor;
v8::Persistent<v8::Function> ZoomVideoNodeSDKRawdataServerMgrWrap::constructor;
v8::Persistent<v8::Function> ZoomVideoNodeCmdChannelHelperWrap::constructor;
v8::Persistent<v8::Function> ZoomVideoNodePhoneHelperWrap::constructor;
v8::Persistent<v8::Function> ZoomVideoNodeRecordingHelperWrap::constructor;
v8::Persistent<v8::Function> ZoomVideoNodeRemoteCameraControlHelperWrap::constructor;
v8::Persistent<v8::Function> ZoomVideoNodeCameraControlRequestHandlerWrap::constructor;
v8::Persistent<v8::Function> ZoomVideoNodeAudioSettingWrap::constructor;
v8::Persistent<v8::Function> ZoomVideoNodeTestAudioDeviceWrap::constructor;
v8::Persistent<v8::Function> ZoomVideoNodeLiveTranscriptionHelperWrap::constructor;
v8::Persistent<v8::Function> ZoomVideoNodeShareSettingWrap::constructor;
#if (!defined __linux)
v8::Persistent<v8::Function> ZoomVideoNodeRemoteControlHelperWrap::constructor;
v8::Persistent<v8::Function> ZoomVideoNodeRemoteControlRequestHandlerWrap::constructor;
#endif

///////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

ZoomVideoNodeWrap::ZoomVideoNodeWrap()
{
	_g_native_wrap.SetSink(&ZoomVideoNodeSinkWrapMgr::GetInst().m_ZoomVideoSDKSink);
}
ZoomVideoNodeWrap::~ZoomVideoNodeWrap()
{
	_g_native_wrap.SetSink(NULL);
}

void ZoomVideoNodeWrap::CreateZoomVideoSDKObj(const v8::FunctionCallbackInfo<v8::Value>& args) {
	
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		bool zn_bret = ZoomNodeAPIUtilHelper::GetInst().ExportNAPIUtilFunc();
		if (!zn_bret)
		{
			err = ZNZoomVideoSDKErrors_Internal_Error;
			break;
		}
		com::electron::zoomvideo::sdk::proto::CreateVideoSDKObjParam proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::CreateVideoSDKObjParam >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_path())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		ZoomSTRING path;
		path = s2zs(proto_param.path());

		err = _g_native_wrap.CreateZoomVideoSDKObj(path);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeWrap::DestroyZoomVideoSDKObj(const v8::FunctionCallbackInfo<v8::Value>& args) {

	_g_video_pipe_server._uv_ipc_server.StopPipeServer();
	_g_share_pipe_server._uv_ipc_server.StopPipeServer();
	_g_audio_pipe_server._uv_ipc_server.StopPipeServer();
	v8::Isolate* isolate = args.GetIsolate();

	ZNZoomVideoSDKErrors err = _g_native_wrap.DestroyZoomVideoSDKObj();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomVideoNodeWrap::Initialize(const v8::FunctionCallbackInfo<v8::Value>& args){
	
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::VideoSDKInitParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::VideoSDKInitParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		if (!proto_param.has_domain() ||
			!proto_param.has_logfileprefix()
			)
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		ZNZoomVideoSDKInitParams param;
		param.domain = s2zs(proto_param.domain());
		param.logFilePrefix = s2zs(proto_param.logfileprefix());
		if (proto_param.has_enablelog())
		{
			convertBool(proto_param.enablelog(), param.enableLog);
		}
		if (proto_param.has_audiorawdatamemorymode())
		{
			int zn_audioRawDataMemoryMode = (int)proto_param.audiorawdatamemorymode();
			param.audioRawDataMemoryMode = (ZNZoomVideoSDKRawDataMemoryMode)zn_audioRawDataMemoryMode;
		}
		if (proto_param.has_zn_videorawdatamemorymode())
		{
			int zn_videoRawDataMemoryMode = (int)proto_param.zn_videorawdatamemorymode();
			param.videoRawDataMemoryMode = (ZNZoomVideoSDKRawDataMemoryMode)zn_videoRawDataMemoryMode;
		}
		if (proto_param.has_zn_sharerawdatamemorymode())
		{
			int zn_shareRawDataMemoryMode = (int)proto_param.zn_sharerawdatamemorymode();
			param.shareRawDataMemoryMode = (ZNZoomVideoSDKRawDataMemoryMode)zn_shareRawDataMemoryMode;
		}
		if (proto_param.has_speakertestfilepath())
		{
			param.extendParam.speakerTestFilePath = s2zs(proto_param.speakertestfilepath());
		}

		err = _g_native_wrap.Initialize(param);
		bool bsucc_video_pipe = false;
		bsucc_video_pipe = _g_video_pipe_server._uv_ipc_server.StartPipeServer(VIDEO_PIPE_NAME, &_g_video_pipe_server);

		bool bsucc_share_pipe = false;
		bsucc_share_pipe = _g_share_pipe_server._uv_ipc_server.StartPipeServer(SHARE_PIPE_NAME, &_g_share_pipe_server);
		if (!bsucc_video_pipe ||
			!bsucc_share_pipe
			)
		{
			err = ZNZoomVideoSDKErrors_Internal_Error;
		}
	} while (false);
	

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomVideoNodeWrap::CleanUp(const v8::FunctionCallbackInfo<v8::Value>& args) {
	
	v8::Isolate* isolate = args.GetIsolate();
	ZoomNodeVideoSinkHelper::GetInst().Reset();
	ZoomVideoNodeSDKDelayGC::GetInst().StopTimer();
	ZNZoomVideoSDKErrors err = _g_native_wrap.CleanUp();
	bool bsucc_video_pipe = false;
	bsucc_video_pipe = _g_video_pipe_server._uv_ipc_server.StopPipeServer();
	bool bsucc_share_pipe = false;
	bsucc_share_pipe = _g_share_pipe_server._uv_ipc_server.StopPipeServer();
	if (!bsucc_video_pipe ||
		!bsucc_share_pipe
		)
	{
		err = ZNZoomVideoSDKErrors_Internal_Error;
	}
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeWrap::JoinSession(const v8::FunctionCallbackInfo<v8::Value>& args) {

	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::VideoSDKSessionContext proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::VideoSDKSessionContext >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		if (!proto_param.has_sessionname() ||
			!proto_param.has_token() ||
			!proto_param.has_username())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		ZNZoomVideoSDKSessionContext zn_sessionContext;
		zn_sessionContext.sessionName = s2zs(proto_param.sessionname());
		zn_sessionContext.token = s2zs(proto_param.token());
		zn_sessionContext.userName = s2zs(proto_param.username());
		if (proto_param.has_sessionpassword())
		{
			zn_sessionContext.sessionPassword = s2zs(proto_param.sessionpassword());
		}
		if (proto_param.has_localvideoon())
		{
			convertBool(proto_param.localvideoon(), zn_sessionContext.videoOption.localVideoOn);
		}
		if (proto_param.has_connect())
		{
			convertBool(proto_param.connect(), zn_sessionContext.audioOption.connect);
		}
		if (proto_param.has_mute())
		{
			convertBool(proto_param.mute(), zn_sessionContext.audioOption.mute);
		}
		if (proto_param.has_preprocessor())
		{
			convertBool(proto_param.preprocessor(), zn_sessionContext.preProcessor);
		}
		if (proto_param.has_externalvideosource())
		{
			convertBool(proto_param.externalvideosource(), zn_sessionContext.externalVideoSource);
		}
		if (proto_param.has_sessionidletimeoutmins())
		{
			zn_sessionContext.sessionIdleTimeoutMins = proto_param.sessionidletimeoutmins();
		}

		err = _g_native_wrap.JoinSession(zn_sessionContext);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeWrap::LeaveSession(const v8::FunctionCallbackInfo<v8::Value>& args) {

	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::LeaveSessionParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::LeaveSessionParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_zn_bend())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		bool zn_bEnd = false;
		convertBool(proto_param.zn_bend(), zn_bEnd);

		err = _g_native_wrap.LeaveSession(zn_bEnd);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeWrap::IsInSession(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bIsInSession = _g_native_wrap.IsInSession();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bIsInSession);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeWrap::GetSDKVersion(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING sdkVersion = _g_native_wrap.GetSDKVersion();
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(sdkVersion).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeWrap::InputSessionPassword(const v8::FunctionCallbackInfo<v8::Value>& args) {

	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::SessionPasswordParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::SessionPasswordParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_zn_password())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		ZoomSTRING zn_password;
		zn_password = s2zs(proto_param.zn_password());

		err = _g_native_wrap.InputSessionPassword(zn_password);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeWrap::LeaveSessionIgnorePassword(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = _g_native_wrap.LeaveSessionIgnorePassword();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}


void ZoomVideoNodeWrap::GetSessionInfoCtrl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomVideoNodeSessionInfoCtrlWrap::NewInstance(args);
}
void ZoomVideoNodeWrap::GetAudioHelper(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomVideoNodeAudioHelperWrap::NewInstance(args);
}
void ZoomVideoNodeWrap::GetVideoHelper(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomVideoNodeVideoHelperWrap::NewInstance(args);
}
void ZoomVideoNodeWrap::GetShareHelper(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomVideoNodeShareHelperWrap::NewInstance(args);
}
void ZoomVideoNodeWrap::GetUserHelper(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomVideoNodeUserHelperWrap::NewInstance(args);
}
void ZoomVideoNodeWrap::GetVideoSDKRender(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomVideoNodeSDKVideoRenderWrap::NewInstance(args);
}
void ZoomVideoNodeWrap::GetVideoSDKRawDataServerMgr(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomVideoNodeSDKRawdataServerMgrWrap::NewInstance(args);
}
void ZoomVideoNodeWrap::GetChatHelper(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomVideoNodeChatHelperWrap::NewInstance(args);
}
void ZoomVideoNodeWrap::GetLiveStreamHelper(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomVideoNodeLiveStreamHelperWrap::NewInstance(args);
}
void ZoomVideoNodeWrap::GetIncomingLiveStreamHelper(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomVideoNodeIncomingLiveStreamHelperWrap::NewInstance(args);
}
void ZoomVideoNodeWrap::GetCmdChannel(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomVideoNodeCmdChannelHelperWrap::NewInstance(args);
}
void ZoomVideoNodeWrap::GetPhoneHelper(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomVideoNodePhoneHelperWrap::NewInstance(args);
}
void ZoomVideoNodeWrap::GetRemoteCameraCtrlHelper(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomVideoNodeRemoteCameraControlHelperWrap::NewInstance(args);
}
void ZoomVideoNodeWrap::GetCameraControlRequestHandler(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomVideoNodeCameraControlRequestHandlerWrap::NewInstance(args);
}
void ZoomVideoNodeWrap::GetRecordingHelper(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomVideoNodeRecordingHelperWrap::NewInstance(args);
}
void ZoomVideoNodeWrap::GetAudioSetting(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomVideoNodeAudioSettingWrap::NewInstance(args);
}
void ZoomVideoNodeWrap::GetTestAudioDevice(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomVideoNodeTestAudioDeviceWrap::NewInstance(args);
}
void ZoomVideoNodeWrap::GetLiveTranscriptionHelper(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomVideoNodeLiveTranscriptionHelperWrap::NewInstance(args);
}
void ZoomVideoNodeWrap::GetShareSetting(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomVideoNodeShareSettingWrap::NewInstance(args);
}
#if (!defined __linux)
void ZoomVideoNodeWrap::GetRemoteCtrlHelper(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomVideoNodeRemoteControlHelperWrap::NewInstance(args);
}
void ZoomVideoNodeWrap::GetRemoteControlRequestHandler(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZoomVideoNodeRemoteControlRequestHandlerWrap::NewInstance(args);
}
#endif

void ZoomVideoNodeWrap::SetNodeAddonCallbacks(const v8::FunctionCallbackInfo<v8::Value>& args)
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
			ZoomNodeVideoSinkHelper::GetInst().onNodeAddonCallbacks.Clear();
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		if (!args[0]->IsFunction())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		ZoomNodeVideoSinkHelper::GetInst().onNodeAddonCallbacks.Reset(isolate, cbfunc);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}