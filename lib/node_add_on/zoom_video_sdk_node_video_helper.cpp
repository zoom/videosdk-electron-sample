#include "zoom_video_sdk_node_video_helper.h"
#include "zoom_video_sdk_node_video_raw_data.h"

ZoomVideoNodeVideoHelperWrap::ZoomVideoNodeVideoHelperWrap()
{
	
}

ZoomVideoNodeVideoHelperWrap::~ZoomVideoNodeVideoHelperWrap()
{
	
}
void ZoomVideoNodeVideoHelperWrap::StartVideo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();

	ZNZoomVideoSDKErrors err = _g_native_wrap.GetVideoHelperWrap().StartVideo();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeVideoHelperWrap::StopVideo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();

	ZNZoomVideoSDKErrors err = _g_native_wrap.GetVideoHelperWrap().StopVideo();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeVideoHelperWrap::SpotLightVideo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::SpotLightVideoParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::SpotLightVideoParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		if (!proto_param.has_user())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		com::electron::zoomvideo::sdk::proto::VideoSDKUser _User = proto_param.user();
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* zn_pUser = (ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser*)_User.p_user();

		err = _g_native_wrap.GetVideoHelperWrap().SpotLightVideo(zn_pUser);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeVideoHelperWrap::UnSpotLightVideo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::UnSpotLightVideoParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::UnSpotLightVideoParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		if (!proto_param.has_user())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		com::electron::zoomvideo::sdk::proto::VideoSDKUser _User = proto_param.user();
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* zn_pUser = (ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser*)_User.p_user();

		err = _g_native_wrap.GetVideoHelperWrap().UnSpotLightVideo(zn_pUser);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeVideoHelperWrap::UnSpotlightAllVideos(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();

	ZNZoomVideoSDKErrors err = _g_native_wrap.GetVideoHelperWrap().UnSpotlightAllVideos();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeVideoHelperWrap::GetSpotlightedVideoUserList(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	
	v8::Isolate* isolate = args.GetIsolate();

	com::electron::zoomvideo::sdk::proto::UserList _spotlightedUsers;
	_g_native_wrap.GetVideoHelperWrap().GetSpotlightedVideoUserList(_spotlightedUsers);
	size_t _size = _spotlightedUsers.ByteSize();
	auto array_buf = v8::ArrayBuffer::New(isolate, _size);
	char* char_temp_param = nullptr;
	size_t sz_temp_param = 0;
	fnGetRawArrayBufferPtr pGetRawArrayBufferPtr = NULL;
	pGetRawArrayBufferPtr = ZoomNodeAPIUtilHelper::GetInst().m_fnGetRawArrayBufferPtr;
	if (!pGetRawArrayBufferPtr)
	{
		return;
	}
	pGetRawArrayBufferPtr(array_buf, (void**)(&char_temp_param), sz_temp_param);
	_spotlightedUsers.SerializeToArray(char_temp_param, _size);
	v8::Local<v8::Uint8Array> uint8_array_buf = v8::Uint8Array::New(array_buf, 0, _size);
	
	args.GetReturnValue().Set(uint8_array_buf);
}
void ZoomVideoNodeVideoHelperWrap::RotateMyVideo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bRotate = false;
	do
	{
		com::electron::zoomvideo::sdk::proto::RotateMyVideoParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::RotateMyVideoParams >(args, proto_param))
		{
			break;
		}

		if (!proto_param.has_zn_rotation())
		{
			break;
		}

		ZNVideoRotation zn_rotation = (ZNVideoRotation)proto_param.zn_rotation();
		zn_bRotate = _g_native_wrap.GetVideoHelperWrap().RotateMyVideo(zn_rotation);
	} while (false);
	
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bRotate);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeVideoHelperWrap::SwitchCamera(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bSucc = _g_native_wrap.GetVideoHelperWrap().SwitchCamera();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bSucc);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeVideoHelperWrap::SelectCamera(const v8::FunctionCallbackInfo<v8::Value>& args) {

	v8::Isolate* isolate = args.GetIsolate();
	bool b_Succ = false;
	do
	{
		com::electron::zoomvideo::sdk::proto::SelectCameraParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::SelectCameraParams >(args, proto_param))
		{
			break;
		}

		if (!proto_param.has_zn_deviceid())
		{
			break;
		}

		ZoomSTRING zn_deviceID;
		zn_deviceID = s2zs(proto_param.zn_deviceid());

		b_Succ = _g_native_wrap.GetVideoHelperWrap().SelectCamera(zn_deviceID);
	} while (false);
	
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, b_Succ);
	args.GetReturnValue().Set(bret);
}
#if (!defined __linux)
void ZoomVideoNodeVideoHelperWrap::EnableMultiStreamVideo(const v8::FunctionCallbackInfo<v8::Value>& args) {

	v8::Isolate* isolate = args.GetIsolate();
	bool b_Succ = false;
	do
	{
		com::electron::zoomvideo::sdk::proto::EnableMultiStreamVideoParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::EnableMultiStreamVideoParams >(args, proto_param))
		{
			break;
		}

		if (!proto_param.has_deviceid())
		{
			break;
		}

		ZoomSTRING zn_deviceID;
		zn_deviceID = s2zs(proto_param.deviceid());

		b_Succ = _g_native_wrap.GetVideoHelperWrap().EnableMultiStreamVideo(zn_deviceID);
	} while (false);
	
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, b_Succ);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeVideoHelperWrap::DisableMultiStreamVideo(const v8::FunctionCallbackInfo<v8::Value>& args) {

	v8::Isolate* isolate = args.GetIsolate();
	bool b_Succ = false;
	do
	{
		com::electron::zoomvideo::sdk::proto::DisableMultiStreamVideoParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::DisableMultiStreamVideoParams >(args, proto_param))
		{
			break;
		}

		if (!proto_param.has_deviceid())
		{
			break;
		}

		ZoomSTRING zn_deviceID;
		zn_deviceID = s2zs(proto_param.deviceid());

		b_Succ = _g_native_wrap.GetVideoHelperWrap().DisableMultiStreamVideo(zn_deviceID);
	} while (false);
	
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, b_Succ);
	args.GetReturnValue().Set(bret);
}
#endif
void ZoomVideoNodeVideoHelperWrap::GetNumberOfCameras(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	int zn_CamNum = _g_native_wrap.GetVideoHelperWrap().GetNumberOfCameras();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, zn_CamNum);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeVideoHelperWrap::GetCameraList(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	com::electron::zoomvideo::sdk::proto::GetCameraList _CameraLst;
	_g_native_wrap.GetVideoHelperWrap().GetCameraList(_CameraLst);
	size_t _size = _CameraLst.ByteSize();
	auto array_buf = v8::ArrayBuffer::New(isolate, _size);
	char* char_temp_param = nullptr;
	size_t sz_temp_param = 0;
	fnGetRawArrayBufferPtr pGetRawArrayBufferPtr = NULL;
	pGetRawArrayBufferPtr = ZoomNodeAPIUtilHelper::GetInst().m_fnGetRawArrayBufferPtr;
	if (!pGetRawArrayBufferPtr)
	{
		return;
	}
	pGetRawArrayBufferPtr(array_buf, (void**)(&char_temp_param), sz_temp_param);
	_CameraLst.SerializeToArray(char_temp_param, _size);
	v8::Local<v8::Uint8Array> uint8_array_buf = v8::Uint8Array::New(array_buf, 0, _size);

	args.GetReturnValue().Set(uint8_array_buf);
}
void ZoomVideoNodeVideoHelperWrap::CanControlCamera(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	bool zn_bCan = false;
	ZNZoomVideoSDKErrors err = _g_native_wrap.GetVideoHelperWrap().CanControlCamera(zn_bCan);
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "bCan", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_bCan));

	args.GetReturnValue().Set(node);
}
void ZoomVideoNodeVideoHelperWrap::TurnCameraLeft(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	com::electron::zoomvideo::sdk::proto::LocalCameraCtrlTurnLeftParams proto_param;
	if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::LocalCameraCtrlTurnLeftParams >(args, proto_param))
	{
		return;
	}
	unsigned int zn_range = 50;
	if (proto_param.has_range())
	{
		zn_range = (ZNVideoRotation)proto_param.range();
	}

	ZNZoomVideoSDKErrors err = _g_native_wrap.GetVideoHelperWrap().TurnCameraLeft(zn_range);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeVideoHelperWrap::TurnCameraRight(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	com::electron::zoomvideo::sdk::proto::LocalCameraCtrlTurnRightParams proto_param;
	if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::LocalCameraCtrlTurnRightParams >(args, proto_param))
	{
		return;
	}
	unsigned int zn_range = 50;
	if (proto_param.has_range())
	{
		zn_range = (ZNVideoRotation)proto_param.range();
	}

	ZNZoomVideoSDKErrors err = _g_native_wrap.GetVideoHelperWrap().TurnCameraRight(zn_range);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeVideoHelperWrap::TurnCameraUp(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	com::electron::zoomvideo::sdk::proto::LocalCameraCtrlTurnUpParams proto_param;
	if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::LocalCameraCtrlTurnUpParams >(args, proto_param))
	{
		return;
	}
	unsigned int zn_range = 50;
	if (proto_param.has_range())
	{
		zn_range = (ZNVideoRotation)proto_param.range();
	}

	ZNZoomVideoSDKErrors err = _g_native_wrap.GetVideoHelperWrap().TurnCameraUp(zn_range);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeVideoHelperWrap::TurnCameraDown(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	com::electron::zoomvideo::sdk::proto::LocalCameraCtrlTurnDownParams proto_param;
	if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::LocalCameraCtrlTurnDownParams >(args, proto_param))
	{
		return;
	}
	unsigned int zn_range = 50;
	if (proto_param.has_range())
	{
		zn_range = (ZNVideoRotation)proto_param.range();
	}

	ZNZoomVideoSDKErrors err = _g_native_wrap.GetVideoHelperWrap().TurnCameraDown(zn_range);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeVideoHelperWrap::ZoomCameraIn(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	com::electron::zoomvideo::sdk::proto::LocalCameraCtrlZoomInParams proto_param;
	if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::LocalCameraCtrlZoomInParams >(args, proto_param))
	{
		return;
	}
	unsigned int zn_range = 50;
	if (proto_param.has_range())
	{
		zn_range = (ZNVideoRotation)proto_param.range();
	}

	ZNZoomVideoSDKErrors err = _g_native_wrap.GetVideoHelperWrap().ZoomCameraIn(zn_range);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeVideoHelperWrap::ZoomCameraOut(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	com::electron::zoomvideo::sdk::proto::LocalCameraCtrlZoomOutParams proto_param;
	if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::LocalCameraCtrlZoomOutParams >(args, proto_param))
	{
		return;
	}
	unsigned int zn_range = 50;
	if (proto_param.has_range())
	{
		zn_range = (ZNVideoRotation)proto_param.range();
	}

	ZNZoomVideoSDKErrors err = _g_native_wrap.GetVideoHelperWrap().ZoomCameraOut(zn_range);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeVideoHelperWrap::SetVideoQualityPreference(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	com::electron::zoomvideo::sdk::proto::SetVideoQualityPreferenceParams proto_param;
	if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::SetVideoQualityPreferenceParams >(args, proto_param))
	{
		return;
	}
	ZNZoomVideoSDKVideoPreferenceSetting zn_preference_setting;
	if (proto_param.has_mode())
	{
		zn_preference_setting.mode = (ZNZoomVideoSDKVideoPreferenceMode)proto_param.mode();
	}
	if (proto_param.has_minimum_frame_rate())
	{
		zn_preference_setting.minimum_frame_rate = proto_param.minimum_frame_rate();
	}
	if (proto_param.has_maximum_frame_rate())
	{
		zn_preference_setting.maximum_frame_rate = proto_param.maximum_frame_rate();
	}

	ZNZoomVideoSDKErrors err = _g_native_wrap.GetVideoHelperWrap().SetVideoQualityPreference(zn_preference_setting);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeVideoHelperWrap::StartVideoPreview(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	
	do
	{
		com::electron::zoomvideo::sdk::proto::StartVideoPreviewParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::StartVideoPreviewParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_zn_recv_handle() ||
			!proto_param.has_cameradeviceid())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		unsigned long long zn_recv_handle = (unsigned long long)proto_param.zn_recv_handle();
		ZoomSTRING zn_deviceID;
		zn_deviceID = s2zs(proto_param.cameradeviceid());

		std::map<unsigned long long, ZNativeVideoSDKVideoRawDataHelper*>::iterator iter = ZoomVideoNodeRawDataHelperMgr::GetInst().m_videorawdatahelper_map.find(zn_recv_handle);
		if (ZoomVideoNodeRawDataHelperMgr::GetInst().m_videorawdatahelper_map.end() == iter)
		{
			ZNativeVideoSDKVideoRawDataHelper* pRawDataHelper = new ZNativeVideoSDKVideoRawDataHelper;
			if (pRawDataHelper)
			{
				std::pair <std::map<unsigned long long, ZNativeVideoSDKVideoRawDataHelper*>::iterator, bool> ret_pair = ZoomVideoNodeRawDataHelperMgr::GetInst().m_videorawdatahelper_map.insert(std::make_pair(zn_recv_handle, pRawDataHelper));
				if (!ret_pair.second)
				{
					break;
				}
				iter = ret_pair.first;
			}
			else
			{
				break;
			}
		}

		ZNativeVideoSDKVideoRawDataHelper* pTempHelper = (*iter).second;
		if (pTempHelper)
		{
			pTempHelper->SetRecvHandle(zn_recv_handle);
			err = _g_native_wrap.GetVideoHelperWrap().StartVideoPreview(dynamic_cast<ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRawDataPipeDelegate*>(pTempHelper), zn_deviceID);
		}
		else
		{
			break;
		}

	} while (false);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeVideoHelperWrap::StopVideoPreview(const v8::FunctionCallbackInfo<v8::Value>& args)
{

	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	
	do
	{
		com::electron::zoomvideo::sdk::proto::StopVideoPreviewParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::StopVideoPreviewParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_zn_recv_handle())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		unsigned long long zn_recv_handle = (unsigned long long)proto_param.zn_recv_handle();
		std::map<unsigned long long, ZNativeVideoSDKVideoRawDataHelper*>::iterator iter = ZoomVideoNodeRawDataHelperMgr::GetInst().m_videorawdatahelper_map.find(zn_recv_handle);
		if (ZoomVideoNodeRawDataHelperMgr::GetInst().m_videorawdatahelper_map.end() == iter)
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		ZNativeVideoSDKVideoRawDataHelper* pTempHelper = (*iter).second;
		if (pTempHelper)
		{
			err = _g_native_wrap.GetVideoHelperWrap().StopVideoPreview(dynamic_cast<ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRawDataPipeDelegate*>(pTempHelper));
			ZoomVideoNodeSDKDelayGC::GetInst().AddToPotentialDeleteList((unsigned long long)pTempHelper);
			ZoomVideoNodeRawDataHelperMgr::GetInst().m_videorawdatahelper_map.erase(zn_recv_handle);
		}
		else
		{
			break;
		}

	} while (false);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
