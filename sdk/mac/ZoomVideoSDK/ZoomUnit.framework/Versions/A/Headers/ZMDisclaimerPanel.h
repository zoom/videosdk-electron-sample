//
//  ZMDisclaimerPanel.h
//  ZCommonUI
//
//  Created by javenlee on 2020/3/4.
//  Copyright © 2020 zoom. All rights reserved.
//


typedef  NS_ENUM(NSInteger, ZMDisclaimerButtonTag) {
    ZMDisclaimer_Agree = 0,
    ZMDisclaimer_Cancel,// "esc" key
    ZMDisclaimer_OpenLink,
};

typedef NS_ENUM(NSInteger, ZMDisclaimerShowAlertType) {
    ZMDisclaimerNormal,
    ZMDisclaimerPopup,
    ZMDisclaimerSheet,
};

NS_ASSUME_NONNULL_BEGIN

typedef void (^ZMDisclaimerCompletionHandler)(ZMDisclaimerButtonTag tag);

@interface ZMDisclaimerPanel : ZMPlainPanel

@property (nonatomic, assign, readonly) ZMDisclaimerShowAlertType alertType;
@property (readonly, getter=isShowing) BOOL showing;
@property (nonatomic, copy) ZMDisclaimerCompletionHandler handler;
@property (nonatomic, copy) dispatch_block_t relayoutCompleteBlock;

- (void)resetAlert;
- (void)setDisclaimerTitle:(NSString*)inTitle;
- (void)setDisclaimerContent:(NSString*)inString;
- (void)setInfoContent:(NSString *)info;
- (void)setLinkInfo:(NSString *)info;
- (void)addButtonWithTitle:(NSString*)inTitle tag:(ZMDisclaimerButtonTag)tag isDefaultButton:(BOOL)inbDefault;
- (void)relayout;
- (void)showDisclaimer;
- (void)showWindowWithCompletionHandler:(nullable ZMDisclaimerCompletionHandler)handler;
- (void)showPopupModalForWindow:(nullable NSWindow *)attachWindow completionHandler:(nullable ZMDisclaimerCompletionHandler)handler;
- (void)showSheetModalForWindow:(nullable NSWindow *)sheetWindow completionHandler:(nullable ZMDisclaimerCompletionHandler)handler;

@end

NS_ASSUME_NONNULL_END
