//
//  ZMMTChatHelper.h
//  VideoUIBridge
//
//  Created by Cain Zhou on 2022/11/8.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMBaseHelper.h>
#import <zVideoUIBridge/ZMUIConstants.h>
#ifdef __cplusplus
#import <zm_conf_universal_ui/zm_conf_universal_ui_api.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@class ZMUser;

#ifdef __cplusplus
class IZoomChatInWebinar;
class ICmmUser;
#endif

typedef NS_ENUM(NSUInteger, ZMTDLPResultType)
{
    ZMTDLPResultType_NotSet = 0,
    ZMTDLPResultType_NeedConfirm,
    ZMTDLPResultType_Block,
};

typedef NS_ENUM(NSUInteger, ZMMTChatFileType) {
    ZMMTChatFile_None,
    ZMMTChatFile_Normal,
    ZMMTChatFile_Giphy,
    ZMMTChatFile_Screenshot,
};

typedef NS_OPTIONS(NSUInteger, ZMMTChatFilter) {
    ZMMTChatFilter_None     = 0,
    ZMMTChatFilter_MySelf   = 1 << 0,
    ZMMTChatFilter_Silent   = 1 << 1,
    ZMMTChatFilter_EnterSub = 1 << 2,
    
    ZMMTChatFilter_IgnoreType = 1 << 5, //means no need to verify the actual user type, only used in member list
};

@interface ZMMTChatHelper : ZMBaseHelper

@property (nonatomic, readonly) NSString *DMInviteeName;
@property (nonatomic, readonly) NSString *DMOnlySessionID;
@property (nonatomic, readonly) BOOL showDMOnlyEnabled;
@property (nonatomic, readonly) BOOL showDMOnly;

@property (nonatomic, readonly) BOOL isKindOfInstantMeeting;

#ifdef __cplusplus
- (nullable IZoomChatInWebinar *)fetchWebinarChatComponent;
- (PANELIST_CHAT_PRIVILEGE)fetchPanelistChatPrivilege;
- (NSInteger)fetchRealUserID:(NSInteger)sendID GUID:(NSString*)GUID;
#endif
- (uint8_t)fetchAttendeeChatPrivilege;
- (BOOL)isWebinarChatSettingEnabled;

//chat permission
- (BOOL)isPrivateOff;
- (BOOL)isChatDisabledByInfoBarrier;
- (BOOL)isChatOff;
- (BOOL)isChatDisabledByArchive;
- (BOOL)isChatDisabledByDLP;
- (BOOL)isChatDisabledByRegulatedUserJoinE2EEMeeting;

// save chat
- (BOOL)hasSaveChatPrivilege; // show up the save chat item
- (BOOL)enableSaveChat; // enable to click the save chat item
- (BOOL)saveChatToFile;
- (BOOL)isSaveChatOff;

// user
- (BOOL)isUserInSilentMode:(long)uid;
- (BOOL)isGuestByUser:(ZMUser *)zmUser; // the condition is not connected with the guest web setting, which is different from `zmUserHelper`
- (int)fetchWebinarChattedAttendeeCount;
#ifdef __cplusplus
- (BOOL)isValidChatUser:(ICmmUser *)cmmUser; // filter self and silent
- (BOOL)isValidChatUser:(ICmmUser *)cmmUser filter:(ZMMTChatFilter)filter;
#endif
- (BOOL)canDirectChatToUser:(ZMUser*)zmUser;

// copy chat
- (BOOL)hasCopyChatPrivilege;
- (BOOL)isCopyChatEnabled;

// share chat
- (BOOL)shouldShowShareMeetingChat;

// delete chat
- (BOOL)hasDeleteChatPrivilege:(NSString *)messageId;
- (void)deleteMessage:(NSString *)messageId;
- (BOOL)isDeleteChatEnabled;

// Chat Etiquette Tool
- (ZMTDLPResultType)checkDLPPolicyWithContent:(NSString *)content;

