//
//  ZMMTUserHelper.h
//  VideoUIBridge
//
//  Created by geno.chen on 2022/7/11.
//

#import <zVideoUIBridge/ZMBaseHelper.h>
#import <zVideoUIBridge/NSMutableArray+ZMUserHelper.h>
NS_ASSUME_NONNULL_BEGIN

@class ZMUser;
@class ZMMTNameTag;

@interface ZMUserHelper : ZMBaseHelper

+ (ZMUserHelper*)sharedHelper;

- (int)getAllUserCount;
#ifdef __cplusplus
- (NSInteger)getAllUserCount:(int&)outHost coHost:(int&)outCoHost waiting:(int&)outWaiting tempTalk:(int&)outTempTalk;//ZOOM-15291
- (NSInteger)getUserCountWithFilter:(ZMUserExcludeFilter)filter;
- (NSInteger)getUserCount:(const std::vector<zm::UserConstraint>&)vecConstraint;
- (BOOL)isSameUser:(ZMUserID)userA with:(ZMUserID)userB;
- (BOOL)isSignLanguageInterpreterAllowedToTalkByCmmUser:(ICmmUser*)inCmmUser; //ZOOM-330475
#endif
- (BOOL)userVideoCanMuteByHostWithUser:(ZMUser *)theUser;
- (BOOL)userVideoCanUnmuteByHostWithUser:(ZMUser *)theUser;
- (BOOL)amIHost;
- (BOOL)amICoHost;
- (BOOL)amIHostCoHost;
- (BOOL)amIBOModerator;
- (BOOL)amIOriginalHost;
- (BOOL)amIAltHost;
- (BOOL)amIMasterConfHost;
- (BOOL)amIInterpreter;
- (BOOL)amISignLanguageInterpreter;
- (BOOL)isMySelfForUserId:(ZMUserID)inUserId;
#ifdef __cplusplus
- (BOOL)isMySelfForUniqueJoinIndex:(CmmUInt32)uniqueJoinIndex;
- (ZMUserID)getMyUserId;
- (NSString *)getMyUserGUID;
- (CmmUInt32)getMyUniqueJoinIndex;
#endif

- (nullable ZMUser *)getMyzmUser;
- (nullable ZMUser *)getZmHostUser;
- (nullable ZMUser *)getMasterZmHostUser;
- (long long)getMyAttendeeId;

#ifdef __cplusplus
- (nullable ICmmUser*)getMySelf;
- (nullable ICmmUser*)getMasterMySelf;
- (nullable ICmmUser*)getHostUser;
- (nullable ICmmUser*)getMasterOriginalHostUser;
- (nullable ICmmUser*)getLoginUserByEmail:(NSString *)email;
- (nullable ICmmUser*)getNonAnonymousJoinUserByEmail:(NSString *)email;
- (nullable NSArray <ZMUser *> *)getUserByUserEmail:(NSString *)email;
- (nullable ICmmUser*)getCmmUserByUserName:(NSString *)userName;
- (nullable NSString*)getUserNameByCmmUser:(ICmmUser*)inCmmUser;
- (NSString*)getUserPronounByCmmUser:(ICmmUser*)inCmmUser;//ZOOM-273485
- (NSString*)getUserNameById:(ZMUserID)inUserId;
- (NSString*)getUserPronounById:(ZMUserID)inUserId; //ZOOM-273485
- (NSString*)getLeftUserNameById:(int)inUserId;
- (nullable NSImage*)getAvatarByCmmUser:(ICmmUser*)inCmmUser;

//webinar attend info
- (nullable IZoomQABuddy*)getWebinarUserByUserId:(int)inUserId;
- (nullable IZoomQABuddy*)getWebinarUserByJid:(NSString*)inJid;
- (nullable IZoomQABuddy*)getWebinarUserByGuid:(NSString*)inGuid;
- (nullable IZoomQABuddy*)getMyWebinarUser;
#endif
- (NSString*)getWebinarUserNameByJid:(NSString*)inJid;
- (nullable NSArray<ZMUser*>*)getFilterBuddyListByKey:(NSString*)keyWord;
- (NSUInteger)getAttendeeCount;

