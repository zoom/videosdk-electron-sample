//

#import <Foundation/Foundation.h>

@class ZMVideoSDKUser;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief The command channel allows users to send commands or data (such as plain text or a binary encoded into string) to other users in the same session.
 */
@interface ZMVideoSDKCmdChannel : NSObject
/**
 @brief Send custom commands or data to other users in the current session.
 @Note Limit up to 60 custom commands per second.
 @param commandContent the custom commands or data, represented in string format.
 @param user An instance of ZMVideoSDKUser associated with the user who receives the command. See {@link ZMVideoSDKUser} If receiver is set to <code>nil</code>, the command is broadcast to all users.
 @return ZMVideoSDKErrors_Success if the command sends successfully, otherwise the send command request failed.
 */
- (ZMVideoSDKErrors)sendCommand:(NSString *)commandContent receiveUser:(nullable ZMVideoSDKUser *)user;
@end

NS_ASSUME_NONNULL_END
