#include "zoom_video_sdk_node_audio_setting.h"


ZoomVideoNodeAudioSettingWrap::ZoomVideoNodeAudioSettingWrap()
{
	
}

ZoomVideoNodeAudioSettingWrap::~ZoomVideoNodeAudioSettingWrap()
{
	
}

void ZoomVideoNodeAudioSettingWrap::GetSuppressBackgroundNoiseLevel(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	ZNZoomVideoSDKSuppressBackgroundNoiseLevel zn_level = ZNZoomVideoSDKSuppressBackgroundNoiseLevel_Auto;
	ZNZoomVideoSDKErrors err = _g_native_wrap.GetAudioSettingWrap().GetSuppressBackgroundNoiseLevel(zn_level);
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "level", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_level));
	args.GetReturnValue().Set(node);
}
void ZoomVideoNodeAudioSettingWrap::SetSuppressBackgroundNoiseLevel(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::SetSuppressBackgroundNoiseLevelParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::SetSuppressBackgroundNoiseLevelParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_level())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		int temp = (int)proto_param.level();
		ZNZoomVideoSDKSuppressBackgroundNoiseLevel zn_level = (ZNZoomVideoSDKSuppressBackgroundNoiseLevel)temp;

		err = _g_native_wrap.GetAudioSettingWrap().SetSuppressBackgroundNoiseLevel(zn_level);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeAudioSettingWrap::EnableMicOriginalInput(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::EnableMicOriginalInputParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::EnableMicOriginalInputParams >(args, proto_param))
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

		err = _g_native_wrap.GetAudioSettingWrap().EnableMicOriginalInput(bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeAudioSettingWrap::IsMicOriginalInputEnable(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	bool bEnable = false;
	ZNZoomVideoSDKErrors err = _g_native_wrap.GetAudioSettingWrap().IsMicOriginalInputEnable(bEnable);
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "bEnable", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, bEnable));
	args.GetReturnValue().Set(node);
}
void ZoomVideoNodeAudioSettingWrap::EnableHighFidelityMusicMode(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::EnableHighFidelityMusicModeParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::EnableHighFidelityMusicModeParams >(args, proto_param))
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

		err = _g_native_wrap.GetAudioSettingWrap().EnableHighFidelityMusicMode(bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeAudioSettingWrap::IsHighFidelityMusicModeEnable(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	bool bEnable = false;
	ZNZoomVideoSDKErrors err = _g_native_wrap.GetAudioSettingWrap().IsHighFidelityMusicModeEnable(bEnable);
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "bEnable", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, bEnable));
	args.GetReturnValue().Set(node);
}
void ZoomVideoNodeAudioSettingWrap::EnableEchoCancellation(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::EnableEchoCancellationParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::EnableEchoCancellationParams >(args, proto_param))
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

		err = _g_native_wrap.GetAudioSettingWrap().EnableEchoCancellation(bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeAudioSettingWrap::IsEchoCancellationEnable(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	bool bEnable = false;
	ZNZoomVideoSDKErrors err = _g_native_wrap.GetAudioSettingWrap().IsEchoCancellationEnable(bEnable);
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "bEnable", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, bEnable));
	args.GetReturnValue().Set(node);
}
void ZoomVideoNodeAudioSettingWrap::EnableStereoAudio(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::EnableStereoAudioParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::EnableStereoAudioParams >(args, proto_param))
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

		err = _g_native_wrap.GetAudioSettingWrap().EnableStereoAudio(bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeAudioSettingWrap::IsStereoAudioEnable(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	bool bEnable = false;
	ZNZoomVideoSDKErrors err = _g_native_wrap.GetAudioSettingWrap().IsStereoAudioEnable(bEnable);
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "bEnable", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, bEnable));
	args.GetReturnValue().Set(node);
}
void ZoomVideoNodeAudioSettingWrap::GetEchoCancellationLevel(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	ZNZoomVideoSDKEchoCancellationLevel zn_level = ZNZoomVideoSDKEchoCancellationLevel_Default;
	ZNZoomVideoSDKErrors err = _g_native_wrap.GetAudioSettingWrap().GetEchoCancellationLevel(zn_level);
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "level", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_level));
	args.GetReturnValue().Set(node);
}
void ZoomVideoNodeAudioSettingWrap::SetEchoCancellationLevel(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::SetEchoCancellationLevelParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::SetEchoCancellationLevelParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_level())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		int temp = (int)proto_param.level();
		ZNZoomVideoSDKEchoCancellationLevel zn_level = (ZNZoomVideoSDKEchoCancellationLevel)temp;

		err = _g_native_wrap.GetAudioSettingWrap().SetEchoCancellationLevel(zn_level);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ZoomVideoNodeTestAudioDeviceWrap::ZoomVideoNodeTestAudioDeviceWrap()
{

}

ZoomVideoNodeTestAudioDeviceWrap::~ZoomVideoNodeTestAudioDeviceWrap()
{

}
void ZoomVideoNodeTestAudioDeviceWrap::StartMicTestRecording(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::StartMicTestRecordingParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::StartMicTestRecordingParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_deviceid())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		ZoomSTRING zn_deviceid;
		zn_deviceid = s2zs(proto_param.deviceid());

		err = _g_native_wrap.GetTestAudioDeviceWrap().StartMicTestRecording(zn_deviceid);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeTestAudioDeviceWrap::StopMicTestRecording(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = _g_native_wrap.GetTestAudioDeviceWrap().StopMicTestRecording();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeTestAudioDeviceWrap::PlayMicTestRecording(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = _g_native_wrap.GetTestAudioDeviceWrap().PlayMicTestRecording();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeTestAudioDeviceWrap::StartSpeakerTest(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::StartSpeakerTestParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::StartSpeakerTestParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_deviceid())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		ZoomSTRING zn_deviceid;
		zn_deviceid = s2zs(proto_param.deviceid());

		err = _g_native_wrap.GetTestAudioDeviceWrap().StartSpeakerTest(zn_deviceid);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeTestAudioDeviceWrap::StopSpeakerTest(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = _g_native_wrap.GetTestAudioDeviceWrap().StopSpeakerTest();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeTestAudioDeviceWrap::SetTimerInterval(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::SetTimerIntervalParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::SetTimerIntervalParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_timerinterval())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		unsigned int temp = (unsigned int)proto_param.timerinterval();

		err = _g_native_wrap.GetTestAudioDeviceWrap().SetTimerInterval(temp);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}