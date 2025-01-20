#ifndef _ZOOM_INSTANT_NATIVE_AUDIO_RAW_DATA_HELPER_H_
#define _ZOOM_INSTANT_NATIVE_AUDIO_RAW_DATA_HELPER_H_

#include "zoom_video_sdk_node_common_include.h"
//#include "zoom_video_sdk_native_sdk_wrap_core.h"
#include "zoom_video_sdk_singleton_wrap_class.h"
#include <iostream>
#include <string>
#include "export_h/helpers/zoom_video_sdk_video_source_helper_interface.h"

class ZNativeInstantVideoSourcePreProcessor : public ZOOM_INSTANT_SDK_NAMESPACE::IZoomInstantSDKVideoSourcePreProcessor
{
public:
	
	ZNativeInstantVideoSourcePreProcessor();
	virtual ~ZNativeInstantVideoSourcePreProcessor();

	virtual void onPreProcessRawData(YUVProcessDataI420* rawData);
	
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//class ZNativeInstantVideoSource : public ZOOM_INSTANT_SDK_NAMESPACE::IZoomInstantSDKVideoSource
//{
//public:
//
//	ZNativeInstantVideoSource();
//	virtual ~ZNativeInstantVideoSource();
//
//	virtual	void onInitialize(ZOOM_INSTANT_SDK_NAMESPACE::IZoomInstantSDKVideoSender* sender, ZOOM_INSTANT_SDK_NAMESPACE::IZoomInstantSDKVideoCapabilityHelper* helper);
//	virtual void onPropertyChange(ZOOM_INSTANT_SDK_NAMESPACE::IZoomInstantSDKVideoCapability* item);
//	virtual void onStartSend();
//	virtual void onStopSend();
//	virtual void onUninitialized();
//
//	ZOOM_INSTANT_SDK_NAMESPACE::IZoomInstantSDKVideoSender* m_pVideoSender;
//	ZOOM_INSTANT_SDK_NAMESPACE::IZoomInstantSDKVideoCapabilityHelper* m_pVideoCapabilityHelper;
//
//};



#endif
