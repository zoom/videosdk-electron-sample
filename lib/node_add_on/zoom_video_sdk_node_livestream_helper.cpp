#include "zoom_video_sdk_node_livestream_helper.h"


ZoomVideoNodeLiveStreamHelperWrap::ZoomVideoNodeLiveStreamHelperWrap()
{
	
}

ZoomVideoNodeLiveStreamHelperWrap::~ZoomVideoNodeLiveStreamHelperWrap()
{
	
}
void ZoomVideoNodeLiveStreamHelperWrap::StartLiveStream(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::StartLiveStreamParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::StartLiveStreamParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_zn_streamurl() ||
			!proto_param.has_zn_key() ||
			!proto_param.has_zn_broadcasturl()
			)
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}


		ZoomSTRING zn_streamUrl;
		zn_streamUrl = s2zs(proto_param.zn_streamurl());
		ZoomSTRING zn_key;
		zn_key = s2zs(proto_param.zn_key());
		ZoomSTRING zn_broadcastUrl;
		zn_broadcastUrl = s2zs(proto_param.zn_broadcasturl());


	    err = _g_native_wrap.GetLiveStreamHelperWrap().StartLiveStream(zn_streamUrl, zn_key, zn_broadcastUrl);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeLiveStreamHelperWrap::StopLiveStream(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err =  _g_native_wrap.GetLiveStreamHelperWrap().StopLiveStream();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeLiveStreamHelperWrap::CanStartLiveStream(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = _g_native_wrap.GetLiveStreamHelperWrap().CanStartLiveStream();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}


ZoomVideoNodeIncomingLiveStreamHelperWrap::ZoomVideoNodeIncomingLiveStreamHelperWrap()
{
	
}

ZoomVideoNodeIncomingLiveStreamHelperWrap::~ZoomVideoNodeIncomingLiveStreamHelperWrap()
{
	
}
void ZoomVideoNodeIncomingLiveStreamHelperWrap::BindIncomingLiveStream(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::IncomingLiveStreamParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::IncomingLiveStreamParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_strstreamkeyid())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		ZoomSTRING zn_strStreamKeyID;
		zn_strStreamKeyID = s2zs(proto_param.strstreamkeyid());

	    err = _g_native_wrap.GetIncomingLiveStreamHelperWrap().BindIncomingLiveStream(zn_strStreamKeyID);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeIncomingLiveStreamHelperWrap::UnbindIncomingLiveStream(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::IncomingLiveStreamParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::IncomingLiveStreamParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_strstreamkeyid())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		ZoomSTRING zn_strStreamKeyID;
		zn_strStreamKeyID = s2zs(proto_param.strstreamkeyid());

	    err = _g_native_wrap.GetIncomingLiveStreamHelperWrap().UnbindIncomingLiveStream(zn_strStreamKeyID);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeIncomingLiveStreamHelperWrap::GetIncomingLiveStreamStatus(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = _g_native_wrap.GetIncomingLiveStreamHelperWrap().GetIncomingLiveStreamStatus();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeIncomingLiveStreamHelperWrap::StartIncomingLiveStream(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::IncomingLiveStreamParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::IncomingLiveStreamParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_strstreamkeyid())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		ZoomSTRING zn_strStreamKeyID;
		zn_strStreamKeyID = s2zs(proto_param.strstreamkeyid());

	    err = _g_native_wrap.GetIncomingLiveStreamHelperWrap().StartIncomingLiveStream(zn_strStreamKeyID);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeIncomingLiveStreamHelperWrap::StopIncomingLiveStream(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::IncomingLiveStreamParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::IncomingLiveStreamParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_strstreamkeyid())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		ZoomSTRING zn_strStreamKeyID;
		zn_strStreamKeyID = s2zs(proto_param.strstreamkeyid());

	    err = _g_native_wrap.GetIncomingLiveStreamHelperWrap().StopIncomingLiveStream(zn_strStreamKeyID);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}