//
//  ZMMTAudioUUIHelper.h
//  VideoUIBridge
//
//  Created by Michael Lin on 2025/9/19.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMBaseHelper.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTAudioUUIHelper : ZMBaseHelper

// MARK: - Audio Plan Notice
- (nullable NSString *)getAudioPlanNoticeUrl;

// MARK: - Audio Plan Status  
- (BOOL)isAudioPlanSuspended;

@end

NS_ASSUME_NONNULL_END
