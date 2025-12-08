/**
 * @file ZMVideoSDKPasswordHandler.h
 * @brief This file defines the interface for handling session password input within the Zoom Video SDK.
 */

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZMVideoSDKPasswordHandler
 * @brief Provides methods to manage session password entry when joining a session.
 */
@interface ZMVideoSDKPasswordHandler : NSObject

/**
 * @brief Input session password.
 * @param password The session password.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)inputSessionPassword:(NSString*)password;
    
/**
 * @brief Cancel input password.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)leaveSessionIgnorePassword;

@end
NS_ASSUME_NONNULL_END
