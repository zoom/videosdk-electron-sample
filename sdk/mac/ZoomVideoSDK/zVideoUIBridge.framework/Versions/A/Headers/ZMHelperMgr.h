//
//  ZMHelperMgr.h
//  VideoUIBridge
//
//  Created by geno.chen on 2022/6/17.
//

#import <Foundation/Foundation.h>

@class ZMConfSession;

NS_ASSUME_NONNULL_BEGIN

@interface ZMHelperMgr : NSObject

+ (instancetype)shared;
+ (void)uninitHelperMgr;

- (nullable id)helperWithClass:(Class)cls identifier:(NSString *)identifier;
- (nullable id)helperWithProtocol:(Protocol *)protocol identifier:(NSString *)identifier;
- (void)destroyHelperWithIdentifier:(NSString *)identifier;

- (nullable ZMConfSession *)zmConfSessionWithID:(NSString *)identifier;
@end

NS_ASSUME_NONNULL_END
