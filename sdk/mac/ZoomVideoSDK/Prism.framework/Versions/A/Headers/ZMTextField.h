//
//  ZMTextField.h
//  ButtonDeom
//
//  Created by francis zhuo on 2017/12/19.
//  Copyright © 2017 fenfei. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Prism/ZMBaseTextAttachmentCell.h>
#import <Prism/NSBezierPath+ZoomKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMAccessibilityTextFieldCellDelegate <NSObject>
- (BOOL)cellAccessibilityIsIgnored:(__kindof NSTextFieldCell*)buttunCell;
- (NSRect)cellAccessibilityAdjustedFrameInScreenCoordinate:(__kindof NSTextFieldCell*)buttunCell proposedFrame:(NSRect)frame;
@end

@interface ZMTextFieldCell : NSTextFieldCell
@property (weak) IBOutlet id<ZMAccessibilityTextFieldCellDelegate> delegate;
- (void)drawBackgroundWithFrame:(NSRect)cellFrame inview:(NSView*)controlView;
@end

@interface ZMTextField : NSTextField <ZMBaseTextProtocol>
@property(nonatomic,retain,nullable) NSTextView* zmFieldEditor;
@property(nullable, assign) SEL becomeKeyAction;
@property(nullable, assign) SEL keySpaceAction;
@property(assign)IBInspectable ZMRectCornerRadius rectCornerRadius;
@property(assign)IBInspectable ZMPathStyle borderStyle;
@property(assign)IBInspectable BOOL isDrawBorder;
@property(assign)IBInspectable BOOL ignoreUndo;
@property(nullable, retain)IBInspectable NSColor* borderColor;
@property(nullable, retain)IBInspectable NSColor* activeBorderColor;
@property(nullable, retain)IBInspectable NSColor* tintColor;
@property(assign)IBInspectable CGFloat radius;
@property(assign)IBInspectable CGFloat borderWidth;
@property(readwrite, assign)IBInspectable NSEdgeInsets margin;
@property (assign) IBInspectable NSEdgeInsets focusRingMaskMargin;
@property (nonatomic, readwrite, assign)int  maxInputCharNum;
@property(nonatomic,retain,nullable) NSCharacterSet *acceptableInputCharacterSet;
- (void)cleanUp;
- (NSBezierPath*)getBorderPath;
- (void)drawBorder:(NSRect)dirtyRect;
- (void)setPaddingH:(CGFloat)value;
- (void)setPaddingX:(CGFloat)value;
- (void)setPaddingW:(CGFloat)value;
@property (nonatomic,retain) NSColor *placeHolderFloatingLayerColor;
@property (nullable, copy) NSString *placeholderString NS_AVAILABLE_MAC(10_9);
@property (nullable, copy) NSAttributedString *placeholderAttributedString NS_AVAILABLE_MAC(10_9);

@property (assign, nonatomic) IBInspectable BOOL hasFloatingPlaceHolder;//!< default is NO
@property (copy, nonatomic, nullable) IBInspectable NSString *floatingPlaceHolder;//!< If nil, use placeholder or attributted placeholder

- (void)addAttachmentCell:(ZMBaseTextAttachmentCell *)attachmentCell withFrame:(CGRect)frame;

@end

extern const NSNotificationName ZMMoreButtonDidClick;
@interface ZMMoreInfoTextFieldCell : ZMTextFieldCell
@end

@interface ZMMoreInfoTextField : ZMTextField{
    BOOL _isPopUp;
}
@end

@interface ZMFlashNotificationTextField : NSTextField {
    NSTimer*                _elapsedTimer;
    float                   _elapsedSeconds;
    float                   _maxHeight;
}

@property (nonatomic, readwrite, assign) IBInspectable float  maxHeight;
@property (nonatomic, readwrite, assign) float elapsedSeconds;

- (void)flash;
@end


@interface ZMColorSearchField : NSSearchField

@property(nullable, nonatomic, retain) NSColor *tintColor;
@property(nullable, retain)IBInspectable NSColor* borderColor;
@property(nullable, retain)IBInspectable NSColor* activeBorderColor;

@end

NS_ASSUME_NONNULL_END
