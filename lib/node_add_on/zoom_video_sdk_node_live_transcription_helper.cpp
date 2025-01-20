#include "zoom_video_sdk_node_live_transcription_helper.h"
#include "node_core/zoom_video_sdk_events_wrap_class.h"


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ZoomVideoNodeLiveTranscriptionHelperWrap::ZoomVideoNodeLiveTranscriptionHelperWrap()
{

}

ZoomVideoNodeLiveTranscriptionHelperWrap::~ZoomVideoNodeLiveTranscriptionHelperWrap()
{

}
void ZoomVideoNodeLiveTranscriptionHelperWrap::CanStartLiveTranscription(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool bCan = false;
	do
	{
		bCan = _g_native_wrap.GetLiveTranscriptionHelperWrap().CanStartLiveTranscription();
	} while (false);
	
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, bCan);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeLiveTranscriptionHelperWrap::GetLiveTranscriptionStatus(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	ZNZoomVideoSDKLiveTranscriptionStatus zn_status;
	if (err == ZNZoomVideoSDKErrors_Success)
	{
		err = _g_native_wrap.GetLiveTranscriptionHelperWrap().GetLiveTranscriptionStatus(zn_status);
	}
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "liveTranscriptionStatus", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_status));

	args.GetReturnValue().Set(node);
}
void ZoomVideoNodeLiveTranscriptionHelperWrap::StartLiveTranscription(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		err = _g_native_wrap.GetLiveTranscriptionHelperWrap().StartLiveTranscription();
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeLiveTranscriptionHelperWrap::StopLiveTranscription(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		err = _g_native_wrap.GetLiveTranscriptionHelperWrap().StopLiveTranscription();
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomVideoNodeLiveTranscriptionHelperWrap::GetAvailableSpokenLanguages(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	v8::Isolate* isolate = args.GetIsolate();

	com::electron::zoomvideo::sdk::proto::LTTLanguagesList _spokenLanguagesLst;
	if (err == ZNZoomVideoSDKErrors_Success)
	{
		_g_native_wrap.GetLiveTranscriptionHelperWrap().GetAvailableSpokenLanguages(_spokenLanguagesLst);
	}
	
	size_t _size = _spokenLanguagesLst.ByteSize();
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
	_spokenLanguagesLst.SerializeToArray(char_temp_param, _size);
	v8::Local<v8::Uint8Array> uint8_array_buf = v8::Uint8Array::New(array_buf, 0, _size);

	args.GetReturnValue().Set(uint8_array_buf);
}
void ZoomVideoNodeLiveTranscriptionHelperWrap::GetAvailableTranslationLanguages(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	v8::Isolate* isolate = args.GetIsolate();

	com::electron::zoomvideo::sdk::proto::LTTLanguagesList _translationLanguagesLst;
	if (err == ZNZoomVideoSDKErrors_Success)
	{
		_g_native_wrap.GetLiveTranscriptionHelperWrap().GetAvailableTranslationLanguages(_translationLanguagesLst);
	}
	
	size_t _size = _translationLanguagesLst.ByteSize();
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
	_translationLanguagesLst.SerializeToArray(char_temp_param, _size);
	v8::Local<v8::Uint8Array> uint8_array_buf = v8::Uint8Array::New(array_buf, 0, _size);

	args.GetReturnValue().Set(uint8_array_buf);
}
void ZoomVideoNodeLiveTranscriptionHelperWrap::SetSpokenLanguage(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::SetSpokenLanguageParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::SetSpokenLanguageParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		int zn_languageID = 0;
		if (proto_param.has_languageid())
		{
			zn_languageID = (ZNVideoRotation)proto_param.languageid();
		}

		err = _g_native_wrap.GetLiveTranscriptionHelperWrap().SetSpokenLanguage(zn_languageID);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeLiveTranscriptionHelperWrap::SetTranslationLanguage(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::SetTranslationLanguageParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::SetTranslationLanguageParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		int zn_languageID = 0;
		if (proto_param.has_languageid())
		{
			zn_languageID = (ZNVideoRotation)proto_param.languageid();
		}

		err = _g_native_wrap.GetLiveTranscriptionHelperWrap().SetTranslationLanguage(zn_languageID);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeLiveTranscriptionHelperWrap::GetSpokenLanguage(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();

	ZNLiveTranscriptionLanguage spokenLanguage;
	if (err == ZNZoomVideoSDKErrors_Success)
	{
		err = _g_native_wrap.GetLiveTranscriptionHelperWrap().GetSpokenLanguage(spokenLanguage);
	}
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "spokenLanguageID", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)spokenLanguage.lttLanguageID));
	node->Set(context, v8::String::NewFromUtf8(isolate, "spokenLanguageName", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(spokenLanguage.lttLanguageName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());

	args.GetReturnValue().Set(node);
}
void ZoomVideoNodeLiveTranscriptionHelperWrap::GetTranslationLanguage(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();

	ZNLiveTranscriptionLanguage translationLanguage;
	if (err == ZNZoomVideoSDKErrors_Success)
	{
		err = _g_native_wrap.GetLiveTranscriptionHelperWrap().GetTranslationLanguage(translationLanguage);
	}
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "translationLanguageID", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)translationLanguage.lttLanguageID));
	node->Set(context, v8::String::NewFromUtf8(isolate, "translationLanguageName", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(translationLanguage.lttLanguageName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());

	args.GetReturnValue().Set(node);
}





