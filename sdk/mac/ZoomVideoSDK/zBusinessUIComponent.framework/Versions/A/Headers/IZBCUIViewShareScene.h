//
//  IZBCUIViewShareScene.h
//  zBusinessUIComponent
//
//  Created by Giannis Ge on 2023/10/11.
//

#import <Foundation/Foundation.h>
#import "IZBCUIScene.h"
#import "ZBCUISceneDef.h"
#import "zBusinessComponent/zbc_share_scene_interface.h"
#import "zoom_meeting_bridge/export_h/render/zm_meeting_bridge_render_channel_interface.h"
#import "zoom_meeting_bridge/export_h/render/zm_meeting_bridge_render_data_provider_interface.h"

NS_ASSUME_NONNULL_BEGIN
USING_ZM_MEETING_BRIDGE_NAMESPACE
USING_ZBC_NAMESPACE

@protocol IZBCUIViewShareScene;
@protocol IZBCUIViewShareSceneDelegate <IZBCUISceneDelegate>
@optional

- (IZBCViewShareSceneHandler *)getViewShareSceneHandler:(id<IZBCUIScene>)scene;
- (IZMBRenderChannel *)getRenderChannel:(id<IZBCUIScene>)scene;
- (IZMBRenderDataProvider *)getDataProvider:(id<IZBCUIScene>)scene;
- (void)onNewShareSourceViewable:(id<IZBCUIScene>)scene;
- (void)onAllShareSourceClosed:(id<IZBCUIScene>)scene;
- (void)onAnnoToolbarStateChanged:(id<IZBCUIViewShareScene>)scene;
- (BOOL)isRemoteControlDisabled:(id<IZBCUIViewShareScene>)viewShareScene;
@end

@protocol IZBCUIViewShareScene <IZBCUIScene>
@property (nonatomic, weak) id<IZBCUIViewShareSceneDelegate> delegate;
- (void)showViewer:(ZBCUIViewLayoutBlock)layoutBlock listenerBlock:(ZBCUIWindowDelegateListenerBlock)listenerBlock;
- (void)tryStartViewPureComputerAudio;
- (void)bringScreenShareWindowToFront;
- (BOOL)isAnnoToolbarShown;
@end

NS_ASSUME_NONNULL_END
