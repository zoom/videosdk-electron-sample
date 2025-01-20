#ifndef _ZOOM_NODE_VIDEO_SDK_USER_HELPER_H_
#define _ZOOM_NODE_VIDEO_SDK_USER_HELPER_H_
#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"
#include "zoom_video_sdk_singleton_wrap_class.h"

extern ZNativeVideoSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomVideoNodeUserHelperWrap :
	public ZoomWrapObject<ZoomVideoNodeUserHelperWrap >
{
	friend class ZoomWrapObject<ZoomVideoNodeUserHelperWrap >;
private:
	ZoomVideoNodeUserHelperWrap();
	~ZoomVideoNodeUserHelperWrap();
public:
	
	static void ChangeName(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void MakeHost(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void MakeManager(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void RevokeManager(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void RemoveUser(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<> inline 
void InitClassAttribute<ZoomVideoNodeUserHelperWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomVideoNodeUserHelperWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	
	NODE_SET_PROTOTYPE_METHOD(tpl, "ChangeName", ZoomVideoNodeUserHelperWrap::ChangeName);
	NODE_SET_PROTOTYPE_METHOD(tpl, "MakeHost", ZoomVideoNodeUserHelperWrap::MakeHost);
	NODE_SET_PROTOTYPE_METHOD(tpl, "MakeManager", ZoomVideoNodeUserHelperWrap::MakeManager);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RevokeManager", ZoomVideoNodeUserHelperWrap::RevokeManager);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RemoveUser", ZoomVideoNodeUserHelperWrap::RemoveUser);
}
template<> inline 
v8::Persistent<v8::Function>* GetConstructor<ZoomVideoNodeUserHelperWrap >() {
	return &ZoomVideoNodeUserHelperWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif
