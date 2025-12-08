//
//  IZMLeaveMeetingMgr.h
//  VideoUIBridge
//
//  Created by Molay.Yu on 2023/12/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class ZMLeaveMeetingWindow;
@protocol IZMLeaveMeetingMgr <ZMRoutableObject>

- (void)leaveWithoutComfirm:(BOOL)withFeedback;
- (void)endMeeting;
- (void)startDebrief;
- (void)leaveMeetingWindowDidEndButtonAction:(ZMLeaveMeetingWindow *)window;

@end

NS_ASSUME_NONNULL_END
