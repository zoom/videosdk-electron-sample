//
//  ZMMTDynamicLayoutModel.h
//  VideoUIBridge
//
//  Created by Jun Pang on 1/18/24.
//

#import <Foundation/Foundation.h>

#define MakeMTDLRect(rect, cornerMask) [ZMMTDLRect buildMTDLRect:rect cornerType:cornerMask]
#define MakeAnimationRect(rect, type) [ZMMTAnimationRect buildAnimationRect:rect withType:type]
#define GetRectType(targetRect, aTopRect, aBotRect) [ZMMTAnimationTools getRectType:targetRect topRect:aTopRect bottomRect:aBotRect]


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ZMMTDynamicRectType) {
    ZMMTDynamicRectTypeNone,
    ZMMTDynamicRectTypeTop,
    ZMMTDynamicRectTypeBottom
};

@interface ZMMTDLRect : NSObject

@property (nonatomic) NSRect rect;
@property (nonatomic) NSRectCorner cornerMask;
+(instancetype)buildMTDLRect:(NSRect)rect cornerType:(NSRectCorner)cornerMask;

@end

@interface ZMMTAnimationRect : NSObject

@property (nonatomic) NSRect rect;
@property (nonatomic) ZMMTDynamicRectType type;
+(instancetype)buildAnimationRect:(NSRect)rect withType:(ZMMTDynamicRectType)type;

@end

@interface ZMMTAnimationTools : NSObject

+ (ZMMTDynamicRectType)getRectType:(NSRect)targetRect topRect:(NSRect)topRect bottomRect:(NSRect)botRect;

@end

@interface ZMMTActiveSpeakerNumberConfig : NSObject

@property (nonatomic) NSUInteger activeSpeakerNum;
@property (nonatomic) NSUInteger minUserCount;
@property (nonatomic) NSUInteger maxUserCount;

@end

NS_ASSUME_NONNULL_END
