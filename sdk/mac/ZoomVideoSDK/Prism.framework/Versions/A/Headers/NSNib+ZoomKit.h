//
//  NSNib+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/12.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface NSNib (ZoomKit)

+ (void)instantiateNibWithName:(nonnull NSString *)nibName owner:(nonnull id)owner;

@end