// message
- (int)fetchMessageCount;
- (nullable NSString *)fetchMessageIDByIndex:(int)index isNotification:(BOOL *)isNotification;
#ifdef __cplusplus
- (nullable CmmChat::ICmmChatMessageItem *)fetchMessageByID:(NSString *)messageId;
#endif
- (void)notifyUnreadMessageCount:(int)num;

// tip of legal notice: who can see your messages
- (BOOL)isNoticeAvailable;
- (BOOL)isCMRNoticeAvailable;
- (BOOL)isLocalRecordingNoticeAvailable;

// file
- (BOOL)isFileTransferEnabled;
- (BOOL)needPromotePotentialSecurityIssueDialog:(NSString *)messageId needShowCheck:(BOOL *)needShow;
- (BOOL)needPromotePotentialSecurityIssueDialog:(NSString*)fileName senderGuid:(NSString*)senderGuid senderJid:(NSString*)senderJid needShowCheck:(BOOL *)needShowCheck;

#ifdef __cplusplus
- (BOOL)IsDropBoxInMeetingOn:(FileIntegrationOperation)op;
- (BOOL)IsOneDriveInMeetingOn:(FileIntegrationOperation)op;
- (BOOL)IsGoogleDriveInMeetingOn:(FileIntegrationOperation)op;
- (BOOL)IsBoxInMeetingOn:(FileIntegrationOperation)op;
- (BOOL)IsSharePointInMeetingOn:(FileIntegrationOperation)op;

- (ssb_xmpp::XmppError)uploadFile:(NSString *)filePath
     toUser:(long)userID
chatMsgType:(ChatMsgType)msgType;
- (ssb_xmpp::XmppError)downloadFile:(NSString *)filePath
  messageID:(NSString *)msgID;
- (BOOL)shareFileIntegrationTo:(long)receiveID
                       content:(const ShareFileInMeetingChatParam_s &)fileInfo
                   chatMsgType:(ChatMsgType)msgType;
#endif
- (BOOL)filePause:(NSString *)msgID;
- (BOOL)fileResume:(NSString *)msgID;
- (BOOL)fileCancel:(NSString *)msgID;
- (uint64_t)fetchFileTransferLimitSize; // Can be 0 if sdk makes some error.
- (unsigned long long)fetchMaxFileSize; // if `fetchFileTransferLimitSize` is 0, will return `512M`.
- (BOOL)isFileSizeFailed:(unsigned long long)size;
- (BOOL)isFileTypeBlocked:(NSString *)path;
- (BOOL)isFileTransferDisabledByInfoBarrier;
- (BOOL)isFileDisabledByInfoBarrier; // with `isFileTransferDisabledByInfoBarrier` || `isChatDisabledByInfoBarrier`

// webinar
- (void)updateChattedAttendees;
- (void)changeAttendeeChatPrivilege:(NSInteger)privilege;
- (void)changePanelistChatPriviledge:(NSInteger)privilege;

// window
- (BOOL)isPopupChatWindowEnabled;
- (void)setPopupChatWindowEnable:(BOOL)enable;

/* send messages for meeting & webinar
   params:
     - to user group: `receiverId` is `0`;
   ZOOM-46301: to silent users;
 */
#ifdef __cplusplus
- (BOOL)sendMessage:(NSString *)content to:(long)receiverId chatMsgType:(ChatMsgType)msgType;
- (BOOL)isSilentModeMessageType:(ChatMsgType)type;
#endif

// new chat & pmc
- (nullable NSString *)getContentMsgByMsgID:(NSString *)msgID;
- (BOOL)isPMCNewExperienceEnabled;
- (BOOL)isPMCForBackendEnabled;
- (BOOL)isPMCReplyChatDisabled;
- (BOOL)isPMCScreenShotEnabled;
- (BOOL)isScreenShotWithoutFileEnabled;
- (BOOL)isCMCLoadMsgHalfwayEnabled;
- (NSString *)fetchNewChatSessionId;
- (NSString *)sessionID;  //Zoom Meeting ChannelID

- (void)showInFinder;
- (void)refreshThreadData:(BOOL)inTeamChat;

- (BOOL)isChatDisabled;
- (BOOL)isChatDisabledByHost;
- (BOOL)isChatDisabledByConfig;
- (BOOL)isCopyDisabled;
- (BOOL)isEditDisabled;
- (NSString*)disableDetail;

