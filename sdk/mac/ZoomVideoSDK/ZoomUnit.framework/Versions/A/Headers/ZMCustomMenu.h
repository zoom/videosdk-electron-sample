//
//  ZMCustomMenu.h
//  ZCommonUI
//
//  Created by John on 11/25/14.
//  Copyright (c) 2014 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@class ZMUILibPopupDlg;

@protocol ZMCustomMenuItem
- (void)setItemState:(int)state;
- (void)setItemSelect:(BOOL)flag;
- (BOOL)isItemSelected;
- (BOOL)isItemSelectable;
- (void)sendItemAction;
- (NSView*)getItemView;
- (float)preferedWidth;
@end

@interface ZMMenuControlView : NSView
{
    BOOL                _isHover;
    NSTrackingArea*     _trackingArea;
}
@property(nonatomic, strong) NSTrackingArea* trackingArea;
@end

@interface ZMCustomMenu : NSObject
{
    float               _width;
    NSMutableArray*     _itemArray;
    ZMMenuControlView*  _controlView;
    ZMUILibPopupDlg*    _popupWindow;
}
@property(nonatomic, assign) float                  width;
@property(nonatomic, strong) ZMMenuControlView*     controlView;
@property(nonatomic, strong) ZMUILibPopupDlg*       popupWindow;

- (void)popupMenuForView:(NSView*)view;
- (void)addItem:(id<ZMCustomMenuItem>)item;
- (void)removeItem:(id<ZMCustomMenuItem>)item;
- (float)preferedWidth;
- (float)relayOut;
- (NSInteger)numberOfItems;
- (void)removeAllItems;
@end

//can be used by others

@interface ZMCustomMenuButton : NSButton<ZMCustomMenuItem>
{
    BOOL        _separatorItem;
    BOOL        _isFlippedToRight;//right image
    float       _iconLeftMargin;
    float       _iconWidth;
    float       _iconRightMargin;
    float       _titleRightMargin;
    int         _iconType;
    BOOL        _isDown;
    BOOL        _isSelected;
    NSColor*    _iconColor;
    NSColor*    _titleColor;
    NSColor*    _backgroundColor;
    NSColor*    _selectedColor;
}
@property (nonatomic, readwrite, assign)BOOL        separatorItem;
@property (nonatomic, readwrite, assign)BOOL        isFlippedToRight;
@property (nonatomic, readwrite, assign)float       iconLeftMargin;
@property (nonatomic, readwrite, assign)float       iconWidth;
@property (nonatomic, readwrite, assign)float       iconRightMargin;
@property (nonatomic, readwrite, assign)float       titleRightMargin;
@property (nonatomic, readwrite, assign)int         iconType;
@property (nonatomic, readwrite, assign)BOOL        isDown;
@property (nonatomic, readwrite, assign)BOOL        isSelected;//for pop up dialogue indicator
@property (nonatomic, readwrite, strong)NSColor*    iconColor;
@property (nonatomic, readwrite, strong)NSColor*    titleColor;
@property (nonatomic, readwrite, strong)NSColor*    backgroundColor;
@property (nonatomic, readwrite, strong)NSColor*    selectedColor;
@property (nonatomic, readwrite, strong)NSColor*    selectedTitleColor;
@property (nonatomic, readwrite, strong)NSColor*    selectedIconColor;
- (NSPoint)getTipPointToScreen;
- (float)getTitleStringWidth;
- (NSPoint)getLeftBottomPointToScreen;
- (float)preferedWidth;
@end


