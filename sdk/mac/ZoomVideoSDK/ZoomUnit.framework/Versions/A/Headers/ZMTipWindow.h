//
//  ZMTipWindow.h
//  ZMTipWindow
//
//  Created by zoom on 13-7-20.
//  Copyright (c) 2013 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

typedef enum {
    ZMFixedNone = 0,
    ZMFixedWidth,
    ZMFixedHeight
}ZMFixedType;
typedef enum _ZMTipWindowPosition
{
    ZMPositionLeft          = NSMinXEdge, // 0
    ZMPositionRight         = NSMaxXEdge, // 2
    ZMPositionTop           = NSMaxYEdge, // 3
    ZMPositionBottom        = NSMinYEdge, // 1
    ZMPositionLeftTop       = 4,
    ZMPositionLeftBottom    = 5,
    ZMPositionRightTop      = 6,
    ZMPositionRightBottom   = 7,
    ZMPositionTopLeft       = 8,
    ZMPositionTopRight      = 9,
    ZMPositionBottomLeft    = 10,
    ZMPositionBottomRight   = 11,
    ZMPositionAutomatic     = 12
}ZMTipWindowPosition;


APPKIT_EXTERN NSString* const kZoomShouldCloseTipWindowNotification;
@interface ZMAutoSizeTipView : NSControl
{
    NSString*               _content;
    NSAttributedString*     _attributeContent;
    
    NSRect                  _viewFrame;
    NSPoint                 _arrowPoint;
    NSTextView*             _contentTextView;
    NSBezierPath*           _viewShape;
}
@property(nonatomic, copy)NSString* content;
@property(nonatomic, copy)NSAttributedString* attributeContent;
@property(nonatomic, assign)NSPoint arrowPoind;
@property(nonatomic,readwrite,retain)NSTextView* contentTextView;
@property(nonatomic,readwrite,retain)NSBezierPath* viewShape;
- (id) initWithContent:(NSString*)content;
- (id) init;

- (NSDictionary*)attribute;
- (BOOL)isSpecialAttrStr;
- (ZMFixedType)fixedType;
- (CGFloat)fixedLength;
- (NSColor*)backgroundColor;
- (float)viewMargin;
- (NSColor*)borderColor;
- (float)borderWidth;
- (float)arrowBaseWidth;
- (float)arrowHeight;
- (BOOL)hasArrow;
- (float)cornerRadius;
- (BOOL)drawsRoundCornerBesizeArrow;
- (float)arrowMargin;
- (ZMTipWindowPosition)side;

- (void) reLayout;
- (void) cleanUp;
@end

@interface ZMTipWindow : NSWindow
{
    NSColor* _borderColor;
    float _borderWidth;
    float _viewMargin;
    float _arrowBaseWidth;
    float _arrowHeight;
    BOOL _hasArrow;
    float _cornerRadius;
    BOOL _drawsRoundCornerBesizeArrow;
    float _arrowMargin;
    
    NSView* _view;
    NSPoint _point;
    ZMTipWindowPosition _side;
    float _distance;
    NSRect _viewFrame;
    BOOL _resizing;
    
    //ZMTipWindow(String)
    NSString*       _content;
    NSDictionary*   _attribute;
    ZMFixedType     _fixedType;
    CGFloat         _fixedLength;
    NSColor*        _viewBackgroundColor;
    BOOL            _isSpecialAttributeString;
    BOOL            _isCloseBtnClicked;
    
    NSInteger       _tag;
}
@property(nonatomic, retain)NSColor* borderColor;
@property(nonatomic, assign)float borderWidth;
@property(nonatomic, assign)float viewMargin;
@property(nonatomic, assign)float arrowBaseWidth;
@property(nonatomic, assign)float arrowHeight;
@property(nonatomic, assign)BOOL hasArrow;
@property(nonatomic, assign)float cornerRadius;
@property(nonatomic, assign)BOOL drawsRoundCornerBesizeArrow;
@property(nonatomic, assign)float arrowMargin;
@property(nonatomic, retain)NSView* view;
@property(nonatomic, assign)ZMTipWindowPosition side;
@property(nonatomic, retain)NSDictionary* attribute;
@property(nonatomic, assign)ZMFixedType fixedType;
@property(nonatomic, assign)CGFloat     fixedLength;
@property(nonatomic, retain)NSColor* viewBackgroundColor;
@property(nonatomic, readonly, assign)BOOL isSpecialAttributeString;
@property(nonatomic, readonly, assign)BOOL isCloseBtnClicked;
@property(nonatomic,readwrite, assign)NSInteger tag;
- (ZMTipWindow *)initWithView:(NSView *)view
              attachedToPoint:(NSPoint)point
                     inWindow:(NSWindow *)window
                       onSide:(ZMTipWindowPosition)side
                   atDistance:(float)distance;
