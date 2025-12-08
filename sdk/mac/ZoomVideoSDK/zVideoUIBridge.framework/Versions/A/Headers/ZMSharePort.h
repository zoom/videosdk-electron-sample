//
//  ZMSharePort.h
//  VideoUIBridge
//
//  Created by vinson.wang on 2024/7/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMSharePort : NSObject

@property (nonatomic, copy, readonly) NSString *sharePortId;
@property (nonatomic, readonly, nullable) ZMUser *shareUser;
@property (nonatomic, strong, readonly, nullable) ZMConfSession *confSession;

//status
@property (nonatomic, assign, readonly) BOOL isPaused;
@property (nonatomic, assign, readonly) BOOL isManualPaused;
@property (nonatomic, assign, readonly) NSSize captureSize;

//capability
@property (nonatomic, assign, readonly) BOOL supportFullHD;

//option
@property (nonatomic, assign, readonly) BOOL isVideoShareEnabledExcludeVideo;
@property (nonatomic, assign, readonly) BOOL isVideoShareEnabled;
@property (nonatomic, assign, readonly) BOOL isAudioShareEnabled;
@property (nonatomic, assign, readonly) BOOL isBoShareEnabled;
@property (nonatomic, assign, readonly) BOOL isPrivateShareEnabled;
@property (nonatomic, assign, readonly) BOOL isFullHDEnabled;
@property (nonatomic, assign, readonly) BOOL isHighFPSEnabled;
@property (nonatomic, assign, readonly) BOOL isBoShareAvailable;

//local share
@property (nonatomic, assign, readonly) BOOL isLocalShareOn;

+ (instancetype)sharePortWithPortId:(NSString *)sharePortId confSession:(ZMConfSession *)confSession;
+ (nullable instancetype)defaultSharePort:(ZMConfSession *)confSession;

- (nullable ICmmASSharePort *)getCmmSharePort;
- (nullable ICmmASShareSource *)getCmmShareSource;
- (nullable ICmmAnnotationAPI *)getCmmAnnotation;
@end

NS_ASSUME_NONNULL_END
