//
//  ZMBOHelper.h
//  VideoUIBridge
//
//  Created by Francis Zhuo on 10/9/22.
//

#import <zVideoUIBridge/ZMBaseHelper.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMBOHelper : ZMBaseHelper

#pragma mark - Old BO
- (BOOL)isBOEnable;
- (BOOL)isInBOSession;
- (BOOL)isBOHost;
- (BOOL)isBOModerator;
- (BOOL)isUserAssignedToBO:(ZMUser *)zmUser;
- (BOOL)isMoveParticipantFromWaitingRoomToBOEnabled;
- (NSString *_Nullable)getBORoomName;

#pragma mark - New BO
- (BOOL)isNewBOEnabled;
- (BOOL)isInNewBOSession;
- (BOOL)isLeavingNewBOSession;
- (BOOL)needToBeBuilt;
- (BOOL)canEditWhileStart;
- (BOOL)canControlBO;
- (BOOL)isInBOStatus:(zm::new_bo::bo_user_status)status;
- (BOOL)isBOListReady;
- (zm::new_bo::bo_status)getBOStatus;
- (BOOL)getUserWhoStartBO:(CmmUInt32&)unique_join_index isMySelf:(CmmBool&)isMySelf;
- (BOOL)getUserWhoStopBO:(CmmUInt32&)unique_join_index isMySelf:(CmmBool&)isMySelf ;
- (std::vector<std::shared_ptr<zm::new_bo::IBORoom>>)getBORooms;
- (std::shared_ptr<zm::new_bo::IBORoom>)getBORoomWithID:(NSInteger)roomID;
- (NSInteger)getMaxRoomLimits;
- (NSInteger)getMaxRoomUserLimits;
- (BOOL)getBORemainTimerTime:(NSInteger&)seconds;
- (BOOL)getBORemainStopTime:(NSInteger &)seconds;
- (std::shared_ptr<zm::new_bo::IBuild>)getBuilder;
- (zm::new_bo::Configs)getConfig;
- (zm::new_bo::Configs)getDefaultConfig;
- (std::shared_ptr<zm::new_bo::IDraftConfig>)getDraftConfig;
- (NSString*)getRoomName;
- (NSString*)getRoomName:(std::shared_ptr<zm::new_bo::IBORoom>)room;
- (NSString*)getRoomNameWithID:(NSInteger)roomID;
- (nullable ICmmUser *)getUserByUniqueJoinIndex:(ZMUserID)uniqueJoinIndex;
- (nullable IZoomQABuddy *)getBuddyByUniqueJoinIndex:(ZMUserID)uniqueJoinIndex;
- (nullable ICmmUser *)getLeftUserByUniqueJoinIndex:(ZMUserID)uniqueJoinIndex;
- (std::shared_ptr<zm::new_bo::IParticipant>)getParticipantByUniqueJoinIndex:(ZMUserID)uniqueJoinIndex;
- (NSInteger)getRoomCount;

- (BOOL)canLeaveBOFreely;

- (BOOL)isEnableTimer;

- (BOOL)isInNewBOWithUser:(ZMUser*)zmUser;
- (BOOL)isInNewBOWithBuddy:(IZoomQABuddy *)buddy;
- (BOOL)isInNewBO:(ICmmUser*)cmmUser;

- (BOOL)isCmmUserInMainSession:(ICmmUser*)cmmUser;
- (nullable ZMUser*)getDefaultUserForUser:(ZMUser*)zmUser;

- (BOOL)isUserInMainSession:(ZMUserID)uniqueJoinIndex;
- (BOOL)isUserBelongToRoom:(ZMUserID)uniqueJoinIndex;
- (BOOL)isUserUnassigned:(ZMUserID)uniqueJoinIndex;
- (BOOL)isUserExist:(ZMUserID)uniqueJoinIndex;
- (BOOL)canBroadcastMessage;

- (BOOL)needAttendeeConfirmJoinWebinarBO;
- (void)agreeWebinarBODisclaimer:(BOOL)agree;

- (void)markUITip:(int)uiTip;
- (BOOL)isUITipMarked:(int)uiTip;

// capacity
- (NSInteger)getMaxParticipantLimits;
- (BOOL)isReachParticipantLimits;

- (BOOL)canLoadPreAssign:(zm::new_bo::pre_assign_type)type;
- (BOOL)isLoadingPreAssign;
- (BOOL)canSaveBO;

// bo activity
- (BOOL)isViewBOActivityEnabled;
- (BOOL)needPromptViewBOActDisclaimer;

- (BOOL)needPromptStopShareWhenSwitchRoom;
- (void)setNeedPromptStopShareWhenSwitchRoom:(BOOL)needPrompt;

- (BOOL)isAllowChangeBOConfigWhileBOInActionEnabled;

#pragma mark - SpotsBO
#ifdef ENABLE_ZAPP
- (NSString*)getSpotsBORoomName:(std::shared_ptr<zm::spots::IBubble>)room;
- (nullable ICmmUser *)getSpotsUserByUniqueJoinIndex:(ZMUserID)uniqueJoinIndex;
- (BOOL)isSpotsEnabled;
- (BOOL)isInSpotsBOSession;
- (NSString*)getSpotsBORoomName;
- (BOOL)isInSpotsBOWithUser:(ZMUser*)zmUser;
#endif

#pragma mark - NextBO
- (nullable ICmmNextBOSession *)getNextBOSession;
- (BOOL)hasNextBOData;
- (NSString *)getNextBOSessionName;
- (NSString *)createNextBOSession:(NSString *)name;
- (void)updateNextBOSessionInfo:(NSString *)BID
                    sessionName:(NSString *)name
                      userArray:(NSArray<NSString *> *)array;
- (void)removeNextBOSession:(NSString *)BID;
- (void)getNextBOSetting:(CmmBOConfigData&)setting;
- (void)updateNextBOSetting:(const CmmBOConfigData&)setting;
- (void)deleteAllNextBOSessions;
- (void)setNeedStartNextBOSession:(BOOL)needStart;
- (nullable ICmmBOObject *)getBOObjectByUserGUID:(NSString *)userGUID;

- (BOOL)nextBONeedToBeBuilt;
- (std::shared_ptr<zm::new_bo::IBuild>)getNextBOBuilder;
- (NSInteger)getNextBORoomCount;
- (std::vector<std::shared_ptr<zm::new_bo::IBORoom>>)getNextBORooms;
- (std::shared_ptr<zm::new_bo::IBORoom>)getNextBORoomWithID:(NSInteger)roomID;
- (NSString*)getNextBORoomNameWithID:(NSInteger)roomID;
- (NSInteger)getNextBOMaxRoomLimits;
- (NSInteger)getNextBOMaxRoomUserLimits;
- (zm::new_bo::Configs)getNextBOConfig;
- (std::shared_ptr<zm::new_bo::IDraftConfig>)getNextBODraftConfig;
- (std::shared_ptr<zm::new_bo::IParticipant>)getNextBOParticipantByUniqueJoinIndex:(ZMUserID)uniqueJoinIndex;
- (BOOL)isNextBOUserBelongToRoom:(ZMUserID)uniqueJoinIndex;
- (BOOL)isNextBOUserUnassigned:(ZMUserID)uniqueJoinIndex;
- (BOOL)isNextBOLoadingPreAssign;
- (NSInteger)getNextBOUnassignedCount;

@end

NS_ASSUME_NONNULL_END
