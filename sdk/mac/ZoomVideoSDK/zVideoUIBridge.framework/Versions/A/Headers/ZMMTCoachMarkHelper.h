//
//  ZMMTCoachMarkHelper.h
//  VideoUIBridge
//
//  Created by Howie Xu on 12/12/23.
//

#import <zVideoUIBridge/ZMBaseHelper.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTCoachMarkHelper : ZMBaseHelper

- (nullable cmm_chmrk::IZMCoachMarkMgr *)getCoachMarkMgr;

- (BOOL)isFirstTimeUse;

- (void)initCoachMark;

- (void)uninitCoachMark;

- (void)setNotFirstTimeUse;

- (void)setupCoachMark:(CmmUInt32)interval;

- (BOOL)isCoachMarkAvailableWithIdentifier:(NSString *)identifier;

- (void)markCoachMarkShownOnRegisterWithIdentifier:(NSString *)identifier;

- (void)onCoachMarkShowingWithIdentifier:(NSString *)identifier;

- (void)markCoachMarkShownWithIdentifier:(NSString *)identifier;

- (NSInteger)getCoachMarkShownCountWithIdentifier:(NSString *)identifier;

@end

NS_ASSUME_NONNULL_END
