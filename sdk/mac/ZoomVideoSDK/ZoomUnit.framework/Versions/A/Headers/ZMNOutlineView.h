//
//  ZMNOutlineView.h
//  zChatUI
//
//  Created by groot.ding on 2018/9/26.
//  Copyright © 2018 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

typedef NS_ENUM(NSUInteger, ZMNOutlineViewIndentationStyle) {
    ZMNOutlineViewIndentationStyleNSDefault = 0,
    ZMNOutlineViewIndentationStyleCentered,
    ZMNOutlineViewIndentationStyleLeading,
};

@protocol ZMNOutlineViewDelegate <NSOutlineViewDelegate>

@optional;
- (void)outlineView:(NSOutlineView *)outlineView cellView:(NSTableCellView *)cellView clickAtPoint:(CGPoint)point;

- (void)outlineView:(NSOutlineView *)outlineView rightMouseDown:(CGPoint)point;

- (BOOL)outlineView:(NSOutlineView *)outlineView shouldBecomeKeyView:(id)item;

- (NSArray <NSView *> *)outlineViewCanBecomeKeyViews:(NSOutlineView *)outlineView;

- (BOOL)outlineView:(NSOutlineView *)outlineView checkValidateMenuItem:(NSMenuItem *)menuItem;

- (BOOL)outlineView:(NSOutlineView *)outlineView interceptKeyDown:(NSEvent *)event;

- (BOOL)outlineViewInterceptCopyAction:(NSOutlineView *)outlineView;

- (void)outlineViewWillCallCopyAction:(NSOutlineView *)outlineView fromSender:(id)sender;
@end

@interface ZMNOutlineView : NSOutlineView

@property (nonatomic,copy) BOOL (^interceptKeyDownBlock)(NSEvent *);
@property (nonatomic,copy) void (^becomeFirstResponsederBlock)(BOOL);
@property (assign) BOOL ignoreDoubleClick;
@property (assign) BOOL ignoreMouseDownEvent;
@property (assign) BOOL allowMutableSelected;
@property (assign) BOOL mutableSelectOnlyOne;
@property (assign) BOOL ignoreDragStyle;

@property (nonatomic,assign) BOOL needCustomCacheReuseView;
@property (nonatomic, readonly) NSIndexSet *mutableSelectedIndexs;
@property (nonatomic, assign) BOOL escapeTopTimeItemWhenUsingKeyboard;
/** set outlineview accessibility ignored cell classes. There was some problems with the up and down keys before 10.14 */
@property (nonatomic,strong) NSMutableArray<Class> *accessibilityIgnoredClasses;

@property (nonatomic, assign) ZMNOutlineViewIndentationStyle indentationStyle;

- (BOOL)isVisibleWithNode:(NSTreeNode*)node;

- (void)unselectAll;

- (void)mutableSelectedRow:(NSInteger)row;

- (void)copy:(id)sender;

@end
