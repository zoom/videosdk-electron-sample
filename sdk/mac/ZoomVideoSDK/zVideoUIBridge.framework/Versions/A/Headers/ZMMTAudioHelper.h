//
//  ZMMTAudioHelper.h
//  VideoUI
//
//  Created by javenlee.li on 2021/11/13.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMBaseHelper.h>
#import <zVideoUIBridge/ZMUIConstants.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTAudioHelper : ZMBaseHelper

- (BOOL)isMuteOnEntry;
- (void)setMuteOnEntry:(BOOL)isOn;

- (BOOL)isPlayChimeOn;
- (void)setPlayChime:(BOOL)isOn;

- (BOOL)isAllowParticipantUnmuteSelf;
- (void)setAllowParticipantUnmuteSelf:(BOOL)isOn;

- (BOOL)canHostCohostUnmuteMeDirectly;
- (BOOL)isModeratedUnmuteEnabled;

- (BOOL)isAlwaysUseVoIPWhenJoinMeeting;
- (void)setAlwaysUseVoIPWhenJoinMeeting:(BOOL)isOn;

- (int)getAudioType;
- (BOOL)isSupportVoip;
- (BOOL)isSupport3rdParty;
- (BOOL)isSupportDialIn;
- (BOOL)isSupportCallMe;
- (BOOL)isSupportTelephony;

#ifdef __cplusplus
///device: timeout
- (SSB_MC_AUDIO_DEVICE_TIMEOUT_TYPE)getAudioDeviceStatus;
#endif

///voip
- (BOOL)isJoinAudioByVoip;

///call me
- (BOOL)isCallingOut;
- (BOOL)isOnlyUseTelephone;
- (BOOL)isUseOwnZoomPhoneNumber;
- (BOOL)isUseOwnPhoneNumber;

///call out
- (BOOL)isPhoneNumberNotMatchCallout;
- (BOOL)isSupportInternationalCallOut;
- (BOOL)isCalloutTypeLimited;
- (void)clearAllCallMeHistoryCountry;
- (int)getSupportCallOutType;
- (nullable NSString *)getMyCallOutNumber;

/// PSTN
- (BOOL)hasPSTNPassword;
- (nullable NSString*)getPSTNPassword;

/// zoom phone
- (BOOL)joinCompliantMeetingAutoCall;
- (BOOL)hangUpCompliantMeetingAutoCall;

///voice record
- (BOOL)setIsEnableSpeakerDiarization:(BOOL)enable;
- (BOOL)enableSpeakerTag:(BOOL)enable userId:(ZMUserID)userId;
- (void)setSpeakerDiarizationOfflineClustering:(BOOL)enable;
@end

NS_ASSUME_NONNULL_END
