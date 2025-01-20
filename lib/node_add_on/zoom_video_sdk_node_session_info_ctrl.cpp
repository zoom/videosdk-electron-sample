#include "zoom_video_sdk_node_session_info_ctrl.h"


ZoomVideoNodeSessionInfoCtrlWrap::ZoomVideoNodeSessionInfoCtrlWrap()
{
	
}

ZoomVideoNodeSessionInfoCtrlWrap::~ZoomVideoNodeSessionInfoCtrlWrap()
{
	
}
void ZoomVideoNodeSessionInfoCtrlWrap::GetSessionName(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING zn_sessionName = _g_native_wrap.GetSessionInfoWrap().GetSessionName();
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(zn_sessionName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeSessionInfoCtrlWrap::GetSessionPassword(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING zn_sessionPwd = _g_native_wrap.GetSessionInfoWrap().GetSessionPassword();
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(zn_sessionPwd).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeSessionInfoCtrlWrap::GetSessionID(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING zn_sessionID = _g_native_wrap.GetSessionInfoWrap().GetSessionID();
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(zn_sessionID).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeSessionInfoCtrlWrap::GetSessionHostName(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING zn_sessionHostName = _g_native_wrap.GetSessionInfoWrap().GetSessionHostName();
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(zn_sessionHostName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
	args.GetReturnValue().Set(bret);
}

void ZoomVideoNodeSessionInfoCtrlWrap::GetSessionHost(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	
	v8::Isolate* isolate = args.GetIsolate();

	com::electron::zoomvideo::sdk::proto::VideoSDKUser _SessionHost;
	_g_native_wrap.GetSessionInfoWrap().GetSessionHost(_SessionHost);
	size_t _size = _SessionHost.ByteSize();
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
	_SessionHost.SerializeToArray(char_temp_param, _size);
	v8::Local<v8::Uint8Array> uint8_array_buf = v8::Uint8Array::New(array_buf, 0, _size);
	
	args.GetReturnValue().Set(uint8_array_buf);
}
void ZoomVideoNodeSessionInfoCtrlWrap::GetRemoteUsers(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	
	v8::Isolate* isolate = args.GetIsolate();

	com::electron::zoomvideo::sdk::proto::UserList _RemoteUsers;
	_g_native_wrap.GetSessionInfoWrap().GetRemoteUsers(_RemoteUsers);
	size_t _size = _RemoteUsers.ByteSize();
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
	_RemoteUsers.SerializeToArray(char_temp_param, _size);
	v8::Local<v8::Uint8Array> uint8_array_buf = v8::Uint8Array::New(array_buf, 0, _size);
	
	args.GetReturnValue().Set(uint8_array_buf);
}
void ZoomVideoNodeSessionInfoCtrlWrap::GetMyself(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	
	v8::Isolate* isolate = args.GetIsolate();
	
	com::electron::zoomvideo::sdk::proto::VideoSDKUser _Myself;
	_g_native_wrap.GetSessionInfoWrap().GetMyself(_Myself);
	size_t _size = _Myself.ByteSize();
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
	_Myself.SerializeToArray(char_temp_param, _size);
	v8::Local<v8::Uint8Array> uint8_array_buf = v8::Uint8Array::New(array_buf, 0, _size);
	
	args.GetReturnValue().Set(uint8_array_buf);
}

void ZoomVideoNodeSessionInfoCtrlWrap::GetSessionAudioStatisticInfo(const v8::FunctionCallbackInfo<v8::Value>& args)
{

	v8::Isolate* isolate = args.GetIsolate();

	com::electron::zoomvideo::sdk::proto::VideoSDKSessionAudioStatisticInfoList _infoList;
	_g_native_wrap.GetSessionInfoWrap().GetSessionAudioStatisticInfo(_infoList);
	size_t _size = _infoList.ByteSize();
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
	_infoList.SerializeToArray(char_temp_param, _size);
	v8::Local<v8::Uint8Array> uint8_array_buf = v8::Uint8Array::New(array_buf, 0, _size);

	args.GetReturnValue().Set(uint8_array_buf);
}
void ZoomVideoNodeSessionInfoCtrlWrap::GetSessionVideoStatisticInfo(const v8::FunctionCallbackInfo<v8::Value>& args)
{

	v8::Isolate* isolate = args.GetIsolate();

	com::electron::zoomvideo::sdk::proto::VideoSDKSessionASVStatisticInfoList _infoList;
	_g_native_wrap.GetSessionInfoWrap().GetSessionVideoStatisticInfo(_infoList);
	size_t _size = _infoList.ByteSize();
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
	_infoList.SerializeToArray(char_temp_param, _size);
	v8::Local<v8::Uint8Array> uint8_array_buf = v8::Uint8Array::New(array_buf, 0, _size);

	args.GetReturnValue().Set(uint8_array_buf);
}
void ZoomVideoNodeSessionInfoCtrlWrap::GetSessionShareStatisticInfo(const v8::FunctionCallbackInfo<v8::Value>& args)
{

	v8::Isolate* isolate = args.GetIsolate();

	com::electron::zoomvideo::sdk::proto::VideoSDKSessionASVStatisticInfoList _infoList;
	_g_native_wrap.GetSessionInfoWrap().GetSessionShareStatisticInfo(_infoList);
	size_t _size = _infoList.ByteSize();
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
	_infoList.SerializeToArray(char_temp_param, _size);
	v8::Local<v8::Uint8Array> uint8_array_buf = v8::Uint8Array::New(array_buf, 0, _size);

	args.GetReturnValue().Set(uint8_array_buf);
}