#ifndef _ZOOM_VIDEO_SDK_NODE_RAWDATA_SERVER_MGR_H_
#define _ZOOM_VIDEO_SDK_NODE_RAWDATA_SERVER_MGR_H_

#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"
#include "zoom_video_sdk_singleton_wrap_class.h"

#include "zoom_video_sdk_node_rawdata_helper_mgr_class.h"

extern ZNativeVideoSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomVideoNodeSDKRawdataServerMgrWrap :
	public ZoomWrapObject<ZoomVideoNodeSDKRawdataServerMgrWrap >
{
	friend class ZoomWrapObject<ZoomVideoNodeSDKRawdataServerMgrWrap >;
private:
	ZoomVideoNodeSDKRawdataServerMgrWrap();
	virtual ~ZoomVideoNodeSDKRawdataServerMgrWrap();
public:
	
	static void StartVideoServer(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StopVideoServer(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StartAudioServer(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StopAudioServer(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<> inline 
void InitClassAttribute<ZoomVideoNodeSDKRawdataServerMgrWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomVideoNodeSDKRawdataServerMgrWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartVideoServer", ZoomVideoNodeSDKRawdataServerMgrWrap::StartVideoServer);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopVideoServer", ZoomVideoNodeSDKRawdataServerMgrWrap::StopVideoServer);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartAudioServer", ZoomVideoNodeSDKRawdataServerMgrWrap::StartAudioServer);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopAudioServer", ZoomVideoNodeSDKRawdataServerMgrWrap::StopAudioServer);

}
template<> inline 
v8::Persistent<v8::Function>* GetConstructor<ZoomVideoNodeSDKRawdataServerMgrWrap >() {
	return &ZoomVideoNodeSDKRawdataServerMgrWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




#endif
