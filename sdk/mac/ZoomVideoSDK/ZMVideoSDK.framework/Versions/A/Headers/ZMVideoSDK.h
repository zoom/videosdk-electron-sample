/**
 * @file ZMVideoSDK.h
 * @brief Main header file for the Zoom Video SDK.
 *
 * This file provides the core interfaces for initializing the SDK,
 * managing video sessions, handling audio/video/chat, and accessing helper components.
 */

#import <Foundation/Foundation.h>
#import <ZMVideoSDK/ZMVideoSDKDelegate.h>
#import <ZMVideoSDK/ZMVideoSDKAudioHelper.h>
#import <ZMVideoSDK/ZMVideoSDKVideoHelper.h>
#import <ZMVideoSDK/ZMVideoSDKUserHelper.h>
#import <ZMVideoSDK/ZMVideoSDKShareHelper.h>
#import <ZMVideoSDK/ZMVideoSDKLiveStreamHelper.h>
#import <ZMVideoSDK/ZMVideoSDKChatHelper.h>
#import <ZMVideoSDK/ZMVideoSDKSession.h>
#import <ZMVideoSDK/ZMVideoSDKVideoSourceHelper.h>
#import <ZMVideoSDK/ZMVideoSDKAudioSendRawdata.h>
#import <ZMVideoSDK/ZMVideoSDKChatMessage.h>
#import <ZMVideoSDK/ZMVideoSDKPasswordHandler.h>
#import <ZMVideoSDK/ZMVideoSDKRecordingHelper.h>
#import <ZMVideoSDK/ZMVideoSDKPhoneHelper.h>
#import <ZMVideoSDK/ZMVideoSDKCmdChannel.h>
#import <ZMVideoSDK/ZMVideoSDKAudioSettingHelper.h>
#import <ZMVideoSDK/ZMVideoSDKNetworkConnectionHelper.h>
#import <ZMVideoSDK/ZMVideoSDKRecordingConsentHandler.h>
#import <ZMVideoSDK/ZMVideoSDKVideoSettingHelper.h>
#import <ZMVideoSDK/ZMVideoSDKShareSettingHelper.h>
#import <ZMVideoSDK/ZMVideoSDKVideoCanvas.h>
#import <ZMVideoSDK/ZMVideoSDKCRCHelper.h>
#import <ZMVideoSDK/ZMVideoSDKAnnotationHelper.h>
#import <ZMVideoSDK/ZMVideoSDKLiveTranscriptionHelper.h>
#import <ZMVideoSDK/ZMVideoSDKSubSessionHelper.h>
#import <ZMVideoSDK/ZMVideoSDKBroadcastStreamingController.h>
#import <ZMVideoSDK/ZMVideoSDKBroadcastStreamingViewer.h>
#import <ZMVideoSDK/ZMVideoSDKRTMSHelper.h>

NS_ASSUME_NONNULL_BEGIN
@class ZMVideoSDKExtendParams;

/**
 * @class ZMVideoSDKInitParams
 * @brief Initialization parameters for Zoom Video SDK.
 */
@interface ZMVideoSDKInitParams : NSObject
/**
 * @brief Set client domain of ZOOM Video SDK.
 */
@property (nonatomic, retain, readwrite, nullable) NSString* domain;

/**
 * @brief Prefix of log file name.
 */
@property (nonatomic, retain, readwrite, nullable) NSString* logFilePrefix;

/**
 * @brief Set whether to enable default log of which the capacity is less than 5M.
 */
@property (nonatomic, assign, readwrite) BOOL enableLog;

/**
 * @brief Set audio raw data memory mode.
 */
@property (nonatomic, assign, readwrite) ZMVideoSDKRawDataMemoryMode audioRawDataMemoryMode;

/**
 * @brief Set video raw data memory mode.
 */
@property (nonatomic, assign, readwrite) ZMVideoSDKRawDataMemoryMode videoRawDataMemoryMode;

/**
 * @brief Set share raw data memory mode.
 */
@property (nonatomic, assign, readwrite) ZMVideoSDKRawDataMemoryMode shareRawDataMemoryMode;

/**
 * @brief Extended parameters.
 */
@property (retain, nonatomic, nullable) ZMVideoSDKExtendParams *extendParams;
@end

