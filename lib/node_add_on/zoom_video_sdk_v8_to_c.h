#ifndef _video_sdk_v8_to_c_h_
#define _video_sdk_v8_to_c_h_
#include <string>
#include "zoom_video_sdk_node_common_include.h"
#if (defined BUILD_WIN)
#define ZNODESTRING std::wstring
#else
#define ZNODESTRING std::string
#endif
void zoom_v8toc(v8::Local<v8::String> v8string, ZNODESTRING& c_string);
void convertBool(bool o_bool, bool& n_bool);
std::string zs2s(const ZNODESTRING& s);
ZNODESTRING s2zs(const std::string& s);
std::string ws2s(const ZNODESTRING& inputws);
#if (defined _WIN32)
void utf8to16(const char* src, ZNODESTRING& buffer);
std::string wchar2utf8(LPCWSTR pwszSrc);
#endif
#endif 
