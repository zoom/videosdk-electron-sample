//
//  ZMNSRectCorner.h
//  ZoomKit
//
//  Created by Cooper.Chen on 2025/7/2.
//

#ifndef ZMNSRectCorner_h
#define ZMNSRectCorner_h

//MARK: - Geometry
typedef NS_OPTIONS(NSUInteger, NSRectCorner) {
    NSRectCornerNotSpecified = 0,
    NSRectCornerTopLeft = 1 << 0,
    NSRectCornerTopRight = 1 << 1,
    NSRectCornerBottomRight = 1 << 2,
    NSRectCornerBottomLeft = 1 << 3,
    NSRectCornerNone = 1 << 4, // No corners is a unique value (instead of 0) for backwards compatibility with other ZM code
    
    NSRectCornerTop = NSRectCornerTopLeft|NSRectCornerTopRight,
    NSRectCornerBottom = NSRectCornerBottomRight|NSRectCornerBottomLeft,
    NSRectCornerLeft = NSRectCornerTopLeft|NSRectCornerBottomLeft,
    NSRectCornerRight = NSRectCornerTopRight|NSRectCornerBottomRight,
    NSRectCornerAll = NSRectCornerTop|NSRectCornerBottom,
};
APPKIT_EXTERN NSRectCorner NSFlippedRectCorner(NSRectCorner corner);
APPKIT_EXTERN CACornerMask NSRectCornerToCACornerMask(NSRectCorner corners);

APPKIT_EXTERN NSRect NSAutoRectInRect(NSRect aRect, NSRect bRect);
APPKIT_EXTERN NSRectCorner NSAutoRectCorner(NSRectCorner corner);

#endif /* ZMNSRectCorner_h */
