//
//  ZMSecureTextField.h
//  ButtonDeom
//
//  Created by francis zhuo on 2018/1/25.
//  Copyright © 2018 fenfei. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@protocol ZMAccessibilitySecureTextFieldCellDelegate <NSObject>
- (BOOL)cellAccessibilityIsIgnored:(__kindof NSSecureTextFieldCell*)buttunCell;
- (NSRect)cellAccessibilityAdjustedFrameInScreenCoordinate:(__kindof NSSecureTextFieldCell*)buttunCell proposedFrame:(NSRect)frame;
@end
@interface ZMSecureTextFieldCell : NSSecureTextFieldCell
@property (weak) IBOutlet id<ZMAccessibilitySecureTextFieldCellDelegate> delegate;
- (void)drawBackgroundWithFrame:(NSRect)cellFrame inview:(NSView*)controlView;
@end

@interface ZMSecureTextField : NSSecureTextField
{
    ZMPathStyle _borderStyle;
    CGFloat     _radius;
    
    BOOL        _isDrawBorder;
    NSColor*    _borderColor;
    NSColor*    _activeBorderColor;
    CGFloat     _borderWidth;
    
    CGFloat     _paddingH;  //Horizontal padding
    CGFloat     _paddingX;
    NSColor*    _tintColor; //the cursor color
}
@property(assign)IBInspectable ZMPathStyle borderStyle;
@property(assign)IBInspectable BOOL isDrawBorder;
@property(strong)IBInspectable NSColor* borderColor;
@property(strong)IBInspectable NSColor* activeBorderColor;
@property(assign)IBInspectable CGFloat radius;
@property(assign)IBInspectable CGFloat borderWidth;
@property(assign)IBInspectable CGFloat paddingH;
@property(strong)IBInspectable NSColor* tintColor;
@property(assign)IBInspectable CGFloat paddingX;
@property(assign)IBInspectable CGFloat rightMargin;

- (void)cleanUp;
- (NSBezierPath*)getBorderPath;
- (void)drawBorder:(NSRect)dirtyRect;

@property (nonatomic, strong) NSColor *placeHolderFloatingLayerColor;
@property (assign, nonatomic) IBInspectable BOOL hasFloatingPlaceHolder;//!< default is NO
@property (copy, nonatomic) IBInspectable NSString *floatingPlaceHolder;//!< If nil, use placeholder or attributted placeholder
@property (nonatomic, assign)NSInteger  maxInputCharNum;

@end

