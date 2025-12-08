//
//  ZPUICommonDef.h
//  SaasBeeConfUIModule
//
//  Created by Justin on 11/20/12.
//  Copyright (c) 2012 Zipow. All rights reserved.
//

#ifndef SaasBeeConfUIModule_ZPUICommonDef_h
#define SaasBeeConfUIModule_ZPUICommonDef_h

#define keyZoomusMeetingLeaveReason @"keyZoomusMeetingLeaveReason"
#define keyZoomusMeetingLeaveGiftParam @"keyZoomusMeetingLeaveGiftParam"
#define keyZoomusMeetingLeaveArchiveParam @"keyZoomusMeetingLeaveArchiveParam"
#define keyZoomusMeetingLeaveAmIHost @"keyZoomusMeetingLeaveAmIHost"
#define keyZoomusMeetingLeaveIsSimuliveWebinar @"keyZoomusMeetingLeaveIsSimuliveWebinar"
#define keyZoomusMeetingLeaveIsOnZoomMeeting @"keyZoomusMeetingLeaveIsOnZoomMeeting"
#define keyZoomusMeetingLeaveConnectFailedParam @"keyZoomusMeetingLeaveConnectFailedParam"
#define keyZoomusMeetingLeaveMeetingID @"keyZoomusMeetingLeaveMeetingID"

typedef enum
{
    ZoomusMeetingLeaveUnset = 0,
    ZoomusMeetingForceLeaveByPT = 1,
    ZoomusMeetingLeaveManually = 1 << 1,
    ZoomusMeetingEndByHost = 1 << 2,
    ZoomusMeetingExpelByhost = 1 << 3,
    ZoomusMeetingEndJBHTimeout = 1 << 4,
    ZoomusMeetingEndFreeMeetTimeout = 1 << 5,
    ZoomusMeetingEndByAnotherMeeting = 1 << 6,
    ZoomusMeetingEndByNoAttendee = 1 << 7,
    ZoomusMeetingEndSDKConnectionBroken = 1 << 8,
    ZoomusMeetingEndArchiveFailed = 1 << 9,
    ZoomusMeetingEndByNone = 1 << 10,
    ZoomusMeetingEndByAdmin = 1 << 11,
    ZoomusMeetingEndByArchivingFailed = 1 << 12,
    ZoomusMeetingConnectFailed = 1 << 13,
    ZoomusMeetingEndACRArchiveFailed = 1 << 14,
    ZoomusMeetingEndByException = 1 << 15,
    ZoomusMeetingEndBySimuliveFinish = 1 << 16,
    ZoomusMeetingEndBySimuliveTimeout = 1 << 17,
    ZoomusMeetingPutAllIntoWaitingRoom = 1 << 18,
    ZoomusMeetingEndBySelf = 1 << 19,
} valueZoomusMeetingLeaveReason;

#define keyZMFreeGroupMeetingCount @"ZoomusMeetingFreeGroupMeetingCount" //NSInteger
#define keyZMIsWebinar @"ZoomusIsWebinarMeeting" //BOOL
#define keyZMUpgradedFromSip @"ZoomusMeetingUpgradedFromSip" //BOOL
#define keyZMElapsedTime @"ZoomusMeetingElapsedTime" //NSUInteger
#define keyZMUpgradeUrl @"ZoomusMeetingUpgradeUrl" //NSString
#define keyZMArcihveTitle @"ZoomusMeetingArcihveTitle" //NSString
#define keyZMArcihveMessage @"ZoomusMeetingArcihveMessage" //NSAttributeString
#define keyZMConnectFailedTitle @"ZoomusMeetingConnectFailedTitle" //NSString
#define keyZMConnectFailedMessage @"ZoomusMeetingConnectFailedMessage" //NSString
#define keyZMFreeMeetingNoticeTitle @"ZoomusFreeMeetingNoticeTitle"
#define keyZMFreeMeetingNoticeDescription @"ZoomusFreeMeetingNoticeDescription"

