//
//  ZMUnifyWebURLSchemeHelper.h
//  ZoomAppUISDK
//
//  Created by Jax Wu on 2023/12/1.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import "ZMUnifyWebViewDefine.h"


typedef void (^ZMUnifyWebSchemeBlockTask)(NSURLRequest *request);
typedef NSString * _Nullable (^ZMUnifyWebSchemeTaskIdentityID)(NSURLRequest *request);
typedef NSData * _Nullable (^ZMUnifyWebSchemeTaskData)(NSURLRequest *request);

API_AVAILABLE(macos(10.13))
@protocol ZMUnifyWebURLSchemeHandler <NSObject, WKURLSchemeHandler, ZMUnifyWebViewURLSchemeHandlerProtocol>

@property (nonatomic, copy) NSString *urlScheme;
@property (nonatomic, assign) NSInteger appType;
@property (nonatomic, strong) NSMutableDictionary* storedRequestBodies;
@property (nonatomic, strong) NSURLSession *session;

@property (nonatomic, copy) ZMUnifyWebSchemeBlockTask task;
@property (nonatomic, copy) ZMUnifyWebSchemeTaskIdentityID getIdentityID;
@property (nonatomic, copy) ZMUnifyWebSchemeTaskData getData;

- (void)preformOnlineRequest:(NSURLRequest *)request;
- (void)finishSchemeTask:(BOOL)success identityID:(NSString *)identityID data:(NSData *)data response:(NSURLResponse *)response;
- (void)finishSchemeTask:(BOOL)success identityID:(NSString *)identityID fullPath:(NSString *)fullPath response:(NSURLResponse *)response;

@end

@interface ZMUnifyWebURLSchemeHelper : NSObject

+ (ZMUnifyWebURLSchemeHelper *)shareInstance;

- (id<ZMUnifyWebURLSchemeHandler>)generateUnifyURLSchemeHandler;
- (void)deleteUnifyURLSchemeHandler:(id<ZMUnifyWebURLSchemeHandler>)handler;

@end
