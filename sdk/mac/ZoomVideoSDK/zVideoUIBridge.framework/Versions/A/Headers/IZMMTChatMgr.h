//
//  IZMMTChatMgr.h
//  VideoUIBridge
//
//  Created by Cain Zhou on 2022/11/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMMTMessageProtocol <NSObject>
@property (nonatomic, strong, readonly) NSString *message;
@property (nullable, nonatomic, strong, readonly) NSString *urlStr;
@property (nonatomic, assign, readonly) NSUInteger startIndex;
@property (nonatomic, assign, readonly) NSUInteger length;
@end

@class ZMMTChatUserModel;
@class ZMMTOldChatBaseItem;
@class ZMMTChatMessageModel;
@protocol IZMMTChatMgr <ZMRoutableObject>

//MainSession Only
@property (nonatomic, assign) long sendToID;
@property (nonatomic, retain) NSString *sendToJID; // attendee try to talk
@property (nonatomic, readonly) NSString *sessionID;
@property (nonatomic, readonly) ZMMTChatUserModel *sendToUser;
//Old Chat Only
@property (nonatomic, readonly) NSArray<ZMMTOldChatBaseItem*> *oldChats;

//State
@property (nonatomic, readonly) ZMConfSession *confSession;
@property (nonatomic, readonly) NSWindow *chatWindow;
@property (nonatomic, readonly) NSString *chatTitle;
@property (nonatomic, readonly) NSUInteger unread;
@property (nonatomic, readonly) BOOL isChatOpened;
@property (nonatomic, readonly) BOOL isChatOpening;
@property (nonatomic, readonly) BOOL isChatShowing;
@property (nonatomic, readonly) BOOL isChatPopout;
@property (nonatomic, readonly) BOOL isChatRespondable; //for cmd -/+ shortcuts

- (void)closeChat;
- (void)openChat;
- (void)openChatAgain; // close + open
- (void)openChatWithUser:(nullable ZMUser*)zmUser;
- (void)openChatWithGroup:(int)type;
- (void)openChatWithMessage:(ZMMTChatMessageModel*)message;
- (void)jump2Message:(NSString*)messageID;
- (BOOL)sendMessage:(NSString*)message msgType:(int)msgType userID:(uint32_t)userID;
- (ZMMTChatUserModel*)chatUserForSession:(NSString*)sessionID threadID:(NSString*)messageID;

- (BOOL)isSessionCreated:(NSString*)sessionID;
- (void)markSessionCreated:(NSString*)sessionID;
- (void)markSessionRemoved:(NSString*)sessionID;
- (void)makeInputViewFirstResponder;

//Old Chat Only
- (void)onChatMessageReceived:(NSString*)msgID;
- (void)onChatMessageDeleted:(NSString*)msgID deleteBy:(int)deleteBy;

- (void)onChatFileUploaded:(NSString*)msgID result:(NSUInteger)result;
- (void)onChatFileProgress:(NSString*)msgID ratio:(NSUInteger)ratio size:(NSUInteger)size speed:(NSUInteger)speed;
- (void)onChatFileStateChanged:(NSString*)msgID;

#ifdef __cplusplus
- (void)onChatShareFileInMeeting:(const ShareFileInMeetingChatParam_s&)shareFile;
#endif

- (void)onChatGetPublicDownloadLink:(NSString*)msgID ret:(BOOL)ret;
- (void)onChatDownloadMessageFile:(id)messageItem;

- (void)onZappMessageUpdated:(NSString*)appId iconPath:(NSString*)iconPath;
- (void)onZappMessageUpdated:(NSString*)msgId thumbnailPath:(NSString*)thumbnailPath;
- (void)onZappMessageLoginStateUpdated:(BOOL)logined;

#ifdef __cplusplus
- (void)onChatShareDocsInMeeting:(zm::docs::MeetingDocsInfo*)docsInfo;
#endif
- (void)onChatShareClipsInMeeting:(id<ZMMTMessageProtocol>)model;
@end

@protocol ZMMTChatMgrSinkProtocol <NSObject>
@optional
//privilege
- (void)onPanelistPrivilegeChanged;
- (void)onAttendeePrivilegeChanged;

- (void)onArchiveInE2EMeetingChanged;
- (void)onChatDisableByDLPChanged;

- (void)onInfoBarrierChanged;
- (void)onFileInfoBarrierChanged;

- (void)onChattedAttendeeUpdate:(ZMUserID)attendeID;
@end

@class ZMMTChatGroupItem;
@protocol ZMMTChatControllerProtocol <NSObject>
@property (nonatomic, readonly) ZMMTChatGroupItem *groupItem;
@property (nonatomic, readonly) BOOL isSendingMessage;

- (void)jump2Message:(NSString*)messageID;
- (BOOL)sendMessage:(NSString*)message msgType:(int)msgType userID:(uint32_t)userID;
- (BOOL)checkRespond2Message:(NSString*)messageID sessionID:(NSString*)sessionID;
- (void)makeInputViewFirstResponder;

- (void)viewDidShow;
- (void)viewWillHide;

- (void)runShortcut:(NSUInteger)type; //ZMMTChatShortcutType

@optional // new chat only
- (void)updateFontSize;
- (void)switch2SilentMode;
@end

@protocol ZMMTChatViewStatusProtocol <NSObject>

@optional
- (void)onChatTitleUpdated;
- (void)onChatSendToUpdated;
- (void)onChatInTeamChatMUCUpdated; // new chat only
- (void)onChatInMeetingDBLoaded;  // new chat only
- (void)onChatInMeetingDataLoaded; // new chat only -> for history
- (void)onChatInMeetingDataRefreshed;

- (void)onChatSidePanelSizeChanged;
- (void)onChatErrorOccured:(NSString*)errText;
- (void)onChatSaved;

- (void)onAvatarStatusChanged;

- (void)onZappMessageUpdated:(NSString*)appId iconPath:(NSString*)iconPath;
- (void)onZappMessageUpdated:(NSString*)msgId thumbnailPath:(NSString*)thumbnailPath;
- (void)onZappMessageLoginStateUpdated:(BOOL)logined;

- (void)onUnreadCountChanged;
@end

@protocol ZMMTOldChatViewStatusProtocol <NSObject>

- (void)onChatItemsReceived:(NSArray<ZMMTOldChatBaseItem*>*)items isSelfSend:(BOOL)isSelfSend;
- (void)onChatItemsDeleted:(NSArray<ZMMTOldChatBaseItem*>*)item;

- (void)onChatItemFileUploaded:(ZMMTOldChatBaseItem*)item result:(NSUInteger)result;
- (void)onChatItemFileProgressUpdated:(ZMMTOldChatBaseItem*)item;
- (void)onChatItemFileStateUpdated:(ZMMTOldChatBaseItem*)item;
#ifdef __cplusplus
- (void)onChatShareFileInMeeting:(const ShareFileInMeetingChatParam_s &)shareFile;
#endif
- (void)onChatItemUpdated:(ZMMTOldChatBaseItem*)item;
- (void)onChatToSelected;

@end


@protocol ZMMTScreenShotProtocol <ZMRoutableObject>
@optional
- (void)onChatBeginScreenShot:(BOOL)needHideWindow;
- (void)onChatEndedScreenShot:(BOOL)shotSuccess;
@end

NS_ASSUME_NONNULL_END
