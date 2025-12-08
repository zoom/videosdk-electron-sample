//
//  IZBCUILeaveScene.h
//  zBusinessUIComponent
//
//  Created by Nicola Lin on 2023/10/22.
//
#import "IZBCUIScene.h"
#import "zBusinessComponent/zbc_def.h"

NS_ASSUME_NONNULL_BEGIN
@protocol IZBCUILeaveScene;
@protocol IZBCUILeaveSceneDelegate <IZBCUISceneDelegate>
@optional
- (BOOL)amIHost:(id<IZBCUIScene>)scene;
- (void)leaveMeeting:(BOOL)end scene:(id<IZBCUIScene>)scene;
- (NSString *)getUserNameByUserId:(NSNumber *)userId scene:(id<IZBCUIScene>)scene;
- (NSString *)getUserAvatarPathByUserId:(NSNumber *)userId scene:(id<IZBCUIScene>)scene;
- (NSArray<NSNumber *> *)getParticipantsCanBeAssignedHostIdArray:(id<IZBCUIScene>)scene;
- (void)assignUserToHost:(NSNumber *)userId scene:(id<IZBCUIScene>)scene;
- (NSArray<ZBCUILeaveSceneDropdownButtonModel *> *)getEndButtonDropdownModelArray:(id<IZBCUILeaveScene>)leaveScene;
- (void)leaveScene:(id<IZBCUILeaveScene>)leaveScene onDropdownButtonOfModelClicked:(ZBCUILeaveSceneDropdownButtonModel *)model;
- (nullable NSImage *)leaveScene:(id<IZBCUILeaveScene>)leaveScene getAvatarByUserId:(NSNumber *)userId;
@end

@protocol IZBCUILeaveScene <IZBCUIScene>
@property (nonatomic, weak) id<IZBCUILeaveSceneDelegate> delegate;
- (void)updateToolbarEndButtonColorType:(ZBCUILeaveSceneToolbarEndButtonColorType)colorType title:(NSString *)title;
@end

NS_ASSUME_NONNULL_END