- (NSUInteger)getRaiseHandUserCount;
- (NSUInteger)getPanelistRaiseHandUserCount;
- (int)getWebinarAttendeeRaiseHandUserCount;
- (nullable NSArray<ZMUser*>*)getOrderPanelistRaiseHandUserArray;
- (nullable NSString*)getTheOnlyRaiseHandUserName;
- (int)getPureTelephoneUserCount;


- (int)getNodeIdByUserId:(int)inUserId;
- (int)getPeerUserId;

- (nullable NSMutableArray<ZMUser*>*)getWaitingUsersArray;
- (nullable NSMutableArray<ZMUser*>*)getWaitingUsersArrayWithoutLeaving;
- (NSInteger)getWaitingUserCount;
- (int)getUserCountWithoutWaiting;
- (int)getFirstWaitingUserId;

- (BOOL)isGuestFeatureEnable;
- (BOOL)isGuestByUser:(ZMUser *)theUser;

- (BOOL)isLinkedInSwitchOn;//ZOOM-35020
- (nullable NSURL*)getLinkedInURLByUserID:(int)inUserId;//ZOOM-35020

- (BOOL)hasUserInSilenceMode;//ZOOM-46301

//ZOOM-115938
- (BOOL)hasPureCallInUser;
- (BOOL)hasNoAudioClientUser;
- (nullable NSArray*)getUsersCanMergeToUser:(ZMUser *)user;

#ifdef __cplusplus
//ZOOM-276920
/// When invitee has no conf user id use email to get ConfInviteeItem struct
- (nullable NS_ZOOM_DATA::ConfInviteeItem *)getConfInviteeItemByCUID:(NSString *)confuserId orByEmail:(NSString *)email;
/// Return yes, if invitee joined current meeting / in waiting room/ in break room
/// Return no, if invitee never joined, left meeting
- (BOOL)isInviteeInMeeting:(NS_ZOOM_DATA::ConfInviteeItem *) inviteeItem;//ZOOM-276920
#endif

- (BOOL)canIRenameUserWithUser:(ZMUser *)theUser;

- (BOOL)canIRemoveUser:(ZMUser *)theUser;//ZOOM-177544

- (nullable NSArray*)getAllHostCoHostUserIds;//ZOOM-271443
- (nullable NSArray<ZMUser *> *)getAllHostCoHostUserArray;
- (NSArray*)getMultiStreamGroupUsersForUser:(ZMUser*)zmUser;
- (nullable NSArray*)getChildrenForUser:(ZMUser*)zmUser;
- (nullable NSArray*)getMultiStreamChildrenForUser:(ZMUser*)zmUser;
- (nullable ZMUser*)getParentUserForUser:(ZMUser*)zmUser;
- (BOOL)hasChildrenForUser:(ZMUser*)zmUser;
- (BOOL)isAvailableParentUser:(ZMUser*)zmUser;
- (BOOL)hasMultiStreamChildrenForUser:(ZMUser*)zmUser;
- (BOOL)hasSmartGalleryChildrenForUser:(ZMUser*)zmUser;
- (nullable NSArray<ZMUser *> *)getAllRSGWUserArray;

- (nullable ZMUser *)getZmUserByUserId:(ZMUserID)userID;
- (nullable ZMUser *)getE2EELeaderUser;

// before confReady
- (nullable ZMMTNameTag *)getMyNameTag;

- (NSInteger)legalParticipantCount;
- (NSInteger)legalAttendeCount;
- (int)getParticipantUserCount;//from MMR calculated every second

#ifdef __cplusplus
- (nullable ICmmUserList*)getCmmUserList;
- (nullable ICmmUserList*)getMasterCmmUserList;

