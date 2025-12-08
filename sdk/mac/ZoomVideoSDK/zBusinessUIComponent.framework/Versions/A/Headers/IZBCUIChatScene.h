//
//  IZBCUIChatScene.h
//  zBusinessUIComponent
//
//  Created by Giannis Ge on 2023/10/11.
//

#import <Foundation/Foundation.h>
#import "IZBCUIScene.h"
#import "zBusinessComponent/zbc_chat_scene_interface.h"

NS_ASSUME_NONNULL_BEGIN
USING_ZBC_NAMESPACE

@protocol IZBCUIChatScene;
@protocol IZBCUIChatSceneDelegate <IZBCUISceneDelegate>
@optional
- (IZBCChatSceneHandler *)getChatSceneHandler:(id<IZBCUIScene>)scene;
- (BOOL)handleChatBtnClicked:(id<IZBCUIScene>)scene;
- (BOOL)isChatPanelVisible:(id<IZBCUIChatScene>)chatScene;
@end

@protocol IZBCUIChatScene <IZBCUIScene>
@property (nonatomic, weak) id<IZBCUIChatSceneDelegate> delegate;
- (void)updateChatBadgeNumber:(NSUInteger)badgeNumber;
@end

NS_ASSUME_NONNULL_END
