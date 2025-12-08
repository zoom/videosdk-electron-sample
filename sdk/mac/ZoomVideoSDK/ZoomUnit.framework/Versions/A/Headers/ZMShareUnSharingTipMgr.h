//
//  ZMShareUnSharingTipMgr.h
//  zVideoUI
//
//  Created by walt.li on 9/1/20.
//  Copyright © 2020 zoom.us. All rights reserved.
//


@class ZMSharePaddingMgr;

@interface ZMShareUnSharingTipMgr : NSObject

- (instancetype)initWithPaddingMgr:(ZMSharePaddingMgr *)paddingMgr;
- (void)showTipWindowWithSharedScreen:(NSScreen *)screen windowID:(CGWindowID)windowID;
- (void)hideTipWindow;
- (void)cleanUp;
@end

