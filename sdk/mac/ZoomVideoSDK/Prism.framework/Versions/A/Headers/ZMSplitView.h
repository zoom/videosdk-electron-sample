//
//  ZMSplitView.h
//
//  Created by francis zhuo on 18/02/2020.
//  Copyright © 2020 fenfei. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Prism/ZMBaseView.h>

NS_ASSUME_NONNULL_BEGIN
@interface NSView (ZMSplitView)
- (void)zm_splitViewWillStartDrag;
- (void)zm_splitViewDidEndDrag;
@end

@protocol ZMSplitViewDelegate;
@class ZMSplitViewItem;
@interface ZMSplitView : ZMBaseView
@property (weak) id<ZMSplitViewDelegate> delegate;
@property (nonatomic, assign) BOOL isContinue;//autolayout always true
@property (assign) BOOL isVertical;//if yes =, if no ||

@property (assign) BOOL useAutoLayout;//default is YES
/**
 *dividerClass need based ZMSplitDivider
 *default is ZMSplitDivider
 */
@property (nonatomic, null_resettable, assign) Class dividerClass;
@property (nonatomic, assign) CGFloat dividerWidth;
@property (nonatomic, readonly) BOOL inLiveDragging;

@property (nonatomic, assign) NSEdgeInsets paddingRatio;//0~1
@property (nonatomic, assign) NSEdgeInsets padding;
@property (nonatomic, assign) NSSize       aspectRatio;//default NSZeroSize, will not take effect

- (void)commonInit NS_REQUIRES_SUPER; // to override

@property (readonly, assign) NSArray* arrangedItems;
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

- (void)beginUpdates;
- (void)relayoutUI;
- (void)endUpdates;
@end
@compatibility_alias ZMMTSplitView ZMSplitView;
NS_ASSUME_NONNULL_END
