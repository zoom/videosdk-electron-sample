//
//  ZMPopupAlertViewController.h
//  zChatUI
//
//  Created by groot.ding on 2018/9/13.
//  Copyright © 2018 Zoom. All rights reserved.
//

#import <ZoomUnit/NSView+Create.h>

typedef enum : NSUInteger {
    ZMPopupAlertConfirm,
    ZMPopupAlertCancel,
    ZMPopupAlertClose,
    ZMPopupAlertMoreInfo,
    ZMPopupAlertLinkInfo
} ZMPopupAlertIndex;

@interface ZMPopupAlertViewController : ZMBaseViewController

@property (nonatomic,copy) NSString *titleString;

@property (nonatomic,copy) NSString *contentString;

@property (nonatomic,copy) NSString *confirmTitle;

@property (nonatomic,copy) NSString *checkString;

@property (nonatomic,copy) NSAttributedString *contentAttributedString;

@property (nonatomic,copy) NSAttributedString *errorAttributedString;

@property (nonatomic,strong) NSView *customView;

@property (nonatomic,assign) ZMButtonStyle confirmButtonStyle;

@property (nonatomic,assign) CGFloat contentWidth;

@property (nonatomic,assign) BOOL titleUsesSingleLine;
@property (nonatomic,assign) NSLineBreakMode titleLineBreakMode;

@property (nonatomic,assign) BOOL showCancelButton;

@property (nonatomic,assign) BOOL showConfirmButton;

@property (nonatomic,assign) BOOL showCloseButton;

@property (nonatomic,assign) BOOL enableConfirmButton;

@property (nonatomic,copy) void(^actionBlock)(ZMPopupAlertIndex index);

@property (nonatomic,copy) void(^checkBoxActionBlock)(BOOL isChecked);

@property (nonatomic,strong) NSDictionary *userInfo;

//default NO(NSLineBreakByTruncatingTail)
@property (nonatomic,assign) BOOL isTitleBreakByWord;

@property (nonatomic, copy) NSString *cancelTitle;
@property (nonatomic,copy) NSAttributedString *moreInfoTitle;
@property (nonatomic, copy) NSString *linkInfo;

@property (nonatomic,assign) BOOL onlyDarkMode;

@property(nonatomic, assign) CGFloat buttonMaxWidth;

- (BOOL)isChecked;

- (void)dismiss;

- (__kindof NSButton *)buttonAtIndex:(ZMPopupAlertIndex)index;

- (NSTextField *)infoTextField;

- (CGFloat)calculateCustomContentHeight;

- (void)confirm;

- (void)updateConfirmTitle;

- (void)updateContent;

- (void)updateUI;

@end
