#include "zoom_video_sdk_node_share_setting.h"

ZoomVideoNodeShareSettingWrap::ZoomVideoNodeShareSettingWrap()
{
	
}

ZoomVideoNodeShareSettingWrap::~ZoomVideoNodeShareSettingWrap()
{
	
}

void ZoomVideoNodeShareSettingWrap::SetScreenCaptureMode(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::SetScreenCaptureModeParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::SetScreenCaptureModeParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_capturemode())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		int temp = (int)proto_param.capturemode();
		ZNZoomVideoSDKScreenCaptureMode zn_capturemode = (ZNZoomVideoSDKScreenCaptureMode)temp;

		err = _g_native_wrap.GetShareSettingWrap().SetScreenCaptureMode(zn_capturemode);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeShareSettingWrap::GetScreenCaptureMode(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	ZNZoomVideoSDKScreenCaptureMode zn_capturemode = ZNZoomVideoSDKScreenCaptureMode_Auto;
	ZNZoomVideoSDKErrors err = _g_native_wrap.GetShareSettingWrap().GetScreenCaptureMode(zn_capturemode);
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "capturemode", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_capturemode));
	args.GetReturnValue().Set(node);
}
void ZoomVideoNodeShareSettingWrap::EnableGreenBorder(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::EnableGreenBorderParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::EnableGreenBorderParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_benable())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		bool bEnable;
		convertBool(proto_param.benable(), bEnable);

		err = _g_native_wrap.GetShareSettingWrap().EnableGreenBorder(bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeShareSettingWrap::IsGreenBorderEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bIs= _g_native_wrap.GetShareSettingWrap().IsGreenBorderEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bIs);
	args.GetReturnValue().Set(bret);
}
#if (defined _WIN32)
void ZoomVideoNodeShareSettingWrap::EnableAdminRemoteControl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::EnableAdminRemoteControlParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::EnableAdminRemoteControlParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_benable())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		bool bEnable;
		convertBool(proto_param.benable(), bEnable);

		err = _g_native_wrap.GetShareSettingWrap().EnableAdminRemoteControl(bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeShareSettingWrap::IsRemoteControlAllApplicationsEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bIs= _g_native_wrap.GetShareSettingWrap().IsRemoteControlAllApplicationsEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bIs);
	args.GetReturnValue().Set(bret);
}
#endif