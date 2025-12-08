//
//  ZMKFlexboxNode.h
//  ZoomKit
//
//  Created by Cyan.Yang on 2024/6/6.
//

#import <Foundation/Foundation.h>

#if TARGET_OS_MAC
#import <Cocoa/Cocoa.h>

typedef NSView *PlatformView;
#else
#error "This platform is not supported."
#endif

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMKFlexboxDirection) {
    ZMKFlexboxDirectionHorizontal,
    ZMKFlexboxDirectionVertical,
};

typedef NS_ENUM(NSUInteger, ZMKFlexboxPosition) {
    ZMKFlexboxPositionStatic,
    ZMKFlexboxPositionRelative,
    ZMKFlexboxPositionAbsolute,
};

typedef NS_ENUM(NSUInteger, ZMKFlexboxAlign) {
    ZMKFlexboxAlignAuto,
    ZMKFlexboxAlignFlexStart,
    ZMKFlexboxAlignCenter,
    ZMKFlexboxAlignFlexEnd,
    ZMKFlexboxAlignStretch,
    ZMKFlexboxAlignBaseline,
    ZMKFlexboxAlignSpaceBetween,
    ZMKFlexboxAlignSpaceAround,
    ZMKFlexboxAlignSpaceEvenly,
};

typedef NS_ENUM(NSUInteger, ZMKFlexboxJustify) {
    ZMKFlexboxJustifyFlexStart,
    ZMKFlexboxJustifyCenter,
    ZMKFlexboxJustifyFlexEnd,
    ZMKFlexboxJustifySpaceBetween,
    ZMKFlexboxJustifySpaceAround,
    ZMKFlexboxJustifySpaceEvenly,
};

typedef NS_ENUM(NSUInteger, ZMKFlexboxValueType) {
    ZMKFlexboxValueTypeUnset,
    ZMKFlexboxValueTypePoint,
    ZMKFlexboxValueTypePercent,
};

struct ZMKFlexboxValue {
    CGFloat value;
    ZMKFlexboxValueType type;
};
typedef struct CF_BOXABLE ZMKFlexboxValue ZMKFlexboxValue;

NS_INLINE ZMKFlexboxValue
ZMKFlexboxValueMakePoint(CGFloat value) {
    return (ZMKFlexboxValue) {
        .value = value,
        .type = ZMKFlexboxValueTypePoint,
    };
}

NS_INLINE ZMKFlexboxValue
ZMKFlexboxValueMakePercent(CGFloat value) {
    return (ZMKFlexboxValue) {
        .value = value,
        .type = ZMKFlexboxValueTypePercent,
    };
}

extern const ZMKFlexboxValue ZMKFlexboxValueUnset;

@interface ZMKFlexboxNode : NSObject

@property (nonatomic, nullable, readonly, weak) PlatformView view;

@property (nonatomic, assign) BOOL usesControlSize;

@property (nonatomic, assign, getter=isFlexWrap) BOOL flexWrap;
@property (nonatomic, assign) CGFloat flexGrow;
@property (nonatomic, assign) CGFloat flexShrink;
@property (nonatomic, assign) CGFloat gap;
@property (nonatomic, assign) ZMKFlexboxValue width;
@property (nonatomic, assign) ZMKFlexboxValue height;
@property (nonatomic, assign) ZMKFlexboxDirection flexDirection;
@property (nonatomic, assign) ZMKFlexboxPosition position;
@property (nonatomic, assign) ZMKFlexboxAlign alignItems;
@property (nonatomic, assign) ZMKFlexboxAlign alignContent;
@property (nonatomic, assign) ZMKFlexboxJustify justifyContent;

@property (nonatomic, assign) NSEdgeInsets margin;
@property (nonatomic, assign) NSEdgeInsets padding;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
