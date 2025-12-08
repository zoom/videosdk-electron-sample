/**
 * @file ZMVideoSDKRecordingConsentHandler.h
 * @brief Defines the interface for handling recording consent in Zoom Video SDK sessions.
 */


#import <Foundation/Foundation.h>
#import <ZMVideoSDK/ZMVideoSDKDef.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZMVideoSDKRecordingConsentHandler
 * @brief Provides methods to handle user consent for cloud recording in a Zoom Video SDK session.
 */
@interface ZMVideoSDKRecordingConsentHandler : NSObject

/**
 * @brief The type of cloud record agreement.
 */
@property (nonatomic, assign, readonly)ZMVideoSDKConsentType consentType;

/**
 * @brief Accept the clound record.
 * @return YES if the action is accepted successfully. Otherwise NO.
 */
- (BOOL)accept;

/**
 * @brief Decline the clound record.
 * @return YES if the action is declined successfully. Otherwise NO.
 */
- (BOOL)decline;

@end

NS_ASSUME_NONNULL_END
