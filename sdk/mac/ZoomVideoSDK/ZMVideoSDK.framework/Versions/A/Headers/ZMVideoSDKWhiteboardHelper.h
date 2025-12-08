/**
 * @file ZMVideoSDKWhiteboardHelper.h
 * @brief Header file for whiteboard functionality in Zoom Video SDK sessions.
 */
#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZMVideoSDKWhiteboardHelper
 * @brief Helper class for managing whiteboard functionality in Zoom Video SDK sessions.
 * @note IMPORTANT: To prevent whiteboard data loss, developers must call \link exportWhiteboard: \endlink before the following scenarios:
 *       - Closing the whiteboard (calling \link stopShareWhiteboard \endlink)
 *       - Leaving the session (calling \link ZMVideoSDK::leaveSession \endlink)
 *       - Joining a sub-session (calling \link SubSessionKit::joinSubSession \endlink or \link SubSessionKit::joinSubSessionByUserRequest \endlink)
 *       KNOWN ISSUE: Data loss is unavoidable in crash or failover scenarios. To minimize potential data loss, implement periodic auto-save functionality using \link exportWhiteboard: \endlink.
 */
@interface ZMVideoSDKWhiteboardHelper : NSObject

/**
 * @brief Displays the whiteboard view when someone is sharing the whiteboard.
 * @param window The owner window for the whiteboard display. Cannot be nil.
 * @return ZMVideoSDKErrors_Success if successful, otherwise an error code.
 * @note Call this method when you want to view a whiteboard that is being shared by another participant.
 * @note The whiteboard view should be hidden when whiteboard sharing is stopped, or the user who is sharing the whiteboard leaves session, or the session is failover for ZMVideoSDKErrors_Session_Reconnecting.
 */
- (ZMVideoSDKErrors)subscribeWhiteboard:(NSWindow *)window;

/**
 * @brief Hides the whiteboard sharing view when someone is sharing the whiteboard.
 * @return ZMVideoSDKErrors_Success if successful, otherwise an error code.
 * @note Call this method when you no longer want to view the shared whiteboard.
 */
- (ZMVideoSDKErrors)unSubscribeWhiteboard;

/**
 * @brief Checks whether the current user can start whiteboard sharing. Only the host can start whiteboard sharing.
 * @return YES if the user can start whiteboard sharing, otherwise NO.
 */
- (BOOL)canStartShareWhiteboard;

/**
 * @brief Checks whether the current user can stop whiteboard sharing.
 * @return YES if the user can stop whiteboard sharing, otherwise NO.
 * @note This method typically returns YES if the user is currently sharing a whiteboard.
 */
- (BOOL)canStopShareWhiteboard;

/**
 * @brief Set the position of the whiteboard web view window.
 * @param point The position coordinates (x, y) for the whiteboard window. Use (-1, -1) to center
 *              the window on the screen where the owner window is located.
 * @return ZMVideoSDKErrors_Success if successful, otherwise an error code.
 */
- (ZMVideoSDKErrors)setWhiteboardViewPos:(NSPoint)point;

/**
 * @brief Set the size of the whiteboard web view window.
 * @param size The width and height dimensions for the whiteboard window. Use (0, 0) to use
 *             the default window size.
 * @return ZMVideoSDKErrors_Success if successful, otherwise an error code.
 */
- (ZMVideoSDKErrors)setWhiteboardViewSize:(NSSize)size;

/**
 * @brief Checks whether another user is currently sharing a whiteboard.
 * @return YES if another user is sharing a whiteboard, otherwise NO.
 * @note This method helps determine if there is active whiteboard content to view.
 */
- (BOOL)isOtherSharingWhiteboard;

/**
 * @brief Starts whiteboard sharing in the session.
 * @return @c ZMVideoSDKErrors_Success if successful, otherwise an error code.
 * @note Ensure that whiteboard sharing is enabled and the user has permission before calling this method.
 *       Use \link canStartShareWhiteboard \endlink to check availability first.
 */
- (ZMVideoSDKErrors)startShareWhiteboard;

/**
 * @brief Stops whiteboard sharing in the session.
 * @return @c ZMVideoSDKErrors_Success if successful, otherwise an error code.
 * @note This will stop the whiteboard sharing and hide it from other participants.
 *       Use \link canStopShareWhiteboard \endlink to check if stopping is allowed.
 */
- (ZMVideoSDKErrors)stopShareWhiteboard;



/**
 * @brief Exports the currently shared whiteboard.
 * @param format The export format.
 * @return @c ZMVideoSDKErrors_Success if successful, otherwise an error code.
 * @note The exported data is delivered via \link ZMVideoSDKDelegate::onWhiteboardExported:data:dataLength: \endlink. Be sure to implement this callback in your delegate to handle the exported data.
 * @warning During the export process (before receiving the \link ZMVideoSDKDelegate::onWhiteboardExported:data:dataLength: \endlink callback), calling \link stopShareWhiteboard \endlink will cause data loss. Wait until the export is complete before stopping the whiteboard share.
 */
- (ZMVideoSDKErrors)exportWhiteboard:(ZMVideoSDKExportFormat)format;
@end

NS_ASSUME_NONNULL_END
