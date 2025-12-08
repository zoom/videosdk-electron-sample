//
//  NSDate+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/12.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDate (ZoomKit)

@property (readonly, nonatomic, getter=isToday) BOOL today;
@property (readonly, nonatomic, getter=isTomorrow) BOOL tomorrow;
@property (readonly, nonatomic, getter=isYesterday) BOOL yesterday;
@property (readonly, nonatomic, getter=isThisYear) BOOL  thisYear;
@property (readonly, nonatomic, getter=isThisWeek) BOOL  thisWeek;
@property (readonly, nonatomic) NSInteger daysLeft;
@property (readonly, nonatomic) NSInteger minutesLeft;
@property (readonly, nonatomic) NSString *zmFormattedDateString;
@property (readonly, nonatomic) NSString *zmFormattedTimeString;
@property (readonly, nonatomic) NSString *zmFormattedOptionalSecondsTimeString;
@property (readonly, nonatomic) NSString *zmFormattedDateAndTimeString;
@property (readonly, nonatomic) NSString *zmFormattedFullDateAndTimeString;
@property (readonly, nonatomic) NSString *zmFormattedFullWeekDateAndTimeString;
@property (readonly, nonatomic) NSString *zmFormattedFullDateString;
@property (readonly, nonatomic) NSString *zmFormattedMMddString;
@property (readonly, nonatomic) NSString *zmFormattedModifyTimeString;

- (NSInteger)year;
- (NSInteger)month;
- (NSInteger)day;
- (NSInteger)hour;//24 hours format.
- (NSInteger)minute;
- (NSInteger)second;
- (NSInteger)weekday;
- (BOOL)isSameDayWithDate:(NSDate*)theDate;
- (NSDate *)getSameDayZeroHour:(NSDate *)theDate;
- (NSInteger)howManyDaysFromToday;
- (NSString *)formattedDateStringWith:(NSString *)format;

- (BOOL)sameDayWith:(NSDate *)theDate;

+ (NSDate*)dateWithYear:(NSInteger)year month:(NSInteger)month day:(NSInteger)day;

+ (NSInteger)daysBetweenDate:(NSDate *)fromDateTime andDate:(NSDate *)toDateTime;

+ (BOOL)currentTimeInScheduleTime:(NSInteger)hour startMin:(NSInteger)startM endHour:(NSInteger)endH endMin:(NSInteger)endM;//for chat settings

@end

NS_ASSUME_NONNULL_END
