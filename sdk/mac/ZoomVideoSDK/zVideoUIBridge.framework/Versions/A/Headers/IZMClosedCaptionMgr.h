//
//  IZMClosedCaptionMgr.h
//  VideoUIBridge
//
//  Created by martin yu on 8/2/23.
//

#ifndef IZMClosedCaptionMgr_h
#define IZMClosedCaptionMgr_h

NS_ASSUME_NONNULL_BEGIN

@class ZMMTBaseViewController;
@class ZMUser;
@class ZMMenu;
@class ZMMenuItem;
@class PZMMenuItem;
@class ZMCCLanguage;
@class ZMCCSelectCaptionsLanguageConfig;
@class ZMCCSubtitlesMessage;
@protocol ZMCCSubtitlesContainer;

@protocol ZMCCSubtitlesMgrDelegate <NSObject>
@optional
- (void)didReceiveSubtitlesMessage:(ZMCCSubtitlesMessage *)message;
@end

@protocol IZMCCSubtitlesMgr <NSObject>
- (void)addDelegate:(id<ZMCCSubtitlesMgrDelegate>)delegate;
- (void)removeDelegate:(id<ZMCCSubtitlesMgrDelegate>)delegate;
@end

@protocol IZMClosedCaptionUIHelper <NSObject>
- (void)closeAllWindow;
- (void)closeAllWindowWhenCaptionDisabled;

// ZOOM-254515
- (ZMMenu *)showCCOptionMenuWithTargetView:(NSView *)sender
                                targetRect:(NSRect)targetRect
                                isInFitBar:(BOOL)isInFitBar;
- (void)closeCCOptionMenu;
- (BOOL)isCCOptionMenuShowing;

- (NSArray<ZMMenuItem *> *)speakingLanguageMenuItems;
- (NSArray<PZMMenuItem *> *)speakingLanguagePMenuItems;
- (NSArray<ZMBaseMenuItem *> *)allTranslationLanguageMenuItems;
- (NSArray<PZMMenuItem *> *)allTranslationLanguagePMenuItems;

#pragma mark - Subtitles
@property (nonatomic, assign, readonly) BOOL isCaptionsShowing;
@property (nonatomic, strong, readonly) ZMMTBaseViewController<ZMCCSubtitlesContainer> *captionsViewController;
// For open again with new message arrived after auto closeed.
@property (nonatomic, assign) BOOL isCaptionsShouldShow;
@property (nonatomic, assign) BOOL isMainWindowShouldShowCaptions;
- (void)loadCCLiveTranscriptWindowIfNeeded;
- (void)showCaptions;
- (void)hideCaptions;
- (CGFloat)savedWidthForCaptionsBox;
- (CGFloat)savedHeightForCaptionsBox;
- (void)saveWidthForCaptionsBox:(CGFloat)width;
- (void)saveHeightForCaptionsBox:(CGFloat)height;
- (NSWindow *)getCurrentWind;

@property (nonatomic, assign) BOOL didShowSubtitlesAutomaticallyForGR;

#pragma mark - Select Captions Language

// ZOOM-423978
- (void)showSelectCaptionsLanguagePanelWithConfig:(ZMCCSelectCaptionsLanguageConfig *)config;
- (void)closeSelectCaptionsLanguagePanel;

#pragma mark - Request Captions
@property (nonatomic, assign) BOOL enabledTranslationWhenRequestCaptions;
- (void)showRequestCaptionPanel;
- (void)closeRequestCaptionPanel;
- (BOOL)isRequestCaptionPanelShowing;

- (void)showApproveCaptionRequestPanel:(BOOL)bEnableTranslation;
- (void)closeApproveCaptionRequestPanel;

#pragma mark - Host Control Settings
// ZOOM-561362
- (void)showHostControlSettingsPanel;
- (void)closeHostControlSettingsPanel;

@end

typedef NS_ENUM(NSInteger, ZMCCButtonShowType) {
    ZMCCButtonShowTypeNone,
    ZMCCButtonShowTypeShowCaptions,
    ZMCCButtonShowTypeEnableCaptions,
    ZMCCButtonShowTypeReuqestCaptions,
    ZMCCButtonShowTypeAssignCCEditor,
};

