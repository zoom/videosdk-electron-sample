#ifndef _ZOOM_NODE_VIDEO_SDK_RECORDING_HELPER_H_
#define _ZOOM_NODE_VIDEO_SDK_RECORDING_HELPER_H_
#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"
#include "zoom_video_sdk_singleton_wrap_class.h"

extern ZNativeVideoSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomVideoNodeRecordingHelperWrap :
	public ZoomWrapObject<ZoomVideoNodeRecordingHelperWrap >
{
	friend class ZoomWrapObject<ZoomVideoNodeRecordingHelperWrap >;
private:
	ZoomVideoNodeRecordingHelperWrap();
	~ZoomVideoNodeRecordingHelperWrap();
public:
	static void CanStartRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StartCloudRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StopCloudRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void PauseCloudRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void ResumeCloudRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetCloudRecordingStatus(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<> inline 
void InitClassAttribute<ZoomVideoNodeRecordingHelperWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomVideoNodeRecordingHelperWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanStartRecording", ZoomVideoNodeRecordingHelperWrap::CanStartRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartCloudRecording", ZoomVideoNodeRecordingHelperWrap::StartCloudRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopCloudRecording", ZoomVideoNodeRecordingHelperWrap::StopCloudRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "PauseCloudRecording", ZoomVideoNodeRecordingHelperWrap::PauseCloudRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ResumeCloudRecording", ZoomVideoNodeRecordingHelperWrap::ResumeCloudRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetCloudRecordingStatus", ZoomVideoNodeRecordingHelperWrap::GetCloudRecordingStatus);
}
template<> inline 
v8::Persistent<v8::Function>* GetConstructor<ZoomVideoNodeRecordingHelperWrap >() {
	return &ZoomVideoNodeRecordingHelperWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif
