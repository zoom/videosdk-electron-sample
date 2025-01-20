

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMVideoSDKUser;


@interface ZMFileTransferProgress : NSObject
/**
 @brief The ratio of the file transfer completed.
 */
@property(nonatomic, assign, readonly) unsigned int ratio;
/**
 @brief The size of the file transferred so far in bytes.
 */
@property(nonatomic, assign, readonly) unsigned long long completeSize;
/**
 @brief The speed of the file transfer in bits per second.
 */
@property(nonatomic, assign, readonly) unsigned int bitPreSecond;
@end

@interface ZMVideoSDKFileStatus : NSObject
/**
 @brief The status of the file transfer.
 */
@property(nonatomic, assign, readonly) ZMVideoSDKFileTransferStatus transStatus;
/**
 @brief The progress of the file transfer.
 */
@property(nonatomic, retain, readonly) ZMFileTransferProgress *transProgress;
@end

@interface ZMVideoSDKSendFile : NSObject
/**
 @brief The timestamp of the file transfer.
 */
@property(nonatomic, assign, readonly) time_t timeStamp;
/**
 @brief Determine whether the file transfer is send to all.
 */
@property(nonatomic, assign, readonly) BOOL isSendToAll;
/**
 @brief The file size of the file transfer.
 */
@property(nonatomic, assign, readonly) unsigned long long fileSize;
/**
 @brief The file name of the file transfer.
 */
@property(nonatomic, copy, readonly) NSString *fileName;
/**
 @brief The status of the file transfer.
 */
@property(nonatomic, retain, readonly) ZMVideoSDKFileStatus *status;
/**
 @brief The receiver of the file transfer.
 */
@property(nonatomic, assign, readonly) ZMVideoSDKUser * _Nullable receiver;

/**
 @brief Cancel the file transfer.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)cancelSend;
@end

@interface ZMVideoSDKReceiveFile : NSObject
/**
 @brief The timestamp of the file transfer.
 */
@property(nonatomic, assign, readonly) time_t timeStamp;
/**
 @brief Determine whether the file transfer is send to all.
 */
@property(nonatomic, assign, readonly) BOOL isSendToAll;
/**
 @brief The file size of the file transfer.
 */
@property(nonatomic, assign, readonly) unsigned long long fileSize;
/**
 @brief The file name of the file transfer.
 */
@property(nonatomic, copy, readonly) NSString *fileName;
/**
 @brief The status of the file transfer.
 */
@property(nonatomic, retain, readonly) ZMVideoSDKFileStatus *status;
/**
 @brief The sender of the file transfer.
 */
@property(nonatomic, assign, readonly) ZMVideoSDKUser * _Nullable sender;

/**
 @brief Start receive the file.
 @param downloadPath The download path, you need to pass the complete path, including the file name and file format.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)startReceive:(NSString *)downloadPath;
/**
 @brief Cancel receive the file.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)cancelReceive;
@end

/**
 @brief Session audio statistic information interface.
 */
@interface ZMVideoSDKSessionAudioStatisticInfo : NSObject

/**
 @brief Get the frequency in kilohertz (KHz) sent by the current user.
 */
@property(nonatomic, assign, readonly) int sendFrequency;

/**
 @brief Get the audio latency (delay in network data transfer) experienced by the current user while sending data.
 */
@property(nonatomic, assign, readonly) int sendLatency;

/**
 @brief Get the audio jitter (change in latency) experienced by the current user while sending data.
 */
@property(nonatomic, assign, readonly) int sendJitter;

/**
 @brief Get the average audio packet loss sent by the current user.
 */
@property(nonatomic, assign, readonly) float sendPacketLossAvg;

/**
 @brief Get the maximum audio packet loss sent by the current user.
 */
@property(nonatomic, assign, readonly) float sendPacketLossMax;

/**
 @brief Get the frequency in kilohertz (KHz) received by the current user.
 */
@property(nonatomic, assign, readonly) int recvFrequency;

/**
 @brief Get the audio latency (delay in network data transfer) experienced by the current user while receiving data.
 */
@property(nonatomic, assign, readonly) int recvLatency;

/**
 @brief Get the audio jitter (change in latency) experienced by the current user while receiving data.
 */
@property(nonatomic, assign, readonly) int recvJitter;

/**
 @brief Get the average audio packet loss received by the current user.
 */
@property(nonatomic, assign, readonly) float recvPacketLossAvg;

/**
 @brief Get the maximum audio packet loss received by the current user.
 */
@property(nonatomic, assign, readonly) float recvPacketLossMax;
@end

/**
 @brief Share statistic information such as FPS, latency, data loss, etc.
 */
@interface ZMVideoSDKSessionASVStatisticInfo : NSObject

/**
 @brief Get the frame width in pixels sent by the current user.
 */
@property(nonatomic, assign, readonly) int sendFrameWidth;

