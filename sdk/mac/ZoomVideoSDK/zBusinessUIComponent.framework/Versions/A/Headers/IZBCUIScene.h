//
//  IZBCUIScene.h
//  zBusinessUIComponent
//
//  Created by Giannis Ge on 2023/8/29.
//

#import <Foundation/Foundation.h>
#import "ZBCUISceneDef.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Base
@protocol IZBCUISceneRuntimeContext <NSObject>
@required
- (void)cleanUp;
- (id<ZMEventRegistry, ZMEventPosterGenerator>)getRuntimeEventCenter;
@end

@protocol IZBCUIScene;
@protocol IZBCUISceneDelegate <NSObject>
@required
- (id<IZBCUISceneRuntimeContext>)getSceneRuntimeContext:(id<IZBCUIScene>)scene;
@optional
- (NSWindow *)getAttachedWindow:(id<IZBCUIScene>)scene;
@end

@protocol IZBCUIScene <NSObject>
@required
@property (nonatomic, weak) id<IZBCUISceneDelegate> delegate;
- (void)setUp;
- (void)cleanUp;
- (ZBCUISceneType)sceneType;
@end

NS_ASSUME_NONNULL_END
