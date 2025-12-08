//
//  ZMAsyncTask.h
//  ZoomKit
//
//  Created by Cyan.Yang on 2022/10/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMAsyncTask;

/// A type used to identify and manage async tasks.
@interface ZMAsyncTaskQueue : NSObject

@property (nonatomic, readonly, assign) NSUInteger numberOfRunningTasks;

/// Creates and returns a queue with given identifier and default QOS class.
///
/// - Parameter identifier: The identifier of the queue.
+ (instancetype)queueWithIdentifier:(nullable NSString *)identifier;

- (instancetype)init;
- (instancetype)initWithIdentifier:(nullable NSString *)identifier
                               qos:(qos_class_t)qos NS_DESIGNATED_INITIALIZER;

/// Submits a task to execute. The task will be waiting in a queue and
/// get scheduled when possible.
///
/// - Parameter task: The task to be executed.
- (void)submitTask:(ZMAsyncTask *)task;

@end

/// `ZMAsyncTask` is designed to enable easy use of background queues.
///
/// The most common use case is for integrating into UI, and that would perform
/// some operation in the background and post the result back to the main queue.
///
/// `ZMAsyncTask` cannot be used directly, and subclassing is required instead.
/// You override `runInBackground` and `handleResult:` methods to perform your
/// works. And optionally, check the `cancelled` property periodically to support
/// the cancellation feature.
@interface ZMAsyncTask<ResultType> : NSObject

@property (nonatomic, readonly, getter=isFinished, assign) BOOL finished;
@property (nonatomic, readonly, getter=isCancelled, assign) BOOL cancelled;

/// Creates and returns a task that uses blocks for its operations.
///
/// - Parameters:
///   - mainBlock: The block to execute in the background.
///   - resultHandler: The block to execute in the main queue to handle the result.
+ (instancetype)taskWithBlock:(ResultType _Nullable (^)(void))mainBlock
                resultHandler:(void (^)(ResultType _Nullable result, ZMAsyncTask *task))handler;

/// Creates and returns a task that uses blocks for its operations.
///
/// - Parameters:
///   - mainBlock: The block to execute in the background.
///   - resultHandler: The block to execute in the main queue to handle the result.
///   - cancellationHandler: The block to execute in the main queue to perform some
///                          clean-ups for cancelled task. This handler is guaranteed
///                          to be executed once the task is cancelled, whether its
///                          background jobs started or not.
+ (instancetype)taskWithBlock:(ResultType _Nullable (^)(void))mainBlock
                resultHandler:(void (^)(ResultType _Nullable result, ZMAsyncTask *task))handler
          cancellationHandler:(void (^ _Nullable)(ResultType _Nullable result, ZMAsyncTask *task))handler;

- (instancetype)init;
- (instancetype)initWithIdentifier:(nullable NSString *)identifier NS_DESIGNATED_INITIALIZER;

/// Cancels the task.
///
/// The task will not be interrupted if it was already executed, and it will not
/// ever be executed if it's in the waiting queue. If the task has finished its
/// background jobs, this will prevent the result handler from being called.
- (void)cancel;

/// Override point for running the task, the method is called in some background queue.
- (nullable ResultType)runInBackground;

/// Override point for handling the task result, the method is called in main queue.
- (void)handleResult:(nullable ResultType)result;

/// Override point for handling the cancellation, the method is called in main queue.
- (void)handleCancellationWithResult:(nullable ResultType)result;

@end

NS_ASSUME_NONNULL_END
