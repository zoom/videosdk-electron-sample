//
//  IZMMTSimuliveMgr.h
//  VideoUIBridge
//
//  Created by Carol.Li on 2024/10/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol  IZMMTSimuliveMgr <ZMRoutableObject>

- (ZMBubbleObject *)getNewSimuliveBubble;
- (BOOL)isSimuliveBubbleShowing;
- (void)closeSimuliveBubble;
- (NSString *)getCountDownString;
- (BOOL)isImmediateGoLive;

- (void)onSimuliveCountDownReminderStatusChanged:(CmmUInt32)reminder;
@end

NS_ASSUME_NONNULL_END
