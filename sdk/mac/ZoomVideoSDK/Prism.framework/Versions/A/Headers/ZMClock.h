//
//  ZMClock.h
//  zChatUI
//
//  Created by Huxley on 2018/4/28.
//  Copyright © 2018 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ZMClockWatcher <NSObject>

@optional
- (void)ticktack;//by seconds;

- (void)minuteChanged;
- (void)hourChanged;
- (void)dayChanged;

@end

@interface ZMClock : NSObject

+ (instancetype)sharedClock;

- (void)addWatcher:(id <ZMClockWatcher>)watcher;
- (void)removeWatcher:(id <ZMClockWatcher>)watcher;

@end
