//
//  IZMRecordMgr.h
//  VideoUIBridge
//
//  Created by geno.chen on 2022/11/13.
//

#ifndef IZMRecordMgr_h
#define IZMRecordMgr_h

#define kRecordingResourceInvalidIndex  SSB_MC_IMMERSIVE_RECODING_RESOURCE_INDEX_BASE+999

@class ZMUser;

@protocol IZMRecordMgr <NSObject>

@optional
- (void)updateBacksplashIfNeeds:(BOOL)isStart;
- (void)setNeedUpdateRecordContent:(BOOL)needUpdate;

- (void)confirmToStartCMR;
- (void)confirmToStartCMRWithExpectedZRAValue:(NSNumber *)expectedZRAValue;
- (void)confirmToStartLocalRecord;
- (void)checkDocsAndWhiteboardCapture;

//MARK: Smart Recording

- (void)startCMRWithAICompanion;
- (void)onCMRSettingOptionChanged;
- (void)requestCMR;
- (void)requestLocalRecord;
- (void)requestEnableSmartRecording;
- (void)onRequestCMREnableStatusChanged;
- (void)onSmartRecordingStatusChanged;
- (void)startCMRWithAICompanion:(NSString *)reqID sender:(ZMUserID)senderId;
- (void)closeRecordingAlertIfNeed;

//callback
- (void)onStartCMRRequestReceived:(NSString *)reqID sender:(ZMUserID)senderId;
- (void)onStartCMRRequestResponseReceived:(BOOL)bTimeOut decline:(BOOL)bDecline;
- (void)onEnableSmartRecordingResult:(BOOL)succ error:(long long)error_code;

//ZOOM-773690
- (void)onCMRControlFlagChanged:(ZMUser *)user;

- (void)userVideoStatusChangedNotification:(ZMUser *)zmUser;

@end


#endif /* IZMRecordMgr_h */
