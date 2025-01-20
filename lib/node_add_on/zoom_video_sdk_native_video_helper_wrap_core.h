#pragma once

#include "zoom_video_sdk_native_sdk_wrap_core_def.h"
#include "zoom_video_sdk_sinks_wrap_class.h"



class ZVideoHelperWrap
{
public:
	ZVideoHelperWrap();
	virtual ~ZVideoHelperWrap();

	ZNZoomVideoSDKErrors StartVideo();
	ZNZoomVideoSDKErrors StopVideo();
	ZNZoomVideoSDKErrors SpotLightVideo(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser);
	ZNZoomVideoSDKErrors UnSpotLightVideo(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser);
	ZNZoomVideoSDKErrors UnSpotlightAllVideos();
	void GetSpotlightedVideoUserList(com::electron::zoomvideo::sdk::proto::UserList& _spotlightedUsers);
	bool RotateMyVideo(ZNVideoRotation rotation);
	bool SwitchCamera();
	bool SelectCamera(ZoomSTRING deviceID);
#if (!defined __linux)
	bool EnableMultiStreamVideo(ZoomSTRING deviceID);
	bool DisableMultiStreamVideo(ZoomSTRING deviceID);
	ZNZoomVideoSDKErrors AddVirtualBackgroundItem(ZoomSTRING imagePath, int64_t& vbItem);
	ZNZoomVideoSDKErrors RemoveVirtualBackgroundItem(int64_t imageItem);
	ZNZoomVideoSDKErrors SetVirtualBackgroundItem(int64_t imageItem);
	void GetSelectedVirtualBackgroundItem(int64_t& selectedItem);
	void GetVirtualBackgroundItemList(com::electron::zoomvideo::sdk::proto::VBItemHandleList& vbItemList);
	ZNZoomVideoSDKErrors GetVirtualBackgroundItemInfo(int64_t imageItem, com::electron::zoomvideo::sdk::proto::VBItemInfo& itemInfo);
	bool IsValidItem(int64_t imageItem);
#endif
	int GetNumberOfCameras();
	void GetCameraList(com::electron::zoomvideo::sdk::proto::GetCameraList& _cameraList);
	ZNZoomVideoSDKErrors CanControlCamera(bool& bCan);
	ZNZoomVideoSDKErrors TurnCameraLeft(unsigned int range);
	ZNZoomVideoSDKErrors TurnCameraRight(unsigned int range);
	ZNZoomVideoSDKErrors TurnCameraUp(unsigned int range);
	ZNZoomVideoSDKErrors TurnCameraDown(unsigned int range);
	ZNZoomVideoSDKErrors ZoomCameraIn(unsigned int range);
	ZNZoomVideoSDKErrors ZoomCameraOut(unsigned int range);
	ZNZoomVideoSDKErrors SetVideoQualityPreference(ZNZoomVideoSDKVideoPreferenceSetting preference_setting);
	ZNZoomVideoSDKErrors StartVideoPreview(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRawDataPipeDelegate* listener, ZoomSTRING cameraDeviceID);
	ZNZoomVideoSDKErrors StopVideoPreview(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRawDataPipeDelegate* listener);
	void GetMultiCameraStreamList(com::electron::zoomvideo::sdk::proto::MultiCameraStreamList& _mutilCameraStreamList, ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser);
};
