#include "zoom_video_sdk_native_cmd_channel_helper_wrap_core.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"

extern ZNativeVideoSDKWrap _g_native_wrap;

ZCmdChannelHelperWrap::ZCmdChannelHelperWrap()
{

}
ZCmdChannelHelperWrap::~ZCmdChannelHelperWrap()
{

}
ZNZoomVideoSDKErrors ZCmdChannelHelperWrap::SendCommand(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* receiver, ZoomSTRING strCmd)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		if (receiver && !_g_native_wrap.IsValidUser(receiver))
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKCmdChannel* pCmdChannel = pVideoSDK->getCmdChannel();
		if (!pCmdChannel)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pCmdChannel->sendCommand(receiver, strCmd.c_str());
	} while (false);
	return err;
}
