//
//  ZMMTClipsHelper.h
//  VideoUIBridge
//
//  Created by Michael Lin on 2025/1/9.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMBaseHelper.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMMTClipsSharePropertyModel;
@class ZMMTMediaInfoModel;
@interface ZMMTClipsHelper : ZMBaseHelper

@property (nonatomic, strong, readonly, nullable) ZMMTClipsSharePropertyModel *sharePropertyModel;
@property (nonatomic, assign, readonly) double currentVolume;
@property (nonatomic, assign, readonly) NSTimeInterval currentTimestamp;

- (BOOL)isShareClipsViewEnabled;
- (BOOL)isClipsSharing;
- (BOOL)isSharingClips;
- (BOOL)canEnableVideoShareClips;
- (BOOL)canStartVideoShareClips;
- (BOOL)startShareClips:(nullable NSString *)clipsJsonStr optimizeVideoShare:(BOOL)optimizeVideoShare;
- (void)stopShareClips;
- (void)playEndShareClips;
- (void)pauseShareClips;
- (void)resumeShareClips;

/// seek to a timestamp and add delay in order to merge continuously API call
/// - Parameter timestamp: seek timestamp
- (void)seekTimestamp:(NSTimeInterval)timestamp;
- (void)switchMuteStatus;

///  set volume and add delay in order to merge continuously API call
/// - Parameter volume: set volume
- (void)setVolume:(double)volume;
- (void)setSpeed:(double)speed;
- (void)setCloseCaption:(BOOL)closeCaption;
- (void)setOptimizeVideoShare:(BOOL)optimizeVideoShare;

- (nullable ZMMTMediaInfoModel *)getMediaSyncInfoWithUserID:(ZMUserID)userID;
    
- (void)setupSinks;
- (void)removeSinks;

@end

NS_ASSUME_NONNULL_END
