//
//  ZMUser.h
//  ZCommonUI
//
//  Created by francis on 3/28/17.
//  Copyright © 2017 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, ZMUserType){
    ZMUserType_CmmUser      = 1<<0,
    ZMUserType_LeftUser     = 1<<1,
    ZMUserType_MasterUser   = 1<<2,
    ZMUserType_ViewOnly     = 1<<3,
    ZMUserType_Specific     = 1<<4,
    ZMUserType_Invitee      = 1<<5,
};

#ifdef __cplusplus
class ICmmUser;
class IZoomQABuddy;
#endif
@class ZMConfSession;

@interface ZMUser : NSObject<NSCopying>
@property(nullable,nonatomic,retain) ZMConfSession* confSession;

@property(assign) ZMUserType userType;
@property(readonly,assign) ZMUserID userId;//MMR protection
@property(readonly,assign) ZMUserID defaultUserId;
@property(readonly,assign) ZMUUID   userUUID;
@property(readonly,assign) ZMUJID   userUJID;
@property(nullable,readonly,copy) NSString*      GUID; /// PII
@property(nullable,readonly,copy) NSString*      userJid; /// PII
@property(nullable,readonly,copy) NSString*      CUID;/// PII - conf user id
@property(nullable,readonly,copy) NSString*      deviceID; /// PII
@property(nullable,readonly,copy) NSString*      email;/// PII - ZOOM-276920 /// If an invitee don't have CUID, we have to use email to identify.
@property(nullable,readonly,copy) NSString*  specificID;
@property(nonatomic, readonly) NSString *identifier;
@property(nullable,copy) NSString* specificUserName;

///may be return nil, eg: attendee in webinar bo
@property(readonly,assign) ZMUser* defaultUser;
@property(readonly,assign,nullable) ZMUser* masterUser;
@property(readonly,assign,nullable) ZMUser* viewOnlyUser;//cmmuser transfer to QAbuddy

@property(readonly,assign)BOOL         isLeftUser;
@property(readonly,assign)BOOL         isMasterUser;
@property(readonly,assign)BOOL         isViewOnly;
@property(readonly,assign)BOOL         isValid;
@property(readonly,assign)BOOL         isFreeWayIndexUser;
@property(readonly,assign)BOOL         isMultistreamUser;
@property(readonly,assign)BOOL         isPairedZRUser;
@property(readonly,assign)BOOL         isSmartGalleryVideoUser;
@property(readonly,assign)BOOL         isMyself;
@property(readonly,assign)BOOL         isSupportSilentMode;
@property(readonly,assign)BOOL         isInSilentMode;
@property(readonly,assign)BOOL         isHostCohost;
@property(readonly,assign)BOOL         isHost;
@property(readonly,assign)BOOL         isCoHost;
@property(readonly,assign)BOOL         isWatchOnlyUser;
@property(readonly,assign)BOOL         isVirtualAssistantUser;
@property(readonly,assign)BOOL         isRTMPUser;
@property(readonly,assign)BOOL         isActiveRTMPUser;
@property(readonly,assign)BOOL         isSimuliveUser;
@property(readonly,assign)BOOL         isActiveSimuliveUser;
@property(readonly,assign)BOOL         isGatewayPSLProducer;
@property(readonly,assign)BOOL         isVideoSceneUser;
@property(readonly,assign)BOOL         isActiveVideoSceneUser;

@property(readonly,assign)BOOL         isViewOnlyInDefaultSession;
@property(readonly,assign)BOOL         isSupportProctoringMode;
@property(readonly,assign)BOOL         isInCompanionMode;
@property(readonly,assign)BOOL         isSupportZESwitchCompanionMode;
@property(readonly,assign)BOOL         isZECompanionUser;
@property(readonly,assign)BOOL         isRaiseHand;
@property(readonly,assign)BOOL         isSupportSubChat;
@property(readonly,assign)BOOL         isSupportPrivateChat;
@property(readonly,assign)NSUInteger   raiseHandIndex;
@property(readonly,assign)BOOL         isInPBO;

#ifdef __cplusplus
+ (instancetype)userWithCmmUser:(ICmmUser*)user;
+ (instancetype)userWithCmmUser:(ICmmUser*)user confSession:(nullable ZMConfSession*)confSession;
+ (instancetype)leftUserWithCmmUser:(ICmmUser*)user confSession:(ZMConfSession*)confSession;
+ (instancetype)masterUserWithCmmUser:(ICmmUser*)user;
+ (instancetype)masterLeftUserWithCmmUser:(ICmmUser*)user;
+ (instancetype)userWithBuddy:(IZoomQABuddy*)buddy;
+ (nullable instancetype)userWithInviteeItem:(NS_ZOOM_DATA::ConfInviteeItem*)item;
+ (nullable instancetype)userWithInviteeCUID:(nullable NSString*)CUID email:(nullable NSString*)email;
+ (instancetype)userWithZmUser:(ZMUser*)zmUser;

+ (nullable id)userWithID:(ZMUserID)ID confSession:(ZMConfSession*)confSession;
+ (id)userWithSpecificID:(NSString*)specificID;
+ (nullable id)userWithUJID:(ZMUJID)uniqueJoinIndex confSession:(ZMConfSession*)confSession;

- (nullable ICmmUser *)getCmmUser;
- (nullable ICmmUser *)masterCmmUser;//BO get master user
- (nullable ICmmUser *)getLeftCmmUser;
- (nullable NS_ZOOM_DATA::ConfInviteeItem *)getInviteeItem;
- (nullable IZoomQABuddy*)getBuddyUser;
#endif

- (nullable NSImage *)avatarWithSize:(NSSize)size;

- (NSString *)originalName;//without change TWFlag
- (NSString *)masterUserName;
- (NSString *)userName;
/// This leftUserName is used only by invitee who joined once and left participant list.
- (NSString *)leftUserName;
- (nullable NSString *)effectiveVBFileID;
- (nullable NSString *)domainString;

@end
NS_ASSUME_NONNULL_END
