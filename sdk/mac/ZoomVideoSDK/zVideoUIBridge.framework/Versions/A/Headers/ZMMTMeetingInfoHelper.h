//
//  ZMMTMeetingInfoHelper.h
//  VideoUIBridge
//
//  Created by Karen Cao on 12/12/24.
//

#import <zVideoUIBridge/ZMBaseHelper.h>
#import <zVideoUIBridge/ZMSmartAgendaDocInfo.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, LiveSummaryStatus) {
    LiveSummaryStatusNone = 0,
    LiveSummaryStatusStart = 1,
    LiveSummaryStatusStop = 2,
};

typedef NS_ENUM(NSUInteger, AICStatus) {
    AICStatusSummaryQueryOff = 0,
    AICStatusSummaryOn = 1,
    AICStatusQueryOn = 2,
    AICStatusSummaryQueryOn = 3,
};

@interface ZMMTMeetingInfoHelper : ZMBaseHelper
- (NSString*)getLiveSummaryDocId;
- (BOOL)isPopupNewMeetingInfoWindowEnabled;
- (void)setPopupNewMeetingInfoWindowEnable:(BOOL)enabled;
- (BOOL)isMeetingDetailEnabled;
- (BOOL)isMeetingHasAssets;
- (BOOL)isLiveSummaryEnabled;
- (BOOL)isSmartAgendaEnabled;
- (BOOL)isLiveSummaryOn;
- (LiveSummaryStatus)getLiveSummaryStatus;
- (BOOL)changeLiveSummaryStatus:(LiveSummaryStatus)action;
- (ZMSmartAgendaDocInfo *)getSmartAgendaDocInfo;
- (AICStatus)getAICStatus;
- (BOOL)updateSummaryShareLevel;
- (BOOL)requestToSwitchAICompanionWithLiveSummary:(long long)aicOption switchAction:(NSInteger)switchAction;
- (BOOL)respondToSwitchAICompanionWithLiveSummary:(NSString *)reqId senderId:(ZMUserID)senderId switchAction:(NSInteger)switchAction agree:(BOOL)agree;

@end
NS_ASSUME_NONNULL_END
