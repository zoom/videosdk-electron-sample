#include "zoom_video_sdk_node_chat_helper.h"


ZoomVideoNodeChatHelperWrap::ZoomVideoNodeChatHelperWrap()
{
	
}

ZoomVideoNodeChatHelperWrap::~ZoomVideoNodeChatHelperWrap()
{
	
}
void ZoomVideoNodeChatHelperWrap::IsChatDisabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bIs = _g_native_wrap.GetChatHelperWrap().IsChatDisabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bIs);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeChatHelperWrap::IsPrivateChatDisabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bIs = _g_native_wrap.GetChatHelperWrap().IsPrivateChatDisabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bIs);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeChatHelperWrap::SendChatToUser(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Invalid_Parameter;
	do
	{
		com::electron::zoomvideo::sdk::proto::SendChatToUserParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::SendChatToUserParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_user() ||
			!proto_param.has_zn_msgcontent()
			)
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		com::electron::zoomvideo::sdk::proto::VideoSDKUser _User = proto_param.user();
		ZoomSTRING zn_msgContent;
		zn_msgContent = s2zs(proto_param.zn_msgcontent());

		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* zn_pUser = (ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser*)_User.p_user();
		if (zn_pUser)
		{
			err = _g_native_wrap.GetChatHelperWrap().SendChatToUser(zn_pUser, zn_msgContent);
		}
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeChatHelperWrap::SendChatToAll(const v8::FunctionCallbackInfo<v8::Value>& args)
{

	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::SendChatToAllParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::SendChatToAllParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_zn_msgcontent())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		ZoomSTRING zn_msgContent;
		zn_msgContent = s2zs(proto_param.zn_msgcontent());

		err = _g_native_wrap.GetChatHelperWrap().SendChatToAll(zn_msgContent);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeChatHelperWrap::DeleteChatMessage(const v8::FunctionCallbackInfo<v8::Value>& args)
{

	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::DeleteChatMessageParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::DeleteChatMessageParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_messageid())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		ZoomSTRING zn_msgID;
		zn_msgID = s2zs(proto_param.messageid());

		ZNZoomVideoSDKErrors err = _g_native_wrap.GetChatHelperWrap().DeleteChatMessage(zn_msgID);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeChatHelperWrap::CanChatMessageBeDeleted(const v8::FunctionCallbackInfo<v8::Value>& args)
{

	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bIs = false;
	do
	{
		com::electron::zoomvideo::sdk::proto::CanChatMessageBeDeletedParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::CanChatMessageBeDeletedParams >(args, proto_param))
		{
			break;
		}

		if (!proto_param.has_messageid())
		{
			break;
		}

		ZoomSTRING zn_msgID;
		zn_msgID = s2zs(proto_param.messageid());

		zn_bIs = _g_native_wrap.GetChatHelperWrap().CanChatMessageBeDeleted(zn_msgID);
	} while (false);
	
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bIs);
	args.GetReturnValue().Set(bret);
}