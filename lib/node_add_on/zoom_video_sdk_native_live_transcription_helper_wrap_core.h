#pragma once

#include "zoom_video_sdk_native_sdk_wrap_core_def.h"
#include "zoom_video_sdk_sinks_wrap_class.h"

class ZLiveTranscriptionHelperWrap
{
public:
	ZLiveTranscriptionHelperWrap();
	virtual ~ZLiveTranscriptionHelperWrap();

	bool CanStartLiveTranscription();
	ZNZoomVideoSDKErrors GetLiveTranscriptionStatus(ZNZoomVideoSDKLiveTranscriptionStatus& status);
	ZNZoomVideoSDKErrors StartLiveTranscription();
	ZNZoomVideoSDKErrors StopLiveTranscription();
	void GetAvailableSpokenLanguages(com::electron::zoomvideo::sdk::proto::LTTLanguagesList& _availableSpokenLanguagesList);
	void GetAvailableTranslationLanguages(com::electron::zoomvideo::sdk::proto::LTTLanguagesList& _availableTranslationLanguagesList);
	ZNZoomVideoSDKErrors SetSpokenLanguage(int languageID);
	ZNZoomVideoSDKErrors SetTranslationLanguage(int languageID);
	ZNZoomVideoSDKErrors GetSpokenLanguage(ZNLiveTranscriptionLanguage& spokenLanguage);
	ZNZoomVideoSDKErrors GetTranslationLanguage(ZNLiveTranscriptionLanguage& translationLanguage);
};
