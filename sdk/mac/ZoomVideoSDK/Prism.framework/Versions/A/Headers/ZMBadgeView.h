//
//  ZMBadgeView.h
//  ZCommonUI
//
//  Created by John on 6/17/14.
//  Copyright (c) 2014 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

enum _badgeShape
{
    Badge_Shape_Rect,
    Badge_Shape_Circle,
    Badge_Shape_RoundRect,
};
enum _badgeDrawType{
    Badge_DrawType_String,
    Badge_DrawType_AttributeString,
    Badge_DrawType_Image
};
@interface ZMBadgeView : NSControl
{
    NSColor* _backgroudColor;
    NSColor* _borderColor;
    int _borderWidth;
    int _shape;
    BOOL _hasBorder;
    
    NSImage* _badgeImage;
    NSAttributedString* _attributeString;
    int _drawType;
}
@property(nonatomic, retain) NSColor* backgroundColor;
@property(nonatomic, retain) NSColor* borderColor;
@property(nonatomic, assign) int borderWidth;
@property(nonatomic, assign) int shape;
@property(nonatomic, assign) BOOL hasBorder;
@property(nonatomic, retain) NSImage* badgeImage;
@property(nonatomic, copy)   NSAttributedString* attributeString;
@property(nonatomic, assign) int drawType;

- (void)setBadgeString:(NSString*)inString;
- (void)setStringFont:(NSFont*)inFont;
- (void)setStringColor:(NSColor*)inColor;
- (void)updateUI;
@end
