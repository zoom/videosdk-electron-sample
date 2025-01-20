#ifndef _ZOOM_NODE_VIDEO_SDK_CHAT_HELPER_H_
#define _ZOOM_NODE_VIDEO_SDK_CHAT_HELPER_H_
#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"
#include "zoom_video_sdk_singleton_wrap_class.h"

extern ZNativeVideoSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomVideoNodeChatHelperWrap :
	public ZoomWrapObject<ZoomVideoNodeChatHelperWrap >
{
	friend class ZoomWrapObject<ZoomVideoNodeChatHelperWrap >;
private:
	ZoomVideoNodeChatHelperWrap();
	~ZoomVideoNodeChatHelperWrap();
public:
	static void IsChatDisabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsPrivateChatDisabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SendChatToUser(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SendChatToAll(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void CanChatMessageBeDeleted(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void DeleteChatMessage(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<> inline 
void InitClassAttribute<ZoomVideoNodeChatHelperWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomVideoNodeChatHelperWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsChatDisabled", ZoomVideoNodeChatHelperWrap::IsChatDisabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsPrivateChatDisabled", ZoomVideoNodeChatHelperWrap::IsPrivateChatDisabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SendChatToUser", ZoomVideoNodeChatHelperWrap::SendChatToUser);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SendChatToAll", ZoomVideoNodeChatHelperWrap::SendChatToAll);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanChatMessageBeDeleted", ZoomVideoNodeChatHelperWrap::CanChatMessageBeDeleted);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DeleteChatMessage", ZoomVideoNodeChatHelperWrap::DeleteChatMessage);
}
template<> inline 
v8::Persistent<v8::Function>* GetConstructor<ZoomVideoNodeChatHelperWrap >() {
	return &ZoomVideoNodeChatHelperWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif
