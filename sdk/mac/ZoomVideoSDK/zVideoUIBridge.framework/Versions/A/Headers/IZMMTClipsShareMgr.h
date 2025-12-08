//
//  IZMMTClipsShareMgr.h
//  VideoUIBridge
//
//  Created by Michael Lin on 2024/11/18.
//

#ifndef IZMMTClipsShareMgr_h
#define IZMMTClipsShareMgr_h

typedef NS_ENUM(NSUInteger, ZMClipsShareStatus) {
    ZMClipsShareStatusIdle = 0,
    ZMClipsShareStatusStarting,
    ZMClipsShareStatusPlaying,
    ZMClipsShareStatusPaused,
};
@class ZMMTClipsSharePropertyModel, ZMMTClipsShareHelper, ZMMTClipsShareContentStatus;
@protocol IZMMTClipsShareMgr <ZMRoutableObject>

- (nonnull ZMMTClipsShareHelper *)clipsShareHelper;
- (BOOL)isFilePickerShown;
- (BOOL)isClipsSharingAllowed;
- (BOOL)isOptimizeVideoShare;
- (BOOL)isClipsSettingEnable;
- (void)stopClipsShare;
- (void)showFilePickerWindowWithOptimizeVideoShare:(BOOL)optimizeVideoShare;
- (void)closeFilePickerWindow;
- (void)showClipsShareSetting;

- (void)onClipsStartShareRequestFailed;
- (void)onClipsInviteGatewayFailedWithErrorCode:(int64_t)errorCode;
- (void)onClipsShareStateMessageUpdatedWithGatewayID:(ZMUserID)gatewayID code:(NSInteger)code message:(nullable NSString *)message session:(nullable ZMConfSession *)session;
- (void)onClipsShareStartedWithIsMyClips:(BOOL)isMyClips shareSourceID:(uint32_t)shareSourceID session:(nullable ZMConfSession *)session;
- (void)onClipsShareStoppedWithIsMyClips:(BOOL)isMyClips shareSourceID:(uint32_t)shareSourceID session:(nullable ZMConfSession *)session;
- (void)onClipsShareContentStatusUpdated:(nonnull ZMMTClipsShareContentStatus *)status shareSourceID:(uint32_t)shareSourceID session:(nullable ZMConfSession *)session;
- (void)startShareClips:(nullable NSDictionary *)params;
- (nullable ZMMTClipsSharePropertyModel *)mySharePropertyModel;
- (void)resetMyPropertyModel;
- (nonnull ZMMTClipsSharePropertyModel *)sharePropertyModelForOwnerID:(ZMUserID)ownerID;
- (void)resetSharePropertyModelForOwnerID:(ZMUserID)ownerID;

@end

#endif /* IZMMTClipsShareMgr_h */
