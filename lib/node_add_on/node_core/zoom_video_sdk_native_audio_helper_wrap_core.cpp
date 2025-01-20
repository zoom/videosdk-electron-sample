#include "zoom_video_sdk_native_audio_helper_wrap_core.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"


extern ZNativeVideoSDKWrap _g_native_wrap;

ZAudioHelperWrap::ZAudioHelperWrap()
{
}
ZAudioHelperWrap::~ZAudioHelperWrap()
{
}
ZNZoomVideoSDKErrors ZAudioHelperWrap::StartAudio()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAudioHelper* pAudioHelper = pVideoSDK->getAudioHelper();
		if (pAudioHelper)
		{
			err = (ZNZoomVideoSDKErrors)pAudioHelper->startAudio();
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZAudioHelperWrap::StopAudio()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAudioHelper* pAudioHelper = pVideoSDK->getAudioHelper();
		if (pAudioHelper)
		{
			err = (ZNZoomVideoSDKErrors)pAudioHelper->stopAudio();
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZAudioHelperWrap::MuteAudio(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAudioHelper* pAudioHelper = pVideoSDK->getAudioHelper();
		if (pAudioHelper)
		{
			if (_g_native_wrap.IsValidUser(pUser))
			{
				err = (ZNZoomVideoSDKErrors)pAudioHelper->muteAudio(pUser);
			}
			else
			{
				err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			}
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZAudioHelperWrap::UnMuteAudio(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAudioHelper* pAudioHelper = pVideoSDK->getAudioHelper();
		if (pAudioHelper)
		{
			if (_g_native_wrap.IsValidUser(pUser))
			{
				err = (ZNZoomVideoSDKErrors)pAudioHelper->unMuteAudio(pUser);
			}
			else
			{
				err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			}
		}
	}
	return err;
}

void ZAudioHelperWrap::GetSpeakerList(com::electron::zoomvideo::sdk::proto::GetSpeakerList& _speakerList)
{
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			return;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAudioHelper* pAudioHelper = pVideoSDK->getAudioHelper();
		if (!pAudioHelper)
		{
			return;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKSpeakerDevice* >* lst_speaker = pAudioHelper->getSpeakerList();
		if (!lst_speaker)
		{
			return;
		}
		for (int i = 0; i < lst_speaker->GetCount(); ++i)
		{
			ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKSpeakerDevice* pSpeakerTemp = lst_speaker->GetItem(i);
			com::electron::zoomvideo::sdk::proto::SpeakerInfos* protoVideoSDKSpeakerInfos = _speakerList.add_speakerinfo();
			if (!pSpeakerTemp || !protoVideoSDKSpeakerInfos)
			{
				continue;
			}
			ZoomSTRING temp_deviceId = pSpeakerTemp->getDeviceId();
			protoVideoSDKSpeakerInfos->set_deviceid(ws2s(temp_deviceId).c_str());
			ZoomSTRING temp_deviceName = pSpeakerTemp->getDeviceName();
			protoVideoSDKSpeakerInfos->set_devicename(ws2s(temp_deviceName).c_str());
			protoVideoSDKSpeakerInfos->set_isselecteddevice(pSpeakerTemp->isSelectedDevice());
		}

	} while (false);
}
void ZAudioHelperWrap::GetMicList(com::electron::zoomvideo::sdk::proto::GetMicList& _micList)
{
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			return;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAudioHelper* pAudioHelper = pVideoSDK->getAudioHelper();
		if (!pAudioHelper)
		{
			return;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKMicDevice* >* lst_mic = pAudioHelper->getMicList();
		if (!lst_mic)
		{
			return;
		}
		
		for (int i = 0; i < lst_mic->GetCount(); ++i)
		{
			ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKMicDevice* pMicTemp = lst_mic->GetItem(i);
			com::electron::zoomvideo::sdk::proto::MicInfos* protoVideoSDKMicInfos = _micList.add_micinfo();
			if (!pMicTemp || !protoVideoSDKMicInfos)
			{
				continue;
			}
			ZoomSTRING temp_deviceId = pMicTemp->getDeviceId();
			protoVideoSDKMicInfos->set_deviceid(ws2s(temp_deviceId).c_str());
			ZoomSTRING temp_deviceName = pMicTemp->getDeviceName();
			protoVideoSDKMicInfos->set_devicename(ws2s(temp_deviceName).c_str());
			protoVideoSDKMicInfos->set_isselecteddevice(pMicTemp->isSelectedDevice());
		}

	} while (false);
}
ZNZoomVideoSDKErrors ZAudioHelperWrap::SelectSpeaker(ZoomSTRING deviceId, ZoomSTRING deviceName)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAudioHelper* pAudioHelper = pVideoSDK->getAudioHelper();
		if (pAudioHelper)
		{
			err = (ZNZoomVideoSDKErrors)pAudioHelper->selectSpeaker(deviceId.c_str(), deviceName.c_str());
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZAudioHelperWrap::SelectMic(ZoomSTRING deviceId, ZoomSTRING deviceName)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAudioHelper* pAudioHelper = pVideoSDK->getAudioHelper();
		if (pAudioHelper)
		{
			err = (ZNZoomVideoSDKErrors)pAudioHelper->selectMic(deviceId.c_str(), deviceName.c_str());
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZAudioHelperWrap::Subscribe()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAudioHelper* pAudioHelper = pVideoSDK->getAudioHelper();
		if (pAudioHelper)
		{
			err = (ZNZoomVideoSDKErrors)pAudioHelper->subscribe();
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZAudioHelperWrap::UnSubscribe()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAudioHelper* pAudioHelper = pVideoSDK->getAudioHelper();
		if (pAudioHelper)
		{
			err = (ZNZoomVideoSDKErrors)pAudioHelper->unSubscribe();
		}
	}
	return err;
}