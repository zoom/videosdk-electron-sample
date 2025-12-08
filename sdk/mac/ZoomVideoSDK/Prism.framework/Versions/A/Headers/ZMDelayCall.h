//
//  ZMDelayCall.h
//  ZoomKit
//
//  Created by Vinson Wang on 2023/12/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMBaseCall : NSObject
@property(assign) CGFloat timeInterval;//default 0.1
@property(nonatomic,copy) NSArray<NSRunLoopMode>* runloopModes;
@end
@compatibility_alias ZMMTBaseCall ZMBaseCall;

@interface ZMDelayCall : ZMMTBaseCall
@property(copy) void (^action)(void);
@property(assign) NSInteger maxAccumulation;//when setNeedsCall up to the maxAccumulation, will direct callAction.
+ (instancetype)delayCall;
///will call by delay if needed, do not call this function in action block.
- (void)setNeedsCall:(BOOL)need;
///will call by delay, can call this function in action block
- (void)callActionWithDelay:(CGFloat)timeInterval;
///will call immediately, do not call this function in action block.
- (void)callAction;
@end
@compatibility_alias ZMMTDelayCall ZMDelayCall;


@interface ZMAsyncCall<Type> : NSObject
@property(copy) void (^action)(Type value);
+ (instancetype)asyncCall;
- (void)callWithValue:(nullable Type)value;
@end
@compatibility_alias ZMMTAsyncCall ZMAsyncCall;

@interface ZMCoalesceCall<Type> : ZMMTBaseCall
@property(copy) void (^action)(NSArray<Type>* values);
+ (instancetype)coalesceCall;
- (void)callWithValue:(nullable Type)value;
- (void)callWithArray:(nullable NSArray<Type>*)array;
- (void)cancel;
@end
@compatibility_alias ZMMTCoalesceCall ZMCoalesceCall;

@interface ZMConcurrencyCall<Type> : ZMMTBaseCall
@property(copy) void (^action)(NSArray<Type>* values);
@property(assign) NSUInteger concurrency; // default 20
+ (instancetype)concurrencyCall;
- (void)callWithValue:(nullable Type)value;
- (void)cancel;
@end
@compatibility_alias ZMMTConcurrencyCall ZMConcurrencyCall;

NS_ASSUME_NONNULL_END
