//
//  ZMStepProgressIndicator.h
//  ChatUI
//
//  Created by fistice on 2023-04-19.
//  Copyright © 2023 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMStepProgressIndicator : NSView

/*
 max = 3
 now 0: Ooo
 now 1: √Oo
 now 2: √√O
 now 3: √√√
 */
@property (nonatomic, assign,getter=isVertical) BOOL vertical;

@property (nonatomic, assign) NSInteger intValue;//!< [0,max], default 0
@property (nonatomic, assign) NSInteger maxValue;
@property (nonatomic, copy, nullable) NSString *label;

- (NSSize)intrinsicContentSize;
- (void)sizeToFit;
@end

NS_ASSUME_NONNULL_END
