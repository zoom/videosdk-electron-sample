#ifndef _ZOOM_NODE_RENDER_ADDON_H_
#define _ZOOM_NODE_RENDER_ADDON_H_

#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_native_sdk_wrap_core_def.h"
#include "zoom_video_sdk_singleton_wrap_class.h"



class ZOOM_NODE_HIDE ZoomNodeInstantPainterWrap : public ZoomWrapObject<ZoomNodeInstantPainterWrap >
{
	friend class ZoomWrapObject<ZoomNodeInstantPainterWrap >;
private:
	ZoomNodeInstantPainterWrap() {}
	~ZoomNodeInstantPainterWrap() {}

public:
	
	static void GetVideoLibuvClientObj(const v8::FunctionCallbackInfo<v8::Value>& args);
	//static void GetAudioLibuvClientObj(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeInstantPainterWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeInstantPainterWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetVideoLibuvClientObj", ZoomNodeInstantPainterWrap::GetVideoLibuvClientObj);

	/*
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetShareLibuvClientObj", ZoomNodeRenderWrap::GetShareLibuvClientObj);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetAudioLibuvClientObj", ZoomNodeRenderWrap::GetAudioLibuvClientObj);*/
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeInstantPainterWrap >() {
	return &ZoomNodeInstantPainterWrap::constructor;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZOOM_NODE_HIDE ZoomInstantNodeVideoRawDataLibuvClientWrap :
	public ZoomWrapObject<ZoomInstantNodeVideoRawDataLibuvClientWrap >
{
	//
	friend class ZoomWrapObject<ZoomInstantNodeVideoRawDataLibuvClientWrap >;
private:
	ZoomInstantNodeVideoRawDataLibuvClientWrap() {};
	~ZoomInstantNodeVideoRawDataLibuvClientWrap() {};
public:
	static void SetPainterVideoRawDataCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StartVideoClient(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StopVideoClient(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};

template<>
static void InitClassAttribute<ZoomInstantNodeVideoRawDataLibuvClientWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomInstantNodeVideoRawDataLibuvClientWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetPainterVideoRawDataCB", ZoomInstantNodeVideoRawDataLibuvClientWrap::SetPainterVideoRawDataCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartVideoClient", ZoomInstantNodeVideoRawDataLibuvClientWrap::StartVideoClient);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopVideoClient", ZoomInstantNodeVideoRawDataLibuvClientWrap::StopVideoClient);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomInstantNodeVideoRawDataLibuvClientWrap >() {
	return &ZoomInstantNodeVideoRawDataLibuvClientWrap::constructor;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//class ZOOM_NODE_HIDE ZoomNodeAudioRawDataLibuvClientWrap :
//	public ZoomWrapObject<ZoomNodeAudioRawDataLibuvClientWrap >
//{
//	//
//	friend class ZoomWrapObject<ZoomNodeAudioRawDataLibuvClientWrap >;
//private:
//	ZoomNodeAudioRawDataLibuvClientWrap() {};
//	~ZoomNodeAudioRawDataLibuvClientWrap() {};
//public:
//	static void SetRenderAudioRawDataCB(const v8::FunctionCallbackInfo<v8::Value>& args);
//	static void StartAudioClient(const v8::FunctionCallbackInfo<v8::Value>& args);
//	static void StopAudioClient(const v8::FunctionCallbackInfo<v8::Value>& args);
//
//	static v8::Persistent<v8::Function> constructor;
//};
//
//template<>
//static void InitClassAttribute<ZoomNodeAudioRawDataLibuvClientWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
//{
//	tpl->SetClassName(v8::String::NewFromUtf8(
//		isolate, "ZoomNodeAudioRawDataLibuvClientWrap", v8::NewStringType::kInternalized).ToLocalChecked());
//	tpl->InstanceTemplate()->SetInternalFieldCount(1);
//
//	// Prototype
//	NODE_SET_PROTOTYPE_METHOD(tpl, "SetRenderAudioRawDataCB", ZoomNodeAudioRawDataLibuvClientWrap::SetRenderAudioRawDataCB);
//	NODE_SET_PROTOTYPE_METHOD(tpl, "StartAudioClient", ZoomNodeAudioRawDataLibuvClientWrap::StartAudioClient);
//	NODE_SET_PROTOTYPE_METHOD(tpl, "StopAudioClient", ZoomNodeAudioRawDataLibuvClientWrap::StopAudioClient);
//}
//template<>
//static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeAudioRawDataLibuvClientWrap >() {
//	return &ZoomNodeAudioRawDataLibuvClientWrap::constructor;
//}
#endif
