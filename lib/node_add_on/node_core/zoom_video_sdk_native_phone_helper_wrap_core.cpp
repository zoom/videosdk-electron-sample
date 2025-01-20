#include "zoom_video_sdk_native_phone_helper_wrap_core.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"

extern ZNativeVideoSDKWrap _g_native_wrap;

ZPhoneHelperWrap::ZPhoneHelperWrap()
{

}
ZPhoneHelperWrap::~ZPhoneHelperWrap()
{

}
bool ZPhoneHelperWrap::IsSupportPhoneFeature()
{
	bool bRet = false;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKPhoneHelper* pPhoneHelper = pVideoSDK->getPhoneHelper();
		if (pPhoneHelper)
		{
			bRet = pPhoneHelper->isSupportPhoneFeature();
		}
	}
	return bRet;
}
void ZPhoneHelperWrap::GetSupportCountryInfo(com::electron::zoomvideo::sdk::proto::GetPhoneSupportCountryList& phoneSupportCountryList)
{
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			return;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKPhoneHelper* pPhoneHelper = pVideoSDK->getPhoneHelper();
		if (!pPhoneHelper)
		{
			return;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKPhoneSupportCountryInfo* >* lst_country = pPhoneHelper->getSupportCountryInfo();
		if (!lst_country)
		{
			return;
		}
		for (int i = 0; i < lst_country->GetCount(); ++i)
		{
			ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKPhoneSupportCountryInfo* pCountryTemp = lst_country->GetItem(i);
			com::electron::zoomvideo::sdk::proto::PhoneSupportCountryInfos* protoPhoneSupportCountryInfos = phoneSupportCountryList.add_phonesupportcountryinfo();
			if (!pCountryTemp || !protoPhoneSupportCountryInfos)
			{
				continue;
			}
			ZoomSTRING temp_countryId = pCountryTemp->getCountryID();
			protoPhoneSupportCountryInfos->set_countryid(ws2s(temp_countryId).c_str());
			ZoomSTRING temp_countryName = pCountryTemp->getCountryName();
			protoPhoneSupportCountryInfos->set_countryname(ws2s(temp_countryName).c_str());
			ZoomSTRING temp_countryCode = pCountryTemp->getCountryCode();
			protoPhoneSupportCountryInfos->set_countrycode(ws2s(temp_countryCode).c_str());
		}

	} while (false);
}
ZNZoomVideoSDKErrors ZPhoneHelperWrap::InviteByPhone(ZoomSTRING countryCode, ZoomSTRING phoneNumber, ZoomSTRING name)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKPhoneHelper* pPhoneHelper = pVideoSDK->getPhoneHelper();
		if (pPhoneHelper)
		{
			err = (ZNZoomVideoSDKErrors)pPhoneHelper->inviteByPhone(countryCode.c_str(), phoneNumber.c_str(), name.c_str());
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZPhoneHelperWrap::InvitePhoneUser(ZNInvitePhoneUserInfo& zn_inviteInfo)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKPhoneHelper* pPhoneHelper = pVideoSDK->getPhoneHelper();
		if (pPhoneHelper)
		{
			ZOOM_VIDEO_SDK_NAMESPACE::InvitePhoneUserInfo inviteInfo;
			inviteInfo.countryCode = zn_inviteInfo.countryCode.c_str();
			inviteInfo.phoneNumber = zn_inviteInfo.phoneNumber.c_str();
			inviteInfo.name = zn_inviteInfo.name.c_str();
			inviteInfo.bPressOne = zn_inviteInfo.bPressOne;
			inviteInfo.bGreeting = zn_inviteInfo.bGreeting;
			err = (ZNZoomVideoSDKErrors)pPhoneHelper->invitePhoneUser(inviteInfo);
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZPhoneHelperWrap::CancelInviteByPhone()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKPhoneHelper* pPhoneHelper = pVideoSDK->getPhoneHelper();
		if (pPhoneHelper)
		{
			err = (ZNZoomVideoSDKErrors)pPhoneHelper->cancelInviteByPhone();
		}
	}
	return err;
}
ZNPhoneStatus ZPhoneHelperWrap::GetInviteByPhoneStatus()
{
	ZNPhoneStatus zn_status = ZNPhoneStatus_None;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKPhoneHelper* pPhoneHelper = pVideoSDK->getPhoneHelper();
		if (pPhoneHelper)
		{
			zn_status = (ZNPhoneStatus)pPhoneHelper->getInviteByPhoneStatus();
		}
	}
	return zn_status;
}
