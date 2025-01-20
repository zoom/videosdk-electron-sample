#include "zoom_video_sdk_node_audio_helper.h"


ZoomVideoNodeAudioHelperWrap::ZoomVideoNodeAudioHelperWrap()
{
	
}

ZoomVideoNodeAudioHelperWrap::~ZoomVideoNodeAudioHelperWrap()
{
	
}
void ZoomVideoNodeAudioHelperWrap::StartAudio(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();

	ZNZoomVideoSDKErrors err = _g_native_wrap.GetAudioHelperWrap().StartAudio();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeAudioHelperWrap::StopAudio(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();

	ZNZoomVideoSDKErrors err = _g_native_wrap.GetAudioHelperWrap().StopAudio();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeAudioHelperWrap::MuteAudio(const v8::FunctionCallbackInfo<v8::Value>& args) {

	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		com::electron::zoomvideo::sdk::proto::MuteAudioParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::MuteAudioParams >(args, proto_param))
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
		if (zn_pUser)
		{
			err = _g_native_wrap.GetAudioHelperWrap().MuteAudio(zn_pUser);
		}
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeAudioHelperWrap::UnMuteAudio(const v8::FunctionCallbackInfo<v8::Value>& args) {

	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		com::electron::zoomvideo::sdk::proto::UnMuteAudioParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::UnMuteAudioParams >(args, proto_param))
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
		if (zn_pUser)
		{
			err = _g_native_wrap.GetAudioHelperWrap().UnMuteAudio(zn_pUser);
		}
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomVideoNodeAudioHelperWrap::GetSpeakerList(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	
	com::electron::zoomvideo::sdk::proto::GetSpeakerList _SpeakerList;
	_g_native_wrap.GetAudioHelperWrap().GetSpeakerList(_SpeakerList);
	size_t _size = _SpeakerList.ByteSize();
	auto array_buf = v8::ArrayBuffer::New(isolate, _size);
	char* char_temp_param = nullptr;
	size_t sz_temp_param = 0;
	fnGetRawArrayBufferPtr pGetRawArrayBufferPtr = NULL;
	pGetRawArrayBufferPtr = ZoomNodeAPIUtilHelper::GetInst().m_fnGetRawArrayBufferPtr;
	if (!pGetRawArrayBufferPtr)
	{
		return;
	}
	pGetRawArrayBufferPtr(array_buf, (void**)(&char_temp_param), sz_temp_param);
	_SpeakerList.SerializeToArray(char_temp_param, _size);
	v8::Local<v8::Uint8Array> uint8_array_buf = v8::Uint8Array::New(array_buf, 0, _size);

	args.GetReturnValue().Set(uint8_array_buf);
}
void ZoomVideoNodeAudioHelperWrap::GetMicList(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();

	com::electron::zoomvideo::sdk::proto::GetMicList _MicList;
	_g_native_wrap.GetAudioHelperWrap().GetMicList(_MicList);
	size_t _size = _MicList.ByteSize();
	auto array_buf = v8::ArrayBuffer::New(isolate, _size);
	char* char_temp_param = nullptr;
	size_t sz_temp_param = 0;
	fnGetRawArrayBufferPtr pGetRawArrayBufferPtr = NULL;
	pGetRawArrayBufferPtr = ZoomNodeAPIUtilHelper::GetInst().m_fnGetRawArrayBufferPtr;
	if (!pGetRawArrayBufferPtr)
	{
		return;
	}
	pGetRawArrayBufferPtr(array_buf, (void**)(&char_temp_param), sz_temp_param);
	_MicList.SerializeToArray(char_temp_param, _size);
	v8::Local<v8::Uint8Array> uint8_array_buf = v8::Uint8Array::New(array_buf, 0, _size);

	args.GetReturnValue().Set(uint8_array_buf);
}
void ZoomVideoNodeAudioHelperWrap::SelectSpeaker(const v8::FunctionCallbackInfo<v8::Value>& args) {

	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::SelectSpeakerParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::SelectSpeakerParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_zn_deviceid() ||
			!proto_param.has_zn_devicename()
			)
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		ZoomSTRING zn_deviceid;
		ZoomSTRING zn_devicename;
		zn_deviceid = s2zs(proto_param.zn_deviceid());
		zn_devicename = s2zs(proto_param.zn_devicename());

		err = _g_native_wrap.GetAudioHelperWrap().SelectSpeaker(zn_deviceid, zn_devicename);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeAudioHelperWrap::SelectMic(const v8::FunctionCallbackInfo<v8::Value>& args) {

	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::SelectMicParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::SelectMicParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_zn_deviceid() ||
			!proto_param.has_zn_devicename()
			)
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		ZoomSTRING zn_deviceid;
		ZoomSTRING zn_devicename;
		zn_deviceid = s2zs(proto_param.zn_deviceid());
		zn_devicename = s2zs(proto_param.zn_devicename());

		err = _g_native_wrap.GetAudioHelperWrap().SelectMic(zn_deviceid, zn_devicename);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeAudioHelperWrap::Subscribe(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();

	ZNZoomVideoSDKErrors err = _g_native_wrap.GetAudioHelperWrap().Subscribe();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeAudioHelperWrap::UnSubscribe(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();

	ZNZoomVideoSDKErrors err = _g_native_wrap.GetAudioHelperWrap().UnSubscribe();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}