/**
 @brief Get the frame height in pixels sent by the current user.
 */
@property(nonatomic, assign, readonly) int sendFrameHeigh;

/**
 @brief Get the frame rate in FPS sent by the current user.
 */
@property(nonatomic, assign, readonly) int sendFps;

/**
 @brief Get the video latency (delay in network data transfer) experienced by the current user while sending data.
 */
@property(nonatomic, assign, readonly) int sendLatency;

/**
 @brief Get the video jitter (change in latency) experienced by the current user while sending data.
 */
@property(nonatomic, assign, readonly) int sendJitte;

/**
 @brief Get the average video packet loss sent by the current user.
 */
@property(nonatomic, assign, readonly) float sendPacketLossAvg;

/**
 @brief Get the maximum video packet loss sent by the current user.
 */
@property(nonatomic, assign, readonly) float sendPacketLossMax;

/**
 @brief Get the frame width in pixels received by the current user.
 */
@property(nonatomic, assign, readonly) int recvFrameWidth;

/**
 @brief Get the frame height in pixels received by the current user.
 */
@property(nonatomic, assign, readonly) int recvFrameHeigh;

/**
 @brief Get the frame rate in FPS received by the current user.
 */
@property(nonatomic, assign, readonly) int recvFps;

/**
 @brief Get the video latency (delay in network data transfer) experienced by the current user while receiving data.
 */
@property(nonatomic, assign, readonly) int recvLatency;

/**
 @brief Get the video jitter (change in latency) experienced by the current user while receiving data.
 */
@property(nonatomic, assign, readonly) int recvJitte;

/**
 @brief Get the video average packet loss received by the current user.
 */
@property(nonatomic, assign, readonly) float recvPacketLossAvg;

/**
 @brief Get the maximum video packet loss received by the current user.
 */
@property(nonatomic, assign, readonly) float recvPacketLossMax;
@end

/**
 @brief Video session information interface.
 */
@interface ZMVideoSDKSession : NSObject

/**
 @brief Get the current session number.
 @return If the function succeeds, the return value is the current meeting number. Otherwise returns ZERO(0).
 */
- (unsigned long long)getSessionNumber;

/**
 @brief Get the session's name.
 @return The value is session name.
 */
- (NSString* _Nullable)getSessionName;

/**
 @brief Get the session's password.
 @return The value is session password.
 */
- (NSString* _Nullable)getSessionPassword;

/**
 @brief Get the session's password.
 @return The value is session password.
 */
- (NSString* _Nullable)getSessionPhonePasscode;

/**
 @brief Get the session Id.
 @Note: Only the host can get the session Id.
 @return The value is session ID.
 */
- (NSString* _Nullable)getSessionID;

/**
 @brief Get the host's name.
 @return The value is session host name.
 */
- (NSString* _Nullable)getSessionHostName;

/**
 @brief Get the session's host user object.
 @return Remote users list.
 */
- (ZMVideoSDKUser* _Nullable)getSessionHost;

/**
 @brief Get a list of the session's remote users.
 @return If the function succeeds, the return value is remote users list. Otherwise returns nil.
 */
- (NSArray<ZMVideoSDKUser *>* _Nullable)getRemoteUsers;

/**
 @brief The session's user object for myself.
 @return If the function succeeds, the return value is myself object. Otherwise returns nil.
 */
- (ZMVideoSDKUser* _Nullable)getMySelf;

/**
 @brief Get the session's audio statistic information.
 @return If the function succeeds, it will return a session audio statistic infomation object, otherwise returns nil.
 */
- (ZMVideoSDKSessionAudioStatisticInfo* _Nullable)getSessionAudioStatisticInfo;

/**
 @brief Get the session's video statistic information.
 @return If the function succeeds, it will return a session video statistic information object, otherwise returns nil.
 */
- (ZMVideoSDKSessionASVStatisticInfo* _Nullable)getSessionVideoStatisticInfo;

/**
 @brief Get the session's screen share statistic information.
 @return If the function succeeds, it will return a session share statistic information object, otherwise returns nil.
 */
- (ZMVideoSDKSessionASVStatisticInfo* _Nullable)getSessionShareStatisticInfo;

/**
 @brief Determine whether file transfer is enabled.
 @return YES if file transfer is enabled, otherwise NO.
 */
- (BOOL)isFileTransferEnabled;

/**
 @brief Send file to all users in current session.
 @param filePath The local path of the file.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)transferFile:(NSString *)filePath;

/**
 @brief Get the list of allowed file types in transfer.
 @return The value of allowed file types in transfer, comma-separated if there are multiple values. Exe files are by default forbidden from being transferred.
 */
- (NSString * _Nullable)getTransferFileTypeWhiteList;

/**
 @brief Get the maximum size for file transfer.
 @return The maximum number of bytes for file transfer.
 */
- (unsigned long long)getMaxTransferFileSize;
@end

NS_ASSUME_NONNULL_END
