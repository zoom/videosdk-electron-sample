
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMVideoSDKDialInNumberInfo : NSObject
/**
 @brief The country ID of the current information.
 */
@property (nonatomic, copy, readonly) NSString* countryID;
/**
 @brief The country code of the current information.
 */
@property (nonatomic, copy, readonly) NSString* countryCode;
/**
 @brief The country name of the current information.
 */
@property (nonatomic, copy, readonly) NSString* countryName;
/**
 @brief The country number.
 */
@property (nonatomic, copy, readonly) NSString* number;
/**
 @brief The display number.
 */
@property (nonatomic, copy, readonly) NSString* displayNumber;
/**
 @brief The type of dial in number.
 */
@property (nonatomic, assign, readonly) ZMVideoSDKDialInNumType type;
@end

@interface ZMVideoSDKPhoneSupportCountryInfo : NSObject
/**
 @brief The country ID of the current information.
 */
@property (nonatomic, copy, readonly) NSString* countryID;
/**
 @brief The country name of the current information.
 */
@property (nonatomic, copy, readonly) NSString* countryName;
/**
 @brief The country code of the current information.
 */
@property (nonatomic, copy, readonly) NSString* countryCode;
@end

@interface ZMVideoSDKInvitePhoneUserInfo : NSObject
/**
 @brief The country code of the specified user must be in the support list.
 */
@property (nonatomic, copy, nullable) NSString* countryCode;
/**
 @brief The phone number of specified user.
 */
@property (nonatomic, copy, nullable) NSString* phoneNumber;
/**
 @brief The screen name of the specified user in the session.
 */
@property (nonatomic, copy, nullable) NSString* name;
/**
 @brief YES means need press number one to agree to join the session, otherwise not.
 */
@property (nonatomic, assign) BOOL bPressOne;
/**
 @brief YES means When joining the session, play a greeting prompt tone., otherwise not.
 */
@property (nonatomic, assign) BOOL bGreeting;
@end

@interface ZMVideoSDKPhoneHelper : NSObject
/**
 @brief Determine if the session supports join by phone or not.
 @return YES indicates join by phone is supported, otherwise NO.
 */
- (BOOL)isSupportPhoneFeature;

/**
 @brief Get the list of the country information where the session supports to join by telephone.
 @return If the function succeeds, the return value is the array of the country information, otherwise returns nil.
 */
- (NSArray<ZMVideoSDKPhoneSupportCountryInfo*>* _Nullable)getSupportCountryInfo;

/**
 @brief Invite the specified user to join the session by phone.
 @param countryCode The country code of the specified user must be in the support list.
 @param phoneNumber The phone number of specified user.
 @param name The screen name of the specified user in the session.
 @return If the function succeeds, the return value is ZMVideoSDKErrors_Success, otherwise not.
 */
- (ZMVideoSDKErrors)inviteByPhone:(NSString*)countryCode phoneNumber:(NSString*)phoneNumber name:(NSString*)name DEPRECATED_MSG_ATTRIBUTE("Use -invitePhoneUser: instead");

/**
 @brief Invite the specified user to join the session by phone.
 @param inviteInfo The info for invite by phone.
 @return If the function succeeds, the return value is ZMVideoSDKErrors_Success, otherwise not.
 */
- (ZMVideoSDKErrors)invitePhoneUser:(ZMVideoSDKInvitePhoneUserInfo *)inviteInfo;
/**
 @brief Cancel the invitation that is being called out by phone.
 @return If the function succeeds, the return value is ZMVideoSDKErrors_Success, otherwise not.
 */
- (ZMVideoSDKErrors)cancelInviteByPhone;

/**
 @brief Get the status of the invitation by phone.
 @return If the function succeeds, the method returns the ZMPhoneStatus of the invitation by phone. To get extended error information, see {@link ZMPhoneStatus}.
 */
- (ZMPhoneStatus)getInviteByPhoneStatus;

/**
 @brief Get the list of dial in numbers supported by session.
 @return If the function succeeds, the return value is the list of the call-in numbers. Otherwise failed. For more details, see {@link ZMVideoSDKDialInNumberInfo}.
 */
- (NSArray<ZMVideoSDKDialInNumberInfo *>* _Nullable)getSessionDialInNumbers;
@end

NS_ASSUME_NONNULL_END
