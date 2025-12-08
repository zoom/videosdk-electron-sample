//
//  ZMHMenu.h
//  zChatUI
//
//  Created by Huxley Yang on 19/01/2018.
//  Copyright © 2018 Zipow. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Prism/ZMNSRectCorner.h>
#import <Prism/ZMObjectDispose.h>

NS_ASSUME_NONNULL_BEGIN

#define ZM_Meeting_Popup_Menu @"ZoomMeetingPopupMenu"

@class ZMHMenu, ZMMenuConfig, ZMHMenuWindow, ZMBaseMenuItem;
@protocol ZMHMenuDelegate <NSObject>

@optional
- (void)menu:(ZMHMenu *)menu clickedItem:(ZMBaseMenuItem *)item;//!<ZMHMenuItem which has custom view property will not trigger this method
- (void)menuWillShow:(ZMHMenu *)menu;
- (void)menuWillClose:(ZMHMenu *)menu;
- (void)menuDidClosed:(ZMHMenu *)menu;
- (void)menu:(ZMHMenu *)menu willShowSubWindowWithItem:(ZMBaseMenuItem *)item;//ZOOM-43362
- (void)menu:(ZMHMenu *)menu didShowSubWindowWithItem:(ZMBaseMenuItem *)item;
- (void)menu:(ZMHMenu *)menu didCloseSubWindowWithItem:(ZMBaseMenuItem *)item; //ZOOM-507601
- (BOOL)menuShouldCloseWithEvent:(NSEvent*)event;
- (BOOL)menuShouldAcceptMouseMove:(ZMHMenu *)menu;
- (void)menu:(ZMHMenu *)menu viewDidCreatedWithMenuItem:(ZMBaseMenuItem *)item;
@end

@interface ZMHMenu : NSObject <ZMObjectDispose> //Tree Menu

@property (weak, nullable) id <ZMHMenuDelegate> delegate;

@property (nonatomic, retain,nullable) ZMMenuConfig *config;

@property (copy, nonatomic, nullable) NSArray <__kindof ZMBaseMenuItem *> *items;

@property (nonatomic, readonly, retain,nullable) NSScreen* screen;
@property (nonatomic, retain,nullable) ZMHMenuWindow *rootWindow;

@property (nonatomic, retain,nullable) NSString *windowTitle;

@property (nonatomic, retain) NSColor *backgroundColor; //default is White
@property (nonatomic, assign) NSSize maxSize;
@property (nonatomic, assign) NSEdgeInsets edgePaddings;

@property (nonatomic, assign) int cornerRadius;

@property (nonatomic, assign) BOOL onlyDarkMode;
@property (nonatomic, assign) BOOL autoCloseWhenMouseExist;
@property (nonatomic, assign) BOOL costMouseEventWhenClose;//!< 'event == nil', Default is YES. (Deprecated)
/// This property is added for dealing with the scenario that no menu window or child-window is active or is keyWindow but don't want to close the menu when resignKeyWindow happens.
@property (nonatomic, assign) BOOL ignoreResignKeyWindow; //ZOOM-257029
@property (nonatomic, assign) BOOL enableSearch;
@property (nonatomic, assign) BOOL assignKeyWindow;
@property (readonly) BOOL shown;
/// If YES, the menu will automatically close on focus lost, clicking outside the menu, etc.
/// If NO, the menu will only close when an item is clicked OR when [close] is called by code outsie the menu.
/// @note Defaults to YES
@property (nonatomic, assign) BOOL allowInteractiveClose;

@property (assign) int tag;
@property (nullable,retain) id representedObject;
@property (copy,nullable) NSDictionary *shadowParameters;

@property (nonatomic, assign) NSWindowStyleMask windowStyleMask;

+ (Class)menuWindowClass;
+ (Class)menuSubWindowClass;

- (NSView *)generateContentView;

//use the view's absolute position
- (void)popupAtFixedPosition:(NSPoint)position inView:(nullable NSView *)view anchorCorner:(NSRectCorner)corner;

//auto convert position to the view's RTL position
- (void)popupAtPosition:(NSPoint)position inView:(nullable NSView *)view anchorCorner:(NSRectCorner)corner;
- (void)popupAtPosition:(NSPoint)position inView:(nullable NSView *)view anchorCorner:(NSRectCorner)corner asChildWindow:(BOOL)isChild;
- (void)popupAtPosition:(NSPoint)position inView:(nullable NSView *)view anchorCorner:(NSRectCorner)corner asChildWindow:(BOOL)isChild isFixedPos:(BOOL)isFixedPos;

- (void)relayoutAtPosition:(NSPoint)position inView:(nullable NSView *)view anchorCorner:(NSRectCorner)corner;

- (void)reloadMenuDataSource;
- (void)reloadMenuDataSourceRecursively;

/// rootWindow only
- (__kindof ZMBaseMenuItem *)getSelectedItem;
- (void)selectMenuItem:(__kindof ZMBaseMenuItem *)menuItem;

- (void)close;
- (void)closeSubMenuWindow;
- (void)cleanUp;

- (BOOL)isShowing;
- (BOOL)isMouseOnMenu;

- (void)showSubMenuWithItem:(ZMBaseMenuItem *)item;
- (void)menuKeyMayChanged;

- (void)selectPreviousItem:(nullable id)sender;
- (void)selectNextItem:(nullable id)sender;

- (BOOL)isMyMenuWindow:(__kindof NSWindow *)window;

- (void)insertMenuItem:(ZMBaseMenuItem *)item atIndex:(NSInteger)index;
- (void)removeMenuItem:(ZMBaseMenuItem *)item atIndex:(NSInteger)index;
- (void)moveMenuItemAtIndex:(NSInteger)index toIndex:(NSInteger)toIndex;
@end

NS_ASSUME_NONNULL_END
