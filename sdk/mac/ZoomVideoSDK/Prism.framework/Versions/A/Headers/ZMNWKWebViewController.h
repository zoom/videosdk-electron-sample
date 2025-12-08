//
//  ZMWKWebViewController.h
//  zCalendarUI
//
//  Created by Dongbiao.Gao on 1/5/22.
//  Copyright © 2022 ZOOM. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Prism/ZMNWKWebView.h>
#import <Prism/ZMBaseViewController.h>

typedef void(^WebviewCompletion)(NSString *uniqueID, NSError *error);

API_AVAILABLE(macos(10.10))
@interface ZMNWKWebViewController : ZMBaseViewController

@property (nonatomic, readonly) ZMNWKWebView *webView;

@property (nonatomic, assign) BOOL allowOpenLinkURL;
@property (nonatomic, assign) BOOL disableForm;
@property (nonatomic, assign) BOOL disableRightClickMenus;

- (void)loadFileURL:(NSURL *)fileURL;
- (void)loadRequest:(NSURLRequest *)urlRequest;
- (void)loadHtmlStringWithPath:(NSString *)filePath;
- (void)loadHtmlPath:(NSString *)path
       allowedScheme:(NSArray *)schemes
            uniqueID:(NSString *)uniqueID
          completion:(WebviewCompletion)completion;
@end
