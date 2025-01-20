#pragma once

#include "zoom_video_sdk_native_sdk_wrap_core_def.h"
#include "zoom_video_sdk_sinks_wrap_class.h"

class ZChatHelperWrap
{
public:
	ZChatHelperWrap();
	virtual ~ZChatHelperWrap();

	bool IsChatDisabled();
	bool IsPrivateChatDisabled();
	ZNZoomVideoSDKErrors SendChatToUser(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, ZoomSTRING msgContent);
	ZNZoomVideoSDKErrors SendChatToAll(ZoomSTRING msgContent);
	bool CanChatMessageBeDeleted(ZoomSTRING msgID);
	ZNZoomVideoSDKErrors DeleteChatMessage(ZoomSTRING msgID);
};