typedef NS_ENUM(int, ZMCCOperationType) {
    ZMCCOperationTypeNone = 0,
    ZMCCOperationTypeAdd,
    ZMCCOperationTypeUpdate,
    ZMCCOperationTypeDelete,
    ZMCCOperationTypeComplete, //ZOOM-283768
    ZMCCOperationTypeTranslationNotSupported, //ZOOM-319811
    ZMCCOperationTypeZRSpeakerID, //ZOOM-819049
};//copy of cmmchatmoduleapi.h

@protocol IZMClosedCaptionMgr <ZMRoutableObject>

@property (nonatomic, assign) BOOL hasMessageReceived;
@property (nonatomic, assign) BOOL shouldTryToShowCCTipWhenBOHostAvailable;
@property (nonatomic, assign) BOOL isChangeLanguageTipShowed;

@property (nonatomic, strong) id<IZMCCSubtitlesMgr> subtitlesMgr;
@property (nonatomic, strong, nullable) id<IZMClosedCaptionUIHelper> uiHelper;

@property (nonatomic, assign, readonly) ZMConfSession *confSession;

- (ZMMTBaseViewController<ZMCCSubtitlesContainer> *)newMainSubtitlesViewControllerWithType:(ZMMTType)type;
- (ZMMTBaseViewController<ZMCCSubtitlesContainer> *)newBSSubtitlesViewControllerWithType:(ZMMTType)type;
- (ZMMTBaseViewController *)newSubtitlesContainerViewController;

- (void)onConfReady;
- (void)onHostChanged;

- (BOOL)onCCButtonClicked:(NSView *)sender buttonFrame:(NSRect)buttonFrame bUp:(BOOL)bUp;//ZOOM-72640 RTT{
- (void)onCCLiveTranscriptStatusChanged:(ZMConfSession *)session;
//ZOOM-423989
- (BOOL)shouldAlwaysShowCaptions;
- (BOOL)shouldShowCaptionsAutomatically;
- (void)handleBeforeOpenSubtitlsAutomatically;
- (void)showCaptions;
- (void)showCaptions:(BOOL)needCheckCationsLanguageSettings;
- (void)hideCaptions;

- (void)closeAllWindow;
- (void)openCloseCaptionPanel;
- (void)closeCloseCaptionPanel;
- (void)setSidePanelItemNoNeedRestore;
- (BOOL)isCloseCaptionPanelVisible;
- (BOOL)isCloseCaptionPanelInSidePanel;
- (void)mergeCloseCaptionPanelToMainWindow;

- (void)updateUIWithFontName:(nullable NSString *)fontName;
- (void)updateUIWithFontSize:(int)inFontSize;
- (void)updateCaptionColor:(NSColor *)color;
- (void)updateTranslationColor:(NSColor *)color;
- (void)updateBackgroundColor:(NSColor *)color;
- (void)updateCaptionDisplayMode:(ZMMTCaptionDisplayMode)displayMode;
- (void)updateCCRecvWndPosition;
- (void)updateCCUI;

// Used for New LTT
- (ZMCCButtonShowType)getCCButtonShowType;

/// return true when one of manual or live transcriptions is on in web settings.
- (BOOL)amIHost;
- (void)onLiveTranscriptButtonClicked;
- (void)save;
- (void)showInFinderBtnClicked;
//ZOOM-72640 RTT}
- (void)openCCWindow;
- (void)closeCCWindow;
- (void)try2OpenCCSendWnd;

- (void)onShowChangeCCEditorAlertWithUser:(ZMUser *)theUser;
- (void)grabCCEditorRole;
- (void)onChangeCCEditor:(ZMUser *)theUser;
- (void)ccEditorDidChangedWithUser:(ZMUser *)theUser;

- (void)onSendRealtimeCCContent:(NSString *)inContent;
- (BOOL)onSendCCContent:(NSString *)inContent;

- (void)onMessageReceived:(NSString*)msgID type:(int)type session:(ZMConfSession *)session;
- (void)onCCMessageReceivedWithString:(NSString *)inString messageId:(NSString *)msgID session:(ZMConfSession *)session;
- (void)onCCRealtimeMessageReceived:(NSString *)realtimeMessage session:(ZMConfSession *)session;//ZOOM-32977
- (void)loadHistoryMsg;

- (BOOL)getCCWindowVisible;
- (BOOL)isNeedShowCCButton;

// ZOOM-254515 begin
- (BOOL)enabledLTInThePast;
- (BOOL)canShowRLTButton;
- (BOOL)canShowRLTMenuItem;

