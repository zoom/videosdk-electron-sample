//
//  IZBCUIClosedCaptionScene.h
//  zBusinessUIComponent
//
//  Created by Giannis Ge on 2023/10/11.
//

#import <Foundation/Foundation.h>
#import "IZBCUIScene.h"
#import "zBusinessComponent/zbc_closed_caption_scene_interface.h"

NS_ASSUME_NONNULL_BEGIN
USING_ZBC_NAMESPACE

@protocol IZBCUIClosedCaptionScene;
@protocol IZBCUIClosedCaptionSceneDelegate <IZBCUISceneDelegate>
@optional
- (IZBCClosedCaptionSceneHandler *)getClosedCaptionSceneHandler:(id<IZBCUIScene>)scene;
- (BOOL)scene:(id<IZBCUIScene>)scene isClosedCaptionCanBeAttachedToWindow:(NSWindow *)window;
- (BOOL)canShowFullTranscriptItem:(id<IZBCUIClosedCaptionScene>)closeCaptionScene;
- (BOOL)isFullTranscriptPanelVisible:(id<IZBCUIClosedCaptionScene>)closeCaptionScene;
- (void)closeClosedCaptionFullTranscriptPanel;
- (void)openClosedCaptionFullTranscriptPanel;
- (void)scene:(id<IZBCUIScene>)scene notifyCaptionsStateChange:(BOOL)bCaptionsOpened;
- (nullable NSImage *)closedCaptionScene:(id<IZBCUIClosedCaptionScene>)closedCaptionScene getAvatarByUserId:(NSUInteger)userId;
- (nullable NSArray<NSNumber *> *)availableSpeakingLanguageIdArray:(id<IZBCUIClosedCaptionScene>)closedCaptionScene;
@end

@protocol IZBCUIClosedCaptionScene <IZBCUIScene>
@property (nonatomic, weak) id<IZBCUIClosedCaptionSceneDelegate> delegate;
- (void)showFullTranscriptViewWithLayoutBlock:(ZBCUIViewLayoutBlock)layoutBlock;
- (void)updateClosedCaptionDraggableWindowPosition:(BOOL)needReShowWindow;
- (void)openCCLiveTranscriptWindow;
- (void)closeCCLiveTranscriptWindow;
- (BOOL)isCCLiveTranscriptWindowVisible;
- (BOOL)isLTWindowShouldShow;
- (void)keepOpenedCCLiveTranscriptWindowIfNeed;
- (void)updateClosedCaptionSubtitleColor:(nullable NSColor *)color;
- (void)updateClosedCaptionTranslationColor:(nullable NSColor *)color;
- (void)updateClosedCaptionFontsize:(NSUInteger)fontSize;
@end

NS_ASSUME_NONNULL_END
