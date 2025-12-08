//
//  ZMMTGridView.h
//  ZMGridDemo
//
//  Created by Francis Zhuo on 2020/8/13.
//  Copyright © 2020 Francis Zhuo. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <zVideoUIBridge/ZMMTGridCellView.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTGridViewTrigger:NSObject
@property(copy) NSString* identifier;
@property(strong) NSArray* rectArray;
@end

@class ZMMTGridView;
@protocol ZMMTGridViewDelegate <NSObject>

- (NSInteger)numberOfCellInGridView:(ZMMTGridView*)gridView;
- (nonnull id)gridView:(ZMMTGridView*)gridView objectValueForIndex:(NSInteger)index;
- (NSRect)gridView:(ZMMTGridView*)gridView rectForIndex:(NSInteger)index;

@optional
- (NSRange)visibleCellRangeInGridView:(ZMMTGridView*)gridView;
- (NSIndexSet*)visibleCellIndexsInGridView:(ZMMTGridView*)gridView;

@optional
- (nullable ZMMTGridCellView*)gridView:(ZMMTGridView*)gridView viewForObjectValue:(id)objectValue;
- (nullable ZMMTGridCellView*)gridView:(ZMMTGridView*)gridView viewForObjectValue:(id)objectValue atIndex:(NSInteger)index;

@optional
- (NSString*)gridView:(ZMMTGridView*)gridView identifierForObjectValue:(id)objectValue;

@optional
- (BOOL)gridView:(ZMMTGridView*)gridView cellViewNeedRemoveBeforeAddToGrid:(NSView*)cellView objectValue:(id)objectValue;
- (void)gridView:(ZMMTGridView*)gridView cellViewWillAddToGridView:(NSView*)cellView objectValue:(id)objectValue;
- (void)gridView:(ZMMTGridView*)gridView cellViewDidAddToGridView:(NSView*)cellView objectValue:(id)objectValue;

- (void)gridView:(ZMMTGridView*)gridView cellViewConfigReady:(NSView*)cellView objectValue:(id)objectValue;

- (void)gridView:(ZMMTGridView*)gridView cellViewWillRemoveFromGridView:(NSView*)cellView objectValue:(id)objectValue;
- (void)gridView:(ZMMTGridView*)gridView cellViewDidRemoveFromGridView:(NSView*)cellView objectValue:(id)objectValue;

- (void)gridView:(ZMMTGridView*)gridView recycleCellView:(NSView*)cellView;

//MARK: animation
- (NSArray<CABasicAnimation*>*)getAnimationsInGridView:(ZMMTGridView*)gridView view:(NSView*)view cellRect:(NSRect)cellRect objectValue:(id)objectValue;
- (void)cellViewWillSetNewFrame:(ZMMTGridView*)gridView view:(NSView*)view cellRect:(NSRect)cellRect objectValue:(id)objectValue;

- (void)gridViewBeginRelayoutItem:(ZMMTGridView*)gridView;
- (void)gridViewEndRelayoutItem:(ZMMTGridView*)gridView;

//MARK: drag
- (BOOL)gridView:(ZMMTGridView*)gridView enableDragCellForObjectValue:(id)objectValue;
- (ZMMTGridCellView*)gridView:(ZMMTGridView*)gridView dragViewForObjectValue:(id)objectValue;
- (void)gridView:(ZMMTGridView*)gridView failDragCellForObjectValue:(id)objectValue;
- (void)gridView:(ZMMTGridView*)gridView willDragCellForObjectValue:(id)objectValue;
- (void)gridView:(ZMMTGridView*)gridView beginDragCellForObjectValue:(id)objectValue;
- (void)gridView:(ZMMTGridView*)gridView willEndDragCellForObjectValue:(id)objectValue;
- (void)gridView:(ZMMTGridView*)gridView endDragCellForObjectValue:(id)objectValue newOrderArray:(NSArray*)objectArray;

- (NSArray<ZMMTGridViewTrigger*>*)gridViewTrigger:(ZMMTGridView*)gridView;
- (void)gridView:(ZMMTGridView*)gridView enterTrigger:(ZMMTGridViewTrigger*)trigger;
- (void)gridView:(ZMMTGridView*)gridView moveInTrigger:(ZMMTGridViewTrigger*)trigger;
- (void)gridView:(ZMMTGridView*)gridView exitTrigger:(ZMMTGridViewTrigger*)trigger;

//MARK: keyboard control
- (NSInteger)leftIndexForGridView:(ZMMTGridView*)gridView currentIndex:(NSInteger)curIndex;
- (NSInteger)rightIndexForGridView:(ZMMTGridView*)gridView currentIndex:(NSInteger)curIndex;
- (NSInteger)topIndexForGridView:(ZMMTGridView*)gridView currentIndex:(NSInteger)curIndex;
- (NSInteger)bottomIndexForGridView:(ZMMTGridView*)gridView currentIndex:(NSInteger)curIndex;
- (void)gridView:(ZMMTGridView*)gridView moveIndexToVisible:(NSInteger)index;
- (void)gridView:(ZMMTGridView*)gridView willMoveCellFromIndex:(NSInteger)fromIndex toIndex:(NSInteger)toIndex;
- (void)gridView:(ZMMTGridView*)gridView didMoveCellFromIndex:(NSInteger)fromIndex toIndex:(NSInteger)toIndex newOrderArray:(NSArray*)objectArray;
@end

@interface ZMMTGridView : NSView
@property(nullable, weak) id<ZMMTGridViewDelegate> delegate;
@property(assign) BOOL enable;
@property(nonatomic, assign) BOOL enableAnimation;//default is NO
@property(nonatomic, assign) BOOL enableDrag;//default is NO
@property(readonly, strong) NSIndexSet* visibleCellIndexs;
@property(readonly, strong) NSMutableArray* displayCellArray;
@property(readonly, assign) BOOL isDragging;
@property(readonly, strong) id draggingObject;

- (__kindof NSView*)displayDraggingView;
- (nullable __kindof NSView*)displayViewAtPoint:(NSPoint)point;
- (nullable __kindof NSView*)displayViewForObjectValue:(id)objectValue;

- (void)reloadData;
- (void)reloadDataWithAnimation:(BOOL)animation;
- (void)setNeedsRelayout:(BOOL)needsRelayout;
- (void)removeAllCellView;
- (BOOL)cancelMouseDragIfNeed;

- (void)beginRelayoutItems NS_REQUIRES_SUPER;
- (void)endedRelayoutItems NS_REQUIRES_SUPER;

///convert display Index to zeroize Index
- (NSInteger)convertToZeroizeIndex:(NSInteger)displayIndex;
- (nullable ZMMTGridCellView*)cellViewForObjectValue:(id)objectValue;//for over write
- (void)recycleCellView:(ZMMTGridCellView*)cellView;//for over write
- (nullable __kindof NSView *)makeViewWithIdentifier:(NSUserInterfaceItemIdentifier)identifier owner:(nullable id)owner;

- (void)cellViewBecomeFirstResponder:(nullable ZMMTGridCellView*)cellView;
- (BOOL)isCellViewSelected:(ZMMTGridCellView*)cellView;
- (BOOL)isCellViewMoveable:(ZMMTGridCellView*)cellView;

@end

@interface NSView(ZMMTGridView)
@property(retain, nullable) id zm_objectValue;
@end

NS_ASSUME_NONNULL_END
