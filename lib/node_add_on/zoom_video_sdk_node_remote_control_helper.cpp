#include "zoom_video_sdk_node_remote_control_helper.h"
#include "node_core/zoom_video_sdk_events_wrap_class.h"


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ZoomVideoNodeRemoteControlHelperWrap::ZoomVideoNodeRemoteControlHelperWrap()
{

}

ZoomVideoNodeRemoteControlHelperWrap::~ZoomVideoNodeRemoteControlHelperWrap()
{

}
void ZoomVideoNodeRemoteControlHelperWrap::CanRequestControl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bCan = ZNZoomVideoSDKRemoteControlHelper::GetInst().CanRequestControl();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bCan);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeRemoteControlHelperWrap::RequestRemoteControl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKRemoteControlHelper::GetInst().RequestRemoteControl();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeRemoteControlHelperWrap::EndRemoteControl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKRemoteControlHelper::GetInst().EndRemoteControl();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeRemoteControlHelperWrap::CanRemoteControl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bCan = ZNZoomVideoSDKRemoteControlHelper::GetInst().CanRemoteControl();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bCan);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeRemoteControlHelperWrap::EnterRemoteControl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKRemoteControlHelper::GetInst().EnterRemoteControl();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeRemoteControlHelperWrap::IsRemoteControlling(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bIs = ZNZoomVideoSDKRemoteControlHelper::GetInst().IsRemoteControlling();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bIs);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeRemoteControlHelperWrap::LeaveRemoteControl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKRemoteControlHelper::GetInst().LeaveRemoteControl();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ZoomVideoNodeRemoteControlRequestHandlerWrap::ZoomVideoNodeRemoteControlRequestHandlerWrap()
{

}

ZoomVideoNodeRemoteControlRequestHandlerWrap::~ZoomVideoNodeRemoteControlRequestHandlerWrap()
{

}
void ZoomVideoNodeRemoteControlRequestHandlerWrap::Approve(const v8::FunctionCallbackInfo<v8::Value>& args) {

	v8::Isolate* isolate = args.GetIsolate();

	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKRemoteControlRequestHandler::GetInst().Approve();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeRemoteControlRequestHandlerWrap::Deny(const v8::FunctionCallbackInfo<v8::Value>& args) {

	v8::Isolate* isolate = args.GetIsolate();

	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKRemoteControlRequestHandler::GetInst().Deny();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}