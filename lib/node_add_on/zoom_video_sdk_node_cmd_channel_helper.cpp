#include "zoom_video_sdk_node_cmd_channel_helper.h"


ZoomVideoNodeCmdChannelHelperWrap::ZoomVideoNodeCmdChannelHelperWrap()
{
	
}

ZoomVideoNodeCmdChannelHelperWrap::~ZoomVideoNodeCmdChannelHelperWrap()
{
	
}
void ZoomVideoNodeCmdChannelHelperWrap::SendCommand(const v8::FunctionCallbackInfo<v8::Value>& args) 
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::SendCommandParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::SendCommandParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_strcmd())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* zn_pUser = NULL;
		if (proto_param.has_user())
		{
			com::electron::zoomvideo::sdk::proto::VideoSDKUser _User = proto_param.user();
			zn_pUser = (ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser*)_User.p_user();
		}

		ZoomSTRING zn_strcmd;
		zn_strcmd = s2zs(proto_param.strcmd());

		err = _g_native_wrap.GetCmdChannelWrap().SendCommand(zn_pUser, zn_strcmd);
	} while (false);
	
	v8::Local<v8::Integer> ret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(ret);	
}