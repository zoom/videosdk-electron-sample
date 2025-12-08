//
//  ZMMTShareStatusProtocol.h
//  VideoUIBridge
//
//  Created by geno.chen on 2022/8/19.
//

#ifndef ZMMTShareStatusProtocol_h
#define ZMMTShareStatusProtocol_h

@class ZMShareSource;
@class ZMSharePort;
@protocol ZMMTShareStatusProtocol <NSObject>
@optional
- (void)userStartSharing:(ZMShareSource *)shareSource;
- (void)userStopSharing:(ZMShareSource *)shareSource;
- (void)onStartSendShare;
- (void)onStopSendShare;
- (void)onUpdateSendShare;
- (void)onWillResumeShare;
- (void)onShareResumed;
- (void)onSharePausedWithReason:(NSInteger)reason;
- (void)shareOptionChanged:(BOOL)videoShare
                audioShare:(BOOL)audioShare
                   boShare:(BOOL)boShare;

- (void)stopShareRequestReceived:(ZMConfSession *)confSession;

- (void)selfWillStartSharing;

- (void)onAudioShareModeChanged;

- (void)onRemoteControlStatusChanged;

- (void)onShareRenderRectChanged:(ZMShareSource *)shareSource;

//normal share + audio
- (void)onAudioShareStatusChanged:(ZMShareSource *)shareSource;

//ZMConfUpdateStrategy_New_Share_Source_Received
- (void)onNewShareSourceReceived:(ZMShareSource *)shareSource;

//ZMConfUpdateStrategy_Share_Source_Changed
- (void)onShareSourceChanged:(ZMShareSource *)shareSource;

//ZMConfUpdateStrategy_Share_Content_Received
- (void)onShareSourceReceivingStatusBecomeActive:(ZMShareSource *)shareSource;

//ZMConfUpdateStrategy_Share_Content_First_Frame_Received
- (void)onShareSourceFirstFrameRendered:(ZMShareSource *)shareSource;
- (void)onShareRenderFirstFrameReceived:(void *)renderHandle;
- (void)onShareRenderFrameSizeChanged:(void *)renderHandle;

- (void)onShareSourceVideoSharingPropertyChanged:(ZMShareSource *)shareSource
                                       isEnabled:(BOOL)isEnabled;

//mask share content
- (void)onMaskShareContentStatusChanged:(ZMSharePort *)sharePort
                                 masked:(BOOL)masked;

// on share zoom windows options changed
- (void)onShareZoomWindowsStatusChanged:(ZMConfSession *)confSession;

@end



#endif /* ZMMTShareStatusProtocol_h */
