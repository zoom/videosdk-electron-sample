#include "zoom_video_sdk_node_audio_raw_data.h"

ZoomInstantNodeSDKAudioRawDataHelperWrap::ZoomInstantNodeSDKAudioRawDataHelperWrap()
{
}
ZoomInstantNodeSDKAudioRawDataHelperWrap::~ZoomInstantNodeSDKAudioRawDataHelperWrap()
{
}
void ZoomInstantNodeSDKAudioRawDataHelperWrap::Subscribe(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();

	ZNZoomInstantSDKErrors err = ZoomInstantNodeRawDataHelperMgr::GetInst().m_audiorawdatahelper.Subscribe();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomInstantNodeSDKAudioRawDataHelperWrap::UnSubscribe(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();

	ZNZoomInstantSDKErrors err = ZoomInstantNodeRawDataHelperMgr::GetInst().m_audiorawdatahelper.UnSubscribe();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}