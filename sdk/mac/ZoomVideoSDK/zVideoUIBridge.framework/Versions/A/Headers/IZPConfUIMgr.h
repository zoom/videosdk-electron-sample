//
//  IZPConfUIMgr.h
//  VideoUI
//
//  Created by martin.yu on 9/15/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef IZPConfUIMgr_h
#define IZPConfUIMgr_h

typedef NS_ENUM(NSUInteger, ZMMTLeaveMeetingAction) {
    ZMMTLeaveMeetingActionCancel,
    ZMMTLeaveMeetingActionLeave,
};

@class ZMToast;

NS_ASSUME_NONNULL_BEGIN

typedef void (^ZMMTLeaveMeetingCompletion)(ZMMTLeaveMeetingAction action);

@protocol IZPConfUIMgr <ZMRoutableObject>
@property (nonatomic, readonly, assign) BOOL isConfReady;

- (void)startSendingShareForType:(NSInteger)type; //ZMSendingShareType

- (void)askConfLeaveWithConfirm:(BOOL)confirm completion:(ZMMTLeaveMeetingCompletion)completion;

- (void)addToast:(ZMToast *)toast;
- (void)removeToast:(ZMToast *)toast;
- (nullable ZMToast *)fetchToastWithIdentifier:(NSString *)identifier;

- (__kindof NSWindow *)confWindow;

@end

NS_ASSUME_NONNULL_END

#endif /* IZPConfUIMgr_h */
