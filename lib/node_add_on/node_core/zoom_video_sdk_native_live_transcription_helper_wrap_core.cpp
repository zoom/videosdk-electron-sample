#include "zoom_video_sdk_node_rawdata_helper_mgr_class.h"
#include "zoom_video_sdk_native_live_transcription_helper_wrap_core.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"

extern ZNativeVideoSDKWrap _g_native_wrap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ZLiveTranscriptionHelperWrap::ZLiveTranscriptionHelperWrap()
{

}
ZLiveTranscriptionHelperWrap::~ZLiveTranscriptionHelperWrap()
{

}
bool ZLiveTranscriptionHelperWrap::CanStartLiveTranscription()
{
	bool bSucc = false;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}

		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKLiveTranscriptionHelper* pLTTHelper = pVideoSDK->getLiveTranscriptionHelper();
		if (!pLTTHelper)
		{
			break;
		}
		bSucc = pLTTHelper->canStartLiveTranscription();
	} while (false);
	return bSucc;
}
ZNZoomVideoSDKErrors ZLiveTranscriptionHelperWrap::GetLiveTranscriptionStatus(ZNZoomVideoSDKLiveTranscriptionStatus& status)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}

		ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKLiveTranscriptionStatus sdk_status;
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKLiveTranscriptionHelper* pLTTHelper = pVideoSDK->getLiveTranscriptionHelper();
		if (!pLTTHelper)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pLTTHelper->getLiveTranscriptionStatus(sdk_status);
		status = (ZNZoomVideoSDKLiveTranscriptionStatus)sdk_status;
	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZLiveTranscriptionHelperWrap::StartLiveTranscription()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}

		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKLiveTranscriptionHelper* pLTTHelper = pVideoSDK->getLiveTranscriptionHelper();
		if (!pLTTHelper)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pLTTHelper->startLiveTranscription();
	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZLiveTranscriptionHelperWrap::StopLiveTranscription()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKLiveTranscriptionHelper* pLTTHelper = pVideoSDK->getLiveTranscriptionHelper();
		if (!pLTTHelper)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pLTTHelper->stopLiveTranscription();
	} while (false);
	return err;
}
void ZLiveTranscriptionHelperWrap::GetAvailableSpokenLanguages(com::electron::zoomvideo::sdk::proto::LTTLanguagesList& _availableSpokenLanguagesList)
{
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			return;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKLiveTranscriptionHelper* pLTTHelper = pVideoSDK->getLiveTranscriptionHelper();
		if (!pLTTHelper)
		{
			return;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<ZOOM_VIDEO_SDK_NAMESPACE::ILiveTranscriptionLanguage*>* pLanguages = pLTTHelper->getAvailableSpokenLanguages();
		if (!pLanguages)
		{
			return;
		}

		for (int i = 0; i < pLanguages->GetCount(); ++i)
		{
			ILiveTranscriptionLanguage* pLanguageTemp = pLanguages->GetItem(i);
			com::electron::zoomvideo::sdk::proto::LTTLanguage* protoLTTLanguage = _availableSpokenLanguagesList.add_lttlanguageinfo();
			if (!pLanguageTemp || !protoLTTLanguage)
			{
				continue;
			}
			protoLTTLanguage->set_lttlanguageid(pLanguageTemp->getLTTLanguageID());
			ZoomSTRING temp_lttLanguageName = pLanguageTemp->getLTTLanguageName();
			protoLTTLanguage->set_lttlanguagename(zs2s(temp_lttLanguageName).c_str());
		}
	} while (false);
}
void ZLiveTranscriptionHelperWrap::GetAvailableTranslationLanguages(com::electron::zoomvideo::sdk::proto::LTTLanguagesList& _availableTranslationLanguagesList)
{
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			return;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKLiveTranscriptionHelper* pLTTHelper = pVideoSDK->getLiveTranscriptionHelper();
		if (!pLTTHelper)
		{
			return;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<ZOOM_VIDEO_SDK_NAMESPACE::ILiveTranscriptionLanguage*>* pLanguages = pLTTHelper->getAvailableTranslationLanguages();
		if (!pLanguages)
		{
			return;
		}

		for (int i = 0; i < pLanguages->GetCount(); ++i)
		{
			ILiveTranscriptionLanguage* pLanguageTemp = pLanguages->GetItem(i);
			com::electron::zoomvideo::sdk::proto::LTTLanguage* protoLTTLanguage = _availableTranslationLanguagesList.add_lttlanguageinfo();
			if (!pLanguageTemp || !protoLTTLanguage)
			{
				continue;
			}
			protoLTTLanguage->set_lttlanguageid(pLanguageTemp->getLTTLanguageID());
			ZoomSTRING temp_lttLanguageName = pLanguageTemp->getLTTLanguageName();
			protoLTTLanguage->set_lttlanguagename(zs2s(temp_lttLanguageName).c_str());
		}
	} while (false);
}
ZNZoomVideoSDKErrors ZLiveTranscriptionHelperWrap::SetSpokenLanguage(int languageID)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKLiveTranscriptionHelper* pLTTHelper = pVideoSDK->getLiveTranscriptionHelper();
		if (!pLTTHelper)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pLTTHelper->setSpokenLanguage(languageID);
	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZLiveTranscriptionHelperWrap::SetTranslationLanguage(int languageID)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}

		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKLiveTranscriptionHelper* pLTTHelper = pVideoSDK->getLiveTranscriptionHelper();
		if (!pLTTHelper)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pLTTHelper->setTranslationLanguage(languageID);
	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZLiveTranscriptionHelperWrap::GetSpokenLanguage(ZNLiveTranscriptionLanguage& spokenLanguage)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		
		ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKLiveTranscriptionStatus sdk_status;
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKLiveTranscriptionHelper* pLTTHelper = pVideoSDK->getLiveTranscriptionHelper();
		if (!pLTTHelper)
		{
			break;
		}
		ILiveTranscriptionLanguage* pLanguageTemp = pLTTHelper->getSpokenLanguage();
		if (!pLanguageTemp)
		{
			break;
		}
		spokenLanguage.lttLanguageID = pLanguageTemp->getLTTLanguageID();
		spokenLanguage.lttLanguageName = pLanguageTemp->getLTTLanguageName();
		err = ZNZoomVideoSDKErrors_Success;
	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZLiveTranscriptionHelperWrap::GetTranslationLanguage(ZNLiveTranscriptionLanguage& translationLanguage)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}

		ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKLiveTranscriptionStatus sdk_status;
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKLiveTranscriptionHelper* pLTTHelper = pVideoSDK->getLiveTranscriptionHelper();
		if (!pLTTHelper)
		{
			break;
		}
		ILiveTranscriptionLanguage* pLanguageTemp = pLTTHelper->getTranslationLanguage();
		if (!pLanguageTemp)
		{
			break;
		}
		translationLanguage.lttLanguageID = pLanguageTemp->getLTTLanguageID();
		translationLanguage.lttLanguageName = pLanguageTemp->getLTTLanguageName();
		err = ZNZoomVideoSDKErrors_Success;
	} while (false);
	return err;
}
