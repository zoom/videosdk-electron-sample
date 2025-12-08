//
//  ZMContentCollectionViewItem.h
//  ChatUI
//
//  Created by Michael Lin on 2023/6/25.
//  Copyright © 2023 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Prism/ZMContentCollectionSubviewDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMBaseView, ZMTrackingView;
@interface ZMContentCollectionViewItem : NSCollectionViewItem <ZMContentCollectionSubviewDelegate>

- (void)configUI;
- (void)refreshUI;
- (void)updateAccessibilityDescription;
@property (nullable, nonatomic, copy) NSString *zmAccessibilityPosition;
@property (nullable, nonatomic, copy) NSString *zmAccessibilityValue;
@property (nonatomic, setter=setZMSelected:, getter=isZMSelected) BOOL zmSelected;
- (void)setZMSelectedWithSelectableCheck:(BOOL)zmSelected;
@property (setter=setZMHovered:, getter=isZMHovered) BOOL zmHovered;
@property (nonatomic, strong) ZMTrackingView *trackingView;

- (BOOL)supportHoverEffect;
@property (nonatomic, strong, nullable) ZMBaseView *hoverView;

@end

NS_ASSUME_NONNULL_END
