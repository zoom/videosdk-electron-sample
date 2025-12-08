//
//  IZMMTImprovedCompanionMgr.h
//  VideoUIBridge
//
//  Created by Molay.Yu on 2024/2/4.
//

@class ZMMTImprovedCompanionViewController;

@protocol IZMMTImprovedCompanionMgr <ZMRoutableObject>

- (BOOL)isSessionInImprovedCompanionMode;

- (ZMMTImprovedCompanionViewController *)newViewControllerWithType:(ZMMTType)type;

- (void)showLeaveImprovedCompanionModeAlert;

@end
