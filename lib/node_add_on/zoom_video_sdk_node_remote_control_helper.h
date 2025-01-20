#ifndef _ZOOM_NODE_VIDEO_SDK_REMOTE_CONTROLLER_HELPER_H_
#define _ZOOM_NODE_VIDEO_SDK_REMOTE_CONTROLLER_HELPER_H_
#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"
#include "zoom_video_sdk_singleton_wrap_class.h"

extern ZNativeVideoSDKWrap _g_native_wrap;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ZOOM_NODE_HIDE ZoomVideoNodeRemoteControlHelperWrap :
	public ZoomWrapObject<ZoomVideoNodeRemoteControlHelperWrap >
{
	friend class ZoomWrapObject<ZoomVideoNodeRemoteControlHelperWrap >;
private:
	ZoomVideoNodeRemoteControlHelperWrap();
	~ZoomVideoNodeRemoteControlHelperWrap();
public:
	static void CanRequestControl(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void RequestRemoteControl(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EndRemoteControl(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void CanRemoteControl(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnterRemoteControl(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsRemoteControlling(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void LeaveRemoteControl(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<> inline 
void InitClassAttribute<ZoomVideoNodeRemoteControlHelperWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomVideoNodeRemoteControlHelperWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanRequestControl", ZoomVideoNodeRemoteControlHelperWrap::CanRequestControl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RequestRemoteControl", ZoomVideoNodeRemoteControlHelperWrap::RequestRemoteControl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EndRemoteControl", ZoomVideoNodeRemoteControlHelperWrap::EndRemoteControl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanRemoteControl", ZoomVideoNodeRemoteControlHelperWrap::CanRemoteControl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnterRemoteControl", ZoomVideoNodeRemoteControlHelperWrap::EnterRemoteControl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsRemoteControlling", ZoomVideoNodeRemoteControlHelperWrap::IsRemoteControlling);
	NODE_SET_PROTOTYPE_METHOD(tpl, "LeaveRemoteControl", ZoomVideoNodeRemoteControlHelperWrap::LeaveRemoteControl);
}
template<> inline 
v8::Persistent<v8::Function>* GetConstructor<ZoomVideoNodeRemoteControlHelperWrap >() {
	return &ZoomVideoNodeRemoteControlHelperWrap::constructor;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ZOOM_NODE_HIDE ZoomVideoNodeRemoteControlRequestHandlerWrap :
	public ZoomWrapObject<ZoomVideoNodeRemoteControlRequestHandlerWrap >
{
	friend class ZoomWrapObject<ZoomVideoNodeRemoteControlRequestHandlerWrap >;
private:
	ZoomVideoNodeRemoteControlRequestHandlerWrap();
	~ZoomVideoNodeRemoteControlRequestHandlerWrap();
public:
	static void Approve(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Deny(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<> inline 
void InitClassAttribute<ZoomVideoNodeRemoteControlRequestHandlerWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomVideoNodeRemoteControlRequestHandlerWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "Approve", ZoomVideoNodeRemoteControlRequestHandlerWrap::Approve);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Deny", ZoomVideoNodeRemoteControlRequestHandlerWrap::Deny);

}
template<> inline 
v8::Persistent<v8::Function>* GetConstructor<ZoomVideoNodeRemoteControlRequestHandlerWrap >() {
	return &ZoomVideoNodeRemoteControlRequestHandlerWrap::constructor;
}

#endif
