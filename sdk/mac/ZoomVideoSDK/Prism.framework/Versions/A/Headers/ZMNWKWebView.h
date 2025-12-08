//
//  ZMWKWebView.h
//  zCalendarUI
//
//  Created by Dongbiao.Gao on 1/5/22.
//  Copyright © 2022 ZOOM. All rights reserved.
//

#import <WebKit/WebKit.h>

@class ZMNWKWebView;

API_AVAILABLE(macos(10.10))
@protocol ZMJSMessageHandler <NSObject>
- (void)webView:(ZMNWKWebView *)webView didReceiveJSMessage:(NSDictionary *)message;
@end

API_AVAILABLE(macos(10.11))
@interface WKPreferences (ZMWKWebView)
+ (NSArray *)_experimentalFeatures;
- (void)_setEnabled:(BOOL)value forFeature:(id)feature;
- (void)_setEnabled:(BOOL)value forExperimentalFeature:(id)feature;
- (void)_setMediaDevicesEnabled:(BOOL)enabled;
@end

API_AVAILABLE(macos(10.10))
@interface ZMNWKWebView : WKWebView
@property (nonatomic, weak) id<ZMJSMessageHandler> jsMsgHandler;
@property (nonatomic, assign) BOOL mouseToSelectText;
+ (instancetype)wkWebView;

- (void)loadHtmlStringWithPath:(NSString *)filePath;
- (void)loadFileURL:(NSURL *)fileURL;

@end
