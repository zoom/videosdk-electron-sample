/**
* @file zoom_video_sdk_broadcast_streaming_controller_interface.h
* @brief broadcast streaming controller
*
*/

#ifndef _ZOOM_VIDEO_SDK_BROADCAST_STREAMING_CONTROLLER_INTERFACE_H_
#define _ZOOM_VIDEO_SDK_BROADCAST_STREAMING_CONTROLLER_INTERFACE_H_
#include "zoom_video_sdk_def.h"
#include "zoom_video_sdk_vector_interface.h"

BEGIN_ZOOM_VIDEO_SDK_NAMESPACE

/**
 * @brief Enumerations of broadcast control status.
 */
enum ZoomVideoSDKBroadcastControlStatus
{
	/** Initialized status. */
	ZoomVideoSDKBroadcastControlStatus_None,

	/** Broadcast is starting. */
	ZoomVideoSDKBroadcastControlStatus_Starting,
	
	/** Broadcast is started. */
	ZoomVideoSDKBroadcastControlStatus_Started,
	
	/** Broadcast is stopping. */
	ZoomVideoSDKBroadcastControlStatus_Stopping,
	
	/** Broadcast is stopped. */
	ZoomVideoSDKBroadcastControlStatus_Stopped
};

/**
 * @brief Broadcast streaming controller interface.
 */
class IZoomVideoSDKBroadcastStreamingController
{
public:
	virtual ~IZoomVideoSDKBroadcastStreamingController() {}

	/**
	 * @brief Checks if the session supports broadcast streaming.
	 * @return true if supported; false if not
	 */
	virtual bool isBroadcastStreamingSupported() = 0;

	/**
	 * @brief Checks if the user has permission to start a broadcast.
	 * @return true if allowed; false if not
	 */
	virtual bool canStartBroadcast() = 0;

	/**
	 * @brief Start broadcast streaming asynchronously. The result is notified via the callback 'onStartBroadcastResponse'.
	 * @return {@link ZoomVideoSDKErrors#ZoomVideoSDKErrors_Success} if the function succeeds; otherwise, the method failed.
	 */
	virtual ZoomVideoSDKErrors startBroadcast() = 0;

	/**
	 * @brief Stops broadcast streaming asynchronously. The result is notified via the callback 'onStopBroadcastResponse'.
	 * @param channelID The broadcast streaming channel ID. 
	 * @return {@link ZoomVideoSDKErrors#ZoomVideoSDKErrors_Success} if the function succeeds; otherwise, the method is failed.
	 */
	virtual ZoomVideoSDKErrors stopBroadcast(const zchar_t* channelID) = 0;

	/**
	 * @brief Gets broadcast status asynchronously. The result is notified via the callback 'onGetBroadcastControlStatus'.
	 * @param channelID The broadcast streaming channel ID. 
	 * @return {@link ZoomVideoSDKErrors#ZoomVideoSDKErrors_Success} if the function succeeds. otherwise, the method is failed.
	 */
	virtual ZoomVideoSDKErrors getBroadcastStatus(const zchar_t* channelID) = 0;

};
END_ZOOM_VIDEO_SDK_NAMESPACE
#endif