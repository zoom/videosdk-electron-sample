//
//  ZMChatUIInterfaceProtocol.h
//  ChatUI
//
//  Created by Groot Ding on 2022/3/31.
//  Copyright © 2022 Zoom. All rights reserved.
//

#ifndef ZMChatUIInterfaceProtocol_h
#define ZMChatUIInterfaceProtocol_h
#import <ZoomUnit/ZPZMailAdapter.h>

@class ZMUserProfileFloat;
@class ZMMessageAdapter;
@class ZMFileEntity;
@class ZMChatFileItem;
@class ZMUserProfileFloatViewController;
@class ZMProfileConfig;
@class ZMWKWebUserProfileViewController;

@protocol ZMChatUIBuddyParamProtocol <NSObject>

@optional
//type is from ZoomBuddyGroupBuddyType string,split by ",",like "1,2,3"
- (NSString *)contactType;
- (BOOL)isForInviteToMeeting;
- (BOOL)externalFlag;
- (NSInteger)category;
- (NSString *)reqSource;

@end

@protocol ZMChatUIInviteProtocol <NSObject>

@optional
- (void)showInviteWindow;
- (void)closeInviteWindow;
- (void)startChatWithSessionID:(NSString *)sessionID;

@end

@protocol ZMChatUISearchInterfaceProtocol <NSObject>

- (NSString *)searchBuddy:(NSString *)key param:(id<ZMChatUIBuddyParamProtocol>)param callBack:(void(^)(NSString *key,NSArray <NSString *> * jids,NSError *error))callBack;

- (NSString *)asyn_searchLocalBuddyByKey:(NSString *)key callBack:(void(^)(NSString *key,NSArray <NSString *> * jids,NSError *error))callBack;

- (void)removeBuddySearch:(NSString *)key;

- (void)refreshBuddyVCards:(NSArray<NSString *> *)jids;
- (void)refreshBuddyVCardsRightNow:(NSArray<NSString *> *)jids;
@end

@protocol ZMChatUIPresenceInterfaceProtocol <NSObject>

- (void)subscribeBuddyPresence:(NSArray <NSString *>*)jids forType:(int)type;

//target use ZMChatUIBuddyUpdateInterfaceProtocol
- (void)registerBuddyUpdateByTartget:(id)target;

@end

@protocol ZMChatUIMessageInterfaceProtocol <NSObject>

@required

- (void)jumpToChatByMessageId:(NSString *)messageId sessionId:(NSString *)sessionId;

- (void)deleteMessageById:(NSString *)messageId sessionId:(NSString *)sessionId;

- (ZMMessageAdapter *)getMessageById:(NSString *)messageId sessionId:(NSString *)sessionId;

@end

@protocol ZMChatUIVCardInterfaceProtocol <NSObject>

@required

- (void)showUserProfilePannel:(NSString *)uid positioningView:(NSView *)positioningView relativeRect:(NSRect)rect;

//- (void)showUserProfilePannel:(NSString *)uid positioningView:(NSView *)positioningView relativeRect:(NSRect)rect autoClose:(BOOL)autoClose;

- (ZMUserProfileFloat *)getUserProfileFloat;

- (NSViewController *)getNewVcardViewController:(NSString *)uid floatConfig:(ZMProfileConfig *)config;

- (NSString *)getJIDWithUserId:(NSString *)userid;

- (BOOL)isUserInvalid:(NSString *)jid meetingGuest:(BOOL)meetingGuest;

@end

@protocol ZMChatUIHuddleViewInterfaceProtocol <NSObject>

@required

- (void)didHuddleViewChangeBackground:(NSString *)sessionId;

@end

//@protocol ZMChatUIToastInterfaceProtocol <NSObject>
//
//@required
//
//- (void)showToast:(id)toast_String_or_AttributedString autoDisappear:(BOOL)autoDisappear type:(NSInteger)type;
//
//@end

@protocol ZMChatUIOpenFileInterfaceProtocol <NSObject>

@required

- (void)openFilePreviewByItems:(NSArray <ZMFileEntity *> *)fileItems sessionId:(NSString *)sessionId currentIndex:(NSInteger)currentIndex  window:(NSWindow *)window isDockOut:(BOOL)isDockout;

