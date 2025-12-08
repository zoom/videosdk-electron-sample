//
//  ZMMemLogAdapter.h
//  ZoomUnit
//
//  Created by Cooper.Chen on 2024/11/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMemLogAdapter : NSObject

+ (void)adapterMtsInfoLevelLog:(NSString *)logid moduleId:(NSInteger)moduleId logLevel:(NSInteger)logLevel msg:(NSString *)msg;

+ (BOOL)isDogFood;

+ (BOOL)isLogVersion;

@end

NS_ASSUME_NONNULL_END
