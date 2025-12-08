//
//  ZMMTUIModuleDelegate.h
//  VideoUIBridge
//
//  Created by Francis Zhuo on 2023/11/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMMTUIModuleDelegate <NSObject>
+ (Cmm::ICmmMessageQueueClient*)newMeetingClient;
@end

NS_ASSUME_NONNULL_END
