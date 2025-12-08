//
//  IZBCUIRecordScene.h
//  zBusinessUIComponent
//
//  Created by Nicola Lin on 2023/10/22.
//

#import "IZBCUIScene.h"
#import "zBusinessComponent/zbc_record_scene_interface.h"

NS_ASSUME_NONNULL_BEGIN
USING_ZBC_NAMESPACE

@protocol IZBCUIRecordSceneDelegate <IZBCUISceneDelegate>
@optional
- (IZBCRecordSceneHandler *)getRecordSceneHandler:(id<IZBCUIScene>)scene;
- (void)onRecordingStart:(id<IZBCUIScene>)scene;
- (void)onRecordingStop:(id<IZBCUIScene>)scene;
@end

@protocol IZBCUIRecordScene <IZBCUIScene>
@property (nonatomic, weak) id<IZBCUIRecordSceneDelegate> delegate;
- (void)updateRecordingViewVisibility:(BOOL)isVisible layoutBlock:(ZBCUIViewLayoutBlock)layoutBlock;
- (void)startRecording:(BOOL)isCloudRecording;
- (void)customizeDisablePauseRecording:(BOOL)isPauseDisable disableStopRecording:(BOOL)isStopDisable;
- (void)customizeStartRecordingToolTip:(nullable NSString *)startToolTip
                 pauseRecordingToolTip:(nullable NSString *)pauseToolTip
                resumeRecordingToolTip:(nullable NSString *)resumeToolTip
                  stopRecordingToolTip:(nullable NSString *)stopToolTip;
@end

NS_ASSUME_NONNULL_END
