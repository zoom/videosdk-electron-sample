//
//  ZBCUILayerVideoController.h
//  zBusinessUIComponent
//
//  Created by Jax Wu on 2024/1/9.
//

#import <Cocoa/Cocoa.h>
#import "ZBCUILayerDefine.h"
#import <zVideoUIBridge/ZMUIConstants.h>
#import <zVideoUIBridge/ZMMTVideoViewController.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZBCUILayerVideoController : ZMMTVideoViewController

#pragma mark - Public API
- (void)addCustomBGView:(NSView *)bgView;
- (void)removeCustomBGView;
- (void)configGridVideEdge:(NSEdgeInsets)edge;

// Data Source API
- (void)reloadWith:(NSArray<id<ZBCUILayerModelProtocol>> *)models;
- (void)reloadWith:(NSArray<id<ZBCUILayerModelProtocol>> *)models animation:(BOOL)animation;
- (void)addModel:(NSArray<id<ZBCUILayerModelProtocol>> *)models;
- (void)addModel:(NSArray<id<ZBCUILayerModelProtocol>> *)models animation:(BOOL)animation;

- (void)removeAllModels;
- (void)removeModel:(NSArray<NSString *> *)identifierArray;
- (void)removeModel:(NSArray<NSString *> *)identifierArray animation:(BOOL)animation;
- (void)removeModelWithType:(ZBCUILayerModelType)modelType;
- (void)removeModelWithType:(ZBCUILayerModelType)modelType animation:(BOOL)animation;

- (void)onSpotsCurrentSessionChanged:(ZMConfSession *)session;
@end

NS_ASSUME_NONNULL_END
