//
//  ZMListView.h
//  ZMListViewDemo
//
//  Created by groot.ding on 2/18/23.
//

#import <Cocoa/Cocoa.h>
#import <Prism/ZMMutableSelectProtocal.h>

NS_ASSUME_NONNULL_BEGIN
@protocol ZMListReuseViewProtocal <NSObject>
@optional
- (void)viewWillAddToReuseCache;
@end

typedef NS_OPTIONS(NSInteger, ZMListViewCellType){
    ZMListViewCellType_Normal       = 0,
    ZMListViewCellType_SectionHeader= 1<<1,
    ZMListViewCellType_SectionFooter= 1<<2,
    ZMListViewCellType_GroupHeader  = 1<<3,
    ZMListViewCellType_GroupFooter  = 1<<4,
};

typedef NS_OPTIONS(NSInteger, ZMListViewGroupType){
    ZMListViewGroupType_None            = 0,   //can not display as groupItem
    ZMListViewGroupType_Header          = 1<<1,//can display as groupItem in top
    ZMListViewGroupType_Footer          = 1<<2,//can display as groupItem in bottom
    ZMListViewGroupType_SectionHeader   = 1<<3,//can display as groupItem in top when it's section header
    ZMListViewGroupType_SectionFooter   = 1<<4,//can display as groupItem in bottom when it's section footer and section header is display in top
};

typedef NS_ENUM(NSInteger, ZMListViewGroupSegEffect){
    ZMListViewGroupSegEffect_None,
    ZMListViewGroupSegEffect_Line,
    ZMListViewGroupSegEffect_Shadow,
    ZMListViewGroupSegEffect_Custom,
};

typedef NS_ENUM(NSInteger, ZMListViewAutoPreventDitheringPreference){
    ZMListViewAutoPreventDitheringPreferenceTop,
    ZMListViewAutoPreventDitheringPreferenceBottom,
};

@interface ZMListViewGroupSegEffectView : NSView
@property(nonatomic,assign) ZMListViewGroupSegEffect effect;
@property(nonatomic,assign) ZMListViewCellType viewType;
@property(nonatomic,null_resettable,strong) NSColor* color;
@end

@interface ZMListViewSelectRange : NSObject
@property(nonatomic, assign) BOOL isSelectedAll;
@property(nonatomic, assign) NSPoint startPoint;
@property(nonatomic, assign) NSPoint endedPoint;

@property(nullable, nonatomic, strong) id representedObject;//cache user select info
@end

@protocol ZMListViewCellViewProtocol <ZMMutableSelectProtocal>
@optional
@property(nonatomic, getter=isSelected) BOOL selected;//selected row
@property(nonatomic, getter=isHovered) BOOL hovered;//hovered row

- (BOOL)updateCellView;

- (nullable id)selectTextWithRange:(nullable ZMListViewSelectRange*)range;//return an object to indicate what you selected.
- (void)onClickAtPoint:(NSPoint)point event:(NSEvent*)event;
- (nullable id)onDoubleClickAtPoint:(NSPoint)point event:(NSEvent*)event;//return an object to indicate what you selected.
@end

@class ZMListView;
@protocol ZMListViewDataSource <NSObject>
- (NSInteger)listView:(ZMListView *)listView numberOfChildrenOfItem:(nullable id)item;

- (nullable id)listView:(ZMListView *)listView child:(NSInteger)index ofItem:(nullable id)item;

@optional
- (BOOL)listView:(ZMListView *)listView isItemExpandable:(id)item;

- (BOOL)listView:(ZMListView *)listView isItemExpanded:(id)item;

///if all childChildren are visible, return NSMakeRange(0, NSIntegerMax)
- (NSRange)listView:(ZMListView *)listView visibleChildrenRangeOfItem:(nullable id)item;
@end

@protocol ZMListViewDelegate <NSObject>

@optional

- (nullable NSView *)listView:(ZMListView *)listView viewForItem:(id)item;
- (nullable NSView *)listView:(ZMListView *)listView viewForItem:(id)item viewType:(ZMListViewCellType)type;

- (nullable NSString*)listView:(ZMListView *)listView identifierForItem:(id)item;

- (CGFloat)listView:(ZMListView *)listView heightOfRowByItem:(id)item;
- (CGFloat)listView:(ZMListView *)listView heightOfSectionItem:(id)item viewType:(ZMListViewCellType)type;

- (BOOL)listView:(ZMListView *)listView checkValidateMenuItem:(NSMenuItem *)menuItem;

- (BOOL)listView:(ZMListView *)listView interceptKeyDown:(NSEvent *)event;

- (BOOL)listView:(ZMListView *)listView shouldBecomeKeyView:(id)item;

