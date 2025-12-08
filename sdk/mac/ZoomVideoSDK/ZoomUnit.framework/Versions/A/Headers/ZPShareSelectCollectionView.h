//
//  ZPShareSelectCollectionView.h
//  ZCommonUI
//
//  Created by sanshi on 3/26/12.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@class ZPShareSelectCollectionView;
@protocol ZPShareSelectCollectionViewDelegate <NSObject>
/// User interacts with a item whether it is selected or not. In single selection mode, item is selected or reselected. In multi-selction mode, item is seleted or unselected.
- (void)collectionView:(nonnull ZPShareSelectCollectionView *)collection didSelectItem:(nonnull NSCollectionViewItem *)item;
- (void)collectionViewSelectedItemDidChange:(ZPShareSelectCollectionView*_Nonnull)collection;
- (void)collectionViewStartShareSelectedItem:(ZPShareSelectCollectionView*_Nonnull)collection;
- (void)collectionViewStartShare:(ZPShareSelectCollectionView*_Nonnull)collection collectionItem:(NSCollectionViewItem *_Nonnull)item;
@optional
- (void)collectionViewMoreMenuClicked:(ZPShareSelectCollectionView*_Nonnull)collection collectionItem:(NSCollectionViewItem *_Nonnull)item menuTag:(NSInteger)menuTag;
- (NSNumber *_Nullable)moreMenuSelectedStatus:(ZPShareSelectCollectionView*_Nonnull)collection collectionItem:(NSCollectionViewItem *_Nonnull)item;
@end

@class ZPShareSelectWindowController;
@class ZPShareSelectView;


@interface ZPShareSelectCollectionView : NSCollectionView
{
    ZPShareSelectView *_lastHoveredView;
}
@property (nonatomic, weak, nullable) id<ZPShareSelectCollectionViewDelegate> mgrDelegate;
@property (nonatomic, assign) BOOL isShiftKeyDown;
@property (nonatomic, retain, readwrite, nullable) ZPShareSelectView *lastHoveredView;
@property (assign) NSUInteger maxMultiSelectDesktop;
@property (assign) BOOL supportMultiSelectDesktop;
@property (assign, readonly) NSUInteger itemCountPerRow;
- (void)cleanUp;
- (void)collectViewItemDidDoubleClicked:(NSCollectionViewItem * _Nonnull)item;
- (void)collectViewItemReturnKeyPressed:(NSCollectionViewItem * _Nonnull)item;
- (void)collectViewItemDidHovered:(NSCollectionViewItem * _Nonnull)item hovered:(BOOL)hovered;
- (void)collectViewItemWillSelect:(NSCollectionViewItem * _Nonnull)item;
- (void)collectViewItemWillSelectTop:(NSCollectionViewItem * _Nonnull)item;
- (void)collectViewItemWillSelectBottom:(NSCollectionViewItem * _Nonnull)item;
- (void)collectViewItemWillSelectLeft:(NSCollectionViewItem * _Nonnull)item;
- (void)collectViewItemWillSelectRight:(NSCollectionViewItem * _Nonnull)item;
- (void)collectViewItemSelectPreviousValidKeyView:(NSCollectionViewItem * _Nonnull)item;
- (void)collectViewItemSelectNextValidKeyView:(NSCollectionViewItem * _Nonnull)item;
- (void)collectViewItemDidBecomeFirstResponse:(NSCollectionViewItem * _Nonnull)item;
- (void)collectViewItemMoreMenuClicked:(NSCollectionViewItem * _Nonnull)item menuTag:(NSInteger)menuTag;
- (NSNumber *_Nullable)moreMenuSelectedStatus:(NSCollectionViewItem*_Nonnull)item;
- (void)setSelectionIndexPaths:(NSSet<NSIndexPath *> *_Nonnull)selectionIndexPaths shouldAutoScroll:(BOOL)shouldAutoScroll;
@end
