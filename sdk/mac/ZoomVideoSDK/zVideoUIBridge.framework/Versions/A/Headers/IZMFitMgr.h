//
//  IZMFitMgr.h
//  VideoUI
//
//  Created by martin.yu on 9/13/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef IZMFitMgr_h
#define IZMFitMgr_h

NS_ASSUME_NONNULL_BEGIN

@protocol IZMFitMgr <ZMRoutableObject>
- (void)updateAudio;
- (void)updateInterpretationButton;
- (void)setRemainTime:(int)inTime;
- (void)updateRemainTimeView;
- (void)updateQA;
- (void)updateRoomControllerButton;

// ToolSuite
- (void)showToolbarWindow;
- (void)hideToolbarWindow;
@end

NS_ASSUME_NONNULL_END

#endif /* IZMFitMgr_h */
