/**
 * @file zoom_video_sdk_rtms_helper_interface.h
 * @brief rtms helper
 */

#ifndef _ZOOM_VIDEO_SDK_RTMS_HELPER_INTERFACE_H_
#define _ZOOM_VIDEO_SDK_RTMS_HELPER_INTERFACE_H_
#include "zoom_video_sdk_def.h"

BEGIN_ZOOM_VIDEO_SDK_NAMESPACE

/**
 * @brief real-time media streams status.
 */
enum RealTimeMediaStreamsStatus
{
	/** No real-time media streams activity. */
	RealTimeMediaStreams_None,
	/** Real-time media streams has started. */
	RealTimeMediaStreams_Start,
	/** Real-time media streams has been paused. */
	RealTimeMediaStreams_Pause,
	/** Real-time media streams has been stopped. */
	RealTimeMediaStreams_Stop,
};

/**
 * @brief Failure reasons for RealTimeMediaStreams.
 */
enum RealTimeMediaStreamsFailReason
{
	/** Default value, no error (initial state) */
	RealTimeMediaStreamsFailReason_None,
	/** No users have subscribed to the RTMS */
	RealTimeMediaStreamsFailReason_NoSubscription,
	/** Failed to start the RTMS */
	RealTimeMediaStreamsFailReason_StartFail
};

class IZoomVideoSDKRTMSHelper
{
public:
	/**
	 * @brief Determine if the session supports the real-time media streams feature.
	 * @return True indicates the real-time media streams feature is supported, otherwise it is not.
	 */
	virtual bool isSupportRealTimeMediaStreams() = 0;

	/**
	 * @brief Checks if the current user meets the requirements to start real-time media streams.
	 * @note Only the host is permitted to start real-time media streams.
	 * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise it failed.
	 */
	virtual ZoomVideoSDKErrors canStartRealTimeMediaStreams() = 0;

	/**
	 * @brief Start real-time media streams.
	 * @note Call canStartRealTimeMediaStreams() first to verify permissions.
	 * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.
	 */
	virtual ZoomVideoSDKErrors startRealTimeMediaStreams() = 0;

	/**
	 * @brief Pause real-time media streams.	
	 * @note Can only be called after startRealTimeMediaStreams() has succeeded.
	 * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.
	 */
	virtual ZoomVideoSDKErrors pauseRealTimeMediaStreams() = 0;

	/**
	 * @brief Resume real-time media streams.
	 * @note Can only be called after pauseRealTimeMediaStreams() has been called.
	 * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.
	 */
	virtual ZoomVideoSDKErrors resumeRealTimeMediaStreams() = 0;

	/**
	 * @brief Stop real-time media streams.	
	 * @note Can be called when stream is in any active state.
	 * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.
	 */
	virtual ZoomVideoSDKErrors stopRealTimeMediaStreams() = 0;		
};
END_ZOOM_VIDEO_SDK_NAMESPACE

#endif
