//
//  ZMMessagePort.h
//  ZoomKit
//
//  Created by Devl on 12/20/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMMessagePortType) {
    ZMMessagePortLocal,     // message receiver
    ZMMessagePortRemote,    // message sender
};

@protocol ZMMessagePortDelegate <NSObject>
@optional
- (void)handleMessageRecevied:(NSData *)data;
@end

@interface ZMMessagePort : NSObject
@property (weak) id<ZMMessagePortDelegate> delegate;

+ (instancetype)messagePortWithType:(ZMMessagePortType)type name:(NSString*)name;

- (void)start;
- (void)stop;

- (void)sendMessage:(NSData *)message;

@end

NS_ASSUME_NONNULL_END
