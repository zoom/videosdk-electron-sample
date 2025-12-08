//
//  ZMTopbarStatusPortocol.h
//  VideoUI
//
//  Created by Michael Lin on 2024/2/1.
//  Copyright © 2024 zoom.us. All rights reserved.
//

#ifndef ZMTopbarStatusPortocol_h
#define ZMTopbarStatusPortocol_h

typedef NS_ENUM(NSUInteger, ZMTopbarItemType) {
    ZMTopbarItemTypeInvalid = 0,
    ZMTopbarItemTypeRecording,
    ZMTopbarItemTypeRecordAction,
    ZMTopbarItemTypeRemainTime,
    ZMTopbarItemTypeSwitchCamera,
    ZMTopbarItemTypeBackToSharing,//pin when receive sharing ZOOM-3159
    ZMTopbarItemTypeOriginalSound,
    ZMTopbarItemTypeLiveStream,
    ZMTopbarItemTypeNewSimulive,
    ZMTopbarItemTypeClock,
    ZMTopbarItemTypeAudioWatermark,//ZOOM-70153
    ZMTopbarItemTypeBandwidth,//ZOOM-82229
    ZMTopbarItemTypeMeetingInfo,//ZOOM-105984
    ZMTopbarItemTypeAudioPrivacy,//ZOOM-169862
    ZMTopbarItemTypeGovDomain,//ZOOM-105984
    ZMTopbarItemTypeMilDomain,//ZOOM-715018
    ZMTopbarItemTypeArchive,
    ZMTopbarItemTypeCameraController,
    ZMTopbarItemTypeAppSignal,//ZOOM-267129
    ZMTopbarItemTypeFocusMode,//ZOOM-271443
    ZMTopbarItemTypeNDI, //ZOOM-273351
    ZMTopbarItemTypeOnAir,
    ZMTopbarItemTypeSummary,    //ZOOM-490929
    ZMTopbarItemTypeIQ,    //ZOOM-544412
    ZMTopbarItemTypeBOBroadcast,    //ZOOM-356559
    ZMTopbarItemTypeBackstage,
    ZMTopbarItemTypeWatchBackstagePresenting,
    ZMTopbarItemTypeWatchLiveWebinarFeed,
    ZMTopbarItemTypeGatewaysIcon,
    ZMTopbarItemTypeTimer,
    ZMTopbarItemTypeBilling,
#ifdef ENABLE_ZAPP
    ZMTopbarItemTypeAppTimer,
    ZMTopbarItemTypeRTMS,
#endif
    ZMTopbarItemTypeSignIn,
    ZMTopbarItemTypeProctoringMode,
    ZMTopbarItemTypeExtendMeeting,
    ZMTopbarItemTypePairZoomRoom,
    ZMTopbarItemTypeMore,
    ZMTopbarItemTypeViewOptions,
    ZMTopbarItemTypeSeperator,
    ZMTopbarItemTypeLID, //ZOOM-614238
#ifdef BUILD_FOR_DOGFOOD
    ZMTopbarItemTypeDogFood,
#endif
    ZMTopbarItemTypeMediaStream,
    ZMTopbarItemTypeDisaster,
    ZMTopbarItemTypeAudioController,
};

typedef NS_ENUM(NSUInteger, ZMTopbarStyle) {
    ZMTopbarStyleInvalid = 0,
    ZMTopbarStyleTopbar = 1 << 0,
    ZMTopbarStyleInfoBar = 1 << 1,
    ZMTopbarStyleMoreMenu = 1 << 2,
    ZMTopbarStyleNewUIStyle = ZMTopbarStyleInfoBar|ZMTopbarStyleMoreMenu,
    ZMTopbarStyleAll = ZMTopbarStyleTopbar|ZMTopbarStyleInfoBar|ZMTopbarStyleMoreMenu,
};

@protocol ZMTopbarStatusPortocol <NSObject>
@optional
- (void)updateTopbarItemWithType:(ZMTopbarItemType)type;

- (void)updateTopbarItemWithType:(ZMTopbarItemType)type andRelayoutUI:(BOOL)relayoutUI;

- (void)updateTopbarUI;
- (void)updateTopbarUIForType:(ZMMTType)type;
- (void)relayoutTopbarUI;
- (void)relayoutTopbarUIForType:(ZMMTType)type;
- (void)refreshAllTopbarItems;
- (void)refreshAllTopbarItemsForType:(ZMMTType)type;

- (void)topbarWithType:(ZMMTType)type style:(ZMTopbarStyle)style appearanceChanged:(BOOL)appearance;

- (void)onTopbarRecordingShownChanged;

- (void)showTopbarAppSignalTip;
- (void)setTopbarRemainTime:(int)remainTime;
- (void)updateTopbarRemainTimeView;
- (void)showTopbarCameraControllerTip;
- (void)showTopbarBroadcastTipAndDismissLater;
- (void)showTopbarAudioControllerTip;

@end

#endif /* ZMTopbarStatusPortocol_h */
