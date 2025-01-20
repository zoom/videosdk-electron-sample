#ifndef _ZOOM_VIDEO_SDK_NODE_ADDON_H_
#define _ZOOM_VIDEO_SDK_NODE_ADDON_H_
#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"
#include "zoom_video_sdk_singleton_wrap_class.h"

class VideoNodeAddonData {
public:
	explicit VideoNodeAddonData(v8::Isolate* isolate)
	{
		node::AddEnvironmentCleanupHook(isolate, DeleteInstance, this);
	}

	v8::Local<v8::Object> zoomNodeWrapInstance;

	static void DeleteInstance(void* data) {
		delete static_cast<VideoNodeAddonData*>(data);
	}
};

class ZOOM_NODE_HIDE ZoomVideoNodeWrap : public ZoomWrapObject<ZoomVideoNodeWrap >
{
	friend class ZoomWrapObject<ZoomVideoNodeWrap >;
private:
	ZoomVideoNodeWrap();
	~ZoomVideoNodeWrap();

public:
	static void CreateZoomVideoSDKObj(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void DestroyZoomVideoSDKObj(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Initialize(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void CleanUp(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void JoinSession(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void LeaveSession(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsInSession(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetSDKVersion(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void InputSessionPassword(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void LeaveSessionIgnorePassword(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void GetSessionInfoCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetAudioHelper(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetVideoHelper(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetShareHelper(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetUserHelper(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetVideoSDKRender(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetVideoSDKRawDataServerMgr(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetChatHelper(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetLiveStreamHelper(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetIncomingLiveStreamHelper(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetCmdChannel(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetPhoneHelper(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetCameraControlRequestHandler(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetRemoteCameraCtrlHelper(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetRecordingHelper(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetAudioSetting(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetTestAudioDevice(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetLiveTranscriptionHelper(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetShareSetting(const v8::FunctionCallbackInfo<v8::Value>& args);
#if (!defined __linux)
	static void GetRemoteControlRequestHandler(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetRemoteCtrlHelper(const v8::FunctionCallbackInfo<v8::Value>& args);
#endif

	static void SetNodeAddonCallbacks(const v8::FunctionCallbackInfo<v8::Value>& args);
	

	static v8::Persistent<v8::Function> constructor;
};
template<> inline 
void InitClassAttribute<ZoomVideoNodeWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomVideoNodeWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "CreateZoomVideoSDKObj", ZoomVideoNodeWrap::CreateZoomVideoSDKObj);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DestroyZoomVideoSDKObj", ZoomVideoNodeWrap::DestroyZoomVideoSDKObj);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Initialize", ZoomVideoNodeWrap::Initialize);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CleanUp", ZoomVideoNodeWrap::CleanUp);
	NODE_SET_PROTOTYPE_METHOD(tpl, "JoinSession", ZoomVideoNodeWrap::JoinSession);
	NODE_SET_PROTOTYPE_METHOD(tpl, "LeaveSession", ZoomVideoNodeWrap::LeaveSession);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsInSession", ZoomVideoNodeWrap::IsInSession);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSDKVersion", ZoomVideoNodeWrap::GetSDKVersion);

	NODE_SET_PROTOTYPE_METHOD(tpl, "InputSessionPassword", ZoomVideoNodeWrap::InputSessionPassword);
	NODE_SET_PROTOTYPE_METHOD(tpl, "LeaveSessionIgnorePassword", ZoomVideoNodeWrap::LeaveSessionIgnorePassword);

	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSessionInfoCtrl", ZoomVideoNodeWrap::GetSessionInfoCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetAudioHelper", ZoomVideoNodeWrap::GetAudioHelper);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetVideoHelper", ZoomVideoNodeWrap::GetVideoHelper);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetShareHelper", ZoomVideoNodeWrap::GetShareHelper);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetUserHelper", ZoomVideoNodeWrap::GetUserHelper);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetVideoSDKRender", ZoomVideoNodeWrap::GetVideoSDKRender);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetVideoSDKRawDataServerMgr", ZoomVideoNodeWrap::GetVideoSDKRawDataServerMgr);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetChatHelper", ZoomVideoNodeWrap::GetChatHelper);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetLiveStreamHelper", ZoomVideoNodeWrap::GetLiveStreamHelper);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetIncomingLiveStreamHelper", ZoomVideoNodeWrap::GetIncomingLiveStreamHelper);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetCmdChannel", ZoomVideoNodeWrap::GetCmdChannel);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetPhoneHelper", ZoomVideoNodeWrap::GetPhoneHelper);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetCameraControlRequestHandler", ZoomVideoNodeWrap::GetCameraControlRequestHandler);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetRemoteCameraCtrlHelper", ZoomVideoNodeWrap::GetRemoteCameraCtrlHelper);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetRecordingHelper", ZoomVideoNodeWrap::GetRecordingHelper);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetAudioSetting", ZoomVideoNodeWrap::GetAudioSetting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetTestAudioDevice", ZoomVideoNodeWrap::GetTestAudioDevice);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetLiveTranscriptionHelper", ZoomVideoNodeWrap::GetLiveTranscriptionHelper);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetShareSetting", ZoomVideoNodeWrap::GetShareSetting);
#if (!defined __linux)
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetRemoteControlRequestHandler", ZoomVideoNodeWrap::GetRemoteControlRequestHandler);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetRemoteCtrlHelper", ZoomVideoNodeWrap::GetRemoteCtrlHelper);
#endif

	NODE_SET_PROTOTYPE_METHOD(tpl, "SetNodeAddonCallbacks", ZoomVideoNodeWrap::SetNodeAddonCallbacks);

}
template<> inline 
v8::Persistent<v8::Function>* GetConstructor<ZoomVideoNodeWrap >() {
	return &ZoomVideoNodeWrap::constructor;
}



#endif
