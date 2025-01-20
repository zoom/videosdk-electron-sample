#ifndef _zoom_sdk_napi_util_load_helper_h_
#define _zoom_sdk_napi_util_load_helper_h_
#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_native_sdk_wrap_core_def.h"

typedef void (*fnFreeDataBufferNotification)(void* hint);
typedef void(*fnCallbackVideoFormatDataToJS)(uint64_t recvHandle, const std::string& video_data_format,
	char* video_data_buf, int len, v8::Local<v8::Function>& executor, fnFreeDataBufferNotification notification, void* hint);
typedef void(*fnCallbackMixedAudioFormatDataToJS)(const std::string& audio_data_format,
	char* audio_data_buf, int len, v8::Local<v8::Function>& executor, fnFreeDataBufferNotification notification, void* hint);
typedef void(*fnCallbackOnewayAudioFormatDataToJS)(const std::string& nodeid, const std::string& audio_data_format,
	char* audio_data_buf, int len, v8::Local<v8::Function>& executor, fnFreeDataBufferNotification notification, void* hint);
typedef void(*fnGetRawBufferPtr)(v8::Local<v8::Uint8Array>& data_buffer, void** pp_raw_ptr, size_t& p_size);
typedef void(*fnGetRawArrayBufferPtr)(v8::Local<v8::ArrayBuffer>& data_buffer, void** pp_raw_ptr, size_t& p_size);

class ZoomNodeAPIUtilHelper
{
public:
	static ZoomNodeAPIUtilHelper& GetInst()
	{
		static ZoomNodeAPIUtilHelper inst;
		return inst;
	}
	~ZoomNodeAPIUtilHelper() 
	{
		m_fnCallbackVideoFormatDataToJS = NULL;
		m_fnCallbackMixedAudioFormatDataToJS = NULL;
		m_fnCallbackOnewayAudioFormatDataToJS = NULL;
		m_fnGetRawBufferPtr = NULL;
		m_fnGetRawArrayBufferPtr = NULL;
		m_bInit = false;
	}
	bool ExportNAPIUtilFunc();
	void Reset();
	bool m_bInit;
	fnCallbackVideoFormatDataToJS m_fnCallbackVideoFormatDataToJS;
	fnCallbackMixedAudioFormatDataToJS m_fnCallbackMixedAudioFormatDataToJS;
	fnCallbackOnewayAudioFormatDataToJS m_fnCallbackOnewayAudioFormatDataToJS;
	fnGetRawBufferPtr m_fnGetRawBufferPtr;
	fnGetRawArrayBufferPtr m_fnGetRawArrayBufferPtr;
	
private:
	ZoomNodeAPIUtilHelper() 
	{
		m_fnCallbackVideoFormatDataToJS = NULL;
		m_fnCallbackMixedAudioFormatDataToJS = NULL;
		m_fnCallbackOnewayAudioFormatDataToJS = NULL;
		m_fnGetRawBufferPtr = NULL;
		m_fnGetRawArrayBufferPtr = NULL;
		m_bInit = false;
	}
};

///////////////////////////////////////////////////////////////////////////////


#endif
