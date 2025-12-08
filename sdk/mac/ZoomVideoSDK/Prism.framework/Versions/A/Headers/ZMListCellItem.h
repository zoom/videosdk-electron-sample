//
//  ZMListCellItem.h
//  ZMListViewDemo
//
//  Created by groot.ding on 2/22/23.
//

#import <Foundation/Foundation.h>
#import <Prism/ZMListView.h>
NS_ASSUME_NONNULL_BEGIN

@class ZMListView;
@class ZMListCellItem;

@interface ZMListRowAccessibilityElement : NSAccessibilityElement

@property (nonatomic,weak) ZMListCellItem *rowItem;

@end

@interface ZMListCellItem : NSObject
@property (nonatomic,retain) NSString* identifier;
@property (nonatomic,retain) NSObject *representedObject;

@property (nonatomic,assign) NSUInteger row;

@property (nonatomic,assign) BOOL isExpandable;
@property (nonatomic,assign) BOOL isExpanded;
@property (nonatomic,assign) NSRange visibleChilds;//defult NSMakeRange(0, NSIntegerMax), all childs can visible

@property (nonatomic,assign) BOOL needUpdateCellHeight;

@property (nonatomic,assign) BOOL needUpdateCellView;
@property (nonatomic,assign) BOOL needUpdateGroupHeaderView;
@property (nonatomic,assign) BOOL needUpdateGroupFooterView;

@property (nonatomic,assign) CGFloat cellHeight;

@property (nonatomic,assign) CGFloat cellPointY;
@property (nonatomic,readonly) CGFloat cellMaxY;

@property (nullable,nonatomic,weak) ZMListCellItem *parentItem;

@property (nonatomic,assign) BOOL needLoadChilds;
@property (nonatomic,retain) NSMutableArray <ZMListCellItem *> *childs;

@property (nonatomic,readonly) BOOL isHidden;

@property (nonatomic,readonly) NSInteger totleChildrensCount;

@property (nonatomic,retain) ZMListRowAccessibilityElement *accessibilityElement;

@property (nonatomic,weak) ZMListView *listView;

@property (nonatomic,weak) NSView *cellView;
@property (nonatomic,weak) NSView *groupHeaderView;
@property (nonatomic,weak) NSView *groupFooterView;
@property (nonatomic,assign) BOOL needUpdateGroupCellHeight;
@property (nonatomic,assign) CGFloat groupCellHeight;

@property (nonatomic,assign) ZMListViewGroupType groupType;
@property (readonly) BOOL isGroupHeaderItem;
@property (readonly) BOOL isGroupFooterItem;

@property (nonatomic,assign) ZMListViewCellType cellType;
@property (nullable,nonatomic,retain) ZMListCellItem *sectionFooterItem;

@property (nonatomic,assign) BOOL isSelected;
@property (nonatomic,assign) BOOL isHovered;

//support select text
@property(nullable,nonatomic, strong) ZMListViewSelectRange* selectRange;
- (void)setSelectedAll:(BOOL)selectedAll;
- (void)selectTextWithRange:(ZMListViewSelectRange*)range;
- (void)selectTextWithDoubleClickEvent:(NSEvent*)event;
- (void)deselectedAll:(BOOL)alsoChildren;

+ (instancetype)itemWithRepresentedObject:(NSObject *)representedObject;

- (BOOL)addChildItem:(nonnull ZMListCellItem *)childItem;
- (BOOL)insertChildItem:(ZMListCellItem *)childItem atIndex:(NSInteger)index;
- (BOOL)removeChildItem:(nonnull ZMListCellItem *)childItem;
- (BOOL)removeChildItemAtIndex:(NSUInteger)index;

- (NSUInteger)getChildIndex:(nonnull ZMListCellItem *)childItem;
- (nullable ZMListCellItem *)getChildCellByIndex:(NSUInteger)index;
- (void)updateAccessibilityElementInfo;

- (void)setExpanded:(BOOL)isExpanded alsoChildren:(BOOL)alsoChildren;

- (void)setNeedUpdateCellHeight:(BOOL)needUpdateCellHeight asloUpdateChildren:(BOOL)asloUpdateChildren;

- (BOOL)pointYInCell:(CGFloat)pointY;

- (void)cleanData;
- (void)cleanChildsRow;

- (NSArray *)getAllRowsAccessibilityElements;
@end

NS_ASSUME_NONNULL_END
