//
//  ZMSplitViewController.h
//  SaasBeeConfUIModule
//
//  Created by Francis Zhuo on 8/15/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <Prism/ZMBaseViewController.h>
#import <Prism/ZMSplitView.h>
#import <Prism/ZMSizeScaleFactor.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMSplitViewItem;
@protocol ZMSplitViewDelegate <NSObject>
@optional
- (void)splitView:(ZMSplitView*)splitView splitItemWillCollapse:(ZMSplitViewItem*)splitItem;
- (void)splitView:(ZMSplitView*)splitView splitItemDidCollapsed:(ZMSplitViewItem*)splitItem;
- (void)splitView:(ZMSplitView*)splitView splitItemWillExpand:(ZMSplitViewItem*)splitItem;
- (void)splitView:(ZMSplitView*)splitView splitItemDidExpanded:(ZMSplitViewItem*)splitItem;

@end
#define ZMMTSplitViewDelegate ZMSplitViewDelegate

@interface ZMSplitViewItem : NSObject
@property (weak, readonly) ZMSplitView* splitView;
@property (readonly) NSView* view;
@property (assign) Class backgroundViewClass;
@property (assign) BOOL canCollapse;
@property (nonatomic, getter=isCollapsed) BOOL collapsed;

@property (nonatomic, assign) Class dividerClass;
@property (nonatomic, assign) CGFloat dividerWidth;

@property (nullable, nonatomic, retain) ZMBaseViewController* viewController;
@property (nullable, nonatomic, retain) NSView* documentView;//recommend use viewController

@property (nonatomic, assign) NSEdgeInsets paddingRatio;//0~1
@property (nonatomic, assign) NSEdgeInsets padding;
@property (nonatomic, assign) NSSize       aspectRatio;//default NSZeroSize, will not take effect

@property (nonatomic, assign) NSSize intrinsicContentSize;
@property (assign) NSSize minimumSize;
@property (assign) NSSize maximumSize;

@property (assign) NSInteger sizePriority;//1~499, default 300
@property (assign) NSInteger resizePriority;//1~499, default 300

- (void)commonInit NS_REQUIRES_SUPER;

@property (assign) BOOL autoSaveViewSizeScale;//default is YES
@property (nonatomic, null_resettable, retain) ZMSizeScaleFactor* scaleFactor;
- (void)saveViewSizeScale;
- (void)restoreViewSizeByScale;

- (void)loadDocumentViewIfNeed NS_REQUIRES_SUPER;//for override
@end
@compatibility_alias ZMMTSplitViewItem ZMSplitViewItem;

@interface ZMSplitViewController : ZMBaseViewController
@property(retain) ZMSplitView* view;
/**
 *dividerClass need based ZMSplitDivider
 *default is ZMSplitDivider
 */

/**
 *Adds a split view item to the end of the splitViewItems array of the split view controller.
 */
- (void)addSplitViewItem:(ZMSplitViewItem*)viewItem;

/**
 *Adds a split view item to the splitViewItems array of the split view controller, at a specified index position.
 */
- (void)insertSplitViewItem:(ZMSplitViewItem *)splitViewItem atIndex:(NSInteger)index;

/**
 * Removes a specified split view item from the split view controller.
 */
- (void)removeSplitViewItem:(ZMSplitViewItem *)splitViewItem;

/**
 Begins a group of updates for the SplitView
 */
- (void)beginUpdates;
/**
 Ends the group of updates for the SplitView
 Please ensure the split view did add to window, otherwise will not trigger relayoutUI, especially the case with splitview nesting
 */
- (void)endUpdates;
@end
@compatibility_alias ZMMTSplitViewController ZMSplitViewController;
NS_ASSUME_NONNULL_END
