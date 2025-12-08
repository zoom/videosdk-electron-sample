//
//  NSCell+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/12.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <AppKit/AppKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@interface NSCell (ZoomKit)

@property (readonly, nonatomic) NSParagraphStyle * effectiveParagraphStyle;

@property (nonatomic, retain) id zm_userInfo;
@property (nonatomic,assign) BOOL theAccessibilityIgnored;

@end
NS_ASSUME_NONNULL_END
