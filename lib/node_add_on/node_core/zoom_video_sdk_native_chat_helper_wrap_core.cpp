#include "zoom_video_sdk_native_chat_helper_wrap_core.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"

extern ZNativeVideoSDKWrap _g_native_wrap;

ZChatHelperWrap::ZChatHelperWrap()
{

}
ZChatHelperWrap::~ZChatHelperWrap()
{

}
bool ZChatHelperWrap::IsChatDisabled()
{
	bool bRet = false;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKChatHelper* pChatHelper = pVideoSDK->getChatHelper();
		if (pChatHelper)
		{
			bRet = pChatHelper->isChatDisabled();
		}
	}
	return bRet;
}
bool ZChatHelperWrap::IsPrivateChatDisabled()
{
	bool bRet = false;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKChatHelper* pChatHelper = pVideoSDK->getChatHelper();
		if (pChatHelper)
		{
			bRet = pChatHelper->isPrivateChatDisabled();
		}
	}
	return bRet;
}
ZNZoomVideoSDKErrors ZChatHelperWrap::SendChatToUser(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, ZoomSTRING msgContent)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKChatHelper* pChatHelper = pVideoSDK->getChatHelper();
		if (!pChatHelper)
		{
			break;
		}
		if (!msgContent.empty())
		{
			if (_g_native_wrap.IsValidUser(pUser))
			{
				err = (ZNZoomVideoSDKErrors)pChatHelper->sendChatToUser(pUser, msgContent.c_str());
			}
			else
			{
				err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			}
		}
		else
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
		}

	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZChatHelperWrap::SendChatToAll(ZoomSTRING msgContent)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKChatHelper* pChatHelper = pVideoSDK->getChatHelper();
		if (!pChatHelper)
		{
			break;
		}
		if (!msgContent.empty())
		{
			err = (ZNZoomVideoSDKErrors)pChatHelper->sendChatToAll(msgContent.c_str());
		}
		else
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
		}

	} while (false);
	return err;
}
bool ZChatHelperWrap::CanChatMessageBeDeleted(ZoomSTRING msgID)
{
	bool bRet = false;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKChatHelper* pChatHelper = pVideoSDK->getChatHelper();
		if (!pChatHelper)
		{
			break;
		}
		if (msgID.empty())
		{
			break;
		}
		bRet = pChatHelper->canChatMessageBeDeleted(msgID.c_str());

	} while (false);
	return bRet;
}
ZNZoomVideoSDKErrors ZChatHelperWrap::DeleteChatMessage(ZoomSTRING msgID)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKChatHelper* pChatHelper = pVideoSDK->getChatHelper();
		if (!pChatHelper)
		{
			break;
		}
		if (!msgID.empty())
		{
			err = (ZNZoomVideoSDKErrors)pChatHelper->deleteChatMessage(msgID.c_str());
		}
		else
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
		}

	} while (false);
	return err;
}
