//
//  NSImageView+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/7/5.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface NSImageView (ZoomKit)

@property (assign, nonatomic) IBInspectable NSString *imageName;

+ (instancetype)zm_imageViewWithImage:(NSImage *)image;

@end
