//
//  IZMMTBOControlMgr.h
//  VideoUI
//
//  Created by Francis Zhuo on 10/9/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ZMMTBORoomModel, ZMMTBOUserModel, ZMMTBOConfigModel, ZMMTBOUserListDataManager, ZMMTRosterList;
@protocol IZMMTBOHandlerChainProtocol;

typedef NS_ENUM(NSInteger, ZMMTBOEntryType) {
    ZMMTBOEntryTypeNone = 0,
    ZMMTBOEntryTypeControl,
    ZMMTBOEntryTypeSelfChoose,
    ZMMTBOEntryTypeReceiveInvitation,
    ZMMTBOEntryTypeCountdown,
    ZMMTBOEntryTypeAskForHelp,
};

typedef NS_ENUM(NSInteger, ZMMTBOUserType) {
    ZMMTBOUserTypeHost = 0,
    ZMMTBOUserTypeCoHost,
    ZMMTBOUserTypePanelist,
    ZMMTBOUserTypeAttendee,
};

typedef NS_OPTIONS(NSInteger, ZMMTBORoomAttributesType) {
    ZMMTBORoomAttributesTypeNone                = 0,
    ZMMTBORoomAttributesTypeName                = 1<<1,
    ZMMTBORoomAttributesTypeIndex               = 1<<2,
    ZMMTBORoomAttributesTypeUserCountOnMMR      = 1<<3,
    ZMMTBORoomAttributesTypeUserLimit           = 1<<4,
};

typedef NS_ENUM(NSInteger, ZMMTBOHandlerChainEventType) {
    ZMMTBOHandlerChainEventTypeNone = 0,
    ZMMTBOHandlerChainEventTypeStartBO,
    ZMMTBOHandlerChainEventTypeJoinBO,
};

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMTBOControlMgr <ZMRoutableObject>

- (void)onFeatureReady;

- (void)show;
- (void)close;

- (void)createRooms:(NSInteger)count withConfig:(ZMMTBOConfigModel *)config;
- (void)createRooms:(NSInteger)count;
- (void)createRoomsFromPollWithID:(NSString *)pollingID
                       questionID:(NSString *)questionID
                     enableLimits:(BOOL)enableLimits
                            count:(NSUInteger)count;
- (void)renameRoom:(ZMMTBORoomModel *)roomModel withName:(NSString *)name;
- (void)removeRooms:(NSArray<ZMMTBORoomModel *> *)rooms;

- (NSArray<ZMMTBORoomModel *> *)getRoomList;
- (NSArray<ZMMTBOUserModel *> *)getUserListInRoom:(ZMMTBORoomModel *)room;

- (void)moveUser:(ZMUserID)uniqueJoinIndex toRoom:(NSInteger)roomID force:(BOOL)force;
- (void)moveUserToMainSession:(ZMUserID)uniqueJoinIndex force:(BOOL)force removeFromBO:(BOOL)removeFromBO;

- (BOOL)startBO;
- (void)stopBO;
- (void)joinBO:(ZMMTBORoomModel *)roomModel;
- (void)leaveBO;

- (void)saveBOWithName:(NSString *)name forFutureUse:(BOOL)useInFuture;

- (void)broadcastMessage:(NSString *)message;
- (void)broadcastVoiceToBo:(BOOL)start;
- (BOOL)isBroadcastSpeaking;
- (NSString *)broadcastVoiceNoticeString;
- (void)onVoiceToBOStatusChanged:(BOOL)start;
- (BOOL)isBroadcastMessageEnabled;
- (BOOL)isBroadcastBOVoiceMsgEnabled;
- (BOOL)haveBroadcastVoiceCapacity;
- (void)startBroadcastVoiceByShortcut;
- (void)stopBroadcastVoiceByShortcut;
- (BOOL)checkIsMyBroadcastSpeaking;
- (NSInteger)checkBroadcastVoiceStatus;
- (void)onBOBroadcastVoice;

- (BOOL)canShowBOEntry;
- (ZMMTBOEntryType)getBOEntryType;
- (void)onBOEntryClicked:(id)sender;
- (NSInteger)getUnassignedUserCount;

- (void)onUserRosterChanged:(ZMMTRosterList *)roster session:(ZMConfSession*)session;
- (void)onAttendeeRosterChanged:(ZMMTRosterList *)roster session:(ZMConfSession *)session;

