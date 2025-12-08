//
//  IZBCUIToolbarScene.h
//  zBusinessUIComponent
//
//  Created by Giannis Ge on 2023/10/13.
//

#import <Foundation/Foundation.h>
#import "IZBCUIScene.h"
#import "zBusinessComponent/zbc_toolbar_scene_interface.h"

NS_ASSUME_NONNULL_BEGIN
USING_ZBC_NAMESPACE

@protocol IZBCUIToolbarSceneDelegate <IZBCUISceneDelegate>
- (IZBCToolbarSceneHandler *)getToolbarSceneHandler:(id<IZBCUIScene>)scene;
@end

@protocol IZBCUIToolbarScene <IZBCUIScene>
@optional
@property (nonatomic, weak) id<IZBCUIToolbarSceneDelegate> delegate;
- (void)bindScenes:(nullable NSArray<id<IZBCUIScene>> *)scenes;
- (void)configureComponentTypesOfHeadStack:(nullable NSArray<NSNumber *> *)headComponentTypes
                               middleStack:(nullable NSArray<NSNumber *> *)middleComponentTypes
                                 tailStack:(nullable NSArray<NSNumber *> *)tailComponentTypes;
- (void)updateToolbarViewVisibility:(BOOL)isVisible layoutBlock:(ZBCUIViewLayoutBlock)layoutBlock;
- (void)customizeForceHidden:(BOOL)isHidden disable:(BOOL)isDisable toolbarComponentType:(ZBCUIToolbarComponentType)type;
- (void)refreshToolbar;
@end

NS_ASSUME_NONNULL_END
