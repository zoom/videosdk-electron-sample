//
//  ZMMTShareHelper.h
//  VideoUIBridge
//
//  Created by Molay.Yu on 2024/5/24.
//

#import <zVideoUIBridge/ZMBaseHelper.h>
#import <zVideoApp/CmmConfAPI.h>

#import <zVideoUIBridge/ZMShareZoomWindowsOptions.h>
#import <zVideoUIBridge/ZMMTShareWatermarkOption.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMUser;
@interface ZMMTShareHelper : ZMBaseHelper

@property (nonatomic, strong, nullable) ZMShareZoomWindowsOptions *shareZoomWindowsOptions;
@property (nonatomic, strong) ZMMTShareWatermarkOption *watermarkOption;

- (BOOL)requestToEnableMultiShare;
- (BOOL)respondToEnableMultiShareRequest:(NSString *)requestID requestUserID:(ZMUserID)requestUserID status:(CmmEnableMultiShareResponseStatus)status;
- (BOOL)isAllowRequestToEnableMultiShare;
- (BOOL)setAllowRequestToEnableMultiShare:(BOOL)allow;

//capability
- (BOOL)isScreenShareDisabled;
- (BOOL)isScreenShareDisabled:(NSUInteger *)reason;
- (BOOL)isShareDisabledByInfoBarrier;//ZOOM-93173
- (BOOL)isShareDisabledByExternalLimit;
- (BOOL)canShareDesktop;
- (BOOL)canShareCamera;
- (BOOL)isAutoShareDesktopEnabled;
- (BOOL)isShareAudioDisableForMultipleShareInWebinar;
- (BOOL)isSupportSpotlight;// ZOOM-734161
- (BOOL)isVideoOptimizeShareDisabled;
- (BOOL)isSharePreviewEnabled;



//share setting
- (CMM_SHARE_SETTING_TYPE)getShareSettingType;
- (BOOL)isMultiShareSelected;
- (BOOL)isHostOnlyShareSelected;
- (void)setShareSettingType:(int)inType;
- (BOOL)isMultiShareDisabled;
- (BOOL)isSharSettingTypeLocked;

//normal share status
- (BOOL)isShareSessionCompleted;

/// Is currently anyone sharing anything (include screen share, whiteboard, doc and computer audio)
- (BOOL)isAnySharingExistInMeeting;

//////receiver
- (BOOL)isAnyoneSharing;
- (NSUInteger)getShareSourceCount;
- (NSUInteger)getPublicShareSourceCount;
- (NSUInteger)getPrivateGroupShareCount;
- (BOOL)isReceivingSharingFromCurrentConf;
- (BOOL)isReceivingSharing;
- (NSUInteger)getViewableASShareSourceCount;
- (NSArray<ZMShareSource*>*)getViewableASShareSourceArray;
- (BOOL)isViewableShare:(ZMShareSource *)shareSource;

//////sender
- (BOOL)isSendingAnySharing;
- (BOOL)isSendingSharing;
- (BOOL)isSendingSharingDoc;
- (BOOL)isSendingSharingZappCollaborateWindow;
- (BOOL)isSendingSharingVideo;
- (BOOL)isSendingSharingScreen;
- (BOOL)isSendingSharingCamera;
- (BOOL)isSendingSharingAffectWindow;
- (BOOL)isSendingShareUserSupportAutoShare;

- (BOOL)isLocalShareOn;

//share computer audio
- (BOOL)isSendingComputerAudio;
- (BOOL)isReceivingComputerAudio;
- (nullable ZMUser *)getPureComputerAudioSharingUser;
- (BOOL)isPureComputerAudioSharing:(ZMUser *)inUser;
- (BOOL)isInComputerAudioSharingMode;
- (void)requestStopPureComputerAudioShare:(ZMUser *)inUser;
- (void)requestStopPureComputerAudioShareIfViewing;
- (void)startPureComputerAudioShare;
- (void)stopPureComputerAudioShare;
- (BOOL)isComputerAudioShareStereoModeOn;

//remote support
- (nullable NSArray<ZMUser*>*)getSupportAutoShareUserArray;
- (nullable NSArray<ZMUser*>*)getSupportAutoRebootUserArray;

//stop normal share
- (void)requestStopAllViewableShare;
- (BOOL)requestStopViewableUser:(ZMUser *)inUser;
- (BOOL)requestStopViewableShare:(ZMShareSource *)inSource;

//stop normal share & audio share
- (void)requestStopAllShare;


//focus mode
- (CmmShareFocusMode)getFocusModeType;
- (BOOL)isShareFocusModeOn;
- (BOOL)canIViewShareSource:(ZMShareSource *)shareSource;

//multi select
- (BOOL)isMultiSelectAppShareTooltipDisabled;
- (void)disableMultiSelectAppShareTooltip:(BOOL)disabled;
- (BOOL)isMultiSelectDesktopShareTooltipDisabled;
- (void)disableMultiSelectDesktopShareTooltip:(BOOL)disabled;
- (NSUInteger)getMaxNumberSelectMultiDesktop;

- (nullable ICmmASShareSource*)getConfInstShareSourceById:(ZMShareSourceID)inShareSourceId;
// just AS
- (BOOL)isSharingWithUser:(ZMUser *)inUser;


//share to bo
/**
 only for share bo case, if in old bo, it is boMasterSession,
 if in new bo, it is defaultSession,
 otherwise it it nil
 */
+ (nullable ZMConfSession *)BOMainSession;
/**
 only for share bo case, if in old bo, check if it is boMasterSession or not,
 if in new bo, check if it is defaultSession or not,
 otherwise it is false
 */
- (BOOL)isBOMainSession;
/**
 only for share bo case, if in old bo, check if it is defaultSession or not,
 if in new bo, check if it is isNewBOSession or not,
 otherwise it is false
 */
- (BOOL)canReceiveShareBO;

//share zoom window
- (BOOL)isPreventCaptureZoomWindowEnabled;
/**
 in masked share content for viewing myself share
 */
- (BOOL)isMaskedRepeatWindow;
- (BOOL)allowRepeatingWindowEffect;

//annotate
- (BOOL)isAnnotationFeatureEnabled;//whether the annotation feature is globally enabled (feature toggle)
- (BOOL)isAnnotationAllowedForAttendee;//Whether attendees are allowed to annotate, as controlled by web configuration
- (BOOL)canAttendeeAnnotateInCurrentShare;//Whether annotation is available to attendees in the current share state
- (BOOL)isShowingAnnotatorName;
- (void)toggleShowingAnnotatorName;
- (BOOL)isAttendeeAnnotationLocked;//Whether attendee annotation is locked by the presenter via UI
- (void)toggleAnnotationLockForAttendee;
//annotate - convenient for presenter
- (void)setPresenterAnnoDockPosition:(NSPoint)topLeft
                            topRight:(NSPoint)topRight
                          bottomLeft:(NSPoint)bottomLeft
                         bottomRight:(NSPoint)bottomRight;
- (void)hidePresenterAnnoterToolbar;
- (void)showPresenterAnnoterToolbar;
- (BOOL)isPresenterAnnoterToolbarShown;
- (BOOL)isPresenterAnnotating;
- (BOOL)isSharingWhiteboard;

// Spotlight
- (BOOL)spotlightShareSource:(ZMShareSource *)shareSource;
- (BOOL)stopSpotlightShareSource:(ZMShareSource *)shareSource;

//presenter layout
- (BOOL)isPresenterLayoutEnabled;
@end

NS_ASSUME_NONNULL_END
