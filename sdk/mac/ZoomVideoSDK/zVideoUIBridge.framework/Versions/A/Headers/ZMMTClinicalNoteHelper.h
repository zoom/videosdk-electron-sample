//
//  ZMMTClinicalNoteHelper.h
//  VideoUIBridge
//
//  Created by Karen Cao on 12/10/24.
//

#import <zVideoUIBridge/ZMBaseHelper.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMClinicalNoteStatus) {
    ZMClinicalNoteStatusNone = 0,
    ZMClinicalNoteStatusStop,
    ZMClinicalNoteStatusStart,
    ZMClinicalNoteStatusPause,
    ZMClinicalNoteStatusPending,
    ZMClinicalNoteStatusTimeout,
};

typedef NS_ENUM(NSUInteger, ZMClinicalNoteStopReason) {
    ZMClinicalNoteStopReasonNone = 0,
    ZMClinicalNoteStopReasonUserCancel,
    ZMClinicalNoteStopReasonUserStop,
    ZMClinicalNoteStopReasonStartTimeout,
    ZMClinicalNoteStopReasonStreamCancel,
};

@interface ZMMTClinicalNoteHelper : ZMBaseHelper
- (BOOL)canSeeEntryButton;
- (BOOL)changeClinicalNoteStatus:(ZMClinicalNoteStatus)newStatus withInstanceId:(NSUInteger)instanceId stopReason:(ZMClinicalNoteStopReason)stopReason;
- (BOOL)requestToSwitchClinicalNote:(NSInteger)switchAction;
- (BOOL)respondToSwitchClinicalNote:(NSString *)req_id requestUserId:(ZMUserID)req_user_id switchAction:(NSInteger)switchAction isDecline:(BOOL)is_decline;
- (BOOL)isClinicalNoteStarted;
- (BOOL)isClinicalNotePaused;
- (BOOL)isClinicalNoteStopped;
- (BOOL)isClinicalNotePending;
- (BOOL)isClinicalNoteNone;
- (BOOL)isClinicalNoteTimeout;
- (BOOL)needShowOptionMenu;
- (ZMClinicalNoteStatus)getClinicalNoteStatus:(NSUInteger)instanceId;
- (NSUInteger)getClinicalNoteInstanceId;
- (NSString*)getClinicalNoteSessionId;
- (NSString*)getPatientDataBoardUrl;
- (NSString*)getClinicalNoteIndicatorId;
- (BOOL)isClinicalNoteIndicator:(NSString*)tabId;
- (BOOL)canShowFooterButton;
- (BOOL)getUserInfoMeetingToken:(NSString *)reqId;

@end

NS_ASSUME_NONNULL_END
