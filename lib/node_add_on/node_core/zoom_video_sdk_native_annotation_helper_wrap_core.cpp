#include "zoom_video_sdk_native_annotation_helper_wrap_core.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"

extern ZNativeVideoSDKWrap _g_native_wrap;

ZAnnotationHelperWrap::ZAnnotationHelperWrap()
{
}
ZAnnotationHelperWrap::~ZAnnotationHelperWrap()
{
}
bool ZAnnotationHelperWrap::CanDoAnnotation()
{
	bool bRet = false;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAnnotationHelper* m_AnnotationHelper = _g_native_wrap.GetShareHelperWrap().GetAnnotationHelper();
		if (m_AnnotationHelper)
		{
			bRet = m_AnnotationHelper->canDoAnnotation();
		}
	}
	return bRet;
}
ZNZoomVideoSDKErrors ZAnnotationHelperWrap::StartAnnotation()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAnnotationHelper* m_AnnotationHelper = _g_native_wrap.GetShareHelperWrap().GetAnnotationHelper();
		if (m_AnnotationHelper)
		{
			err = (ZNZoomVideoSDKErrors)m_AnnotationHelper->startAnnotation();
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZAnnotationHelperWrap::StopAnnotation()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAnnotationHelper* m_AnnotationHelper = _g_native_wrap.GetShareHelperWrap().GetAnnotationHelper();
		if (m_AnnotationHelper)
		{
			err = (ZNZoomVideoSDKErrors)m_AnnotationHelper->stopAnnotation();
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZAnnotationHelperWrap::SetToolType(ZNZoomVideoSDKAnnotationToolType toolType)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAnnotationHelper* m_AnnotationHelper = _g_native_wrap.GetShareHelperWrap().GetAnnotationHelper();
		if (m_AnnotationHelper)
		{
			err = (ZNZoomVideoSDKErrors)m_AnnotationHelper->setToolType((ZoomVideoSDKAnnotationToolType)toolType);
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZAnnotationHelperWrap::GetToolType(ZNZoomVideoSDKAnnotationToolType& zn_toolType)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAnnotationHelper* m_AnnotationHelper = _g_native_wrap.GetShareHelperWrap().GetAnnotationHelper();
		if (m_AnnotationHelper)
		{
			ZoomVideoSDKAnnotationToolType sdk_toolType = ZoomVideoSDKAnnotationToolType_None;
			err = (ZNZoomVideoSDKErrors)m_AnnotationHelper->getToolType(sdk_toolType);
			if (ZNZoomVideoSDKErrors_Success == err)
			{
				zn_toolType = (ZNZoomVideoSDKAnnotationToolType)sdk_toolType;
			}
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZAnnotationHelperWrap::SetToolColor(unsigned long color)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAnnotationHelper* m_AnnotationHelper = _g_native_wrap.GetShareHelperWrap().GetAnnotationHelper();
		if (m_AnnotationHelper)
		{
			err = (ZNZoomVideoSDKErrors)m_AnnotationHelper->setToolColor(color);
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZAnnotationHelperWrap::GetToolColor(unsigned long& zn_color)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAnnotationHelper* m_AnnotationHelper = _g_native_wrap.GetShareHelperWrap().GetAnnotationHelper();
		if (m_AnnotationHelper)
		{
			unsigned long sdk_toolColor = 0;
			err = (ZNZoomVideoSDKErrors)m_AnnotationHelper->getToolColor(sdk_toolColor);
			if (ZNZoomVideoSDKErrors_Success == err)
			{
				zn_color = sdk_toolColor;
			}
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZAnnotationHelperWrap::SetToolWidth(long lineWidth)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAnnotationHelper* m_AnnotationHelper = _g_native_wrap.GetShareHelperWrap().GetAnnotationHelper();
		if (m_AnnotationHelper)
		{
			err = (ZNZoomVideoSDKErrors)m_AnnotationHelper->setToolWidth(lineWidth);
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZAnnotationHelperWrap::GetToolWidth(long& zn_lineWidth)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAnnotationHelper* m_AnnotationHelper = _g_native_wrap.GetShareHelperWrap().GetAnnotationHelper();
		if (m_AnnotationHelper)
		{
			long sdk_toolWidth = 0;
			err = (ZNZoomVideoSDKErrors)m_AnnotationHelper->getToolWidth(sdk_toolWidth);
			if (ZNZoomVideoSDKErrors_Success == err)
			{
				zn_lineWidth = sdk_toolWidth;
			}
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZAnnotationHelperWrap::Clear(ZNZoomVideoSDKAnnotationClearType clearType)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAnnotationHelper* m_AnnotationHelper = _g_native_wrap.GetShareHelperWrap().GetAnnotationHelper();
		if (m_AnnotationHelper)
		{
			err = (ZNZoomVideoSDKErrors)m_AnnotationHelper->clear((ZoomVideoSDKAnnotationClearType)clearType);
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZAnnotationHelperWrap::Undo()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAnnotationHelper* m_AnnotationHelper = _g_native_wrap.GetShareHelperWrap().GetAnnotationHelper();
		if (m_AnnotationHelper)
		{
			err = (ZNZoomVideoSDKErrors)m_AnnotationHelper->undo();
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZAnnotationHelperWrap::Redo()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
	if (pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKAnnotationHelper* m_AnnotationHelper = _g_native_wrap.GetShareHelperWrap().GetAnnotationHelper();
		if (m_AnnotationHelper)
		{
			err = (ZNZoomVideoSDKErrors)m_AnnotationHelper->redo();
		}
	}
	return err;
}
