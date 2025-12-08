/**
 * @file ZMVideoSDKLiveTranscriptionHelper.h
 * @brief This file defines interfaces related to live transcription.
 */


#import <Foundation/Foundation.h>
#import <ZMVideoSDK/ZMVideoSDKUserHelper.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZMVideoSDKLiveTranscriptionLanguage
 * @brief Represents a language used in live transcription.
 */
@interface ZMVideoSDKLiveTranscriptionLanguage : NSObject

/**
 * @brief The id of the language.
 */
@property (nonatomic, assign, readonly)int languageID;

/**
 * @brief The name of the language.
 */
@property (nonatomic, copy, readonly)NSString *languageName;

@end



/**
 * @class ZMVideoSDKLiveTranscriptionMessageInfo
 * @brief Represents a single message information of live transcription.
 */
@interface ZMVideoSDKLiveTranscriptionMessageInfo : NSObject
/**
 * @brief Get the message ID of the current message.
 */
@property (nonatomic, copy, readonly) NSString *messageID;

/**
 * @brief Get the speaker's ID.
 */
@property (nonatomic, copy, readonly) NSString *speakerID;

/**
 * @brief Get the speaker's name.
 */
@property (nonatomic, copy, readonly) NSString *speakerName;

/**
 * @brief Get the content of the current message.
 */
@property (nonatomic, copy, readonly) NSString *messageContent;

/**
 * @brief Get the time stamp of the current message.
 */
@property (nonatomic, assign, readonly) time_t timeStamp;

/**
 * @brief Get the type of the current message.
 */
@property (nonatomic, assign, readonly) ZMVideoSDKLiveTranscriptionOperationType messageType;
@end


/**
 * @class ZMVideoSDKLiveTranscriptionHelper
 * @brief Provides methods for controlling and interacting with live transcription.
 */
@interface ZMVideoSDKLiveTranscriptionHelper : NSObject

/**
 * @brief Query if the user can start live transcription.
 * @return YES if the user can start live transcription. NO otherwise.
 */
- (BOOL)canStartLiveTranscription;

/**
 * @brief Get the current live transcription status.
 * @return If the function succeeds, the return value is the current live transcription status.
 */
- (ZMVideoSDKLiveTranscriptionStatus)getLiveTranscriptionStatus;

/**
 * @brief Start live transcription.
 * @return If the function succeeds, it will return @c ZMVideoSDKErrors_Success, otherwise failed.
 * @note If the session allows multi-language transcription, all user can start live transcription. Otherwise only the host can start it.
 */
- (ZMVideoSDKErrors)startLiveTranscription;

/**
 * @brief Stop live transcription.
 * @return If the function succeeds, it will return @c ZMVideoSDKErrors_Success, otherwise failed.
 * @note If the session allows multi-language transcription, all user can stop live transcription. Otherwise only the host can stop it.
 */
- (ZMVideoSDKErrors)stopLiveTranscription;

/**
 * @brief Get the list of all available spoken languages in session.
 * @return If the function succeeds, the return value is the list of the available spoken languages in a session.
 */
- (NSArray<ZMVideoSDKLiveTranscriptionLanguage*> * _Nullable)getAvailableSpokenLanguages;

/**
 * @brief Set the spoken language of the current user.
 * @param languageID The spoken language ID.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)setSpokenLanguage:(int)languageID;

/**
 * @brief Get the spoken language of the current user.
 * @return The spoken language of the current user. Otherwise returns nil.
 */
- (ZMVideoSDKLiveTranscriptionLanguage* _Nullable)getSpokenLanguage;

/**
 * @brief Get the list of all available translation languages in a session.
 * @return If the function succeeds, the return value is the list of all available translation languages in a session.
 */
- (NSArray<ZMVideoSDKLiveTranscriptionLanguage*> * _Nullable)getAvailableTranslationLanguages;

/**
 * @brief Set the translation language of the current user.
 * @param languageID The translation language ID. If the language id is set to -1, live translation will be disabled.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)setTranslationLanguage:(int)languageID;

/**
 * @brief Get the translation language of the current user.
 * @return The translation language of the current user. Otherwise returns nil.
 */
- (ZMVideoSDKLiveTranscriptionLanguage* _Nullable)getTranslationLanguage;

/**
 * @brief Enable or disable to receive original and translated content. If you enable this feature, you must start live transcription.
 * @param enable Set to YES to receive both spoken language content. NO to disable.
 * @return If the function succeeds, the return value is ZMVideoSDKErrors_Success. Otherwise not.
 */
- (ZMVideoSDKErrors)enableReceiveSpokenLanguageContent:(BOOL)enable;

/**
 * @brief Determine whether the feature to receive original and translated is available.
 * @return YES indicates that the feature to receive original and translated is available. Otherwise NO.
 */
- (BOOL)isReceiveSpokenLanguageContentEnabled;

/**
 * @brief Determine whether the view history translation message is available.
 * @return YES indicates that the view history transcription message is available. Otherwise NO.
 */
- (BOOL)isAllowViewHistoryTranslationMessageEnabled;

/**
 * @brief Get the list of all history translation messages in a session.
 * @return If the function succeeds, the return value is a array of all history translation messages in a session. Otherwise it fails, and the return value is nil.
 */
- (NSArray<ZMVideoSDKLiveTranscriptionMessageInfo*>* _Nullable)getHistoryTranslationMessageList;
@end

NS_ASSUME_NONNULL_END
