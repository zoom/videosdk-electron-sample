//
//  ZMRouterCenterProtocols.h
//  ZoomKit
//
//  Created by martin.yu on 4/23/22.
//

#ifndef ZMRouterCenterProtocols_h
#define ZMRouterCenterProtocols_h

#import <Foundation/Foundation.h>
#import <Prism/ZMRouterMacroUtil.h>
#import <Prism/ZMRoutableObject.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMEventPoster <NSObject, NSCopying>
@property (weak) id sender;
@property (assign) BOOL ignoreSender;
@property (weak) id object;
@end

typedef NSInteger ZMEventPriority;
static ZMEventPriority ZMEventPriorityDefault = NSIntegerMax;

@protocol ZMEventTarget <NSObject>
@property (assign, readonly) Protocol *p;
@property (weak, readonly) NSObject *target;
@property (weak, readonly) id object;
@property (assign, readonly) BOOL isValid;
@property (assign, readonly) NSInteger tag;
@property (assign) ZMEventPriority priority;
@end


#define ZMEventPosterFor(P) ((id<P>)[ZMRouterCenter.shared posterForProtocol:@protocol(P)])
#define ZMEventPosterV2(P,O) ((id<P>)[ZMRouterCenter.shared posterForProtocol:@protocol(P) sender:nil object:O])
#define ZMEventPosterBroadcast(P) ((id<P>)[ZMRouterCenter.shared posterForProtocol:@protocol(P) sender:nil object:nil tag:-1 ignoreSelfObjectIfNil:YES])
@protocol ZMEventPosterGenerator <NSObject>
- (nullable id<ZMEventPoster>)posterForProtocol:(Protocol *)protocol;
- (nullable id<ZMEventPoster>)posterForProtocol:(Protocol *)protocol sender:(nullable id)sender;
- (nullable id<ZMEventPoster>)posterForProtocol:(Protocol *)protocol sender:(nullable id)sender object:(nullable id)object;
- (nullable id<ZMEventPoster>)posterForProtocol:(Protocol *)protocol sender:(nullable id)sender object:(nullable id)object tag:(NSInteger)tag;
- (nullable id<ZMEventPoster>)posterForProtocol:(Protocol *)protocol sender:(nullable id)sender object:(nullable id)object tag:(NSInteger)tag ignoreSelfObjectIfNil:(BOOL)ignoreSelfObjectIfNil;
@end

@protocol ZMEventRegistry <NSObject>
- (nullable id<ZMEventTarget>)registerTartget:(NSObject *)target forProtocol:(Protocol *)protocol;
- (nullable id<ZMEventTarget>)registerTartget:(NSObject *)target forProtocol:(Protocol *)protocol object:(nullable id)object;
- (nullable id<ZMEventTarget>)registerTartget:(NSObject *)target forProtocol:(Protocol *)protocol object:(nullable id)object priority:(ZMEventPriority)priority;
- (nullable id<ZMEventTarget>)registerTartget:(NSObject *)target forProtocol:(Protocol *)protocol object:(nullable id)object tag:(NSInteger)tag;
- (nullable id<ZMEventTarget>)registerTartget:(NSObject *)target forProtocol:(Protocol *)protocol object:(nullable id)object priority:(ZMEventPriority)priority tag:(NSInteger)tag;
- (void)unregisterTartget:(NSObject *)target forProtocol:(Protocol *)protocol;
- (void)unregisterTartgetByEventTarget:(id<ZMEventTarget>)eventTarget;
- (void)unregisterTartget:(NSObject *)target;
@end

#define ZMEventRegister(O,P) ([ZMRouterCenter.shared registerTartget:O forProtocol:@protocol(P)])
#define ZMEventUnregister(O,P) ([ZMRouterCenter.shared unregisterTartget:O forProtocol:@protocol(P)])

/*!
 export protocol for routerA
 @code
 xxx.h
 @protocol protocolA<NSObject>
 @end
 
 @protocol protocolB<NSObject>
 @end
 
 @interface routerA
 @end
 
 xxx.m
 @routerable(routerA, protocolA, protocolB)
 @implementation routerA
 @end
 @endcode
 */
#define routerable(className, protocolName...) routerable_(className, protocolName)

/*!
 export protocol for routerA
 @code
 xxx.h
 @protocol protocolA<NSObject>
 @end
 @protocol protocolB<NSObject>
 @end
 
 @interface routerA<ZMRoutableObject>
 @end
 
 xxx.m
 @implementation routerA
 ZMExportProtocol(protocolA,protocolB)
 @end
 @endcode
 */
#define ZMExportProtocol(protocol...) ZMExportProtocol_(protocol)


/*!
 get Instance methods
 @code
 id<protocolA> objectA = ZMObjectFor(Protocol);
 @endcode
 */
#define ZMObjectFor(P) (id<P>)[ZMRouterCenter.shared objectForProtocol:@protocol(P)]

/*!
 get singleton methods
 @code
 id<protocolA> objectA = ZMSharedFor(Protocol);
 @endcode
 */
#define ZMSharedFor(P) ((id<P>)[ZMRouterCenter.shared singletonForProtocol:@protocol(P)])

/*!
 observe xxx router did register
 @code
 [NSNotificationCenter.defaultCenter addObserver:self selector:@selector(routerADidReady) name:ZMRouterReady object:@protocol(protocolA)];
 @endcode
 */
extern NSNotificationName const ZMRouterReady;

@protocol ZMRouterCenterDelegate;
@protocol ZMRouterCenter <ZMEventPosterGenerator, ZMEventRegistry, ZMRoutableObject>
@property(nullable, weak) id<ZMRouterCenterDelegate> delegate;
- (void)registerProtocol:(Protocol *)protocol forClass:(Class)aClass;
- (void)registerProtocols:(NSArray<Protocol *> *)protocols forClass:(Class)aClass;
- (nullable Class)classForProtocol:(Protocol *)protocol;
- (nullable id)objectForProtocol:(Protocol *)protocol;

- (void)registerSingleton:(id)Object forProtocol:(Protocol *)protocol;
- (void)removeSingletonForProtocol:(Protocol *)protocol;
- (nullable id)singletonForProtocol:(Protocol *)protocol;
- (void)enumerateSingletonsUsingBlock:(void (NS_NOESCAPE ^)(id obj, NSUInteger idx, BOOL *stop))block;

- (nullable id)registerSuccessAction:(void(^_Nullable)(void))action forProtocol:(Protocol *)protocol;
- (BOOL)registerSuccessAction:(void(^_Nullable)(void))action forProtocol:(Protocol *)protocol withID:(id)identifer;
- (void)removeSuccessActionForProtocol:(Protocol *)protocol WithID:(id)identifer;
@end

@protocol ZMRouterCenterDelegate <NSObject>
@optional
//for Singleton
- (id)routerCenter:(id<ZMRouterCenter>)routerCenter singletonForProtocol:(Protocol *)protocol;

//for EventPoster
- (void)routerCenter:(id<ZMRouterCenter>)routerCenter collectTargets:(id<ZMEventRegistry>)collector forProtocol:(Protocol *)protocol;
@end
NS_ASSUME_NONNULL_END

#endif /* ZMRouterCenterProtocols_h */
