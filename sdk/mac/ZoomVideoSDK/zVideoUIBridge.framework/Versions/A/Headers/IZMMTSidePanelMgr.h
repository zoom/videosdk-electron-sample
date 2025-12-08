//
//  ZMSidePanel.h
//  VideoUI
//
//  Created by Jun Pang on 3/31/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//
#import <zVideoUIBridge/ZMMTSidePanelBaseItem.h>

NS_ASSUME_NONNULL_BEGIN
@protocol IZMMTSidePanelMgr <NSObject>

- (BOOL)shouldShowSidePanel;
- (BOOL)canShowSidePanel;
- (BOOL)isSidePanelShow;
- (BOOL)isInSidePanelModel;
- (CGFloat)getCurrentSidePanelWidth;
- (NSView*)getCurrentSidePanelView;
- (void)setSidePanelScale:(CGFloat)scale;//0.3-0.8
- (void)setSidePanelWidth:(CGFloat)width;

- (BOOL)isItemInSidePanel:(id<ZMSidePanelItem>)sidePanelItem;

- (void)showSidePanelItem:(id<ZMSidePanelItem>)sidePanelItem;
- (void)closeSidePanelItem:(id<ZMSidePanelItem>)sidePanelItem;
- (void)closeSidePanel;

- (BOOL)isSidePanelItemMiniaturized:(id<ZMSidePanelItem>)sidePanelItem;
- (BOOL)canMiniaturizeSidePanelItem:(id<ZMSidePanelItem>)sidePanelItem;
- (void)miniaturizeSidePanelItem:(id<ZMSidePanelItem>)sidePanelItem;

- (BOOL)canDeminiaturizeSidePanelItem:(id<ZMSidePanelItem>)sidePanelItem;
- (void)deminiaturizeSidePanelItem:(id<ZMSidePanelItem>)sidePanelItem;

- (void)collapseSidePanel:(id<ZMSidePanelItem>)sidePanelItem;
- (void)expandSidePanel:(id<ZMSidePanelItem>)sidePanelItem;
- (BOOL)isSidePanelExpanded;
- (NSSize)getCurrentSidePanelSize;

- (void)registRestoreItem:(id<ZMSidePanelItem>)sidePanelItem;
- (void)unregistRestoreItem:(id<ZMSidePanelItem>)sidePanelItem;
@end
NS_ASSUME_NONNULL_END
