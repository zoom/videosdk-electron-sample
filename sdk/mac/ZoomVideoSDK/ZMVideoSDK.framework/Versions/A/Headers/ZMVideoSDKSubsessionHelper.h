//
//  ZMVideoSDKSubSessionHelper.h
//  ZMVideoSDK
//

#import <Foundation/Foundation.h>

@class ZMVideoSDKUser;
NS_ASSUME_NONNULL_BEGIN

/**
 * @brief Subsession user.
 */
@interface ZMVideoSDKSubSessionUser : NSObject
/**
 * @brief Get the subsession user's username.
 */
@property(nonatomic, copy, readonly)NSString* userName;
/**
 * @brief Get the subsession user's GUID.
 */
@property(nonatomic, copy, readonly)NSString* userGUID;
@end

/**
 * @brief Subsession kit.
 */
@interface ZMVideoSDKSubSessionKit : NSObject
/**
 * @brief Get the subsession's name.
 */
@property(nonatomic, copy, readonly)NSString* subSessionName;
/**
 * @brief Get the subsession's ID.
 */
@property(nonatomic, copy, readonly)NSString* subSessionID;
/**
 * @brief Get the list of users in this subsession.
 * @return If the function succeeds, it returns an array of ZMVideoSDKSubSessionUser. Otherwise returns NULL. For more details, see \link ZMVideoSDKSubSessionUser \endlink.
 */
- (NSArray<ZMVideoSDKSubSessionUser*>* _Nullable)getSubSessionUserList;

/**
 * @brief Join this subsession.
 * @return If the function succeeds, the return value @c ZoomSDKError_Success. Otherwise, the function fails.
 */
- (ZMVideoSDKErrors)joinSubSession;
@end

/**
 * @brief Subsession user help request handler.
 */
@interface ZMVideoSDKSubSessionUserHelpRequestHandler : NSObject
/**
 * @brief Get the username of the user who sent this request.
 */
@property(nonatomic, copy, readonly)NSString* requestUserName;
/**
 * @brief Get the name of the subsession where the user sent this request.
 */
@property(nonatomic, copy, readonly)NSString* requestSubSessionName;
/**
 * @brief Ignore this request.
 * @return If the function succeeds, the return value @c ZoomSDKError_Success. Otherwise, the function fails.
 * @note 'onSubSessionUserHelpRequestResult' is the corresponding callback notification.
 */
- (ZMVideoSDKErrors)ignore;

/**
 * @brief Join the subsession from which the help request originated.
 * @return If the function succeeds, the return value @c ZoomSDKError_Success. Otherwise, the function fails.
 */
- (ZMVideoSDKErrors)joinSubSessionByUserRequest;
@end

/**
 * @brief Subsession manager helper interface.
 */
@interface ZMVideoSDKSubSessionManager : NSObject
/**
 * @brief Start subsession.
 * @return If the function succeeds, the return value @c ZoomSDKError_Success. Otherwise, the function fails.
 * @note 'onSubSessionStatusChanged' is the corresponding callback notification.
 */
- (ZMVideoSDKErrors)startSubSession;

/**
 * @brief Determine if the subsession has started.
 * @return If the function succeeds, the return value @c ZoomSDKError_Success. Otherwise, the function fails.
 */
- (BOOL)isSubSessionStarted;

/**
 * @brief Stop subsession.
 * @return If the function succeeds, the return value @c ZoomSDKError_Success. Otherwise, the function fails.
 * @note 'onSubSessionStatusChanged' is the corresponding callback notification.
 */
- (ZMVideoSDKErrors)stopSubSession;

/**
 * @brief Broadcast a message to all subsessions.
 * @param message The message to be broadcast.
 * @return If the function succeeds, the return value @c ZoomSDKError_Success. Otherwise, the function fails.
 * @note 'onBroadcastMessageFromMainSession' is the corresponding callback notification.
 */
- (ZMVideoSDKErrors)broadcastMessage:(NSString*)message;
@end

/**
 * @brief Subsession participant helper interface.
 */
@interface ZMVideoSDKSubSessionParticipant : NSObject
/**
 * @brief Return to main session.
 * @return If the function succeeds, the return value @c ZoomSDKError_Success. Otherwise, the function fails.
 */
- (ZMVideoSDKErrors)returnToMainSession;

/**
 * @brief Request help.
 * @return If the function succeeds, the return value @c ZoomSDKError_Success. Otherwise, the function fails.
 * @note 'onSubSessionUserHelpRequestResult'is the corresponding callback notification.
 */
- (ZMVideoSDKErrors)requestForHelp;
@end

/**
 * @brief Subsession helper interface.
 * @note Only session host and manager can get this helper.
 */
@interface ZMVideoSDKSubSessionHelper : NSObject

/**
 * @brief Withdraw all committed subsessions and commit the new list.
 * @param subSessionList Create subsession name list.
 * @return If the function succeeds, the return value @c ZoomSDKError_Success. Otherwise, the function fails.
 */
- (ZMVideoSDKErrors)commitSubSessionList:(NSArray<NSString*>*)subSessionList;

/**
 * @brief Withdraw all committed subsessions.
 * @return If the function succeeds, the return value @c ZoomSDKError_Success. Otherwise, the function fails.
 */
- (ZMVideoSDKErrors)withdrawSubSessionList;

/**
 * @brief Get the list of commited subsessions.
 * @return If the function succeeds, it returns an array of ZMVideoSDKSubSessionKit. Otherwise returns NULL. For more details, see \link ZMVideoSDKSubSessionKit \endlink.
 */
- (NSArray<ZMVideoSDKSubSessionKit*>* _Nullable)getCommittedSubSessionList;
@end
NS_ASSUME_NONNULL_END
