//
//  ZMMTCallCenter.h
//  VideoUIBridge
//
//  Created by Francis Zhuo on 1/4/23.
//

#import <zVideoUIBridge/ZMBaseHelper.h>
#import <zVideoUIBridge/ZMUser.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTCallCenter : ZMBaseHelper
@property (nonatomic, retain) ZMMTDelayCall* userRosterChangedCall;
@property (nonatomic, retain) ZMMTDelayCall* userKBRosterChangedCall;

@property (nonatomic, retain) ZMMTCoalesceCall<ZMUser*>* audioStatusChangedCall;
@property (nonatomic, retain) ZMMTDelayCall* activeAudioChangedCall;

@property (nonatomic, retain) ZMMTCoalesceCall<ZMUser*>* videoStatusChangedCall;
@property (nonatomic, retain) ZMMTAsyncCall<ZMUser*>* activeVideoChangedCall;
@property (nonatomic, retain) ZMMTAsyncCall<ZMUser*>* activeDeckVideoChangedCall;

@property (nonatomic, retain) ZMMTCoalesceCall<ZMUser*>* userJoinCall;
@property (nonatomic, retain) ZMMTCoalesceCall<ZMUser*>* userLeftCall;

@property (nonatomic, retain) ZMMTCoalesceCall<ZMUser*>* userNameChangedCall;
@property (nonatomic, retain) ZMMTCoalesceCall<ZMUser*>* userNameTagChangedCall;
@property (nonatomic, retain) ZMMTCoalesceCall<ZMUser*>* userAvatarChangedCall;

@property (nonatomic, retain) ZMMTCoalesceCall<ZMUser*>* userHandStatusChangedCall;
@property (nonatomic, retain) ZMMTCoalesceCall<ZMUser*>* attendeeHandStatusChangedCall;
@property (nonatomic, retain) ZMMTCoalesceCall<ZMUser*>* feedbackChangedCall;

@property (nonatomic, retain) ZMMTDelayCall* attendeeListChangedCall;

- (void)forceUpdateVideo:(ZMVideoUpdateStrategy)strategy user:(ZMUser*)zmUser;
- (void)forceUpdateAllVideos:(ZMVideoUpdateStrategy)strategy;
- (void)forceUpdateConference:(ZMConfUpdateStrategy)strategy user:(ZMUser*)zmUser;
- (void)forceUpdateConference:(ZMConfUpdateStrategy)strategy;
@end

NS_ASSUME_NONNULL_END
