//
//  ZBCUISceneCreator.h
//  zBusinessUIComponent
//
//  Created by Giannis Ge on 2023/9/28.
//

#import <Foundation/Foundation.h>
#import "IZBCUIToolbarScene.h"
#import "IZBCUIAudioScene.h"
#import "IZBCUIVideoScene.h"
#import "IZBCUIChatScene.h"
#import "IZBCUIClosedCaptionScene.h"
#import "IZBCUISendShareScene.h"
#import "IZBCUIViewShareScene.h"
#import "IZBCUIWhiteboardScene.h"
#import "IZBCUIContactCenterScene.h"
#import "IZBCUILeaveScene.h"
#import "IZBCUIParticipantScene.h"
#import "IZBCUIRecordScene.h"

NS_ASSUME_NONNULL_BEGIN
USING_ZBC_NAMESPACE
@interface ZBCUISceneCreator : NSObject
#pragma mark - scene creator
+ (id<IZBCUIToolbarScene>)createToolbarScene;
+ (id<IZBCUIAudioScene>)createAudioScene;
+ (id<IZBCUIVideoScene>)createVideoScene;
+ (id<IZBCUIChatScene>)createChatScene;
+ (id<IZBCUIClosedCaptionScene>)createClosedCaptionScene;
+ (id<IZBCUISendShareScene>)createSendShareScene;
+ (id<IZBCUIViewShareScene>)createViewShareScene;
+ (id<IZBCUIWhiteboardScene>)createWhiteboardScene;
+ (id<IZBCUIContactCenterScene>)createContactCenterScene;
+ (id<IZBCUILeaveScene>)createLeaveScene;
+ (id<IZBCUIParticipantScene>)createParticipantScene;
+ (id<IZBCUIRecordScene>)createRecordScene;

#pragma mark - scene handler creator & destroyer
+ (IZBCToolbarSceneHandler *)createToolbarSceneHandler;
+ (void)destroyToolbarSceneHandler:(IZBCToolbarSceneHandler *)handler;
+ (IZBCAudioSceneHandler *)createAudioSceneHandler;
+ (void)destroyAudioSceneHandler:(IZBCAudioSceneHandler *)handler;
+ (IZBCVideoSceneHandler *)createVideoSceneHandler;
+ (void)destroyVideoSceneHandler:(IZBCVideoSceneHandler *)handler;
+ (IZBCChatSceneHandler *)createChatSceneHandler;
+ (void)destroyChatSceneHandler:(IZBCChatSceneHandler *)handler;
+ (IZBCClosedCaptionSceneHandler *)createClosedCaptionSceneHandler;
+ (void)destroyClosedCaptionSceneHandler:(IZBCClosedCaptionSceneHandler *)handler;
+ (IZBCSendShareSceneHandler *)createSendShareSceneHandler;
+ (void)destroySendShareSceneHandler:(IZBCSendShareSceneHandler *)handler;
+ (IZBCViewShareSceneHandler *)createViewShareSceneHandler;
+ (void)destroyViewShareSceneHandler:(IZBCViewShareSceneHandler *)handler;
+ (IZBCWhiteboardSceneHandler *)createWhiteboardSceneHandler;
+ (void)destroyWhiteboardSceneHandler:(IZBCWhiteboardSceneHandler *)handler;
+ (IZBCRecordSceneHandler *)createRecordSceneHandler;
+ (void)destroyRecordSceneHandler:(IZBCRecordSceneHandler *)handler;
#pragma mark - scene runtime context creator
+ (id<IZBCUISceneRuntimeContext>)createSceneRuntimeContext;
@end

NS_ASSUME_NONNULL_END
