//
//  ZMMTTransitionModel.h
//  VideoUIBridge
//
//  Created by Francis Zhuo on 12/1/22.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

@class ZMConfSession;
@interface ZMMTTransitionModel : NSObject
@property(retain) ZMConfSession* fromSession;
@property(retain) ZMConfSession* toSession;
@property(assign) BOOL inTransition;
@end

NS_ASSUME_NONNULL_END
