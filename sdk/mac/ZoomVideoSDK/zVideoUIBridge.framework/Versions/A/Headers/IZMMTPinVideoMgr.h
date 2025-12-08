//
//  IZMMTPinVideoMgr.h
//  VideoUI
//
//  Created by Francis Zhuo on 10/22/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMMTPinFrom) {
    ZMMTPinFrom_None,
    ZMMTPinFrom_CameraControl,
};

@protocol IZMMTPinVideoMgr <ZMRoutableObject>
#pragma mark - pinned video
- (BOOL)canPinVideo;
- (BOOL)canPinVideoWithUser:(ZMUser*)zmUser;
- (BOOL)canPinVideoOnMainWindow;
- (BOOL)isPinMultipleVideoEnable;
- (BOOL)canIPinMultipleVideo;
- (BOOL)isParticipantReachMultiPinLimit;
- (BOOL)isParticipantReachPinLimit;
- (BOOL)isReachedParticipantPinLimit;
- (NSString*)getPinLimitText;
- (NSArray<ZMUser*>*)getPinnedUserArray;
- (NSUInteger)getPinnedUserCount;
- (BOOL)isUserPinnedWithUser:(ZMUser*)zmUser;
- (void)pinWithUser:(ZMUser*)zmUser;
- (void)unpinWithUser:(ZMUser*)zmUser;
- (void)unpinAllUser;
- (void)unpinAllUser:(BOOL)unpinAux;
- (void)pinUserAndUnpinOthers:(ZMUser*)zmUser;
- (void)pinUserAndUnpinOthers:(ZMUser*)zmUser from:(ZMMTPinFrom)from;
- (ZMMTPinFrom)pinFrom;

#pragma mark - pinned video in 2rd
- (BOOL)canPinVideoOnAuxWindow;
- (BOOL)isUserAuxPinnedWithUser:(ZMUser*)zmUser;
- (ZMUser*)getAuxPinnedUser;
- (void)pinToAuxWithUser:(ZMUser*)zmUser;
- (void)unpinAuxWithUser:(ZMUser*)zmUser;
- (void)unpinAllAuxUser;

#pragma mark - spotlight
- (BOOL)isLeadShipMode;
- (BOOL)isLeadShipModeUser:(ZMUser*)zmUser;
- (ZMUser*)getLeadShipModeUser;

- (BOOL)amISpotlighted;
- (BOOL)canISpotlightMultipleVideo;
- (BOOL)isSpotlightingMode;
- (BOOL)isSpotlightingUser:(ZMUser*)zmUser;
- (NSUInteger)getSpotlightingUserCount;
- (NSArray<ZMUser*>*)getSpotlightingUserArray;
- (NSArray<ZMUser *> *)getSpotlightingUserArrayWithFilter:(ZMMTVideoFilter)filter;

- (void)spotlightUser:(ZMUser*)zmUser;
- (void)spotlightUser:(ZMUser*)zmUser removeOthers:(BOOL)removeOthers;
- (void)spotlightUserArray:(NSArray*)zmUser removeOthers:(BOOL)removeOthers;
- (void)stopSpotlightUser:(ZMUser*)zmUser;
- (void)stopSpotlightUserArray:(NSArray<ZMUser*>*)userArray;
- (void)stopSpotlightAllUser;

#pragma mark - drag layout
- (BOOL)shouldLockHostPosition;
- (BOOL)shouldLockSelfPosition;

- (BOOL)isFollowHostVideoOrderEnable;
- (BOOL)isFollowHostVideoOrder;
- (BOOL)shouldFollowHostVideoOrder;
- (void)setFollowHostVideoOrder:(BOOL)follow;

- (BOOL)isVideoDragMode;
- (BOOL)isVideoOrderMode;
- (NSArray<ZMUser*>*)getVideoOrderUserArray;
- (void)setVideoOrderUserArray:(nullable NSArray<ZMUser*>*)orderArray;
- (void)setVideoDragUserArray:(nullable NSArray<ZMUser*>*)dragArray;

#pragma mark - sort video by
- (ZMMTVideoSortType)effectiveVideoOrderSortType;
- (void)setVideoOrderSortType:(ZMMTVideoSortType)sortType;

#pragma mark - save video order
- (void)saveGalleryVideoOrderArray;
- (void)loadGalleryVideoOrderArray;

#pragma mark - zoom room order
- (BOOL)isMultiStreamGroupInPin:(ZMUser*)zmUser;
- (BOOL)isMultiStreamGroupInSpotlight:(ZMUser*)zmUser;
- (BOOL)isMultiStreamGroupInRaiseHand:(ZMUser*)zmUser;
- (NSMutableArray<ZMUser*>*)sortUserOrderArray:(NSMutableArray<ZMUser*> *)array;

#pragma mark - show/hide room view
// user action
- (BOOL)enableHideRoomViewForUser:(ZMUser *)user;

// current view status
- (BOOL)isRoomViewHiddenForUser:(ZMUser *)user;

- (void)showRoomViewForUser:(ZMUser *)user;
- (void)hideRoomViewForUser:(ZMUser *)user;

// 1 in main session
// 2 in gallery view mode
// 3 is zr user
// 4 room view not pinned / spotlighted / raise hand
- (BOOL)isValidUserForHideRoomView:(ZMUser *)user;

- (NSMutableArray<ZMUser *> *)filterRoomViewUserIfNeeded:(NSMutableArray<ZMUser *> *)zmUserArray;

@end

@protocol IZMMTPinVideoSinkProtocol <NSObject>
- (void)onSpotlightStatusChanged:(BOOL)inSpotlightMode;
- (void)onSpotlightGroupChanged;

- (void)onFollowVideoOrderStatusChanged;
- (void)onDragVideoLayoutStatusChanged;
- (void)onVideoOrderSortTypeChanged;

- (void)onGalleryVideoOrderSaved:(BOOL)ret;
- (void)onGalleryVideoOrderLoaded:(NSString*)orderString;
@end

@protocol IZMMTPinVideoStatusProtocol <ZMRoutableObject>
@optional
- (void)onPinnedGroupChanged:(ZMConfSession*)confSession;
- (void)onSpotlightGroupChanged:(ZMConfSession*)confSession;
- (void)onDraggedGroupChanged:(ZMConfSession*)confSession;
- (void)onVideoSortTypeChanged:(ZMConfSession*)confSession;
- (void)onRoomViewStatusChanged:(ZMConfSession*)confSession;
- (void)onPinnedAuxGroupChanged:(ZMConfSession*)confSession;
@end

NS_ASSUME_NONNULL_END
