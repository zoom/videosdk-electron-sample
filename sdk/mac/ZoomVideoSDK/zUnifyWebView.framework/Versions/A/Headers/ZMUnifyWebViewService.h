//
//  ZMUnifyWebViewService.h
//  ZoomAppUISDK
//
//  Created by Jax Wu on 2023/11/30.
//

#import <Foundation/Foundation.h>
#import "ZMUnifyWebViewProtocol.h"

NS_ASSUME_NONNULL_BEGIN
 
@interface ZMUnifyWebViewService : NSObject

+ (ZMUnifyWebViewService *)shareInstance;
//MARK: - V2
- (id<ZMUnifyWebViewProtocol>)createUnifyWebView:(ZMUnifyWebViewConfiguration*)config;
- (id<ZMUnifyWebViewProtocol>)getUnifyWebViewWith:(NSString *)webViewID;
- (void)destroyUnifyWebView:(id<ZMUnifyWebViewProtocol>)unifyWebInstance;

//MARK: - V1
- (id<ZMUnifyWebViewInstance>)createUnifyWebView:(ZMUnifyWebViewConfiguration *)config layoutBlock:(void (^)(NSView *view))layoutBlock;
- (id<ZMUnifyWebViewInstance>)createUnifyWebView:(enum UnifyWebViewAppType)moduleType processDisplayName:(NSString *)processDisplayName config:(WKWebViewConfiguration *)config layoutBlock:(void (^)(NSView *view))layoutBlock;
- (id<ZMUnifyWebViewInstance>)unifyWebViewWith:(NSString *)webViewID;
- (void)destroyWebView:(id<ZMUnifyWebViewInstance>)unifyWebInstance;

@end

NS_ASSUME_NONNULL_END
