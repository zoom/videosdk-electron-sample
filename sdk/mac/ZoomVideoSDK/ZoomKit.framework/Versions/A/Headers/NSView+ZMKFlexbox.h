//
//  NSView+ZMKFlexbox.h
//  ZoomKit
//
//  Created by Cyan.Yang on 2024/6/6.
//

#import <TargetConditionals.h>

#if TARGET_OS_MAC

#import <Cocoa/Cocoa.h>
@class ZMKFlexboxNode;

NS_ASSUME_NONNULL_BEGIN

@interface NSView (ZMKFlexbox)

@property (nonatomic, nullable, readonly) ZMKFlexboxNode *zmk_flexboxNode;
@property (nonatomic, assign, getter=zmk_isFlexboxEnabled, setter=zmk_setFlexboxEnabled:) BOOL zmk_flexboxEnabled;
@property (nonatomic, assign, getter=zmk_managesSubviews, setter=zmk_setManagesSubviews:) BOOL zmk_managesSubviews;
@property (nonatomic, nullable, copy, getter=zmk_customMeasureBlock, setter=zmk_setCustomMeasureBlock:) CGSize (^zmk_customMeasureBlock)(PlatformView view, CGSize proposalSize);

- (void)zmk_configureFlexboxWithBlock:(void (NS_NOESCAPE ^)(ZMKFlexboxNode *node))block;

- (void)zmk_setNeedsUpdateFlexboxManagedLayout;

- (void)zmk_updateFlexboxManagedLayout;

- (CGSize)zmk_flexboxLayoutSizeFittingSize:(CGSize)size;

@end

NS_ASSUME_NONNULL_END

#endif
