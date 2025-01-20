

#import <Foundation/Foundation.h>
#import <ZMVideoSDK/ZMVideoSDKUserHelper.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMVideoSDKLiveTranscriptionLanguage : NSObject

/**
 @brief The id of the language.
 */
@property (nonatomic, assign, readonly)int languageID;

/**
 @brief The name of the language.
 */
@property (nonatomic, copy, readonly)NSString *languageName;

@end


/**
 @brief Live transcription message interface.
 */
@interface ZMVideoSDKLiveTranscriptionMessageInfo : NSObject
/**
 @brief Get the message ID of the current message.
 */
@property (nonatomic, copy, readonly) NSString *messageID;

/**
 @brief Get the speaker's ID.
 */
@property (nonatomic, copy, readonly) NSString *speakerID;

/**
 @brief Get the speaker's name.
 */
@property (nonatomic, copy, readonly) NSString *speakerName;

/**
 @brief Get the content of the current message.
 */
@property (nonatomic, copy, readonly) NSString *messageContent;

/**
 @brief Get the time stamp of the current message.
 */
@property (nonatomic, assign, readonly) time_t timeStamp;

/**
 @brief Get the type of the current message.
 */
@property (nonatomic, assign, readonly) ZMVideoSDKLiveTranscriptionOperationType messageType;
@end


@interface ZMVideoSDKLiveTranscriptionHelper : NSObject

/**
 @brief Query if the user can start live transcription.
 */
-(BOOL)canStartLiveTranscription;

/**
 @brief Get the current live transcription status.
 @return If the function succeeds, the return value is the current live transcription status. For more details refer to {@link ZMVideoSDKLiveTranscriptionStatus}.
 */
-(ZMVideoSDKLiveTranscriptionStatus)getLiveTranscriptionStatus;

/**
 @brief Start live transcription.
 @Note If the session allows multi-language transcription, all user can start live transcription. Otherwise only the host can start it.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)startLiveTranscription;

/**
 @brief Stop live transcription.
 @Note If the session allows multi-language transcription, all user can stop live transcription. Otherwise only the host can stop it.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)stopLiveTranscription;

/**
 @brief Get the list of all available spoken languages in session.
 @return If the function succeeds, the return value is the list of the available spoken languages in a session.
 */
-(NSArray<ZMVideoSDKLiveTranscriptionLanguage*> * _Nullable)getAvailableSpokenLanguages;

/**
 @brief Set the spoken language of the current user.
 @param languageID The spoken language ID.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)setSpokenLanguage:(int)languageID;

/**
 @brief Get the spoken language of the current user.
 */
-(ZMVideoSDKLiveTranscriptionLanguage* _Nullable)getSpokenLanguage;

/**
 @brief Get the list of all available translation languages in a session.
 @return If the function succeeds, the return value is the list of all available translation languages in a session.
 */
-(NSArray<ZMVideoSDKLiveTranscriptionLanguage*> * _Nullable)getAvailableTranslationLanguages;

/**
 @brief Set the translation language of the current user.
 @param languageID The translation language ID. If the language id is set to -1, live translation will be disabled.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)setTranslationLanguage:(int)languageID;

/**
 @brief Get the translation language of the current user.
 */
-(ZMVideoSDKLiveTranscriptionLanguage* _Nullable)getTranslationLanguage;

/**
 @brief Enable or disable to receive original and translated content. If you enable this feature, you must start live transcription.
 @return If the function succeeds, the return value is ZMVideoSDKErrors_Success. Otherwise not.
 */
- (ZMVideoSDKErrors)enableReceiveSpokenLanguageContent:(BOOL)enable;

/**
 @brief Determine whether the feature to receive original and translated is available.
 @return YES indicates that the feature to receive original and translated is available. Otherwise NO.
 */
- (BOOL)isReceiveSpokenLanguageContentEnabled;

/**
 @brief Determine whether the view history translation message is available.
 @return YES indicates that the view history transcription message is available. Otherwise NO.
 */
- (BOOL)isAllowViewHistoryTranslationMessageEnabled;

/**
 @brief Get the list of all history translation messages in a session.
 @return If the function succeeds, the return value is a array of all history translation messages in a session. Otherwise it fails, and the return value is nil.
 */
- (NSArray<ZMVideoSDKLiveTranscriptionMessageInfo*>* _Nullable)getHistoryTranslationMessageList;
@end

NS_ASSUME_NONNULL_END
