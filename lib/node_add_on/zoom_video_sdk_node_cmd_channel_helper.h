#ifndef _ZOOM_NODE_VIDEO_SDK_CMD_CHANNEL_HELPER_H_
#define _ZOOM_NODE_VIDEO_SDK_CMD_CHANNEL_HELPER_H_
#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"
#include "zoom_video_sdk_singleton_wrap_class.h"

extern ZNativeVideoSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomVideoNodeCmdChannelHelperWrap :
	public ZoomWrapObject<ZoomVideoNodeCmdChannelHelperWrap >
{
	friend class ZoomWrapObject<ZoomVideoNodeCmdChannelHelperWrap >;
private:
	ZoomVideoNodeCmdChannelHelperWrap();
	~ZoomVideoNodeCmdChannelHelperWrap();
public:
	static void SendCommand(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<> inline 
void InitClassAttribute<ZoomVideoNodeCmdChannelHelperWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomVideoNodeCmdChannelHelperWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "SendCommand", ZoomVideoNodeCmdChannelHelperWrap::SendCommand);
}
template<> inline 
v8::Persistent<v8::Function>* GetConstructor<ZoomVideoNodeCmdChannelHelperWrap >() {
	return &ZoomVideoNodeCmdChannelHelperWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif
