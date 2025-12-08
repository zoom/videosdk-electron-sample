//
//  ZMMTVideoViewMgr.h
//  SaasBeeConfUIModule
//
//  Created by Francis Zhuo on 8/11/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <zVideoUIBridge/ZMMTViewMgr.h>
#import <zVideoUIBridge/ZMMTConstants.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTVideoViewMgr : ZMMTViewMgr<ZMMTForceUpdateProtocol>

@end

NS_ASSUME_NONNULL_END
