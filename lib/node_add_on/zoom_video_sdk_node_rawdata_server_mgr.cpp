#include "zoom_video_sdk_node_rawdata_server_mgr.h"

extern ZoomVideoNodePipeServerMgr _g_video_pipe_server;
extern ZoomVideoNodePipeServerMgr _g_audio_pipe_server;

ZoomVideoNodeSDKRawdataServerMgrWrap::ZoomVideoNodeSDKRawdataServerMgrWrap()
{
}
ZoomVideoNodeSDKRawdataServerMgrWrap::~ZoomVideoNodeSDKRawdataServerMgrWrap()
{
}

void ZoomVideoNodeSDKRawdataServerMgrWrap::StartVideoServer(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool err = false;
	err = _g_video_pipe_server._uv_ipc_server.StartPipeServer(VIDEO_PIPE_NAME, &_g_video_pipe_server);
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);

}
void ZoomVideoNodeSDKRawdataServerMgrWrap::StopVideoServer(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool err = false;
	err = _g_video_pipe_server._uv_ipc_server.StopPipeServer();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeSDKRawdataServerMgrWrap::StartAudioServer(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool err = false;
	err = _g_audio_pipe_server._uv_ipc_server.StartPipeServer(AUDIO_PIPE_NAME, NULL);
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);

}
void ZoomVideoNodeSDKRawdataServerMgrWrap::StopAudioServer(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool err = false;
	err = _g_audio_pipe_server._uv_ipc_server.StopPipeServer();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);
}

