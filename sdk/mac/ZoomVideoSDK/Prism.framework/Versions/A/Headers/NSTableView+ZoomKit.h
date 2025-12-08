//
//  NSTableView+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/11.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Prism/NSView+ZoomKit.h>

NS_ASSUME_NONNULL_BEGIN
@interface NSTableView (ZoomKit)

//ZOOM-220478
- (void)makeIntercellZeroSpacingOnARM;
/**
 Selects a row at the specified index if legally, won't extending selection, will ask delegate if possible.
 @note pass -1 will deselect all if possible.
 @param row The row to select.
 @return YES if the row is selected, otherwise NO.
 */
- (BOOL)selectRowSafelyWithoutExtendingSelection:(NSInteger)row;

- (void)selectFirstRow;
- (void)selectLastRow;
- (void)selectNextRow;
- (void)selectPreviousRow;
- (void)selectRow:(NSInteger)index;//Same as -selectRowSafelyWithoutExtendingSelection:
- (void)selectNextRowLoopBack:(BOOL)loopback;
- (void)selectPreviousRowLoopBack:(BOOL)loopback;

@property (nullable, nonatomic) NSTableRowView  *latestHoveredRowView;
@property (nullable, readonly)  NSTableCellView *selectedCellView;
@property (nullable, readonly)  NSTableRowView *selectedRowView;
@property (nonatomic, assign) BOOL loopDisable;  //ZOOM-78260 Rephontil.Zhou
@property (nonatomic, assign, nullable) SEL loadMoreAction;  //ZOOM-78260 Rephontil.Zhou
@property (nonatomic, assign) BOOL usingHoveredRow;
@property (nonatomic, assign) NSInteger hoveredRow;
@property (nonatomic, assign, nullable) SEL hoverAction;
@property (nonatomic, assign, nullable) SEL unHoverAction;
@property (nonatomic, assign) BOOL zm_disableEstimatingRowHeights;

- (void)scrollRowToTopVisible:(NSInteger)row;
- (void)scrollRowToBottomVisible:(NSInteger)row;

@end
NS_ASSUME_NONNULL_END