- (void)openCodeSnippetByMessage:(ZMMessageAdapter *)message window:(NSWindow *)window;

- (void)openWhiteboardFile:(ZMChatFileItem *)file;

@end

@protocol ZMChatUIShareMailInfoProtocol <NSObject>

@required
- (NSString *)mailTitle;
- (NSString *)fromJid;
- (NSString *)fromName;
- (NSString *)mailBody;
- (NSString *)mailId;
- (unsigned long long)mailTime;

- (NSString *)filePath;
@optional
- (BOOL)isFromZMail;
- (NSString *)validInfo;

@end

@protocol ZMChatUIShareMessageInterfaceProtocol <NSObject>

@required

- (void)shareEmail:(id<ZMChatUIShareMailInfoProtocol>)emailInfo shareCallback:(void (^)(ZMShareResult result))shareCallback;

@end

@protocol ZMChatUIScheduernterfaceProtocol <NSObject>

@required
- (BOOL)isZoomCalendarUIEnabled;
- (BOOL)isCalendarUILoaded;
- (void)embedSchedulerToSidebar;
- (void)closeSchedulerInSidebar;
- (void)removeSchedulerFromSidebar:(BOOL)needClearDraft;
- (void)closeScheudlerWnd;
- (void)openCalendarTab;
- (void)expandQuickSchedule;
- (void)closeScheduler;
- (void)closeUnifyScheduler;
- (void)switch2FindTime;
- (void)schedulerOptionsHaveChanged;
@end

//@protocol ZMChatUIActivityCenterInterfaceProtocol <NSObject>
//
//@required
//- (void)openActivityCenterSettingWindow;
//- (void)closeActivityCenterSettingWindow;
//
//- (void)closeActivityCenterWindow;
//
//- (void)closeActivityCenterWithSourceType:(NSInteger)sourceType webView:(NSView *)webView;
//@end

@protocol ZMChatUIReportProtocol <NSObject>

@required
- (void)reportWhiteboardFromMeeting;
- (void)reportNotesFromMeeting;
- (void)reportDocsFromMeeting;
- (void)openQualtricsFeedbackFromMeeting:(NSString*)activeTab
                                  sender:(id)sender;
@end

//@protocol ZMChatUIJSCallInterfaceProtocol <NSObject>
////- (void)addPostJsMessageCommonAPISink;
////- (void)removePostJsMessageCommonAPISink;
////- (NSArray *)getRegisteredFunctionNames;
//- (void)handleJsMessageWithParam:(NSDictionary *)param sourceType:(NSInteger)type;
//- (NSString *)getResourceStringWithResourceType:(NSInteger)resourceType;
//@end

@protocol ZMWebViewCallProtocol <NSObject>
@optional
- (void)handleJsMessageWithParam:(NSDictionary *)param sourceType:(NSInteger)type;
- (NSString *)getResourceStringWithResourceType:(NSInteger)resourceType;
- (void)showUserProfilePannel:(NSString *)uid positioningView:(NSView *)positioningView relativeRect:(NSRect)rect autoClose:(BOOL)autoClose;
- (void)showToast:(id)toast_String_or_AttributedString autoDisappear:(BOOL)autoDisappear type:(NSInteger)type;

- (void)openActivityCenterSettingWindow;
- (void)closeActivityCenterSettingWindow;
- (void)closeActivityCenterWindow;
- (void)closeActivityCenterWithSourceType:(NSInteger)sourceType webView:(NSView *)webView;
@end

@protocol ZMChatUIInterfaceProtocol <ZMChatUIMessageInterfaceProtocol,ZMChatUIVCardInterfaceProtocol,ZMChatUIHuddleViewInterfaceProtocol,ZMChatUIOpenFileInterfaceProtocol,ZMChatUIShareMessageInterfaceProtocol,ZMChatUISearchInterfaceProtocol,ZMChatUIPresenceInterfaceProtocol,ZMChatUIScheduernterfaceProtocol, ZMChatUIReportProtocol, ZMWebViewCallProtocol>

- (BOOL)isLoginin;

@end

@protocol ZMChatUISettingProtocol

- (void)showSettingWindow;
- (void)closeSettingWindow;

@end

#endif /* ZMChatUIInterfaceProtocol_h */
