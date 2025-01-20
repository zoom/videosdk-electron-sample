#ifndef _ZOOM_NODE_RENDER_ADDON_H_
#define _ZOOM_NODE_RENDER_ADDON_H_

#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_native_sdk_wrap_core_def.h"
#include "zoom_video_sdk_singleton_wrap_class.h"



class ZOOM_NODE_HIDE ZoomVideoNodeLibuvWrap : public ZoomWrapObject<ZoomVideoNodeLibuvWrap >
{
	friend class ZoomWrapObject<ZoomVideoNodeLibuvWrap >;
private:
	ZoomVideoNodeLibuvWrap() {}
	~ZoomVideoNodeLibuvWrap() {}

public:
	
	static void GetVideoLibuvClientObj(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetAudioLibuvClientObj(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<> inline
void InitClassAttribute<ZoomVideoNodeLibuvWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomVideoNodeLibuvWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetVideoLibuvClientObj", ZoomVideoNodeLibuvWrap::GetVideoLibuvClientObj);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetAudioLibuvClientObj", ZoomVideoNodeLibuvWrap::GetAudioLibuvClientObj);
}
template<> inline
v8::Persistent<v8::Function>* GetConstructor<ZoomVideoNodeLibuvWrap >() {
	return &ZoomVideoNodeLibuvWrap::constructor;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZOOM_NODE_HIDE ZoomVideoNodeVideoRawDataLibuvClientWrap :
	public ZoomWrapObject<ZoomVideoNodeVideoRawDataLibuvClientWrap >
{
	//
	friend class ZoomWrapObject<ZoomVideoNodeVideoRawDataLibuvClientWrap >;
private:
	ZoomVideoNodeVideoRawDataLibuvClientWrap() {};
	~ZoomVideoNodeVideoRawDataLibuvClientWrap() {};
public:
	static void SetPainterVideoRawDataCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Start(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Stop(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};

template<> inline
void InitClassAttribute<ZoomVideoNodeVideoRawDataLibuvClientWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomVideoNodeVideoRawDataLibuvClientWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetPainterVideoRawDataCB", ZoomVideoNodeVideoRawDataLibuvClientWrap::SetPainterVideoRawDataCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Start", ZoomVideoNodeVideoRawDataLibuvClientWrap::Start);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Stop", ZoomVideoNodeVideoRawDataLibuvClientWrap::Stop);
}
template<> inline
v8::Persistent<v8::Function>* GetConstructor<ZoomVideoNodeVideoRawDataLibuvClientWrap >() {
	return &ZoomVideoNodeVideoRawDataLibuvClientWrap::constructor;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZOOM_NODE_HIDE ZoomVideoNodeAudioRawDataLibuvClientWrap :
	public ZoomWrapObject<ZoomVideoNodeAudioRawDataLibuvClientWrap >
{
	//
	friend class ZoomWrapObject<ZoomVideoNodeAudioRawDataLibuvClientWrap >;
private:
	ZoomVideoNodeAudioRawDataLibuvClientWrap() {};
	~ZoomVideoNodeAudioRawDataLibuvClientWrap() {};
public:
	static void SetRenderAudioRawDataCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Start(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Stop(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};

template<> inline
void InitClassAttribute<ZoomVideoNodeAudioRawDataLibuvClientWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomVideoNodeAudioRawDataLibuvClientWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetRenderAudioRawDataCB", ZoomVideoNodeAudioRawDataLibuvClientWrap::SetRenderAudioRawDataCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Start", ZoomVideoNodeAudioRawDataLibuvClientWrap::Start);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Stop", ZoomVideoNodeAudioRawDataLibuvClientWrap::Stop);
}
template<> inline
v8::Persistent<v8::Function>* GetConstructor<ZoomVideoNodeAudioRawDataLibuvClientWrap >() {
	return &ZoomVideoNodeAudioRawDataLibuvClientWrap::constructor;
}

class VideoNodeLibuvAddonData {
public:
	explicit VideoNodeLibuvAddonData(v8::Isolate* isolate)
	{
		node::AddEnvironmentCleanupHook(isolate, DeleteInstance, this);
	}

	v8::Local<v8::Object> zoomNodeWrapInstance;

	static void DeleteInstance(void* data) {
		delete static_cast<VideoNodeLibuvAddonData*>(data);
	}
};
#endif
