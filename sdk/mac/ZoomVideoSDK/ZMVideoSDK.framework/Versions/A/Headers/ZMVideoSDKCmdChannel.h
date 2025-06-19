//

#import <Foundation/Foundation.h>

@class ZMVideoSDKUser;

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief The command channel allows users to send commands or data (such as plain text or a binary encoded into string) to other users in the same session.
 */
@interface ZMVideoSDKCmdChannel : NSObject
/**
 * @brief Send custom commands or data to other users in the current session.
 * @param commandContent the custom commands or data, represented in string format.
 * @param user An instance of ZMVideoSDKUser associated with the user who receives the command. See \link ZMVideoSDKUser \endlink. If receiver is set to <code>nil</code>, the command is broadcast to all users.
 * @return If the function succeeds, it will return @c ZMVideoSDKErrors_Success, otherwise failed.
 * @note Limit up to 60 custom commands per second.
 */
- (ZMVideoSDKErrors)sendCommand:(NSString *)commandContent receiveUser:(nullable ZMVideoSDKUser *)user;
@end

NS_ASSUME_NONNULL_END
