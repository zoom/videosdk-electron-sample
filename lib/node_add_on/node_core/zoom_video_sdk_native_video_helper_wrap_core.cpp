#include "zoom_video_sdk_node_rawdata_helper_mgr_class.h"
#include "zoom_video_sdk_native_video_helper_wrap_core.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"


extern ZNativeVideoSDKWrap _g_native_wrap;

ZVideoHelperWrap::ZVideoHelperWrap()
{
}
ZVideoHelperWrap::~ZVideoHelperWrap()
{
}
ZNZoomVideoSDKErrors ZVideoHelperWrap::StartVideo()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (pVideoHelper)
		{
			err = (ZNZoomVideoSDKErrors)pVideoHelper->startVideo();
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZVideoHelperWrap::StopVideo()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (pVideoHelper)
		{
			err = (ZNZoomVideoSDKErrors)pVideoHelper->stopVideo();
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZVideoHelperWrap::SpotLightVideo(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		if (!_g_native_wrap.IsValidUser(pUser))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (!pVideoHelper)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pVideoHelper->spotLightVideo(pUser);
	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZVideoHelperWrap::UnSpotLightVideo(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		if (!_g_native_wrap.IsValidUser(pUser))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (!pVideoHelper)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pVideoHelper->unSpotLightVideo(pUser);
	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZVideoHelperWrap::UnSpotlightAllVideos()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (!pVideoHelper)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pVideoHelper->unSpotlightAllVideos();
	} while (false);
	return err;
}
void ZVideoHelperWrap::GetSpotlightedVideoUserList(com::electron::zoomvideo::sdk::proto::UserList& _spotlightedUsers)
{
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			return;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (!pVideoHelper)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser*>* pSpotlightedUsers = pVideoHelper->getSpotlightedVideoUserList();
		if (!pSpotlightedUsers)
		{
			return;
		}
		
		for (int i = 0; i < pSpotlightedUsers->GetCount(); ++i)
		{
			IZoomVideoSDKUser* pUserTemp = pSpotlightedUsers->GetItem(i);
			com::electron::zoomvideo::sdk::proto::VideoSDKUser* protoVideoSDKUser = _spotlightedUsers.add_user();
			if (!pUserTemp || !protoVideoSDKUser)
			{
				continue;
			}
			ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKUserToProtoUser(pUserTemp, protoVideoSDKUser);
		}
	} while (false);
}
bool ZVideoHelperWrap::RotateMyVideo(ZNVideoRotation rotation)
{
	bool bSucc = false;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (pVideoHelper)
		{
			bSucc = (ZNZoomVideoSDKErrors)pVideoHelper->rotateMyVideo((ZOOM_VIDEO_SDK_NAMESPACE::VideoRotation)rotation);
		}
	}
	return bSucc;
}
bool ZVideoHelperWrap::SwitchCamera()
{
	bool bSucc = false;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (pVideoHelper)
		{
			bSucc = (ZNZoomVideoSDKErrors)pVideoHelper->switchCamera();
		}
	}
	return bSucc;
}
bool ZVideoHelperWrap::SelectCamera(ZoomSTRING deviceID)
{
	bool bSucc = false;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (pVideoHelper)
		{
			bSucc = pVideoHelper->selectCamera(deviceID.c_str());
		}
	}
	return bSucc;
}
#if (!defined __linux)
bool ZVideoHelperWrap::EnableMultiStreamVideo(ZoomSTRING deviceID)
{
	bool bSucc = false;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (pVideoHelper)
		{
			bSucc = pVideoHelper->enableMultiStreamVideo(deviceID.c_str());
		}
	}
	return bSucc;
}

