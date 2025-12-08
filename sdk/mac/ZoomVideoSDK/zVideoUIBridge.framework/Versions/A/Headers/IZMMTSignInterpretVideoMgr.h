//
//  IZMMTSignInterpretVideoMgr.h
//  VideoUIBridge
//
//  Created by martin.yu on 10/7/22.
//

#ifndef IZMMTSignInterpretVideoMgr_h
#define IZMMTSignInterpretVideoMgr_h

@protocol IZMMTSignInterpretVideoMgr <ZMRoutableObject>

- (void)updateVideoUsers;
- (void)destroyAllRenders;

@end

#endif /* IZMMTSignInterpretVideoMgr */
