//
//  IZMMTClinicalNoteMgr.h
//  VideoUIBridge
//
//  Created by Karen Cao on 12/10/24.
//

#ifndef IZMMTClinicalNoteMgr_h
#define IZMMTClinicalNoteMgr_h

@protocol IZMMTClinicalNoteMgr <ZMRoutableObject>

@optional
- (void)onReceiveSwitchClinicalNoteRequestMsg:(NSString *)reqId senderId:(ZMUserID)senderId switchAction:(NSInteger)switchAction;
- (void)onReceiveSwitchClinicalNoteResponseMsg:(BOOL)timeout isDecline:(BOOL)decline switchAction:(NSInteger)switchAction;
- (void)onClinicalNoteStatusChanged;
- (void)onTurnOnButtonClicked;
- (void)onTurnOffButtonClicked;
- (void)onTurnOffNotifierButtonClicked;
- (void)onPauseButtonClicked;
- (void)onResumeButtonClicked;
- (void)startClinicalNote;
- (void)stopClinicalNote;
- (void)pauseClinicalNote;
- (NSString*)getClinicalNoteNotiferFooterText;
- (ZMBaseView *)getContentView;
- (BOOL)isUrlEmpty;
- (void)onPatientDataPanelHidden:(BOOL)isDataWindowVisible;
- (void)loadView;

- (BOOL)isPatientDataSidepanelShowing;
- (void)openPatientDataSidepanel;
- (void)closePatientDataSidepanel;
- (void)mergeToMeetingWindow;
- (void)popupWindowEnabled:(BOOL)enable;
- (BOOL)isPopupWindowEnabled;
- (BOOL)needRestorePatientDataPanel;
- (void)onClinicalNoteGetMMRToken:(NSString *)jsCallId;
@end

@protocol IZMMTClinicalNoteEvent <NSObject>

@optional
- (void)onReceiveSwitchClinicalNoteRequestMsg:(NSString *)reqId senderId:(ZMUserID)senderId switchAction:(NSInteger)switchAction;
- (void)onReceiveSwitchClinicalNoteResponseMsg:(BOOL)timeout isDecline:(BOOL)decline switchAction:(NSInteger)switchAction;
- (void)onClinicalNoteChanged;
- (void)onCNPatientDataSaved:(BOOL)isSuccess;
- (void)onCreateClinicalNoteSessionFailed:(NSInteger)errCode;
- (void)onAICompanionTokenReceived:(BOOL)isSuccess reqId:(NSString*)reqId token:(NSString *)token;

@end

#endif /* IZMMTClinicalNoteMgr_h */

