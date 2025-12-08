//
//  ZMMTVideoViewController.h
//  zVideoUI
//
//  Created by Francis Zhuo on 9/2/20.
//  Copyright © 2020 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMMTVideoView.h>
#import <zVideoUIBridge/ZMMTBaseViewController.h>

NS_ASSUME_NONNULL_BEGIN
@class ZMMTVideoViewController;
@protocol ZMMTVideoViewControllerDelegate <NSObject>
@optional
- (void)onVideoViewWillStartVideo:(ZMMTVideoViewController*)viewController;
- (void)onVideoViewDidStartVideo:(ZMMTVideoViewController*)viewController;
- (void)onVideoViewWillStopVideo:(ZMMTVideoViewController*)viewController;
- (void)onVideoViewDidStopVideo:(ZMMTVideoViewController*)viewController;

@end

@class ZMConfSession;
@interface ZMMTVideoViewController : ZMMTBaseViewController<ZMMTForceUpdateProtocol>
@property(weak) id<ZMMTVideoViewControllerDelegate> delegate;
@property(weak) ZMConfSession* confSession;
- (void)cleanUp;

- (BOOL)isVideoShowing;
- (void)stopVideo;
- (void)startVideo;

- (void)lockVideo;
- (void)unlockVideo;
- (void)destroyRender;

- (void)updateActiveVideoView:(ZMUser*)zmUser;

- (nullable NSArray*)getVideoArrayForRecording;//for override

#pragma mark - videoViewLifeCycle
- (void)videoViewWillStartVideo;//for override
- (void)videoViewDidStartVideo;//for override
- (void)videoViewWillStopVideo;//for override
- (void)videoViewDidStopVideo;//for override
@end

NS_ASSUME_NONNULL_END
