#ifndef _ZOOM_NODE_VIDEO_SDK_VIDEO_HELPER_H_
#define _ZOOM_NODE_VIDEO_SDK_VIDEO_HELPER_H_
#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"
#include "zoom_video_sdk_singleton_wrap_class.h"

extern ZNativeVideoSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomVideoNodeVideoHelperWrap :
	public ZoomWrapObject<ZoomVideoNodeVideoHelperWrap >
{
	friend class ZoomWrapObject<ZoomVideoNodeVideoHelperWrap >;
private:
	ZoomVideoNodeVideoHelperWrap();
	~ZoomVideoNodeVideoHelperWrap();
public:
	static void StartVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StopVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SpotLightVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void UnSpotLightVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void UnSpotlightAllVideos(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetSpotlightedVideoUserList(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void RotateMyVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SwitchCamera(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SelectCamera(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetNumberOfCameras(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetCameraList(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void CanControlCamera(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void TurnCameraLeft(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void TurnCameraRight(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void TurnCameraUp(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void TurnCameraDown(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void ZoomCameraIn(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void ZoomCameraOut(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetVideoQualityPreference(const v8::FunctionCallbackInfo<v8::Value>& args);
#if (!defined __linux)
	static void EnableMultiStreamVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void DisableMultiStreamVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void AddVirtualBackgroundItem(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void RemoveVirtualBackgroundItem(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetVirtualBackgroundItemList(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetVirtualBackgroundItem(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetSelectedVirtualBackgroundItem(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetVirtualBackgroundItemInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
#endif
	static void StartVideoPreview(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StopVideoPreview(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<> inline 
void InitClassAttribute<ZoomVideoNodeVideoHelperWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomVideoNodeVideoHelperWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartVideo", ZoomVideoNodeVideoHelperWrap::StartVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopVideo", ZoomVideoNodeVideoHelperWrap::StopVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SpotLightVideo", ZoomVideoNodeVideoHelperWrap::SpotLightVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UnSpotLightVideo", ZoomVideoNodeVideoHelperWrap::UnSpotLightVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UnSpotlightAllVideos", ZoomVideoNodeVideoHelperWrap::UnSpotlightAllVideos);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSpotlightedVideoUserList", ZoomVideoNodeVideoHelperWrap::GetSpotlightedVideoUserList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RotateMyVideo", ZoomVideoNodeVideoHelperWrap::RotateMyVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SwitchCamera", ZoomVideoNodeVideoHelperWrap::SwitchCamera);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SelectCamera", ZoomVideoNodeVideoHelperWrap::SelectCamera);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetNumberOfCameras", ZoomVideoNodeVideoHelperWrap::GetNumberOfCameras);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetCameraList", ZoomVideoNodeVideoHelperWrap::GetCameraList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanControlCamera", ZoomVideoNodeVideoHelperWrap::CanControlCamera);
	NODE_SET_PROTOTYPE_METHOD(tpl, "TurnCameraLeft", ZoomVideoNodeVideoHelperWrap::TurnCameraLeft);
	NODE_SET_PROTOTYPE_METHOD(tpl, "TurnCameraRight", ZoomVideoNodeVideoHelperWrap::TurnCameraRight);
	NODE_SET_PROTOTYPE_METHOD(tpl, "TurnCameraUp", ZoomVideoNodeVideoHelperWrap::TurnCameraUp);
	NODE_SET_PROTOTYPE_METHOD(tpl, "TurnCameraDown", ZoomVideoNodeVideoHelperWrap::TurnCameraDown);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ZoomCameraIn", ZoomVideoNodeVideoHelperWrap::ZoomCameraIn);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ZoomCameraOut", ZoomVideoNodeVideoHelperWrap::ZoomCameraOut);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetVideoQualityPreference", ZoomVideoNodeVideoHelperWrap::SetVideoQualityPreference);
#if !defined __linux
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableMultiStreamVideo", ZoomVideoNodeVideoHelperWrap::EnableMultiStreamVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DisableMultiStreamVideo", ZoomVideoNodeVideoHelperWrap::DisableMultiStreamVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "AddVirtualBackgroundItem", ZoomVideoNodeVideoHelperWrap::AddVirtualBackgroundItem);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RemoveVirtualBackgroundItem", ZoomVideoNodeVideoHelperWrap::RemoveVirtualBackgroundItem);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetVirtualBackgroundItemList", ZoomVideoNodeVideoHelperWrap::GetVirtualBackgroundItemList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetVirtualBackgroundItem", ZoomVideoNodeVideoHelperWrap::SetVirtualBackgroundItem);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSelectedVirtualBackgroundItem", ZoomVideoNodeVideoHelperWrap::GetSelectedVirtualBackgroundItem);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetVirtualBackgroundItemInfo", ZoomVideoNodeVideoHelperWrap::GetVirtualBackgroundItemInfo);
#endif
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartVideoPreview", ZoomVideoNodeVideoHelperWrap::StartVideoPreview);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopVideoPreview", ZoomVideoNodeVideoHelperWrap::StopVideoPreview);
}
template<> inline 
v8::Persistent<v8::Function>* GetConstructor<ZoomVideoNodeVideoHelperWrap >() {
	return &ZoomVideoNodeVideoHelperWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif
