#include <assert.h>
#include <node_api.h>
#include "zoom_video_sdk_napi_util.h"

#define DECLARE_NAPI_METHOD(name, func)                                        \
  { name, 0, func, 0, 0, 0, napi_default, 0 }

napi_env g_napi_env = nullptr;

napi_ref  g_rawdata_callback = nullptr;
static napi_value ZoomNodeApiModule(napi_env env, napi_callback_info info) {
	napi_value rc;
	napi_create_string_utf8(env, "ZoomNAPIUtil", NAPI_AUTO_LENGTH, &rc);
	return (rc);
}

static napi_value Init(napi_env env, napi_value exports) {
	g_napi_env = env;
	napi_status status;
	napi_property_descriptor reg_desc = DECLARE_NAPI_METHOD("ZoomNodeApiModule", ZoomNodeApiModule);
	status = napi_define_properties(env, exports, 1, &reg_desc);
	assert(status == napi_ok);
	return exports;
}

#define NODE_GYP_MODULE_NAME_NAPI ZOOMSDK_NAPI_MODULE
NAPI_MODULE(NODE_GYP_MODULE_NAME_NAPI, Init)

struct FreeDataBufferInfo
{
    fnFreeDataBufferNotification fnCallback;
    void* hint;
};
void FreeExternalArrayBufferMemory(napi_env env, void* data, void* hint)
{
	if (hint)
    {
        FreeDataBufferInfo* info = (FreeDataBufferInfo*)hint;
        if (info->fnCallback)
            info->fnCallback(info->hint);
        delete info;
    }
}

extern "C" NODE_MODULE_EXPORT void CallbackVideoFormatDataToJS(uint64_t recvHandle, const std::string & video_data_format,
	char* video_data_buf, int len, v8::Local<v8::Function>& executor, fnFreeDataBufferNotification notification, void* hint)
{
	do 
	{
		if (nullptr == g_napi_env || nullptr == video_data_buf)
			break;

		napi_value napi_executor = reinterpret_cast<napi_value>(*executor);
		if (nullptr == napi_executor)
			break;
        
        napi_value napi_video_array_buffer;
#if 1
		napi_status status = napi_create_buffer_copy(g_napi_env, len, (void*)video_data_buf, nullptr, &napi_video_array_buffer);
		if (notification)
			notification(hint);
#else
		FreeDataBufferInfo* info = new FreeDataBufferInfo;
		info->fnCallback = notification;
		info->hint = hint;
		napi_status status = napi_create_external_buffer(g_napi_env, len, (void*)video_data_buf,
			FreeExternalArrayBufferMemory, info, &napi_video_array_buffer);
#endif
		if (napi_ok != status)
			break;

		napi_value napi_recv_handle;
		status = napi_create_bigint_uint64(g_napi_env, recvHandle, &napi_recv_handle);
		if (napi_ok != status)
			break;

		napi_value napi_video_foramt;
		status = napi_create_string_utf8(g_napi_env, video_data_format.c_str(), video_data_format.size(), &napi_video_foramt);
		if (napi_ok != status)
			break;

		napi_value global;
		status = napi_get_global(g_napi_env, &global);
		if (napi_ok != status)
			break;

		napi_value argv[3] = {napi_video_foramt, napi_recv_handle, napi_video_array_buffer };
		napi_value result;
		status = napi_call_function(g_napi_env, global, napi_executor, sizeof(argv) / sizeof(argv[0]), argv, &result);
	} while (false);
}