/*!
 * @class ZMVideoSDKExtendParams
 * @brief Extended configuration parameters for Zoom Video SDK.
 */
@interface ZMVideoSDKExtendParams : NSObject
/*!
 * @brief Specify a file path for speaker test.
 * @note Only support mp3 format. The size cannot exceed 1M.
 */
@property (nonatomic, copy, nullable) NSString *speakerTestFilePath;

/**
 * @brief Wrapper type.
 */
@property (nonatomic, assign, readwrite) int wrapperType;

/**
 * @brief Prefer video resolution.
 */
@property (nonatomic, assign, readwrite) ZMVideoSDKPreferVideoResolution preferVideoResolution;

/**
 * @brief disable access keychain.
 */
@property (nonatomic, assign, readwrite) BOOL disableKeychainAccess;
@end


/**
 * @class ZMVideoSDKVideoOption
 * @brief Video configuration options for joining a session.
 */
@interface ZMVideoSDKVideoOption : NSObject
/**
 * @brief Set local video on or off.
 */
@property (nonatomic, assign, readwrite) BOOL localVideoOn;
@end

/**
 * @class ZMVideoSDKAudioOption
 * @brief Audio configuration options for joining a session.
 */
@interface ZMVideoSDKAudioOption : NSObject
/**
 * @brief Whether to connect local audio or not.
 */
@property (nonatomic, assign, readwrite) BOOL connect;

/**
 * @brief Whether to mute audio or not.
 */
@property (nonatomic, assign, readwrite) BOOL mute;

/**
 * @brief Determine whether my voice is in the mixed audio raw data or not. YES to include. No to exclude.
 */
@property (nonatomic, assign, readwrite) BOOL isMyVoiceInMix;

/**
 * @brief Whether to automatically adjust the volume of the speaker or not. If YES, this will automatically adjust the volume if it is muted or low. If NO it will not.
 */
@property (nonatomic, assign, readwrite) BOOL autoAdjustSpeakerVolume;

@end

/**
 * @class ZMVideoSDKSessionContext
 * @brief Session context information for a Zoom Video SDK session.
 */
@interface ZMVideoSDKSessionContext : NSObject

/**
 * @brief Session name.
 */
@property (nonatomic, retain, readwrite, nullable) NSString* sessionName;

/**
 * @brief Session password (optional).
 */
@property (nonatomic, retain, readwrite, nullable) NSString* sessionPassword;

/**
 * @brief User name(required).
 */
@property (nonatomic, retain, readwrite, nullable) NSString* userName;

/**
 * @brief JWT token to join session.
 */
@property (nonatomic, retain, readwrite, nullable) NSString* token;

/**
 * @brief Video option.
 */
@property (nonatomic, retain, readwrite, nullable) ZMVideoSDKVideoOption* videoOption;

/**
 * @brief Audio option.
 */
@property (nonatomic, retain, readwrite, nullable) ZMVideoSDKAudioOption* audioOption;

/**
 * @brief Set delegate. (optional).
 */
@property (nonatomic, assign, readwrite) id<ZMVideoSDKVideoSourcePreProcessor> preProcessor;
/**
 * @brief Set delegate (optional).
 */
@property (nonatomic, assign, readwrite) id<ZMVideoSDKVideoSource> externalVideoSource;
/**
 * @brief Set virtual audio delegate (optional).
 */
@property (nonatomic, assign, readwrite) id<ZMVideoSDKVirtualAudioMic> virtualAudioMic;
/**
 * @brief Set virtual audio speaker delegate (optional).
 */
@property (nonatomic, assign, readwrite) id<ZMVideoSDKVirtualAudioSpeaker> virtualAudioSpeaker;
/**
 * @brief [Optional] The amount of time in minutes after which an idle session will end.
 * @note When there is only one user remaining in a session, that session is considered idle.
 * @note Default value: 40. If the value is less than 0, the session will stay alive indefinitely.
 */
@property (nonatomic, assign, readwrite) unsigned int sessionIdleTimeoutMins;
/**
 * @brief Whether to automatically load multi streams when entering a session, default value is YES, optional.
 */
@property (nonatomic, assign, readwrite) BOOL autoLoadMutliStream;
@end


