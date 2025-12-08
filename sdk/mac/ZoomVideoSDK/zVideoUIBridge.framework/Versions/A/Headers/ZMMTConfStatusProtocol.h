//
//  ZMMTConfStatusProtocol.h
//  VideoUIBridge
//
//  Created by geno.chen on 2022/8/15.
//

#ifndef ZMMTConfStatusProtocol_h
#define ZMMTConfStatusProtocol_h

@class ZMConfSession;
@protocol ZMMTConfStatusProtocol <NSObject>
@optional
- (void)onPSSceneFetchResult:(BOOL)result;
- (void)onPSProducerChanged:(int)result;
- (void)onPSProducerLiving;
- (void)onPSUserWillLived:(NSUInteger)context;
- (void)onPSPublishSceneChanged;
- (void)onAvatarPermissionChanged;
- (void)onSummaryStatusChanged:(ZMConfSession*)session;
- (void)onAllowRequestAICompanionChanged:(ZMConfSession*)session;
- (void)onMyPSLProducerStopped:(int)inReason;
- (void)onPSLVideoSendingInfoHeartBeat:(BOOL)result;

- (void)onExtendMeeting:(BOOL)result;
- (void)onCancelExtendMeeting:(BOOL)result;
- (void)extendStatusOnMMR:(BOOL)result;
- (void)onUserCount1To2Or2To1:(BOOL)result;

- (void)allowAttendeeRaiseHandStatusChanged:(ZMConfSession *)confSession;

- (void)onParticipantUserCountChanged;
- (void)onViewOnlyUserCountChanged;
@end


#endif /* ZMMTConfStatusProtocol_h */
