//
//  ZMRouterCenter.h
//  ZCommonUI
//
//  Created by Francis Zhuo on 4/3/21.
//  Copyright © 2021 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Prism/ZMRouterCenterProtocols.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMRouterCenter : NSObject <ZMRouterCenter>
+ (instancetype)shared;
@property (readonly) NSMutableDictionary *protocolMap;
@property (readonly) NSMutableDictionary *singletonMap;
@end

NS_ASSUME_NONNULL_END

