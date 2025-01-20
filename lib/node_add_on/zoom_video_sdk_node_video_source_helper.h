#ifndef _ZOOM_INSTANT_NODE_AUDIO_RAW_DATA_H_
#define _ZOOM_INSTANT_NODE_AUDIO_RAW_DATA_H_

#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"
#include "zoom_video_sdk_singleton_wrap_class.h"

#include "zoom_video_sdk_node_rawdata_helper_mgr_class.h"
#include "zoom_video_sdk_native_audio_raw_data_helper.h"

extern ZNativeInstantSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomInstantNodeSDKAudioRawDataHelperWrap :
	public ZoomWrapObject<ZoomInstantNodeSDKAudioRawDataHelperWrap >
{
	friend class ZoomWrapObject<ZoomInstantNodeSDKAudioRawDataHelperWrap >;
private:
	ZoomInstantNodeSDKAudioRawDataHelperWrap();
	virtual ~ZoomInstantNodeSDKAudioRawDataHelperWrap();
public:
	
	static void Subscribe(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void UnSubscribe(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomInstantNodeSDKAudioRawDataHelperWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomInstantNodeSDKAudioRawDataHelperWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype

	NODE_SET_PROTOTYPE_METHOD(tpl, "Subscribe", ZoomInstantNodeSDKAudioRawDataHelperWrap::Subscribe);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UnSubscribe", ZoomInstantNodeSDKAudioRawDataHelperWrap::UnSubscribe);

}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomInstantNodeSDKAudioRawDataHelperWrap >() {
	return &ZoomInstantNodeSDKAudioRawDataHelperWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif
