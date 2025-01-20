#ifndef _ZOOM_NODE_VIDEO_SDK_REMOTE_CAMERA_CONTROLLER_HELPER_H_
#define _ZOOM_NODE_VIDEO_SDK_REMOTE_CAMERA_CONTROLLER_HELPER_H_
#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"
#include "zoom_video_sdk_singleton_wrap_class.h"

extern ZNativeVideoSDKWrap _g_native_wrap;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ZOOM_NODE_HIDE ZoomVideoNodeRemoteCameraControlHelperWrap :
	public ZoomWrapObject<ZoomVideoNodeRemoteCameraControlHelperWrap >
{
	friend class ZoomWrapObject<ZoomVideoNodeRemoteCameraControlHelperWrap >;
private:
	ZoomVideoNodeRemoteCameraControlHelperWrap();
	~ZoomVideoNodeRemoteCameraControlHelperWrap();
public:
	static void RequestControlRemoteCamera(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GiveUpControlRemoteCamera(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void TurnLeft(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void TurnRight(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void TurnUp(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void TurnDown(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void ZoomIn(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void ZoomOut(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<> inline 
void InitClassAttribute<ZoomVideoNodeRemoteCameraControlHelperWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomVideoNodeRemoteCameraControlHelperWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "RequestControlRemoteCamera", ZoomVideoNodeRemoteCameraControlHelperWrap::RequestControlRemoteCamera);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GiveUpControlRemoteCamera", ZoomVideoNodeRemoteCameraControlHelperWrap::GiveUpControlRemoteCamera);
	NODE_SET_PROTOTYPE_METHOD(tpl, "TurnLeft", ZoomVideoNodeRemoteCameraControlHelperWrap::TurnLeft);
	NODE_SET_PROTOTYPE_METHOD(tpl, "TurnRight", ZoomVideoNodeRemoteCameraControlHelperWrap::TurnRight);
	NODE_SET_PROTOTYPE_METHOD(tpl, "TurnUp", ZoomVideoNodeRemoteCameraControlHelperWrap::TurnUp);
	NODE_SET_PROTOTYPE_METHOD(tpl, "TurnDown", ZoomVideoNodeRemoteCameraControlHelperWrap::TurnDown);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ZoomIn", ZoomVideoNodeRemoteCameraControlHelperWrap::ZoomIn);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ZoomOut", ZoomVideoNodeRemoteCameraControlHelperWrap::ZoomOut);
}
template<> inline 
v8::Persistent<v8::Function>* GetConstructor<ZoomVideoNodeRemoteCameraControlHelperWrap >() {
	return &ZoomVideoNodeRemoteCameraControlHelperWrap::constructor;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ZOOM_NODE_HIDE ZoomVideoNodeCameraControlRequestHandlerWrap :
	public ZoomWrapObject<ZoomVideoNodeCameraControlRequestHandlerWrap >
{
	friend class ZoomWrapObject<ZoomVideoNodeCameraControlRequestHandlerWrap >;
private:
	ZoomVideoNodeCameraControlRequestHandlerWrap();
	~ZoomVideoNodeCameraControlRequestHandlerWrap();
public:
	static void Approve(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Decline(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<> inline 
void InitClassAttribute<ZoomVideoNodeCameraControlRequestHandlerWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomVideoNodeCameraControlRequestHandlerWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "Approve", ZoomVideoNodeCameraControlRequestHandlerWrap::Approve);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Decline", ZoomVideoNodeCameraControlRequestHandlerWrap::Decline);

}
template<> inline 
v8::Persistent<v8::Function>* GetConstructor<ZoomVideoNodeCameraControlRequestHandlerWrap >() {
	return &ZoomVideoNodeCameraControlRequestHandlerWrap::constructor;
}

#endif
