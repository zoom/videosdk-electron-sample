#include "zoom_video_sdk_node_rtms_helper.h"

ZoomVideoNodeRTMSHelperWrap::ZoomVideoNodeRTMSHelperWrap()
{

}

ZoomVideoNodeRTMSHelperWrap::~ZoomVideoNodeRTMSHelperWrap()
{

}
void ZoomVideoNodeRTMSHelperWrap::IsSupportRealTimeMediaStreams(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool bIs = _g_native_wrap.GetRTMSHelperWrap().IsSupportRealTimeMediaStreams();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, bIs);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeRTMSHelperWrap::CanStartRealTimeMediaStreams(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = _g_native_wrap.GetRTMSHelperWrap().CanStartRealTimeMediaStreams();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeRTMSHelperWrap::StartRealTimeMediaStreams(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = _g_native_wrap.GetRTMSHelperWrap().StartRealTimeMediaStreams();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeRTMSHelperWrap::PauseRealTimeMediaStreams(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = _g_native_wrap.GetRTMSHelperWrap().PauseRealTimeMediaStreams();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeRTMSHelperWrap::ResumeRealTimeMediaStreams(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = _g_native_wrap.GetRTMSHelperWrap().ResumeRealTimeMediaStreams();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeRTMSHelperWrap::StopRealTimeMediaStreams(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = _g_native_wrap.GetRTMSHelperWrap().StopRealTimeMediaStreams();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
