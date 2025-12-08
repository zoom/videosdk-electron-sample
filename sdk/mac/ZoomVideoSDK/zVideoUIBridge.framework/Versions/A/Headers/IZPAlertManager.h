//
//  IZPAlertManager.h
//  VideoUI
//
//  Created by martin.yu on 9/14/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef IZPAlertManager_h
#define IZPAlertManager_h

@class ZMAlertPanel;

NS_ASSUME_NONNULL_BEGIN

@protocol IZPAlertManager <ZMRoutableObject>
- (void)showAllowSignLanguageInterpreterToTalkAlert;
- (void)closeAllowSignLanguageInterpreterToTalkAlert;

- (void)showZECompanionInterpretationEnableStreamAlertConfirmBlock:(void (^)(void))confirmAction;

- (void)showArchiveAlert;
- (void)closeArchiveAlert;
- (void)showArchiveFailedAlert;
- (void)closeArchiveFailedAlert;

- (void)showPSProducerNoInterChannelAlert;


- (ZMAlertPanel *_Nullable)alertPanelWithIdentifier:(nullable NSString *)identifier makeIfNecessary:(BOOL)makeIfNecessary;
- (void)closeAlertPanelWithIdentifier:(nullable NSString *)identifier;
- (void)showQADlpCheckAlertWithConfirm:(void(^)(void))actionConfirm;
- (void)showQADlpBlockAlert;
- (void)closeDLPQACheckAlert;
- (void)closeDLPQABlockAlert;

- (void)showQAConflictAlert;
- (void)showDlpCheckAlertWithConfirm:(void(^)(void))actionConfirm;
- (void)showDlpBlockAlert:(NSString *)policyName;//policyName is useless
- (void)closeDLPAlert;
- (void)closeDLPCheckAlert;

- (void)showWhiteboardBlockShareAlert;
- (void)showWhiteboardBlockGeneralAlertWithContinueAction:(nullable dispatch_block_t)continueAction
                                             cancelAction:(nullable dispatch_block_t)cancelAction;

- (void)showRecordingHostNotInMeetingAlert;

- (void)showRecordingDisclaimer:(BOOL)isCloud expectedZRAValue:(NSNumber *)expectedZRAValue;
- (void)showMiniWindowCannotRecodingAlert;
- (void)closeMiniWindowCannotRecodingAlert;

- (BOOL)showSimuliveAlertIfNeed;
- (void)showAudioVideoUnavailableAlert; //ZOOM-748835
- (void)closeAudioVideoUnavailableAlert;

- (void)showAudioDeviceErrorAlert:(NSString*)tipString;
- (void)showCoreAudioErrorAlert;

- (void)showAudioControlDisclaimer:(ZMUser *)user;
- (BOOL)isAudioControlDisclaimerShowing:(ZMUser *)user;
- (void)closeAudioControlDisclaimer:(ZMUser *)user;
- (void)closeAllAudioControlDisclaimer;

- (void)showAddToAudioControlGroupAlert:(ZMUser *)user;
- (BOOL)isAddToAudioControlGroupAlertShowing:(ZMUser *)user;
- (void)closeAddToAudioControlGroupAlert:(ZMUser *)user;
- (void)closeAllAddToAudioControlGroupAlert;

- (void)showRequestAudioControlAlert:(ZMUser *)user;
- (void)showForbidUnmuteAudioWhenAudioSharingAlert;

//voice record
- (void)showDeleteVoiceRecordAlert;
- (void)showEndVoiceRecordAlert;
@end

NS_ASSUME_NONNULL_END

#endif /* IZPAlertManager_h */
