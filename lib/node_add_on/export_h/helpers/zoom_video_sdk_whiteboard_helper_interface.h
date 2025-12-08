/**
 * @file zoom_video_sdk_whiteboard_helper_interface.h
 * @brief whiteboard helper
 */

#ifndef _ZOOM_VIDEO_SDK_WHITEBOARD_HELPER_INTERFACE_H_
#define _ZOOM_VIDEO_SDK_WHITEBOARD_HELPER_INTERFACE_H_
#include "zoom_video_sdk_def.h"

BEGIN_ZOOM_VIDEO_SDK_NAMESPACE

/**
 * @brief The whiteboard helper interface.
 * @note IMPORTANT: To prevent whiteboard data loss, developers must call \link exportWhiteboard \endlink before the following scenarios:
 *       - Closing the whiteboard (calling \link stopShareWhiteboard \endlink)
 *       - Leaving the session (calling \link IZoomVideoSDK::leaveSession \endlink)
 *       - Joining a sub-session (calling \link ISubSessionKit::joinSubSession \endlink or \link ISubSessionKit::joinSubSessionByUserRequest \endlink)
 *       KNOWN ISSUE: Data loss is unavoidable in crash or failover scenarios. To minimize potential data loss, implement periodic auto-save functionality using \link exportWhiteboard \endlink.
 */
class IZoomVideoSDKWhiteboardHelper
{
public:
	/**
	 * @brief Displays the whiteboard view when someone is sharing the whiteboard.
     * @param hOwner Specify the owner window handle. If the hOwner is nullptr, the owner window will be desktop window.
     * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed. For detailed error codes, see \link ZoomVideoSDKErrors \endlink enum.
     * @note The whiteboard view should be hidden when whiteboard sharing is stopped, or the user who is sharing the whiteboard leaves session, or the session is failover for Errors_Session_Reconncting.
     */
	virtual ZoomVideoSDKErrors subscribeWhiteboard(void* hOwner) = 0;

	/**
	 * @brief Hides the whiteboard sharing view when someone is sharing the whiteboard.
	 * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed. For detailed error codes, see \link ZoomVideoSDKErrors \endlink enum.
	 */
	virtual ZoomVideoSDKErrors unSubscribeWhiteboard() = 0;

	/**
	 * @brief Checks whether the current user can start whiteboard sharing. Only the host can start whiteboard sharing.
	 * @return true if the user can start whiteboard sharing, otherwise it returns false.
	 */
	virtual bool canStartShareWhiteboard() = 0;

	/**
	 * @brief Checks whether the current user can stop whiteboard sharing.
	 * @return true if the user can stop whiteboard sharing, otherwise it returns false.
	 */
	virtual bool canStopShareWhiteboard() = 0;

	/**
	 * @brief Starts whiteboard sharing in the session.
	 * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed. For detailed error codes, see \link ZoomVideoSDKErrors \endlink enum.
	 */
	virtual ZoomVideoSDKErrors startShareWhiteboard() = 0;

	/**
	 * @brief Stops whiteboard sharing in the session.
	 * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed. For detailed error codes, see \link ZoomVideoSDKErrors \endlink enum.
	 */
	virtual ZoomVideoSDKErrors stopShareWhiteboard() = 0;

	/**
	 * @brief Checks whether another user is currently sharing a whiteboard.
	 * @return true if another user is sharing whiteboard; otherwise it returns false.
	 */
	virtual bool isOtherSharingWhiteboard() = 0;



	/**
	 * @brief Exports the currently shared whiteboard.
	 * @param format The export format.
	 * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed. For detailed error codes, see \link ZoomVideoSDKErrors \endlink enum.
	 * @note The exported data is delivered via \link onWhiteboardExported \endlink. Be sure to implement this callback in your delegate to handle the exported data.
	 * @warning During the export process (before receiving the \link onWhiteboardExported \endlink callback), calling \link stopShareWhiteboard \endlink will cause data loss. Wait until the export is complete before stopping the whiteboard share.
	 */
	virtual ZoomVideoSDKErrors exportWhiteboard(ZoomVideoSDKExportFormat format) = 0;

	/**
	 * @brief Sets a custom icon for the whiteboard sharing content window.
	 * @param hResInstance A handle to the module that contains the icon resource.
	 * @param iconID The resource ID of the icon to used.
	 * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed. For detailed error codes, see \link ZoomVideoSDKErrors \endlink enum.
	 * @note This function should be called before joining a session if you want to use a custom icon.
	 */
	virtual ZoomVideoSDKErrors setCustomizedResIcon(void* hResInstance, unsigned int iconID) = 0;
};

END_ZOOM_VIDEO_SDK_NAMESPACE
#endif