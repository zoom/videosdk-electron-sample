//
//  ZMQueryResponse.h
//  VideoUIBridge
//
//  Created by Jun Pang on 7/14/23.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMIQConstant.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMQueryResponse : NSObject
@property(nonatomic, strong) NSString* requestId;
@property(nonatomic, strong) NSString* answer;
@property(nonatomic) ZMQueryRequestError errorCode;
@property(nonatomic, strong) NSString* errorMsg;
@property(nonatomic, strong) NSDate* date;
@end

NS_ASSUME_NONNULL_END
