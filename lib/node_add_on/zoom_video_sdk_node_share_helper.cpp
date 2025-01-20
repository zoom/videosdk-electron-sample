#include "zoom_video_sdk_node_share_helper.h"
#include "zoom_video_sdk_node_video_raw_data.h"

ZoomVideoNodeShareHelperWrap::ZoomVideoNodeShareHelperWrap()
{
	
}

ZoomVideoNodeShareHelperWrap::~ZoomVideoNodeShareHelperWrap()
{
	
}
void ZoomVideoNodeShareHelperWrap::StartShareView(const v8::FunctionCallbackInfo<v8::Value>& args) {

	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::StartShareViewParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::StartShareViewParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_zn_handle())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		ZoomSTRING zn_handle;
		zn_handle = s2zs(proto_param.zn_handle());
		ZNZoomVideoSDKShareOption zn_shareOption;
		if (proto_param.has_iswithdeviceaudio())
		{
			convertBool(proto_param.iswithdeviceaudio(), zn_shareOption.isWithDeviceAudio);
		}
		if (proto_param.has_isoptimizeforsharedvideo())
		{
			convertBool(proto_param.isoptimizeforsharedvideo(), zn_shareOption.isOptimizeForSharedVideo);
		}

		err = _g_native_wrap.GetShareHelperWrap().StartShareView(zn_handle, zn_shareOption);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeShareHelperWrap::StartShareScreen(const v8::FunctionCallbackInfo<v8::Value>& args) {

	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::StartShareScreenParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::StartShareScreenParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_zn_monitorid())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		ZoomSTRING zn_monitorID;
		zn_monitorID = s2zs(proto_param.zn_monitorid());
		ZNZoomVideoSDKShareOption zn_shareOption;
		if (proto_param.has_iswithdeviceaudio())
		{
			convertBool(proto_param.iswithdeviceaudio(), zn_shareOption.isWithDeviceAudio);
		}
		if (proto_param.has_isoptimizeforsharedvideo())
		{
			convertBool(proto_param.isoptimizeforsharedvideo(), zn_shareOption.isOptimizeForSharedVideo);
		}

		err = _g_native_wrap.GetShareHelperWrap().StartShareScreen(zn_monitorID, zn_shareOption);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeShareHelperWrap::StartShareComputerAudio(const v8::FunctionCallbackInfo<v8::Value>& args) {

	v8::Isolate* isolate = args.GetIsolate();

	ZNZoomVideoSDKErrors err = _g_native_wrap.GetShareHelperWrap().StartShareComputerAudio();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeShareHelperWrap::StopShare(const v8::FunctionCallbackInfo<v8::Value>& args) {

	v8::Isolate* isolate = args.GetIsolate();

	ZNZoomVideoSDKErrors err = _g_native_wrap.GetShareHelperWrap().StopShare();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeShareHelperWrap::IsSharingOut(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bIs = _g_native_wrap.GetShareHelperWrap().IsSharingOut();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bIs);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeShareHelperWrap::IsScreenSharingOut(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bIs = _g_native_wrap.GetShareHelperWrap().IsScreenSharingOut();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bIs);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeShareHelperWrap::IsOtherSharing(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bIs = _g_native_wrap.GetShareHelperWrap().IsOtherSharing();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bIs);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeShareHelperWrap::LockShare(const v8::FunctionCallbackInfo<v8::Value>& args) {

	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::LockShareParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::LockShareParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_zn_block())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		bool zn_bLock;
		convertBool(proto_param.zn_block(), zn_bLock);

		err = _g_native_wrap.GetShareHelperWrap().LockShare(zn_bLock);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeShareHelperWrap::IsShareLocked(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bIs = _g_native_wrap.GetShareHelperWrap().IsShareLocked();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bIs);
	args.GetReturnValue().Set(bret);
}

void ZoomVideoNodeShareHelperWrap::GetMonitorsList(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	ZNList<ZoomSTRING> zn_sharemonitor_lst;
	zn_sharemonitor_lst = _g_native_wrap.GetShareInfoHelperWrap().GetMonitorsList();

	v8::Local<v8::Array> nodes = v8::Array::New(isolate);
	for (unsigned int i = 0; i < zn_sharemonitor_lst.size(); ++i)
	{
		v8::HandleScope scope(isolate);
		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(context, v8::String::NewFromUtf8(isolate, "shareMonitorID", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_sharemonitor_lst[i]).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		nodes->Set(context, i, node);
	}
	args.GetReturnValue().Set(nodes);
}
void ZoomVideoNodeShareHelperWrap::EnableShareDeviceAudio(const v8::FunctionCallbackInfo<v8::Value>& args) {

	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::EnableShareDeviceAudioParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::EnableShareDeviceAudioParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_enable())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		bool bEnable;
		convertBool(proto_param.enable(), bEnable);

		err = _g_native_wrap.GetShareHelperWrap().EnableShareDeviceAudio(bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeShareHelperWrap::IsShareDeviceAudioEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bIs = _g_native_wrap.GetShareHelperWrap().IsShareDeviceAudioEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bIs);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeShareHelperWrap::EnableOptimizeForSharedVideo(const v8::FunctionCallbackInfo<v8::Value>& args) {

	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::EnableOptimizeForSharedVideoParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::EnableOptimizeForSharedVideoParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_enable())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		bool bEnable;
		convertBool(proto_param.enable(), bEnable);

		err = _g_native_wrap.GetShareHelperWrap().EnableOptimizeForSharedVideo(bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeShareHelperWrap::IsOptimizeForSharedVideoEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bIs = _g_native_wrap.GetShareHelperWrap().IsOptimizeForSharedVideoEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bIs);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeShareHelperWrap::StartShare2ndCamera(const v8::FunctionCallbackInfo<v8::Value>& args) {

	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::StartShare2ndCameraParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::StartShare2ndCameraParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_zn_cameraid())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		ZoomSTRING zn_cameraID;
		zn_cameraID = s2zs(proto_param.zn_cameraid());

		err = _g_native_wrap.GetShareHelperWrap().StartShare2ndCamera(zn_cameraID);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}