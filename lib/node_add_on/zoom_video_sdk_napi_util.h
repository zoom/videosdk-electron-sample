#pragma once
#include <node.h>
#include <v8.h>
#include <string>

typedef void (*fnFreeDataBufferNotification)(void* hint);
extern "C" NODE_MODULE_EXPORT void CallbackVideoFormatDataToJS(uint64_t recvHandle, const std::string & video_data_format,
	char* video_data_buf, int len, v8::Local<v8::Function>& executor, fnFreeDataBufferNotification notification, void* hint);

extern "C" NODE_MODULE_EXPORT void CallbackMixedAudioFormatDataToJS(const std::string & audio_data_format,
	char* audio_data_buf, int len, v8::Local<v8::Function>& executor, fnFreeDataBufferNotification notification, void* hint);


extern "C" NODE_MODULE_EXPORT void CallbackOnewayAudioFormatDataToJS(const std::string & nodeid, const std::string & audio_data_format,
	char* audio_data_buf, int len, v8::Local<v8::Function>& executor, fnFreeDataBufferNotification notification, void* hint);

extern "C" NODE_MODULE_EXPORT void GetRawBufferPtr(v8::Local<v8::Uint8Array>& data_buffer, void** pp_raw_ptr, size_t& p_size);

extern "C" NODE_MODULE_EXPORT void GetRawArrayBufferPtr(v8::Local<v8::ArrayBuffer>&data_buffer, void** pp_raw_ptr, size_t & p_size);
