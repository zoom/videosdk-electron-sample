//
//  ZMUnifyWebView.h
//  ZoomAppUISDK
//
//  Created by Jax Wu on 2023/11/28.
//

#import <WebKit/WebKit.h>
#import "ZMUnifyWebViewProtocol.h"
#import "ZMUnifyWKWebViewBase.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZMUnifyWebView : ZMUnifyWKWebViewBase <ZMUnifyWebViewInstance>

@property (nonatomic, weak) id<ZMUnifyWebViewInstanceDelegate> unifyDelegate;
@property (nonatomic, readonly) NSString *webViewID;
@property (nonatomic, strong) NSString *homeURL;
@property (nonatomic, assign) BOOL isRecycled;
@property (nonatomic, assign) long long createStartTime;
@property (nonatomic, assign) long long createEndTime;
@property (nonatomic, assign) long long firstFinishNavigationTime;
@property (nonatomic, assign) NSInteger errorCode;
@property (nonatomic, assign, readonly) BOOL isVisible;

+ (instancetype)unifyWebViewWithConfig:(ZMUnifyWebViewConfiguration *)config;
+ (WKWebViewConfiguration *)wkConfigurationWith:(ZMUnifyWebViewConfiguration *)unifyConfig;

- (void)prepareForUnifyWebView;
- (void)prepareForDestroy;
- (void)userContentController:(WKUserContentController *)userContentController didReceiveScriptMessage:(WKScriptMessage *)message;
- (BOOL)isJSCallSrcURLInvalid:(NSURL *)srcURL;
- (void)checkTimeFormatChange;
- (void)showUnifyErrorView:(NSInteger)errorCode;
- (void)showUnifyErrorView:(NSString*)title errorInfo:(NSString*)info errorCode:(int)errorCode;
- (void)hideUnifyErrorViewIfNeeded;
- (void)recycleUnifyWebView;
- (void)restoreUnifyWebView;

- (BOOL)isUnifyWebViewVisible;
- (long long)getIntervalSecondSinceInactive;

@end

NS_ASSUME_NONNULL_END
