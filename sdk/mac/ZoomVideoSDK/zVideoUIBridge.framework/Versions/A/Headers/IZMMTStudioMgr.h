//
//  IZMMTStudioMgr.h
//  VideoUIBridge
//
//  Created by geno.chen on 2022/11/13.
//

#ifndef IZMMTStudioMgr_h
#define IZMMTStudioMgr_h

#import <zVideoUIBridge/ZMMTBaseViewController.h>

@class ZMMTProductionStudioViewController;
@class ZMMTStudioScene;

@protocol IZMMTStudioMgr <NSObject>

@optional
- (nullable ZMMTProductionStudioViewController *)newViewControllerWithType:(ZMMTType)type;
- (BOOL)isStudioWindowShowing;
- (void)openStudioWindow;
- (void)closeStudioWindow;
- (void)stopLiving;
- (BOOL)isStudioLivingForHostCohost;
- (BOOL)isSendingLiveByMe;
- (void)startPumpPureVideoForProducer;
- (void)stopPumpPureVideoForProducer;
- (void)updatePrivateShareReceiver;

- (void)onPSLMixShareInfoChangedWithSourceID:(ZMShareSourceID)shareSourceID rect:(NSRect)rect;
- (void)onPSLInviteRequested:(BOOL)isSuccess message:(NSString *_Nullable)errorMessage;
- (void)onPSLLiveLayoutChanged:(CMM_USERID)sender_id layout:(const CmmPSLLayout&)layout;
- (void)onPSLControlCommandChanged:(const CmmRSGWControlData&)data;
- (ZMMTStudioScene *)getLiveScene;
@end

#endif /* IZMMTStudioMgr_h */
