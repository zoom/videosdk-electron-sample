//
//  ZMAlertViewController.h
//  ZCommonUI
//
//  Created by francis zhuo on 2019/9/12.
//  Copyright © 2019 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Prism/Prism.h>

@class ZMHMenu, ZMBaseMenuItem;
@protocol ZMHMenuDelegate;

NS_ASSUME_NONNULL_BEGIN

@protocol ZMAlertProtocol;
typedef void (^ZMAlertAction)(id<ZMAlertProtocol> alert, BOOL* closeWindow);

@class ZMCheckButton, ZMButton, PZMButton, PZMView, ZMAlertScrollView, PZMLine;
@protocol ZMAlertProtocol<NSObject>

@property(nullable, strong)NSImage* imageIcon;

@property(nonatomic, strong, readonly)PZMView* titleBar;
@property(nonatomic, strong, readonly)NSTextField* titleField;
@property(retain)NSString* titleText;
@property(retain)NSAttributedString* attributedTitleText;
@property(assign)BOOL showTitleBarLine;

@property(assign)NSEdgeInsets informationContentInsets;
@property(assign)NSColor* informationBackgroundColor;
@property(assign)CGFloat informationCornerRadius;

@property(assign)BOOL supportWrapsMessage;
@property(retain)NSString* messageText;
@property(retain)NSAttributedString* attributedMessageText;

@property(retain)NSString* infomationText;
@property(retain)NSAttributedString* attributedInfomationText;
@property(assign)BOOL supportHyperlinks;

@property(readonly,strong)NSButton* checkButton;

@property(strong, nullable)id representedObject;

@property (nonatomic, copy, nullable) NSEvent *_Nullable(^keyPressHandler)(NSEvent *_Nonnull);

- (void)setMinSize:(NSSize)minSize;
- (void)setMaxSize:(NSSize)maxSize;
- (void)setContentMargin:(NSEdgeInsets)margin;

- (void)resetAlert;
- (void)resetAlertWithAccessoryView; //!remove AccessoryView

//contentView
- (void)setContentStackViewMargin:(NSEdgeInsets)margin;

//add button/custom view into button bar
- (NSButton*)addCheckButtonWithTitle:(NSString*)title actionBlock:(nullable ZMAlertAction)blockAction;

- (ZMButton*)addButtonWithTitle:(NSString*)title actionBlock:(ZMAlertAction)blockAction isDefault:(BOOL)isDefaultButton layoutDirection:(ZMLayoutDirection)layoutDirection;
- (ZMButton*)addButtonWithTitle:(NSString*)title actionBlock:(ZMAlertAction)blockAction;
- (ZMButton*)addButtonWithTitle:(NSString*)title actionBlock:(ZMAlertAction)blockAction style:(ZMButtonColorStyle)style needKeyEquivalent:(BOOL)needKeyEquivalent layoutDirection:(ZMLayoutDirection)layoutDirection;

- (ZMButton*)addButtonWithDropdownMenuWithTitle:(NSString*)title dropdownIcon:(nullable NSImage *)dropdownIcon actionBlock:(ZMAlertAction)blockAction style:(ZMButtonColorStyle)style needKeyEquivalent:(BOOL)needKeyEquivalent layoutDirection:(ZMLayoutDirection)layoutDirection menuItems:(NSArray<ZMHMenuItem *> *)menuItems;

- (ZMButton*)addButtonWithTitle:(NSString*)title target:(id)target action:(SEL)action isDefault:(BOOL)isDefaultButton layoutDirection:(ZMLayoutDirection)layoutDirection;

- (NSButton*)addCustomButton:(NSButton*)button actionBlock:(nullable ZMAlertAction)blockAction layoutDirection:(ZMLayoutDirection)layoutDirection;

- (PZMButton *)addCustomPZMButton:(PZMButton *)button actionBlock:(nullable ZMAlertAction)blockAction layoutDirection:(ZMLayoutDirection)layoutDirection;

