//
//  ZMRecordHelper.h
//  VideoUI
//
//  Created by geno.chen on 2021/11/13.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMBaseHelper.h>
NS_ASSUME_NONNULL_BEGIN

@interface ZMRecordHelper : ZMBaseHelper

#pragma mark - API for both local recording and CMR

/** Equal to IsLocalRecordingInProgress() || IsCMRInProgress() */
- (BOOL)isRecordingInProgress;
/**
 * Is someone is recording the meeting by local record or CMR
 * if only CMR is recording and CRM is connecting or paused, it will return false
 * if only one user is local recording, and the local recording is paused, it will return false
 */
- (BOOL)theMeetingisBeingRecording;
- (BOOL)needPromptRecordingDisclaimer;
- (void)agreeContinueRecording:(BOOL)bAgree;

#pragma mark - API only for local recording
- (u_int32_t)getLocalRecordSessionGroupId;
- (BOOL)startLocalRecord:(NSString *)recordPath
               videoList:(nullable PSSB_MC_DATA_BLOCK_RECORDING_SELECTTED_USERS)videoList
            isCurSession:(BOOL)isCurSession
              hideAvatar:(BOOL)hideAvatar
                 recFlag:(uint32_t)recFlag;
- (BOOL)stopLocalRecord:(BOOL)needRestore;
- (BOOL)pauseLocalRecord;
- (BOOL)resumeLocalRecord;
- (BOOL)isLocalRecordStarted;
- (BOOL)isLocalRecordPaused;
- (BOOL)isLocalRecordStoped;

- (BOOL)canStartLocalRecord;
- (BOOL)setImmersiveSceneInfo:(SSB_MC_DATA_BLOCK_RECORDING_IMMERSIVE_INFO)info;
/** Equal to GetLocalRecordStatus() == CMM_RECORD_STATUS_START || GetLocalRecordStatus() == CMM_RECORD_STATUS_PAUSE */
- (BOOL)isLocalRecordingInProgress;
- (BOOL)setRecordRootPath:(NSString *)path;
- (NSString *)getCurrentRecPath;
- (BOOL)setRecordContentList:(PSSB_MC_DATA_BLOCK_RECORDING_SELECTTED_USERS)videoList;
- (BOOL)setScreenResolution:(NSUInteger)resolution;
- (BOOL)isShowNameInLocalRecordEnabled;

// ZOOM-715648
- (BOOL)updateCustomIdInfo:(const SSB_MC_DATA_BLOCK_RECORDING_CUSTOM_ID_INFO&)info;

- (BOOL)localRecordNeedHideAvatar;
- (void)setHideUserAvatar:(BOOL)bHide;

#pragma mark - API only for CMR
- (BOOL)startCMR;
- (BOOL)stopCMR;
- (BOOL)pauseCMR;
- (BOOL)resumeCMR;
- (CMM_RECORD_STATUS)getCMRStatus;
/** Equal to GetCMRStatus() == CMM_RECORD_STATUS_START */
- (BOOL)isCMRStarted;
/** Equal to GetCMRStatus() == CMM_RECORD_STATUS_PAUSE */
- (BOOL)isCMRPaused;
/** Equal to GetCMRStatus() == CMM_RECORD_STATUS_STOP */
- (BOOL)isCMRStoped;
/**
 * Check if I have the privilege to start CMR
 */
- (BOOL)canStartCMR;
/** Check if can Pause/Resume/Stop CMR */
- (BOOL)canControlCMR;
/**
 * For history compatible issue, this function have two conditions: I can control CMR and the status of CMR is not stop
 * Equal to CanStartCMR() && (GetCMRStatus() == CMM_RECORD_STATUS_CONNECTING ||  GetCMRStatus() == CMM_RECORD_STATUS_START || GetCMRStatus() == CMM_RECORD_STATUS_PAUSE)
 * Note: New user should use GetCMRStatus() and CanControlCMR() to instead this function
 */
- (BOOL)isCMRInProgress;
/** Equal to GetCMRStatus() == CMM_RECORD_STATUS_CONNECTING */
- (BOOL)isCMRInConnecting;
- (BOOL)isZRARecording;

