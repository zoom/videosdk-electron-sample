#ifndef _ZOOM_NODE_VIDEO_SDK_AUDIO_SETTING_H_
#define _ZOOM_NODE_VIDEO_SDK_AUDIO_SETTING_H_
#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"
#include "zoom_video_sdk_singleton_wrap_class.h"


extern ZNativeVideoSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomVideoNodeAudioSettingWrap :
	public ZoomWrapObject<ZoomVideoNodeAudioSettingWrap >
{
	friend class ZoomWrapObject<ZoomVideoNodeAudioSettingWrap >;
private:
	ZoomVideoNodeAudioSettingWrap();
	~ZoomVideoNodeAudioSettingWrap();
public:
	static void GetSuppressBackgroundNoiseLevel(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetSuppressBackgroundNoiseLevel(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableMicOriginalInput(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsMicOriginalInputEnable(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableHighFidelityMusicMode(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsHighFidelityMusicModeEnable(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableEchoCancellation(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsEchoCancellationEnable(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableStereoAudio(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsStereoAudioEnable(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetEchoCancellationLevel(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetEchoCancellationLevel(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<> inline 
void InitClassAttribute<ZoomVideoNodeAudioSettingWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomVideoNodeAudioSettingWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSuppressBackgroundNoiseLevel", ZoomVideoNodeAudioSettingWrap::GetSuppressBackgroundNoiseLevel);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetSuppressBackgroundNoiseLevel", ZoomVideoNodeAudioSettingWrap::SetSuppressBackgroundNoiseLevel);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableMicOriginalInput", ZoomVideoNodeAudioSettingWrap::EnableMicOriginalInput);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsMicOriginalInputEnable", ZoomVideoNodeAudioSettingWrap::IsMicOriginalInputEnable);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableHighFidelityMusicMode", ZoomVideoNodeAudioSettingWrap::EnableHighFidelityMusicMode);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsHighFidelityMusicModeEnable", ZoomVideoNodeAudioSettingWrap::IsHighFidelityMusicModeEnable);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableEchoCancellation", ZoomVideoNodeAudioSettingWrap::EnableEchoCancellation);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsEchoCancellationEnable", ZoomVideoNodeAudioSettingWrap::IsEchoCancellationEnable);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableStereoAudio", ZoomVideoNodeAudioSettingWrap::EnableStereoAudio);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsStereoAudioEnable", ZoomVideoNodeAudioSettingWrap::IsStereoAudioEnable);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetEchoCancellationLevel", ZoomVideoNodeAudioSettingWrap::GetEchoCancellationLevel);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetEchoCancellationLevel", ZoomVideoNodeAudioSettingWrap::SetEchoCancellationLevel);
}
template<> inline 
v8::Persistent<v8::Function>* GetConstructor<ZoomVideoNodeAudioSettingWrap >() {
	return &ZoomVideoNodeAudioSettingWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ZOOM_NODE_HIDE ZoomVideoNodeTestAudioDeviceWrap :
	public ZoomWrapObject<ZoomVideoNodeTestAudioDeviceWrap >
{
	friend class ZoomWrapObject<ZoomVideoNodeTestAudioDeviceWrap >;
private:
	ZoomVideoNodeTestAudioDeviceWrap();
	~ZoomVideoNodeTestAudioDeviceWrap();
public:
	static void StartMicTestRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StopMicTestRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void PlayMicTestRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StartSpeakerTest(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StopSpeakerTest(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetTimerInterval(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<> inline 
void InitClassAttribute<ZoomVideoNodeTestAudioDeviceWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomVideoNodeTestAudioDeviceWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartMicTestRecording", ZoomVideoNodeTestAudioDeviceWrap::StartMicTestRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopMicTestRecording", ZoomVideoNodeTestAudioDeviceWrap::StopMicTestRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "PlayMicTestRecording", ZoomVideoNodeTestAudioDeviceWrap::PlayMicTestRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartSpeakerTest", ZoomVideoNodeTestAudioDeviceWrap::StartSpeakerTest);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopSpeakerTest", ZoomVideoNodeTestAudioDeviceWrap::StopSpeakerTest);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetTimerInterval", ZoomVideoNodeTestAudioDeviceWrap::SetTimerInterval);
}
template<> inline 
v8::Persistent<v8::Function>* GetConstructor<ZoomVideoNodeTestAudioDeviceWrap >() {
	return &ZoomVideoNodeTestAudioDeviceWrap::constructor;
}

#endif
