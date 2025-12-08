//
//  IZMMTPollingMgr.h
//  VideoUIBridge
//
//  Created by Carol.Li on 2024/3/26.
//

#ifndef IZMMTPollingMgr_h
#define IZMMTPollingMgr_h
@protocol IZMMTPollingMgr <ZMRoutableObject>
- (BOOL)hasPollCapability;
- (void)pollConflict:(BOOL)isConflict;
@end

#endif /* IZMMTPollingMgr_h */
