//
//  ZMTipNotificationMgr.h
//  zVideoUI
//
//  Created by javenlee on 2020/07/09.
//  Copyright © 2020 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMTipPanel.h>
#import <zVideoUIBridge/ZMConfSession.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMConfSession (ZMTipType)
- (ZMTipType)tipType;
@end

@interface ZMTipNotificationMgr : NSObject <ZMTipNotificationProtocol>
@property (nonatomic, assign, readonly) BOOL isReloading;
@property (nonatomic, strong, readonly) NSMutableArray<NSPanel<ZMMTTipPanelProtocol> *>* deliveredTipWindowArray;

- (id<ZMMTTipNotification>)newTipNotification;

- (BOOL)needTransformToSystemNotification;
- (NSString*)deliverTipNotification:(id<ZMMTTipNotification>)tip;//return tip identifier
- (BOOL)isTipExistsWithIdentifier:(NSString *)tipIdentifier;
- (void)removeTipWithIdentifier:(NSString *)tipIdentifier;

- (void)setNeedReloadTips:(BOOL)needed;
- (void)setNeedRelayoutTips:(BOOL)needed;
- (void)reloadTips;

- (void)cleanupAllTips;

- (void)windowDidResize;
- (void)relayoutTips;

- (void)updateTipTitle:(NSString *)title WithIdentifier:(NSString *)tipIdentifier;
- (void)updateTipAttributedTitle:(NSAttributedString *)attributedTitle WithIdentifier:(NSString *)tipIdentifier;
- (NSInteger)indexOfRunningTipWindow:(NSPanel<ZMMTTipPanelProtocol> *_Nullable *_Nullable)outTipWindow tipIdentifier:(NSString *)identifier;

- (BOOL)showTip:(ZMTipNotification *)tip;
/// ----------------------------
/// Subclass must override these methods
/// ----------------------------
- (void)showTipWindow:(NSPanel<ZMMTTipPanelProtocol> *)tipWindow;
- (void)layoutDeliveredTipWindow;

- (void)showTipNotification:(ZMTipNotification *)tip;
- (BOOL)canShowTip:(id<ZMMTTipNotification>)tip;

@end

NS_ASSUME_NONNULL_END