extern "C" NODE_MODULE_EXPORT void CallbackMixedAudioFormatDataToJS(const std::string & audio_data_format,
	char* audio_data_buf, int len, v8::Local<v8::Function>& executor, fnFreeDataBufferNotification notification, void* hint)
{
	do
	{
		if (nullptr == g_napi_env || nullptr == audio_data_buf)
			break;

		napi_value napi_executor = reinterpret_cast<napi_value>(*executor);
		if (nullptr == napi_executor)
			break;
		napi_value napi_audio_array_buffer;
#if 1
		napi_status status = napi_create_buffer_copy(g_napi_env, len, (void*)audio_data_buf, nullptr, &napi_audio_array_buffer);
		if (notification)
			notification(hint);
#else
        FreeDataBufferInfo* info = new FreeDataBufferInfo;
        info->fnCallback = notification;
        info->hint = hint;
		napi_status status = napi_create_external_buffer(g_napi_env, len, (void*)audio_data_buf,
			FreeExternalArrayBufferMemory, info, &napi_audio_array_buffer);
#endif
		if (napi_ok != status)
			break;

		napi_value napi_audio_foramt;
		status = napi_create_string_utf8(g_napi_env, audio_data_format.c_str(), audio_data_format.size(), &napi_audio_foramt);
		if (napi_ok != status)
			break;

		napi_value global;
		status = napi_get_global(g_napi_env, &global);
		if (napi_ok != status)
			break;

		napi_value argv[2] = { napi_audio_array_buffer, napi_audio_foramt};
		napi_value result;
		status = napi_call_function(g_napi_env, global, napi_executor, sizeof(argv) / sizeof(argv[0]), argv, &result);
	} while (false);
}


extern "C" NODE_MODULE_EXPORT void CallbackOnewayAudioFormatDataToJS(const std::string & nodeid, const std::string & audio_data_format,
	char* audio_data_buf, int len, v8::Local<v8::Function>& executor, fnFreeDataBufferNotification notification, void* hint)
{
	do
	{
		if (nullptr == g_napi_env || nullptr == audio_data_buf)
			break;

		napi_value napi_executor = reinterpret_cast<napi_value>(*executor);
		if (nullptr == napi_executor)
			break;
		napi_value napi_audio_array_buffer;
#if 1
		napi_status status = napi_create_buffer_copy(g_napi_env, len, (void*)audio_data_buf, nullptr, &napi_audio_array_buffer);
		if (notification)
			notification(hint);
#else
        FreeDataBufferInfo* info = new FreeDataBufferInfo;
        info->fnCallback = notification;
        info->hint = hint;
		napi_status status = napi_create_external_buffer(g_napi_env, len, (void*)audio_data_buf,
			FreeExternalArrayBufferMemory, info, &napi_audio_array_buffer);
#endif
		if (napi_ok != status)
			break;

		napi_value napi_audio_foramt;
		status = napi_create_string_utf8(g_napi_env, audio_data_format.c_str(), audio_data_format.size(), &napi_audio_foramt);
		if (napi_ok != status)
			break;

		napi_value napi_nodeid;
		status = napi_create_string_utf8(g_napi_env, nodeid.c_str(), nodeid.size(), &napi_nodeid);
		if (napi_ok != status)
			break;

		napi_value global;
		status = napi_get_global(g_napi_env, &global);
		if (napi_ok != status)
			break;

		napi_value argv[3] = { napi_audio_array_buffer, napi_audio_foramt, napi_nodeid };
		napi_value result;
		status = napi_call_function(g_napi_env, global, napi_executor, sizeof(argv) / sizeof(argv[0]), argv, &result);
	} while (false);
}

extern "C" NODE_MODULE_EXPORT void GetRawBufferPtr(v8::Local<v8::Uint8Array> & data_buffer, void** pp_raw_ptr, size_t & p_size)
{
	do 
	{
		if (nullptr == g_napi_env)
			break;

		napi_value napi_buffer = reinterpret_cast<napi_value>(*data_buffer);
		if (nullptr == napi_buffer)
			break;

		napi_status stauts = napi_get_buffer_info(g_napi_env,
			napi_buffer,
			pp_raw_ptr,
			&p_size);
	} while (false);
}
extern "C" NODE_MODULE_EXPORT void GetRawArrayBufferPtr(v8::Local<v8::ArrayBuffer> &data_buffer, void** pp_raw_ptr, size_t & p_size)
{
	do
	{
		if (nullptr == g_napi_env)
			break;

		napi_value napi_buffer = reinterpret_cast<napi_value>(*data_buffer);
		if (nullptr == napi_buffer)
			break;

		napi_status stauts = napi_get_arraybuffer_info(g_napi_env,
			napi_buffer,
			pp_raw_ptr,
			&p_size);
	} while (false);
}