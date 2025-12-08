//
//  ZMPBOHelper.h
//  VideoUIBridge
//
//  Created by Javenlee Li on 2023/3/13.
//

#import <zVideoUIBridge/ZMBaseHelper.h>

@class ZMPBORoomModel, ZMPBOUserModel;

NS_ASSUME_NONNULL_BEGIN

@interface ZMPBOHelper : ZMBaseHelper
- (BOOL)isPBOEnable;
- (BOOL)isInPBOSession;
- (BOOL)canCreatePBO;
- (NSString *)getRoomName;
- (NSString *)getRoomNameWithID:(NSInteger)roomID;

- (BOOL)isUserInPBO:(ZMUser *)zmUser;
- (BOOL)isUserLeavingPBO:(ZMUser *)zmUser;

- (BOOL)isRoomOwner;
- (BOOL)moveOutPBO:(NSInteger)roomID user:(ZMUser *)user;
- (BOOL)closePBOWithRoomID:(NSInteger)roomID;
- (BOOL)leaveCurrentPBO;
- (BOOL)closeAllPBO:(NSUInteger)countDownSeconds;
- (BOOL)closeMyPBO;

- (NSInteger)getPBOPermission;
- (void)changePBOPermission:(NSInteger)permission;

- (NSInteger)getRoomCount;
- (nullable ZMPBORoomModel *)getRoomWithID:(NSInteger)roomID;
- (NSArray<ZMPBORoomModel *> *)getRooms;
- (NSArray<ZMPBOUserModel *> *)getUserByUniqueJoinIndex:(ZMUserID)uniqueJoinIndex;
- (NSInteger)getRoomIndexWithID:(NSInteger)roomID;
- (NSInteger)getRoomUserCountWithID:(NSInteger)roomID;
- (BOOL)isRoomHasUserWithID:(NSInteger)roomID;
- (ZMUserID)getRoomCreatorUniqueJoinIndexWithID:(NSInteger)roomID;
- (NSArray<ZMPBOUserModel *> *)getRoomUsersWithID:(NSInteger)roomID;
- (nullable ZMPBOUserModel *)getRoomUserWithID:(NSInteger)roomID uniqueJoinIndex:(ZMUserID)uniqueJoinIndex;

- (NSArray<ZMPBORoomModel *> *)transferToRoomModel:(const std::vector<std::shared_ptr<zm::pbo::IPBORoom>>&)rooms;
- (NSArray<ZMPBOUserModel *> *)transferToUserModel:(const std::vector<std::shared_ptr<zm::pbo::IPBOUser>>&)users;

@end

NS_ASSUME_NONNULL_END
