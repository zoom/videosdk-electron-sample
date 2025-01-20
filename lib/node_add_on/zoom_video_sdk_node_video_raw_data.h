#ifndef _ZOOM_VIDEO_SDK_NODE_VIDEO_RAW_DATA_H_
#define _ZOOM_VIDEO_SDK_NODE_VIDEO_RAW_DATA_H_

#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"
#include "zoom_video_sdk_singleton_wrap_class.h"

#include "zoom_video_sdk_node_rawdata_helper_mgr_class.h"
#include "zoom_video_sdk_node_timer.h"
#include <map>

extern ZNativeVideoSDKWrap _g_native_wrap;

class ZoomVideoNodeSDKDelayGC
{
public:
	static ZoomVideoNodeSDKDelayGC& GetInst()
	{
		static ZoomVideoNodeSDKDelayGC inst;
		return inst;
	}
	virtual ~ZoomVideoNodeSDKDelayGC();

	void StartTimer();
	void StopTimer();
	void Hearbeat();
	void AddToRealDeleteList(unsigned long long rawDataHelper);
	void AddToPotentialDeleteList(unsigned long long rawDataHelper);

private:
	ZoomVideoNodeSDKDelayGC();

private:
	NodeTimer m_timer;
	std::mutex m_mutex;
	std::map<unsigned long long, bool> m_realDeleteMap; //key is the address of the ZNativeVideoSDKVideoRawDataHelper
	std::map<unsigned long long, bool> m_potentialDeleteMap;
};
class ZOOM_NODE_HIDE ZoomVideoNodeSDKVideoRenderWrap :
	public ZoomWrapObject<ZoomVideoNodeSDKVideoRenderWrap >
{
	friend class ZoomWrapObject<ZoomVideoNodeSDKVideoRenderWrap >;
public:
	static ZoomVideoNodeSDKVideoRenderWrap& GetInst()
	{
		static ZoomVideoNodeSDKVideoRenderWrap inst;
		return inst;
	}
private:
	ZoomVideoNodeSDKVideoRenderWrap();
	virtual ~ZoomVideoNodeSDKVideoRenderWrap();
public:
	
	static void Subscribe(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void UnSubscribe(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void SubscribeMultiCameraStream(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void UnSubscribeMultiCameraStream(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetMultiCameraStreamList(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<> inline 
void InitClassAttribute<ZoomVideoNodeSDKVideoRenderWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomVideoNodeSDKVideoRenderWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "Subscribe", ZoomVideoNodeSDKVideoRenderWrap::Subscribe);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UnSubscribe", ZoomVideoNodeSDKVideoRenderWrap::UnSubscribe);

	NODE_SET_PROTOTYPE_METHOD(tpl, "SubscribeMultiCameraStream", ZoomVideoNodeSDKVideoRenderWrap::SubscribeMultiCameraStream);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UnSubscribeMultiCameraStream", ZoomVideoNodeSDKVideoRenderWrap::UnSubscribeMultiCameraStream);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMultiCameraStreamList", ZoomVideoNodeSDKVideoRenderWrap::GetMultiCameraStreamList);
	
}
template<> inline 
v8::Persistent<v8::Function>* GetConstructor<ZoomVideoNodeSDKVideoRenderWrap >() {
	return &ZoomVideoNodeSDKVideoRenderWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




#endif
