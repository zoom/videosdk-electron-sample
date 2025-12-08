//
//  ZMPolicyObserver.h
//  VideoUIBridge
//
//  Created by Francis Zhuo on 2025/1/20.
//

#import <Foundation/Foundation.h>
#include <cmmlib/CmmPrefBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMPolicyObserver : NSObject
- (zpref::zPolicyIds)policyIDs;//for override

- (void)policyUpdated:(zpref::zPolicyId)policy;//for override
@end

NS_ASSUME_NONNULL_END
