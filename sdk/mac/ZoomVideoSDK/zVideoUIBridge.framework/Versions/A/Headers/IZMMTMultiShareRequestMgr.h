//
//  IZMMTMultiShareRequestMgr.h
//  VideoUIBridge
//
//  Created by Molay.Yu on 2024/5/23.
//

#ifndef IZMMTMultiShareRequestMgr_h
#define IZMMTMultiShareRequestMgr_h

@class ZMUser;

@protocol IZMMTMultiShareRequestMgr <ZMRoutableObject>

- (BOOL)canShowPromoteMutiShareAlert;
- (BOOL)canShowPromoteMutiShareAlertWhenShareMultiObjOn;
- (void)showPromoteMultiShareAlertWithAllowAction:(dispatch_block_t _Nullable)allowAction
                                    replaceAction:(dispatch_block_t _Nullable)replaceAction
                                     cancelAction:(dispatch_block_t _Nullable)cancelAction;

- (void)onReceiveEnableMultiShareRequestMsg:(NSString * _Nonnull)requestID user:(ZMUser * _Nullable)user;
- (void)onReceiveEnableMultiShareResponseMsg:(CmmEnableMultiShareResponseStatus)status;
- (void)closeAllAlerts;

@end

#endif /* IZMMTMultiShareRequestMgr_h */
