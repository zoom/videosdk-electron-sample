#ifndef _ZOOM_NODE_VIDEO_SDK_LTT_HELPER_H_
#define _ZOOM_NODE_VIDEO_SDK_LTT_HELPER_H_
#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"
#include "zoom_video_sdk_singleton_wrap_class.h"

extern ZNativeVideoSDKWrap _g_native_wrap;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ZOOM_NODE_HIDE ZoomVideoNodeLiveTranscriptionHelperWrap :
	public ZoomWrapObject<ZoomVideoNodeLiveTranscriptionHelperWrap >
{
	friend class ZoomWrapObject<ZoomVideoNodeLiveTranscriptionHelperWrap >;
private:
	ZoomVideoNodeLiveTranscriptionHelperWrap();
	~ZoomVideoNodeLiveTranscriptionHelperWrap();
public:
	static void CanStartLiveTranscription(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetLiveTranscriptionStatus(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StartLiveTranscription(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StopLiveTranscription(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetAvailableSpokenLanguages(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetAvailableTranslationLanguages(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetSpokenLanguage(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetTranslationLanguage(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetSpokenLanguage(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetTranslationLanguage(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<> inline 
void InitClassAttribute<ZoomVideoNodeLiveTranscriptionHelperWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomVideoNodeLiveTranscriptionHelperWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanStartLiveTranscription", ZoomVideoNodeLiveTranscriptionHelperWrap::CanStartLiveTranscription);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetLiveTranscriptionStatus", ZoomVideoNodeLiveTranscriptionHelperWrap::GetLiveTranscriptionStatus);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartLiveTranscription", ZoomVideoNodeLiveTranscriptionHelperWrap::StartLiveTranscription);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopLiveTranscription", ZoomVideoNodeLiveTranscriptionHelperWrap::StopLiveTranscription);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetAvailableSpokenLanguages", ZoomVideoNodeLiveTranscriptionHelperWrap::GetAvailableSpokenLanguages);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetAvailableTranslationLanguages", ZoomVideoNodeLiveTranscriptionHelperWrap::GetAvailableTranslationLanguages);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetSpokenLanguage", ZoomVideoNodeLiveTranscriptionHelperWrap::SetSpokenLanguage);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetTranslationLanguage", ZoomVideoNodeLiveTranscriptionHelperWrap::SetTranslationLanguage);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSpokenLanguage", ZoomVideoNodeLiveTranscriptionHelperWrap::GetSpokenLanguage);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetTranslationLanguage", ZoomVideoNodeLiveTranscriptionHelperWrap::GetTranslationLanguage);
}
template<> inline 
v8::Persistent<v8::Function>* GetConstructor<ZoomVideoNodeLiveTranscriptionHelperWrap >() {
	return &ZoomVideoNodeLiveTranscriptionHelperWrap::constructor;
}
#endif
