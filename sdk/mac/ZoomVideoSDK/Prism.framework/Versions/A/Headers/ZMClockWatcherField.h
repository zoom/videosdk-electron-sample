//
//  ZMClockWatcherField.h
//  zChatUI
//
//  Created by Huxley on 2018/4/28.
//  Copyright © 2018 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class ZMClockWatcherField;
typedef void (^ZMClockWatcherFieldHandler)(ZMClockWatcherField *sender, NSDate *current);

@interface ZMClockWatcherField : NSTextField

@property (copy, nonatomic) ZMClockWatcherFieldHandler tickSeconds;
@property (copy, nonatomic) ZMClockWatcherFieldHandler tickMinutes;

@property (copy, nonatomic) NSDate *informativeDate;

@end
