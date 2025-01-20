#pragma once

#include "zoom_video_sdk_native_sdk_wrap_core_def.h"
#include "zoom_video_sdk_sinks_wrap_class.h"


class ZAudioSettingWrap
{
public:
	ZAudioSettingWrap();
	virtual ~ZAudioSettingWrap();

	ZNZoomVideoSDKErrors GetSuppressBackgroundNoiseLevel(ZNZoomVideoSDKSuppressBackgroundNoiseLevel& level);
	ZNZoomVideoSDKErrors SetSuppressBackgroundNoiseLevel(ZNZoomVideoSDKSuppressBackgroundNoiseLevel level);
	ZNZoomVideoSDKErrors EnableMicOriginalInput(bool bEnable);
	ZNZoomVideoSDKErrors IsMicOriginalInputEnable(bool& bEnable);
	ZNZoomVideoSDKErrors EnableHighFidelityMusicMode(bool bEnable);
	ZNZoomVideoSDKErrors IsHighFidelityMusicModeEnable(bool& bEnable);
	ZNZoomVideoSDKErrors EnableEchoCancellation(bool bEnable);
	ZNZoomVideoSDKErrors IsEchoCancellationEnable(bool& bEnable);
	ZNZoomVideoSDKErrors EnableStereoAudio(bool bEnable);
	ZNZoomVideoSDKErrors IsStereoAudioEnable(bool& bEnable);
	ZNZoomVideoSDKErrors GetEchoCancellationLevel(ZNZoomVideoSDKEchoCancellationLevel& level);
	ZNZoomVideoSDKErrors SetEchoCancellationLevel(ZNZoomVideoSDKEchoCancellationLevel level);
};

class ZTestAudioDeviceWrap
{
public:
	ZTestAudioDeviceWrap();
	virtual ~ZTestAudioDeviceWrap();

	ZNZoomVideoSDKErrors StartMicTestRecording(ZoomSTRING deviceID);
	ZNZoomVideoSDKErrors StopMicTestRecording();
	ZNZoomVideoSDKErrors PlayMicTestRecording();
	ZNZoomVideoSDKErrors StartSpeakerTest(ZoomSTRING deviceID);
	ZNZoomVideoSDKErrors StopSpeakerTest();
	ZNZoomVideoSDKErrors SetTimerInterval(unsigned int timerInterval);
};
