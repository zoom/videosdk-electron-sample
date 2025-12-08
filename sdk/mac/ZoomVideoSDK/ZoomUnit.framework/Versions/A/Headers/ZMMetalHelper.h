//
//  ZMMetalHelper.h
//  ZCommonUI
//
//  Created by Geno on 2020/5/12.
//  Copyright © 2020 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMetalHelper : NSObject

+ (int)getMetalDeviceCount;
+ (BOOL)isMeetingSupportLayer;
+ (BOOL)isCreateMetalDefaultDeviceSuccess;

@end

NS_ASSUME_NONNULL_END