#if !defined __linux
void ZoomVideoNodeVideoHelperWrap::AddVirtualBackgroundItem(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::AddVirtualBackgroundItemParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::AddVirtualBackgroundItemParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
		}

		if (!proto_param.has_imagepath())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
		}

		ZoomSTRING zn_imagePath;
		zn_imagePath = s2zs(proto_param.imagepath());

		int64_t zn_vbItem = 0;
		if (err == ZNZoomVideoSDKErrors_Success)
		{
			err = _g_native_wrap.GetVideoHelperWrap().AddVirtualBackgroundItem(zn_imagePath, zn_vbItem);
		}

		node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
		node->Set(context, v8::String::NewFromUtf8(isolate, "vbItemHandle", v8::NewStringType::kInternalized).ToLocalChecked(), v8::BigInt::New(isolate, zn_vbItem));
	} while (false);
	
	args.GetReturnValue().Set(node);
}
void ZoomVideoNodeVideoHelperWrap::RemoveVirtualBackgroundItem(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::RemoveVirtualBackgroundItemParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::RemoveVirtualBackgroundItemParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		if (!proto_param.has_vbitemhandle())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		err = _g_native_wrap.GetVideoHelperWrap().RemoveVirtualBackgroundItem(proto_param.vbitemhandle());
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeVideoHelperWrap::GetVirtualBackgroundItemList(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	com::electron::zoomvideo::sdk::proto::VBItemHandleList _VBItemLst;
	_g_native_wrap.GetVideoHelperWrap().GetVirtualBackgroundItemList(_VBItemLst);
	size_t _size = _VBItemLst.ByteSize();
	auto array_buf = v8::ArrayBuffer::New(isolate, _size);
	char* char_temp_param = nullptr;
	size_t sz_temp_param = 0;
	fnGetRawArrayBufferPtr pGetRawArrayBufferPtr = NULL;
	pGetRawArrayBufferPtr = ZoomNodeAPIUtilHelper::GetInst().m_fnGetRawArrayBufferPtr;
	if (!pGetRawArrayBufferPtr)
	{
		return;
	}
	pGetRawArrayBufferPtr(array_buf, (void**)(&char_temp_param), sz_temp_param);
	_VBItemLst.SerializeToArray(char_temp_param, _size);
	v8::Local<v8::Uint8Array> uint8_array_buf = v8::Uint8Array::New(array_buf, 0, _size);

	args.GetReturnValue().Set(uint8_array_buf);
}
void ZoomVideoNodeVideoHelperWrap::SetVirtualBackgroundItem(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::SetVirtualBackgroundItemParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::SetVirtualBackgroundItemParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		if (!proto_param.has_vbitemhandle())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		err = _g_native_wrap.GetVideoHelperWrap().SetVirtualBackgroundItem(proto_param.vbitemhandle());
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeVideoHelperWrap::GetSelectedVirtualBackgroundItem(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();

	int64_t _VBItem = 0;
	_g_native_wrap.GetVideoHelperWrap().GetSelectedVirtualBackgroundItem(_VBItem);
	v8::Local<v8::BigInt> ret = v8::BigInt::New(isolate, _VBItem);

	args.GetReturnValue().Set(ret);
}
void ZoomVideoNodeVideoHelperWrap::GetVirtualBackgroundItemInfo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	do
	{
		com::electron::zoomvideo::sdk::proto::GetVirtualBackgroundItemInfoParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::GetVirtualBackgroundItemInfoParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_vbitemhandle())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		com::electron::zoomvideo::sdk::proto::VBItemInfo zn_vbItemInfo;
		err = _g_native_wrap.GetVideoHelperWrap().GetVirtualBackgroundItemInfo(proto_param.vbitemhandle(), zn_vbItemInfo);
		if (err != ZNZoomVideoSDKErrors_Success)
		{
			break;
		}
		size_t _size = zn_vbItemInfo.ByteSize();
		auto array_buf = v8::ArrayBuffer::New(isolate, _size);
		char* char_temp_param = nullptr;
		size_t sz_temp_param = 0;
		fnGetRawArrayBufferPtr pGetRawArrayBufferPtr = NULL;
		pGetRawArrayBufferPtr = ZoomNodeAPIUtilHelper::GetInst().m_fnGetRawArrayBufferPtr;
		if (!pGetRawArrayBufferPtr)
		{
			err = ZNZoomVideoSDKErrors_Internal_Error;
			break;
		}
		pGetRawArrayBufferPtr(array_buf, (void**)(&char_temp_param), sz_temp_param);
		zn_vbItemInfo.SerializeToArray(char_temp_param, _size);
		v8::Local<v8::Uint8Array> uint8_array_buf = v8::Uint8Array::New(array_buf, 0, _size);
		node->Set(context, v8::String::NewFromUtf8(isolate, "vbItemInfo", v8::NewStringType::kInternalized).ToLocalChecked(), uint8_array_buf);
	} while (false);

	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	args.GetReturnValue().Set(node);
}

#endif
