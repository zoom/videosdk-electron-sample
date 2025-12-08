//
//  ZMSipCallProtocol.h
//  zChatComponent
//
//  Created by groot.ding on 6/29/23.
//

#ifndef ZMSipCallProtocol_h
#define ZMSipCallProtocol_h

#import <ZoomUnit/ZMSipContactItemProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMBuddyAdapter;
@class ZMSipCloudPBX;

@protocol ZMSipCallWarningProtocol <ZMRoutableObject>

- (BOOL)try2ShowDlgBeforeEnterMeeting:(id)pDelegate andCallBack:(NSString*)strCallBack andParam:(id)idParam andIsJoinMeeting:(BOOL)isJoinMeeting;

- (BOOL)try2ShowDlgBeforeEnterMeeting:(id)pDelegate andCallBack:(NSString*)strCallBack andParam:(id)idParam;

- (BOOL)try2ShowDlgBeforeEnterMeeting:(id)deleagte userJID:(NSString*)jid openVideo:(BOOL)open;

- (BOOL)try2ShowDlgBeforeEnterMeeting:(id)pDelegate andCallBack:(NSString*)strCallBack andCancelCallBack:(NSString*)strCancelCallBack andParam:(id)idParam andIsJoinMeeting:(BOOL)isJoinMeeting;

- (void)closeWhenDelegateRelease:(id)privateDelegate;

- (void)closeWhenMeetingDeleted:(id)privateDelegate andMeetingNum:(long long)meetingNum;

@end

@protocol ZMSipCallExternalVoicemailAPIProtocol <NSObject>

- (void)updateUIWithCallID:(nonnull NSString *)callID;

@end

@protocol ZMSipCallExternalVoicemailEventProtocol <NSObject>

- (void)onExternalVoicemailChangedToInvalidWithCallIDs:(nonnull NSArray<NSString *> *)callIDs;

- (void)onExternalVoicemailUpdatedWithCallIDs:(nullable NSArray<NSString *> *)callIDs;

@end

@protocol IZMCallUpgradeDialogMgr <ZMRoutableObject>

- (NSUInteger)meetingCountBeforeShowUpgradeDialog;
- (void)addMeetingCount;

@end

@protocol ZMSipCallProtocol <ZMRoutableObject>

@optional
- (BOOL)hasSipCall;

@required

@property (nonatomic, readonly, nullable) id<IZMCallUpgradeDialogMgr> callUpgradeDialogMgr;

- (BOOL)isSIPFeatureEnabled;

- (BOOL)checkPhoneTabIsVisible;

- (BOOL)isInCallWithAdapter:(ZMBuddyAdapter *)buddy;

- (BOOL)isInCallWithNumber:(NSString *)number;

- (BOOL)isCloudPBXEnable;
// for CloudPBX
- (BOOL)isAllowCallForMac;

- (BOOL)isAvayaEnabled;

- (BOOL)isMitelEnabled;

- (BOOL)isCallPSTNEnable;

- (ZMSipCloudPBX*)getMyPBXConfig;

- (BOOL)try2callPeer:(NSString*)number peerName:(NSString*)peerName numberType:(int)numberType;

- (void)navigate2SipTab;

- (BOOL)isInSIPCall;

- (BOOL)isInCCIAudio;

- (BOOL)hasCallingoutCall;

- (BOOL)hasIncomingCall;

- (BOOL)hasIncomingOrInCall;

- (BOOL)isEnableSMS;

- (BOOL)isVipSLAExecutiveEnable;

- (BOOL)isVipSLAEnable;

- (BOOL)isTransfering;

- (BOOL)isWarmTransfering;

- (BOOL)isEnableCallTransfer;

- (BOOL)isInServerConferenceCall;

- (NSInteger)getSipCallCount;

- (NSString*)getTransferCallID;

- (BOOL)isHideCallButtonInIM:(ZMBuddyAdapter *)useradapter;

- (BOOL)isCallButtonEnable:(ZMBuddyAdapter *)useradapter;

- (id <ZMSipContactItem>)getSipContactByID:(NSString *)cloudID;

- (void)selectedSessionWithToNumber:(NSString *)toNumber toName:(NSString *)toName;

- (void)transferCall:(NSString*)callID peerUri:(NSString*)peerUri warmTransfer:(int)transferType andNumberType:(int)type name:(NSString*)name jID:(NSString*)jID;

- (BOOL)isNewCallLogEnable;

- (NSString *)isLinkedOrganization:(NSString *)paId;

- (void)requestUpdateHideZRAOption:(BOOL)isOpen;

- (void)handlePhoneDeepLinkWithParams:(NSDictionary <NSString *, NSString *> *)params;

- (BOOL)isBillingFeatureEnable;

- (nullable __kindof NSView<ZMSipCallExternalVoicemailAPIProtocol> *)voicemailConciseCardWithCallID:(nonnull NSString *)callID;

- (nullable NSView *)voicemailConciseCardLoadingView;

- (void)toResponsedKeyDownClickedWhileInDTMF:(NSEvent *)keyEvent;

- (BOOL)isPlayAudioFile;

- (void)pausePlayAudioAndUpdateUI;

- (BOOL)isInIPPhoneCall;

- (void)try2SyncMuteStatus2zzHostDevice;

- (void)unholdActiveCall;

- (BOOL)isPhoneAudioEnable;

- (void)muteCall:(BOOL)isMute;

- (void)acceptFromRevolabsDevice;

- (void)declineFromRevolabsDevice;

- (void)holdActiveCall:(BOOL)bPhoneAction;

- (void)syncDeviceStatusToPhone;
@end

NS_ASSUME_NONNULL_END

#endif /* ZMSipCallProtocol_h */
