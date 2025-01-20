#include "zoom_video_sdk_native_audio_setting_wrap_core.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"


extern ZNativeVideoSDKWrap _g_native_wrap;

ZAudioSettingWrap::ZAudioSettingWrap()
{
}
ZAudioSettingWrap::~ZAudioSettingWrap()
{
}
ZNZoomVideoSDKErrors ZAudioSettingWrap::GetSuppressBackgroundNoiseLevel(ZNZoomVideoSDKSuppressBackgroundNoiseLevel& level)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAudioSettingHelper* pAudioSetting = pVideoSDK->getAudioSettingHelper();
		if (pAudioSetting)
		{
			ZoomVideoSDKSuppressBackgroundNoiseLevel sdk_level = ZoomVideoSDKSuppressBackgroundNoiseLevel_Auto;
			err = (ZNZoomVideoSDKErrors)pAudioSetting->getSuppressBackgroundNoiseLevel(sdk_level);
			if (ZNZoomVideoSDKErrors_Success == err)
			{
				level = (ZNZoomVideoSDKSuppressBackgroundNoiseLevel)sdk_level;
			}
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZAudioSettingWrap::SetSuppressBackgroundNoiseLevel(ZNZoomVideoSDKSuppressBackgroundNoiseLevel level)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAudioSettingHelper* pAudioSetting = pVideoSDK->getAudioSettingHelper();
		if (pAudioSetting)
		{
			err = (ZNZoomVideoSDKErrors)pAudioSetting->setSuppressBackgroundNoiseLevel((ZoomVideoSDKSuppressBackgroundNoiseLevel)level);
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZAudioSettingWrap::EnableMicOriginalInput(bool bEnable)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAudioSettingHelper* pAudioSetting = pVideoSDK->getAudioSettingHelper();
		if (pAudioSetting)
		{
			err = (ZNZoomVideoSDKErrors)pAudioSetting->enableMicOriginalInput(bEnable);
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZAudioSettingWrap::IsMicOriginalInputEnable(bool& bEnable)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAudioSettingHelper* pAudioSetting = pVideoSDK->getAudioSettingHelper();
		if (pAudioSetting)
		{
			err = (ZNZoomVideoSDKErrors)pAudioSetting->isMicOriginalInputEnable(bEnable);
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZAudioSettingWrap::EnableHighFidelityMusicMode(bool bEnable)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAudioSettingHelper* pAudioSetting = pVideoSDK->getAudioSettingHelper();
		if (pAudioSetting)
		{
			err = (ZNZoomVideoSDKErrors)pAudioSetting->enableHighFidelityMusicMode(bEnable);
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZAudioSettingWrap::IsHighFidelityMusicModeEnable(bool& bEnable)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAudioSettingHelper* pAudioSetting = pVideoSDK->getAudioSettingHelper();
		if (pAudioSetting)
		{
			err = (ZNZoomVideoSDKErrors)pAudioSetting->isHighFidelityMusicModeEnable(bEnable);
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZAudioSettingWrap::EnableEchoCancellation(bool bEnable)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAudioSettingHelper* pAudioSetting = pVideoSDK->getAudioSettingHelper();
		if (pAudioSetting)
		{
			err = (ZNZoomVideoSDKErrors)pAudioSetting->enableEchoCancellation(bEnable);
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZAudioSettingWrap::IsEchoCancellationEnable(bool& bEnable)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAudioSettingHelper* pAudioSetting = pVideoSDK->getAudioSettingHelper();
		if (pAudioSetting)
		{
			err = (ZNZoomVideoSDKErrors)pAudioSetting->isEchoCancellationEnable(bEnable);
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZAudioSettingWrap::EnableStereoAudio(bool bEnable)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAudioSettingHelper* pAudioSetting = pVideoSDK->getAudioSettingHelper();
		if (pAudioSetting)
		{
			err = (ZNZoomVideoSDKErrors)pAudioSetting->enableStereoAudio(bEnable);
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZAudioSettingWrap::IsStereoAudioEnable(bool& bEnable)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAudioSettingHelper* pAudioSetting = pVideoSDK->getAudioSettingHelper();
		if (pAudioSetting)
		{
			err = (ZNZoomVideoSDKErrors)pAudioSetting->isStereoAudioEnable(bEnable);
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZAudioSettingWrap::GetEchoCancellationLevel(ZNZoomVideoSDKEchoCancellationLevel& level)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAudioSettingHelper* pAudioSetting = pVideoSDK->getAudioSettingHelper();
		if (pAudioSetting)
		{
			ZoomVideoSDKEchoCancellationLevel sdk_level = ZoomVideoSDKEchoCancellationLevel_Default;
			err = (ZNZoomVideoSDKErrors)pAudioSetting->getEchoCancellationLevel(sdk_level);
			level = (ZNZoomVideoSDKEchoCancellationLevel)sdk_level;
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZAudioSettingWrap::SetEchoCancellationLevel(ZNZoomVideoSDKEchoCancellationLevel level)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAudioSettingHelper* pAudioSetting = pVideoSDK->getAudioSettingHelper();
		if (pAudioSetting)
		{
			err = (ZNZoomVideoSDKErrors)pAudioSetting->setEchoCancellationLevel((ZoomVideoSDKEchoCancellationLevel)level);
		}
	}
	return err;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ZTestAudioDeviceWrap::ZTestAudioDeviceWrap()
{
}
ZTestAudioDeviceWrap::~ZTestAudioDeviceWrap()
{
}
ZNZoomVideoSDKErrors ZTestAudioDeviceWrap::StartMicTestRecording(ZoomSTRING deviceID)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKTestAudioDeviceHelper* pAudioDeviceTest = pVideoSDK->GetAudioDeviceTestHelper();
		if (pAudioDeviceTest)
		{
			err = (ZNZoomVideoSDKErrors)pAudioDeviceTest->startMicTestRecording(deviceID.c_str());
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZTestAudioDeviceWrap::StopMicTestRecording()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKTestAudioDeviceHelper* pAudioDeviceTest = pVideoSDK->GetAudioDeviceTestHelper();
		if (pAudioDeviceTest)
		{
			err = (ZNZoomVideoSDKErrors)pAudioDeviceTest->stopMicTestRecording();
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZTestAudioDeviceWrap::PlayMicTestRecording()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKTestAudioDeviceHelper* pAudioDeviceTest = pVideoSDK->GetAudioDeviceTestHelper();
		if (pAudioDeviceTest)
		{
			err = (ZNZoomVideoSDKErrors)pAudioDeviceTest->playMicTestRecording();
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZTestAudioDeviceWrap::StartSpeakerTest(ZoomSTRING deviceID)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKTestAudioDeviceHelper* pAudioDeviceTest = pVideoSDK->GetAudioDeviceTestHelper();
		if (pAudioDeviceTest)
		{
			err = (ZNZoomVideoSDKErrors)pAudioDeviceTest->startSpeakerTest(deviceID.c_str());
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZTestAudioDeviceWrap::StopSpeakerTest()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKTestAudioDeviceHelper* pAudioDeviceTest = pVideoSDK->GetAudioDeviceTestHelper();
		if (pAudioDeviceTest)
		{
			err = (ZNZoomVideoSDKErrors)pAudioDeviceTest->stopSpeakerTest();
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZTestAudioDeviceWrap::SetTimerInterval(unsigned int timerInterval)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKTestAudioDeviceHelper* pAudioDeviceTest = pVideoSDK->GetAudioDeviceTestHelper();
		if (pAudioDeviceTest)
		{
			err = (ZNZoomVideoSDKErrors)pAudioDeviceTest->setTimerInterval(timerInterval);
		}
	}
	return err;
}