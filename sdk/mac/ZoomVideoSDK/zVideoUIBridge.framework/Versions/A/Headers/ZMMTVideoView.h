//
//  ZMMTVideoView.h
//  zVideoUI
//
//  Created by Francis Zhuo on 9/2/20.
//  Copyright © 2020 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMMTBaseView.h>
#import <zVideoUIBridge/ZMMTConstants.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMConfSession;
@class ZMUser;

@protocol ZMMTVideoView<ZMMTForceUpdateProtocol>
@property(weak) ZMConfSession* confSession;
- (void)cleanUp;

- (BOOL)isVideoShowing;
- (void)stopVideo;
- (void)startVideo;

- (void)lockVideo;
- (void)unlockVideo;
- (void)destroyRender;

- (void)relayoutUI;

- (void)updateActiveVideoView:(ZMUser*)zmUser;
@end

@interface ZMMTVideoView : ZMMTBaseView<ZMMTVideoView>
@property(assign) BOOL isVideoShowing;
@end

NS_ASSUME_NONNULL_END