- (BOOL)listView:(ZMListView *)tableView shouldSelectRow:(NSInteger)row;

- (void)listView:(ZMListView *)listView cellView:(NSView *)cellView clickAtPoint:(CGPoint)point;

- (void)listView:(ZMListView *)listView rightMouseDown:(CGPoint)point;

- (void)listView:(ZMListView *)listView hoverRow:(NSInteger)newHoverRow oldHoverRow:(NSInteger)oldHoverRow;

// can do something before cellView call updateCellView
- (void)listView:(ZMListView *)listView updateCellView:(NSView *)cellView forItem:(id)item;
- (void)listView:(ZMListView *)listView didAddCellView:(NSView *)cellView row:(NSInteger)row;
- (void)listView:(ZMListView *)listView didRemoveCellView:(NSView *)cellView row:(NSInteger)row;

- (void)listViewBoundsDidChanged:(ZMListView *)listView;
- (void)listViewBeginLiveScroll:(ZMListView *)listView;
- (void)listViewDidLiveScroll:(ZMListView *)listView;
- (void)listViewEndedLiveScroll:(ZMListView *)listView;
- (void)listViewSelectionDidChange:(ZMListView *)listView;

- (void)listView:(ZMListView *)listView itemWillExpand:(id)item;
- (void)listView:(ZMListView *)listView itemDidExpand:(id)item;
- (void)listView:(ZMListView *)listView itemWillCollapse:(id)item;
- (void)listView:(ZMListView *)listView itemDidCollapse:(id)item;

- (BOOL)listView:(ZMListView *)listView isSectionItem:(id)item;
- (ZMListViewGroupType)listView:(ZMListView *)listView isGroupItem:(id)item viewType:(ZMListViewCellType)type;

- (void)listView:(ZMListView *)listView copy:(nullable id)sender;
@end

@interface ZMListView : NSControl

@property (nullable, weak) id <ZMListViewDataSource> dataSource;
@property (nullable, weak) id <ZMListViewDelegate> delegate;

@property (readonly) NSInteger numberOfRows;
@property (nonatomic, assign) NSInteger numberOfPreloadRows;//default ZMListShowMoreData = 3

@property (nonatomic, assign) BOOL autoExpandChilds;
@property (nonatomic, assign) BOOL displayInTopWhenExpand;

@property (nonatomic, assign) CGFloat rowHeight;
@property (nonatomic, assign) BOOL dynamicLoadRowHeight;
@property (nonatomic, assign) BOOL usesAutomaticRowHeights;
@property (nonatomic, assign) BOOL useAutoLayout;//default is NO

@property (nonatomic, assign) BOOL isEnableTrack;//default is NO
@property (nonatomic, assign) NSInteger hoveredRow;

@property (nonatomic, assign) NSInteger selectedRow;
@property (nonatomic, assign) BOOL arrowKeyDownSelectHoverRow;
@property (nonatomic, assign) BOOL hoverToSelectRow;

@property (nonatomic, assign) BOOL supportSelectedText;//default is NO
@property (nonatomic,assign) BOOL isSelectTextAllRow;

@property (nonatomic, assign) BOOL inLivingSelectText;

@property (nonatomic, readonly) BOOL inLivingScroll;

@property (nonatomic, assign) BOOL mouseDownCanMoveWindow;

//float group Item
@property (nonatomic, assign) NSInteger maxNumberOfHeaderGroupItem;//default 0
@property (nonatomic, assign) NSInteger maxNumberOfFooterGroupItem;//default 0
@property (nonatomic, assign) ZMListViewGroupSegEffect groupSegmentationEffect;
@property (nonatomic, null_resettable, strong) ZMListViewGroupSegEffectView* headerGroupEffectView;
@property (nonatomic, null_resettable, strong) ZMListViewGroupSegEffectView* footerGroupEffectView;

- (nullable __kindof NSView *)makeViewWithIdentifier:(nonnull NSUserInterfaceItemIdentifier)identifier;

- (void)scrollRowToVisible:(NSInteger)row;
- (void)scrollRowToBottomVisible:(NSInteger)row;

- (void)reloadData;
- (void)reloadDataWithItem:(nullable id)item;

- (void)reloadItem:(id)item;

///The datasource has changed and this row of data needs to be reloaded
- (void)reloadDataWithIndexes:(NSIndexSet *)indexes inParent:(nullable id)parent;

///The datasource item remains unchanged. Only the UI need refreshed, maybe cause by item's property changed
- (void)reloadDataForRowIndexes:(NSIndexSet *)rowIndexes;

