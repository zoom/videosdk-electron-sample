//
//  IZBCUIContactCenterScene.h
//  zBusinessUIComponent
//
//  Created by Nicola Lin on 2023/10/20.
//

#import <Foundation/Foundation.h>
#import "IZBCUIScene.h"
#import "zBusinessComponent/zbc_def.h"

NS_ASSUME_NONNULL_BEGIN

@protocol IZBCUIContactCenterSceneDelegate <IZBCUISceneDelegate>
@optional
- (BOOL)canShowTakeoverButton:(id<IZBCUIScene>)scene;
- (void)onToolbarTakeoverButtonClicked:(id<IZBCUIScene>)scene;
- (BOOL)canShowHoldButton:(id<IZBCUIScene>)scene;
- (void)onToolbarHoldButtonClicked:(id<IZBCUIScene>)scene;
- (BOOL)isHoldSessionStarted:(id<IZBCUIScene>)scene;
- (BOOL)canShowReleaseButton:(id<IZBCUIScene>)scene;
- (void)onToolbarReleaseButtonClicked:(id<IZBCUIScene>)scene;
- (BOOL)canShowTransferButton:(id<IZBCUIScene>)scene;
- (void)onToolbarTransferButtonClicked:(id<IZBCUIScene>)scene;
@end

@protocol IZBCUIContactCenterScene <IZBCUIScene>
@property (nonatomic, weak) id<IZBCUIContactCenterSceneDelegate> delegate;
- (void)holdSessionStatusChanged;
@end

NS_ASSUME_NONNULL_END
