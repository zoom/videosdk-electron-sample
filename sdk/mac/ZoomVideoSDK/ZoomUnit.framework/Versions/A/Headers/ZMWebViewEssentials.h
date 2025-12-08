//
//  ZMWebViewEssentials.h
//  ZoomUnit
//
//  Created by Lester Gong on 2023/5/22.
//  Copyright © 2021 us.zoom. All rights reserved.
//

#import <ZoomKit/ZoomKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMWebViewEssentials : NSObject

//The unified response to runOpenPanelWithParameters
+ (void)webView:(WKWebView *)webView
     parameters:(WKOpenPanelParameters *)parameters
          frame:(WKFrameInfo *)frame
        handler:(void (^)(NSArray<NSURL *> *URLs))completionHandler;

+ (NSInteger)extractErrorCodeFromTraitedURL:(NSString*)urlString
                           defaultErrorCode:(NSInteger)defaultErrorCode;
+ (NSString*)ZMMTLanguageCookie;
+ (NSString*)extractHost:(NSString*)protocalDomain;
@end

@interface ZMWebLoadingView : ZMBaseView
- (instancetype)initWithTitle:(NSString*)title;
@end


@interface ZMWebErrorView : ZMBaseView

- (instancetype)initWithTarget:(id)target
                         title:(NSString*)title
                 refreshAction:(SEL)refreshAction
                  reportAction:(nullable SEL)reportAction;

- (instancetype)initWithTarget:(id)target
                         title:(NSString*)title
                  refreshTitle:(nullable NSString*)refreshTitle
                 refreshAction:(SEL)refreshAction
                  reportAction:(nullable SEL)reportAction;

@property (nonatomic, assign) NSInteger errorCode;

@property (nonatomic, assign) NSString* stringInformation;

@property (nonatomic, strong, readonly, nullable) ZMButton *refreshButton;

@end

NS_ASSUME_NONNULL_END
