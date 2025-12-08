//
//  ZMLoginPasswordTextFieldView.h
//  zLoginUI
//
//  Created by Davies Zhao on 2025/6/6.
//

#import <ZoomKit/ZoomKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMSecureInputView : ZMBaseView

@property (nonatomic, copy) NSString *placeholderString;
@property (nonatomic, strong) NSFont *font;
@property (nonatomic, assign) CGFloat textFieldBorderWidth;
@property (nonatomic, strong) NSColor *textFieldBorderColor;
@property (nonatomic, strong) NSColor *textFieldActiveBorderColor;
@property (nonatomic, assign) NSInteger maxInputCharNum;
@property (nonatomic, copy) NSString* (^eyeBallButtonAccessibilityDescriptionBlock)(__kindof ZPTrackingButton* mySelf);

@property (nonatomic, assign) BOOL stringVisible;
@property (nonatomic, copy, nullable) NSString *stringValue;
@property (nonatomic, copy) void (^controlTextDidChange)(NSString *_Nullable password);
@property (nonatomic, copy) void (^onEyeButtonClicked)(BOOL selected);

- (void)makeFirstResponder;
@end

NS_ASSUME_NONNULL_END
