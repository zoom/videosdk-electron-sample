#ifndef _ZOOM_NODE_VIDEO_SDK_SESSION_INFO_CTRL_H_
#define _ZOOM_NODE_VIDEO_SDK_SESSION_INFO_CTRL_H_
#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"
#include "zoom_video_sdk_singleton_wrap_class.h"

extern ZNativeVideoSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomVideoNodeSessionInfoCtrlWrap :
	public ZoomWrapObject<ZoomVideoNodeSessionInfoCtrlWrap >
{
	friend class ZoomWrapObject<ZoomVideoNodeSessionInfoCtrlWrap >;
private:
	ZoomVideoNodeSessionInfoCtrlWrap();
	~ZoomVideoNodeSessionInfoCtrlWrap();
public:
	
	static void GetSessionName(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetSessionPassword(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetSessionID(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetSessionHostName(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetSessionHost(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetRemoteUsers(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetMyself(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetSessionAudioStatisticInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetSessionVideoStatisticInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetSessionShareStatisticInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<> inline 
void InitClassAttribute<ZoomVideoNodeSessionInfoCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomVideoNodeSessionInfoCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSessionName", ZoomVideoNodeSessionInfoCtrlWrap::GetSessionName);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSessionID", ZoomVideoNodeSessionInfoCtrlWrap::GetSessionID);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSessionPassword", ZoomVideoNodeSessionInfoCtrlWrap::GetSessionPassword);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSessionHostName", ZoomVideoNodeSessionInfoCtrlWrap::GetSessionHostName);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSessionHost", ZoomVideoNodeSessionInfoCtrlWrap::GetSessionHost);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetRemoteUsers", ZoomVideoNodeSessionInfoCtrlWrap::GetRemoteUsers);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMyself", ZoomVideoNodeSessionInfoCtrlWrap::GetMyself);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSessionAudioStatisticInfo", ZoomVideoNodeSessionInfoCtrlWrap::GetSessionAudioStatisticInfo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSessionVideoStatisticInfo", ZoomVideoNodeSessionInfoCtrlWrap::GetSessionVideoStatisticInfo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSessionShareStatisticInfo", ZoomVideoNodeSessionInfoCtrlWrap::GetSessionShareStatisticInfo);

}
template<> inline 
v8::Persistent<v8::Function>* GetConstructor<ZoomVideoNodeSessionInfoCtrlWrap >() {
	return &ZoomVideoNodeSessionInfoCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif
