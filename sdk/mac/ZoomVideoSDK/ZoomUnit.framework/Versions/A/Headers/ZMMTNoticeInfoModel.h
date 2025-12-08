//
//  ZMMTNoticeInfoModel.h
//  ZoomUnit
//
//  Created by davies zhao on 2025/5/15.
//

#import <Foundation/Foundation.h>
#import <dataModule/zMeetingDataDef.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTNoticeInfoModel : NSObject
@property (nonatomic, copy) NSString *noticeId;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *descriptionString;
@property (nonatomic, copy) NSString *btnText;
@property (nonatomic, assign) BOOL hasURL;
@property (nonatomic, copy) NSString *btnURL;

@property (nonatomic, copy) NSString *secBtnText;
@property (nonatomic, copy) NSString *secBtnURL;

- (instancetype)initWithMTNoticeInfo:(NS_ZOOM_DATA::UnLimitedMeetingNoticeInfo &)noticeInfo;


@end

NS_ASSUME_NONNULL_END
