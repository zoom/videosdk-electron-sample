#include "zoom_video_sdk_node_remote_camera_control_helper.h"
#include "node_core/zoom_video_sdk_events_wrap_class.h"


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ZoomVideoNodeRemoteCameraControlHelperWrap::ZoomVideoNodeRemoteCameraControlHelperWrap()
{

}

ZoomVideoNodeRemoteCameraControlHelperWrap::~ZoomVideoNodeRemoteCameraControlHelperWrap()
{

}
void ZoomVideoNodeRemoteCameraControlHelperWrap::TurnLeft(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::RemoteCameraCtrlTurnLeftParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::RemoteCameraCtrlTurnLeftParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		if (!proto_param.has_user())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		com::electron::zoomvideo::sdk::proto::VideoSDKUser _User = proto_param.user();

		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* zn_pUser = (ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser*)_User.p_user();
		unsigned int zn_range = 50;
		if (proto_param.has_range())
		{
			zn_range = (ZNVideoRotation)proto_param.range();
		}

		err = _g_native_wrap.GetRemoteCameraCtrlHelperWrap().TurnLeft(zn_pUser, zn_range);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeRemoteCameraControlHelperWrap::TurnRight(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::RemoteCameraCtrlTurnRightParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::RemoteCameraCtrlTurnRightParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		if (!proto_param.has_user())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		com::electron::zoomvideo::sdk::proto::VideoSDKUser _User = proto_param.user();

		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* zn_pUser = (ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser*)_User.p_user();
		unsigned int zn_range = 50;
		if (proto_param.has_range())
		{
			zn_range = (ZNVideoRotation)proto_param.range();
		}

		err = _g_native_wrap.GetRemoteCameraCtrlHelperWrap().TurnRight(zn_pUser, zn_range);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeRemoteCameraControlHelperWrap::TurnUp(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::RemoteCameraCtrlTurnUpParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::RemoteCameraCtrlTurnUpParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		if (!proto_param.has_user())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		com::electron::zoomvideo::sdk::proto::VideoSDKUser _User = proto_param.user();

		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* zn_pUser = (ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser*)_User.p_user();
		unsigned int zn_range = 50;
		if (proto_param.has_range())
		{
			zn_range = (ZNVideoRotation)proto_param.range();
		}

		err = _g_native_wrap.GetRemoteCameraCtrlHelperWrap().TurnUp(zn_pUser, zn_range);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeRemoteCameraControlHelperWrap::TurnDown(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::RemoteCameraCtrlTurnDownParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::RemoteCameraCtrlTurnDownParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		if (!proto_param.has_user())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		com::electron::zoomvideo::sdk::proto::VideoSDKUser _User = proto_param.user();

		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* zn_pUser = (ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser*)_User.p_user();
		unsigned int zn_range = 50;
		if (proto_param.has_range())
		{
			zn_range = (ZNVideoRotation)proto_param.range();
		}

		err = _g_native_wrap.GetRemoteCameraCtrlHelperWrap().TurnDown(zn_pUser, zn_range);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeRemoteCameraControlHelperWrap::ZoomIn(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::RemoteCameraCtrlZoomInParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::RemoteCameraCtrlZoomInParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		if (!proto_param.has_user())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		com::electron::zoomvideo::sdk::proto::VideoSDKUser _User = proto_param.user();

		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* zn_pUser = (ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser*)_User.p_user();
		unsigned int zn_range = 50;
		if (proto_param.has_range())
		{
			zn_range = (ZNVideoRotation)proto_param.range();
		}

		err = _g_native_wrap.GetRemoteCameraCtrlHelperWrap().ZoomIn(zn_pUser, zn_range);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeRemoteCameraControlHelperWrap::ZoomOut(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::RemoteCameraCtrlZoomOutParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::RemoteCameraCtrlZoomOutParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		if (!proto_param.has_user())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		com::electron::zoomvideo::sdk::proto::VideoSDKUser _User = proto_param.user();

		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* zn_pUser = (ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser*)_User.p_user();
		unsigned int zn_range = 50;
		if (proto_param.has_range())
		{
			zn_range = (ZNVideoRotation)proto_param.range();
		}

		err = _g_native_wrap.GetRemoteCameraCtrlHelperWrap().ZoomOut(zn_pUser, zn_range);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeRemoteCameraControlHelperWrap::RequestControlRemoteCamera(const v8::FunctionCallbackInfo<v8::Value>& args) {

	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::RequestControlRemoteCameraParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::RequestControlRemoteCameraParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}


		if (!proto_param.has_user())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		com::electron::zoomvideo::sdk::proto::VideoSDKUser _User = proto_param.user();

		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* zn_pUser = (ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser*)_User.p_user();
		err = ZNZoomVideoSDKErrors_Internal_Error;
		if (zn_pUser)
		{
			err = _g_native_wrap.GetRemoteCameraCtrlHelperWrap().RequestControlRemoteCamera(zn_pUser);
		}
	} while (false);
	

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeRemoteCameraControlHelperWrap::GiveUpControlRemoteCamera(const v8::FunctionCallbackInfo<v8::Value>& args) {

	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::GiveUpControlRemoteCameraParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::GiveUpControlRemoteCameraParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}


		if (!proto_param.has_user())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		com::electron::zoomvideo::sdk::proto::VideoSDKUser _User = proto_param.user();

		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* zn_pUser = (ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser*)_User.p_user();
		err = ZNZoomVideoSDKErrors_Internal_Error;
		if (zn_pUser)
		{
			err = _g_native_wrap.GetRemoteCameraCtrlHelperWrap().GiveUpControlRemoteCamera(zn_pUser);
		}
	} while (false);
	

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ZoomVideoNodeCameraControlRequestHandlerWrap::ZoomVideoNodeCameraControlRequestHandlerWrap()
{

}

ZoomVideoNodeCameraControlRequestHandlerWrap::~ZoomVideoNodeCameraControlRequestHandlerWrap()
{

}
void ZoomVideoNodeCameraControlRequestHandlerWrap::Approve(const v8::FunctionCallbackInfo<v8::Value>& args) {

	v8::Isolate* isolate = args.GetIsolate();

	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKCameraControlRequestHandler::GetInst().Approve();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeCameraControlRequestHandlerWrap::Decline(const v8::FunctionCallbackInfo<v8::Value>& args) {

	v8::Isolate* isolate = args.GetIsolate();

	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKCameraControlRequestHandler::GetInst().Decline();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}