//
//  IZMMTGroupViewMgr.h
//  VideoUIBridge
//
//  Created by Devl on 2022/11/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMTGroupMgr <ZMRoutableObject>
- (void)switch2GroupModeForPinIfNeed;
- (void)switch2GroupModeForSpotlightIfNeed;

@end

NS_ASSUME_NONNULL_END
