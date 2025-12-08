//
//  ZMMTUserStatusProtocol.h
//  VideoUIBridge
//
//  Created by geno.chen on 2022/7/21.
//

#ifndef ZMMTUserStatusProtocol_h
#define ZMMTUserStatusProtocol_h

@class ZMUser;
@class ZMMTRosterList;

@protocol IZMMTUserStatusProtocol <NSObject>
@optional
- (void)userPSLivedStatusChange:(ZMUser *)user;
- (void)userActiveVideoChanged:(ZMUser *)user;
- (void)userActiveRSGWChanged:(ZMUser *)user;

- (void)userRosterCompleted:(ZMConfSession*)session;
- (void)userRosterChanged:(ZMConfSession*)session;
- (void)userKBRosterChanged:(ZMConfSession*)session;

- (void)userJoinByCoalesce:(NSArray<ZMUser*>*)userArray;
- (void)userLeftByCoalesce:(NSArray<ZMUser*>*)userArray;
- (void)userJoinWaitingRoomByCoalesce:(NSArray<ZMUser*>*)userArray;

- (void)userAudioStatusChangedByCoalesce:(NSArray<ZMUser*>*)userArray;
- (void)userVideoStatusChangedByCoalesce:(NSArray<ZMUser*>*)userArray;

- (void)userNameChangedByCoalesce:(NSArray<ZMUser*>*)userArray;
- (void)userNameTagChangedByCoalesce:(NSArray<ZMUser*>*)userArray;
- (void)userAvatarChangedByCoalesce:(NSArray<ZMUser*>*)userArray;
- (void)userAvatarChanged:(NSString *)jid confSession:(ZMConfSession*)confSession;
- (void)userNameTagChanged:(ZMUser *)user;

- (void)hostCohostStatusChanged:(ZMUser*)zmUser;
- (void)hostPermissionChanged:(ZMConfSession*)session user:(ZMUser *)user;
- (void)cohostPermissionChanged:(ZMConfSession*)session user:(ZMUser *)user;
- (void)onHostLeft:(ZMConfSession*)session user:(ZMUser *)user;
- (void)userMultiPinPriviligeChanged:(ZMUser*)zmUser;
- (void)userAudioTypeChanged:(ZMUser *)user;

- (void)userAttendeeRosterChanged:(ZMConfSession*)session;

- (void)feedbackChangedByCoalesce:(NSArray<ZMUser*> *)userArray;
- (void)usersHandStatusChangedByCoalesce:(NSArray<ZMUser*> *)userArray;
- (void)webinarAttendeeHandStatusChangedByCoalesce:(NSArray<ZMUser*> *)userArray;
- (void)userFeedbackDidCleanedUp:(ZMConfSession *)confSession;

- (void)practiceSessionCountChanged:(NSUInteger)count;
/**
 CMD_USER_ALLOW_VIEWONLY_TALK,
 CMD_USER_DISALLOW_VIEWONLY_TALK
 */
- (void)userAllowTalkStatusChanged:(ZMUser *)user;
- (void)onUserRosterChanged:(ZMMTRosterList *)roster session:(ZMConfSession*)session;

- (void)onMasterUserLeft:(ZMConfSession*)session;

@end


#endif /* ZMMTUserStatusProtocol_h */
