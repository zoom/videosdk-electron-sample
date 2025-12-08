//
//  ZMScenarioTelemetryTracker.h
//  ZoomUnit
//
//  Created by Davies Zhao on 2025/7/31.
//

#import <Foundation/Foundation.h>
#import <events/MetricsScenario_enum.h>
#import <cmmlib/CmmString.h>
#import <ZoomTelemetry/ZoomTelemetryEnums.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMScenarioTelemetry : NSObject
@property (nonatomic, assign) e_MetricsScenario_module_name moduleName;
@property (nonatomic, assign) e_MetricsScenario_scenario_name scenarioName;
@property (nonatomic, assign) e_MetricsScenario_scenario_location scenarioLocation;
@property (nonatomic, assign) e_MetricsScenario_service_name serviceName;

@property (nonatomic, assign) e_MetricsScenario_step_name stepName;
@property (nonatomic, assign) e_MetricsScenario_sub_step subStep;
@property (nonatomic, assign) e_MetricsScenario_step_type stepType;
@property (nonatomic, assign) ns_zoom_telemetry::ZMonitorLogCategory logCategoryType;
@end

@interface ZMScenarioTelemetryTracker : NSObject

+ (BOOL)startMetricsScenario:(ZMScenarioTelemetry *)telemetry andSessionID:(Cmm::CString &)sessionID;
+ (BOOL)addStepInfo:(ZMScenarioTelemetry *)telemetry bySessionID:(NSString *)sessionID;
+ (BOOL)endMetricsScenario:(ZMScenarioTelemetry *)telemetry bySessionID:(NSString *)sessionID;
@end

NS_ASSUME_NONNULL_END
