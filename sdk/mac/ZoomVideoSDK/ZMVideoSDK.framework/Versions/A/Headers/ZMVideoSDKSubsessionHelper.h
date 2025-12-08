/**
 * @file ZMVideoSDKSubSessionHelper.h
 * @brief This file declares the interfaces for managing Zoom Video SDK subsessions,
 */


#import <Foundation/Foundation.h>

@class ZMVideoSDKUser;
NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZMVideoSDKSubSessionUser
 * @brief Represents a user within a subsession.
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
 * @class ZMVideoSDKSubSessionKit
 * @brief Represents a subsession instance.
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
 * @return If the function succeeds, it returns an array of ZMVideoSDKSubSessionUser. Otherwise returns nil.
 */
- (NSArray<ZMVideoSDKSubSessionUser*>* _Nullable)getSubSessionUserList;

/**
 * @brief Join this subsession.
 * @return If the function succeeds, the return value @c ZoomSDKError_Success. Otherwise, the function fails.
 */
- (ZMVideoSDKErrors)joinSubSession;
@end

/**
 * @class ZMVideoSDKSubSessionUserHelpRequestHandler
 * @brief Handler for user help requests in subsessions.
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
 * @class ZMVideoSDKSubSessionManager
 * @brief Manages subsession lifecycle and communication.
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
 * @class ZMVideoSDKSubSessionParticipant
 * @brief Interface for subsession participants.
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
 * @class ZMVideoSDKSubSessionHelper
 * @brief Helper class for managing subsessions.
 * @note Only available to session hosts and managers.
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
 * @return If the function succeeds, it returns an array of ZMVideoSDKSubSessionKit. Otherwise returns nil.
 */
- (NSArray<ZMVideoSDKSubSessionKit*>* _Nullable)getCommittedSubSessionList;
@end
NS_ASSUME_NONNULL_END
