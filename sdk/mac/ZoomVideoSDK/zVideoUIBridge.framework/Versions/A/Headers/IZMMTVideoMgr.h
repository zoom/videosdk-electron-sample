//
//  IZMMTVideoMgr.h
//  VideoUI
//
//  Created by Francis Zhuo on 10/14/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, ZMVideoCutoutType){
    ZMVideoCutoutType_None = 0,
    ZMVideoCutoutType_Immersive         = 1ll<<1,
    ZMVideoCutoutType_Zapp_Plugin       = 1ll<<2,
    ZMVideoCutoutType_PresenterLayout   = 1ll<<3,
    ZMVideoCutoutType_SendingShare      = 1ll<<4,
    ZMVideoCutoutType_SendingDocShare   = 1ll<<5,
};

typedef NS_OPTIONS(NSUInteger, ZMVideoMirrorType){
    ZMVideoMirrorType_None              = 0,
    ZMVideoMirrorType_PresenterLayout   = 1ll<<1,
    ZMVideoMirrorType_SendingShare      = 1ll<<2,
    ZMVideoMirrorType_SendingDocShare   = 1ll<<3,
};

typedef NS_OPTIONS(NSUInteger, ZMVideoAlphaMaskType){
    ZMVideoAlphaMaskType_None           = 0,
    ZMVideoAlphaMaskType_PresenterLayout= 1ll<<1,
    ZMVideoAlphaMaskType_SendingShare   = 1ll<<2,
    ZMVideoAlphaMaskType_GalleryPlus    = 1ll<<3,
    ZMVideoAlphaMaskType_Immersive      = 1ll<<4,
    ZMVideoAlphaMaskType_SendingDocShare= 1ll<<5,
    ZMVideoAlphaMaskType_Zapp_Plugin    = 1ll<<6,
};

@protocol IZMMTVideoMgr <NSObject>
- (void)onAutoStartVideo:(NSInteger)ret session:(ZMConfSession*)session;
- (void)onEnableVBFailed:(ZMConfSession*)session;

- (void)onSendVideoPrivilegeChange;//ZOOM-82229
- (void)onReceiveVideoPrivilegeChange;//ZOOM-82229

- (void)onHostChangedWithUser:(ZMUser*)zmUser;
- (void)onCoHostChangedWithUser:(ZMUser*)zmUser;
- (void)onFocusModeStatusChanged:(ZMConfSession*)session;
- (void)onFocusModeEnding:(ZMConfSession*)session;
- (void)onFocusModeWhiteListChanged:(ZMConfSession*)session;
- (void)resetFocusModeWhiteList:(ZMConfSession*)session;

- (void)onVideoSizeChanged:(ZMUser *)zmUser;

- (BOOL)isMyVideoTurnOn;
- (BOOL)isSupportSmartVirtualBackground;

// Immersive
- (BOOL)isVideoCutout;
- (BOOL)setPortraitRect:(NSRect)rect renderHandle:(void *)handle;
- (void)setVideoReplaceEnabled:(BOOL)enabled;
- (void)setVideoCutoutEnabled:(BOOL)enabled forType:(ZMVideoCutoutType)type;
- (void)setVideoPickColorEnabled:(BOOL)enabled;
- (void)setVideoMirrorDisable:(BOOL)disable forType:(ZMVideoMirrorType)type;
- (BOOL)isVideoMirrorDisable;
- (void)setVideoAlphaMaskEnabled:(BOOL)enable forType:(ZMVideoAlphaMaskType)type;
- (BOOL)isVideoEnableAlphaMask;

- (void)onMyVideoDevideRunStarted:(/*CMM_MY_VIDEO_RUN_TYPE*/NSInteger)runType;
@end

NS_ASSUME_NONNULL_END