bool ZVideoHelperWrap::DisableMultiStreamVideo(ZoomSTRING deviceID)
{
	bool bSucc = false;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (pVideoHelper)
		{
			bSucc = pVideoHelper->disableMultiStreamVideo(deviceID.c_str());
		}
	}
	return bSucc;
}
#endif
int ZVideoHelperWrap::GetNumberOfCameras()
{
	int num_cam = -1;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (pVideoHelper)
		{
			num_cam = pVideoHelper->getNumberOfCameras();
		}
	}
	return num_cam;
}
void ZVideoHelperWrap::GetCameraList(com::electron::zoomvideo::sdk::proto::GetCameraList& _carmeraLst)
{
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			return;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (!pVideoHelper)
		{
			return;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKCameraDevice* >* lst_camera = pVideoHelper->getCameraList();
		if (!lst_camera)
		{
			return;
		}
		
		for (int i = 0; i < lst_camera->GetCount(); ++i)
		{
			IZoomVideoSDKCameraDevice* pCameraTemp = lst_camera->GetItem(i);
			com::electron::zoomvideo::sdk::proto::CameraInfos* protoVideoSDKCameraInfos = _carmeraLst.add_camerainfo();
			if (!pCameraTemp || !protoVideoSDKCameraInfos)
			{
				continue;
			}
			ZoomSTRING temp_deviceId = pCameraTemp->getDeviceId();
			protoVideoSDKCameraInfos->set_deviceid(ws2s(temp_deviceId).c_str());
			ZoomSTRING temp_deviceName = pCameraTemp->getDeviceName();
			protoVideoSDKCameraInfos->set_devicename(ws2s(temp_deviceName).c_str());
			protoVideoSDKCameraInfos->set_isselecteddevice(pCameraTemp->isSelectedDevice());
#if (!defined __linux)
			protoVideoSDKCameraInfos->set_isselectedasmulticamera(pCameraTemp->isSelectedAsMultiCamera());
			protoVideoSDKCameraInfos->set_isrunningasmulticamera(pCameraTemp->isRunningAsMultiCamera());
#endif
		}
	} while (false);
}
void ZVideoHelperWrap::GetMultiCameraStreamList(com::electron::zoomvideo::sdk::proto::MultiCameraStreamList& _mutilCameraStreamList, ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser)
{
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK || !_g_native_wrap.IsValidUser(pUser))
		{
			return;
		}
		
		std::map<int64_t, std::map<int32_t, int64_t > >::iterator iter_user = ZoomVideoNodeMultiCameraStreamHelperMgr::GetInst().m_multicamerastreamhelper_map.find((int64_t)pUser);
		if (ZoomVideoNodeMultiCameraStreamHelperMgr::GetInst().m_multicamerastreamhelper_map.end() == iter_user)
		{
			return;
		}
		if (iter_user->second.size() == 0)
		{
			return;
		}
		std::map<int32_t, int64_t >::iterator iter_camerastreamid;
		for (iter_camerastreamid = iter_user->second.begin(); iter_camerastreamid != iter_user->second.end(); iter_camerastreamid++)
		{
			com::electron::zoomvideo::sdk::proto::MultiCameraStreamInfos* protoMultiCameraStreamInfos = _mutilCameraStreamList.add_camerastreaminfo();
			if (!protoMultiCameraStreamInfos)
			{
				continue;
			}
			protoMultiCameraStreamInfos->set_camerastreamid((int64_t)iter_camerastreamid->first);
		}
	} while (false);
}
ZNZoomVideoSDKErrors ZVideoHelperWrap::CanControlCamera(bool& bCan)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (!pVideoHelper)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pVideoHelper->canControlCamera(bCan);
	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZVideoHelperWrap::TurnCameraLeft(unsigned int range)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (!pVideoHelper)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pVideoHelper->turnCameraLeft(range);
	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZVideoHelperWrap::TurnCameraRight(unsigned int range)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (!pVideoHelper)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pVideoHelper->turnCameraRight(range);
	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZVideoHelperWrap::TurnCameraUp(unsigned int range)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (!pVideoHelper)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pVideoHelper->turnCameraUp(range);
	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZVideoHelperWrap::TurnCameraDown(unsigned int range)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (!pVideoHelper)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pVideoHelper->turnCameraDown(range);
	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZVideoHelperWrap::ZoomCameraIn(unsigned int range)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (!pVideoHelper)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pVideoHelper->zoomCameraIn(range);
	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZVideoHelperWrap::ZoomCameraOut(unsigned int range)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (!pVideoHelper)
		{
			break;
		}
		err = (ZNZoomVideoSDKErrors)pVideoHelper->zoomCameraOut(range);
	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZVideoHelperWrap::SetVideoQualityPreference(ZNZoomVideoSDKVideoPreferenceSetting preference_setting)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (!pVideoHelper)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKVideoPreferenceSetting sdk_preference_setting;
		sdk_preference_setting.mode = (ZoomVideoSDKVideoPreferenceMode)preference_setting.mode;
		sdk_preference_setting.minimum_frame_rate = preference_setting.minimum_frame_rate;
		sdk_preference_setting.maximum_frame_rate = preference_setting.maximum_frame_rate;
		err = (ZNZoomVideoSDKErrors)pVideoHelper->setVideoQualityPreference(sdk_preference_setting);
	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZVideoHelperWrap::StartVideoPreview(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRawDataPipeDelegate* listener, ZoomSTRING cameraDeviceID)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK && listener)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (pVideoHelper)
		{
			err = (ZNZoomVideoSDKErrors)pVideoHelper->startVideoPreview(listener, cameraDeviceID.c_str());
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZVideoHelperWrap::StopVideoPreview(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRawDataPipeDelegate* listener)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK && listener)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (pVideoHelper)
		{
			err = (ZNZoomVideoSDKErrors)pVideoHelper->stopVideoPreview(listener);
		}
	}
	return err;
}
#if !defined __linux
bool ZVideoHelperWrap::IsValidItem(int64_t vbItem)
{
	bool isValid = false;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IVirtualBackgroundItem* pVBItem = (ZOOM_VIDEO_SDK_NAMESPACE::IVirtualBackgroundItem*)vbItem;
		if (!pVBItem)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (!pVideoHelper)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<ZOOM_VIDEO_SDK_NAMESPACE::IVirtualBackgroundItem*>* pVBItemList = pVideoHelper->getVirtualBackgroundItemList();
		if (!pVBItemList)
		{
			break;
		}
		for (int i = 0; i < pVBItemList->GetCount(); i++)
		{
			IVirtualBackgroundItem* pVBItemTemp = pVBItemList->GetItem(i);
			if (pVBItemTemp && pVBItem == pVBItemTemp)
			{
				isValid = true;
				break;
			}
		}
	} while (false);
	return isValid;
}
ZNZoomVideoSDKErrors ZVideoHelperWrap::AddVirtualBackgroundItem(ZoomSTRING imagePath, int64_t& vbItem)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	vbItem = 0;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (!pVideoHelper)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IVirtualBackgroundItem* pInfo = NULL;
		err = (ZNZoomVideoSDKErrors)pVideoHelper->addVirtualBackgroundItem(imagePath.c_str(), &pInfo);
		if (err != ZNZoomVideoSDKErrors_Success)
		{
			break;
		}
		vbItem = (int64_t)pInfo;
	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZVideoHelperWrap::RemoveVirtualBackgroundItem(int64_t imageItem)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (!pVideoHelper)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IVirtualBackgroundItem* pVBItem = (ZOOM_VIDEO_SDK_NAMESPACE::IVirtualBackgroundItem*)imageItem;
		err = (ZNZoomVideoSDKErrors)pVideoHelper->removeVirtualBackgroundItem(pVBItem);
	} while (false);
	return err;
}
ZNZoomVideoSDKErrors ZVideoHelperWrap::SetVirtualBackgroundItem(int64_t imageItem)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (!pVideoHelper)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IVirtualBackgroundItem* pVBItem = (ZOOM_VIDEO_SDK_NAMESPACE::IVirtualBackgroundItem*)imageItem;
		err = (ZNZoomVideoSDKErrors)pVideoHelper->setVirtualBackgroundItem(pVBItem);
	} while (false);
	return err;
}
void ZVideoHelperWrap::GetSelectedVirtualBackgroundItem(int64_t& selectedItem)
{
	selectedItem = 0;
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			return;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (!pVideoHelper)
		{
			return;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IVirtualBackgroundItem* pSelectedItem = pVideoHelper->getSelectedVirtualBackgroundItem();
		if (!pSelectedItem)
		{
			return;
		}
		selectedItem = (int64_t)pSelectedItem;

	} while (false);
}
void ZVideoHelperWrap::GetVirtualBackgroundItemList(com::electron::zoomvideo::sdk::proto::VBItemHandleList& vbItemList)
{
	do
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
		if (!pVideoSDK)
		{
			return;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKVideoHelper* pVideoHelper = pVideoSDK->getVideoHelper();
		if (!pVideoHelper)
		{
			return;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<ZOOM_VIDEO_SDK_NAMESPACE::IVirtualBackgroundItem*>* pVBItemList= pVideoHelper->getVirtualBackgroundItemList();
		if (!pVBItemList)
		{
			return;
		}

		for (int i = 0; i < pVBItemList->GetCount(); ++i)
		{
			IVirtualBackgroundItem* pVBItemTemp = pVBItemList->GetItem(i);
			if (!pVBItemTemp)
			{
				continue;
			}
			int64_t tmp = (int64_t)pVBItemTemp;
			vbItemList.add_vbitemhandle(tmp);
		}
	} while (false);
}
ZNZoomVideoSDKErrors ZVideoHelperWrap::GetVirtualBackgroundItemInfo(int64_t imageItem, com::electron::zoomvideo::sdk::proto::VBItemInfo& itemInfo)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	do
	{
		if (!IsValidItem(imageItem))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IVirtualBackgroundItem* pVBItem = (ZOOM_VIDEO_SDK_NAMESPACE::IVirtualBackgroundItem*)imageItem;
		ZoomSTRING temp_imageFilePath = pVBItem->getImageFilePath();
		itemInfo.set_imagefilepath(zs2s(temp_imageFilePath).c_str());

		ZoomSTRING temp_imageName = pVBItem->getImageName();
		itemInfo.set_imagename(zs2s(temp_imageName).c_str());

		itemInfo.set_vbtype((int)pVBItem->getType());
		itemInfo.set_canbedeleted(pVBItem->canVirtualBackgroundBeDeleted());
		err = ZNZoomVideoSDKErrors_Success;
	} while (false);
	
	return err;
}
#endif