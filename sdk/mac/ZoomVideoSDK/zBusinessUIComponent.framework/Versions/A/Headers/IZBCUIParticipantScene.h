//
//  IZBCUIParticipantScene.h
//  zBusinessUIComponent
//
//  Created by Nicola Lin on 2023/10/22.
//

#import "IZBCUIScene.h"
#import "zBusinessComponent/zbc_def.h"

NS_ASSUME_NONNULL_BEGIN

@protocol IZBCUIParticipantScene;
@protocol IZBCUIParticipantSceneDelegate <IZBCUISceneDelegate>
@optional
- (BOOL)canShowParticipantButton:(id<IZBCUIScene>)scene;
- (BOOL)canShowParticipantMenuButton:(id<IZBCUIScene>)scene;
- (void)onToolbarParticipantButtonClicked:(id<IZBCUIScene>)scene;
- (BOOL)canShowInviteButton:(id<IZBCUIParticipantScene>)participantScene;
- (void)onToolbarInviteButtonClicked:(id<IZBCUIParticipantScene>)participantScene;
@end

@protocol IZBCUIParticipantScene <IZBCUIScene>
@property (nonatomic, weak) id<IZBCUIParticipantSceneDelegate> delegate;
- (void)updateParticipantBadgeNumber:(NSUInteger)badgeNumber;
@end

NS_ASSUME_NONNULL_END
