//
//  ZMMTConstants.h
//  zVideoUI
//
//  Created by francis zhuo on 5/19/20.
//  Copyright © 2020 zoom.us. All rights reserved.
//

#ifndef ZMMTConstants_h
#define ZMMTConstants_h

#import <ZoomKit/ZoomKit.h>
#import <Prism/Prism.h>

NS_ASSUME_NONNULL_BEGIN
@class ZMShareSource;

@protocol ZMMTTrackingViewDelegate <NSObject>
@optional
- (void)onMouseEntered:(nonnull NSView *)view;
- (void)onMouseMoved:(nonnull NSView *)view;
- (void)onMouseExited:(nonnull NSView *)view;
@end
NS_ASSUME_NONNULL_END

#import <zVideoUIBridge/ZMUIConstants.h>
NS_ASSUME_NONNULL_BEGIN
@class ZMUser;
@class ZMConfSession;
@protocol ZMMTForceUpdateProtocol<NSObject>
@optional
- (void)forceUpdateAllVideos:(ZMVideoUpdateStrategy)strategy;
- (void)forceUpdateVideo:(ZMVideoUpdateStrategy)strategy user:(ZMUser*)zmUser;

- (void)forceUpdateConference:(ZMConfUpdateStrategy)strategy user:(ZMUser*)zmUser;
- (void)forceUpdateConference:(ZMConfUpdateStrategy)strategy session:(ZMConfSession*)session;

@end
NS_ASSUME_NONNULL_END

static const ZMEventPriority ZMSessionLifeEventPriorityTransitionMgr = 0;
static const ZMEventPriority ZMSessionLifeEventPrioritySessionMgr = 1;

NS_ASSUME_NONNULL_BEGIN
@class ZMMTTransitionModel;
@protocol ZMMTSessionLifeProtocol<NSObject>
@optional
- (void)onSConfConnecting:(ZMConfSession*)session;
- (void)onSConfStart:(ZMConfSession*)session;
- (void)onSConfReady:(ZMConfSession*)session;

@optional
- (void)onSessionDidFailed:(ZMConfSession*)session;
- (void)onSessionDidStart:(ZMConfSession*)session;
- (void)onSessionWillLeave:(ZMConfSession*)session;
- (void)onSessionDidLeave:(ZMConfSession*)session;

@optional
- (void)onCurrentSessionChanged:(ZMConfSession*)session;
- (void)onCurrentSessionChanged:(ZMConfSession*)session detail:(ZMMTTransitionModel*)detail;
@end
NS_ASSUME_NONNULL_END

@protocol IZMMTRouterCenter <ZMRouterCenter>
@end
#define ZMMTRouterCenter (id<IZMMTRouterCenter>)[ZMRouterCenter.shared singletonForProtocol:@protocol(IZMMTRouterCenter)]
#define ZMMTSharedFor(P) ((id<P>)[ZMMTRouterCenter singletonForProtocol:@protocol(P)])
#define ZMMTEventPosterFor(P) ((id<P>)[ZMMTRouterCenter posterForProtocol:@protocol(P)])
#define ZMMTEventPosterV2(P,O) ((id<P>)[ZMMTRouterCenter posterForProtocol:@protocol(P) sender:nil object:O])
#endif /* ZMMTConstants_h */
