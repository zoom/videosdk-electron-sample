//
//  NSShadow+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/6/26.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface NSShadow (ZoomKit)

// Commented out - migrated to Swift in NSShadow+Prism.swift
+ (instancetype)shadowWithColor:(NSColor *)color offset:(NSSize)offset blurRadius:(CGFloat)blurRadius;

@end