- (ZMMTBOUserListDataManager *)getUserListDataManager;
- (ZMMTBOUserType)getMyIdentity;
- (NSArray<ZMMTBORoomModel *> *)getMoveToRoomListWithUniqueJoinIndex:(ZMUserID)uniqueJoinIndex;

- (void)addBOHandler:(id<IZMMTBOHandlerChainProtocol>)handler forEventType:(ZMMTBOHandlerChainEventType)type;
/// There is no requirement to call "removeBOHandler" when handler is nil, because handler is weak reference.
- (void)removeBOHandler:(id<IZMMTBOHandlerChainProtocol>)handler forEventType:(ZMMTBOHandlerChainEventType)type;
- (void)resumeBOFlowWithContext:(NSDictionary *)context forEventType:(ZMMTBOHandlerChainEventType)type;

- (void)askForHelp;

- (void)onUserActivityStatusChanged:(ZMUser *)user;

@end

@protocol IZMMTBOControlRoomUpdateProtocol <NSObject>

@optional
- (void)onRoomAdd:(NSArray<ZMMTBORoomModel *> *)rooms;
- (void)onRoomRemove:(NSArray<ZMMTBORoomModel *> *)rooms;
- (void)onRoomUpdate:(NSArray<ZMMTBORoomModel *> *)rooms;
- (void)onRoomAttributesUpdate:(ZMMTBORoomModel *)room attributes:(ZMMTBORoomAttributesType)attributes;
@end

@protocol IZMMTBOControlUserUpdateProtocol <NSObject>

@optional
- (void)onBOUserRosterAdd:(NSArray<ZMMTBOUserModel *> *)users;
- (void)onBOUserRosterRemove:(NSArray<ZMMTBOUserModel *> *)users;
- (void)onBOUserRosterUpdate:(NSArray<ZMMTBOUserModel *> *)users;
- (void)onBOUserRosterChanged:(NSArray<ZMMTBOUserModel *> *)users uniqueJoinIndex:(ZMUserID)uniqueJoinIndex;

- (void)onPanelistRosterAdd:(NSArray<ZMMTBOUserModel *> *)users;
- (void)onPanelistRosterRemove:(NSArray<ZMMTBOUserModel *> *)users;
- (void)onPanelistRosterUpdate:(NSArray<ZMMTBOUserModel *> *)users;

- (void)onAttendeeRosterAdd:(NSArray<ZMMTBOUserModel *> *)users;
- (void)onAttendeeRosterRemove:(NSArray<ZMMTBOUserModel *> *)users;
- (void)onAttendeeRosterUpdate:(NSArray<ZMMTBOUserModel *> *)users;

- (void)onUnassignedUserCountChanged:(NSInteger)count;

- (void)boUserAvatarChangedByCoalesce:(NSArray<ZMMTBOUserModel *> *)users;

- (void)onBOUserActivityStatusChanged:(NSArray<ZMMTBOUserModel *> *)users;

@end

@protocol IZMMTBOControlAttributesUpdateProtocol <NSObject>

@optional
- (void)onStatusChangedFrom:(zm::new_bo::bo_status)oldValue to:(zm::new_bo::bo_status)newValue;
- (void)onControlStatusChangedFrom:(BOOL)oldValue to:(BOOL)newValue;
- (void)onConfigChangedFrom:(ZMMTBOConfigModel *)oldValue to:(ZMMTBOConfigModel *)newValue;

@end

@protocol IZMMTBOControlCountDownTimerProtocol <NSObject>

@optional
- (void)updateStoppingTick:(NSInteger)seconds;
- (void)onCountDownTimerBeat:(NSInteger)seconds;
- (void)onCountDownTimerStop;

@end

@protocol IZMMTBOHandlerChainProtocol <NSObject>

/// return value:
///     The flow can go on or not. Yes means can go on, no means will stopped at current handler.
- (BOOL)invokeWithContext:(NSDictionary *)context forEventType:(ZMMTBOHandlerChainEventType)type;

@end

@protocol IZMMTBOControlPreAssignProtocol <NSObject>

@optional
- (void)onBuildFromPoll;

@end

NS_ASSUME_NONNULL_END
