#pragma once

#include "zoom_video_sdk_native_sdk_wrap_core_def.h"
#include "zoom_video_sdk_sinks_wrap_class.h"

class ZPhoneHelperWrap
{
public:
	ZPhoneHelperWrap();
	virtual ~ZPhoneHelperWrap();

	bool IsSupportPhoneFeature();
	void GetSupportCountryInfo(com::electron::zoomvideo::sdk::proto::GetPhoneSupportCountryList& phoneSupportCountryList);
	ZNZoomVideoSDKErrors InviteByPhone(ZoomSTRING countryCode, ZoomSTRING phoneNumber, ZoomSTRING name);
	ZNZoomVideoSDKErrors InvitePhoneUser(ZNInvitePhoneUserInfo& inviteInfo);
	ZNZoomVideoSDKErrors CancelInviteByPhone();
	ZNPhoneStatus GetInviteByPhoneStatus();
};
