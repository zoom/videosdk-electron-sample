//
//  IZBCUIWhiteboardScene.h
//  zBusinessUIComponent
//
//  Created by Giannis Ge on 2023/10/11.
//

#import <Foundation/Foundation.h>
#import "IZBCUIScene.h"
#import "zBusinessComponent/zbc_whiteboard_scene_interface.h"

NS_ASSUME_NONNULL_BEGIN
USING_ZBC_NAMESPACE

@protocol IZBCUIWhiteboardScene;
@protocol IZBCUIWhiteboardSceneDelegate <IZBCUISceneDelegate>
@optional
- (IZBCWhiteboardSceneHandler *)getWhiteboardSceneHandler:(id<IZBCUIScene>)scene;
- (void)handleCanvasLoadingFailed:(id<IZBCUIScene>)scene;
- (void)handleWhiteboardBtnClicked:(id<IZBCUIScene>)scene;
- (void)whiteboardScene:(id<IZBCUIWhiteboardScene>)whiteboardScene didFinishNavigationWithURL:(BOOL)isSuccess;
- (void)whiteboardScene:(id<IZBCUIWhiteboardScene>)whiteboardScene webWBEvent:(WebWBEvent)state docId:(NSString *)docId userId:(unsigned int)userId;
- (nullable NSString *)getDashboardProcessDisplayName:(id<IZBCUIWhiteboardScene>)whiteboardScene;
- (nullable NSString *)getCanvasProcessDisplayName:(id<IZBCUIWhiteboardScene>)whiteboardScene;
@end

@protocol IZBCUIWhiteboardScene <IZBCUIScene>
@property (nonatomic, weak) id<IZBCUIWhiteboardSceneDelegate> delegate;
- (BOOL)isOtherSharingWhiteboard;
- (BOOL)isMyselfSharingWhiteboard;
- (void)stopMyselfSharingWhiteboard;
- (void)closeDashboard;
- (void)showDashboard;
- (void)reloadCurrentCanvas;
- (void)showCanvasInWindow:(NSWindow *)win;
- (void)closeCanvasWindow;
- (void)bringWhiteboardWindowToFront;
- (void)updateDashboardWindowLayout:(nullable ZBCUIWindowLayoutBlock)layoutBlock;
- (void)updateCanvasWindowLayout:(nullable ZBCUIWindowLayoutBlock)layoutBlock;
@end

NS_ASSUME_NONNULL_END
