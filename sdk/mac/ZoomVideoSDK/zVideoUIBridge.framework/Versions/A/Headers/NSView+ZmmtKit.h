//
//  NSView+zmmtKit.h
//  zVideoUI
//
//  Created by francis zhuo on 5/23/20.
//  Copyright © 2020 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSView (ZmmtKit)

@property(nullable, retain) id mtObject;

- (void)zmWindowDidResize;
- (void)zmWindowWillChangeFullScreen:(BOOL)toFullScreen;
- (void)zmWindowDidChangedFullScreen:(BOOL)toFullScreen;
- (void)zmWindowTitlebarVisibleDidChanged:(BOOL)visible;
- (NSArray<id<NSAccessibilityElement>> *)zm_accessibilityChildrenInNavigationOrder NS_AVAILABLE_MAC(10_13);

- (void)setMinSizeConstraint:(NSSize)minSize;

- (NSComparisonResult)navigationCompareView:(NSView *)view1 view2:(NSView *)view2 flipped:(BOOL)flipped;
@end

@interface NSView (ZMMTSafeVideoArea)
@property NSEdgeInsets additionalSafeVideoAreaInsets;
@property (readonly) NSLayoutGuide* safeVideoAreaGuide;
@property (readonly) NSRect safeVideoAreaRect;
@property (assign) BOOL layoutWhenSafeVideoAreaChanged;
@end
NS_ASSUME_NONNULL_END
