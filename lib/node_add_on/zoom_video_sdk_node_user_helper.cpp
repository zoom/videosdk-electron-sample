#include "zoom_video_sdk_node_user_helper.h"


ZoomVideoNodeUserHelperWrap::ZoomVideoNodeUserHelperWrap()
{
	
}

ZoomVideoNodeUserHelperWrap::~ZoomVideoNodeUserHelperWrap()
{
	
}

void ZoomVideoNodeUserHelperWrap::ChangeName(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bret = false;
	do
	{
		com::electron::zoomvideo::sdk::proto::ChangeNameParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::ChangeNameParams >(args, proto_param))
		{
			break;
		}

		if (!proto_param.has_zn_name() ||
			!proto_param.has_user()
			)
		{
			break;
		}

		ZoomSTRING zn_name;
		zn_name = s2zs(proto_param.zn_name());
		com::electron::zoomvideo::sdk::proto::VideoSDKUser _User = proto_param.user();

		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* zn_pUser = (ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser*)_User.p_user();

		if (zn_pUser)
		{
			zn_bret = _g_native_wrap.GetUserHelperWrap().ChangeName(zn_name, zn_pUser);
		}
	} while (false);
	
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bret);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeUserHelperWrap::MakeHost(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bret = false;
	do
	{
		com::electron::zoomvideo::sdk::proto::MakeHostParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::MakeHostParams >(args, proto_param))
		{
			break;
		}

		if (!proto_param.has_user())
		{
			break;
		}

		com::electron::zoomvideo::sdk::proto::VideoSDKUser _User = proto_param.user();

		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* zn_pUser = (ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser*)_User.p_user();

		if (zn_pUser)
		{
			zn_bret = _g_native_wrap.GetUserHelperWrap().MakeHost(zn_pUser);
		}
	} while (false);
	
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bret);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeUserHelperWrap::MakeManager(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bret = false;
	do
	{
		com::electron::zoomvideo::sdk::proto::MakeManagerParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::MakeManagerParams >(args, proto_param))
		{
			break;
		}

		if (!proto_param.has_user())
		{
			break;
		}

		com::electron::zoomvideo::sdk::proto::VideoSDKUser _User = proto_param.user();

		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* zn_pUser = (ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser*)_User.p_user();

		if (zn_pUser)
		{
			zn_bret = _g_native_wrap.GetUserHelperWrap().MakeManager(zn_pUser);
		}
	} while (false);

	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bret);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeUserHelperWrap::RevokeManager(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bret = false;
	do
	{
		com::electron::zoomvideo::sdk::proto::RevokeManagerParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::RevokeManagerParams >(args, proto_param))
		{
			break;
		}

		if (!proto_param.has_user())
		{
			break;
		}


		com::electron::zoomvideo::sdk::proto::VideoSDKUser _User = proto_param.user();

		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* zn_pUser = (ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser*)_User.p_user();

		if (zn_pUser)
		{
			zn_bret = _g_native_wrap.GetUserHelperWrap().RevokeManager(zn_pUser);
		}
	} while (false);
	
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bret);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeUserHelperWrap::RemoveUser(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool err = false;
	do
	{
		com::electron::zoomvideo::sdk::proto::RemoveUserParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::RemoveUserParams >(args, proto_param))
		{
			break;
		}

		if (!proto_param.has_user())
		{
			break;
		}


		com::electron::zoomvideo::sdk::proto::VideoSDKUser _User = proto_param.user();

		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* zn_pUser = (ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser*)_User.p_user();

		if (zn_pUser)
		{
			err = _g_native_wrap.GetUserHelperWrap().RemoveUser(zn_pUser);
		}
	} while (false);
	
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);
}
