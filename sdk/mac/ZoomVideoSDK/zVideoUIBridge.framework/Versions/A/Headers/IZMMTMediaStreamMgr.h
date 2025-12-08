//
//  IZMMTMediaStreamMgr.h
//  VideoUI
//
//  Created by Javenlee.Li on 2024/6/5.
//  Copyright © 2024 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class ZMAlertPanel;

@protocol IZMMTMediaStreamMgr <ZMRoutableObject>

@property (nonatomic, strong, readonly) NSArray *servers;

- (BOOL)canShowEntrance;
- (BOOL)isCurrentSessionSupport;
- (NSString *)appId;

- (ZMAlertPanel *_Nullable)alertPanelWithIdentifier:(nullable NSString *)identifier makeIfNecessary:(BOOL)makeIfNecessary;

- (void)popupWindowEnalbed:(BOOL)enable;
- (BOOL)isPopupWindowEnabled;
- (BOOL)isPanelShowing;
- (void)openMediaStreamPanel;
- (void)closeMediaStreamPanel;
- (void)showFloatPanel;
- (void)closeFloatPanel;

//callback
- (void)onCommonDiclaimerReceived:(NSString *)noticeId status:(int)noticeStatus;
- (void)onToastStatusUpdated:(NSString *)noticeId status:(int)noticeStatus;
- (void)onIndicatorTabReceived:(NSString *)tabId;
- (void)onIndicatorAppStatusUpdated:(NSString *)noticeId app:(const CmmIndicatorAppItem&)indicator_app;
- (void)onIndicatorTabDeleted:(NSString *)tabID;
- (void)onCommonNoticeDeleted:(const CmmNoticeSet&)cmm_notice;
- (void)onZoomStreamingServiceSwitchChanged:(BOOL)newSwitch;
- (void)onZssStatusChanged;
- (void)onRTMSMgrReady;
@end

NS_ASSUME_NONNULL_END
