//
//  IZMMTTransitionMgr.h
//  VideoUI
//
//  Created by Francis Zhuo on 10/20/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, ZMMTTranstionActioSource){
    ZMMTTranstionActioSource_FeatureMgr = 1ll<<1,
    ZMMTTranstionActioSource_GRMgr      = 1ll<<2,
    ZMMTTranstionActioSource_BRMgr      = 1ll<<3,
    ZMMTTranstionActioSource_PBRMgr     = 1ll<<4,
    ZMMTTranstionActioSource_HBRMgr     = 1ll<<5,
    ZMMTTranstionActioSource_LifeMgr    = 1ll<<6,
};

@protocol IZMMTTransitionMgr <ZMRoutableObject>

//for query transition state
- (BOOL)isInTransition;
- (BOOL)isTransitionFrom:(ZMConfSession*_Nullable*_Nullable)fromSession to:(ZMConfSession*_Nullable*_Nullable)toSession;

- (void)beginTransitionTo:(ZMConfSession*)toSession from:(ZMConfSession*)fromSession source:(ZMMTTranstionActioSource)actionSource;
- (void)endedTransitionTo:(ZMConfSession*)toSession success:(BOOL)success source:(ZMMTTranstionActioSource)actionSource;

- (void)beginJoinSession:(ZMConfSession*)session source:(ZMMTTranstionActioSource)actionSource;
- (void)endedJoinSession:(ZMConfSession*)session success:(BOOL)success source:(ZMMTTranstionActioSource)actionSource;

- (void)beginLeaveSession:(ZMConfSession*)session source:(ZMMTTranstionActioSource)actionSource;
- (void)endedLeaveSession:(ZMConfSession*)session success:(BOOL)success source:(ZMMTTranstionActioSource)actionSource;

@end

NS_ASSUME_NONNULL_END
