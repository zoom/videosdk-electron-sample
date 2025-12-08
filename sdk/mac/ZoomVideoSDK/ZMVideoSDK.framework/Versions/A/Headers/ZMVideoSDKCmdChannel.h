/**
 * @file ZMVideoSDKCmdChannel.h
 * @brief Interface for command channel to send custom commands or data between users in the same session.
 */

#import <Foundation/Foundation.h>

@class ZMVideoSDKUser;

NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZMVideoSDKCmdChannel
 * @brief The command channel allows users to send commands or data (such as plain text or a binary encoded into string) to other users in the same session.
 */
@interface ZMVideoSDKCmdChannel : NSObject
/**
 * @brief Send custom commands or data to other users in the current session.
 * @param commandContent the custom commands or data, represented in string format.
 * @param user The target user to receive the command. If nil, the command is broadcast to all users.
 * @return If the function succeeds, it will return @c ZMVideoSDKErrors_Success, otherwise failed.
 * @note Limit up to 60 custom commands per second.
 */
- (ZMVideoSDKErrors)sendCommand:(NSString *)commandContent receiveUser:(nullable ZMVideoSDKUser *)user;
@end

NS_ASSUME_NONNULL_END
