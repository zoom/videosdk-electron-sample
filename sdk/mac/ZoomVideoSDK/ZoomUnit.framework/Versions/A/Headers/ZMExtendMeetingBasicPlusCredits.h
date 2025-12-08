//
//  ZMExtendMeetingBasicPlusCredits.h
//  ZoomUnit
//
//  Created by davies zhao on 2023/7/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMExtendMeetingBasicPlusCredits : NSObject
@property (nonatomic, assign) NSInteger total;
@property (nonatomic, assign) NSInteger unused;
@property (nonatomic, copy,nullable) NSString *creditsEffectTime;
@property (nonatomic, assign) NSInteger duration;
@property (nonatomic, copy,nullable) NSString *upgradeUrl;
@end

NS_ASSUME_NONNULL_END
