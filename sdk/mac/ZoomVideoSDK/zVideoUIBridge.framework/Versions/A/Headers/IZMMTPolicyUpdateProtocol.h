//
//  IZMMTPolicyUpdateProtocol.h
//  VideoUIBridge
//
//  Created by Javenlee Li on 2022/12/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMTPolicyUpdateProtocol <NSObject>

- (void)policyUpdate:(zpref::zPolicyId)policy session:(ZMConfSession*)session;

@end

NS_ASSUME_NONNULL_END
