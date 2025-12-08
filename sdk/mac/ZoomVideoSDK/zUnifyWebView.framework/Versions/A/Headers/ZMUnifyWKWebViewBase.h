//
//  ZMUnifyWKWebViewBase.h
//  zUnifyWebView
//
//  Created by Ethan Wu on 2025/4/7.
//

#import "ZMUnifyWebViewProtocol.h"
#import <WebKit/WebKit.h>

@interface ZMUnifyWKWebViewBase : WKWebView

@property (nonatomic, strong) ZMUnifyWebViewConfiguration *unifyConfig;
@property (nonatomic, strong) NSMutableSet<NSString*>* customMessageHandlerSet;
@property (nonatomic, assign) int currentGPUProcessId;

+ (WKWebViewConfiguration *)getWKConfigurationWith:(ZMUnifyWebViewConfiguration*)unifyConfig;
- (void)cleanUp;

- (void)configCustomMessageHandlers:(NSArray<NSString*>*) customMessageHandlers;

- (void)loadURL:(NSString *)urlStr withRequestHeaders:(nullable NSDictionary *)headers;
- (void)loadURL:(NSString *)urlStr withRequestHeaders:(NSDictionary *)headers domains:(NSArray<NSString *> *)domains isAllow:(BOOL)isAllow;
- (void)loadFileURL:(NSString *)fileString folderPath:(NSString *)folderString;

- (void)configCookie:(NSHTTPCookie *)cookie completionHandler:(nullable void (^)())completionHandler;
- (void)deleteCookie:(NSHTTPCookie *)cookie completionHandler:(nullable void (^)(void))completionHandler;
- (void)getAllCookies:(nullable void (^)(NSArray<NSHTTPCookie *> *))completionHandler;

- (void)setAllowDomainList:(NSArray<NSString *> *)allowedDomains completeHandler:(nullable void (^)(void))completeHandler;
- (void)setAllowDomainList:(NSArray<NSString *> *)allowedDomains customSchemes:(NSArray<NSString *>*)customSchemes completeHandler:(nullable void (^)(void))completeHandler;
- (void)setLocalHostFilterDomain:(NSArray<NSString *>  *)localAllowedDomains  customSchemes:(NSArray<NSString *>*)customSchemes completeHandler:(nullable void (^)(void))completeHandler;
- (void)setDisallowDomainList:(NSArray<NSString *> *)domainList completeHandler:(nullable void (^)(void))completeHandler;
- (void)removeAllContentRuleList:(nullable void (^)(void))completeHandler;
- (void)addContentRuleList:(WKContentRuleList *)contentList completeHandler:(nullable void (^)(void))completeHandler API_AVAILABLE(macos(10.13));

- (void)addScriptMessageHandler:(id<WKScriptMessageHandler>)scriptMessageHandler name:(NSString *)name;
- (void)removeAllUserScript;
- (void)disableContextMenu;
- (NSString *)getUnifyTitleStr;
- (void)configCustomUserAgent:(NSString *)customUserAgent;
- (BOOL)getWebViewLoadingStatus;
- (void)stopMediaPlay:(nullable void (^)(id, NSError *))completeHandler;
- (void)stopLoadingWebView;

- (void)checkHasSound:(nullable void (^)(BOOL, NSError *))completeHandler;
- (void)suspendMediaPlay;
- (void)takeSnapshot:(CGFloat)snapshotWidth completionHandler:(void (^)(NSImage * _Nullable snapshotImage, NSError * _Nullable error))completionHandler;
- (void)getHTMLContentSize:(nullable void (^)(id, NSError *))completeHandler;
- (void)reloadWebView;

- (void)configBackgroundColor:(NSColor *)color;
- (void)enableDrawsTransparentBackground:(BOOL)enabled;

- (void)enableInspector:(BOOL)enabled;
- (void)injectServiceWorkerScriptForUnifyWebView;
- (void)injectCommonScriptForUnifyWebView;

- (NSString *)currentURLStr;

// Check if script message from frame is allowed based on domain matching
- (BOOL)isScriptMessageAllowedFromFrame:(WKFrameInfo *)frameInfo;

- (void)clearUnifyWebCache:(nullable void (^)())completionHandler;

- (NSPoint)convertWebViewPointToScreen:(NSPoint)point;

- (NSArray*)getRenderProcessIds;
- (BOOL)isLocalLoadEnabled;

- (enum UnifyWebViewNavigationType)getNavigationType;
@end
