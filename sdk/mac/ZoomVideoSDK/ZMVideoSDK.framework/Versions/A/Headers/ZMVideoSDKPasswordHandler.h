

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN
/**
 @brief Pasword handle interface.
 */
@interface ZMVideoSDKPasswordHandler : NSObject

/**
 @brief Input session password.
 @param password The session password.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)inputSessionPassword:(NSString*)password;
    
/**
 @brief Cancel input password.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)leaveSessionIgnorePassword;

@end
NS_ASSUME_NONNULL_END
