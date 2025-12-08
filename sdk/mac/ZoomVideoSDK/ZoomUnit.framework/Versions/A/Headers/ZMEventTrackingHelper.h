//
//  ZMEventTrackingHelper.h
//  zChatComponent
//
//  Created by Yong Zhou on 11/1/23.
//

#import <Foundation/Foundation.h>
#import <ZoomTelemetry/ZoomEventLogConsts/ZoomEventLogConsts_Desktop.h>

#import <events/chat_perfmetrics_Perfmetrics_enum.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS (NSUInteger, PerfmetricsEventSource) {
    PerfmetricsEventSource_None = 0,
    PerfmetricsEventSource_Login,
    PerfmetricsEventSource_Fetch,
    PerfmetricsEventSource_Fetch_Handle,
    PerfmetricsEventSource_Heartbeat,
    PerfmetricsEventSource_Message,
    PerfmetricsEventSource_Message_Handle,
    PerfmetricsEventSource_Platform,
    PerfmetricsEventSource_File
};

@interface ZMEventTrackItem : NSObject
@property (nonatomic, assign, getter=isTracked) BOOL tracked;
@property (nonatomic, assign) unsigned int eventType;
@property (nonatomic, copy) NSString *eventID;
@end

@interface ZMEventTrackingHelper : NSObject

@property (nonatomic, strong, readonly) NSMutableDictionary<NSString *, ZMEventTrackItem *> *trackEventPool;

+ (instancetype)sharedInstance;

/// add trackEvetracknt for specificed event.
///    Generally: (a). If the event should only be  tracked once, we'll check if the eventType exists in trackEventPool. If yes, return directly; If No, we'll add the event to trackEventPool. (b).If the event should be tracked everytime, before we add the event to trackEventPool, we'll check if the eventType exists in trackEventPool, if yes, remove the original eventType from trackEventPool,  and add a new eventType to trackEventPool, we'll only record the last one if addTrackEventWithTrackType called multipe times at the same time.
/// - Parameters:
///   - eventType: ZoomLogSubEvent
///   - trackID: eventID, can be any string to Identifier the event.
///   - result: If error happens, error code is needed.
///   - repeats: If YES, the type of event can be tracked repetitively. If NO, the event will be tracked only once.
///   - intParams: Optional. A map of `e_chat_perfmetrics_Perfmetrics_event_tag_int` keys to `long long` values to be passed as part of the event
///   - strParams: Optional. A map of `e_chat_perfmetrics_Perfmetrics_event_tag_str` keys to `NSString` values to be passed as part of the event
+ (void)addTrackEventWithEventSource:(PerfmetricsEventSource)source
                                type:(unsigned int)eventType
                             trackID:(NSString *)trackID
                              result:(long)result
                             repeats:(BOOL)repeats
                           intParams:(NSDictionary<NSNumber*, NSNumber*> *_Nullable)intParams
                           strParams:(NSDictionary<NSNumber*, NSString*> *_Nullable)strParams;

/// add trackEvetracknt for specificed event.
///    Generally: (a). If the event should only be  tracked once, we'll check if the eventType exists in trackEventPool. If yes, return directly; If No, we'll add the event to trackEventPool. (b).If the event should be tracked everytime, before we add the event to trackEventPool, we'll check if the eventType exists in trackEventPool, if yes, remove the original eventType from trackEventPool,  and add a new eventType to trackEventPool, we'll only record the last one if addTrackEventWithTrackType called multipe times at the same time.
/// - Parameters:
///   - eventType: ZoomLogSubEvent
///   - trackID: eventID, can be any string to Identifier the event.
///   - result: If error happens, error code is needed.
///   - repeats: If YES, the type of event can be tracked repetitively. If NO, the event will be tracked only once.
///
+ (void)addTrackEventWithEventSource:(PerfmetricsEventSource)source 
                                type:(unsigned int)eventType
                             trackID:(NSString *)trackID
                              result:(long)result
                             repeats:(BOOL)repeats;

/// tracking the specific eventType only once. If the eventType should be tracked everytime, use addTrackEventWithEventSource:(PerfmetricsEventSource)source type:trackID:result:repeats instead.
+ (void)addTrackEventWithEventSource:(PerfmetricsEventSource)source
                                type:(unsigned int)eventType
                             trackID:(NSString *)trackID
                              result:(long)result;

+ (void)endTrackEventWithEventSource:(PerfmetricsEventSource)source
                                type:(unsigned int)eventType
                             trackID:(NSString *)trackID
                              result:(long)result;

+ (BOOL)isEventTrackedWithType:(unsigned int)eventType;

+ (ZMEventTrackItem *)trackEventWithTrackType:(unsigned int)eventType;

+ (ZMEventTrackItem *)trackEventWithTrackID:(NSString *)trackID;

+ (NSString *)trackIDWithEvent:(unsigned int)eventType;

@end

#pragma mark - Performance Telemetry

void PerfTelemetryInitWithTime(uint64_t startTime);
void PerfTelemetryTerminate();

BOOL PerfTelemetryAddEvent(PerfmetricsEventSource source, unsigned int subEvent, NSString *eventName, uint64_t dwTimeCost, long result);

BOOL PerfTelemetryStart(PerfmetricsEventSource source, unsigned int subEvent, long result);
BOOL PerfTelemetryEnd(PerfmetricsEventSource source, unsigned int subEvent, long result);

BOOL PerfTelemetryStartWithID(PerfmetricsEventSource source, unsigned int subEvent, long result, NSString *eventID,
                              NSDictionary<NSNumber*, NSNumber*> * intParams, NSDictionary<NSNumber*, NSString*> * strParams);
BOOL PerfTelemetryStartWithID(PerfmetricsEventSource source, unsigned int subEvent, long result, NSString *eventID);
BOOL PerfTelemetryEndWithID(PerfmetricsEventSource source, unsigned int subEvent, long result, NSString *eventID);

void *PERF_StartTelemetryStacks(NSString *moduleName, NSString *funcName, BOOL bLog);
void PERF_EndTelemetryStacks(void *);

#ifdef __cplusplus
class PERF_TelemetryStacks {
    void *m_p;
public:
    PERF_TelemetryStacks(NSString *moduleName, NSString *funcName, BOOL bLog = NO);
    ~PERF_TelemetryStacks();
};
#endif

NS_ASSUME_NONNULL_END