/**
 * @class ZMVideoSDK
 * @brief Zoom Video SDK API manager. Main singleton object that controls the video session creation, event callbacks and other main features of video SDK.
 */
@interface ZMVideoSDK : NSObject

/**
 * @brief Returns ZMVideoSDK instance.
 * @return ZMVideoSDK instance.
 */
+ (ZMVideoSDK*)sharedVideoSDK;
    
/**
 * @brief Initialize the Zoom Video SDK with the appropriate parameters.
 * @param params An initialization parameter object containing all required configuration fields.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)initialize:(ZMVideoSDKInitParams*)params;
    
/**
 * @brief Clean up Zoom Video SDK.
 */
- (void)cleanUp;
    
/**
 * @brief Register a listener for session events.
 * @param listener A listener class that groups together all the callbacks related to a session.
 */
- (void)addListener:(id <ZMVideoSDKDelegate>)listener;
    
/**
 * @brief Unregister a listener for session events.
 * @param listener A listener class that groups together all the callbacks related to a session.
 */
- (void)removeListener:(id <ZMVideoSDKDelegate>)listener;
    
/**
 * @brief Call this method to join a session with the appropriate ZMVideoSDKSessionContext parameters. When successful, the SDK will attempt to join a session. Use the callbacks in the listener to confirm whether the SDK actually joined.
 * @param params It is a session context object, contain all params to join session.
 * @return If the function succeeds, the return value is the pointer of session object, otherwise returns nil.
 */
- (ZMVideoSDKSession* _Nullable)joinSession:(ZMVideoSDKSessionContext*)params;
    
/**
 * @brief Call this method to leave a session previously joined through joinSession method call. When successful, the SDK will attempt to leave a session. Use the callbacks in the listener to confirm whether the SDK actually left.
 * @param end YES if the host should end the entire session, or NO if the host should just leave the session.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)leaveSession:(BOOL)end;
    
/**
 * @brief Returns the current session information.
 * @return If the function succeeds, it will return a session object, otherwise returns nil.
 */
- (ZMVideoSDKSession*)getSessionInfo;
    
/**
 @brief Check if there is an active session between participants.
 @return YES means in session, otherwise not.
 */
- (BOOL)isInSession;
    
/**
 * @brief Returns Zoom SDK internal version.
 * @return If the function succeeds, the return value is sdk version. Otherwise returns nil.
 */
- (NSString* _Nullable)getSDKVersion;

/**
 * @brief Exports a log file to local disk.
 * @return If the function succeeds, the return value is the exported log file path.
 */
- (NSString* _Nullable)exportLog;

/**
 * @brief Cleans all exported logs.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success. Otherwise the function fails.
 */
- (ZMVideoSDKErrors)cleanAllExportedLogs;

/**
 * @brief Returns an instance to manage audio controls related to the current video SDK session.
 * @return If the function succeeds, it will return  a ZMVideoSDKAudioHelper instance, otherwise returns nil.
 */
- (ZMVideoSDKAudioHelper*)getAudioHelper;
    
/**
 * @brief Returns an instance to manage cameras and video during a video SDK session.
 * @return If the function succeeds, it will return  a ZMVideoSDKVideoHelper instance, otherwise returns nil.
 */
- (ZMVideoSDKVideoHelper*)getVideoHelper;
    
/**
 * @brief Returns an instance to manage users present in a video SDK session.
 * @return If the function succeeds, it will return  a ZMVideoSDKUserHelper instance, otherwise returns nil.
 */
- (ZMVideoSDKUserHelper*)getUserHelper;
    
/**
 * @brief Returns an instance to manage screen sharing during a video SDK session.
 * @return If the function succeeds, it will return a ZMVideoSDKShareHelper instance, otherwise returns nil.
 */
- (ZMVideoSDKShareHelper*)getShareHelper;
    
/**
 * @brief Returns an instance to manage live streaming during a video SDK session.
 * @return If the function succeeds, it will return a ZMVideoSDKLiveStreamHelper instance, otherwise returns nil.
 */
- (ZMVideoSDKLiveStreamHelper*)getLiveStreamHelper;
    
/**
 * @brief Returns an instance to send and receive chat messages within video SDK session participants.
 * @return If the function succeeds, it will return a ZMVideoSDKChatHelper instance, otherwise returns nil.
 */
- (ZMVideoSDKChatHelper*)getChatHelper;

