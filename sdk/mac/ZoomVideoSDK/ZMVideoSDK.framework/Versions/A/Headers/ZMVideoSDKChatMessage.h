

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class ZMVideoSDKUser;
/**
 @brief Chat message interface.
 */
@interface ZMVideoSDKChatMessage : NSObject

/**
 @brief Get the send user object of the message.
 @return If the function succeeds, it will return a user object, otherwise returns nil.
 */
@property (nonatomic, retain, readonly) ZMVideoSDKUser* sendUser;
    
/**
 @brief Get the receive user object of the message.
 @return If the function succeeds, it will return a user object, otherwise returns nil.
 */
@property (nonatomic, retain, readonly) ZMVideoSDKUser* receiverUser;

/**
 @brief Content of the message.
 */
@property (nonatomic, copy, readonly) NSString* content;

/**
 @brief Time stamp of the message.
 */
@property (nonatomic, assign, readonly) time_t timeStamp;

/**
 @brief Determine if the message is send to all.
 */
@property (nonatomic, assign, readonly) BOOL isChatToAll;

/**
 @brief Determine if the message is send by yourself.
 */
@property (nonatomic, assign, readonly) BOOL isSelfSend;

/**
 @brief Get the message ID of the current message.
 */
@property (nonatomic, copy, readonly) NSString* messageID;

@end
NS_ASSUME_NONNULL_END
