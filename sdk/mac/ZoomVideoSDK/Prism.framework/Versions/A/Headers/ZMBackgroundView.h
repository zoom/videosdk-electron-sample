//
//  ZMBackgroundView.h
//  ZCommonUI
//
//  Created by John on 3/11/14.
//  Copyright (c) 2014 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

enum _bgview_round_corner_type
{
    ROUND_CORNER_NONE,      //not use round corner
    ROUND_CORNER_DEFAULT,   //four corners is round
    ROUND_CORNER_TOPLEFT_TOPRIGHT,
    ROUND_CORNER_BOTTOMLEFT_BOTTOMRIGHT,
    ROUND_CORNER_BOTTOMLEFT,//ZOOM-5960
    ROUND_CORNER_BOTTOMRIGHT,
    ROUND_CORNER_LEFT,
};

enum _bgview_line_position
{
    LINE_POSITION_NONE,
    LINE_POSITION_LEFT,
    LINE_POSITION_RIGHT,
    LINE_POSITION_TOP,
    LINE_POSITION_BOTTOM,
};

@interface ZMBackgroundView : NSView
{
    NSColor*    _boardColor;//ZOOM-5960
    NSColor*    _backgroundColor;
    NSImage*    _backgroundImage;
    int         _cornerType;
    int         _radius;
}
@property(nonatomic, retain) NSColor* boardColor;//ZOOM-5960
@property(nonatomic, retain) IBInspectable NSColor* backgroundColor;
@property(nonatomic, retain) NSImage* backgroundImage;
@property(nonatomic, assign) int cornerType;
@property(nonatomic, assign) int radius;
@end

@interface ZMBackgroundWithLineView : ZMBackgroundView
{
    int _linePosition;
    NSColor* _lineColor;
}
@property(nonatomic, assign) int linePosition;
@property(nonatomic, retain) NSColor* lineColor;
@end
//backgroud view with title in central or left
//ZOOM-5960
@interface ZMBOWarningView : NSView <NSAccessibilityStaticText>//ZOOM-38370
{
    NSString*           _title;
    NSColor*            _titleColor;
    NSFont*             _font;
    NSColor*            _backgroundColor;
    NSColor*            _underLineColor;
    BOOL                _isUpsideDown;
    BOOL                _drawTitleLeftSide;//ZOOM-4998
    BOOL                _disableAccessibility;//ZOOM-34295
    float               _titleLeftSideOffset;
    NSString*           _zmAccessibilityTitle; //ZOOM-38587
    float               _cornerRadius;//ZOOM-86158
    NSColor*            _borderColor;//ZOOM-86158
}
@property (nonatomic, readwrite, retain)NSString*           zmAccessibilityTitle; //ZOOM-38587
@property (nonatomic, readwrite, retain)NSString*           title;
@property (nonatomic, readwrite, retain)NSColor*            titleColor;
@property (nonatomic, readwrite, retain)NSFont*             font;
@property (nonatomic, readwrite, retain)NSColor*            backgroundColor;
@property (nonatomic, readwrite, retain)NSColor*            underLineColor;
@property (nonatomic, readwrite, assign)BOOL                isUpsideDown;
@property (nonatomic, readwrite, assign)BOOL                drawTitleLeftSide;//ZOOM-4998
@property (nonatomic, readwrite, assign)BOOL                disableAccessibility;//ZOOM-34295
@property (nonatomic, readwrite, assign)float               titleLeftSideOffset;//ZOOM-5960
@property (nonatomic, readwrite, retain)NSColor*            borderColor;//ZOOM-86158
@property (nonatomic, readwrite, assign)float               cornerRadius;//ZOOM-86158

- (void)sizeToFit;//limited width
- (int)preferedWidth;//draw title one line
@end

@interface ZMMovingWindowInfoView : ZMBOWarningView
{
    NSPoint     _startPoint;
    NSRect      _startRect;//ZOOM-37939
}
@end
