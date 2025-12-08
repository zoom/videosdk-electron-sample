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
void ZoomVideoNodeShareHelperWrap::PauseShare(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = _g_native_wrap.GetShareHelperWrap().PauseShare();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeShareHelperWrap::ResumeShare(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = _g_native_wrap.GetShareHelperWrap().ResumeShare();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
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
void ZoomVideoNodeShareHelperWrap::GetAppList(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	v8::Local<v8::Array> nodes = v8::Array::New(isolate);
#if (!defined __linux)
	ZNList<AppInfo> appList = _g_native_wrap.GetShareInfoHelperWrap().GetAppList();
	for (unsigned int i = 0; i < appList.size(); ++i)
	{
		v8::HandleScope scope(isolate);
		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(context, v8::String::NewFromUtf8(isolate, "handle", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, appList[i].handle));
		node->Set(context, v8::String::NewFromUtf8(isolate, "processId", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, appList[i].processId));
		node->Set(context, v8::String::NewFromUtf8(isolate, "title", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(appList[i].title).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "appName", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(appList[i].appName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		nodes->Set(context, i, node);
	}
#endif
	// For linux platform, return empty array
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
void ZoomVideoNodeShareHelperWrap::StartShareWithPreprocessing(const v8::FunctionCallbackInfo<v8::Value>& args) 
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		com::electron::zoomvideo::sdk::proto::StartShareWithPreprocessingParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::StartShareWithPreprocessingParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		ZNZoomVideoSDKSharePreprocessType zn_type = (ZNZoomVideoSDKSharePreprocessType)proto_param.type();
		ZoomSTRING zn_handle;
		if (proto_param.has_handle())
		{
			zn_handle = s2zs(proto_param.handle());
		}

		ZoomSTRING zn_monitorid;
		if (proto_param.has_monitorid())
		{
			zn_monitorid = s2zs(proto_param.monitorid());
		}

		uint32_t processID = 0;
		if (proto_param.has_processid())
		{
			processID = proto_param.processid();
		}
		
		ZSharePreprocessorHelperWrap& shareSendHelper = _g_native_wrap.GetSharePreprocessorHelperWrap();
		err = shareSendHelper.StartShareWithPreprocessing(zn_type, zn_handle, zn_monitorid, processID, dynamic_cast<ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKSharePreprocessor*>(&shareSendHelper));
	} while (false);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeShareHelperWrap::SendPreprocessedData(const v8::FunctionCallbackInfo<v8::Value>& args) 
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		com::electron::zoomvideo::sdk::proto::SendPreprocessedDataParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::SendPreprocessedDataParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_buffer() || !proto_param.has_datahandle())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		char* buffer = const_cast<char*>(proto_param.buffer().data());
		std::string datahandle_str = proto_param.datahandle();
		
		err = _g_native_wrap.GetSharePreprocessorHelperWrap().SendPreprocessedData(buffer, datahandle_str);
	} while (false);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeShareHelperWrap::CreateAnnotationHelper(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();

	ZNZoomVideoSDKErrors err = _g_native_wrap.GetShareHelperWrap().CreateAnnotationHelper();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeShareHelperWrap::DestroyAnnotationHelper(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();

	ZNZoomVideoSDKErrors err = _g_native_wrap.GetShareHelperWrap().DestroyAnnotationHelper();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeShareHelperWrap::SetAnnotationVanishingToolTime(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::SetAnnotationVanishingToolTimeParams proto_params;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::SetAnnotationVanishingToolTimeParams >(args, proto_params))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		if (!proto_params.has_displaytime() || !proto_params.has_vanishingtime())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		unsigned int _displayTime = proto_params.displaytime();
		unsigned int _vanishingTime = proto_params.vanishingtime();
		err = _g_native_wrap.GetShareHelperWrap().SetAnnotationVanishingToolTime(_displayTime, _vanishingTime);
	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeShareHelperWrap::GetAnnotationVanishingToolTime(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	unsigned int displayTime = 0; 
	unsigned int vanishingTime = 0;
	ZNZoomVideoSDKErrors err = _g_native_wrap.GetShareHelperWrap().GetAnnotationVanishingToolTime(displayTime, vanishingTime);
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "displayTime", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)displayTime));
	node->Set(context, v8::String::NewFromUtf8(isolate, "vanishingTime", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)vanishingTime));
	args.GetReturnValue().Set(node);
}
void ZoomVideoNodeShareHelperWrap::StartShareApplication(const v8::FunctionCallbackInfo<v8::Value>& args) {

	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::StartShareApplicationParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::StartShareApplicationParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_processid())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		uint32_t _processID = proto_param.processid();
		ZNZoomVideoSDKShareOption zn_shareOption;
		if (proto_param.has_iswithdeviceaudio())
		{
			convertBool(proto_param.iswithdeviceaudio(), zn_shareOption.isWithDeviceAudio);
		}
		if (proto_param.has_isoptimizeforsharedvideo())
		{
			convertBool(proto_param.isoptimizeforsharedvideo(), zn_shareOption.isOptimizeForSharedVideo);
		}

		err = _g_native_wrap.GetShareHelperWrap().StartShareApplication(_processID, zn_shareOption);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}