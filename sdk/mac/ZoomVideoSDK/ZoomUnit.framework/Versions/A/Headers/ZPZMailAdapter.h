//
//  ZPZMailAdapter.h
//  ZoomUnit
//
//  Created by Jax Wu on 2022/6/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMShareResult) {
    ZMShareResult_Success = 0,
    ZMShareResult_Failed,
    ZMShareResult_Cancel,
};

@interface ZMMailShareToChatInfo : NSObject

@property (nonatomic, copy, nullable) NSString *mailID;
@property (nonatomic, copy, nullable) NSString *jid;
@property (nonatomic, copy, nullable) NSString *subject;
@property (nonatomic, copy, nullable) NSString *name;
@property (nonatomic, copy, nullable) NSString *snippet;
@property (nonatomic, copy, nullable) NSString *zipFilePath;
@property (nonatomic, assign) BOOL isFromZMail;
@property (nonatomic, strong,nullable) NSString *validInfo;
@property (nonatomic, assign) int64_t secondsTimestamp;

- (instancetype)initWith:(NSString *)mailID
                     jid:(NSString *)jid
                 subject:(NSString *)subject
                    name:(NSString *)name
                 snippet:(NSString *)snippet
             zipFilePath:(NSString *)zipFilePath
        secondsTimestamp:(int64_t)secondsTimestamp
             isFromZMail:(BOOL)isFromZMail
               validInfo:(NSString *)validInfo;

@end

NS_ASSUME_NONNULL_END
