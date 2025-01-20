#include "zoom_video_sdk_node_recording_helper.h"


ZoomVideoNodeRecordingHelperWrap::ZoomVideoNodeRecordingHelperWrap()
{
	
}

ZoomVideoNodeRecordingHelperWrap::~ZoomVideoNodeRecordingHelperWrap()
{
	
}
void ZoomVideoNodeRecordingHelperWrap::CanStartRecording(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();

	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	err = _g_native_wrap.GetRecordingHelperWrap().CanStartRecording();
	v8::Local<v8::Integer> ret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(ret);
}
void ZoomVideoNodeRecordingHelperWrap::StartCloudRecording(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();

	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	err = _g_native_wrap.GetRecordingHelperWrap().StartCloudRecording();
	v8::Local<v8::Integer> ret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(ret);
}
void ZoomVideoNodeRecordingHelperWrap::StopCloudRecording(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();

	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	err = _g_native_wrap.GetRecordingHelperWrap().StopCloudRecording();
	v8::Local<v8::Integer> ret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(ret);
}
void ZoomVideoNodeRecordingHelperWrap::PauseCloudRecording(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();

	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	err = _g_native_wrap.GetRecordingHelperWrap().PauseCloudRecording();
	v8::Local<v8::Integer> ret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(ret);
}
void ZoomVideoNodeRecordingHelperWrap::ResumeCloudRecording(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();

	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	err = _g_native_wrap.GetRecordingHelperWrap().ResumeCloudRecording();
	v8::Local<v8::Integer> ret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(ret);
}
void ZoomVideoNodeRecordingHelperWrap::GetCloudRecordingStatus(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	ZNRecordingStatus zn_status;
	ZNZoomVideoSDKErrors err = _g_native_wrap.GetRecordingHelperWrap().GetCloudRecordingStatus(zn_status);
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "recordingStatus", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_status));

	args.GetReturnValue().Set(node);
}