#include "zoom_video_sdk_node_phone_helper.h"


ZoomVideoNodePhoneHelperWrap::ZoomVideoNodePhoneHelperWrap()
{
	
}

ZoomVideoNodePhoneHelperWrap::~ZoomVideoNodePhoneHelperWrap()
{
	
}
void ZoomVideoNodePhoneHelperWrap::IsSupportPhoneFeature(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bIs = _g_native_wrap.GetPhoneHelperWrap().IsSupportPhoneFeature();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bIs);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodePhoneHelperWrap::GetSupportCountryInfo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();

	com::electron::zoomvideo::sdk::proto::GetPhoneSupportCountryList _CountryList;
	_g_native_wrap.GetPhoneHelperWrap().GetSupportCountryInfo(_CountryList);
	size_t _size = _CountryList.ByteSize();
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
	_CountryList.SerializeToArray(char_temp_param, _size);
	v8::Local<v8::Uint8Array> uint8_array_buf = v8::Uint8Array::New(array_buf, 0, _size);

	args.GetReturnValue().Set(uint8_array_buf);
}
void ZoomVideoNodePhoneHelperWrap::InviteByPhone(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::InviteByPhoneParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::InviteByPhoneParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_countrycode() ||
			!proto_param.has_phonenumber() ||
			!proto_param.has_name()
			)
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		ZoomSTRING zn_countryCode;
		zn_countryCode = s2zs(proto_param.countrycode());
		ZoomSTRING zn_phoneNumber;
		zn_phoneNumber = s2zs(proto_param.phonenumber());
		ZoomSTRING zn_name;
		zn_name = s2zs(proto_param.name());

		err = _g_native_wrap.GetPhoneHelperWrap().InviteByPhone(zn_countryCode, zn_phoneNumber, zn_name);
	} while (false);
	

	v8::Local<v8::Integer> ret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(ret);
}
void ZoomVideoNodePhoneHelperWrap::InvitePhoneUser(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::InvitePhoneUserParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::InvitePhoneUserParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_countrycode() ||
			!proto_param.has_phonenumber() ||
			!proto_param.has_name()
			)
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		ZNInvitePhoneUserInfo zn_invitePhoneUserInfo;
		zn_invitePhoneUserInfo.countryCode = s2zs(proto_param.countrycode());
		zn_invitePhoneUserInfo.phoneNumber = s2zs(proto_param.phonenumber());
		zn_invitePhoneUserInfo.name = s2zs(proto_param.name());
		if (proto_param.has_bpressone())
		{
			convertBool(proto_param.bpressone(), zn_invitePhoneUserInfo.bPressOne);
		}
		if (proto_param.has_bgreeting())
		{
			convertBool(proto_param.bgreeting(), zn_invitePhoneUserInfo.bGreeting);
		}

		err = _g_native_wrap.GetPhoneHelperWrap().InvitePhoneUser(zn_invitePhoneUserInfo);
	} while (false);
	

	v8::Local<v8::Integer> ret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(ret);
}
void ZoomVideoNodePhoneHelperWrap::CancelInviteByPhone(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	err = _g_native_wrap.GetPhoneHelperWrap().CancelInviteByPhone();
	v8::Local<v8::Integer> ret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(ret);
}
void ZoomVideoNodePhoneHelperWrap::GetInviteByPhoneStatus(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNPhoneStatus zn_status = ZNPhoneStatus_None;
	zn_status = _g_native_wrap.GetPhoneHelperWrap().GetInviteByPhoneStatus();
	v8::Local<v8::Integer> ret = v8::Integer::New(isolate, (int32_t)zn_status);
	args.GetReturnValue().Set(ret);
}