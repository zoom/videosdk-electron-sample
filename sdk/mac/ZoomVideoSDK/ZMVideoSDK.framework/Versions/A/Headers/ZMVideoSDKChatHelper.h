

#import <Foundation/Foundation.h>
#import <ZMVideoSDK/ZMVideoSDKUserHelper.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Chat helper interface.
 */
@interface ZMVideoSDKChatHelper : NSObject
    
/**
 @brief Determine whether chat is disabled.
 @return YES if chat is disabled, otherwise NO.
 */
-(BOOL)isChatDisabled;
    
/**
 @brief Determine whether private chat is disabled.
 @return YES if private chat is disabled, otherwise NO.
 */
-(BOOL)isPrivateChatDisabled;
    
/**
 @brief Call this method to send a chat message to a specific user.
 @param user The receiver.
 @param msgContent The content of message.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)sendChatToUser:(ZMVideoSDKUser*)user content:(NSString *)msgContent;
    
/**
 @brief Call this method to send a chat message to all users.
 @param msgContent The content of message.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)sendChatToAll:(NSString *)msgContent;

/**
 @brief Determine if a specific message can be deleted.
 @param msgID The message Id.
 @return YES if the message can be deleted, otherwise NO.
 */
-(BOOL)canChatMessageBeDeleted:(NSString *)msgID;

/**
 @brief Call this method to delete a specific chat message from the Zoom server.
 @Note This does not delete the message in your user interface.
 @param msgID The message Id.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success, otherwise failed.
 */
-(ZMVideoSDKErrors)deleteChatMessage:(NSString *)msgID;


/**
 @brief Set participant chat privilege when in session. Only session host/manager can run the function.
 @param privilege The chat privilege of the participant.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success, otherwise failed.
 */
-(ZMVideoSDKErrors)changeChatPrivilege:(ZMVideoSDKChatPrivilegeType)privilege;

/**
 @brief Get participant chat privilege when in session.
 @return The result of participant chat priviledge.
 */
-(ZMVideoSDKChatPrivilegeType)getChatPrivilege;
@end

NS_ASSUME_NONNULL_END
