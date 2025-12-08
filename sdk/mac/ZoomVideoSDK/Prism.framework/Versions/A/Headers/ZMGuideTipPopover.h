//
//  ZMGuideTipPopover.h
//  ZoomKit
//
//  Created by Kris Smith on 10/1/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMGuideTipPopover : NSObject

- (void)showPopOverInView:(NSView *)view rectEdge:(NSRectEdge)rectEdge;
- (void)showPopOverInView:(NSView *)view rectEdge:(NSRectEdge)rectEdge offset:(NSInteger)offset;
- (void)updatePopover:(NSView *)positioningView preferredEdge:(NSRectEdge)preferredEdge;
- (void)closePopover;
- (BOOL)isPopoverVisible;

@end

NS_ASSUME_NONNULL_END