- (void)addVerticalPrimaryButtonWithTitle:(NSString*)title primaryActionBlock:(ZMAlertAction)primaryActionBlock secondaryButtonWithTitle:(NSString*)secondaryTitle secondaryActionBlock:(ZMAlertAction)secondaryActionBlock cancelButtonWithTitle:(NSString*)cancelTitle cancelActionBlock:(ZMAlertAction)cancelActionBlock;

- (NSView*)addCustomView:(NSView*)view layoutDirection:(ZMLayoutDirection)layoutDirection;

- (void)setButtonBarSpacing:(CGFloat)spacing layoutDirection:(ZMLayoutDirection)layoutDirection;

//add custom view into content view(under infomation text field)
- (void)setAccessoryMargin:(NSEdgeInsets)margin;
- (void)setAccessorySpacing:(CGFloat)spacing;
- (void)setAccessoryAlignment:(NSLayoutAttribute)alignment;
- (ZMCheckButton*)addCheckButtonInAccessoryViewWithTitle:(NSString*)title identifier:(NSString*)identifier target:(id)target action:(SEL)action;
- (void)addAccessoryView:(NSView*)view;
- (void)removeAccessoryView:(NSView*)view;
- (void)setMessageFont:(NSFont *)font;
- (void)setInfomationFieldDelegate:(id<NSTextViewDelegate>)delegate;
- (__kindof NSView * _Nullable)viewWithIdentifier:(NSString*)identifier;

//accessibility
- (NSString*)accessibilityLabel;
@end

@interface ZMAlertViewController : NSViewController<ZMAlertProtocol, ZMHMenuDelegate>

@property (nonatomic, strong) NSImageView* iconView;
@property (nonatomic, strong) NSTextField* titleField;
@property (nonatomic, strong) NSTextField* messageField;
@property (nonatomic, strong) ZMAlertScrollView* infomationScrollView;
@property (nonatomic, strong) ZMTextLabel* infomationField;
@property (nonatomic, strong) ZMStackView* contentStackView;
@property (nonatomic, strong) ZMStackView* accessoryStackView;
@property (nonatomic, strong) ZMStackView* leftStackView;
@property (nonatomic, strong) ZMStackView* rightStackView;
@property (nonatomic, strong) ZMStackView* bottomStackView;
@property (nonatomic, strong, nullable) NSMutableDictionary* actionBlockMap;
@property (nonatomic, strong, nullable) NSMutableDictionary* dropdownMenuMap;

@property (nonatomic, strong) NSLayoutConstraint* contentViewLeftConstraint;
@property (nonatomic, strong) NSLayoutConstraint* contentViewRightConstraint;

@property (nonatomic, strong, nullable) NSLayoutConstraint* minWidthConstraint;
@property (nonatomic, strong, nullable) NSLayoutConstraint* minHeightConstraint;
@property (nonatomic, strong, nullable) NSLayoutConstraint* maxWidthConstraint;
@property (nonatomic, strong, nullable) NSLayoutConstraint* maxHeightConstraint;

@property (nonatomic, strong) PZMView* titleBar;
@property (nonatomic, strong) PZMLine* titleBarLine;
@property (nonatomic, strong) NSLayoutConstraint* imageViewTopConstraint;
@property (nonatomic, strong) NSLayoutConstraint* contentViewTopConstraint;
@property (nonatomic, strong) NSLayoutConstraint* contentViewBottomConstraint;

@property (nonatomic, assign) NSEdgeInsets contentViewMargin;

@property (nonatomic, assign) BOOL isVerticalLayout;
@property (nonatomic, assign) BOOL verticalLayoutHasSecondaryButton;
@property (nonatomic, strong) NSView *contentView;

- (void)cleanUp;

- (void)onButtonClick:(ZMButton*)sender;

- (void)updateActionBlockMap:(ZMAlertAction)blockAction identifier:(NSString *)identifier;

@end

@interface NSImage(ZMAlert)
+ (NSImage*)zoomIcon;
+ (NSImage*)zoomWarningIcon;
@end

NS_ASSUME_NONNULL_END
