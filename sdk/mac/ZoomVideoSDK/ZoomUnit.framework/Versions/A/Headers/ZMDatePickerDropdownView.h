//
//  ZMDatePickerDropdownView.h
//  ZoomUnit
//
//

#import <ZoomUnit/ZMDatePicker.h>
#import <ZoomUnit/ZoomUnit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMDatePickerDropdownView : ZMBaseView
+ (ZMDatePickerDropdownView*)datePickerForCalendarDays;
+ (ZMDatePickerDropdownView*)datePickerForHoursMinutes;
@property(nonatomic, retain,nullable) ZMDatePicker* datePicker;
@property(nonatomic, copy) void (^onDateValueChanged)(ZMDatePickerDropdownView* picker);
//the interval, in minutes, for the time picker dropdown menu (e.g. 15 == 10:00, 10:15, 10:30, etc.)
@property(nonatomic, assign) NSInteger minuteInterval;
@end

NS_ASSUME_NONNULL_END