- (void)showLiveTranscriptRequestAlertIfNeeded;

- (void)onStartLiveTranscriptRequestReceived:(ZMUser *)fromUser bAnonymous:(BOOL)bAnonymous;
- (void)onRequestLiveTranscript:(BOOL)bAnonymous;

- (void)onApproveLiveTranscriptRequest:(BOOL)bApproved;
- (void)onDeclineAndDontAskMeAgain;
// ZOOM-254515 end

// ZOOM-284993
- (void)updateCloseCaptionEnabledTip;

// ZOOM-291736
- (BOOL)shouldShowLiveTranscriptLogo;
- (void)onASREngineTypeChanged:(ZMConfSession *)session;

// ZOOM-302959
- (void)onTransfromStatusChanged;

// ZOOM-320888
- (BOOL)canSaveCCForLegalNotice;
- (NSString *)getCCLegalNoticeTitle;
- (NSString *)getCCLegalNoticeToolTip;

// ZOOM-423978
- (BOOL)shouldShowSelectCaptionsPanelWhenShowCaptions;

- (void)showCCChangeLanguageTipIfNeeded;

- (void)onLTTObjCreated:(ZMConfSession *)session;
- (void)onLTTObjWillDestroy:(ZMConfSession *)session;

- (void)subscribeTextChannelsIfNeeded;

- (void)onReceiveLTTTextMessageWithMsgId:(NSString *)msgId opType:(ZMCCOperationType)opType;

- (void)onManualCaptionStatusChanged;

- (void)onMeetingSpeakingLanguageChangedTo:(ZMCCLanguage *)newLanguage from:(ZMCCLanguage *)oldLanguage;
- (void)onCCEditorAssignedStatusChanged;

// ZOOM-423983
- (void)onCaptionsTemporarilyEnabled;
- (void)onCaptionsTemporarilyDisabled;

// ZOOM-423978
- (void)onMeetingSpeakingLanguageUpdatedByUser:(ZMCCLanguage *)newLanguage;
- (void)onTextTranslationStart;

//ZOOM-484107
- (BOOL)canChangeSpeakingLanguageForUser:(ZMUser *)user;
- (BOOL)setSpeakingLanguageForUser:(ZMUser *)user language:(ZMCCLanguage *)langauge;
- (nullable ZMCCLanguage *)speakingLanguageForUser:(ZMUser *)user;

//ZOOM-524794
- (void)onStartLTTRequestReceived:(BOOL)bEnableTranslation;
- (void)onStartLTTRequestApproved;
- (void)onUserSubStatusChanged;

// ZOOM-561362
- (void)onLockSpeakingLanguageStatusChanged:(BOOL)locked;

//ZOOM-614238
@property (nonatomic, assign) BOOL hasReceivedMismatchMsg;
@property (nonatomic, assign) BOOL hasLIDError;
@property (nonatomic, assign) BOOL hasShownLIDTipAutomatically;
@property (nonatomic, strong) ZMCCLanguage *recommendedSpeakingLanguage;
- (void)onASRIdentifiedSpeakingLanguage:(ZMCCLanguage *)language;
- (void)onMeetingSpeakingLanguageUpdatedByRoster:(ZMCCLanguage *)language;
- (void)setSpeakingLanguage:(ZMCCLanguage *)language isForAll:(BOOL)isForAll;

//ZOOM-607475
- (void)onLTTReady;

- (BOOL)isAutomaticallyCall;
- (void)setAutomaticallyCall:(BOOL)isCalling;

//ZOOM-630080
@property (nonatomic, strong) ZMCCLanguage *freeTrialTranslationLanguage;
- (void)onAvailableFreeTrialInfoReceived:(BOOL)bSuccess;

//ZOOM-644161
- (void)onSpeakerTagInfoUpdatedWithMsgIds:(NSMutableOrderedSet<NSString *> *)msgIds;

//ZOOM-875284
@property (nonatomic, assign) BOOL isAskCaptionLanguageAlertShowed;

- (void)openCaptionsSettingPanel;
- (void)closeCaptionsSettingPanel;
- (BOOL)isCaptionsSettingPanelShowing;

// ZOOM-990006
@property (nonatomic, assign, readonly) BOOL isFontSizeChangable;
@end

NS_ASSUME_NONNULL_END

#endif /* IZMClosedCaptionMgr_h */