- (void)noteHeightOfRowsWithIndexesChanged:(nonnull NSIndexSet *)indexSet;
- (void)noteAllRowsHeightChanged;
- (void)noteHeightChangedForRow:(NSInteger)row;//will layout all cell view immediately, so call it if you are necessary

- (NSRect)rectOfRow:(NSUInteger)row;

- (NSRange)rowsInRect:(NSRect)rect;

- (NSInteger)rowAtPoint:(NSPoint)point;

- (nullable NSIndexSet *)visibleRows;

- (BOOL)isVisibleItem:(id)item;

- (nullable id)itemAtRow:(NSUInteger)row;

- (NSUInteger)rowForItem:(id)item;
- (NSUInteger)rowForItem:(id)item viewType:(ZMListViewCellType)type;

- (nullable __kindof NSView *)viewAtRow:(NSInteger)row;
- (nullable __kindof NSView *)viewAtColumn:(NSInteger)column row:(NSInteger)row makeIfNecessary:(BOOL)makeIfNecessary;

- (void)enumerateAvailableRowViewsUsingBlock:(nullable void (NS_NOESCAPE ^)(__kindof NSView *view, NSInteger row))handler;

/* Returns YES if 'item' is expandable and can contain other items.
 */
- (BOOL)isExpandable:(nullable id)item;
- (BOOL)isItemExpanded:(nullable id)item;
- (void)setVisibleChildrenRange:(NSRange)visibleRange forItem:(nullable id)item;

- (void)expandItem:(nullable id)item expandChildren:(BOOL)expandChildren;

/* Calls expandItem:expandChildren with 'expandChildren == NO'
*/
- (void)expandItem:(nullable id)item;

/* Collapses 'item' and all children if 'collapseChildren' is YES. On 10.5 and higher, passing 'nil' for 'item' will collapse each item under the root.
*/
- (void)collapseItem:(nullable id)item collapseChildren:(BOOL)collapseChildren;

/* Calls collapseItem:collapseChildren with 'collapseChildren == NO'
*/
- (void)collapseItem:(nullable id)item;

- (void)insertItemsAtIndexes:(nonnull NSIndexSet *)indexes inParent:(nullable id)parent withAnimation:(NSTableViewAnimationOptions)animationOptions;
- (void)removeItemsAtIndexes:(nonnull NSIndexSet *)indexes inParent:(nullable id)parent withAnimation:(NSTableViewAnimationOptions)animationOptions;
- (void)moveItemAtIndex:(NSInteger)fromIndex inParent:(nullable id)oldParent toIndex:(NSInteger)toIndex inParent:(nullable id)newParent;

- (void)deselectAll:(nullable id)sender;

- (void)reTileList;

//support selected text
- (void)selectAll:(nullable id)sender;
- (void)copy:(nullable id)sender;
- (void)copyUsingBlock:(nullable void (NS_NOESCAPE ^)(id item, NSInteger row, ZMListViewCellType viewType, ZMListViewSelectRange* range, BOOL *stop))handler;

- (void)didAddCellView:(__kindof NSView *)cellView forRow:(NSInteger)row NS_REQUIRES_SUPER;
- (void)didRemoveCellView:(__kindof NSView *)cellView forRow:(NSInteger)row NS_REQUIRES_SUPER;

//click action
/* return NSNotFound if not clicked in any row*/
@property (nonatomic, readonly) NSInteger clickedRow;

@property (nonatomic, assign) BOOL useUpDownArrowSelectRow;//default YES;
@property (nonatomic, assign) BOOL useLeftRightArrowExpandCollapseRow;//default NO;

@property (nonatomic, assign) BOOL autoPreventDithering;//keep dithering when reload/update item
@property (nonatomic, assign) ZMListViewAutoPreventDitheringPreference autoPreventDitheringPreference;
- (void)lockFocusWhenRetileWithRow:(NSInteger)row;

- (void)beginUpdates:(BOOL)keepFocus;
- (void)endUpdates;
@end


//for ZMListView sub class
@class ZMListCellItem;
@interface ZMListView(_protected)
@property (nonatomic,retain,readonly) ZMListCellItem *rootCellItem;
@property (nonatomic,retain,readonly) NSMutableArray *subCellViews;
- (void)setNeedRelayoutCellView:(BOOL)needsLayout;
- (nullable ZMListCellItem *)quickFindCellAtRow:(NSUInteger)row;
@end

@class ZMListView;
@class ZMListCellItem;
@interface NSView(ZMListView)
- (nullable ZMListView*)enclosingListView;

@property (nonatomic, strong, nullable) ZMListCellItem *zm_cell;
@property (nonatomic, assign, nullable) ZMListView* zm_listView;
@end
NS_ASSUME_NONNULL_END
