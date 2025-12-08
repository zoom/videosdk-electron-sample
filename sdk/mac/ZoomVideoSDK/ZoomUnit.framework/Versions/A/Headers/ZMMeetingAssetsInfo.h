//
//  ZMMeetingAssetsInfo.h
//  ZoomUnit
//
//  Created by davies zhao on 2024/8/29.
//

#import <Foundation/Foundation.h>
#import <commonDef/CmmCommonStruct.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMeetingAssetsInfo : NSObject
@property (nonatomic, assign) NSInteger dataAssets;
@property (nonatomic, copy) NSString *meetingChannelID;
@property (nonatomic, copy) NSString *cmcChannelID;
@property (nonatomic, assign) NSInteger meetingNum;
@property (nonatomic, assign) NSInteger occurrenceTime;
@property (nonatomic, copy) NSString *meetingMasterEventID;
@property (nonatomic, assign) BOOL amIHost;
@property (nonatomic, assign) NSInteger leaveReason;
@property (nonatomic, assign) BOOL isWebinar;
@property (nonatomic, assign) BOOL isBillableEnabled;
@property (nonatomic, assign) BOOL isBillableInfoUploaded;

@property (nonatomic, assign) MeetingAssetsInfo assetsInfo;
@property (nonatomic, assign) MeetingInviteesInfo inviteesInfo;
@property (nonatomic, copy) NSString *meetingTopic;


@end

NS_ASSUME_NONNULL_END
