//
//  ZMMTAvatarProtocol.h
//  VideoUIBridge
//
//  Created by Carol.Li on 2024/1/22.
//
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol  ZMMTAvatarProtocol<NSObject>
@optional
- (void)onAvatarPermissionStatusChanged;
@end

NS_ASSUME_NONNULL_END

