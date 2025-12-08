//
//  NSTabViewItem+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/28.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface NSTabViewItem (ZoomKit)

- (BOOL)makeSelectedItemIfAvailable;
@property (readonly, getter=isSelected, nonatomic) BOOL selected;

@end
