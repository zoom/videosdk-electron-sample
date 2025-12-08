//
//  ZMAccessibleView.h
//  ZCommonUI
//
//  Created by Huxley on 2018/11/3.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMAccessibleView : NSView

@property (assign) IBInspectable BOOL accessibilityVisible;
@property (assign) IBInspectable BOOL accessibilityIgnoreChilds;

@property (assign, nonatomic) IBInspectable BOOL accessibilityGroup;

@property (copy, nullable) IBInspectable NSString *accessibilityLabel;
@property (copy, nullable) IBInspectable NSString *accessibilityRoleDescription;
@property (copy, nullable) IBInspectable NSString *accessibilityHelp;

@end

NS_ASSUME_NONNULL_END
