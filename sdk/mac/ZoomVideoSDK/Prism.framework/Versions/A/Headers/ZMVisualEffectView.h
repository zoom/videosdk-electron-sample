//
//  ZMVisualEffectView.h
//  ZCommonUI
//
//  Created by Geno on 2020/3/2.
//  Copyright © 2020 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Prism/ZMNSRectCorner.h>
NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(macos(10.13))
@interface ZMVisualEffectView : NSVisualEffectView

@property (nonatomic, strong, nullable) NSColor *backgroundColor;

/** When the blendingMode = NSVisualEffectBlendingModeBehindWindow and cornerRadius > 0, rounded corners will appear not smooth. Set this property to YES to fix this problem. And the ZMVisualEffectView must be seted as the window's contentView */
@property (nonatomic, assign) BOOL fixRoundedCorners;
@property (nonatomic, assign) CGFloat cornerRadius;
@property(nonatomic, assign) NSRectCorner cornerType;


@end

NS_ASSUME_NONNULL_END
