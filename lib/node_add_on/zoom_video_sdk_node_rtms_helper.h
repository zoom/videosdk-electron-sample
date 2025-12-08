#ifndef _ZOOM_NODE_VIDEO_SDK_RTMS_HELPER_H_
#define _ZOOM_NODE_VIDEO_SDK_RTMS_HELPER_H_
#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"
#include "zoom_video_sdk_singleton_wrap_class.h"

extern ZNativeVideoSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomVideoNodeRTMSHelperWrap :
	public ZoomWrapObject<ZoomVideoNodeRTMSHelperWrap >
{
	friend class ZoomWrapObject<ZoomVideoNodeRTMSHelperWrap >;
private:
	ZoomVideoNodeRTMSHelperWrap();
	~ZoomVideoNodeRTMSHelperWrap();
public:
	static void IsSupportRealTimeMediaStreams(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void CanStartRealTimeMediaStreams(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StartRealTimeMediaStreams(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void PauseRealTimeMediaStreams(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void ResumeRealTimeMediaStreams(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StopRealTimeMediaStreams(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<> inline
void InitClassAttribute<ZoomVideoNodeRTMSHelperWrap>(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomVideoNodeRTMSHelperWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsSupportRealTimeMediaStreams", ZoomVideoNodeRTMSHelperWrap::IsSupportRealTimeMediaStreams);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanStartRealTimeMediaStreams", ZoomVideoNodeRTMSHelperWrap::CanStartRealTimeMediaStreams);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartRealTimeMediaStreams", ZoomVideoNodeRTMSHelperWrap::StartRealTimeMediaStreams);
	NODE_SET_PROTOTYPE_METHOD(tpl, "PauseRealTimeMediaStreams", ZoomVideoNodeRTMSHelperWrap::PauseRealTimeMediaStreams);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ResumeRealTimeMediaStreams", ZoomVideoNodeRTMSHelperWrap::ResumeRealTimeMediaStreams);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopRealTimeMediaStreams", ZoomVideoNodeRTMSHelperWrap::StopRealTimeMediaStreams);
}
template<> inline
v8::Persistent<v8::Function>* GetConstructor<ZoomVideoNodeRTMSHelperWrap >() {
	return &ZoomVideoNodeRTMSHelperWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif
