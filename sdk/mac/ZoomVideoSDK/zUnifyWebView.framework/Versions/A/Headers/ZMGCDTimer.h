//
//  ZMGCDTimer.h
//  ZoomAppUISDK
//
//  Created by Jax Wu on 2024/1/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ZMGCDTimerMode){
    ZMGCDTimerModeOnce = 0,
    ZMGCDTimerModeFinite,
    ZMGCDTimerModeInfinite,
};

typedef NS_ENUM(NSInteger, ZMGCDTimerState){
    ZMGCDTimerStatePaused = 0,
    ZMGCDTimerStateRunning,
    ZMGCDTimerStateExecuting,
    ZMGCDTimerStateFinished,
};

@interface ZMGCDTimer : NSObject

@property (nonatomic, copy) void (^onTimerStateChanged)(ZMGCDTimer *timer);

#pragma mark - Once Timer
- (instancetype)initOnceTimerWith:(NSTimeInterval)timeInterval
                        taskBlock:(void (^) (void))taskBlock;

- (instancetype)initOnceTimerWith:(NSTimeInterval)timeInterval
                        taskBlock:(void (^) (void))taskBlock
                      isAutoStart:(BOOL)isAutoStart;

- (instancetype)initOnceTimerWith:(NSTimeInterval)timeInterval
                        taskBlock:(void (^) (void))taskBlock
                      isAutoStart:(BOOL)isAutoStart
                            queue:(dispatch_queue_t)queue;

#pragma mark - FiniteTimer Timer
- (instancetype)initFiniteTimerWith:(NSTimeInterval)timeInterval
                          repeatNum:(NSUInteger)repeatNum
                           taskBlock:(void (^) (void))taskBlock;

- (instancetype)initFiniteTimerWith:(NSTimeInterval)timeInterval
                          repeatNum:(NSUInteger)repeatNum
                        taskBlock:(void (^) (void))taskBlock
                      isAutoStart:(BOOL)isAutoStart;

- (instancetype)initFiniteTimerWith:(NSTimeInterval)timeInterval
                          repeatNum:(NSUInteger)repeatNum
                        taskBlock:(void (^) (void))taskBlock
                      isAutoStart:(BOOL)isAutoStart
                            queue:(dispatch_queue_t)queue;

#pragma mark - InFiniteTimer Timer
- (instancetype)initInfiniteTimerWith:(NSTimeInterval)timeInterval
                           taskBlock:(void (^) (void))taskBlock;

- (instancetype)initInfiniteTimerWith:(NSTimeInterval)timeInterval
                        taskBlock:(void (^) (void))taskBlock
                      isAutoStart:(BOOL)isAutoStart;

- (instancetype)initInfiniteTimerWith:(NSTimeInterval)timeInterval
                        taskBlock:(void (^) (void))taskBlock
                      isAutoStart:(BOOL)isAutoStart
                            queue:(dispatch_queue_t)queue;

#pragma mark - Factory
- (instancetype)initWithTimeInterval:(NSTimeInterval)timeInterval
                           taskBlock:(void (^) (void))taskBlock
                                mode:(ZMGCDTimerMode)mode
                           repeatNum:(NSUInteger)repeatNum
                         isAutoStart:(BOOL)isAutoStart
                               queue:(dispatch_queue_t)queue;

- (ZMGCDTimerMode)getCurMode;
- (ZMGCDTimerState)getCurState;
- (void)startTimer;
- (void)cancelTimer;

@end

NS_ASSUME_NONNULL_END
