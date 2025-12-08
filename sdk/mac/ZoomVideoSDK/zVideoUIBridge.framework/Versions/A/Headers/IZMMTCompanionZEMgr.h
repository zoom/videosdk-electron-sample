//
//  IZMMTCompanionZEMgr.h
//  VideoUIBridge
//
//  Created by Vinson Wang on 2023/7/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMMTZECompanionViewController;

@protocol IZMMTCompanionZEMgr <ZMRoutableObject>

- (ZMMTZECompanionViewController *)newViewControllerWithType:(ZMMTType)type;

- (void)enterCompanionMode;

- (void)leaveCompanionModeWithVideoOff;

- (void)onLeaveCompanionModeReqReceived:(ZMUser *)sender;

- (void)onLeaveCompanionModeRspReceived:(ZMUser *)sender agree:(BOOL)agree;

- (BOOL)isJoinZECompanionModeWithSessionImage;

- (NSString *)getZECompanionModeSessionImagePath;

- (BOOL)zeCompanionModeImageDownloadHasFailed;

@end

NS_ASSUME_NONNULL_END
