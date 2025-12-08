//
//  ZMConfCallbackDispatcherHelper.h
//  VideoUIBridge
//
//  Created by davies zhao on 2024/5/16.
//

#import <Foundation/Foundation.h>
#include <zm_conf_callback_dispatcher/zm_conf_callback_dispatcher_api.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMConfCallbackDispatcherHelper : NSObject
+ (nullable NS_ZM_CONF_CALLBACK_DISPATCHER::IZmConfCallbackDispatcher *)getConfCallbackDispatcher;
+ (nullable NS_ZM_CONF_CALLBACK_DISPATCHER::IMultiConfContainerSinkDispatcher *)getMultiConfContainerSinkDispatcher;
+ (nullable NS_ZM_CONF_CALLBACK_DISPATCHER::IConfSinkDispatcher *)getConfSinkDispatcher:(const CmmConfInstType &)conf_inst_type andRoomId:(const CmmUInt16&)room_id;
+ (nullable NS_ZM_CONF_CALLBACK_DISPATCHER::IMultiConfSinkDispatcher *)getMultiConfSinkDispatcher:(const CmmConfInstType &)conf_inst_type;
@end

NS_ASSUME_NONNULL_END
