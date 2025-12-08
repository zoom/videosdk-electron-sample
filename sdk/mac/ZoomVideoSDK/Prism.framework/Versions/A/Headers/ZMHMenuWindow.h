//
//  ZMHMenuWindow.h
//  zChatUI
//
//  Created by Huxley Yang on 2018/1/24.
//  Copyright © 2018 Zipow. All rights reserved.
//

#import <Prism/ZMNSRectCorner.h>

@class ZMHMenu, ZMBaseMenuItem, ZMHMenuListView;
@interface ZMHMenuWindow : NSPanel <NSTextFieldDelegate>
{
    BOOL _loaded;
    __weak ZMHMenu *_menu;
}

@property (weak, nonatomic) ZMHMenuWindow *subMenuWindow;
@property (retain) ZMHMenuListView *menuListView;
@property (retain, readonly) ZMBaseMenuItem * representedItem;
@property NSRectCorner preferredAnchorConner;
@property (nonatomic, assign) int cornerRadius;
@property (assign) NSSize maxListSize;
@property (assign) BOOL hasSearchField;
@property (assign) BOOL assignKeyWindow;

@property (assign, readonly) NSSize fittingContentSize;

- (void)constructWithMenu:(ZMHMenu *)menu representedItem:(id)item;
- (void)constructWithMenu:(ZMHMenu *)menu representedItem:(id)item maxSize:(NSSize)maxSize;

- (void)insertMenuItem:(ZMBaseMenuItem *)item atIndex:(NSInteger)index;
- (void)removeMenuItem:(ZMBaseMenuItem *)item atIndex:(NSInteger)index;
- (void)moveMenuItemAtIndex:(NSInteger)index toIndex:(NSInteger)toIndex;
- (BOOL)isDescendantOf:(ZMHMenuWindow *)window;

- (void)show;
- (void)showInScreen:(NSScreen *)screen;
- (void)relayoutInScreen:(NSScreen *)screen;
- (void)showAsChildOf:(NSWindow*)window;
- (void)relayoutAsChildWindow;
- (void)close;

- (BOOL)mouseOnSelfOrDescendantWindows;

- (void)performShowSubWindowWithItem:(ZMBaseMenuItem *)menuItem;
- (void)adjustWindowFrame;
- (void)reloadMenuData;

- (ZMBaseMenuItem *)getSelectedItem;
- (void)selectMenuItem:(__kindof ZMBaseMenuItem *)menuItem;

@end

@interface ZMHMenuSubWindow : ZMHMenuWindow

@end