#define kExtendMeetingParam @"kExtendMeetingParam"
#define kIsBasicPlusHostEnabled @"kMTIsBasicPlusHostEnabled"
#define kIsPPMeetingEnabled @"kIsPPMeetingEnabled"
#define kAmIOriginalHost @"kAmIOriginalHost"
#define kIsInExtendMeeting @"kMTIsInExtendMeeting"
#define kIsInPPMeeting @"kIsInPPMeeting"
#define kExtendMeetingCredits @"kExtendMeetingCredits"
#define kIsMeetingAlreadyExtend @"kIsMeetingAlreadyExtend"

#define kMeetingAssets @"kMeetingAssets"
#define kMTNoticeInfo @"kMTNoticeInfo"

#endif

typedef NS_ENUM(NSUInteger, ZMIMBuddyPresenceType) {
    ZMIMBuddyPresenceType_none,
    ZMIMBuddyPresenceType_unknow,
    ZMIMBuddyPresenceType_offline,
    ZMIMBuddyPresenceType_desktopOnline,
    ZMIMBuddyPresenceType_mobileOnline,
    ZMIMBuddyPresenceType_pzrOnline,
    ZMIMBuddyPresenceType_pzrAway,
    ZMIMBuddyPresenceType_away,
    ZMIMBuddyPresenceType_dnd,
    ZMIMBuddyPresenceType_inMeeting,
    ZMIMBuddyPresenceType_inZoomMeeting,
    ZMIMBuddyPresenceType_inCall,
    ZMIMBuddyPresenceType_e2e,
    ZMIMBuddyPresenceType_other,
    ZMIMBuddyPresenceType_inZoomMeetingPresenting,
    ZMIMBuddyPresenceType_busy,
    ZMIMBuddyPresenceType_outOfOffice
};

typedef enum {
    kPTOpenSettingPageTypeCommon = 0,
    kPTOpenSettingPageTypeAudio,
    kPTOpenSettingPageTypeVideo,
    kPTOpenSettingPageTypeFeedback,
    kPTOpenSettingPageTypeRecord,
    kPTOpenSettingPageTypeAccount,
    kPTOpenSettingPageTypeStatistic,
    kPTOpenSettingPageTypeVirtualBackground,
    kPTOpenSettingPageTypeNotification,
    kPTOpenSettingPageTypeAccessibity,//ZOOM-72640 RTT
    kPTOpenSettingPageTypeStatisticOverall,
    kPTOpenSettingPageTypeUnmuteAudioPrivacy,
    kPTOpenSettingPageTypeVideoFilters,
    kPTOpenSettingPageTypeShortcuts,
    kPTOpenSettingPageTypePrivacy,
    kPTOpenSettingPageTypeShare,
    kPTOpenSettingPageTypeVideoAvatar,
    kPTOpenSettingPageTypeHuddles,
    kPTOpenSettingPageTypeAdmin,
    kPTOpenSettingPageTypeVirtualEffects,
    kPTOpenSettingPageTypeAudioRingtones,
} kPTOpenSettingPageType;

typedef enum{
    kMeetingScheduleType_Preschedule = 0,
    kMeetingScheduleType_Instant  = 1,
    kMeetingScheduleType_Scheudle = 2,
    kMeetingScheduleType_Repeat = 3
}kMeetingScheduleType;

typedef enum {
    kConfPoppingUpTipTypeInfo = 0,
    kConfPoppingUpTipTypeSuccess,
    kConfPoppingUpTipTypeWarning,
    kConfPoppingUpTipTypeError,
    kConfPoppingUpTipTypeInfo_15s,//ZOOM-1561
} ConfPoppingUpTipType;

typedef enum {
    kSettingForConferenceTypeCamera = 0,
    kSettingForConferenceTypeMicrophone,
    kSettingForConferenceTypeSpeaker
} kSettingForConferenceType;
