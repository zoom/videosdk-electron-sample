#ifndef _ZOOM_VIDEO_SDK_NATIVE_SHARE_PREPROCESSOR_HELPER_H_
#define _ZOOM_VIDEO_SDK_NATIVE_SHARE_PREPROCESSOR_HELPER_H_

#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_singleton_wrap_class.h"


class ZSharePreprocessorHelperWrap : public ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKSharePreprocessor
{
public:
	ZSharePreprocessorHelperWrap();
	virtual ~ZSharePreprocessorHelperWrap();

	void onCapturedRawDataReceived(YUVRawDataI420* pRawData, ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKSharePreprocessSender* pSender);
	void onShareStopped();

	ZNZoomVideoSDKErrors StartShareWithPreprocessing(ZNZoomVideoSDKSharePreprocessType zn_type, ZoomSTRING zn_handle, ZoomSTRING zn_monitorid, uint32_t processID, ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKSharePreprocessor* preprocessor);
	ZNZoomVideoSDKErrors SendPreprocessedData(char* buffer, std::string dataHandle);

private:
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKSharePreprocessSender* m_pSender;
	char* m_pBuffer;
	YUVRawDataI420* m_pRawData;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
