//
//  IZBCUISendShareScene.h
//  zBusinessUIComponent
//
//  Created by Giannis Ge on 2023/10/11.
//

#import <Foundation/Foundation.h>
#import "IZBCUIScene.h"
#import "zBusinessComponent/zbc_share_scene_interface.h"
#import "zoom_meeting_bridge/export_h/render/zm_meeting_bridge_render_channel_interface.h"
#import "zoom_meeting_bridge/export_h/render/zm_meeting_bridge_render_data_provider_interface.h"

NS_ASSUME_NONNULL_BEGIN
USING_ZM_MEETING_BRIDGE_NAMESPACE
USING_ZBC_NAMESPACE

@protocol IZBCUISendShareScene;

@protocol IZBCUISendShareSceneDelegate <IZBCUISceneDelegate>
@optional
- (IZBCSendShareSceneHandler *)getSendShareSceneHandler:(id<IZBCUIScene>)scene;
- (IZMBRenderChannel *)getRenderChannel:(id<IZBCUIScene>)scene;
- (IZMBRenderDataProvider *)getDataProvider:(id<IZBCUIScene>)scene;
- (NSArray<NSNumber *> *)getCanRemoteControlUserIdList:(id<IZBCUIScene>)scene;
- (BOOL)canShowRemoteControlBtnWhenNotSharing:(id<IZBCUISendShareScene>)sendShareScene;
- (void)sendShareScene:(id<IZBCUISendShareScene>)sendShareScene remoteControlBtnActionDecisionHandler:(void (^)())actionDecisionHandler;
- (void)handleShareBtnClicked:(id<IZBCUIScene>)scene;

- (void)onDidStartSendShare:(id<IZBCUIScene>)scene;
- (void)onDidStopSendShare:(id<IZBCUIScene>)scene;
- (BOOL)canShowVoiceVideoOptions:(id<IZBCUIScene>)scene;
- (BOOL)isSupportMultiSelect:(id<IZBCUIScene>)scene;
- (void)sendShareScene:(id<IZBCUISendShareScene>)sendShareScene onSharingFitbarManuallyHidden:(BOOL)isHidden;

@end

@protocol IZBCUISendShareScene <IZBCUIScene>
@property (nonatomic, weak) id<IZBCUISendShareSceneDelegate> delegate;
- (void)bindScenes:(nullable NSArray<id<IZBCUIScene>> *)scenes;
- (void)configureFitToolbarComponentTypes:(nullable NSArray<NSNumber *> *)componentTypes;
- (void)showSelections;
- (void)hideSelections;
- (void)notifyShareZoomWindowOptionChanged;
- (void)refreshFitToolbar;
- (BOOL)toggleFitbarVisibility;
@end

NS_ASSUME_NONNULL_END
