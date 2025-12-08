//
//  IZBCUIAudioScene.h
//  zBusinessUIComponent
//
//  Created by Giannis Ge on 2023/10/11.
//

#import <Foundation/Foundation.h>
#import "IZBCUIScene.h"
#import "zBusinessComponent/zbc_audio_scene_interface.h"

NS_ASSUME_NONNULL_BEGIN
USING_ZBC_NAMESPACE

@protocol IZBCUIAudioScene;
@protocol IZBCUIAudioSceneDelegate <IZBCUISceneDelegate>
@optional
- (IZBCAudioSceneHandler *)getAudioSceneHandler:(id<IZBCUIScene>)scene;
- (BOOL)canShowSameAsSystemMicrophoneItem:(id<IZBCUIScene>)scene;
- (BOOL)canShowSameAsSystemSpeakerItem:(id<IZBCUIScene>)scene;
- (BOOL)canShowAudioSettingItem:(id<IZBCUIScene>)scene;
- (BOOL)canShowNoiseSuppressionItem:(id<IZBCUIAudioScene>)audioScene;
@end

@protocol IZBCUIAudioScene <IZBCUIScene>
@property (nonatomic, weak) id<IZBCUIAudioSceneDelegate> delegate;
- (BOOL)testSpeakerAndMicrophone;
@end

NS_ASSUME_NONNULL_END
