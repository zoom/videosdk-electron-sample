//
//  ZMMTTipView.h
//  VideoUIBridge
//
//  Created by martin yu on 2023/12/16.
//

#import <Cocoa/Cocoa.h>
#import <Prism/ZMBaseView.h>
#import <Prism/ZMButton.h>
#import <Prism/ZMTextView.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMTipView;
typedef void(^ZMTipActionBlock)(ZMTipView *aTipView, ZMButton *sender);
typedef void(^ZMTipCloseButtonConfigBlock)(ZMTipView *aTipView, ZMButton *aButton);
typedef void(^ZMTipTextViewConfigBlock)(ZMTipView *aTipView, __kindof ZMTextView *aTextView);

@interface ZMTipView : ZMBaseView
@property (nonatomic, assign) NSEdgeInsets edgeInsets;

#pragma mark - Top Area
@property (nonatomic, strong, nullable) NSView *headIconView;
@property (nonatomic, strong, nullable) NSImage *headIcon;
@property (nonatomic, assign) BOOL needIgnoreHeadIconEvent;

@property (nonatomic, strong, nullable) NSString *title;
@property (nonatomic, strong) NSFont *titleFont;
@property (nonatomic, strong) NSColor *titleColor;
@property (nonatomic, strong, nullable) NSAttributedString *attributedTitle;
- (void)setTitleContentCompressionResistancePriority:(NSLayoutPriority)priority forOrientation:(NSLayoutConstraintOrientation)orientation;
@property (nonatomic, assign) BOOL titleSelectable;
@property (nonatomic, assign) BOOL needDrawTitleFocusRingAttribute;


@property (nonatomic, assign) BOOL needCloseButton;
@property (nonatomic, strong, nullable) ZMButton *closeButton;
@property (nonatomic, copy, nullable) ZMTipCloseButtonConfigBlock closeButtonConfigBlock;
@property (nonatomic, copy, nullable) ZMTipActionBlock closeActionBlock;

@property (nonatomic, assign) NSLayoutAttribute headAlignment;

- (void)relayoutCloseButton:(NSEdgeInsets)edgeInsets; // top & right work only

#pragma mark - Center Area
@property (nonatomic, strong, nullable) NSString *desc;
@property (nonatomic, strong) NSColor *descColor;
@property (nonatomic, strong) NSFont *descFont;
@property (nonatomic, strong, nullable) NSAttributedString *attributedDesc;
@property (nonatomic, copy, nullable) ZMTipTextViewConfigBlock descTextViewConfigBlock;
- (void)setDescContentCompressionResistancePriority:(NSLayoutPriority)priority forOrientation:(NSLayoutConstraintOrientation)orientation;

- (void)addAccessoryView:(NSView *)view;

#pragma mark - Bottom Area
- (ZMButton *)addLeftButtonWithTitle:(NSString *)title actionBlock:(ZMTipActionBlock)actionBlock;
- (ZMButton *)addLeftButtonWithTitle:(NSString *)title style:(ZMButtonColorStyle)style actionBlock:(ZMTipActionBlock)actionBlock;
- (ZMButton *)addRightButtonWithTitle:(NSString *)title isDefault:(BOOL)isDefault actionBlock:(ZMTipActionBlock)actionBlock;
- (NSButton *)addCustomButton:(NSButton *)button
                  actionBlock:(ZMTipActionBlock)actionBlock
                  viewGravity:(NSStackViewGravity)viewGravity;
- (NSView *)addCustomView:(NSView *)view viewGravity:(NSStackViewGravity)viewGravity;
#pragma mark - Spacing
@property (nonatomic, assign) CGFloat topAreaInnerSpacing; // Default is 4
@property (nonatomic, assign) CGFloat spacingAfterTitle; // Default is 4
@property (nonatomic, assign) CGFloat spacingAfterDesc; // Default is 10
@property (nonatomic, assign) CGFloat buttonSpacing; // Default is 10
@end

@compatibility_alias ZMMTTipView ZMTipView;

NS_ASSUME_NONNULL_END
