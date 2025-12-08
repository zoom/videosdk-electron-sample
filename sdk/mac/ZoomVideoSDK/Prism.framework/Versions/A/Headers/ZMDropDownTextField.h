//
//  ZMDropDownTextField.h
//  ZCommonUI
//
//  Created by Geno on 2019/6/25.
//  Copyright © 2019 chenjiannan. All rights reserved.
//

#import <Prism/ZMTextField.h>
#import <Prism/ZMDropDownListView.h>

@class ZMDropDownTextField;

NS_ASSUME_NONNULL_BEGIN

@protocol ZMDropDownTextFieldDelegate <NSTextFieldDelegate>
@optional
- (void)dropDownTextFieldWillShowList:(ZMDropDownTextField *)textField;
- (void)dropDownTextFieldWillHideList:(ZMDropDownTextField *)textField;
- (void)dropDownTextField:(ZMDropDownTextField *)textField didSelectItem:(ZMDropDownItem *)item;

@end

@interface ZMDropDownTextField : ZMTextField

/** max height of drop down list, default is 200 */
@property (nonatomic, assign) CGFloat dropDownMaxHeight;
/** whether to display icon on the left, default is NO */
@property (nonatomic, assign, getter=isShowIcon) BOOL showIcon;
/** size of icon on the left, default is {16, 16} */
@property (nonatomic, assign) NSSize iconSize;
/** items for drop down list */
@property (nonatomic, weak) NSArray <ZMDropDownItem *> *itemArray;
/** height for item on drop down list, default is 32 */
@property (nonatomic, assign) CGFloat itemHeight;
/** whether to display expend icon on the right, default is YES */
@property (nonatomic, assign) BOOL showExpandImage;
/** whether to adjust the height of drop down list according to the number of items, defalut is NO */
@property (nonatomic, assign) BOOL autoAdjustDropDownHeight;

@property (nonatomic, assign) BOOL showErrorBorderColor;

@property (nullable, weak) id <ZMDropDownTextFieldDelegate> delegate;

@property (nonatomic, retain, nullable) ZMDropDownItem *selectedItem;

/** Should select next key view after press Enter key, default value is YES */
@property (nonatomic, assign) BOOL shouldSelectNextKeyView;

- (void)cleanUp;

- (ZMDropDownItem *)addItemWithTitle:(NSString *)title;
- (ZMDropDownItem *)addItemWithTitle:(NSString *)title icon:(NSImage *)icon;
- (void)insertItem:(ZMDropDownItem *)item atIndex:(NSInteger)index;

- (void)removeItemWithTitle:(NSString *)title;
- (void)removeItemAtIndex:(NSInteger)index;
- (void)removeAllItems;

// return NSNotFound when the item not found
- (NSInteger)indexOfItem:(ZMDropDownItem *)item;
- (NSInteger)indexOfItemWithTitle:(NSString *)title;
- (NSInteger)indexOfItemWithTag:(NSInteger)tag;

- (void)selectItemAtIndex:(NSInteger)index;
- (void)selectItemWithTitle:(NSString *)title;
- (void)selectItemWithTag:(NSInteger)tag;

// interface for subclass to relayout UI
- (NSRect)iconRectForBounds:(NSRect)bounds;
- (NSRect)expandIconRectForBounds:(NSRect)bounds;


- (void)showDropDownListView;

// If the ZMDropDownTextField is added to the scrollView, when the list is displayed, the scrollview starts to scroll and the list should be hidden. In order to achieve this goal, you need to set up [_scrollView.contentView setPostsBoundsChangedNotifications:YES];
- (void)hideDropDownListView;

@end

NS_ASSUME_NONNULL_END
