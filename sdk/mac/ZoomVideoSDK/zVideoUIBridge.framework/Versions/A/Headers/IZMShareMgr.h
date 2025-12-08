//
//  IZMShareMgr.h
//  VideoUI
//
//  Created by martin.yu on 9/13/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef IZMShareMgr_h
#define IZMShareMgr_h

#import <zVideoUIBridge/ZMMTVideoViewController.h>

NS_ASSUME_NONNULL_BEGIN

enum Support_Center_Share_Type
{
    Support_Center_Share_Type_None,
    Support_Center_Share_Type_Monitor,
    Support_Center_Share_Type_Window,
};

typedef NS_ENUM(NSInteger, ZMSendingShareType){
    ZMSendingShareType_Normal,
    ZMSendingShareType_Slides,
    ZMSendingShareType_WhiteBoard,
    ZMSendingShareType_ZDoc,
};

@protocol IZMSendShareCompatibleStreamMgr <NSObject>
@property (readonly, assign) NSInteger  shareSessionType;

@end

@protocol IZMMTShareCameraMgr <NSObject>
@property (nonatomic, readonly, strong) __kindof ZMMTVideoViewController *viewController;
- (void)switchShareCamera;
- (BOOL)isAble2ShowSwitchCamera;
@end

@protocol IZMMTShareVideoMgr <NSObject>
@property (nonatomic, readonly, strong) __kindof ZMMTVideoViewController *viewController;
@end

@protocol IZMMTShareAudioViewController <NSObject>

- (void)requestCustomResourceIdForLocalRecord;
- (void)prepareForRecording:(BOOL)bForce;
- (uint32_t)getResourceIndexForRecording;
- (uint32_t)getBgResourceIndexForRecording;
@end

@protocol IZMMTShareAudioMgr <NSObject>
- (nullable __kindof ZMMTVideoViewController *)newViewControllerWithType:(ZMMTType)type;
- (nullable __kindof ZMMTVideoViewController *)getViewControllerWithType:(ZMMTType)type;
- (nullable id<IZMMTShareAudioViewController>)getAudioViewControllerWithType:(ZMMTType)type;
@end

@protocol IZMShareMgr <ZMRoutableObject>
@property (nonatomic, readonly, strong) id<IZMMTShareCameraMgr> shareCameraMgr;
@property (nonatomic, readonly, strong) id<IZMMTShareVideoMgr> shareVideoMgr;
@property (nonatomic, readonly, strong) id<IZMMTShareAudioMgr> shareAudioMgr;

- (BOOL)isMainConfWindowNotVisibleWhileSharing;
- (void)onRemoteForbidded;

- (void)stopShare;
- (void)force2ShowSelections:(int)inType bForced:(BOOL)bForced;
- (NSScreen*)getFITScreen;
- (void)cleanZappShareInfo;
- (void)showFitBarForNotifyWithDelay;

- (void)checkAndSetShareSettingType:(int)inType;
- (BOOL)canShowShareSettingMenu;

// ToolSuite
- (void)showShareSettingWindow;
- (void)closeShareSettingWindow;

- (void)showSelectShareWindow;
- (void)closeSelectShareWindow;

- (void)shareCameraWithDeviceId:(NSString*)deviceId;

- (void)onWatermarkStatusChanged;
@end

@protocol ZMShareMgrProcotol <NSObject>

@optional
- (void)shareSettingTypeChanged:(int)inNewType confSession:(ZMConfSession *)confSession;

@end

NS_ASSUME_NONNULL_END

#endif /* IZMShareMgr_h */
