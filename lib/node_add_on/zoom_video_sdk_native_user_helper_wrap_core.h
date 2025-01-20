#pragma once

#include "zoom_video_sdk_native_sdk_wrap_core_def.h"
#include "zoom_video_sdk_sinks_wrap_class.h"


class ZUserHelperWrap
{
public:
	ZUserHelperWrap();
	virtual ~ZUserHelperWrap();

	bool ChangeName(ZoomSTRING name, ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser); //Change  user name with userId
	bool MakeHost(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser);                        //Set the userId  admin in the session
	bool MakeManager(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser);
	bool RevokeManager(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser);
	bool RemoveUser(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser);      //Remove user by userId
};
