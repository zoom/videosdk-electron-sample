#ifndef _ZOOM_VIDEO_SDK_NATIVE_VIDEO_RAW_DATA_HELPER_H_
#define _ZOOM_VIDEO_SDK_NATIVE_VIDEO_RAW_DATA_HELPER_H_

#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"
#include "zoom_video_sdk_singleton_wrap_class.h"


extern ZNativeVideoSDKWrap _g_native_wrap;
class ZNativeVideoSDKVideoRawDataHelper : public ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRawDataPipeDelegate
{
public:
	
	ZNativeVideoSDKVideoRawDataHelper();
	virtual ~ZNativeVideoSDKVideoRawDataHelper();

	virtual void onRawDataFrameReceived(YUVRawDataI420* data_);
	virtual void onRawDataStatusChanged(RawDataStatus status);
	virtual void onShareCursorDataReceived(ZoomVideoSDKShareCursorData info);
	unsigned long long GetRecvHandle() { return m_recv_handle;}
	void SetRecvHandle(unsigned long long recv_handle);
public:
	
	ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors Subscribe(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, unsigned long long recv_handle, ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKRawDataType rawDataType, ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKResolution resolution);
	ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors UnSubscribe(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKRawDataType rawDataType);

	ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors SubscribeMultiCameraStream(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, unsigned long long recv_handle, ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRawDataPipe* pPipe, ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKResolution resolution);
	ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors UnSubscribeMultiCameraStream(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRawDataPipe* pPipe);

private:
	unsigned long long m_recv_handle;
	ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKRawDataType m_rawdataType;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
