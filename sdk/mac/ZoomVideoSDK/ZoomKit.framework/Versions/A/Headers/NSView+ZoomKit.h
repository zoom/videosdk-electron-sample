//
//  NSView+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/11.
//  Copyright © 2018 zoom. All rights reserved.
//
NS_ASSUME_NONNULL_BEGIN

///This file should always use MRC or will crach by hook_previousKeyView
@interface NSView (ZoomKit2)

@property (nonatomic) CGSize  size;
@property (nonatomic) CGFloat width;//by frame
@property (nonatomic) CGFloat height;//by frame

@end
NS_ASSUME_NONNULL_END

