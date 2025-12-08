//
//  ZMMTStudioHelper.h
//  VideoUI
//
//  Created by geno.chen on 2022/8/9.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMBaseHelper.h>
#include <zVideoApp/Confdef.h>
#import <zVideoUIBridge/ZMMTStudioConstants.h>


NS_ASSUME_NONNULL_BEGIN

@class ZMMTStudioScene;
@class ZMUser;
@class ZMMTStudioLayoutModel;

@interface ZMMTStudioHelper : ZMBaseHelper

- (BOOL)isCurrentProducerPublishing;
- (BOOL)fetchPSScenes;
- (CmmPSLSceneReqStatus)getFetchPSSceneStatus;
- (NSArray <ZMMTStudioScene *> *)getPSScenes;
- (void)changePSScene:(NSString *)sceneID scene:(ZMMTStudioScene *)scene;
- (BOOL)modifyScenesState:(NSArray <ZMMTStudioScene *> *)sceneList;
- (nullable NSString *)getCurrentPublishingSceneID;

- (nullable ZMUser *)getCurrentProducer;
- (ZMUserID)getCurrentProducerUID;
- (nullable ZMUser *)getCurrentProducerParent;
- (void)updateLivedSourceList:(nullable NSArray *)statusArray;
- (nullable NSArray *)getLivedSourceList;
- (NSUInteger)getUserLivedSource:(ZMUserID)userID;
- (BOOL)isUserPSLived:(ZMUser*)zmUser;
- (BOOL)isUserPSLivedWithShare:(ZMUser*)zmUser;
- (ZMUserID)getCurrentVideoScene;

- (BOOL)isProducerParent:(ZMUser *)user;
- (BOOL)isProductionStudioEnabled;
- (BOOL)forceSubscribeProducer;
- (BOOL)isEnablePSLMode;

- (void)notifyPSUserWillLivedWithVideo:(ZMUser *)user;
- (void)notifyPSUserWillLivedWithShare:(ZMUser *)user;
- (void)broadcastMyPublishingScene:(ZMMTStudioScene *)scene;

- (void)joinProducerAudioChannel;
- (void)leaveProducerAudioChannel;

- (BOOL)isFirstTimeStudioSendLive;
- (void)setNotFirstTimeStudioSendLive;

- (BOOL)isFirstTimeStudioOnBoarding;
- (void)setNotFirstTimeStudioOnBoarding;

- (NSInteger)generateCommonLayoutWithUserCount:(NSUInteger)userCount
                              videoRects:(NSArray*_Nullable*_Nullable)videoRects
                                     row:(int*_Nullable)row
                                     col:(int*_Nullable)col
                                  layout:(ZMMTStudioLayoutModel*)layoutModel;

- (void)rectsWithLayoutID:(NSInteger)layoutID
               videoRects:(NSArray*_Nullable*_Nullable)videoRects
               shareRects:(NSArray*_Nullable*_Nullable)shareRects
                   layout:(ZMMTStudioLayoutModel*)layoutModel;
- (void)videoRectsDowngradingLayoutID:(NSInteger)layoutID
                           videoRects:(NSArray*_Nullable*_Nullable)videoRects
                               layout:(ZMMTStudioLayoutModel*)layoutModel
                      containBigCount:(NSInteger)contianBigCount onlineCount:(NSInteger)onlineCount;
- (void)shareRectsDowngradingLayoutID:(NSInteger)layoutID
                           videoRects:(NSArray*_Nullable*_Nullable)videoRects
                           shareRects:(NSArray*_Nullable*_Nullable)shareRects
                               layout:(ZMMTStudioLayoutModel*)layoutModel
                         containShare:(BOOL)containShare
                          onlineCount:(NSInteger)onlineCount;

- (void)notifyPSUserLived:(ZMUserID)userID context:(CmmUInt32)context;


- (void)startSendLive:(NSUInteger)broadcastId;
- (void)stopSendLive;
- (BOOL)isSendingLive;

- (CmmPSLMixVideoQualityLevel)getPreferMixedVideoQuality;
- (CmmPSLMixVideoQualityLevel)getRecommendMixedVideoQuality:(CmmPSLMixVideoQualityLevel)perfer;
- (BOOL)isDeviceSupportOpenPSL;
- (BOOL)isDeviceSupportedHighQuality;
- (BOOL)canStartPrivateShare;
- (BOOL)setPSLMixShareSourceID:(NSUInteger)shareSourceID rect:(NSRect)rect;
- (BOOL)getPSLMixShareSourceID:(NSUInteger*)shareSourceID rect:(NSRect *)rect;


#pragma mark - Cloud Mix

- (BOOL)isCloudMixEnabled;
- (BOOL)requestInvite:(ZMMTStudioInviteUserType)userType;
- (void)startCloudMixLive:(ZMMTStudioScene *)scene;
- (void)stopCloudMixLive;

- (BOOL)updateLiveLayout:(ZMMTStudioScene*)scene;
- (BOOL)updatePreviewLayout:(ZMMTStudioScene*)scene;

- (BOOL)updateControlCommand:(CmmRSGWControlData)controlData;
- (void)updatePlayerWithSceneID:(NSString *)sceneID loopMode:(BOOL)isEnableLoopMode;
- (void)updatePlayerWithSceneID:(NSString *)sceneID playStatus:(BOOL)isPlaying;
- (void)updatePlayerWithSceneID:(NSString *)sceneID seekTime:(CGFloat)seekTime;
- (void)updatePlayerWithSceneID:(NSString *)sceneID volume:(CGFloat)volume;
- (void)updatePlayerWithSceneID:(NSString *)sceneID endOperation:(ZMMTStudioVideoEndOperation)videoEndOperation fileID:(NSString *)fileID;
- (void)requestVideoSceneInfo;

- (CmmPSLLayout)convertLayoutWithScene:(ZMMTStudioScene*)scene;
- (nullable NSArray<ZMUser *> *)gallerySceneUsersWithMaxCount:(NSInteger)maxCount;
- (CGFloat)getShareAreaWithLayoutType:(NSInteger)layoutID;

@end

NS_ASSUME_NONNULL_END
