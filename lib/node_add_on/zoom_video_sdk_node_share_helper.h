#ifndef _ZOOM_NODE_VIDEO_SDK_SHARE_HELPER_H_
#define _ZOOM_NODE_VIDEO_SDK_SHARE_HELPER_H_
#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"
#include "zoom_video_sdk_singleton_wrap_class.h"

#include "zoom_video_sdk_node_rawdata_helper_mgr_class.h"

extern ZNativeVideoSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomVideoNodeShareHelperWrap :
	public ZoomWrapObject<ZoomVideoNodeShareHelperWrap >
{
	friend class ZoomWrapObject<ZoomVideoNodeShareHelperWrap >;
private:
	ZoomVideoNodeShareHelperWrap();
	~ZoomVideoNodeShareHelperWrap();
public:
	static void StartShareView(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StartShareScreen(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StartShareComputerAudio(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StopShare(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsSharingOut(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsScreenSharingOut(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsOtherSharing(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void LockShare(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsShareLocked(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetMonitorsList(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void EnableShareDeviceAudio(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsShareDeviceAudioEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableOptimizeForSharedVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsOptimizeForSharedVideoEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StartShare2ndCamera(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<> inline 
void InitClassAttribute<ZoomVideoNodeShareHelperWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomVideoNodeShareHelperWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartShareView", ZoomVideoNodeShareHelperWrap::StartShareView);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartShareScreen", ZoomVideoNodeShareHelperWrap::StartShareScreen);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartShareComputerAudio", ZoomVideoNodeShareHelperWrap::StartShareComputerAudio);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopShare", ZoomVideoNodeShareHelperWrap::StopShare);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsSharingOut", ZoomVideoNodeShareHelperWrap::IsSharingOut);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsScreenSharingOut", ZoomVideoNodeShareHelperWrap::IsScreenSharingOut);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsOtherSharing", ZoomVideoNodeShareHelperWrap::IsOtherSharing);
	NODE_SET_PROTOTYPE_METHOD(tpl, "LockShare", ZoomVideoNodeShareHelperWrap::LockShare);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsShareLocked", ZoomVideoNodeShareHelperWrap::IsShareLocked);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMonitorsList", ZoomVideoNodeShareHelperWrap::GetMonitorsList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableShareDeviceAudio", ZoomVideoNodeShareHelperWrap::EnableShareDeviceAudio);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsShareDeviceAudioEnabled", ZoomVideoNodeShareHelperWrap::IsShareDeviceAudioEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableOptimizeForSharedVideo", ZoomVideoNodeShareHelperWrap::EnableOptimizeForSharedVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsOptimizeForSharedVideoEnabled", ZoomVideoNodeShareHelperWrap::IsOptimizeForSharedVideoEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartShare2ndCamera", ZoomVideoNodeShareHelperWrap::StartShare2ndCamera);
}
template<> inline 
v8::Persistent<v8::Function>* GetConstructor<ZoomVideoNodeShareHelperWrap >() {
	return &ZoomVideoNodeShareHelperWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif
