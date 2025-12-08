//
//  ZMIPCMessage.h
//  MTProgress
//
//  Created by Francis Zhuo on 4/28/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMIPCMessage : NSObject<NSSecureCoding>
@property(assign) NSInteger IPCType;
@property(strong, nullable) id representObject;

+ (instancetype)messageWithData:(NSData*)data;
- (NSData*)encodedData;
@end

NS_ASSUME_NONNULL_END
