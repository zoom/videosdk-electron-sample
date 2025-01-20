
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Live stream helper interface.
 */
@interface ZMVideoSDKLiveStreamHelper : NSObject

/**
 @brief Start live stream.
 @param streamUrl The live stream url.
 @param url The live stream broadcast url.
 @param key The live stream key.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)startLiveStream:(NSString *)streamUrl   broadcastUrl:(NSString *)url  liveStreamKey:(NSString *)key;
    
/**
 @brief Stop live stream.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)stopLiveStream;
    
/**
 @brief Determine if can start living stream.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)canStartLiveStream;

@end

@interface ZMVideoSDKIncomingLiveStreamStatus : NSObject
/**
 @brief The incoming live stream ID.
 */
@property(nonatomic, copy, readonly, nullable)NSString* strStreamKeyID;
/**
 @brief Is the streaming software (such as OBS) connected to the Zoom platform.
 */
@property(nonatomic, assign, readonly)BOOL isRTMPConnected;
/**
 @brief Has the video stream been pushed to the session.
 */
@property(nonatomic, assign, readonly)BOOL isStreamPushed;

@end

@interface ZMVideoSDKIncomingLiveStreamHelper : NSObject
/**
 @brief Bind incoming live stream with a stream key ID.
 @param strStreamKeyID The stream key ID to bind.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)bindIncomingLiveStream:(NSString *)strStreamKeyID;
/**
 @brief Unbind the bound incoming live stream.
 @param strStreamKeyID The stream key ID you want to unbind.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)unbindIncomingLiveStream:(NSString *)strStreamKeyID;
/**
 @brief Get the status of the bound streams.
 @note Will receive callback "-onIncomingLiveStreamStatusResponse:"
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)getIncomingLiveStreamStatus;
/**
 @brief Start the bound stream as a special participant.
 @param strStreamKeyID The stream key ID you want to start.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)startIncomingLiveStream:(NSString *)strStreamKeyID;
/**
 @brief Stop the bound stream as a special participant.
 @param strStreamKeyID The stream key ID to stop.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)stopIncomingLiveStream:(NSString *)strStreamKeyID;
@end
NS_ASSUME_NONNULL_END
