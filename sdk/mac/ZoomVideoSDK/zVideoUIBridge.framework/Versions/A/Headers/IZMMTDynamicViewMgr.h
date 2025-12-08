//
//  IZMMTDynamicViewMgr.h
//  VideoUIBridge
//
//  Created by Amanda Souriyamath on 1/4/24.
//

#ifndef IZMMTDynamicViewMgr_h
#define IZMMTDynamicViewMgr_h

@protocol IZMMTDynamicViewMgr <ZMRoutableObject>

@end

@protocol ZMMTDynamicChangesProtocol <NSObject>
-(void)onDynamicActiveUserChanged;
@end
#endif /* IZMMTDynamicViewMgr_h */
