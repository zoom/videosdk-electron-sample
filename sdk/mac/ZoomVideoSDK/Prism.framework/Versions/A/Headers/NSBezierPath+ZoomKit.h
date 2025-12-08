//
//  NSBezierPath+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/12.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Prism/ZMNSRectCorner.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

APPKIT_EXTERN CGPathRef __nullable CGPathCreateWithCornerSpecificallyRoundedRect(CGRect rect, NSRectCorner corners, CGSize cornerRadii);

typedef struct _ZMRectCornerRadius {
    CGFloat topLeft;
    CGFloat topRight;
    CGFloat bottomLeft;
    CGFloat bottomRight;
} ZMRectCornerRadius;

FOUNDATION_EXPORT BOOL ZMIsEmptyRectCornerRadius(ZMRectCornerRadius aRect);

NS_INLINE ZMRectCornerRadius ZMMakeRectCornerRadius(CGFloat topLeft, CGFloat topRight,CGFloat bottomLeft,CGFloat bottomRight) {
    ZMRectCornerRadius r;
    r.topLeft = topLeft;
    r.topRight = topRight;
    r.bottomLeft = bottomLeft;
    r.bottomRight = bottomRight;
    return r;
}

@interface NSBezierPath (ZoomKit)

+ (nullable NSBezierPath *)bezierPathWithCornerSpecificallyRoundedRect:(NSRect)rect corners:(NSRectCorner)corners cornerRadii:(CGSize)cornerRadii;


- (nullable CGPathRef)CGPathWithClose:(BOOL)close;


+ (NSBezierPath *)bezierPathWithBubbleInRect:(NSRect)rect arrowRect:(NSRect)arrowRect edge:(NSRectEdge)edge radius:(CGFloat)aRadius arrowRadius:(CGFloat)arrowRadius;
@end

typedef NS_ENUM(NSInteger,ZMPathStyle){
    ZMPathStyleRect,
    ZMPathStyleCircleRect,
    ZMPathStyleRoundRect,
    ZMPathStyleRoundRect_Right,
    ZMPathStyleRoundRect_Left,
    ZMPathStyleRoundRect_Top,
    ZMPathStyleRoundRect_TopRight,
    ZMPathStyleRoundRect_Bottom,
    ZMPathStyleRoundRect_BottomRight,
    
};

@interface NSBezierPath (ZMConvenience)
+ (NSBezierPath*)getBezierPath:(NSRect)bounds style:(ZMPathStyle)style radius:(CGFloat)radius;
+ (NSBezierPath*)getBezierPath:(NSRect)bounds style:(ZMPathStyle)style radius:(CGFloat)radius isFlipped:(BOOL)isFlipped;
+ (NSBezierPath*)getBezierPath:(NSRect)bounds style:(ZMPathStyle)style radius:(CGFloat)radius width:(CGFloat)width;
+ (NSBezierPath*)getBezierPath:(NSRect)bounds style:(ZMPathStyle)style radius:(CGFloat)radius width:(CGFloat)width isFlipped:(BOOL)isFlipped;
+ (NSBezierPath*)getBezierPath4Rect:(NSRect)bounds width:(CGFloat)width;
+ (NSBezierPath*)getBezierPath4CircleRect:(NSRect)bounds width:(CGFloat)width;
+ (NSBezierPath*)getBezierPath:(NSRect)bounds width:(CGFloat)width rectRadius:(ZMRectCornerRadius)rectRadius isFlipped:(BOOL)isFlipped;

+ (NSBezierPath*)controlsBorder:(NSRect)bounds style:(ZMPathStyle)style radius:(CGFloat)radius width:(CGFloat)width isFlipped:(BOOL)isFlipped;
+ (NSBezierPath*)focusRingPath:(NSRect)bounds style:(ZMPathStyle)style radius:(CGFloat)radius isFlipped:(BOOL)isFlipped;
@end

NS_ASSUME_NONNULL_END
