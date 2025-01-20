#ifndef _ZOOM_NODE_VIDEO_SDK_SHARE_SETTING_H_
#define _ZOOM_NODE_VIDEO_SDK_SHARE_SETTING_H_
#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"
#include "zoom_video_sdk_singleton_wrap_class.h"

extern ZNativeVideoSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomVideoNodeShareSettingWrap :
	public ZoomWrapObject<ZoomVideoNodeShareSettingWrap >
{
	friend class ZoomWrapObject<ZoomVideoNodeShareSettingWrap >;
private:
	ZoomVideoNodeShareSettingWrap();
	~ZoomVideoNodeShareSettingWrap();
public:
	static void SetScreenCaptureMode(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetScreenCaptureMode(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableGreenBorder(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsGreenBorderEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
#if (defined _WIN32)	
	static void EnableAdminRemoteControl(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsRemoteControlAllApplicationsEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
#endif
	static v8::Persistent<v8::Function> constructor;
};
template<> inline 
void InitClassAttribute<ZoomVideoNodeShareSettingWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomVideoNodeShareSettingWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetScreenCaptureMode", ZoomVideoNodeShareSettingWrap::SetScreenCaptureMode);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetScreenCaptureMode", ZoomVideoNodeShareSettingWrap::GetScreenCaptureMode);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableGreenBorder", ZoomVideoNodeShareSettingWrap::EnableGreenBorder);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsGreenBorderEnabled", ZoomVideoNodeShareSettingWrap::IsGreenBorderEnabled);
#if (defined _WIN32)
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAdminRemoteControl", ZoomVideoNodeShareSettingWrap::EnableAdminRemoteControl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsRemoteControlAllApplicationsEnabled", ZoomVideoNodeShareSettingWrap::IsRemoteControlAllApplicationsEnabled);
#endif
}
template<> inline 
v8::Persistent<v8::Function>* GetConstructor<ZoomVideoNodeShareSettingWrap >() {
	return &ZoomVideoNodeShareSettingWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif