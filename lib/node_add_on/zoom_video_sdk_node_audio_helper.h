#ifndef _ZOOM_NODE_VIDEO_SDK_AUDIO_HELPER_H_
#define _ZOOM_NODE_VIDEO_SDK_AUDIO_HELPER_H_
#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"
#include "zoom_video_sdk_singleton_wrap_class.h"


extern ZNativeVideoSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomVideoNodeAudioHelperWrap :
	public ZoomWrapObject<ZoomVideoNodeAudioHelperWrap >
{
	friend class ZoomWrapObject<ZoomVideoNodeAudioHelperWrap >;
private:
	ZoomVideoNodeAudioHelperWrap();
	~ZoomVideoNodeAudioHelperWrap();
public:
	static void StartAudio(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StopAudio(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void MuteAudio(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void UnMuteAudio(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static void GetSpeakerList(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetMicList(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SelectSpeaker(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SelectMic(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Subscribe(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void UnSubscribe(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<> inline 
void InitClassAttribute<ZoomVideoNodeAudioHelperWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomVideoNodeAudioHelperWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartAudio", ZoomVideoNodeAudioHelperWrap::StartAudio);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopAudio", ZoomVideoNodeAudioHelperWrap::StopAudio);
	NODE_SET_PROTOTYPE_METHOD(tpl, "MuteAudio", ZoomVideoNodeAudioHelperWrap::MuteAudio);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UnMuteAudio", ZoomVideoNodeAudioHelperWrap::UnMuteAudio);

	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSpeakerList", ZoomVideoNodeAudioHelperWrap::GetSpeakerList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMicList", ZoomVideoNodeAudioHelperWrap::GetMicList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SelectSpeaker", ZoomVideoNodeAudioHelperWrap::SelectSpeaker);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SelectMic", ZoomVideoNodeAudioHelperWrap::SelectMic);

	NODE_SET_PROTOTYPE_METHOD(tpl, "Subscribe", ZoomVideoNodeAudioHelperWrap::Subscribe);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UnSubscribe", ZoomVideoNodeAudioHelperWrap::UnSubscribe);
}
template<> inline 
v8::Persistent<v8::Function>* GetConstructor<ZoomVideoNodeAudioHelperWrap >() {
	return &ZoomVideoNodeAudioHelperWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif
