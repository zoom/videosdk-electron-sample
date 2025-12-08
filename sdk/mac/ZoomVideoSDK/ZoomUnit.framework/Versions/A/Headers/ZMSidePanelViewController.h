//
//  ZMSidePanelViewController.h
//  VideoUI
//
//  Created by Jun Pang on 3/23/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Prism/Prism.h>
#import <ZoomUnit/ZMSidePanelItem.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMSidePanelViewController;
@protocol ZMSidePanelViewControllerDelegate <NSObject>
@optional
- (void)onViewWillAppear:(ZMSidePanelViewController*)viewController;
- (void)onViewDidAppear:(ZMSidePanelViewController*)viewController;
- (void)onViewWillDisappear:(ZMSidePanelViewController*)viewController;
- (void)onViewDidDisappear:(ZMSidePanelViewController*)viewController;

- (void)onSidePanelItemCountChanged:(ZMSidePanelViewController*)viewController;
//for support not auto layout
- (NSSize)getCurrentSidePanelSize;
- (void)updateSidePanelWidth:(CGFloat)width;
@end

@protocol ZMSidePanelItem;
@interface ZMSidePanelViewController : ZMBaseViewController
@property (strong) ZMBaseView* view;
@property (nullable, weak) id<ZMSidePanelViewControllerDelegate> delegate;
@property (nullable, readonly) NSArray<id<ZMSidePanelItem>>* displayingItemArray;

@property(readonly, assign) BOOL isViewShowing;
- (void)showView NS_REQUIRES_SUPER;
- (void)hideView;

- (void)addItem:(id<ZMSidePanelItem>)item;
- (void)removeItem:(id<ZMSidePanelItem>)item;
- (void)removeAllItems;
- (BOOL)isItemInSidePanel:(id<ZMSidePanelItem>)item;

#pragma mark - miniaturize
- (BOOL)isItemMiniaturized:(id<ZMSidePanelItem>)item;
- (BOOL)canMiniaturizeItem:(id<ZMSidePanelItem>)item;
- (BOOL)canDeminiaturizeItem:(id<ZMSidePanelItem>)item;

- (void)miniaturizeItem:(id<ZMSidePanelItem>)item;
- (void)deminiaturizeItem:(id<ZMSidePanelItem>)item;
@end

NS_ASSUME_NONNULL_END
