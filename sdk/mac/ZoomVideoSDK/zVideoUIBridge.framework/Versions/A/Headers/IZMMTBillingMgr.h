//
//  IZMMTBillingMgr.h
//  VideoUIBridge
//
//  Created by Carol.Li on 2025/3/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ZMMTBillingViewPauseResumeTag) {
    ZMMTBillingViewPauseResumeTagNone,
    ZMMTBillingViewPauseResumeTagPause,
    ZMMTBillingViewPauseResumeTagResume,
};

typedef void(^ZMMTBillingAsyncSearchCompletionBlock)(NSArray<ZMBuddyAdapter *> *buddies);

@class ZMUser;
@class ZMBuddyAdapter;
@protocol IZMMTBillingMgr <NSObject>
@property (nonatomic, assign) BOOL startFromNow;  //from now or from meeting start
@property (nonatomic, assign) BOOL isInBillingStatus; //billing actived
@property (nonatomic, strong) ZMUser *billingUser; //real billto user
@property (nonatomic, copy) NSString *billToUserId; //billto userid
@property (nonatomic, nullable, strong) ZMBuddyAdapter *contactBuddy;
@property (nonatomic, nullable, strong) ZMUser *pendingUser; //selectUser without assign
@property (nonatomic, copy) NSString *pendingContactName; //real contactname from JID search
@property (nonatomic, assign) BOOL hasSelectUnknownContact;
@property (nonatomic, assign) BOOL hasFoundedContacts;
@property (nonatomic, assign) BOOL isBillingPaused;
@property (nonatomic, assign) BOOL isBillableHoursSelected;
@property (nonatomic, assign) BOOL hasNoAssignee; //for autobilling
@property (nonatomic, assign) BOOL isBillableInfoUploaded;
@property (nonatomic, copy) NSString *clientCode;
@property (nonatomic, copy) NSString *billingNotes;
@property (nonatomic, copy) NSString *billToName; //cannot get user
@property (nonatomic, copy) NSString *contactId;
@property (nonatomic, copy) void (^updateBilingBlock)(void);

- (BOOL)isMeetingBillableHoursEnabled;
- (void)showAssignBillingWindow;
- (void)startTimer;
- (NSString *)getBillingClockString;
- (void)showBillingEnabledTipWithUserName:(NSString *)name;
- (void)showContactWindowFromMeetingInfo:(BOOL)isFromMeetingInfo withFirstName:(NSString *)firstName lastName:(NSString *)lastName;
- (void)onPauseBillableHours;
- (void)onResumeBillableHours;
- (NSUInteger)getBillableHours;
- (void)onCreateContactResult:(BOOL)isOk andContactItem:(NSString *)name reqID:(NSString *)reqID;
- (void)onPersonalContactResponse:(NSString *)name result:(BOOL)result;

- (void)onConfRecennectStatusChanged;
- (void)resetBillingSelectStatusIfNeeded;
- (void)asynSearchLocalContactByUserName:(NSString *)userName callBackBlock:(ZMMTBillingAsyncSearchCompletionBlock)block;
@end

@protocol IZMMTBillingHoursSinkProtocol <NSObject>

- (void)onRcvContactStatusCheckRes:(BOOL)isMyContact jid:(NSString *)jid contactName:(NSString *)name;

@end
NS_ASSUME_NONNULL_END