- (ZMTipWindow *)initWithView:(NSView *)view
              attachedToPoint:(NSPoint)point
                     inWindow:(NSWindow *)window
                   atDistance:(float)distance;
- (ZMTipWindow *)initWithView:(NSView *)view
              attachedToPoint:(NSPoint)point
                       onSide:(ZMTipWindowPosition)side
                   atDistance:(float)distance;
- (ZMTipWindow *)initWithView:(NSView *)view
              attachedToPoint:(NSPoint)point
                   atDistance:(float)distance;
- (ZMTipWindow *)initWithView:(NSView *)view
              attachedToPoint:(NSPoint)point
                     inWindow:(NSWindow *)window;
- (ZMTipWindow *)initWithView:(NSView *)view
              attachedToPoint:(NSPoint)point
                       onSide:(ZMTipWindowPosition)side;
- (ZMTipWindow *)initWithView:(NSView *)view
              attachedToPoint:(NSPoint)point;

- (void)cleanUp;
- (void)setPoint:(NSPoint)point side:(ZMTipWindowPosition)side;
- (void)setBackgroundImage:(NSImage *)value;

- (void)reDisplay;
- (void)addCloseBtn;
- (void)invisibleInSharing;
- (BOOL)canOrderFrontByShortcuts;
@end

@interface ZMTipWindow(String)
- (id) initWithString:(NSString*) string attachedToPoint:(NSPoint)point inWindow:(NSWindow *)window onSide:(ZMTipWindowPosition)side atDistance:(float)distance
            fixedType:(ZMFixedType)type
          fixedLength:(CGFloat) length;
- (id) initWithString:(NSString*) string attachedToPoint:(NSPoint)point inWindow:(NSWindow *)window onSide:(ZMTipWindowPosition)side atDistance:(float)distance;
- (id) initWithString:(NSString *)string attachedToPoint:(NSPoint)point onSide:(ZMTipWindowPosition)side;
- (id) initWithPoint:(NSPoint)point onSize:(ZMTipWindowPosition)side;
- (id) initWithPoint:(NSPoint)point;

- (void)setContent:(NSString *)content;
- (void)setAttributeContent:(NSAttributedString*) attributeContent;
- (void)reLayout;
@end

@interface ZMUILibPopUpBackgroundView : NSView
{
    NSColor*                    _borderColor;
    NSColor*                    _backgroundColor;
    NSView*                     _contentBox;
}
@property (nonatomic, readwrite, retain)NSColor*                    borderColor;
@property (nonatomic, readwrite, retain)NSColor*                    backgroundColor;
@property (nonatomic, readwrite, retain)NSView*                     contentBox;
- (void)addSubviewBelowBorder:(NSView *)aView;
@end

@interface ZMUILibPopupDlg : NSPanel <NSWindowDelegate>
{
    ZMUILibPopUpBackgroundView*     _backgroundView;
}
@property (nonatomic, readwrite, retain)ZMUILibPopUpBackgroundView*     backgroundView;
@property (nonatomic, readwrite, weak)NSWindow*                       nextKeyWindow;
- (void)invisibleInSharing;
- (id)initWithFrame:(NSRect)rect;
@end

//ZOOM-5960
@interface ZMBOPopUpBackgroundView : NSView
{
    NSPoint         _arrowPoint;
    NSColor*        _borderColor;
    NSColor*        _backgroundColor;
    float           _arrowHeight;
    float           _arrowWidth;
    NSView*                 _contentBox;
}
@property (nonatomic, readwrite, assign)NSPoint     arrowPoint;
@property (nonatomic, readwrite, retain)NSColor*    borderColor;
@property (nonatomic, readwrite, retain)NSColor*    backgroundColor;
@property (nonatomic, readwrite, assign)float       arrowHeight;
@property (nonatomic, readwrite, assign)float       arrowWidth;
@property (nonatomic, readwrite, retain)NSView*                 contentBox;
- (void)addSubviewBelowBorder:(NSView *)aView;
@end

@interface ZMBOPopupDlg : NSPanel
{
    ZMBOPopUpBackgroundView*    _backgroundView;
}
@property (nonatomic, readwrite, retain)ZMBOPopUpBackgroundView*    backgroundView;
- (void)invisibleInSharing;
- (id)initWithFrame:(NSRect)rect;
@end

