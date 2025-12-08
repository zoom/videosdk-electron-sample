//
//  IZMMTSessionLifeMgr.h
//  VideoUIBridge
//
//  Created by Francis Zhuo on 2025/2/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMTSessionLifeMgr <ZMRoutableObject>
@property(readonly, weak) ZMConfSession* currentSession;
@property(readonly, strong) ZMConfSession* activeSession;
@end

NS_ASSUME_NONNULL_END
