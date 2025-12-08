//
//  ZMDatePicker.h
//  SaasBeePTUIModule
//
//  Created by Deal Shao on 1/21/13.
//  Copyright (c) 2013 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <ZoomUnit/ZMCalendarWindowController.h>


@interface ZMDatePicker : NSDatePicker{
    ZMCalendarWindowController* _calendarWindowController;
}

- (void)cleanUp;

- (void)showCalendarWindowAtPoint:(CGPoint)point
                    commitOnClose:(BOOL)commitOnClose
            withCompletionHandler:(void (^)(NSDate *selectedDate))completionHandler;
- (void)showCalendarWindowAtPoint:(CGPoint)point withCompletionHandler:(void (^)(NSDate *selectedDate))completionHandler;
- (void)showCalendarWindow;

@end