/** Is meeting recording by CMR, equal to GetCMRStatus() == CMM_RECORD_STATUS_START || GetCMRStatus() == CMM_RECORD_STATUS_PAUSE */
- (BOOL)recordingMeetingOnCloud;

- (void)updateUserNameDataForLoacalRecord:(const CmmRecordUserNameData&)data;
- (void)updateUserAvatarForLocalRecord:(SSB_MC_DATA_BLOCK_RECORD_USER_AVATAR &)data;
- (void)updateBacksplashForLoacalRecord:(const SSB_MC_DATA_BLOCK_BACK_SPLASH_PIC&)info;
- (void)updateVideoTransparencyForLoacalRecord:(const SSB_MC_DATA_BLOCK_VIDEO_TRANSPARENCY_INFO&)info;
- (void)updateVideoMaskForLoacalRecord:(const SSB_MC_DATA_BLOCK_VIDEO_MASK_INFO&)info;

@end


@interface ZMRecordHelper (OthersAPI)

- (void)setRecordPath:(NSString *)recordPath;
- (BOOL)isCMRReminderEnabled;
/** Only show recording indicator to who is being recorded, others who won’t be recorded cannot see the recording indicator. */
- (BOOL)isHostOnlyCMREnabled;
- (BOOL)isAutoCMRForbidManualStop;
- (BOOL)needPromptStartRecordingDisclaimer;
- (BOOL)canCMRUpgrade;
- (nullable NSURL *)getRecordingManagementURL;
- (BOOL)isPlayRecordVoiceNoti;
- (BOOL)isRecordDisabled;
- (BOOL)isLocalRecordDisabled;
- (BOOL)isLocalRecordSupported;
- (BOOL)isSupportLocalRecordSecuritySettings;
- (BOOL)isRequestLocalRecordPermissionEnabled;
- (BOOL)isAllowAllToRequestLocalRecord;
// Only a part of participants can request, not all
- (BOOL)isAllowToRequestLocalRecord;
- (BOOL)needShowDesignedLocalRecordTip;
- (BOOL)isAllowParticipantLocalRecordLocked;
- (BOOL)isRecordOperationDisabled;

//ZOOM-340709
- (BOOL)isKiwiRecordingEnable;
- (BOOL)getSalesRecordingAnalytics;
- (void)setSalesRecordingAnalytics;
- (BOOL)setSalesRecordingAnalytics:(BOOL)isOn;
- (BOOL)isUseOldZRAEnabled;

#pragma mark - combination
- (BOOL)isRecordingPaused;
- (BOOL)canStartRecording;
- (BOOL)canStopRecording;
- (BOOL)canPauseRecording;
- (BOOL)canResumeRecording;

//MARK: Smart recording
//bit
- (BOOL)isSmartRecordingEntranceEnabled;
- (BOOL)isSmartRecordingEnable;
- (BOOL)isSmartRecordingLocked;
- (BOOL)isAudioTranscriptRecordingEnabled;
- (BOOL)isAudioTranscriptRecordingLocked;
- (CHANGE_WEB_SETTING_STRATEGY)getSmartRecordingEnableStrategy;

//util
- (BOOL)isCMRWithSmartRecordingEnabled;
- (BOOL)canEnableSmartRecording;
- (BOOL)canEnableSmartRecordingInMeeting;
- (BOOL)canRequestEnableSmartRecording;
- (BOOL)isMeetingSupportCMR;
- (BOOL)canRequestStartCMR;
- (BOOL)hasSupportEnableSmartRecordingAdmin;
- (NSString *)getSmartRecordingSettingLink;

- (BOOL)isSupportRequestCMRControl;
- (void)setAllowRequestHostStartCMRStatus:(BOOL)state;
- (BOOL)isAllowRequestHostStartCMR;
- (BOOL)isAllowRequestHostStartCMRLocked;
- (BOOL)isHostInLocalRecord;
//- (BOOL)isAuthLocalRecordDisabled;
- (BOOL)canSendLocalRecordRequest;
- (BOOL)isHostSupportRequestStartCMR;

- (BOOL)canNotStartRecordingFeatureUntilHostJoined;

- (BOOL)canShowRecordingIndicatorForSharing;
@end

NS_ASSUME_NONNULL_END
