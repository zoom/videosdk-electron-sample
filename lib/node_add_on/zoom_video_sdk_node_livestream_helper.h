#ifndef _ZOOM_NODE_VIDEO_SDK_LIVESTREAM_HELPER_H_
#define _ZOOM_NODE_VIDEO_SDK_LIVESTREAM_HELPER_H_
#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"
#include "zoom_video_sdk_singleton_wrap_class.h"

extern ZNativeVideoSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomVideoNodeLiveStreamHelperWrap :
	public ZoomWrapObject<ZoomVideoNodeLiveStreamHelperWrap >
{
	friend class ZoomWrapObject<ZoomVideoNodeLiveStreamHelperWrap >;
private:
	ZoomVideoNodeLiveStreamHelperWrap();
	~ZoomVideoNodeLiveStreamHelperWrap();
public:
	static void StartLiveStream(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StopLiveStream(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void CanStartLiveStream(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<> inline 
void InitClassAttribute<ZoomVideoNodeLiveStreamHelperWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomVideoNodeLiveStreamHelperWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartLiveStream", ZoomVideoNodeLiveStreamHelperWrap::StartLiveStream);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopLiveStream", ZoomVideoNodeLiveStreamHelperWrap::StopLiveStream);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanStartLiveStream", ZoomVideoNodeLiveStreamHelperWrap::CanStartLiveStream);
}
template<> inline 
v8::Persistent<v8::Function>* GetConstructor<ZoomVideoNodeLiveStreamHelperWrap >() {
	return &ZoomVideoNodeLiveStreamHelperWrap::constructor;
}


class ZOOM_NODE_HIDE ZoomVideoNodeIncomingLiveStreamHelperWrap :
	public ZoomWrapObject<ZoomVideoNodeIncomingLiveStreamHelperWrap >
{
	friend class ZoomWrapObject<ZoomVideoNodeIncomingLiveStreamHelperWrap >;
private:
	ZoomVideoNodeIncomingLiveStreamHelperWrap();
	~ZoomVideoNodeIncomingLiveStreamHelperWrap();
public:
	static void BindIncomingLiveStream(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void UnbindIncomingLiveStream(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetIncomingLiveStreamStatus(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StartIncomingLiveStream(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StopIncomingLiveStream(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<> inline 
void InitClassAttribute<ZoomVideoNodeIncomingLiveStreamHelperWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomVideoNodeIncomingLiveStreamHelperWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "BindIncomingLiveStream", ZoomVideoNodeIncomingLiveStreamHelperWrap::BindIncomingLiveStream);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UnbindIncomingLiveStream", ZoomVideoNodeIncomingLiveStreamHelperWrap::UnbindIncomingLiveStream);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetIncomingLiveStreamStatus", ZoomVideoNodeIncomingLiveStreamHelperWrap::GetIncomingLiveStreamStatus);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartIncomingLiveStream", ZoomVideoNodeIncomingLiveStreamHelperWrap::StartIncomingLiveStream);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopIncomingLiveStream", ZoomVideoNodeIncomingLiveStreamHelperWrap::StopIncomingLiveStream);
}
template<> inline 
v8::Persistent<v8::Function>* GetConstructor<ZoomVideoNodeIncomingLiveStreamHelperWrap >() {
	return &ZoomVideoNodeIncomingLiveStreamHelperWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif
