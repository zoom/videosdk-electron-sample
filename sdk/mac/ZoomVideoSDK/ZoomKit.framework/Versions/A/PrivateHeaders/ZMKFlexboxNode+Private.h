//
//  ZMKFlexboxNode+Private.h
//  ZoomKit
//
//  Created by Cyan.Yang on 2024/6/6.
//

#import <CoreGraphics/CoreGraphics.h>
#import <ZoomKit/ZMKFlexboxNode.h>

typedef struct YGNode* YGNodeRef;

NS_ASSUME_NONNULL_BEGIN

@interface ZMKFlexboxNode ()

@property (nonatomic, readonly) YGNodeRef yogaNode;
@property (nonatomic, nullable, readonly) ZMKFlexboxNode *parentNode;

@property (nonatomic, readonly) CGSize measuredSize;
@property (nonatomic, readonly) CGPoint layoutPosition;

- (instancetype)initWithView:(PlatformView)view NS_DESIGNATED_INITIALIZER;

- (void)addChildNode:(ZMKFlexboxNode *)node;
- (void)removeAllChildNodes;
- (void)removeFromParentNode;

- (void)markDirty;

- (void)calculateLayoutWithSize:(CGSize)size fitContentMode:(BOOL)flag;
- (void)applyLayout;

@end

NS_ASSUME_NONNULL_END
