#pragma once

#include "zoom_video_sdk_native_sdk_wrap_core_def.h"
#include "zoom_video_sdk_sinks_wrap_class.h"

class ZAnnotationHelperWrap
{
public:
	ZAnnotationHelperWrap();
	virtual ~ZAnnotationHelperWrap();

	bool CanDoAnnotation();
	ZNZoomVideoSDKErrors StartAnnotation();
	ZNZoomVideoSDKErrors StopAnnotation();
	ZNZoomVideoSDKErrors SetToolType(ZNZoomVideoSDKAnnotationToolType toolType);
	ZNZoomVideoSDKErrors GetToolType(ZNZoomVideoSDKAnnotationToolType& zn_toolType);
	ZNZoomVideoSDKErrors SetToolColor(unsigned long color);
	ZNZoomVideoSDKErrors GetToolColor(unsigned long& zn_color);
	ZNZoomVideoSDKErrors SetToolWidth(long lineWidth);
	ZNZoomVideoSDKErrors GetToolWidth(long& zn_lineWidth);
	ZNZoomVideoSDKErrors Clear(ZNZoomVideoSDKAnnotationClearType clearType);
	ZNZoomVideoSDKErrors Undo();
	ZNZoomVideoSDKErrors Redo();
};
