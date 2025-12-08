//
//  ZMBlockAlert.h
//  ZCommonUI
//
//  Created by Yang on 11/30/16.
//  Copyright © 2016 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, ZMBlockAlertReturnType)
{
    ZMBlockAlertReturnTypeFirst = 1000,
    ZMBlockAlertReturnTypeSecond = 1001,
    ZMBlockAlertReturnTypeThird = 1002
};

typedef void (^ZMBlockAlertCompletionHandler)(ZMBlockAlertReturnType type);

@interface ZMBlockAlert : NSAlert
{
    ZMBlockAlertCompletionHandler _handler;
    NSColor * _textColor;
    BOOL _onlyAccessoryView;
    NSAttributedString * _messageAttributedString;
    NSAttributedString * _informativeAttributedString;
    NSString *_identifier;
}

@property (nonatomic, copy, nullable) NSColor * textColor; //!< For message and informative
@property (nonatomic, copy, nullable) NSAttributedString * messageAttributedString;
@property (nonatomic, copy, nullable) NSAttributedString * informativeAttributedString; //!< Be sure messageAttributedString is not nil if need set this value!

@property (assign) BOOL onlyAccessoryView;
@property (copy, nullable) NSString *identifier;
@property (readonly, getter=isShowing) BOOL showing;

+ (instancetype)alertWithFirstButton:(NSString *)title1 secondButton:(nullable NSString *)title2 thirdButton:(nullable NSString *)title3;

- (void)showSheetModalForWindow:(nullable NSWindow *)sheetWindow completionHandler:(nullable ZMBlockAlertCompletionHandler)handler;

- (void)makePrimaryButtonAtIndex:(NSUInteger)index; //!< Right to left

@end

@interface ZMBlockAlert (ZMConvenience)

+ (instancetype)alertWithType:(NSInteger)type; //!< Not implemented

@end

@interface ZMBlockAlert (Lifetime)

+ (void)forceCloseAllAlerts;

- (void)forceClose;//!< close without invoke completionHandler

+ (nullable instancetype)fetchAlertWithIdentifier:(NSString *)identifer;

@end

@interface NSDictionary (NSAttributedStringZMConvenience)

+ (instancetype)attributesWithColor:(NSColor *)color fontSize:(CGFloat)fontSize center:(BOOL)center;

@end

NS_ASSUME_NONNULL_END
