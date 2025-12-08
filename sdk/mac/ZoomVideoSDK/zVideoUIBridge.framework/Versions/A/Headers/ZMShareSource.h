//
//  ZMShareSource.h
//  VideoUIBridge
//
//  Created by vinson.wang on 2024/7/13.
//

#import <Foundation/Foundation.h>
#ifdef __cplusplus
#import <zVideoApp/Confdef.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@interface ZMShareSource : NSObject

@property (nonatomic, assign, readonly) ZMShareSourceID shareSourceId;
@property (nonatomic, strong, readonly, nullable) ZMUser *shareUser;
@property (nonatomic, strong, readonly, nullable) ZMConfSession *confSession;
@property (nonatomic, assign, readonly) BOOL isValid;
@property (nonatomic, assign, readonly) BOOL hasValidASSource;

//state
@property (nonatomic, assign, readonly) BOOL isSharingDoc;
@property (nonatomic, assign, readonly) BOOL isClipsShare;
@property (nonatomic, assign, readonly) BOOL isSendingClipsShare;
@property (nonatomic, assign, readonly) NSSize resolution;
@property (nonatomic, assign, readonly) BOOL isReceiving;
@property (nonatomic, assign, readonly) BOOL isFirstFrameReceived;
@property (nonatomic, assign, readonly) BOOL isReceivingContinuously;
@property (nonatomic, assign, readonly) BOOL isPaused;
@property (nonatomic, assign, readonly) BOOL isSharingAudio;
@property (nonatomic, assign, readonly) BOOL isSharingVideo;
@property (nonatomic, assign, readonly) BOOL isSpotlighted;

//capability
@property (nonatomic, assign, readonly) BOOL supportAutoShare;
@property (nonatomic, assign, readonly) BOOL supportAutoReboot;
@property (nonatomic, assign, readonly) BOOL supportAnnotation;

@property (nonatomic, readonly) NSString *identifier;

- (instancetype)initWithSourceId:(ZMShareSourceID)shareSourceId confSession:(ZMConfSession *)confSession;
+ (instancetype)shareSourceWithSourceId:(ZMShareSourceID)shareSourceId confSession:(ZMConfSession *)confSession;
+ (instancetype)shareSourceWithSourceId:(ZMShareSourceID)shareSourceId userId:(ZMUserID)userId confSession:(ZMConfSession *)confSession;
+ (nullable instancetype)myShareSource;
+ (nullable instancetype)myShareSource:(ZMConfSession *)confSession;
+ (nullable instancetype)firstShareSourceFromUser:(ZMUser *)user;

#ifdef __cplusplus
- (nullable ICmmASShareSource *)getCmmShareSource;
- (nullable zm::docs::ICmmDocsCollaborationSource *)getDocShareSource;
#endif

// ZOOM-734161
- (BOOL)canShareBeSpotlighted;

// DOC API
- (nullable NSString *)docURL;

- (NSString *)generateShareSourceTitle;

@end

NS_ASSUME_NONNULL_END
