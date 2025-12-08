//
//  IZMZDMRegisterMgr.h
//  ChatUI
//
//  Created by davies zhao on 2024/4/18.
//  Copyright © 2024 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#ifdef __cplusplus
#import <zPTApp/PTService/IPTZDMServiceMgr.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@protocol IZMZDMRegisterMgr <ZMRoutableObject>
- (void)registerZDMStatusObseverIfNeeded;
- (BOOL)canUseZoom;
#ifdef __cplusplus
- (ZDMStatus)getZDMStatus;
#endif
@end

@protocol ZMZDMRegisterEventsProtocol <NSObject>
#ifdef __cplusplus
- (void)zdmStatusUpdated:(ZDMStatus)status;
#endif
@end

NS_ASSUME_NONNULL_END
