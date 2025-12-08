//
//  ZMAlertPanel.h
//  ZCommonUI
//
//  Created by francis zhuo on 2019/9/12.
//  Copyright © 2019 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Prism/Prism.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMAlertPanel : ZMPlainPanel<ZMAlertProtocol>
@property(nonatomic,assign) BOOL constraintWithScreenFrame;//default is YES
- (void)cleanUp;

@property (nullable, retain)NSImage* imageIcon;

@property(retain, nullable)NSString* messageText;
@property(retain)NSAttributedString* attributedMessageText;

@property(nonatomic, strong, readonly)ZMTextLabel* infomationField;
@property(retain, nullable)NSString* infomationText;
@property(retain)NSAttributedString* attributedInfomationText;
@property(assign)BOOL supportHypperLinks;

@property(readonly, strong)NSButton* checkButton;

@property(copy, nullable) ZMAlertAction escBlock;
@property(copy, nullable) ZMAlertAction clickCloseButtonBlock;
/// closeBlock used for all close window action. The default closeWindow in ZMAlertAction is YES;
@property(copy, nullable) ZMAlertAction closeBlock;

@property(strong, nullable)id representedObject;
- (void)resetAlert;
- (void)setMessageFont:(NSFont *)font;
//add button/custom view into button bar
- (NSButton*)addCheckButtonWithTitle:(NSString*)title actionBlock:(nullable ZMAlertAction)blockAction;

- (ZMButton*)addButtonWithTitle:(NSString*)title actionBlock:(ZMAlertAction)blockAction isDefault:(BOOL)isDefaultButton layoutDirection:(ZMLayoutDirection)layoutDirection;
- (ZMButton*)addButtonWithTitle:(NSString*)title actionBlock:(ZMAlertAction)blockAction;
- (ZMButton*)addButtonWithTitle:(NSString*)title actionBlock:(ZMAlertAction)blockAction style:(ZMButtonColorStyle)style needKeyEquivalent:(BOOL)needKeyEquivalent layoutDirection:(ZMLayoutDirection)layoutDirection;

- (ZMButton*)addButtonWithDropdownMenuWithTitle:(NSString*)title dropdownIcon:(nullable NSImage *)dropdownIcon actionBlock:(ZMAlertAction)blockAction style:(ZMButtonColorStyle)style needKeyEquivalent:(BOOL)needKeyEquivalent layoutDirection:(ZMLayoutDirection)layoutDirection menuItems:(NSArray<ZMBaseMenuItem *> *)menuItems;

- (ZMButton*)addButtonWithTitle:(NSString*)title target:(id)target action:(SEL)action isDefault:(BOOL)isDefaultButton layoutDirection:(ZMLayoutDirection)layoutDirection;

- (NSButton*)addCustomButton:(NSButton*)button actionBlock:(nullable ZMAlertAction)blockAction layoutDirection:(ZMLayoutDirection)layoutDirection;

- (PZMButton *)addCustomPZMButton:(PZMButton *)button actionBlock:(nullable ZMAlertAction)blockAction layoutDirection:(ZMLayoutDirection)layoutDirection;

- (void)addVerticalPrimaryButtonWithTitle:(NSString*)title primaryActionBlock:(ZMAlertAction)primaryActionBlock secondaryButtonWithTitle:(NSString*)secondaryTitle secondaryActionBlock:(ZMAlertAction)secondaryActionBlock cancelButtonWithTitle:(NSString*)cancelTitle cancelActionBlock:(ZMAlertAction)cancelActionBlock;

- (NSView*)addCustomView:(NSView*)view layoutDirection:(ZMLayoutDirection)layoutDirection;

//add custom view into content view(under infomation text field)
- (void)setAccessoryAlignment:(NSLayoutAttribute)alignment;
- (ZMCheckButton*)addCheckButtonInAccessoryViewWithTitle:(NSString*)title identifier:(NSString*)identifier;
- (ZMCheckButton*)addCheckButtonInAccessoryViewWithTitle:(NSString*)title
                                              identifier:(NSString*)identifier
                                                  target:(nullable id)target
                                                  action:(nullable SEL)action;
- (void)addAccessoryView:(NSView*)view;
- (void)removeAccessoryView:(NSView*)view;

- (__kindof NSView * _Nullable)viewWithIdentifier:(NSString *_Nullable)identifier;

@end

NS_ASSUME_NONNULL_END
