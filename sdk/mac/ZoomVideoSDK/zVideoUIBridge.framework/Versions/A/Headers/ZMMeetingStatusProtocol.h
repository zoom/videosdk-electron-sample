//
//  ZMMeetingStatusProtocol.h
//  VideoUIBridge
//
//  Created by martin yu on 2025/4/8.
//

#ifndef ZMMeetingStatusProtocol_h
#define ZMMeetingStatusProtocol_h

#import <zVideoUIBridge/ZMConfSession.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMMeetingStatusProtocol <NSObject>
@optional
/// Waiting Room
/// - Parameter isInSilentMode: If isInSilentMode is YES, means user goes to the waiting room
- (void)onMeetingSilentModeChanged:(BOOL)isInSilentMode;
/// Transition
/// - Parameter session: If session.isTransitionSession is YES, means user starts to join/switching/leave BO.
- (void)onMeetingCurrentSessionChanged:(ZMConfSession *)session;
/// Leave Meeting
/// - Parameter leaveReason: see CMM_ENDMEETING_REASON enum.
- (void)onMeetingWillLeave:(int)leaveReason;
/// Meeting AIC Status change
/// - Parameter enable: AIC enable flag.
/// - Parameter session: If session.isTransitionSession is YES, means user starts to join/switching/leave BO.
- (void)onMeetingAICStatusChange:(BOOL)enable confSession:(ZMConfSession *)confSession;
@end

NS_ASSUME_NONNULL_END

#endif /* ZMMeetingStatusProtocol_h */
