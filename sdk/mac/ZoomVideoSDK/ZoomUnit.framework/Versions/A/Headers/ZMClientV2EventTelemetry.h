//
//  ZMClientV2EventTelemetry.h
//  ZoomUnit
//
//  Created by davies zhao on 2025/4/22.
//

#import <Foundation/Foundation.h>
#import <zTelemetryBiz/SnowplowBiz/client_v2/client_v2_telemetry_types.h>
NS_ASSUME_NONNULL_BEGIN

@interface ZMClientV2EventTelemetry : NSObject
@property(nonatomic, assign) e_Interaction_feature_name featureName;
@property(nonatomic, assign) e_Interaction_event_source eventSource;
@property(nonatomic, assign) e_Interaction_event_type eventType;
@property(nonatomic, assign) e_Interaction_event_location eventLocation;
@property(nonatomic, assign) e_Interaction_event_name eventName;

@property(nonatomic, assign) e_Interaction_sub_feature_name subFeatureName;

@property(nonatomic, copy, nullable) NSString * eventTraceSource;
@property(nonatomic, copy, nullable) NSString * errorReason;

- (void)setRawNoticeEntity:(ns_zoom_telemetry::ClientV2NoticeEntityParams)noticeEntity;
@end

@interface ZMClientV2EventTracker : NSObject

+ (void)trackClientEvent:(ZMClientV2EventTelemetry *)clientEvent;

@end

NS_ASSUME_NONNULL_END
