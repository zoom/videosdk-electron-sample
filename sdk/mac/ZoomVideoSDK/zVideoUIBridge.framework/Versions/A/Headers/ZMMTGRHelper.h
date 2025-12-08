//
//  ZMMTGRHelper.h
//  VideoUIBridge
//
//  Created by Francis Zhuo on 2024/7/24.
//

#import <zVideoUIBridge/ZMBaseHelper.h>

NS_ASSUME_NONNULL_BEGIN
@class ZMUser;
@interface ZMMTGRHelper : ZMBaseHelper
- (BOOL)isSupportGreenRoom;
- (BOOL)isInGreenRoom;

- (BOOL)isPanelistCanEnterGRFreely;
- (void)setPanelistCanEnterGRFreely:(BOOL)freely;

- (BOOL)isUserCanJoinGR:(ZMUser *)zmUser;
- (BOOL)isUserCanLeaveGR:(ZMUser *)zmUser;

- (BOOL)canIJoinGR;
- (BOOL)canILeaveGR;
@end

NS_ASSUME_NONNULL_END
