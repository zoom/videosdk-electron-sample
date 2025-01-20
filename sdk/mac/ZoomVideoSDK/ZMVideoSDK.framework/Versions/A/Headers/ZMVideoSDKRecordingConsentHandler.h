//

#import <Foundation/Foundation.h>
#import <ZMVideoSDK/ZMVideoSDKDef.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMVideoSDKRecordingConsentHandler : NSObject

// The type of cloud record agreement.
@property (nonatomic, assign, readonly)ZMVideoSDKConsentType consentType;

/**
 @brief Accept the clound record.
 */
-(BOOL)accept;

/**
 @brief Decline the clound record.
 */
-(BOOL)decline;

@end

NS_ASSUME_NONNULL_END
