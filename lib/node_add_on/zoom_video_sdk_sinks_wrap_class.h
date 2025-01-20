#ifndef _zoom_video_sdk_sinks_wrap_class_h_
#define _zoom_video_sdk_sinks_wrap_class_h_
#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_singleton_wrap_class.h"
#include "zoom_video_sdk_native_sdk_wrap_core_def.h"


class ZNativeZoomVideoSDKSinksWrap
{
public:

	virtual void onNodeAddonCallbacks(com::electron::zoomvideo::sdk::proto::CallbackBody& _callbackbody)
	{
		if (ZoomNodeVideoSinkHelper::GetInst().onNodeAddonCallbacks.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		size_t _size = _callbackbody.ByteSize();
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
		_callbackbody.SerializeToArray(char_temp_param, _size);
		v8::Local<v8::Uint8Array> uint8_array_buf = v8::Uint8Array::New(array_buf, 0, _size);

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { uint8_array_buf };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeVideoSinkHelper::GetInst().onNodeAddonCallbacks);

		fn->Call(context, global, argc, argv);
	}
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZoomVideoNodeSinkWrapMgr
{
public:
	
	ZNativeZoomVideoSDKSinksWrap m_ZoomVideoSDKSink;

	static ZoomVideoNodeSinkWrapMgr& GetInst()
	{
		static ZoomVideoNodeSinkWrapMgr inst;
		return inst;
	}
	~ZoomVideoNodeSinkWrapMgr() {}
private:
	ZoomVideoNodeSinkWrapMgr() {}
};
////////////////////////////////////////////////////////////////////////////////



#endif 
