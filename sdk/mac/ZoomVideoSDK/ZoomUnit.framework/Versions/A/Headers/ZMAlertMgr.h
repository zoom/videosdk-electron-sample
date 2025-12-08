//
//  ZMAlertMgr.h
//  zChatUI
//
//  Created by fistice on 7/29/25.
//  Copyright © 2025 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomUnit/ZMAlertInfo.h>
NS_ASSUME_NONNULL_BEGIN

@interface ZMAlertMgr : NSObject
- (void)showAlertWithInfo:(ZMAlertInfo *)info;
- (void)removeAlertWithInfo:(ZMAlertInfo *)info;
- (void)removeAlertWithIdentifier:(NSString *)identifier;

// @override
- (BOOL)isValidForRegister:(ZMAlertInfo *)info;

- (void)registerCoachMark:(ZMAlertInfo *)info;
- (void)unregisterCoachMark:(ZMAlertInfo *)info;
- (BOOL)isCoachMarkAvailable:(ZMAlertInfo *)info;
- (void)markCoachMarkShowing:(ZMAlertInfo *)info;
- (void)markCoachMarkShown:(ZMAlertInfo *)info;

- (void)showToastWithInfo:(ZMAlertInfo *)info;
- (void)showBubbleWithInfo:(ZMAlertInfo *)info;
- (void)showDialogWithInfo:(ZMAlertInfo *)info;
- (void)showBannerWithInfo:(ZMAlertInfo *)info;

- (void)removeToastWithInfo:(ZMAlertInfo *)info;
- (void)removeBubbleWithInfo:(ZMAlertInfo *)info;
- (void)removeDialogWithInfo:(ZMAlertInfo *)info;
- (void)removeBannerWithInfo:(ZMAlertInfo *)info;
// @@action
- (void)doAction:(ZMAlertButtonInfo *)btnInfo;
- (void)doAction:(ZMAlertInfo *)info position:(ZMAlertButtonPosition)position;

// @content
- (__kindof ZMAlertInfo *)getInfoFromListByID:(NSString *)identifier;
- (__kindof ZMAlertInfo *)getInfoFromListByCoachmarkID:(NSString *)identifier;
- (void)showRegistedAlertWithInfo:(ZMAlertInfo *)info;
- (void)markShowing:(ZMAlertInfo *)info;
- (void)markShown:(ZMAlertInfo *)info;

@end

NS_ASSUME_NONNULL_END