/**
 * @brief Returns an instance to manage cloud recordings during a video SDK session.
 * @return If the function succeeds, it will return a ZMVideoSDKRecordingHelper instance, otherwise returns nil.
 */
- (ZMVideoSDKRecordingHelper*)getRecordingHelper;

/**
 * @brief Returns an instance to use command channel features during a video SDK session.
 * @return If the function succeeds, it will return a ZMVideoSDKCmdChannel instance, otherwise returns nil.
 */
- (ZMVideoSDKCmdChannel*)getCmdChannel;

/**
 * @brief Returns an instance to manage phone invitations during a video SDK session.
 * @return If the function succeeds, it will return a ZMVideoSDKPhoneHelper instance, otherwise returns nil.
 */
- (ZMVideoSDKPhoneHelper*)getPhoneHelper;

/**
 * @brief Returns an instance to manage audio setting during or before a video SDK session.
 * @return If the function succeeds, it will return a ZMVideoSDKAudioSettingHelper instance, otherwise returns nil.
 */
- (ZMVideoSDKAudioSettingHelper*)getAudioSettingHelper;

/**
 * @brief Returns an instance to manage audio device test during or before a video SDK session.
 * @return If the function succeeds, it will return a ZMVideoSDKAudioDeviceTestHelper instance, otherwise returns nil.
 */
- (ZMVideoSDKAudioDeviceTestHelper*)getAudioDeviceTestHelper;

/**
 * @brief Returns an instance to manage network connection during or before a video SDK session.
 * @return If the function succeeds, it will return a ZMVideoSDKNetworkConnectionHelper instance, otherwise returns nil.
 */
- (ZMVideoSDKNetworkConnectionHelper*)getNetworkConnectionHelper;

/**
 * @brief Get video setting helper object.
 * @return If the function succeeds, it will return a ZMVideoSDKVideoSettingHelper instance, otherwise returns nil.
 */
- (ZMVideoSDKVideoSettingHelper*)getVideoSettingHelper;

/**
 * @brief Get share setting helper object.
 * @return If the function succeeds, it will return a ZMVideoSDKShareSettingHelper instance, otherwise returns nil.
 */
- (ZMVideoSDKShareSettingHelper*)getShareSettingHelper;

/**
 * @brief Get crc helper object.
 * @return If the function succeeds, it will return a ZMVideoSDKCRCHelper instance, otherwise returns nil.
 */
- (ZMVideoSDKCRCHelper*)getCRCHelper;

/**
 * @brief Get live transcription helper object.
 * @return If the function succeeds, it will return a ZMVideoSDKLiveTranscriptionHelper instance, otherwise returns nil.
 */
- (ZMVideoSDKLiveTranscriptionHelper*)getLiveTranscriptionHelper;

/**
 * @brief Get incoming live stream helper object.
 * @return If the function succeeds, it will return a ZMVideoSDKIncomingLiveStreamHelper instance, otherwise returns nil.
 */
- (ZMVideoSDKIncomingLiveStreamHelper*)getIncomingLiveStreamHelper;

/**
 * @brief Get the subsession helper object.
 * @return If the function succeeds, it will return a ZMVideoSDKSubSessionHelper instance, otherwise returns nil.
 * @note Only host and manager can call this interface.
 */
- (ZMVideoSDKSubSessionHelper* _Nullable)getSubSessionHelper;

/**
 * @brief Gets the broadcast streaming controller object.
 * @return The broadcast streaming controller object if available; otherwise, nil.
 */
- (ZMVideoSDKBroadcastStreamingController* _Nullable)getBroadcastStreamingController;

/**
 * @brief Gets the broadcast streaming viewer object.
 * @return The broadcast streaming viewer object if available; otherwise, nil.
 */
- (ZMVideoSDKBroadcastStreamingViewer* _Nullable)getBroadcastStreamingViewer;

/**
 * @brief Returns an instance to manage RTMS (Real-Time Media Streams) during a video SDK session.
 * @return If the function succeeds, it will return a ZMVideoSDKRTMSHelper instance, otherwise returns nil.
 */
- (ZMVideoSDKRTMSHelper* _Nullable)getRealTimeMediaStreamsHelper;
@end
NS_ASSUME_NONNULL_END
