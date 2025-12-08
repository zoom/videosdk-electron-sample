//
//  ZMRoutableObject.h
//  ZCommonUI
//
//  Created by Francis Zhuo on 4/3/21.
//  Copyright © 2021 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMRoutableObject <NSObject>

@optional
+ (nullable id)shared;//for singleton

@end

NS_ASSUME_NONNULL_END