- (nullable ICmmUser*)getCmmUserByGUID:(NSString*)GUID;
- (nullable ICmmUser*)getCmmLeftUserByGUID:(NSString*)GUID;
- (nullable ICmmUser*)getMasterCmmUserByGUID:(NSString*)GUID;

- (nullable ICmmUser*)getCmmUserById:(ZMUserID)userId;
- (nullable ICmmUser*)getCmmUserByUUID:(ZMUUID)UUID;
- (nullable ICmmUser*)getCmmUserByUJID:(ZMUJID)UJID;
- (nullable ICmmUser*)getCmmLeftUserById:(ZMUserID)userId;
- (nullable ICmmUser*)getCmmLeftUserByUUID:(ZMUUID)UUID;
- (nullable ICmmUser*)getCmmLeftUserByUJID:(ZMUJID)UJID;
- (nullable ICmmUser*)getCmmLeftUserByCUID:(NSString *)CUID;

- (nullable ICmmUser*)getMasterUserById:(ZMUserID)userId;
- (nullable ICmmUser*)getMasterCmmUserByUUID:(ZMUUID)UUID;
- (nullable ICmmUser*)getMasterCmmUserByUJID:(ZMUJID)UJID;
- (nullable ICmmUser*)getMasterCmmLeftUserById:(ZMUserID)userId;
- (nullable ICmmUser*)getMasterCmmLeftUserByUUID:(ZMUUID)UUID;
- (nullable ICmmUser*)getMasterCmmLeftUserByUJID:(ZMUJID)UJID;
#endif

- (BOOL)canIAdmitOthersWhenNoHost;
- (BOOL)isSupportWaitingAdmit;
//ZOOM-570490
- (BOOL)isMeetingAccountAdmin;
- (BOOL)isSupportEnableSummaryWorkflow;
- (BOOL)isSupportStartSummaryWorkflow;
- (BOOL)hasSupportEnableSummaryAdminInMeeting;
- (BOOL)hasSupportStartSummaryUserInMeeting;

//ZOOM-576025
- (BOOL)isSupportEnableQueryWorkflow;
- (BOOL)isSupportStartQueryWorkflow;
- (BOOL)hasSupportEnableQueryAdmin;
- (BOOL)hasSupportStartQueryUserInMeeting;

- (BOOL)isSupportControlAICompanion;
- (BOOL)hasSupportControlAICompanionHostCoHost;
- (BOOL)hasHostCoHostInMeeting:(BOOL)onlyInMainSession;
- (BOOL)hasSpeechToBoUserInMeeting;
- (BOOL)isSupportClinicalNote;
- (BOOL)isSupportLiveSummary;
- (BOOL)hasSupportLiveSummaryHostCoHost;
- (BOOL)isWatchOnlyUser;
- (BOOL)isAICWatchOnlyUser;
- (BOOL)isAICRestrictedUser;

//ZOOM-10609
- (BOOL)isEnableParticipantID;

#ifdef __cplusplus
//jeffery add
- (nullable ICmmUser*)getCmmUserByConfUserId:(NSString*)ZoomId;
#endif

- (nullable NSString *)getUserEmail:(ZMUser *)zmUser;
- (BOOL)isPSProducerWithUser:(ZMUser *)zmUser;
- (BOOL)isInGreenRoomWithUser:(ZMUser *)zmUser;
- (BOOL)isEnterSubWithUser:(ZMUser *)zmUser;

- (BOOL)hasCoHostUserInMeeting;
- (BOOL)hasCoHostUserInMeetingWithBO;
- (BOOL)isSupportBackgroundTransparencyWithUser:(ZMUser *)zmUser;
- (BOOL)isSupportBackgroundTransparencyWithUserId:(ZMUserID)userId;

- (BOOL)isActiveRTMPUser:(ZMUser *)zmUser;
- (nullable ZMUser *)getActiveRTMPUser;

- (BOOL)isActiveSimuliveUser:(ZMUser *)zmUser;
- (BOOL)isActiveVideoSceneUser:(ZMUser *)zmUser;

@end

NS_ASSUME_NONNULL_END
