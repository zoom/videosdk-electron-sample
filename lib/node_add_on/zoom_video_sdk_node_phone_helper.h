#ifndef _ZOOM_NODE_VIDEO_SDK_PHONE_HELPER_H_
#define _ZOOM_NODE_VIDEO_SDK_PHONE_HELPER_H_
#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"
#include "zoom_video_sdk_singleton_wrap_class.h"

extern ZNativeVideoSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomVideoNodePhoneHelperWrap :
	public ZoomWrapObject<ZoomVideoNodePhoneHelperWrap >
{
	friend class ZoomWrapObject<ZoomVideoNodePhoneHelperWrap >;
private:
	ZoomVideoNodePhoneHelperWrap();
	~ZoomVideoNodePhoneHelperWrap();
public:
	static void IsSupportPhoneFeature(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetSupportCountryInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void InviteByPhone(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void InvitePhoneUser(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void CancelInviteByPhone(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetInviteByPhoneStatus(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<> inline 
void InitClassAttribute<ZoomVideoNodePhoneHelperWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomVideoNodePhoneHelperWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsSupportPhoneFeature", ZoomVideoNodePhoneHelperWrap::IsSupportPhoneFeature);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSupportCountryInfo", ZoomVideoNodePhoneHelperWrap::GetSupportCountryInfo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "InviteByPhone", ZoomVideoNodePhoneHelperWrap::InviteByPhone);
	NODE_SET_PROTOTYPE_METHOD(tpl, "InvitePhoneUser", ZoomVideoNodePhoneHelperWrap::InvitePhoneUser);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CancelInviteByPhone", ZoomVideoNodePhoneHelperWrap::CancelInviteByPhone);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetInviteByPhoneStatus", ZoomVideoNodePhoneHelperWrap::GetInviteByPhoneStatus);
}
template<> inline 
v8::Persistent<v8::Function>* GetConstructor<ZoomVideoNodePhoneHelperWrap >() {
	return &ZoomVideoNodePhoneHelperWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif
