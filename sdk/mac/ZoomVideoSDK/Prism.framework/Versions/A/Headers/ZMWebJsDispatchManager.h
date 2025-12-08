//
//  ZMWebJsDispatchManager.h
//  ZoomKit
//
//  Created by Groot Ding on 2022/2/14.
//

#import <Foundation/Foundation.h>
#import <Prism/ZMNWKWebView.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMNWKWebView(WebJSDisPatch)
@property (nonatomic, copy) NSString *moduleIdentifier;
@property (nonatomic, copy) NSString *identifier;
@property (nonatomic, assign) NSInteger resourceType;
@end

@protocol ZMEvaluateJavaScriptProtocol <NSObject>

- (void)evaluateJavaScript:(NSString *)javaScriptString identifier:(NSString *)identifier API_AVAILABLE(macos(10.10));

- (void)evaluateJavaScript:(NSString *)javaScriptString jsCallId:(NSString *)jsCallId API_AVAILABLE(macos(10.10));

- (void)evaluateJavaScript:(NSString *)javaScriptString resourceType:(NSInteger)resourceType API_AVAILABLE(macos(10.10));

- (void)webView:(ZMNWKWebView *)webView evaluateJavaScript:(NSString *)javaScriptString completionHandler:(void (^)(id, NSError *error))completionHandler API_AVAILABLE(macos(10.10));

@end

@interface ZMWebJsDispatchManager : NSObject <ZMEvaluateJavaScriptProtocol,WKScriptMessageHandler>

+ (instancetype)sharedInstance;

- (void)addWebView:(ZMNWKWebView *)webView API_AVAILABLE(macos(10.10));
- (void)removeWebView:(ZMNWKWebView *)webView API_AVAILABLE(macos(10.10));

- (void)registerJsDispatch:(id<ZMJSMessageHandler>)jsMessageHandler moduleIdentifier:(NSString *)moduleIdentifier API_AVAILABLE(macos(10.10));

- (void)removeJsDispatchByModuleIdentifier:(NSString *)moduleIdentifier;

- (ZMNWKWebView *)getWebViewByJsCallId:(NSString *)jsCallId API_AVAILABLE(macos(10.10));

- (void)cleanJsCallId:(NSString *)jsCallId;

@end

NS_ASSUME_NONNULL_END