- (BOOL)isChatDisabledBySecurity;
- (void)setChatDisabledBySecurity:(BOOL)bDisabled;

- (BOOL)isMySelfSupportPrivateChat;

- (BOOL)isDisableHyperLinkEnabled;

- (BOOL)canChatWithWR;
- (BOOL)canChatWithWRUser;
- (BOOL)canChatInWR;

- (BOOL)canChatWithGR;
- (BOOL)canChatWithMUC;
- (BOOL)canChatWithMain;

- (BOOL)restrictChat2UserId:(long)userId; //can select send to ZOOM-587410

- (BOOL)canSendChat2UserId:(long)userId;
- (BOOL)canSendChat2UserGuid:(NSString*)guid msgType:(NSInteger)msgType;
- (BOOL)canSendChat2UserConfId:(NSString*)userConfId msgType:(NSInteger)msgType;

- (BOOL)canSendFile2UserId:(long)userId fileType:(ZMMTChatFileType)fileType;
- (BOOL)canSendFileIntegration2UserId:(long)userId;

- (NSString *)getChatTitle;
- (NSString *)getLegalNotice:(BOOL)isSubChat;
- (NSString *)getLegalBtnText:(BOOL)isSubChat;

//MARK: - Sub Chat
- (BOOL)isSubChatEnabled;
- (BOOL)isSubChatForSession:(NSString*)sessionID;
- (BOOL)isMainChatForSession:(NSString*)sessionID;

- (BOOL)isCMCEnabledForDM;
- (BOOL)isCMCEnabledForSession:(NSString*)sessionID;
- (BOOL)isChatMessagedForSession:(NSString*)sessionID;
- (NSInteger)unreadCountForSession:(NSString*)sessionID;
- (NSInteger)unreadCountForAll;

- (uint32_t)createSubChatGroup:(ZMUser*)zmUser;
- (uint32_t)createSubChatGroup:(nullable NSString*)groupName userArray:(NSArray<ZMUser*>*)userArray;
- (BOOL)deleteSubChatGroup:(NSString *)groupID;
- (BOOL)modifySubChatGroup:(NSString *)groupID groupName:(NSString*)groupName;
- (BOOL)addSubChatGroupMembers:(NSString *)groupID userArray:(NSArray<ZMUser*>*)userArray;
- (BOOL)removeSubChatGroupMembers:(NSString *)groupID userArray:(NSArray<NSNumber*>*)userJIDArray;
- (BOOL)leaveSubChatGroup:(NSString*)groupID;
#ifdef __cplusplus
- (BOOL)getSubChatGroupList:(SubChatGroupList&)groupList;
- (BOOL)getSubChatGroupById:(NSString*)groupID groupInfo:(CmmSubChatGroupInfo&)groupInfo;
- (BOOL)getSubChatGroupByJoinIndex:(uint32_t)joinIndex groupInfo:(CmmSubChatGroupInfo&)groupInfo;
#endif

- (NSString*)sessionIDForGroupID:(NSString*)groupID;
- (NSString*)groupIDForSessionID:(NSString*)sessionID;

- (NSArray<NSString*>*)sessionIDsForMembers:(NSArray<NSNumber*>*)userArray;

//MARK: - Task
- (BOOL)isCreateZoomTasksEnabled:(NSString *)sessionID messageID:(NSString *)messageID;

//MARK: - Chat with AIC
- (BOOL)canShowChatWithAICCoachMark;
#ifdef __cplusplus
- (void)chatWithAICAction:(NS_ZM_CONF_UNIVERSAL_UI::AicAction)action;
#endif

- (void)initUniversalUI;
- (void)uninitUniversalUI;

#ifdef __cplusplus
- (int)checkMessageDeliveryCap:(nullable ICmmUser*)cmmUser buddy:(nullable IZoomQABuddy*)buddy;

- (nullable NS_ZOOM_MESSAGER::IZoomMessenger*)getZoomMessager;
#endif
@end

NS_ASSUME_NONNULL_END
