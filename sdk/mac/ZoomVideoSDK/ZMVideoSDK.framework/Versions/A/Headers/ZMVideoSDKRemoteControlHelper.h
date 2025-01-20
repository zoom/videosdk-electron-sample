//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMVideoSDKRemoteControlRequestHandler : NSObject
/**
 @brief Approve the remote control request.
 @return ZMVideoSDKErrors_Success If the function succeeds. Otherwise failed. See error codes defined in {@link ZMVideoSDKErrors}.
 */
-(ZMVideoSDKErrors)approve;

/**
 @brief Decline the remote control request.
 @return ZMVideoSDKErrors_Success If the function succeeds. Otherwise failed. See error codes defined in {@link ZMVideoSDKErrors}.
 */
-(ZMVideoSDKErrors)deny;
@end

/**
 @brief Helper class for using remote control in the session.
 */
@interface ZMVideoSDKRemoteControlHelper : NSObject
/**
 @brief Determine if the user is able to ask to remote control the specified user.
 @return If the user is able to request to remote control the specified user, the return value is YES. Otherwise NO.
 */
-(BOOL)canRequestControl;

/**
 @brief Send the remote control request to the specified user.
 @return ZMVideoSDKErrors_Success If the function succeeds. Otherwise failed. See error codes defined in {@link ZMVideoSDKErrors}.
 */
-(ZMVideoSDKErrors)requestRemoteControl;

/**
 @brief End remote control of the specified user.
 @return ZMVideoSDKErrors_Success If the function succeeds. Otherwise failed. See error codes defined in {@link ZMVideoSDKErrors}.
 */
-(ZMVideoSDKErrors)endRemoteControl;

/**
 @brief Determine if the user is able to remote control the specified user.
 @return If the user is able to remote control the specified user, the return value is YES. Otherwise NO.
 */
-(BOOL)canRemoteControl;

/**
 @brief Remote control the specified user.
 @return ZMVideoSDKErrors_Success If the function succeeds. Otherwise failed. See error codes defined in {@link ZMVideoSDKErrors}.
 */
-(ZMVideoSDKErrors)enterRemoteControl;

/**
 @brief Determine if the specified user is in the process of being remotely controlled.
 @return If the specified user is being remotely controlled, the return value is YES. Otherwise NO.
 */
-(BOOL)isRemoteControlling;

/**
 @brief The user has temporarily paused remote control, to continue, there is no need to request remote control again.
 @return ZMVideoSDKErrors_Success If the function succeeds. Otherwise failed. See error codes defined in {@link ZMVideoSDKErrors}.
 */
-(ZMVideoSDKErrors)leaveRemoteControl;
@end

NS_ASSUME_NONNULL_END
