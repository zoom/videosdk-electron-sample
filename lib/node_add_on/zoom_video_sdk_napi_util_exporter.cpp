#include "zoom_video_sdk_napi_util_exporter.h"
#ifdef WIN32
#else
#include <dlfcn.h>
#if TARGET_OS_MAC
#include <mach-o/dyld.h>
#endif
#endif
#if (defined __linux)
#include <link.h>
#include <algorithm>
#define SELF_NAPI_UTIL_MODULE_NAME "zoomvideosdk_napi_util.node"
static int find_self_module_path_callback(struct dl_phdr_info *info, size_t size, void *data)
{
	if (info && info->dlpi_name && data)
	{
		const char* name = info->dlpi_name;
		const char *p = strrchr(name, '/');
        if (nullptr == p)
           return 0;
            
        const char* name_ptr = p + 1;
        if (name_ptr == strstr(name_ptr, SELF_NAPI_UTIL_MODULE_NAME))
        {
			std::string* str_name = (std::string*)data;
			(*str_name).append(name);
        }
	}
	return 0;
}
#endif
bool ZoomNodeAPIUtilHelper::ExportNAPIUtilFunc()
{
	void* napi_util_so = NULL;
	do
	{
		if (m_bInit)
		{
			break;
		}
#if (defined WIN32)
		napi_util_so = (void*)GetModuleHandleA("zoomvideosdk_napi_util.node");
		if (NULL == napi_util_so)
		{
			break;
		}

		m_fnCallbackVideoFormatDataToJS = (fnCallbackVideoFormatDataToJS)GetProcAddress((HMODULE)napi_util_so, "CallbackVideoFormatDataToJS");
		m_fnCallbackMixedAudioFormatDataToJS = (fnCallbackMixedAudioFormatDataToJS)GetProcAddress((HMODULE)napi_util_so, "CallbackMixedAudioFormatDataToJS");
		m_fnCallbackOnewayAudioFormatDataToJS = (fnCallbackOnewayAudioFormatDataToJS)GetProcAddress((HMODULE)napi_util_so, "CallbackOnewayAudioFormatDataToJS");
		m_fnGetRawBufferPtr = (fnGetRawBufferPtr)GetProcAddress((HMODULE)napi_util_so, "GetRawBufferPtr");
		m_fnGetRawArrayBufferPtr = (fnGetRawArrayBufferPtr)GetProcAddress((HMODULE)napi_util_so, "GetRawArrayBufferPtr");
#elif (defined __linux)
		std::string video_sdk_napi_util;
		dl_iterate_phdr(find_self_module_path_callback, &video_sdk_napi_util);

		void* napi_util_so = dlopen(video_sdk_napi_util.c_str(), RTLD_LAZY);

		if (!napi_util_so)
			break;
		m_fnCallbackVideoFormatDataToJS = (fnCallbackVideoFormatDataToJS)dlsym(napi_util_so, "CallbackVideoFormatDataToJS");
		m_fnCallbackMixedAudioFormatDataToJS = (fnCallbackMixedAudioFormatDataToJS)dlsym(napi_util_so, "CallbackMixedAudioFormatDataToJS");
		m_fnCallbackOnewayAudioFormatDataToJS = (fnCallbackOnewayAudioFormatDataToJS)dlsym(napi_util_so, "CallbackOnewayAudioFormatDataToJS");
		m_fnGetRawBufferPtr = (fnGetRawBufferPtr)dlsym(napi_util_so, "GetRawBufferPtr");
		m_fnGetRawArrayBufferPtr = (fnGetRawArrayBufferPtr)dlsym(napi_util_so, "GetRawArrayBufferPtr");
#elif (defined TARGET_OS_MAC)
#define mac_napi_util "zoomvideosdk_napi_util.node" 
#define func_CallbackVideoFormatDataToJS "CallbackVideoFormatDataToJS"
#define func_CallbackMixedAudioFormatDataToJS "CallbackMixedAudioFormatDataToJS"
#define func_CallbackOnewayAudioFormatDataToJS "CallbackOnewayAudioFormatDataToJS"
#define func_GetRawBufferPtr "GetRawBufferPtr"
#define func_GetRawArrayBufferPtr "GetRawArrayBufferPtr"
        void* napi_util_so = nullptr;
        uint32_t numImages = _dyld_image_count();
        for (uint32_t i = 0; i < numImages; i++) {
            const char *name = _dyld_get_image_name(i);
            if (nullptr == name)
                continue;
            
            const char *p = strrchr(name, '/');
            if (nullptr == p)
                continue;
            
            const char* name_ptr = p + 1;
            if (name_ptr == strstr(name_ptr, mac_napi_util))
            {
                napi_util_so = dlopen(name, RTLD_NOW|RTLD_NOLOAD);
                break;
            }
        }
		
		if (!napi_util_so)
			break;
		m_fnCallbackVideoFormatDataToJS = (fnCallbackVideoFormatDataToJS)dlsym(napi_util_so, func_CallbackVideoFormatDataToJS);
		m_fnCallbackMixedAudioFormatDataToJS = (fnCallbackMixedAudioFormatDataToJS)dlsym(napi_util_so, func_CallbackMixedAudioFormatDataToJS);
		m_fnCallbackOnewayAudioFormatDataToJS = (fnCallbackOnewayAudioFormatDataToJS)dlsym(napi_util_so, func_CallbackOnewayAudioFormatDataToJS);
		m_fnGetRawBufferPtr = (fnGetRawBufferPtr)dlsym(napi_util_so, func_GetRawBufferPtr);
		m_fnGetRawArrayBufferPtr = (fnGetRawArrayBufferPtr)dlsym(napi_util_so, func_GetRawArrayBufferPtr);
#endif

		if (NULL == m_fnCallbackVideoFormatDataToJS
			|| NULL == m_fnCallbackMixedAudioFormatDataToJS
			|| NULL == m_fnCallbackOnewayAudioFormatDataToJS
			|| NULL == m_fnGetRawBufferPtr
			|| NULL == m_fnGetRawArrayBufferPtr)
		{
			break;
		}
		m_bInit = true;
	} while (false);

	if (!m_bInit)
	{
		if (napi_util_so)
		{
			Reset();
		}
	}

	return m_bInit;
}
void ZoomNodeAPIUtilHelper::Reset()
{
	m_fnCallbackVideoFormatDataToJS = NULL;
	m_fnCallbackMixedAudioFormatDataToJS = NULL;
	m_fnCallbackOnewayAudioFormatDataToJS = NULL;
	m_fnGetRawBufferPtr = NULL;
	m_fnGetRawArrayBufferPtr = NULL;
	m_bInit = false;
}
